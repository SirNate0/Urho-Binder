#!/usr/bin/env python
""" Usage: call with <filename> <typename>
"""

import sys
import clang.cindex
from pymustache import mustache
from mako.template import Template
import re

#disable html escaping as this is for C++
mustache.html_escape = lambda x: x
mustache.filters['nocolons'] = lambda str: str.replace(':','_')
mustache.filters['dropcolons'] = lambda str: str.replace(':','')
mustache.filters['join-scoped'] = lambda list : '::'.join(list)
mustache.filters['append-scope'] = lambda str: str + '::' if str else ''
mustache.filters['last'] = lambda list: list[-1]
for i in range(10):
    def f(l):
        #print 'HERE:::' + str(len(l)) + '>=' + i
        #return len(l) >= i
        return l[i:] if len(l) >= i else []
    mustache.filters['len-gte-'+str(i)] = f #lambda l : len(l) >= i

clang.cindex.Config.set_library_file('/usr/lib/llvm-3.8/lib/libclang-3.8.so.1')

# operator_functions = {
#     '*' : 'MUL_FUNC'
#
# }


#TODO: new and delete
op_functions = {
'+' : '__ADD_FUNC__',
'-' : '__SUB_FUNC__',
'*' : '__MUL_FUNC__',
'/' : '__DIV_FUNC__',
'%' : '__MOD_FUNC__',
'^' : '__XOR_FUNC__',
'&' : '__BIT_AND_FUNC__',
'|' : '__BIT_OR_FUNC__',
'~' : '__BIT_NOT_FUNC__',
'!' : '__NOT_FUNC__',
'=' : '__ASSIGN_FUNC__',
'<' : '__LT_FUNC__',
'>' : '__GT_FUNC__',
'+=' : '__ADD_ASSIGN_FUNC__',
'-=' : '__SUB_ASSIGN_FUNC__',
'*=' : '__MUL_ASSIGN_FUNC__',
'/=' : '__DIV_ASSIGN_FUNC__',
'%=' : '__MOD_ASSIGN_FUNC__',
'^=' : '__XOR_ASSIGN_FUNC__',
'&=' : '__AND_ASSIGN_FUNC__',
'|=' : '__OR_ASSIGN_FUNC__',
'<<' : '__SL_FUNC__',
'>>' : '__SR_FUNC__',
'>>=' : '__SR_ASSIGN_FUNC__',
'<<=' : '__SL_ASSIGN_FUNC__',
'==' : '__EQ_FUNC__',
'!=' : '__NEQ_FUNC__',
'<=' : '__LTE_FUNC__',
'>=' : '__GTE_FUNC__',
'&&' : '__AND_FUNC__',
'||' : '__OR_FUNC__',
'++' : '__INC_FUNC__',
'--' : '__DEC_FUNC__',
'++@' : '__PRE_INC_FUNC__',
'--@' : '__PRE_DEC_FUNC__',
'@++' : '__POST_INC_FUNC__',
'@--' : '__POST_DEC_FUNC__',
',' : '__DOT_FUNC__',
'->*' : '__ARROW_STAR_FUNC__', #TODO: name
'->' : '__ARROW_FUNC__',
'()' : '__OPERATOR_FUNC__',
'[]' : '__INDEX_FUNC__',
    #CASTS
'bool' : '__BOOL_CAST__',
'int' : '__INT_CAST__',
'float' : '__FLOAT_CAST__',
    #UNARY OPERATORS
'-@' : '__NEG_FUNC__',
'+@' : '__POS_FUNC__',
'*@' : '__DEREFERENCE_FUNC__',
'&@' : '__ADDRESS_FUNC__',
}

op_names = {
'+' : 'add',
'-' : 'sub',
'*' : 'mul',
'/' : 'div',
'%' : 'mod',
'^' : 'xor',
'&' : 'bit_and',
'|' : 'bit_or',
'~' : 'bit_not',
'!' : 'not',
'=' : 'assign',
'<' : 'lt',
'>' : 'gt',
'+=' : 'add_assign',
'-=' : 'sub_assign',
'*=' : 'mul_assign',
'/=' : 'div_assign',
'%=' : 'mod_assign',
'^=' : 'xor_assign',
'&=' : 'and_assign',
'|=' : 'or_assign',
'<<' : 'sl',
'>>' : 'sr',
'>>=' : 'sr_assign',
'<<=' : 'sl_assign',
'==' : 'eq',
'!=' : 'neq',
'<=' : 'lte',
'>=' : 'gte',
'&&' : 'and',
'||' : 'or',
'++' : 'inc', #done: split pre-increment and post-increment
'--' : 'dec',
'++@' : 'pre_inc',
'--@' : 'pre_dec',
'@++' : 'post_inc',
'@--' : 'post_dec',
',' : 'dot',
'->*' : 'arrow_star', #todo: name
'->' : 'arrow',
'()' : 'call',
'[]' : 'index',
    #CAST OPERATORS
'bool' : 'bool',
'int' : 'int',
'float' : 'float',
    #UNARY OPERATORS
'-@' : 'neg',
'+@' : 'pos',
'*@' : 'deref',
'&@' : 'address',
}

op_args = {
'+' : 'binary',
'-' : 'binary',
'*' : 'binary',
'/' : 'binary',
'%' : 'binary',
'^' : 'binary',
'&' : 'binary',
'|' : 'binary',
'~' : 'unary',
'!' : 'unary',
'=' : 'binary',
'<' : 'binary',
'>' : 'binary',
'+=' : 'binary',
'-=' : 'binary',
'*=' : 'binary',
'/=' : 'binary',
'%=' : 'binary',
'^=' : 'binary',
'&=' : 'binary',
'|=' : 'binary',
'<<' : 'binary',
'>>' : 'binary',
'>>=' : 'binary',
'<<=' : 'binary',
'==' : 'binary',
'!=' : 'binary',
'<=' : 'binary',
'>=' : 'binary',
'&&' : 'binary',
'||' : 'binary',
'++' : 'unary', #done: split pre-increment and post-increment
'--' : 'unary',
'++@' : 'unary',
'--@' : 'unary',
'@++' : 'post_unary',
'@--' : 'post_unary',
',' : 'binary',
'->*' : 'binary', #todo: name
'->' : 'binary',
'()' : 'operator',
'[]' : 'operator',
    #CAST OPERATORS
'bool' : 'cast',
'int' : 'cast',
'float' : 'cast',
    #UNARY OPERATORS
'-@' : 'unary',
'+@' : 'unary',
'*@' : 'deref',
'&@' : 'address',
}

def warn(str):
    print 'WARNING: ' + str

def find_all(node, typename):
    """ Find all references to the type named 'typename'
    """
    # if True:#node.kind.is_reference():
    #     #ref_node = clang.cindex.Cursor(node)
    #     ref_node = node#clang.cindex.Cursor_ref(node)
    #     if ref_node.spelling == typename:
    #         print 'Found %s [line=%s, col=%s]' % (
    #             typename, node.location.line, node.location.column)
    print 'Found %s (%s) {%s} [l=%s, c=%s]' % (
        node.spelling, node.displayname,
        node.kind, node.location.line, node.location.column)
    # Recurse for children of this node
    for c in node.get_children():
        find_all(c, typename)


def find_all(node, typename, line_offset):
    """ Find all references to the type named 'typename'
    """
    # if True:#node.kind.is_reference():
    #     #ref_node = clang.cindex.Cursor(node)
    #     ref_node = node#clang.cindex.Cursor_ref(node)
    #     if ref_node.spelling == typename:
    #         print 'Found %s [line=%s, col=%s]' % (
    #             typename, node.location.line, node.location.column)

    # if node.kind == clang.cindex.CursorKind.NAMESPACE:
    print 'Found %s => %s (%s) a %s ->%s | {%s} [l=%s, c=%s]' % (
        typename, node.spelling, node.displayname, node.type.spelling,node.result_type.spelling,
        node.kind, node.location.line - line_offset, node.location.column)
    typename = node.spelling
    # Recurse for children of this node
    for c in node.get_children():
        find_all(c, typename, line_offset)


def find_classes(node, cls):
    if type(node) is not clang.cindex.Cursor:
        print 'NOT CURSOR' + str(type(node))
        return

    if node.kind is clang.cindex.CursorKind.CLASS_DECL\
            or node.kind is clang.cindex.CursorKind.CLASS_TEMPLATE\
            or node.kind is clang.cindex.CursorKind.STRUCT_DECL\
            :
        print 'Found ' + str(node.spelling)
        if cls != '':
            cls = cls + '::' + node.spelling
        else:
            cls = node.spelling

        print node.type.get_canonical.spelling
        fields = [('%s %s' % (n.type.spelling, n.spelling)) for n in node.type.get_fields()]
        print fields


    if node.kind is clang.cindex.CursorKind.FUNCTION_TEMPLATE:
        # args = [(('%s %s' % (n.type.spelling, n.spelling)) if n.spelling is not '' else n.type.spelling) for n in node.get_arguments()]
        args = [n.type.spelling for n in node.get_arguments()]
        print 'Found %s %s::%s<>(%s)' % (str(node.result_type.spelling),cls,str(node.spelling),', '.join(args))

    if node.kind is clang.cindex.CursorKind.CONSTRUCTOR:
        # args = [(('%s %s' % (n.type.spelling, n.spelling)) if n.spelling is not '' else n.type.spelling) for n in node.get_arguments()]
        args = [n.type.spelling for n in node.get_arguments()]
        print 'Found CTOR %s(%s)' % (str(node.spelling),', '.join(args))

    if node.kind is clang.cindex.CursorKind.DESTRUCTOR:
        # args = [(('%s %s' % (n.type.spelling, n.spelling)) if n.spelling is not '' else n.type.spelling) for n in node.get_arguments()]
        args = [n.type.spelling for n in node.get_arguments()]
        print 'Found DTOR %s(%s)' % (str(node.spelling),', '.join(args))

    if node.kind is clang.cindex.CursorKind.CXX_METHOD:
        # args = [(('%s %s' % (n.type.spelling, n.spelling)) if n.spelling is not '' else n.type.spelling) for n in node.get_arguments()]
        args = [n.type.spelling for n in node.get_arguments()]
        for i,a in enumerate(node.get_arguments()):
            print 'arg: ' + a.displayname
            # for c in a.get_children():
            #     print '  literal:' + c.spelling + " " + c.displayname
            foundEq = False
            # print a.extent.end <= can try adjusting that, but instead will just trim last character
            for t in a.get_tokens():
                if foundEq:
                    print '  literal: ' + t.spelling + ' ' + str(t.kind)
                elif t.spelling == '=':
                    foundEq = True
        #     for t in a.get_tokens():
        #         if t.kind == clang.cindex.TokenKind.LITERAL:
        #             print '  literal:' + t.spelling
        if node.is_const_method():
            print 'Found %s %s::%s(%s) const' % (str(node.result_type.spelling),cls,str(node.spelling),', '.join(args))
        else:
            print 'Found %s %s::%s(%s)' % (str(node.result_type.spelling),cls,str(node.spelling),', '.join(args))

        #get_field_offsetof
        #get_arguments

    for c in node.get_children():
        find_classes(c,cls)


def find_enums(node, enm):
    if type(node) is not clang.cindex.Cursor:
        print 'NOT CURSOR' + str(type(node))
        return

    for c in node.get_children():
        find_enums(c,enm)


def find_methods(node, cls):
    return


classd = {
            'class' : 'Object',
            'inherits' : [{'base' : 'Ref-Counted'}],
            'ctor-args' : 'Context *',
            'methods' : [
                {
                    'func' : 'Function',
                    'ret' : 'int',
                    'arg-types' : 'Object, int, void*',
                    'arg-names' : [
                        {
                            'arg' : 'other',
                            'default' : False,
                        },
                        {
                            'arg' : 'size',
                            'default' : True,
                            'val' : '0'
                        },
                        {
                            'arg' : 'size',
                            'default' : True,
                            'val' : 'nullptr'
                        },
                    ]

                }
            ]
        }

templates = []

def get_variable(node, class_dict):
    if not (node.kind is clang.cindex.CursorKind.FIELD_DECL or
         node.kind is clang.cindex.CursorKind.VAR_DECL):
        return
    if node.access_specifier in [clang.cindex.AccessSpecifier.PRIVATE,
            clang.cindex.AccessSpecifier.PROTECTED]:
        print 'Found non-public ' + node.displayname
        return
    in_class = node.semantic_parent.kind in [
         clang.cindex.CursorKind.CLASS_DECL,
         clang.cindex.CursorKind.STRUCT_DECL,
         clang.cindex.CursorKind.CLASS_TEMPLATE]
    if in_class and not class_dict.has_key('class'):
        print 'escaping from '
        return # No error - can just be definition
    print "Var " + node.spelling
    var = {}
    var['var'] = node.spelling
    t = node.type.get_canonical()
    print t.get_canonical().spelling
    const = t.is_const_qualified()
    var['type'] = t.get_canonical().spelling
    var['reference'] = t.get_canonical().spelling[-1] == '&' #str(t.get_ref_qualifier()) <- doesn't work for, e.g. int &
    var['const'] = 'const' if const else ''
    if node.kind is clang.cindex.CursorKind.FIELD_DECL:
        var['static'] = ''
        print 'GOOD'
        class_dict['vars'].append(var)
    elif node.kind is clang.cindex.CursorKind.VAR_DECL:
        if in_class:
            var['static'] = 'static'
            class_dict['vars'].append(var)
        else:
            #in namespace
            var['static'] = ''
            class_dict['vars'].append(var)


def is_friend(node):
    for c in node.get_children():
        if c.kind is clang.cindex.CursorKind.ANNOTATE_ATTR:
            if c.spelling == 'friend':
                return True
    return False


#use for methods and functions (CXX_METHOD vs FUNCTION_DECL
def get_function(node, class_dict):
    if not (node.kind is clang.cindex.CursorKind.CXX_METHOD or
         node.kind is clang.cindex.CursorKind.CONSTRUCTOR or
         node.kind is clang.cindex.CursorKind.FUNCTION_TEMPLATE or
         node.kind is clang.cindex.CursorKind.DESTRUCTOR or
         node.kind is clang.cindex.CursorKind.FUNCTION_DECL):
        return
    if node.access_specifier in [clang.cindex.AccessSpecifier.PRIVATE,
            clang.cindex.AccessSpecifier.PROTECTED]:
        print 'Found non-public ' + node.displayname
        return
    if node.kind is clang.cindex.CursorKind.FUNCTION_TEMPLATE:
        print 'Found function class ' + node.displayname
        templates.append(node.canonical.spelling)
        return
    function = {}
    in_class = node.semantic_parent.kind in [
         clang.cindex.CursorKind.CLASS_DECL,
         clang.cindex.CursorKind.STRUCT_DECL,
         clang.cindex.CursorKind.CLASS_TEMPLATE]
    if in_class and not class_dict.has_key('class'):
        return
    class_name = node.semantic_parent.type.get_canonical().spelling
    # Gather function args
    # function['arg-types'] = ', '.join([n.type.spelling for n in node.get_arguments()])
    t = re.match(r'^.+ [&\*]*\((.*)\).*?',node.type.spelling)
    if t:
        function['arg-types'] = t.group(1)
        if t.group(1) == 'Urho3D::Object::Context *':
            print node.type.spelling + ' ' + node.displayname
            raise Exception('HEre')
    else:
        raise Exception('Failed to match function argument types for ' + node.type.spelling)

    if '...' in function['arg-types']:
        # TODO: type.is_function_variadic
        function['variadic'] = True

    if '**' in node.type.spelling:
        pointer_count = 2
    elif '*' in node.type.spelling:
        pointer_count = 1
    else:
        pointer_count = 0;
    function['pointer-count'] = ['*'] * pointer_count

    # if node.kind is clang.cindex.CursorKind.FUNCTION_TEMPLATE:
    #     print "====================================="
    #     print clang.cindex.conf.lib.clang_Cursor_getNumArguments(node)
    #     print clang.cindex.conf.lib.clang_Cursor_getArgument(node,-1)
    #     for i,a in enumerate(node.get_arguments()):
    #         print i, a.displayname
    #     for c in node.get_children():
    #         if c.kind is clang.cindex.CursorKind.PARM_DECL:
    #             print c.displayname
    #             print c.type.spelling
    #             print c.type.get_canonical().spelling
    #     raise Exception("null")

    argnames = []
    # for i,a in enumerate(node.get_arguments()): #Fails for template types
    for a in node.get_children():
        if a.kind is not clang.cindex.CursorKind.PARM_DECL:
            continue
        arg = {}
        arg['name'] = a.displayname

        default = ''
        foundEquals = False
        # print a.extent.end <= can try adjusting that, but instead will just trim last character
        for t in a.get_tokens():
            if foundEquals:
                default += t.spelling
            elif t.spelling == '=':
                foundEquals = True

        if foundEquals:
            default=default[:-1]
            # arg['default'] = True
            # arg['val'] = default
            arg['default-val'] = default

        t = a.type.get_canonical()
        arg['type'] = t.spelling
        strip = re.match(r'^(const )?([\w:<>, *]+)( &)?',t.spelling)
        if strip:
            arg['stripped-type'] = strip.group(2)
            # if in_class and strip.group(2) == class_dict['class']:
            arg['self'] = in_class and strip.group(2) == class_name


        ##TODO: I think t.get_pointee with t.is_const_qualified and !t.is_pod will get me the const Class & equivalence
        # print ''
        # print t.spelling
        # print 'pointee: ' + t.get_pointee().spelling
        # print 'const ' if t.get_pointee().is_const_qualified() else 'non-const'
        # print 'ref: ' + str(t.get_ref_qualifier())
        # print 'POD' if t.is_pod() else 'NON-POD'
        # print 'Elem type: ' + t.get_array_element_type().spelling
        ### print 'Elem type: ' + t.element_type.spelling


        argnames.append(arg)

    function['args'] = argnames
    function['func'] = node.spelling

    function['ret'] = node.result_type.spelling

    function['const'] = 'const' if node.is_const_method() else ''
    function['static'] = 'static' if node.is_static_method() else ''
    function['friend'] = 'friend' if is_friend(node) else ''

    if node.spelling == 'print':
        warn("Static method print is claimed by python already and may result in SyntaxErrors.")

    #Find operators
    op = re.match(r'^operator ?(\W+|bool|int)$',node.spelling)
    if op:
        #TODO: https://stackoverflow.com/questions/761586/overriding-to-boolean-operator-in-python
        warn('found operator')
        o = op.group(1)
        print o
        function['op'] = o
        #TODO:
        print node.displayname
        function['op-func'] = op_functions[o] #Things like __MUL_FUNC__, etc.
        function[op_names[o]] = op_names[o] # e.g. function['equality'] = 'equality' for ==
        function['op-name'] = op_names[o]
        function['op-style'] = op_args[o]
        print 'Static: ' + str(node.is_static_method())

        #special ops:
        if o == '++' or o == '--': #sort post and pre
            if len(argnames) == 0:
                o += '@'
            elif len(argnames) == 1:
                if argnames[0]['self']: #outside of class
                    o += '@'
                else:
                    o = '@' + o
            elif len(argnames) == 2:
                o = '@' + o
            function['special-op'] = o
            function['op-func'] = op_functions[o]
            function[op_names[o]] = op_names[o]
            function['op-name'] = op_names[o]
            function['op-style'] = op_args[o]
        elif o in ['+','-','*','&']: #sort add/sub from pos/neg
            if len(argnames) == 0:
                o += '@'
                function['special-op'] = o
                function['op-func'] = op_functions[o]
                function[op_names[o]] = op_names[o]
                function['op-name'] = op_names[o]
                function['op-style'] = op_args[o]
            elif len(argnames) == 1 and function['friend'] and \
                            node.kind is clang.cindex.CursorKind.CXX_METHOD:
                if not argnames[0]['self']:
                    raise Exception("work out unary + or - correctly")
                o += '@'
                function['special-op'] = o
                function['op-func'] = op_functions[o]
                function[op_names[o]] = op_names[o]
                function['op-name'] = op_names[o]
                function['op-style'] = op_args[o]
            else:
                pass #already assumed add or subtract






        #find self-typed args
        # for i,a in node.get_arguments():
        #     # print a.canonical.spelling
        #     # print a.displayname
        #     print a.type.spelling
        #     t = a.type.get_canonical()
        #     print t.get_class_type().spelling
        #     if t.is_const_qualified():
        #         print "const"
        #     else:
        #         print 'not const'
        #
        #     print 'ref' if t.get_ref_qualifier() else 'not ref'
        #     print t.get_ref_qualifier()
        #     print a.referenced.displayname
        #
        #     print node.lexical_parent.spelling

        class_dict['operators'].append(function)


    # Gather name, constness, static-ness
    elif node.kind is clang.cindex.CursorKind.CXX_METHOD:
        class_dict['methods'].append(function)
    elif node.kind is clang.cindex.CursorKind.CONSTRUCTOR:
        # print node.displayname
        # print node.location
        # for c in node.get_children():
        #     print c.spelling
        # print node.lexical_parent.spelling + str(node.lexical_parent.kind)
        # print node.semantic_parent.spelling + str(node.semantic_parent.kind)
        class_dict['ctors'].append(function)
    # TODO: template types must be handled separately
    elif node.kind is clang.cindex.CursorKind.FUNCTION_TEMPLATE:
        templates.append(node.canonical.spelling)
    # TODO: non-public dtor
    elif node.kind is clang.cindex.CursorKind.DESTRUCTOR:
        pass

    # FUNCTIONS
    elif node.kind is clang.cindex.CursorKind.FUNCTION_DECL:
        function['ret'] = node.result_type.spelling
        class_dict['functions'].append(function)


    # for c in node.get_children():
    #     get_method(c,class_dict)



skip_classes = [
    'Urho3D::PhysicsWorld2D::ContactInfo'
]

inheritance_hierarchy = {}

def get_class(node, ns, outer=None):
    if node.kind is clang.cindex.CursorKind.CLASS_DECL\
            or node.kind is clang.cindex.CursorKind.STRUCT_DECL\
            :
        if node.access_specifier in [clang.cindex.AccessSpecifier.PRIVATE,
                clang.cindex.AccessSpecifier.PROTECTED]:
            print 'Found non-public class ' + node.displayname
            return
        if len([c for c in node.get_children()]) == 0:
            print "Skipping empty class " + node.type.get_canonical().spelling
            return
        cls = dict()
        cls['class'] = node.type.get_canonical().spelling
        cls['classname'] = node.spelling
        # print str(node.canonical.displayname)
        # print node.displayname
        # print node.spelling
        # print node.canonical.spelling
        # print node.type.spelling
        # print node.type.get_canonical().spelling
        cls['inherits'] = []

        if cls['class'] in skip_classes:
            print 'per request, skipping class ' + cls['class'] + str( node.location) + str(node.access_specifier)
            return


        ref_class = False


        cls['ref-counted'] = ref_class
        # if ref_class:
            # ns['ref-classes'].append(cls)
        # else:
            # ns['nonref-classes'].append(cls)

        if not ns['classes'].has_key('class'):
            ns['classes'][cls['class']] = cls
        else:
            print "Skipping second " + cls['class']

        # print node.type.get_canonical.spelling
        # fields = [('%s %s' % (n.type.spelling, n.spelling)) for n in node.type.get_fields()]
        # print fields
        cls['ctors'] = []
        cls['methods'] = []
        cls['operators'] = []
        cls['vars'] = []
        if outer is None:
            outer = []
        cls['outer'] = outer[:]
        outer += [cls['class']]
        inheritance_hierarchy[cls['class']] = []
        for c in node.get_children():
            if c.kind is clang.cindex.CursorKind.CXX_BASE_SPECIFIER:
                name = c.type.get_canonical().spelling #c.canonical.spelling
                defn = c.canonical.get_definition()
                print 'CLASS_BASE ' + name + ' in ' + cls['class'] + str( defn.location)
                cls['inherits'].append({'base' : name})
                inheritance_hierarchy[cls['class']].append(name)
            elif c.kind is clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.spelling == 'friend':
                    # don't use just True as it may be more helpful to be able to conditionlaly add friend
                    cls['friend'] = 'friend'

            # elif c.kind is clang.cindex.CursorKind.CXX_BASE_SPECIFIER or\
            #             node.kind is clang.cindex.CursorKind.CONSTRUCTOR or\
            #             node.kind is clang.cindex.CursorKind.DESTRUCTOR or\
            #             node.kind is clang.cindex.CursorKind.CXX_METHOD:
            get_function(c, cls)
            get_variable(c, cls)
            get_class(c,ns,outer[:])




    elif node.kind is clang.cindex.CursorKind.CLASS_TEMPLATE:
        print 'Found template class ' + node.displayname
        templates.append(node.canonical.spelling)



    # for c in node.get_children():
    #     get_class(c, class_list)


        #get_field_offsetof
        #get_arguments


namespaces = [
    {
        'namespace' : 'Urho',
        'parents' : ['string', 'of', 'parents'], # ::string::of::parents::Urho
        'ref-classes' : [],
        'classes' : [],
        'functions'  : [],
        'enums' : [],
        'fields' : {
            'name' : 'global_var',
            'type' : 'int'
        }
    }
]

skip_namespaces = ['']

def get_namespace(node, ns_list, parent=[]):
    # mustache.render('{{#list | enum}} {{.0}}: {{.1}},{{/list}}', {'list': [1,2,3] )
    if node.kind is clang.cindex.CursorKind.NAMESPACE or \
            node.kind is clang.cindex.CursorKind.TRANSLATION_UNIT:
        if node.kind is clang.cindex.CursorKind.NAMESPACE:
            name = node.spelling
            print 'Namespace: ' + name
            if name == 'std' or name[0:5] == '__gnu' or name[0:5] == '__cxx':
                print 'Skipping'
                return
            print node.canonical.spelling
        else:
            name = ''
            print 'Global Namespace'
        ns = {}
        ns['namespace'] = name
        ns['full-namespace'] = '::'.join(parent + [name])
        ns['parents'] = parent[:]
        ns['force-global'] = (name in ['','Urho','Urho3D'])
        parent.append(name)
        # refclasses = []
        # classes = []
        # ns['ref-classes'] = []
        # ns['nonref-classes'] = []
        ns['classes'] = {}

        # functions = []
        ns['operators'] = []
        ns['functions'] = []
        enums = []
        # fields = []
        # constfields = []
        ns['vars'] = []
        for c in node.get_children():
            get_class(c, ns)
            get_function(c, ns)
            get_variable(c,ns) #get fields
            # get_enums(c,enums)
            # get_typedefs(c,fields)

        # ns['ref-classes'] = refclasses
        # ns['nonref-classes'] = classes
        # ns['classes'] = ns['ref-classes'] + ns['nonref-classes']
        # print (len(ns['classes']), len(ns['ref-classes']), len(ns['nonref-classes']) )
        # ns['functions'] = functions
        ns['enums'] = enums
        # ns['fields-rw'] = fields
        # ns['fields-r'] = constfields
        # ns['vars'] = fields

        #For urho, skip global:
        if name not in skip_namespaces:
            ns_list.append(ns)
    elif node.kind == clang.cindex.CursorKind.UNEXPOSED_DECL:
        for t in node.get_tokens():
            print t.spelling
    for c in node.get_children():
        get_namespace(c, ns_list, parent[:])


def fill_inheritance_heirarchy():
    #Initialize full dictionary
    full = {}
    for key in inheritance_hierarchy:
        full[key] = []
    print full
    print inheritance_hierarchy
    def add_base(key, base):
        if base not in full[key]:
            full[key].append(base)
            for newbase in inheritance_hierarchy[base]:
                add_base(key, newbase)

    #for every class
    for key in inheritance_hierarchy:
        # for every 1st level base in the class, add dependencies recursively
        for base in inheritance_hierarchy[key]:
            #add that classes bases
            add_base(key,base)

    return full

# def add_outer_classes(inher_dict, classkeylist, classdict):
#     for cn in classkeylist:
#         inher_dict[cn].append(classdict[cn]['outer'])



def merge_namespaces(ns_list):
    dict = {}
    for ns in ns_list:
        #merge data if duplicate namespaces
        if dict.has_key(ns['full-namespace']):
            present = dict[ns['full-namespace']]
            # present['ref-classes'] += ns['ref-classes']
            # present['nonref-classes'] += ns['nonref-classes']
            # present['classes'] += ns['classes']
            present['classes'].update(ns['classes'])
            present['functions'] += ns['functions']
            present['enums'] += ns['enums']
            # present['fields-rw'] += ns['fields-rw']
            # present['fields-r'] += ns['fields-r']
            present['vars'] += ns['vars']
        else:
            dict[ns['full-namespace']] = ns
    # could do del ns_list[:]; ns_list += [...]
    keys = [key for key in dict]
    keys.sort()

    inherits = fill_inheritance_heirarchy()

    #convert class dict to list
    for key in keys:
        # TODO: Must sort them by parent
        classes = dict[key]['classes']
        ks = [k for k in classes]
        # ks.sort() #Must use more complicated sorting than this
        #It requires the outer scope to be handled, which alphabetical does, but also inheritance
        def class_cmp(a,b):
            aname = a['class']
            bname = b['class']
            if aname in inherits[bname] or aname in b['outer']:
                return -1
            elif bname in inherits[aname] or bname in a['outer']:
                return 1
            else:
                return cmp(aname,bname)
        clist = [classes[k] for k in ks]
        clist.sort(cmp = class_cmp)
        dict[key]['classes'] = clist
    return [dict[key] for key in keys]


import json


def print_bools(dict, path=[]):
    if type(dict) == type({}):
        for key in dict:
            if type(dict[key]) == type(False):
                print path + [key, dict[key]]
            else:
                print_bools(dict[key], path+[key])
    elif type(dict) == type([]):
        for i,v in enumerate(dict):
            if type(v) == type(False):
                print path + [i, v]
            else:
                print_bools(v, path+[i])


def render_bindings(dict):
    template = ''
    # with open('binding.moustache') as f:
    with open('binding.mako') as f:
        for line in f:
            template += line
    print json.dumps(dict,indent=1)
    # print_bools(dict)
    # s = mustache.render(template,dict)
    s = Template(template).render(**dict)
    # print s
    with open('result.cpp','w') as f:
        f.write(s)


t = clang.cindex.Type
t._fields_

index = clang.cindex.Index.create()

tu = None
with open(sys.argv[1]) as f:
    file_data = """
#pragma once
#ifdef __BINDING_GENERATOR__
    #define friend __attribute__((annotate("friend"))) static
#endif

#include "%s"

//----------------------------------------------------
// BEGIN SOURCE
//----------------------------------------------------
""".format(sys.argv[1])
    for l in f:
        # l = re.sub(r"\bfriend\s+\b(!class|struct)"), '__attribute__((annotate("friend"))) \1'
        l = re.sub(r"\bfriend\s+\b(class|struct)\b", "//\1 friend", l)
        file_data += l
    print file_data
    tu = index.parse(sys.argv[1], ['-x', 'c++', '-std=c++14', '-D__BINDING_GENERATOR__',
           '-I/home/nathan/Projects/Urho/Urho3D/Build/include'],[(sys.argv[1],file_data)])
# tu = index.parse(sys.argv[1], ['-x', 'c++', '-std=c++14', '-D__BINDING_GENERATOR__'])
print 'Translation unit:', tu.spelling
print '================================'

if len(sys.argv) > 2 and sys.argv[2] == 'all':
    find_all(tu.cursor, '', 11)
    print 'finding all'
    exit()
else:
    # find_classes(tu.cursor,'')
    ns_list = []
    get_namespace(tu.cursor,ns_list)
    list = merge_namespaces(ns_list)
    dict = {'namespaces' : list,
            'file' : sys.argv[1]}
    #get_class(tu.cursor,class_list)
    #dict = {'ref-classes' : class_list}
    render_bindings(dict)

# test_dict = {
#     'ref-classes' : [
#         {
#             'class' : 'Object',
#             'super' : 'Ref-Counted',
#             'ctor-args' : 'Context *',
#             'methods' : [
#                 {
#                     'func' : 'Function',
#                     'ret' : 'int',
#                     'arg-types' : 'Object, int, void*',
#                     'arg-names' : [
#                         {
#                             'arg' : 'other',
#                             'default' : False,
#                         },
#                         {
#                             'arg' : 'size',
#                             'default' : True,
#                             'val' : '0'
#                         },
#                         {
#                             'arg' : 'size',
#                             'default' : True,
#                             'val' : 'nullptr'
#                         },
#                     ]
#
#                 }
#             ]
#         },
#         # {
#         # 'class' : 'Component',
#         # 'super' : 'Object'
#         # },
#     ]
# }
#
# render_bindings(test_dict)
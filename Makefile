IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

#lib: libtest_parse.so
#	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 -lpython2.7 -L . -ltest_parse -shared -fPIC -o urho.so
lib: test_parse.o bindings
	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 -lpython2.7 test_parse.o -shared -fPIC -o urho.so
	
CXX_FLAGS = -std=gnu++14 -g3 -gdwarf-2 -Wno-invalid-offsetof -pthread -DURHO3D_CXX11=1 -DURHO3D_FMT -g -DDEBUG -D_DEBUG  

CXX_DEFINES = -DGLEW_NO_GLU -DGLEW_STATIC -DURHO3D_ANGELSCRIPT -DURHO3D_CPP11 -DURHO3D_LOGGING -DURHO3D_NAVIGATION -DURHO3D_NETWORK -DURHO3D_OPENGL -DURHO3D_PHYSICS -DURHO3D_PROFILING -DURHO3D_SSE -DURHO3D_STATIC_DEFINE -DURHO3D_THREADING -DURHO3D_URHO2D

CXX_INCLUDES =  -I/home/nathan/Projects/Urho/Urho3D/Build/include/ -I/usr/local/include -I/home/nathan/Projects/Urho/Urho3D/Build/include/Urho3D/ThirdParty -I/usr/local/include/Urho3D/ThirdParty -I/usr/local/include/Urho3D/ThirdParty/Bullet -I/usr/local/include/Urho3D

LINK_TARGET = -ldl -lrt -lGL


urholib: urhobindings
	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 $(CXX_INCLUDES) -lpython2.7 -L . -lUrho3D $(LINK_TARGET) $(CXX_DEFINES) -shared -fPIC -o urho.so
#	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I/home/nathan/Projects/Urho/Urho3D/Build/include -I /usr/include/python2.7 -lpython2.7 -L . -lUrho3D -shared -fPIC -o urho.so
#	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 -lpython2.7 /home/nathan/Projects/Urho/Urho3D/Build/lib/libUrho3D.so.0 -shared -fPIC -o urho.so
#	g++ result.cpp -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 -lpython2.7 /usr/local/lib/Urho3D/libUrho3D.a -shared -fPIC -o urho.so

# preprocess command: g++ -E Urho3DAll.h -P -std=c++14 -I /home/nathan/Desktop/testClang/PythonBindings/pybind11/include -I /usr/include/python2.7 -I/home/nathan/Projects/Urho/Urho3D/Build/include/ -I/usr/local/include -I/home/nathan/Projects/Urho/Urho3D/Build/include/Urho3D/ThirdParty -I/usr/local/include/Urho3D/ThirdParty -I/usr/local/include/Urho3D/ThirdParty/Bullet -I/usr/local/include/Urho3D -lpython2.7 -L . -lUrho3D -ldl -lrt -lGL -DGLEW_NO_GLU -DGLEW_STATIC -DURHO3D_ANGELSCRIPT -DURHO3D_CPP11 -DURHO3D_LOGGING -DURHO3D_NAVIGATION -DURHO3D_NETWORK -DURHO3D_OPENGL -DURHO3D_PHYSICS -DURHO3D_PROFILING -DURHO3D_SSE -DURHO3D_STATIC_DEFINE -DURHO3D_THREADING -DURHO3D_URHO2D -shared -fPIC


urhobindings: generate.py test_parse.h
	python generate.py Urho3DProcessed.h
#	python generate.py Urho3DAll.h

#urhobindings: generate.py test_parse.h
#	python generate.py Vector3.h
	
urhoprint: generate.py test_parse.h
	python generate.py Vector3.h all

bindings: generate.py test_parse.h
	python generate.py test_parse.h al
	
print: generate.py test_parse.h
	python generate.py test_parse.h all
	
testcpp: libtest_parse.a

test: test.py
	python test.py

test_parse.o: test_parse.cpp test_parse.h
	g++ -c test_parse.cpp -std=c++14 -static -fPIC -o test_parse.o
	
libtest_parse.a: test_parse.o
	g++ test_parse.o -std=c++14 -static -fPIC -o libtest_parse.a
	
libtest_parse.so: test_parse.o
	g++ test_parse.o -std=c++14 -shared -fPIC -o libtest_parse.so

#ODIR=obj
#LDIR =../lib

#LIBS=-lm

#_DEPS = hellomake.h
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = hellomake.o hellofunc.o 
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


#$(ODIR)/%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#hellomake: $(OBJ)
#	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

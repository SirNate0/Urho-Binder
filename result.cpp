#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <memory>



typedef unsigned long long unsignedlonglong;
typedef unsigned int unsignedint;
typedef unsigned short unsignedshort;
typedef unsigned long unsignedlong;
typedef long long longlong;

#include "String_binding.h"

/*#include "Urho3DProcessed.h"*/
#include "Urho3DAll.h"

namespace py = pybind11;

PYBIND11_MODULE(urho, m) {

//-------------------------------------------
// Export Urho3D namespace as a class
//-------------------------------------------
auto pyclass_NS__Urho3D = m
  // Functions
  .def("AllocatorInitialize", (Urho3D::AllocatorBlock * (*)(unsigned int, unsigned int)) &::Urho3D::AllocatorInitialize, "todo: docstring", py::arg("nodeSize"), py::arg("initialCapacity")=1)
  .def("AllocatorUninitialize", (void (*)(Urho3D::AllocatorBlock *)) &::Urho3D::AllocatorUninitialize, "todo: docstring", py::arg("allocator"))
  .def("AllocatorReserve", (void * (*)(Urho3D::AllocatorBlock *)) &::Urho3D::AllocatorReserve, "todo: docstring", py::arg("allocator"))
  .def("AllocatorFree", (void (*)(Urho3D::AllocatorBlock *, void *)) &::Urho3D::AllocatorFree, "todo: docstring", py::arg("allocator"), py::arg("ptr"))
  .def("RegisterArray", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterArray, "todo: docstring", py::arg("engine"))
  .def("RegisterDictionary", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterDictionary, "todo: docstring", py::arg("engine"))
  .def("RegisterString", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterString, "todo: docstring", py::arg("engine"))
  .def("SetRandomSeed", (void (*)(unsigned int)) &::Urho3D::SetRandomSeed, "todo: docstring", py::arg("seed"))
  .def("GetRandomSeed", (unsigned int (*)()) &::Urho3D::GetRandomSeed, "todo: docstring")
  .def("Rand", (int (*)()) &::Urho3D::Rand, "todo: docstring")
  .def("RandStandardNormal", (float (*)()) &::Urho3D::RandStandardNormal, "todo: docstring")
  .def("FloatToRawIntBits", (unsigned int (*)(float)) &::Urho3D::FloatToRawIntBits, "todo: docstring", py::arg("value"))
  .def("IsNaN", (bool (*)(float)) &::Urho3D::IsNaN, "todo: docstring", py::arg("value"))
  .def("IsPowerOfTwo", (bool (*)(unsigned int)) &::Urho3D::IsPowerOfTwo, "todo: docstring", py::arg("value"))
  .def("NextPowerOfTwo", (unsigned int (*)(unsigned int)) &::Urho3D::NextPowerOfTwo, "todo: docstring", py::arg("value"))
  .def("CountSetBits", (unsigned int (*)(unsigned int)) &::Urho3D::CountSetBits, "todo: docstring", py::arg("value"))
  .def("SDBMHash", (unsigned int (*)(unsigned int, unsigned char)) &::Urho3D::SDBMHash, "todo: docstring", py::arg("hash"), py::arg("c"))
  .def("Random", (float (*)()) &::Urho3D::Random, "todo: docstring")
  .def("Random", (float (*)(float)) &::Urho3D::Random, "todo: docstring", py::arg("range"))
  .def("Random", (float (*)(float, float)) &::Urho3D::Random, "todo: docstring", py::arg("min"), py::arg("max"))
  .def("Random", (int (*)(int)) &::Urho3D::Random, "todo: docstring", py::arg("range"))
  .def("Random", (int (*)(int, int)) &::Urho3D::Random, "todo: docstring", py::arg("min"), py::arg("max"))
  .def("RandomNormal", (float (*)(float, float)) &::Urho3D::RandomNormal, "todo: docstring", py::arg("meanValue"), py::arg("variance"))
  .def("FloatToHalf", (unsigned short (*)(float)) &::Urho3D::FloatToHalf, "todo: docstring", py::arg("value"))
  .def("HalfToFloat", (float (*)(unsigned short)) &::Urho3D::HalfToFloat, "todo: docstring", py::arg("value"))
  .def("SinCos", (void (*)(float, float &, float &)) &::Urho3D::SinCos, "todo: docstring", py::arg("angle"), py::arg("sin"), py::arg("cos"))
  .def("VectorLerp", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &, const Urho3D::Vector2 &, const Urho3D::Vector2 &)) &::Urho3D::VectorLerp, "todo: docstring", py::arg("lhs"), py::arg("rhs"), py::arg("t"))
  .def("VectorMin", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &, const Urho3D::Vector2 &)) &::Urho3D::VectorMin, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorMax", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &, const Urho3D::Vector2 &)) &::Urho3D::VectorMax, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorFloor", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorFloor, "todo: docstring", py::arg("vec"))
  .def("VectorRound", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorRound, "todo: docstring", py::arg("vec"))
  .def("VectorCeil", (Urho3D::Vector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorCeil, "todo: docstring", py::arg("vec"))
  .def("VectorFloorToInt", (Urho3D::IntVector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorFloorToInt, "todo: docstring", py::arg("vec"))
  .def("VectorRoundToInt", (Urho3D::IntVector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorRoundToInt, "todo: docstring", py::arg("vec"))
  .def("VectorCeilToInt", (Urho3D::IntVector2 (*)(const Urho3D::Vector2 &)) &::Urho3D::VectorCeilToInt, "todo: docstring", py::arg("vec"))
  .def("VectorMin", (Urho3D::IntVector2 (*)(const Urho3D::IntVector2 &, const Urho3D::IntVector2 &)) &::Urho3D::VectorMin, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorMax", (Urho3D::IntVector2 (*)(const Urho3D::IntVector2 &, const Urho3D::IntVector2 &)) &::Urho3D::VectorMax, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("StableRandom", (float (*)(const Urho3D::Vector2 &)) &::Urho3D::StableRandom, "todo: docstring", py::arg("seed"))
  .def("StableRandom", (float (*)(float)) &::Urho3D::StableRandom, "todo: docstring", py::arg("seed"))
  .def("VectorLerp", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &, const Urho3D::Vector3 &, const Urho3D::Vector3 &)) &::Urho3D::VectorLerp, "todo: docstring", py::arg("lhs"), py::arg("rhs"), py::arg("t"))
  .def("VectorMin", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &, const Urho3D::Vector3 &)) &::Urho3D::VectorMin, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorMax", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &, const Urho3D::Vector3 &)) &::Urho3D::VectorMax, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorFloor", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorFloor, "todo: docstring", py::arg("vec"))
  .def("VectorRound", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorRound, "todo: docstring", py::arg("vec"))
  .def("VectorCeil", (Urho3D::Vector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorCeil, "todo: docstring", py::arg("vec"))
  .def("VectorFloorToInt", (Urho3D::IntVector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorFloorToInt, "todo: docstring", py::arg("vec"))
  .def("VectorRoundToInt", (Urho3D::IntVector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorRoundToInt, "todo: docstring", py::arg("vec"))
  .def("VectorCeilToInt", (Urho3D::IntVector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::VectorCeilToInt, "todo: docstring", py::arg("vec"))
  .def("VectorMin", (Urho3D::IntVector3 (*)(const Urho3D::IntVector3 &, const Urho3D::IntVector3 &)) &::Urho3D::VectorMin, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorMax", (Urho3D::IntVector3 (*)(const Urho3D::IntVector3 &, const Urho3D::IntVector3 &)) &::Urho3D::VectorMax, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("StableRandom", (float (*)(const Urho3D::Vector3 &)) &::Urho3D::StableRandom, "todo: docstring", py::arg("seed"))
  .def("VectorLerp", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &, const Urho3D::Vector4 &, const Urho3D::Vector4 &)) &::Urho3D::VectorLerp, "todo: docstring", py::arg("lhs"), py::arg("rhs"), py::arg("t"))
  .def("VectorMin", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &, const Urho3D::Vector4 &)) &::Urho3D::VectorMin, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorMax", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &, const Urho3D::Vector4 &)) &::Urho3D::VectorMax, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("VectorFloor", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &)) &::Urho3D::VectorFloor, "todo: docstring", py::arg("vec"))
  .def("VectorRound", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &)) &::Urho3D::VectorRound, "todo: docstring", py::arg("vec"))
  .def("VectorCeil", (Urho3D::Vector4 (*)(const Urho3D::Vector4 &)) &::Urho3D::VectorCeil, "todo: docstring", py::arg("vec"))
  .def("RegisterScriptLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterScriptLibrary, "todo: docstring", py::arg("context"))
  .def("GetActiveASContext", (asIScriptContext * (*)()) &::Urho3D::GetActiveASContext, "todo: docstring")
  .def("GetScriptContext", (Urho3D::Context * (*)()) &::Urho3D::GetScriptContext, "todo: docstring")
  .def("GetScriptContextInstance", (Urho3D::ScriptInstance * (*)()) &::Urho3D::GetScriptContextInstance, "todo: docstring")
  .def("GetScriptContextNode", (Urho3D::Node * (*)()) &::Urho3D::GetScriptContextNode, "todo: docstring")
  .def("GetScriptContextScene", (Urho3D::Scene * (*)()) &::Urho3D::GetScriptContextScene, "todo: docstring")
  .def("GetScriptContextEventListener", (Urho3D::ScriptEventListener * (*)()) &::Urho3D::GetScriptContextEventListener, "todo: docstring")
  .def("GetScriptContextEventListenerObject", (Urho3D::Object * (*)()) &::Urho3D::GetScriptContextEventListenerObject, "todo: docstring")
  .def("CompareDrawables", (bool (*)(Urho3D::Drawable *, Urho3D::Drawable *)) &::Urho3D::CompareDrawables, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("WriteDrawablesToOBJ", (bool (*)(PODVector<Urho3D::Drawable *>, Urho3D::File *, bool, bool, bool)) &::Urho3D::WriteDrawablesToOBJ, "todo: docstring", py::arg("drawables"), py::arg("outputFile"), py::arg("asZUp"), py::arg("asRightHanded"), py::arg("writeLightmapUV")=false)
  .def("GetResourceName", (const Urho3D::String & (*)(Urho3D::Resource *)) &::Urho3D::GetResourceName, "todo: docstring", py::arg("resource"))
  .def("GetResourceType", (Urho3D::StringHash (*)(Urho3D::Resource *, Urho3D::StringHash)) &::Urho3D::GetResourceType, "todo: docstring", py::arg("resource"), py::arg("defaultType"))
  .def("GetResourceRef", (Urho3D::ResourceRef (*)(Urho3D::Resource *, Urho3D::StringHash)) &::Urho3D::GetResourceRef, "todo: docstring", py::arg("resource"), py::arg("defaultType"))
  .def("ToBool", (bool (*)(const Urho3D::String &)) &::Urho3D::ToBool, "todo: docstring", py::arg("source"))
  .def("ToBool", (bool (*)(const char *)) &::Urho3D::ToBool, "todo: docstring", py::arg("source"))
  .def("ToFloat", (float (*)(const Urho3D::String &)) &::Urho3D::ToFloat, "todo: docstring", py::arg("source"))
  .def("ToFloat", (float (*)(const char *)) &::Urho3D::ToFloat, "todo: docstring", py::arg("source"))
  .def("ToDouble", (double (*)(const Urho3D::String &)) &::Urho3D::ToDouble, "todo: docstring", py::arg("source"))
  .def("ToDouble", (double (*)(const char *)) &::Urho3D::ToDouble, "todo: docstring", py::arg("source"))
  .def("ToInt", (int (*)(const Urho3D::String &, int)) &::Urho3D::ToInt, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToInt", (int (*)(const char *, int)) &::Urho3D::ToInt, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToUInt", (unsigned int (*)(const Urho3D::String &, int)) &::Urho3D::ToUInt, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToUInt", (unsigned int (*)(const char *, int)) &::Urho3D::ToUInt, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToInt64", (long long (*)(const Urho3D::String &, int)) &::Urho3D::ToInt64, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToInt64", (long long (*)(const char *, int)) &::Urho3D::ToInt64, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToUInt64", (unsigned long long (*)(const Urho3D::String &, int)) &::Urho3D::ToUInt64, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToUInt64", (unsigned long long (*)(const char *, int)) &::Urho3D::ToUInt64, "todo: docstring", py::arg("source"), py::arg("base")=10)
  .def("ToColor", (Urho3D::Color (*)(const Urho3D::String &)) &::Urho3D::ToColor, "todo: docstring", py::arg("source"))
  .def("ToColor", (Urho3D::Color (*)(const char *)) &::Urho3D::ToColor, "todo: docstring", py::arg("source"))
  .def("ToIntRect", (Urho3D::IntRect (*)(const Urho3D::String &)) &::Urho3D::ToIntRect, "todo: docstring", py::arg("source"))
  .def("ToIntRect", (Urho3D::IntRect (*)(const char *)) &::Urho3D::ToIntRect, "todo: docstring", py::arg("source"))
  .def("ToIntVector2", (Urho3D::IntVector2 (*)(const Urho3D::String &)) &::Urho3D::ToIntVector2, "todo: docstring", py::arg("source"))
  .def("ToIntVector2", (Urho3D::IntVector2 (*)(const char *)) &::Urho3D::ToIntVector2, "todo: docstring", py::arg("source"))
  .def("ToIntVector3", (Urho3D::IntVector3 (*)(const Urho3D::String &)) &::Urho3D::ToIntVector3, "todo: docstring", py::arg("source"))
  .def("ToIntVector3", (Urho3D::IntVector3 (*)(const char *)) &::Urho3D::ToIntVector3, "todo: docstring", py::arg("source"))
  .def("ToQuaternion", (Urho3D::Quaternion (*)(const Urho3D::String &)) &::Urho3D::ToQuaternion, "todo: docstring", py::arg("source"))
  .def("ToQuaternion", (Urho3D::Quaternion (*)(const char *)) &::Urho3D::ToQuaternion, "todo: docstring", py::arg("source"))
  .def("ToRect", (Urho3D::Rect (*)(const Urho3D::String &)) &::Urho3D::ToRect, "todo: docstring", py::arg("source"))
  .def("ToRect", (Urho3D::Rect (*)(const char *)) &::Urho3D::ToRect, "todo: docstring", py::arg("source"))
  .def("ToVector2", (Urho3D::Vector2 (*)(const Urho3D::String &)) &::Urho3D::ToVector2, "todo: docstring", py::arg("source"))
  .def("ToVector2", (Urho3D::Vector2 (*)(const char *)) &::Urho3D::ToVector2, "todo: docstring", py::arg("source"))
  .def("ToVector3", (Urho3D::Vector3 (*)(const Urho3D::String &)) &::Urho3D::ToVector3, "todo: docstring", py::arg("source"))
  .def("ToVector3", (Urho3D::Vector3 (*)(const char *)) &::Urho3D::ToVector3, "todo: docstring", py::arg("source"))
  .def("ToVector4", (Urho3D::Vector4 (*)(const Urho3D::String &, bool)) &::Urho3D::ToVector4, "todo: docstring", py::arg("source"), py::arg("allowMissingCoords")=false)
  .def("ToVector4", (Urho3D::Vector4 (*)(const char *, bool)) &::Urho3D::ToVector4, "todo: docstring", py::arg("source"), py::arg("allowMissingCoords")=false)
  .def("ToVectorVariant", (Urho3D::Variant (*)(const Urho3D::String &)) &::Urho3D::ToVectorVariant, "todo: docstring", py::arg("source"))
  .def("ToVectorVariant", (Urho3D::Variant (*)(const char *)) &::Urho3D::ToVectorVariant, "todo: docstring", py::arg("source"))
  .def("ToMatrix3", (Urho3D::Matrix3 (*)(const Urho3D::String &)) &::Urho3D::ToMatrix3, "todo: docstring", py::arg("source"))
  .def("ToMatrix3", (Urho3D::Matrix3 (*)(const char *)) &::Urho3D::ToMatrix3, "todo: docstring", py::arg("source"))
  .def("ToMatrix3x4", (Urho3D::Matrix3x4 (*)(const Urho3D::String &)) &::Urho3D::ToMatrix3x4, "todo: docstring", py::arg("source"))
  .def("ToMatrix3x4", (Urho3D::Matrix3x4 (*)(const char *)) &::Urho3D::ToMatrix3x4, "todo: docstring", py::arg("source"))
  .def("ToMatrix4", (Urho3D::Matrix4 (*)(const Urho3D::String &)) &::Urho3D::ToMatrix4, "todo: docstring", py::arg("source"))
  .def("ToMatrix4", (Urho3D::Matrix4 (*)(const char *)) &::Urho3D::ToMatrix4, "todo: docstring", py::arg("source"))
  .def("ToString", (Urho3D::String (*)(void *)) &::Urho3D::ToString, "todo: docstring", py::arg("value"))
  .def("ToStringHex", (Urho3D::String (*)(unsigned int)) &::Urho3D::ToStringHex, "todo: docstring", py::arg("value"))
  .def("BufferToString", (void (*)(Urho3D::String &, const void *, unsigned int)) &::Urho3D::BufferToString, "todo: docstring", py::arg("dest"), py::arg("data"), py::arg("size"))
  .def("StringToBuffer", (void (*)(PODVector<unsigned char> &, const Urho3D::String &)) &::Urho3D::StringToBuffer, "todo: docstring", py::arg("dest"), py::arg("source"))
  .def("StringToBuffer", (void (*)(PODVector<unsigned char> &, const char *)) &::Urho3D::StringToBuffer, "todo: docstring", py::arg("dest"), py::arg("source"))
  .def("GetStringListIndex", (unsigned int (*)(const Urho3D::String &, const Urho3D::String *, unsigned int, bool)) &::Urho3D::GetStringListIndex, "todo: docstring", py::arg("value"), py::arg("strings"), py::arg("defaultIndex"), py::arg("caseSensitive")=false)
  .def("GetStringListIndex", (unsigned int (*)(const char *, const Urho3D::String *, unsigned int, bool)) &::Urho3D::GetStringListIndex, "todo: docstring", py::arg("value"), py::arg("strings"), py::arg("defaultIndex"), py::arg("caseSensitive")=false)
  .def("IsAlpha", (bool (*)(unsigned int)) &::Urho3D::IsAlpha, "todo: docstring", py::arg("ch"))
  .def("IsDigit", (bool (*)(unsigned int)) &::Urho3D::IsDigit, "todo: docstring", py::arg("ch"))
  .def("ToUpper", (unsigned int (*)(unsigned int)) &::Urho3D::ToUpper, "todo: docstring", py::arg("ch"))
  .def("ToLower", (unsigned int (*)(unsigned int)) &::Urho3D::ToLower, "todo: docstring", py::arg("ch"))
  .def("GetFileSizeString", (Urho3D::String (*)(unsigned long long)) &::Urho3D::GetFileSizeString, "todo: docstring", py::arg("memorySize"))
  .def("DecodeBase64", (PODVector<unsigned char> (*)(Urho3D::String)) &::Urho3D::DecodeBase64, "todo: docstring", py::arg("encoded_string"))
  .def("SerializableGetAttributeInfo", (const Urho3D::AttributeInfo & (*)(unsigned int, Urho3D::Serializable *)) &::Urho3D::SerializableGetAttributeInfo, "todo: docstring", py::arg("index"), py::arg("ptr"))
  .def("SerializableLoad", (bool (*)(Urho3D::File *, bool, Urho3D::Serializable *)) &::Urho3D::SerializableLoad, "todo: docstring", py::arg("file"), py::arg("setInstanceDefault"), py::arg("ptr"))
  .def("SerializableLoadVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, bool, Urho3D::Serializable *)) &::Urho3D::SerializableLoadVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("setInstanceDefault"), py::arg("ptr"))
  .def("SerializableSave", (bool (*)(Urho3D::File *, Urho3D::Serializable *)) &::Urho3D::SerializableSave, "todo: docstring", py::arg("file"), py::arg("ptr"))
  .def("SerializableSaveVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, Urho3D::Serializable *)) &::Urho3D::SerializableSaveVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("ptr"))
  .def("NodeCreateComponent", (Urho3D::Component * (*)(const Urho3D::String &, Urho3D::CreateMode, unsigned int, Urho3D::Node *)) &::Urho3D::NodeCreateComponent, "todo: docstring", py::arg("typeName"), py::arg("mode"), py::arg("id"), py::arg("ptr"))
  .def("NodeGetOrCreateComponent", (Urho3D::Component * (*)(const Urho3D::String &, Urho3D::CreateMode, unsigned int, Urho3D::Node *)) &::Urho3D::NodeGetOrCreateComponent, "todo: docstring", py::arg("typeName"), py::arg("mode"), py::arg("id"), py::arg("ptr"))
  .def("NodeRemoveComponent", (void (*)(const Urho3D::String &, Urho3D::Node *)) &::Urho3D::NodeRemoveComponent, "todo: docstring", py::arg("typeName"), py::arg("ptr"))
  .def("NodeRemoveComponents", (void (*)(const Urho3D::String &, Urho3D::Node *)) &::Urho3D::NodeRemoveComponents, "todo: docstring", py::arg("typeName"), py::arg("ptr"))
  .def("NodeGetComponent", (Urho3D::Component * (*)(unsigned int, Urho3D::Node *)) &::Urho3D::NodeGetComponent, "todo: docstring", py::arg("index"), py::arg("ptr"))
  .def("NodeGetComponentWithType", (Urho3D::Component * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetComponentWithType, "todo: docstring", py::arg("typeName"), py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetParentComponentWithType", (Urho3D::Component * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetParentComponentWithType, "todo: docstring", py::arg("typeName"), py::arg("fullTraversal"), py::arg("ptr"))
  .def("NodeGetComponents", (Urho3D::CScriptArray * (*)(Urho3D::Node *)) &::Urho3D::NodeGetComponents, "todo: docstring", py::arg("ptr"))
  .def("NodeGetComponentsWithType", (Urho3D::CScriptArray * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetComponentsWithType, "todo: docstring", py::arg("typeName"), py::arg("recursive"), py::arg("ptr"))
  .def("NodeHasComponent", (bool (*)(const Urho3D::String &, Urho3D::Node *)) &::Urho3D::NodeHasComponent, "todo: docstring", py::arg("typeName"), py::arg("ptr"))
  .def("NodeGetChildren", (Urho3D::CScriptArray * (*)(bool, Urho3D::Node *)) &::Urho3D::NodeGetChildren, "todo: docstring", py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetChildrenWithComponent", (Urho3D::CScriptArray * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetChildrenWithComponent, "todo: docstring", py::arg("typeName"), py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetChildrenWithTag", (Urho3D::CScriptArray * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetChildrenWithTag, "todo: docstring", py::arg("typeName"), py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetTags", (Urho3D::CScriptArray * (*)(Urho3D::Node *)) &::Urho3D::NodeGetTags, "todo: docstring", py::arg("ptr"))
  .def("NodeGetNumChildrenNonRecursive", (unsigned int (*)(Urho3D::Node *)) &::Urho3D::NodeGetNumChildrenNonRecursive, "todo: docstring", py::arg("ptr"))
  .def("NodeGetNumChildrenRecursive", (unsigned int (*)(Urho3D::Node *)) &::Urho3D::NodeGetNumChildrenRecursive, "todo: docstring", py::arg("ptr"))
  .def("NodeGetChild", (Urho3D::Node * (*)(unsigned int, Urho3D::Node *)) &::Urho3D::NodeGetChild, "todo: docstring", py::arg("index"), py::arg("ptr"))
  .def("NodeGetChildByName", (Urho3D::Node * (*)(const Urho3D::String &, Urho3D::Node *)) &::Urho3D::NodeGetChildByName, "todo: docstring", py::arg("name"), py::arg("ptr"))
  .def("NodeGetChildByNameRecursive", (Urho3D::Node * (*)(const Urho3D::String &, Urho3D::Node *)) &::Urho3D::NodeGetChildByNameRecursive, "todo: docstring", py::arg("name"), py::arg("ptr"))
  .def("NodeGetChildrenWithScript", (Urho3D::CScriptArray * (*)(bool, Urho3D::Node *)) &::Urho3D::NodeGetChildrenWithScript, "todo: docstring", py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetChildrenWithClassName", (Urho3D::CScriptArray * (*)(const Urho3D::String &, bool, Urho3D::Node *)) &::Urho3D::NodeGetChildrenWithClassName, "todo: docstring", py::arg("className"), py::arg("recursive"), py::arg("ptr"))
  .def("NodeGetVars", (VariantMap & (*)(Urho3D::Node *)) &::Urho3D::NodeGetVars, "todo: docstring", py::arg("ptr"))
  .def("ResourceLoad", (bool (*)(Urho3D::File *, Urho3D::Resource *)) &::Urho3D::ResourceLoad, "todo: docstring", py::arg("file"), py::arg("ptr"))
  .def("ResourceLoadVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, Urho3D::Resource *)) &::Urho3D::ResourceLoadVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("ptr"))
  .def("ResourceLoadByName", (bool (*)(const Urho3D::String &, Urho3D::Resource *)) &::Urho3D::ResourceLoadByName, "todo: docstring", py::arg("fileName"), py::arg("ptr"))
  .def("ResourceSave", (bool (*)(Urho3D::File *, Urho3D::Resource *)) &::Urho3D::ResourceSave, "todo: docstring", py::arg("file"), py::arg("ptr"))
  .def("ResourceSaveVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, Urho3D::Resource *)) &::Urho3D::ResourceSaveVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("ptr"))
  .def("ResourceSaveByName", (bool (*)(const Urho3D::String &, Urho3D::Resource *)) &::Urho3D::ResourceSaveByName, "todo: docstring", py::arg("fileName"), py::arg("ptr"))
  .def("ResourceAddMetadata", (void (*)(const Urho3D::String &, const Urho3D::Variant &, Urho3D::ResourceWithMetadata *)) &::Urho3D::ResourceAddMetadata, "todo: docstring", py::arg("name"), py::arg("value"), py::arg("ptr"))
  .def("ResourceGetMetadata", (const Urho3D::Variant & (*)(const Urho3D::String &, Urho3D::ResourceWithMetadata *)) &::Urho3D::ResourceGetMetadata, "todo: docstring", py::arg("name"), py::arg("ptr"))
  .def("ResourceHasMetadata", (bool (*)(Urho3D::ResourceWithMetadata *)) &::Urho3D::ResourceHasMetadata, "todo: docstring", py::arg("ptr"))
  .def("UIElementLoadXML", (bool (*)(Urho3D::File *, Urho3D::UIElement *)) &::Urho3D::UIElementLoadXML, "todo: docstring", py::arg("file"), py::arg("ptr"))
  .def("UIElementLoadXMLVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, Urho3D::UIElement *)) &::Urho3D::UIElementLoadXMLVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("ptr"))
  .def("UIElementLoadXML", (bool (*)(Urho3D::XMLFile *, Urho3D::XMLFile *, Urho3D::UIElement *)) &::Urho3D::UIElementLoadXML, "todo: docstring", py::arg("file"), py::arg("styleFile"), py::arg("ptr"))
  .def("UIElementLoadChildXML", (Urho3D::UIElement * (*)(Urho3D::XMLFile *, Urho3D::XMLFile *, Urho3D::UIElement *)) &::Urho3D::UIElementLoadChildXML, "todo: docstring", py::arg("file"), py::arg("styleFile"), py::arg("ptr"))
  .def("UIElementSaveXML", (bool (*)(Urho3D::File *, const Urho3D::String &, Urho3D::UIElement *)) &::Urho3D::UIElementSaveXML, "todo: docstring", py::arg("file"), py::arg("indentation"), py::arg("ptr"))
  .def("UIElementSaveXMLVectorBuffer", (bool (*)(Urho3D::VectorBuffer &, const Urho3D::String &, Urho3D::UIElement *)) &::Urho3D::UIElementSaveXMLVectorBuffer, "todo: docstring", py::arg("buffer"), py::arg("indentation"), py::arg("ptr"))
  .def("UIElementCreateChild", (Urho3D::UIElement * (*)(const Urho3D::String &, const Urho3D::String &, unsigned int, Urho3D::UIElement *)) &::Urho3D::UIElementCreateChild, "todo: docstring", py::arg("typeName"), py::arg("name"), py::arg("index"), py::arg("ptr"))
  .def("UIElementRemoveChild", (void (*)(Urho3D::UIElement *, unsigned int, Urho3D::UIElement *)) &::Urho3D::UIElementRemoveChild, "todo: docstring", py::arg("child"), py::arg("index"), py::arg("ptr"))
  .def("UIElementRemoveChild", (void (*)(unsigned int, Urho3D::UIElement *)) &::Urho3D::UIElementRemoveChild, "todo: docstring", py::arg("index"), py::arg("ptr"))
  .def("UIElementGetChildren", (Urho3D::CScriptArray * (*)(bool, Urho3D::UIElement *)) &::Urho3D::UIElementGetChildren, "todo: docstring", py::arg("recursive"), py::arg("ptr"))
  .def("UIElementGetChildrenWithTag", (Urho3D::CScriptArray * (*)(const Urho3D::String &, bool, Urho3D::UIElement *)) &::Urho3D::UIElementGetChildrenWithTag, "todo: docstring", py::arg("tag"), py::arg("recursive"), py::arg("ptr"))
  .def("UIElementGetTags", (Urho3D::CScriptArray * (*)(Urho3D::UIElement *)) &::Urho3D::UIElementGetTags, "todo: docstring", py::arg("ptr"))
  .def("UIElementGetNumChildrenNonRecursive", (unsigned int (*)(Urho3D::UIElement *)) &::Urho3D::UIElementGetNumChildrenNonRecursive, "todo: docstring", py::arg("ptr"))
  .def("UIElementGetNumChildrenRecursive", (unsigned int (*)(Urho3D::UIElement *)) &::Urho3D::UIElementGetNumChildrenRecursive, "todo: docstring", py::arg("ptr"))
  .def("UIElementSetParent", (void (*)(Urho3D::UIElement *, Urho3D::UIElement *)) &::Urho3D::UIElementSetParent, "todo: docstring", py::arg("parent"), py::arg("ptr"))
  .def("UIElementGetVars", (VariantMap & (*)(Urho3D::UIElement *)) &::Urho3D::UIElementGetVars, "todo: docstring", py::arg("ptr"))
  .def("UIElementSetStyle", (void (*)(const Urho3D::String &, Urho3D::UIElement *)) &::Urho3D::UIElementSetStyle, "todo: docstring", py::arg("styleName"), py::arg("ptr"))
  .def("UIElementGetDefaultStyle", (Urho3D::XMLFile * (*)(Urho3D::UIElement *)) &::Urho3D::UIElementGetDefaultStyle, "todo: docstring", py::arg("ptr"))
  .def("RegisterMathAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterMathAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterCoreAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterCoreAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterIOAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterIOAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterResourceAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterResourceAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterSceneAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterSceneAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterGraphicsAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterGraphicsAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterInputAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterInputAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterAudioAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterAudioAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterUIAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterUIAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterNetworkAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterNetworkAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterPhysicsAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterPhysicsAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterRaycastVehicleAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterRaycastVehicleAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterNavigationAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterNavigationAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterUrho2DAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterUrho2DAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterScriptInterfaceAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterScriptInterfaceAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterScriptAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterScriptAPI, "todo: docstring", py::arg("engine"))
  .def("RegisterEngineAPI", (void (*)(asIScriptEngine *)) &::Urho3D::RegisterEngineAPI, "todo: docstring", py::arg("engine"))
  .def("GetScriptContextFile", (Urho3D::ScriptFile * (*)()) &::Urho3D::GetScriptContextFile, "todo: docstring")
  .def("RegisterAudioLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterAudioLibrary, "todo: docstring", py::arg("context"))
  .def("InitFPU", (void (*)()) &::Urho3D::InitFPU, "todo: docstring")
  .def("ErrorDialog", (void (*)(const Urho3D::String &, const Urho3D::String &)) &::Urho3D::ErrorDialog, "todo: docstring", py::arg("title"), py::arg("message"))
  .def("ErrorExit", (void (*)(const Urho3D::String &, int)) &::Urho3D::ErrorExit, "todo: docstring", py::arg("message")=String::EMPTY, py::arg("exitCode")=1)
  .def("OpenConsoleWindow", (void (*)()) &::Urho3D::OpenConsoleWindow, "todo: docstring")
  .def("PrintUnicode", (void (*)(const Urho3D::String &, bool)) &::Urho3D::PrintUnicode, "todo: docstring", py::arg("str"), py::arg("error")=false)
  .def("PrintUnicodeLine", (void (*)(const Urho3D::String &, bool)) &::Urho3D::PrintUnicodeLine, "todo: docstring", py::arg("str"), py::arg("error")=false)
  .def("PrintLine", (void (*)(const Urho3D::String &, bool)) &::Urho3D::PrintLine, "todo: docstring", py::arg("str"), py::arg("error")=false)
  .def("ParseArguments", (const Vector<Urho3D::String> & (*)(const Urho3D::String &, bool)) &::Urho3D::ParseArguments, "todo: docstring", py::arg("cmdLine"), py::arg("skipFirstArgument")=true)
  .def("ParseArguments", (const Vector<Urho3D::String> & (*)(const char *)) &::Urho3D::ParseArguments, "todo: docstring", py::arg("cmdLine"))
  .def("ParseArguments", (const Vector<Urho3D::String> & (*)(const Urho3D::WString &)) &::Urho3D::ParseArguments, "todo: docstring", py::arg("cmdLine"))
  .def("ParseArguments", (const Vector<Urho3D::String> & (*)(const wchar_t *)) &::Urho3D::ParseArguments, "todo: docstring", py::arg("cmdLine"))
  .def("GetArguments", (const Vector<Urho3D::String> & (*)()) &::Urho3D::GetArguments, "todo: docstring")
  .def("GetConsoleInput", (Urho3D::String (*)()) &::Urho3D::GetConsoleInput, "todo: docstring")
  .def("GetPlatform", (Urho3D::String (*)()) &::Urho3D::GetPlatform, "todo: docstring")
  .def("GetNumPhysicalCPUs", (unsigned int (*)()) &::Urho3D::GetNumPhysicalCPUs, "todo: docstring")
  .def("GetNumLogicalCPUs", (unsigned int (*)()) &::Urho3D::GetNumLogicalCPUs, "todo: docstring")
  .def("SetMiniDumpDir", (void (*)(const Urho3D::String &)) &::Urho3D::SetMiniDumpDir, "todo: docstring", py::arg("pathName"))
  .def("GetMiniDumpDir", (Urho3D::String (*)()) &::Urho3D::GetMiniDumpDir, "todo: docstring")
  .def("GetTotalMemory", (unsigned long long (*)()) &::Urho3D::GetTotalMemory, "todo: docstring")
  .def("GetLoginName", (Urho3D::String (*)()) &::Urho3D::GetLoginName, "todo: docstring")
  .def("GetHostName", (Urho3D::String (*)()) &::Urho3D::GetHostName, "todo: docstring")
  .def("GetOSVersion", (Urho3D::String (*)()) &::Urho3D::GetOSVersion, "todo: docstring")
  .def("CompareLights", (bool (*)(Urho3D::Light *, Urho3D::Light *)) &::Urho3D::CompareLights, "todo: docstring", py::arg("lhs"), py::arg("rhs"))
  .def("RegisterGraphicsLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterGraphicsLibrary, "todo: docstring", py::arg("context"))
  .def("GenerateTangents", (void (*)(void *, unsigned int, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int)) &::Urho3D::GenerateTangents, "todo: docstring", py::arg("vertexData"), py::arg("vertexSize"), py::arg("indexData"), py::arg("indexSize"), py::arg("indexStart"), py::arg("indexCount"), py::arg("normalOffset"), py::arg("texCoordOffset"), py::arg("tangentOffset"))
  .def("EstimateCompressBound", (unsigned int (*)(unsigned int)) &::Urho3D::EstimateCompressBound, "todo: docstring", py::arg("srcSize"))
  .def("CompressData", (unsigned int (*)(void *, const void *, unsigned int)) &::Urho3D::CompressData, "todo: docstring", py::arg("dest"), py::arg("src"), py::arg("srcSize"))
  .def("DecompressData", (unsigned int (*)(void *, const void *, unsigned int)) &::Urho3D::DecompressData, "todo: docstring", py::arg("dest"), py::arg("src"), py::arg("destSize"))
  .def("CompressStream", (bool (*)(Urho3D::Serializer &, Urho3D::Deserializer &)) &::Urho3D::CompressStream, "todo: docstring", py::arg("dest"), py::arg("src"))
  .def("DecompressStream", (bool (*)(Urho3D::Serializer &, Urho3D::Deserializer &)) &::Urho3D::DecompressStream, "todo: docstring", py::arg("dest"), py::arg("src"))
  .def("CompressVectorBuffer", (Urho3D::VectorBuffer (*)(Urho3D::VectorBuffer &)) &::Urho3D::CompressVectorBuffer, "todo: docstring", py::arg("src"))
  .def("DecompressVectorBuffer", (Urho3D::VectorBuffer (*)(Urho3D::VectorBuffer &)) &::Urho3D::DecompressVectorBuffer, "todo: docstring", py::arg("src"))
  .def("SplitPath", (void (*)(const Urho3D::String &, Urho3D::String &, Urho3D::String &, Urho3D::String &, bool)) &::Urho3D::SplitPath, "todo: docstring", py::arg("fullPath"), py::arg("pathName"), py::arg("fileName"), py::arg("extension"), py::arg("lowercaseExtension")=true)
  .def("GetPath", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::GetPath, "todo: docstring", py::arg("fullPath"))
  .def("GetFileName", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::GetFileName, "todo: docstring", py::arg("fullPath"))
  .def("GetExtension", (Urho3D::String (*)(const Urho3D::String &, bool)) &::Urho3D::GetExtension, "todo: docstring", py::arg("fullPath"), py::arg("lowercaseExtension")=true)
  .def("GetFileNameAndExtension", (Urho3D::String (*)(const Urho3D::String &, bool)) &::Urho3D::GetFileNameAndExtension, "todo: docstring", py::arg("fullPath"), py::arg("lowercaseExtension")=false)
  .def("ReplaceExtension", (Urho3D::String (*)(const Urho3D::String &, const Urho3D::String &)) &::Urho3D::ReplaceExtension, "todo: docstring", py::arg("fullPath"), py::arg("newExtension"))
  .def("AddTrailingSlash", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::AddTrailingSlash, "todo: docstring", py::arg("pathName"))
  .def("RemoveTrailingSlash", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::RemoveTrailingSlash, "todo: docstring", py::arg("pathName"))
  .def("GetParentPath", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::GetParentPath, "todo: docstring", py::arg("pathName"))
  .def("GetInternalPath", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::GetInternalPath, "todo: docstring", py::arg("pathName"))
  .def("GetNativePath", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::GetNativePath, "todo: docstring", py::arg("pathName"))
  .def("GetWideNativePath", (Urho3D::WString (*)(const Urho3D::String &)) &::Urho3D::GetWideNativePath, "todo: docstring", py::arg("pathName"))
  .def("IsAbsolutePath", (bool (*)(const Urho3D::String &)) &::Urho3D::IsAbsolutePath, "todo: docstring", py::arg("pathName"))
  .def("CompressRelativePath", (Urho3D::String (*)(const Urho3D::String &)) &::Urho3D::CompressRelativePath, "todo: docstring", py::arg("path"))
  .def("ResolvePath", (Urho3D::String (*)(const Urho3D::String &, const Urho3D::String &)) &::Urho3D::ResolvePath, "todo: docstring", py::arg("relative"), py::arg("absolute"))
  .def("GetRevision", (const char * (*)()) &::Urho3D::GetRevision, "todo: docstring")
  .def("GetCompilerDefines", (const char * (*)()) &::Urho3D::GetCompilerDefines, "todo: docstring")
  .def("RegisterNavigationLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterNavigationLibrary, "todo: docstring", py::arg("context"))
  .def("RegisterNetworkLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterNetworkLibrary, "todo: docstring", py::arg("context"))
  .def("ToBtVector3", (btVector3 (*)(const Urho3D::Vector3 &)) &::Urho3D::ToBtVector3, "todo: docstring", py::arg("vector"))
  .def("ToBtQuaternion", (btQuaternion (*)(const Urho3D::Quaternion &)) &::Urho3D::ToBtQuaternion, "todo: docstring", py::arg("quaternion"))
  .def("ToVector3", (Urho3D::Vector3 (*)(const btVector3 &)) &::Urho3D::ToVector3, "todo: docstring", py::arg("vector"))
  .def("ToQuaternion", (Urho3D::Quaternion (*)(const btQuaternion &)) &::Urho3D::ToQuaternion, "todo: docstring", py::arg("quaternion"))
  .def("HasWorldScaleChanged", (bool (*)(const Urho3D::Vector3 &, const Urho3D::Vector3 &)) &::Urho3D::HasWorldScaleChanged, "todo: docstring", py::arg("oldWorldScale"), py::arg("newWorldScale"))
  .def("RegisterPhysicsLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterPhysicsLibrary, "todo: docstring", py::arg("context"))
  .def("DecompressImageDXT", (void (*)(unsigned char *, const void *, int, int, int, Urho3D::CompressedFormat)) &::Urho3D::DecompressImageDXT, "todo: docstring", py::arg("dest"), py::arg("blocks"), py::arg("width"), py::arg("height"), py::arg("depth"), py::arg("format"))
  .def("DecompressImageETC", (void (*)(unsigned char *, const void *, int, int)) &::Urho3D::DecompressImageETC, "todo: docstring", py::arg("dest"), py::arg("blocks"), py::arg("width"), py::arg("height"))
  .def("DecompressImagePVRTC", (void (*)(unsigned char *, const void *, int, int, Urho3D::CompressedFormat)) &::Urho3D::DecompressImagePVRTC, "todo: docstring", py::arg("dest"), py::arg("blocks"), py::arg("width"), py::arg("height"), py::arg("format"))
  .def("FlipBlockVertical", (void (*)(unsigned char *, unsigned char *, Urho3D::CompressedFormat)) &::Urho3D::FlipBlockVertical, "todo: docstring", py::arg("dest"), py::arg("src"), py::arg("format"))
  .def("FlipBlockHorizontal", (void (*)(unsigned char *, unsigned char *, Urho3D::CompressedFormat)) &::Urho3D::FlipBlockHorizontal, "todo: docstring", py::arg("dest"), py::arg("src"), py::arg("format"))
  .def("RegisterResourceLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterResourceLibrary, "todo: docstring", py::arg("context"))
  .def("RegisterSceneLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterSceneLibrary, "todo: docstring", py::arg("context"))
  .def("RegisterUILibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterUILibrary, "todo: docstring", py::arg("context"))
  .def("ToColor", (Urho3D::Color (*)(const b2Color &)) &::Urho3D::ToColor, "todo: docstring", py::arg("color"))
  .def("ToB2Vec2", (b2Vec2 (*)(const Urho3D::Vector2 &)) &::Urho3D::ToB2Vec2, "todo: docstring", py::arg("vector"))
  .def("ToVector2", (Urho3D::Vector2 (*)(const b2Vec2 &)) &::Urho3D::ToVector2, "todo: docstring", py::arg("vec2"))
  .def("ToB2Vec2", (b2Vec2 (*)(const Urho3D::Vector3 &)) &::Urho3D::ToB2Vec2, "todo: docstring", py::arg("vector"))
  .def("ToVector3", (Urho3D::Vector3 (*)(const b2Vec2 &)) &::Urho3D::ToVector3, "todo: docstring", py::arg("vec2"))
  .def("RegisterUrho2DLibrary", (void (*)(Urho3D::Context *)) &::Urho3D::RegisterUrho2DLibrary, "todo: docstring", py::arg("context"))
; // close namespace Urho3D class functions
  // Variables
  pyclass_NS__Urho3D.attr("QUICKSORT_THRESHOLD") = ::Urho3D::QUICKSORT_THRESHOLD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONVERSION_BUFFER_LENGTH") = ::Urho3D::CONVERSION_BUFFER_LENGTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MATRIX_CONVERSION_BUFFER_LENGTH") = ::Urho3D::MATRIX_CONVERSION_BUFFER_LENGTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_PI") = ::Urho3D::M_PI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_HALF_PI") = ::Urho3D::M_HALF_PI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MIN_INT") = ::Urho3D::M_MIN_INT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MAX_INT") = ::Urho3D::M_MAX_INT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MIN_UNSIGNED") = ::Urho3D::M_MIN_UNSIGNED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MAX_UNSIGNED") = ::Urho3D::M_MAX_UNSIGNED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_EPSILON") = ::Urho3D::M_EPSILON; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_LARGE_EPSILON") = ::Urho3D::M_LARGE_EPSILON; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MIN_NEARCLIP") = ::Urho3D::M_MIN_NEARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_MAX_FOV") = ::Urho3D::M_MAX_FOV; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_LARGE_VALUE") = ::Urho3D::M_LARGE_VALUE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_INFINITY") = ::Urho3D::M_INFINITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_DEGTORAD") = ::Urho3D::M_DEGTORAD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_DEGTORAD_2") = ::Urho3D::M_DEGTORAD_2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("M_RADTODEG") = ::Urho3D::M_RADTODEG; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOGIC_CATEGORY") = ::Urho3D::LOGIC_CATEGORY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_EDIT") = ::Urho3D::AM_EDIT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_FILE") = ::Urho3D::AM_FILE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_NET") = ::Urho3D::AM_NET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_DEFAULT") = ::Urho3D::AM_DEFAULT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_LATESTDATA") = ::Urho3D::AM_LATESTDATA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_NOEDIT") = ::Urho3D::AM_NOEDIT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_NODEID") = ::Urho3D::AM_NODEID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_COMPONENTID") = ::Urho3D::AM_COMPONENTID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_NODEIDVECTOR") = ::Urho3D::AM_NODEIDVECTOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("AM_FILEREADONLY") = ::Urho3D::AM_FILEREADONLY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SOUND_MASTER") = ::Urho3D::SOUND_MASTER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SOUND_EFFECT") = ::Urho3D::SOUND_EFFECT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SOUND_AMBIENT") = ::Urho3D::SOUND_AMBIENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SOUND_VOICE") = ::Urho3D::SOUND_VOICE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SOUND_MUSIC") = ::Urho3D::SOUND_MUSIC; // todo: attr docstring
  pyclass_NS__Urho3D.attr("STREAM_BUFFER_LENGTH") = ::Urho3D::STREAM_BUFFER_LENGTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("ELEMENT_TYPESIZES") = ::Urho3D::ELEMENT_TYPESIZES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LEGACY_VERTEXELEMENTS") = ::Urho3D::LEGACY_VERTEXELEMENTS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_AMBIENTSTARTCOLOR") = ::Urho3D::VSP_AMBIENTSTARTCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_AMBIENTENDCOLOR") = ::Urho3D::VSP_AMBIENTENDCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_BILLBOARDROT") = ::Urho3D::VSP_BILLBOARDROT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_CAMERAPOS") = ::Urho3D::VSP_CAMERAPOS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_CLIPPLANE") = ::Urho3D::VSP_CLIPPLANE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_NEARCLIP") = ::Urho3D::VSP_NEARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_FARCLIP") = ::Urho3D::VSP_FARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_DEPTHMODE") = ::Urho3D::VSP_DEPTHMODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_DELTATIME") = ::Urho3D::VSP_DELTATIME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_ELAPSEDTIME") = ::Urho3D::VSP_ELAPSEDTIME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_FRUSTUMSIZE") = ::Urho3D::VSP_FRUSTUMSIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_GBUFFEROFFSETS") = ::Urho3D::VSP_GBUFFEROFFSETS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_LIGHTDIR") = ::Urho3D::VSP_LIGHTDIR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_LIGHTPOS") = ::Urho3D::VSP_LIGHTPOS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_NORMALOFFSETSCALE") = ::Urho3D::VSP_NORMALOFFSETSCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_MODEL") = ::Urho3D::VSP_MODEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_VIEW") = ::Urho3D::VSP_VIEW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_VIEWINV") = ::Urho3D::VSP_VIEWINV; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_VIEWPROJ") = ::Urho3D::VSP_VIEWPROJ; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_UOFFSET") = ::Urho3D::VSP_UOFFSET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_VOFFSET") = ::Urho3D::VSP_VOFFSET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_ZONE") = ::Urho3D::VSP_ZONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_LIGHTMATRICES") = ::Urho3D::VSP_LIGHTMATRICES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_SKINMATRICES") = ::Urho3D::VSP_SKINMATRICES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VSP_VERTEXLIGHTS") = ::Urho3D::VSP_VERTEXLIGHTS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_AMBIENTCOLOR") = ::Urho3D::PSP_AMBIENTCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_CAMERAPOS") = ::Urho3D::PSP_CAMERAPOS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_DELTATIME") = ::Urho3D::PSP_DELTATIME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_DEPTHRECONSTRUCT") = ::Urho3D::PSP_DEPTHRECONSTRUCT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_ELAPSEDTIME") = ::Urho3D::PSP_ELAPSEDTIME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_FOGCOLOR") = ::Urho3D::PSP_FOGCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_FOGPARAMS") = ::Urho3D::PSP_FOGPARAMS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_GBUFFERINVSIZE") = ::Urho3D::PSP_GBUFFERINVSIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTCOLOR") = ::Urho3D::PSP_LIGHTCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTDIR") = ::Urho3D::PSP_LIGHTDIR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTPOS") = ::Urho3D::PSP_LIGHTPOS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_NORMALOFFSETSCALE") = ::Urho3D::PSP_NORMALOFFSETSCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_MATDIFFCOLOR") = ::Urho3D::PSP_MATDIFFCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_MATEMISSIVECOLOR") = ::Urho3D::PSP_MATEMISSIVECOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_MATENVMAPCOLOR") = ::Urho3D::PSP_MATENVMAPCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_MATSPECCOLOR") = ::Urho3D::PSP_MATSPECCOLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_NEARCLIP") = ::Urho3D::PSP_NEARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_FARCLIP") = ::Urho3D::PSP_FARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_SHADOWCUBEADJUST") = ::Urho3D::PSP_SHADOWCUBEADJUST; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_SHADOWDEPTHFADE") = ::Urho3D::PSP_SHADOWDEPTHFADE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_SHADOWINTENSITY") = ::Urho3D::PSP_SHADOWINTENSITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_SHADOWMAPINVSIZE") = ::Urho3D::PSP_SHADOWMAPINVSIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_SHADOWSPLITS") = ::Urho3D::PSP_SHADOWSPLITS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTMATRICES") = ::Urho3D::PSP_LIGHTMATRICES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_VSMSHADOWPARAMS") = ::Urho3D::PSP_VSMSHADOWPARAMS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_ROUGHNESS") = ::Urho3D::PSP_ROUGHNESS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_METALLIC") = ::Urho3D::PSP_METALLIC; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTRAD") = ::Urho3D::PSP_LIGHTRAD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_LIGHTLENGTH") = ::Urho3D::PSP_LIGHTLENGTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_ZONEMIN") = ::Urho3D::PSP_ZONEMIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PSP_ZONEMAX") = ::Urho3D::PSP_ZONEMAX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DOT_SCALE") = ::Urho3D::DOT_SCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUALITY_LOW") = ::Urho3D::QUALITY_LOW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUALITY_MEDIUM") = ::Urho3D::QUALITY_MEDIUM; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUALITY_HIGH") = ::Urho3D::QUALITY_HIGH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUALITY_MAX") = ::Urho3D::QUALITY_MAX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CLEAR_COLOR") = ::Urho3D::CLEAR_COLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CLEAR_DEPTH") = ::Urho3D::CLEAR_DEPTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CLEAR_STENCIL") = ::Urho3D::CLEAR_STENCIL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_NONE") = ::Urho3D::MASK_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_POSITION") = ::Urho3D::MASK_POSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_NORMAL") = ::Urho3D::MASK_NORMAL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_COLOR") = ::Urho3D::MASK_COLOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_TEXCOORD1") = ::Urho3D::MASK_TEXCOORD1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_TEXCOORD2") = ::Urho3D::MASK_TEXCOORD2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_CUBETEXCOORD1") = ::Urho3D::MASK_CUBETEXCOORD1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_CUBETEXCOORD2") = ::Urho3D::MASK_CUBETEXCOORD2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_TANGENT") = ::Urho3D::MASK_TANGENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_BLENDWEIGHTS") = ::Urho3D::MASK_BLENDWEIGHTS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_BLENDINDICES") = ::Urho3D::MASK_BLENDINDICES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_INSTANCEMATRIX1") = ::Urho3D::MASK_INSTANCEMATRIX1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_INSTANCEMATRIX2") = ::Urho3D::MASK_INSTANCEMATRIX2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_INSTANCEMATRIX3") = ::Urho3D::MASK_INSTANCEMATRIX3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MASK_OBJECTINDEX") = ::Urho3D::MASK_OBJECTINDEX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_RENDERTARGETS") = ::Urho3D::MAX_RENDERTARGETS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_VERTEX_STREAMS") = ::Urho3D::MAX_VERTEX_STREAMS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_CONSTANT_REGISTERS") = ::Urho3D::MAX_CONSTANT_REGISTERS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("BITS_PER_COMPONENT") = ::Urho3D::BITS_PER_COMPONENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DRAWABLE_GEOMETRY") = ::Urho3D::DRAWABLE_GEOMETRY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DRAWABLE_LIGHT") = ::Urho3D::DRAWABLE_LIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DRAWABLE_ZONE") = ::Urho3D::DRAWABLE_ZONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DRAWABLE_GEOMETRY2D") = ::Urho3D::DRAWABLE_GEOMETRY2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DRAWABLE_ANY") = ::Urho3D::DRAWABLE_ANY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_VIEWMASK") = ::Urho3D::DEFAULT_VIEWMASK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_LIGHTMASK") = ::Urho3D::DEFAULT_LIGHTMASK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_SHADOWMASK") = ::Urho3D::DEFAULT_SHADOWMASK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_ZONEMASK") = ::Urho3D::DEFAULT_ZONEMASK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_VERTEX_LIGHTS") = ::Urho3D::MAX_VERTEX_LIGHTS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("ANIMATION_LOD_BASESCALE") = ::Urho3D::ANIMATION_LOD_BASESCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_TEXTURE_QUALITY_LEVELS") = ::Urho3D::MAX_TEXTURE_QUALITY_LEVELS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_RAW") = ::Urho3D::LOG_RAW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_DEBUG") = ::Urho3D::LOG_DEBUG; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_INFO") = ::Urho3D::LOG_INFO; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_WARNING") = ::Urho3D::LOG_WARNING; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_ERROR") = ::Urho3D::LOG_ERROR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LOG_NONE") = ::Urho3D::LOG_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("UI_VERTEX_SIZE") = ::Urho3D::UI_VERTEX_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DD_DISABLED") = ::Urho3D::DD_DISABLED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DD_SOURCE") = ::Urho3D::DD_SOURCE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DD_TARGET") = ::Urho3D::DD_TARGET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DD_SOURCE_AND_TARGET") = ::Urho3D::DD_SOURCE_AND_TARGET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("noAttributeInfo") = ::Urho3D::noAttributeInfo; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SOUNDFINISHED") = ::Urho3D::E_SOUNDFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_BEGINFRAME") = ::Urho3D::E_BEGINFRAME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UPDATE") = ::Urho3D::E_UPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_POSTUPDATE") = ::Urho3D::E_POSTUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RENDERUPDATE") = ::Urho3D::E_RENDERUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_POSTRENDERUPDATE") = ::Urho3D::E_POSTRENDERUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ENDFRAME") = ::Urho3D::E_ENDFRAME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_WORKITEMCOMPLETED") = ::Urho3D::E_WORKITEMCOMPLETED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_NONE") = ::Urho3D::DEBUGHUD_SHOW_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_STATS") = ::Urho3D::DEBUGHUD_SHOW_STATS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_MODE") = ::Urho3D::DEBUGHUD_SHOW_MODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_PROFILER") = ::Urho3D::DEBUGHUD_SHOW_PROFILER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_MEMORY") = ::Urho3D::DEBUGHUD_SHOW_MEMORY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_EVENTPROFILER") = ::Urho3D::DEBUGHUD_SHOW_EVENTPROFILER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEBUGHUD_SHOW_ALL") = ::Urho3D::DEBUGHUD_SHOW_ALL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_AUTOLOAD_PATHS") = ::Urho3D::EP_AUTOLOAD_PATHS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_BORDERLESS") = ::Urho3D::EP_BORDERLESS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_DUMP_SHADERS") = ::Urho3D::EP_DUMP_SHADERS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_EVENT_PROFILER") = ::Urho3D::EP_EVENT_PROFILER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_EXTERNAL_WINDOW") = ::Urho3D::EP_EXTERNAL_WINDOW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_FLUSH_GPU") = ::Urho3D::EP_FLUSH_GPU; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_FORCE_GL2") = ::Urho3D::EP_FORCE_GL2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_FRAME_LIMITER") = ::Urho3D::EP_FRAME_LIMITER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_FULL_SCREEN") = ::Urho3D::EP_FULL_SCREEN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_HEADLESS") = ::Urho3D::EP_HEADLESS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_HIGH_DPI") = ::Urho3D::EP_HIGH_DPI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_LOG_LEVEL") = ::Urho3D::EP_LOG_LEVEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_LOG_NAME") = ::Urho3D::EP_LOG_NAME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_LOG_QUIET") = ::Urho3D::EP_LOG_QUIET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_LOW_QUALITY_SHADOWS") = ::Urho3D::EP_LOW_QUALITY_SHADOWS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_MATERIAL_QUALITY") = ::Urho3D::EP_MATERIAL_QUALITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_MONITOR") = ::Urho3D::EP_MONITOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_MULTI_SAMPLE") = ::Urho3D::EP_MULTI_SAMPLE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_ORIENTATIONS") = ::Urho3D::EP_ORIENTATIONS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_PACKAGE_CACHE_DIR") = ::Urho3D::EP_PACKAGE_CACHE_DIR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_RENDER_PATH") = ::Urho3D::EP_RENDER_PATH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_REFRESH_RATE") = ::Urho3D::EP_REFRESH_RATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_RESOURCE_PACKAGES") = ::Urho3D::EP_RESOURCE_PACKAGES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_RESOURCE_PATHS") = ::Urho3D::EP_RESOURCE_PATHS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_RESOURCE_PREFIX_PATHS") = ::Urho3D::EP_RESOURCE_PREFIX_PATHS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SHADER_CACHE_DIR") = ::Urho3D::EP_SHADER_CACHE_DIR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SHADOWS") = ::Urho3D::EP_SHADOWS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SOUND") = ::Urho3D::EP_SOUND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SOUND_BUFFER") = ::Urho3D::EP_SOUND_BUFFER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SOUND_INTERPOLATION") = ::Urho3D::EP_SOUND_INTERPOLATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SOUND_MIX_RATE") = ::Urho3D::EP_SOUND_MIX_RATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_SOUND_STEREO") = ::Urho3D::EP_SOUND_STEREO; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TEXTURE_ANISOTROPY") = ::Urho3D::EP_TEXTURE_ANISOTROPY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TEXTURE_FILTER_MODE") = ::Urho3D::EP_TEXTURE_FILTER_MODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TEXTURE_QUALITY") = ::Urho3D::EP_TEXTURE_QUALITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TIME_OUT") = ::Urho3D::EP_TIME_OUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TOUCH_EMULATION") = ::Urho3D::EP_TOUCH_EMULATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_TRIPLE_BUFFER") = ::Urho3D::EP_TRIPLE_BUFFER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_VSYNC") = ::Urho3D::EP_VSYNC; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_HEIGHT") = ::Urho3D::EP_WINDOW_HEIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_ICON") = ::Urho3D::EP_WINDOW_ICON; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_POSITION_X") = ::Urho3D::EP_WINDOW_POSITION_X; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_POSITION_Y") = ::Urho3D::EP_WINDOW_POSITION_Y; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_RESIZABLE") = ::Urho3D::EP_WINDOW_RESIZABLE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_TITLE") = ::Urho3D::EP_WINDOW_TITLE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WINDOW_WIDTH") = ::Urho3D::EP_WINDOW_WIDTH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("EP_WORKER_THREADS") = ::Urho3D::EP_WORKER_THREADS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CONSOLECOMMAND") = ::Urho3D::E_CONSOLECOMMAND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("BONECOLLISION_NONE") = ::Urho3D::BONECOLLISION_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("BONECOLLISION_SPHERE") = ::Urho3D::BONECOLLISION_SPHERE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("BONECOLLISION_BOX") = ::Urho3D::BONECOLLISION_BOX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CHANNEL_POSITION") = ::Urho3D::CHANNEL_POSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CHANNEL_ROTATION") = ::Urho3D::CHANNEL_ROTATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CHANNEL_SCALE") = ::Urho3D::CHANNEL_SCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("NUM_FRUSTUM_PLANES") = ::Urho3D::NUM_FRUSTUM_PLANES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("NUM_FRUSTUM_VERTICES") = ::Urho3D::NUM_FRUSTUM_VERTICES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SHADOW_MIN_QUANTIZE") = ::Urho3D::SHADOW_MIN_QUANTIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SHADOW_MIN_VIEW") = ::Urho3D::SHADOW_MIN_VIEW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_LIGHT_SPLITS") = ::Urho3D::MAX_LIGHT_SPLITS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_CASCADE_SPLITS") = ::Urho3D::MAX_CASCADE_SPLITS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_RENDER_ORDER") = ::Urho3D::DEFAULT_RENDER_ORDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_NEARCLIP") = ::Urho3D::DEFAULT_NEARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_FARCLIP") = ::Urho3D::DEFAULT_FARCLIP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_CAMERA_FOV") = ::Urho3D::DEFAULT_CAMERA_FOV; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_ORTHOSIZE") = ::Urho3D::DEFAULT_ORTHOSIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VO_NONE") = ::Urho3D::VO_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VO_LOW_MATERIAL_QUALITY") = ::Urho3D::VO_LOW_MATERIAL_QUALITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VO_DISABLE_SHADOWS") = ::Urho3D::VO_DISABLE_SHADOWS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("VO_DISABLE_OCCLUSION") = ::Urho3D::VO_DISABLE_OCCLUSION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_BONEHIERARCHYCREATED") = ::Urho3D::E_BONEHIERARCHYCREATED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ANIMATIONTRIGGER") = ::Urho3D::E_ANIMATIONTRIGGER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ANIMATIONFINISHED") = ::Urho3D::E_ANIMATIONFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PARTICLEEFFECTFINISHED") = ::Urho3D::E_PARTICLEEFFECTFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TERRAINCREATED") = ::Urho3D::E_TERRAINCREATED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("COLOR_LUT_SIZE") = ::Urho3D::COLOR_LUT_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCREENMODE") = ::Urho3D::E_SCREENMODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_WINDOWPOS") = ::Urho3D::E_WINDOWPOS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RENDERSURFACEUPDATE") = ::Urho3D::E_RENDERSURFACEUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_BEGINRENDERING") = ::Urho3D::E_BEGINRENDERING; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ENDRENDERING") = ::Urho3D::E_ENDRENDERING; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_BEGINVIEWUPDATE") = ::Urho3D::E_BEGINVIEWUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ENDVIEWUPDATE") = ::Urho3D::E_ENDVIEWUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_BEGINVIEWRENDER") = ::Urho3D::E_BEGINVIEWRENDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_VIEWBUFFERSREADY") = ::Urho3D::E_VIEWBUFFERSREADY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_VIEWGLOBALSHADERPARAMETERS") = ::Urho3D::E_VIEWGLOBALSHADERPARAMETERS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ENDVIEWRENDER") = ::Urho3D::E_ENDVIEWRENDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ENDALLVIEWSRENDER") = ::Urho3D::E_ENDALLVIEWSRENDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RENDERPATHEVENT") = ::Urho3D::E_RENDERPATHEVENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DEVICELOST") = ::Urho3D::E_DEVICELOST; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DEVICERESET") = ::Urho3D::E_DEVICERESET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_MIN_SIZE") = ::Urho3D::OCCLUSION_MIN_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_DEFAULT_MAX_TRIANGLES") = ::Urho3D::OCCLUSION_DEFAULT_MAX_TRIANGLES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_RELATIVE_BIAS") = ::Urho3D::OCCLUSION_RELATIVE_BIAS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_FIXED_BIAS") = ::Urho3D::OCCLUSION_FIXED_BIAS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_X_SCALE") = ::Urho3D::OCCLUSION_X_SCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("OCCLUSION_Z_SCALE") = ::Urho3D::OCCLUSION_Z_SCALE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("NUM_OCTANTS") = ::Urho3D::NUM_OCTANTS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("ROOT_INDEX") = ::Urho3D::ROOT_INDEX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_NUM_PARTICLES") = ::Urho3D::DEFAULT_NUM_PARTICLES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SHADOW_MIN_PIXELS") = ::Urho3D::SHADOW_MIN_PIXELS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("INSTANCING_BUFFER_DEFAULT_SIZE") = ::Urho3D::INSTANCING_BUFFER_DEFAULT_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_VIEWPORT_TEXTURES") = ::Urho3D::MAX_VIEWPORT_TEXTURES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCAN_FILES") = ::Urho3D::SCAN_FILES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCAN_DIRS") = ::Urho3D::SCAN_DIRS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCAN_HIDDEN") = ::Urho3D::SCAN_HIDDEN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_LOGMESSAGE") = ::Urho3D::E_LOGMESSAGE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ASYNCEXECFINISHED") = ::Urho3D::E_ASYNCEXECFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEBUTTONDOWN") = ::Urho3D::E_MOUSEBUTTONDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEBUTTONUP") = ::Urho3D::E_MOUSEBUTTONUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEMOVE") = ::Urho3D::E_MOUSEMOVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEWHEEL") = ::Urho3D::E_MOUSEWHEEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_KEYDOWN") = ::Urho3D::E_KEYDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_KEYUP") = ::Urho3D::E_KEYUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEXTINPUT") = ::Urho3D::E_TEXTINPUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEXTEDITING") = ::Urho3D::E_TEXTEDITING; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKCONNECTED") = ::Urho3D::E_JOYSTICKCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKDISCONNECTED") = ::Urho3D::E_JOYSTICKDISCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKBUTTONDOWN") = ::Urho3D::E_JOYSTICKBUTTONDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKBUTTONUP") = ::Urho3D::E_JOYSTICKBUTTONUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKAXISMOVE") = ::Urho3D::E_JOYSTICKAXISMOVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_JOYSTICKHATMOVE") = ::Urho3D::E_JOYSTICKHATMOVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TOUCHBEGIN") = ::Urho3D::E_TOUCHBEGIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TOUCHEND") = ::Urho3D::E_TOUCHEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TOUCHMOVE") = ::Urho3D::E_TOUCHMOVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_GESTURERECORDED") = ::Urho3D::E_GESTURERECORDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_GESTUREINPUT") = ::Urho3D::E_GESTUREINPUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MULTIGESTURE") = ::Urho3D::E_MULTIGESTURE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DROPFILE") = ::Urho3D::E_DROPFILE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_INPUTFOCUS") = ::Urho3D::E_INPUTFOCUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEVISIBLECHANGED") = ::Urho3D::E_MOUSEVISIBLECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MOUSEMODECHANGED") = ::Urho3D::E_MOUSEMODECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_EXITREQUESTED") = ::Urho3D::E_EXITREQUESTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SDLRAWINPUT") = ::Urho3D::E_SDLRAWINPUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_INPUTBEGIN") = ::Urho3D::E_INPUTBEGIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_INPUTEND") = ::Urho3D::E_INPUTEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSEB_LEFT") = ::Urho3D::MOUSEB_LEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSEB_MIDDLE") = ::Urho3D::MOUSEB_MIDDLE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSEB_RIGHT") = ::Urho3D::MOUSEB_RIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSEB_X1") = ::Urho3D::MOUSEB_X1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSEB_X2") = ::Urho3D::MOUSEB_X2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUAL_SHIFT") = ::Urho3D::QUAL_SHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUAL_CTRL") = ::Urho3D::QUAL_CTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUAL_ALT") = ::Urho3D::QUAL_ALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("QUAL_ANY") = ::Urho3D::QUAL_ANY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_UNKNOWN") = ::Urho3D::KEY_UNKNOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_A") = ::Urho3D::KEY_A; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_B") = ::Urho3D::KEY_B; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_C") = ::Urho3D::KEY_C; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_D") = ::Urho3D::KEY_D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_E") = ::Urho3D::KEY_E; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F") = ::Urho3D::KEY_F; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_G") = ::Urho3D::KEY_G; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_H") = ::Urho3D::KEY_H; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_I") = ::Urho3D::KEY_I; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_J") = ::Urho3D::KEY_J; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_K") = ::Urho3D::KEY_K; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_L") = ::Urho3D::KEY_L; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_M") = ::Urho3D::KEY_M; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_N") = ::Urho3D::KEY_N; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_O") = ::Urho3D::KEY_O; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_P") = ::Urho3D::KEY_P; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_Q") = ::Urho3D::KEY_Q; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_R") = ::Urho3D::KEY_R; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_S") = ::Urho3D::KEY_S; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_T") = ::Urho3D::KEY_T; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_U") = ::Urho3D::KEY_U; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_V") = ::Urho3D::KEY_V; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_W") = ::Urho3D::KEY_W; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_X") = ::Urho3D::KEY_X; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_Y") = ::Urho3D::KEY_Y; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_Z") = ::Urho3D::KEY_Z; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_0") = ::Urho3D::KEY_0; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_1") = ::Urho3D::KEY_1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_2") = ::Urho3D::KEY_2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_3") = ::Urho3D::KEY_3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_4") = ::Urho3D::KEY_4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_5") = ::Urho3D::KEY_5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_6") = ::Urho3D::KEY_6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_7") = ::Urho3D::KEY_7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_8") = ::Urho3D::KEY_8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_9") = ::Urho3D::KEY_9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_BACKSPACE") = ::Urho3D::KEY_BACKSPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_TAB") = ::Urho3D::KEY_TAB; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RETURN") = ::Urho3D::KEY_RETURN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RETURN2") = ::Urho3D::KEY_RETURN2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_ENTER") = ::Urho3D::KEY_KP_ENTER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_SHIFT") = ::Urho3D::KEY_SHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_CTRL") = ::Urho3D::KEY_CTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_ALT") = ::Urho3D::KEY_ALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_GUI") = ::Urho3D::KEY_GUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_PAUSE") = ::Urho3D::KEY_PAUSE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_CAPSLOCK") = ::Urho3D::KEY_CAPSLOCK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_ESCAPE") = ::Urho3D::KEY_ESCAPE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_SPACE") = ::Urho3D::KEY_SPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_PAGEUP") = ::Urho3D::KEY_PAGEUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_PAGEDOWN") = ::Urho3D::KEY_PAGEDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_END") = ::Urho3D::KEY_END; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_HOME") = ::Urho3D::KEY_HOME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_LEFT") = ::Urho3D::KEY_LEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_UP") = ::Urho3D::KEY_UP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RIGHT") = ::Urho3D::KEY_RIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_DOWN") = ::Urho3D::KEY_DOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_SELECT") = ::Urho3D::KEY_SELECT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_PRINTSCREEN") = ::Urho3D::KEY_PRINTSCREEN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_INSERT") = ::Urho3D::KEY_INSERT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_DELETE") = ::Urho3D::KEY_DELETE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_LGUI") = ::Urho3D::KEY_LGUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RGUI") = ::Urho3D::KEY_RGUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_APPLICATION") = ::Urho3D::KEY_APPLICATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_0") = ::Urho3D::KEY_KP_0; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_1") = ::Urho3D::KEY_KP_1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_2") = ::Urho3D::KEY_KP_2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_3") = ::Urho3D::KEY_KP_3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_4") = ::Urho3D::KEY_KP_4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_5") = ::Urho3D::KEY_KP_5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_6") = ::Urho3D::KEY_KP_6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_7") = ::Urho3D::KEY_KP_7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_8") = ::Urho3D::KEY_KP_8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_9") = ::Urho3D::KEY_KP_9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_MULTIPLY") = ::Urho3D::KEY_KP_MULTIPLY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_PLUS") = ::Urho3D::KEY_KP_PLUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_MINUS") = ::Urho3D::KEY_KP_MINUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_PERIOD") = ::Urho3D::KEY_KP_PERIOD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_KP_DIVIDE") = ::Urho3D::KEY_KP_DIVIDE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F1") = ::Urho3D::KEY_F1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F2") = ::Urho3D::KEY_F2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F3") = ::Urho3D::KEY_F3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F4") = ::Urho3D::KEY_F4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F5") = ::Urho3D::KEY_F5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F6") = ::Urho3D::KEY_F6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F7") = ::Urho3D::KEY_F7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F8") = ::Urho3D::KEY_F8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F9") = ::Urho3D::KEY_F9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F10") = ::Urho3D::KEY_F10; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F11") = ::Urho3D::KEY_F11; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F12") = ::Urho3D::KEY_F12; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F13") = ::Urho3D::KEY_F13; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F14") = ::Urho3D::KEY_F14; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F15") = ::Urho3D::KEY_F15; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F16") = ::Urho3D::KEY_F16; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F17") = ::Urho3D::KEY_F17; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F18") = ::Urho3D::KEY_F18; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F19") = ::Urho3D::KEY_F19; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F20") = ::Urho3D::KEY_F20; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F21") = ::Urho3D::KEY_F21; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F22") = ::Urho3D::KEY_F22; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F23") = ::Urho3D::KEY_F23; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_F24") = ::Urho3D::KEY_F24; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_NUMLOCKCLEAR") = ::Urho3D::KEY_NUMLOCKCLEAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_SCROLLLOCK") = ::Urho3D::KEY_SCROLLLOCK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_LSHIFT") = ::Urho3D::KEY_LSHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RSHIFT") = ::Urho3D::KEY_RSHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_LCTRL") = ::Urho3D::KEY_LCTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RCTRL") = ::Urho3D::KEY_RCTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_LALT") = ::Urho3D::KEY_LALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("KEY_RALT") = ::Urho3D::KEY_RALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_UNKNOWN") = ::Urho3D::SCANCODE_UNKNOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CTRL") = ::Urho3D::SCANCODE_CTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SHIFT") = ::Urho3D::SCANCODE_SHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_ALT") = ::Urho3D::SCANCODE_ALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_GUI") = ::Urho3D::SCANCODE_GUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_A") = ::Urho3D::SCANCODE_A; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_B") = ::Urho3D::SCANCODE_B; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_C") = ::Urho3D::SCANCODE_C; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_D") = ::Urho3D::SCANCODE_D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_E") = ::Urho3D::SCANCODE_E; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F") = ::Urho3D::SCANCODE_F; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_G") = ::Urho3D::SCANCODE_G; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_H") = ::Urho3D::SCANCODE_H; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_I") = ::Urho3D::SCANCODE_I; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_J") = ::Urho3D::SCANCODE_J; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_K") = ::Urho3D::SCANCODE_K; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_L") = ::Urho3D::SCANCODE_L; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_M") = ::Urho3D::SCANCODE_M; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_N") = ::Urho3D::SCANCODE_N; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_O") = ::Urho3D::SCANCODE_O; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_P") = ::Urho3D::SCANCODE_P; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_Q") = ::Urho3D::SCANCODE_Q; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_R") = ::Urho3D::SCANCODE_R; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_S") = ::Urho3D::SCANCODE_S; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_T") = ::Urho3D::SCANCODE_T; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_U") = ::Urho3D::SCANCODE_U; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_V") = ::Urho3D::SCANCODE_V; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_W") = ::Urho3D::SCANCODE_W; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_X") = ::Urho3D::SCANCODE_X; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_Y") = ::Urho3D::SCANCODE_Y; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_Z") = ::Urho3D::SCANCODE_Z; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_1") = ::Urho3D::SCANCODE_1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_2") = ::Urho3D::SCANCODE_2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_3") = ::Urho3D::SCANCODE_3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_4") = ::Urho3D::SCANCODE_4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_5") = ::Urho3D::SCANCODE_5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_6") = ::Urho3D::SCANCODE_6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_7") = ::Urho3D::SCANCODE_7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_8") = ::Urho3D::SCANCODE_8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_9") = ::Urho3D::SCANCODE_9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_0") = ::Urho3D::SCANCODE_0; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RETURN") = ::Urho3D::SCANCODE_RETURN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_ESCAPE") = ::Urho3D::SCANCODE_ESCAPE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_BACKSPACE") = ::Urho3D::SCANCODE_BACKSPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_TAB") = ::Urho3D::SCANCODE_TAB; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SPACE") = ::Urho3D::SCANCODE_SPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MINUS") = ::Urho3D::SCANCODE_MINUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_EQUALS") = ::Urho3D::SCANCODE_EQUALS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LEFTBRACKET") = ::Urho3D::SCANCODE_LEFTBRACKET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RIGHTBRACKET") = ::Urho3D::SCANCODE_RIGHTBRACKET; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_BACKSLASH") = ::Urho3D::SCANCODE_BACKSLASH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_NONUSHASH") = ::Urho3D::SCANCODE_NONUSHASH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SEMICOLON") = ::Urho3D::SCANCODE_SEMICOLON; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_APOSTROPHE") = ::Urho3D::SCANCODE_APOSTROPHE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_GRAVE") = ::Urho3D::SCANCODE_GRAVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_COMMA") = ::Urho3D::SCANCODE_COMMA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PERIOD") = ::Urho3D::SCANCODE_PERIOD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SLASH") = ::Urho3D::SCANCODE_SLASH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CAPSLOCK") = ::Urho3D::SCANCODE_CAPSLOCK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F1") = ::Urho3D::SCANCODE_F1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F2") = ::Urho3D::SCANCODE_F2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F3") = ::Urho3D::SCANCODE_F3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F4") = ::Urho3D::SCANCODE_F4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F5") = ::Urho3D::SCANCODE_F5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F6") = ::Urho3D::SCANCODE_F6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F7") = ::Urho3D::SCANCODE_F7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F8") = ::Urho3D::SCANCODE_F8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F9") = ::Urho3D::SCANCODE_F9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F10") = ::Urho3D::SCANCODE_F10; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F11") = ::Urho3D::SCANCODE_F11; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F12") = ::Urho3D::SCANCODE_F12; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PRINTSCREEN") = ::Urho3D::SCANCODE_PRINTSCREEN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SCROLLLOCK") = ::Urho3D::SCANCODE_SCROLLLOCK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PAUSE") = ::Urho3D::SCANCODE_PAUSE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INSERT") = ::Urho3D::SCANCODE_INSERT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_HOME") = ::Urho3D::SCANCODE_HOME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PAGEUP") = ::Urho3D::SCANCODE_PAGEUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_DELETE") = ::Urho3D::SCANCODE_DELETE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_END") = ::Urho3D::SCANCODE_END; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PAGEDOWN") = ::Urho3D::SCANCODE_PAGEDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RIGHT") = ::Urho3D::SCANCODE_RIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LEFT") = ::Urho3D::SCANCODE_LEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_DOWN") = ::Urho3D::SCANCODE_DOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_UP") = ::Urho3D::SCANCODE_UP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_NUMLOCKCLEAR") = ::Urho3D::SCANCODE_NUMLOCKCLEAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_DIVIDE") = ::Urho3D::SCANCODE_KP_DIVIDE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MULTIPLY") = ::Urho3D::SCANCODE_KP_MULTIPLY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MINUS") = ::Urho3D::SCANCODE_KP_MINUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_PLUS") = ::Urho3D::SCANCODE_KP_PLUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_ENTER") = ::Urho3D::SCANCODE_KP_ENTER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_1") = ::Urho3D::SCANCODE_KP_1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_2") = ::Urho3D::SCANCODE_KP_2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_3") = ::Urho3D::SCANCODE_KP_3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_4") = ::Urho3D::SCANCODE_KP_4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_5") = ::Urho3D::SCANCODE_KP_5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_6") = ::Urho3D::SCANCODE_KP_6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_7") = ::Urho3D::SCANCODE_KP_7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_8") = ::Urho3D::SCANCODE_KP_8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_9") = ::Urho3D::SCANCODE_KP_9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_0") = ::Urho3D::SCANCODE_KP_0; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_PERIOD") = ::Urho3D::SCANCODE_KP_PERIOD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_NONUSBACKSLASH") = ::Urho3D::SCANCODE_NONUSBACKSLASH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_APPLICATION") = ::Urho3D::SCANCODE_APPLICATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_POWER") = ::Urho3D::SCANCODE_POWER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_EQUALS") = ::Urho3D::SCANCODE_KP_EQUALS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F13") = ::Urho3D::SCANCODE_F13; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F14") = ::Urho3D::SCANCODE_F14; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F15") = ::Urho3D::SCANCODE_F15; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F16") = ::Urho3D::SCANCODE_F16; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F17") = ::Urho3D::SCANCODE_F17; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F18") = ::Urho3D::SCANCODE_F18; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F19") = ::Urho3D::SCANCODE_F19; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F20") = ::Urho3D::SCANCODE_F20; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F21") = ::Urho3D::SCANCODE_F21; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F22") = ::Urho3D::SCANCODE_F22; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F23") = ::Urho3D::SCANCODE_F23; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_F24") = ::Urho3D::SCANCODE_F24; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_EXECUTE") = ::Urho3D::SCANCODE_EXECUTE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_HELP") = ::Urho3D::SCANCODE_HELP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MENU") = ::Urho3D::SCANCODE_MENU; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SELECT") = ::Urho3D::SCANCODE_SELECT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_STOP") = ::Urho3D::SCANCODE_STOP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AGAIN") = ::Urho3D::SCANCODE_AGAIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_UNDO") = ::Urho3D::SCANCODE_UNDO; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CUT") = ::Urho3D::SCANCODE_CUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_COPY") = ::Urho3D::SCANCODE_COPY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PASTE") = ::Urho3D::SCANCODE_PASTE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_FIND") = ::Urho3D::SCANCODE_FIND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MUTE") = ::Urho3D::SCANCODE_MUTE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_VOLUMEUP") = ::Urho3D::SCANCODE_VOLUMEUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_VOLUMEDOWN") = ::Urho3D::SCANCODE_VOLUMEDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_COMMA") = ::Urho3D::SCANCODE_KP_COMMA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_EQUALSAS400") = ::Urho3D::SCANCODE_KP_EQUALSAS400; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL1") = ::Urho3D::SCANCODE_INTERNATIONAL1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL2") = ::Urho3D::SCANCODE_INTERNATIONAL2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL3") = ::Urho3D::SCANCODE_INTERNATIONAL3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL4") = ::Urho3D::SCANCODE_INTERNATIONAL4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL5") = ::Urho3D::SCANCODE_INTERNATIONAL5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL6") = ::Urho3D::SCANCODE_INTERNATIONAL6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL7") = ::Urho3D::SCANCODE_INTERNATIONAL7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL8") = ::Urho3D::SCANCODE_INTERNATIONAL8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_INTERNATIONAL9") = ::Urho3D::SCANCODE_INTERNATIONAL9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG1") = ::Urho3D::SCANCODE_LANG1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG2") = ::Urho3D::SCANCODE_LANG2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG3") = ::Urho3D::SCANCODE_LANG3; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG4") = ::Urho3D::SCANCODE_LANG4; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG5") = ::Urho3D::SCANCODE_LANG5; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG6") = ::Urho3D::SCANCODE_LANG6; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG7") = ::Urho3D::SCANCODE_LANG7; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG8") = ::Urho3D::SCANCODE_LANG8; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LANG9") = ::Urho3D::SCANCODE_LANG9; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_ALTERASE") = ::Urho3D::SCANCODE_ALTERASE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SYSREQ") = ::Urho3D::SCANCODE_SYSREQ; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CANCEL") = ::Urho3D::SCANCODE_CANCEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CLEAR") = ::Urho3D::SCANCODE_CLEAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_PRIOR") = ::Urho3D::SCANCODE_PRIOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RETURN2") = ::Urho3D::SCANCODE_RETURN2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SEPARATOR") = ::Urho3D::SCANCODE_SEPARATOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_OUT") = ::Urho3D::SCANCODE_OUT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_OPER") = ::Urho3D::SCANCODE_OPER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CLEARAGAIN") = ::Urho3D::SCANCODE_CLEARAGAIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CRSEL") = ::Urho3D::SCANCODE_CRSEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_EXSEL") = ::Urho3D::SCANCODE_EXSEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_00") = ::Urho3D::SCANCODE_KP_00; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_000") = ::Urho3D::SCANCODE_KP_000; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_THOUSANDSSEPARATOR") = ::Urho3D::SCANCODE_THOUSANDSSEPARATOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_DECIMALSEPARATOR") = ::Urho3D::SCANCODE_DECIMALSEPARATOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CURRENCYUNIT") = ::Urho3D::SCANCODE_CURRENCYUNIT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CURRENCYSUBUNIT") = ::Urho3D::SCANCODE_CURRENCYSUBUNIT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_LEFTPAREN") = ::Urho3D::SCANCODE_KP_LEFTPAREN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_RIGHTPAREN") = ::Urho3D::SCANCODE_KP_RIGHTPAREN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_LEFTBRACE") = ::Urho3D::SCANCODE_KP_LEFTBRACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_RIGHTBRACE") = ::Urho3D::SCANCODE_KP_RIGHTBRACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_TAB") = ::Urho3D::SCANCODE_KP_TAB; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_BACKSPACE") = ::Urho3D::SCANCODE_KP_BACKSPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_A") = ::Urho3D::SCANCODE_KP_A; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_B") = ::Urho3D::SCANCODE_KP_B; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_C") = ::Urho3D::SCANCODE_KP_C; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_D") = ::Urho3D::SCANCODE_KP_D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_E") = ::Urho3D::SCANCODE_KP_E; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_F") = ::Urho3D::SCANCODE_KP_F; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_XOR") = ::Urho3D::SCANCODE_KP_XOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_POWER") = ::Urho3D::SCANCODE_KP_POWER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_PERCENT") = ::Urho3D::SCANCODE_KP_PERCENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_LESS") = ::Urho3D::SCANCODE_KP_LESS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_GREATER") = ::Urho3D::SCANCODE_KP_GREATER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_AMPERSAND") = ::Urho3D::SCANCODE_KP_AMPERSAND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_DBLAMPERSAND") = ::Urho3D::SCANCODE_KP_DBLAMPERSAND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_VERTICALBAR") = ::Urho3D::SCANCODE_KP_VERTICALBAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_DBLVERTICALBAR") = ::Urho3D::SCANCODE_KP_DBLVERTICALBAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_COLON") = ::Urho3D::SCANCODE_KP_COLON; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_HASH") = ::Urho3D::SCANCODE_KP_HASH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_SPACE") = ::Urho3D::SCANCODE_KP_SPACE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_AT") = ::Urho3D::SCANCODE_KP_AT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_EXCLAM") = ::Urho3D::SCANCODE_KP_EXCLAM; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMSTORE") = ::Urho3D::SCANCODE_KP_MEMSTORE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMRECALL") = ::Urho3D::SCANCODE_KP_MEMRECALL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMCLEAR") = ::Urho3D::SCANCODE_KP_MEMCLEAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMADD") = ::Urho3D::SCANCODE_KP_MEMADD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMSUBTRACT") = ::Urho3D::SCANCODE_KP_MEMSUBTRACT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMMULTIPLY") = ::Urho3D::SCANCODE_KP_MEMMULTIPLY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_MEMDIVIDE") = ::Urho3D::SCANCODE_KP_MEMDIVIDE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_PLUSMINUS") = ::Urho3D::SCANCODE_KP_PLUSMINUS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_CLEAR") = ::Urho3D::SCANCODE_KP_CLEAR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_CLEARENTRY") = ::Urho3D::SCANCODE_KP_CLEARENTRY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_BINARY") = ::Urho3D::SCANCODE_KP_BINARY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_OCTAL") = ::Urho3D::SCANCODE_KP_OCTAL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_DECIMAL") = ::Urho3D::SCANCODE_KP_DECIMAL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KP_HEXADECIMAL") = ::Urho3D::SCANCODE_KP_HEXADECIMAL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LCTRL") = ::Urho3D::SCANCODE_LCTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LSHIFT") = ::Urho3D::SCANCODE_LSHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LALT") = ::Urho3D::SCANCODE_LALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_LGUI") = ::Urho3D::SCANCODE_LGUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RCTRL") = ::Urho3D::SCANCODE_RCTRL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RSHIFT") = ::Urho3D::SCANCODE_RSHIFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RALT") = ::Urho3D::SCANCODE_RALT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_RGUI") = ::Urho3D::SCANCODE_RGUI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MODE") = ::Urho3D::SCANCODE_MODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AUDIONEXT") = ::Urho3D::SCANCODE_AUDIONEXT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AUDIOPREV") = ::Urho3D::SCANCODE_AUDIOPREV; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AUDIOSTOP") = ::Urho3D::SCANCODE_AUDIOSTOP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AUDIOPLAY") = ::Urho3D::SCANCODE_AUDIOPLAY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AUDIOMUTE") = ::Urho3D::SCANCODE_AUDIOMUTE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MEDIASELECT") = ::Urho3D::SCANCODE_MEDIASELECT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_WWW") = ::Urho3D::SCANCODE_WWW; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_MAIL") = ::Urho3D::SCANCODE_MAIL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_CALCULATOR") = ::Urho3D::SCANCODE_CALCULATOR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_COMPUTER") = ::Urho3D::SCANCODE_COMPUTER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_SEARCH") = ::Urho3D::SCANCODE_AC_SEARCH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_HOME") = ::Urho3D::SCANCODE_AC_HOME; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_BACK") = ::Urho3D::SCANCODE_AC_BACK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_FORWARD") = ::Urho3D::SCANCODE_AC_FORWARD; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_STOP") = ::Urho3D::SCANCODE_AC_STOP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_REFRESH") = ::Urho3D::SCANCODE_AC_REFRESH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_AC_BOOKMARKS") = ::Urho3D::SCANCODE_AC_BOOKMARKS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_BRIGHTNESSDOWN") = ::Urho3D::SCANCODE_BRIGHTNESSDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_BRIGHTNESSUP") = ::Urho3D::SCANCODE_BRIGHTNESSUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_DISPLAYSWITCH") = ::Urho3D::SCANCODE_DISPLAYSWITCH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KBDILLUMTOGGLE") = ::Urho3D::SCANCODE_KBDILLUMTOGGLE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KBDILLUMDOWN") = ::Urho3D::SCANCODE_KBDILLUMDOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_KBDILLUMUP") = ::Urho3D::SCANCODE_KBDILLUMUP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_EJECT") = ::Urho3D::SCANCODE_EJECT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_SLEEP") = ::Urho3D::SCANCODE_SLEEP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_APP1") = ::Urho3D::SCANCODE_APP1; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SCANCODE_APP2") = ::Urho3D::SCANCODE_APP2; // todo: attr docstring
  pyclass_NS__Urho3D.attr("HAT_CENTER") = ::Urho3D::HAT_CENTER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("HAT_UP") = ::Urho3D::HAT_UP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("HAT_RIGHT") = ::Urho3D::HAT_RIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("HAT_DOWN") = ::Urho3D::HAT_DOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("HAT_LEFT") = ::Urho3D::HAT_LEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_A") = ::Urho3D::CONTROLLER_BUTTON_A; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_B") = ::Urho3D::CONTROLLER_BUTTON_B; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_X") = ::Urho3D::CONTROLLER_BUTTON_X; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_Y") = ::Urho3D::CONTROLLER_BUTTON_Y; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_BACK") = ::Urho3D::CONTROLLER_BUTTON_BACK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_GUIDE") = ::Urho3D::CONTROLLER_BUTTON_GUIDE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_START") = ::Urho3D::CONTROLLER_BUTTON_START; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_LEFTSTICK") = ::Urho3D::CONTROLLER_BUTTON_LEFTSTICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_RIGHTSTICK") = ::Urho3D::CONTROLLER_BUTTON_RIGHTSTICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_LEFTSHOULDER") = ::Urho3D::CONTROLLER_BUTTON_LEFTSHOULDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_RIGHTSHOULDER") = ::Urho3D::CONTROLLER_BUTTON_RIGHTSHOULDER; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_DPAD_UP") = ::Urho3D::CONTROLLER_BUTTON_DPAD_UP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_DPAD_DOWN") = ::Urho3D::CONTROLLER_BUTTON_DPAD_DOWN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_DPAD_LEFT") = ::Urho3D::CONTROLLER_BUTTON_DPAD_LEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_BUTTON_DPAD_RIGHT") = ::Urho3D::CONTROLLER_BUTTON_DPAD_RIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_LEFTX") = ::Urho3D::CONTROLLER_AXIS_LEFTX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_LEFTY") = ::Urho3D::CONTROLLER_AXIS_LEFTY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_RIGHTX") = ::Urho3D::CONTROLLER_AXIS_RIGHTX; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_RIGHTY") = ::Urho3D::CONTROLLER_AXIS_RIGHTY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_TRIGGERLEFT") = ::Urho3D::CONTROLLER_AXIS_TRIGGERLEFT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLLER_AXIS_TRIGGERRIGHT") = ::Urho3D::CONTROLLER_AXIS_TRIGGERRIGHT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MOUSE_POSITION_OFFSCREEN") = ::Urho3D::MOUSE_POSITION_OFFSCREEN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NAVIGATION_MESH_REBUILT") = ::Urho3D::E_NAVIGATION_MESH_REBUILT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NAVIGATION_AREA_REBUILT") = ::Urho3D::E_NAVIGATION_AREA_REBUILT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_FORMATION") = ::Urho3D::E_CROWD_AGENT_FORMATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_NODE_FORMATION") = ::Urho3D::E_CROWD_AGENT_NODE_FORMATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_REPOSITION") = ::Urho3D::E_CROWD_AGENT_REPOSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_NODE_REPOSITION") = ::Urho3D::E_CROWD_AGENT_NODE_REPOSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_FAILURE") = ::Urho3D::E_CROWD_AGENT_FAILURE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_NODE_FAILURE") = ::Urho3D::E_CROWD_AGENT_NODE_FAILURE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_STATE_CHANGED") = ::Urho3D::E_CROWD_AGENT_STATE_CHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CROWD_AGENT_NODE_STATE_CHANGED") = ::Urho3D::E_CROWD_AGENT_NODE_STATE_CHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NAVIGATION_OBSTACLE_ADDED") = ::Urho3D::E_NAVIGATION_OBSTACLE_ADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NAVIGATION_OBSTACLE_REMOVED") = ::Urho3D::E_NAVIGATION_OBSTACLE_REMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MAX_NETWORK_ATTRIBUTES") = ::Urho3D::MAX_NETWORK_ATTRIBUTES; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SERVERCONNECTED") = ::Urho3D::E_SERVERCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SERVERDISCONNECTED") = ::Urho3D::E_SERVERDISCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CONNECTFAILED") = ::Urho3D::E_CONNECTFAILED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLIENTCONNECTED") = ::Urho3D::E_CLIENTCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLIENTDISCONNECTED") = ::Urho3D::E_CLIENTDISCONNECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLIENTIDENTITY") = ::Urho3D::E_CLIENTIDENTITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLIENTSCENELOADED") = ::Urho3D::E_CLIENTSCENELOADED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NETWORKMESSAGE") = ::Urho3D::E_NETWORKMESSAGE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NETWORKUPDATE") = ::Urho3D::E_NETWORKUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NETWORKUPDATESENT") = ::Urho3D::E_NETWORKUPDATESENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NETWORKSCENELOADFAILED") = ::Urho3D::E_NETWORKSCENELOADFAILED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_REMOTEEVENTDATA") = ::Urho3D::E_REMOTEEVENTDATA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_IDENTITY") = ::Urho3D::MSG_IDENTITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_CONTROLS") = ::Urho3D::MSG_CONTROLS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_SCENELOADED") = ::Urho3D::MSG_SCENELOADED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_REQUESTPACKAGE") = ::Urho3D::MSG_REQUESTPACKAGE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_PACKAGEDATA") = ::Urho3D::MSG_PACKAGEDATA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_LOADSCENE") = ::Urho3D::MSG_LOADSCENE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_SCENECHECKSUMERROR") = ::Urho3D::MSG_SCENECHECKSUMERROR; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_CREATENODE") = ::Urho3D::MSG_CREATENODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_NODEDELTAUPDATE") = ::Urho3D::MSG_NODEDELTAUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_NODELATESTDATA") = ::Urho3D::MSG_NODELATESTDATA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_REMOVENODE") = ::Urho3D::MSG_REMOVENODE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_CREATECOMPONENT") = ::Urho3D::MSG_CREATECOMPONENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_COMPONENTDELTAUPDATE") = ::Urho3D::MSG_COMPONENTDELTAUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_COMPONENTLATESTDATA") = ::Urho3D::MSG_COMPONENTLATESTDATA; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_REMOVECOMPONENT") = ::Urho3D::MSG_REMOVECOMPONENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_REMOTEEVENT") = ::Urho3D::MSG_REMOTEEVENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_REMOTENODEEVENT") = ::Urho3D::MSG_REMOTENODEEVENT; // todo: attr docstring
  pyclass_NS__Urho3D.attr("MSG_PACKAGEINFO") = ::Urho3D::MSG_PACKAGEINFO; // todo: attr docstring
  pyclass_NS__Urho3D.attr("CONTROLS_CONTENT_ID") = ::Urho3D::CONTROLS_CONTENT_ID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PACKAGE_FRAGMENT_SIZE") = ::Urho3D::PACKAGE_FRAGMENT_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSPRESTEP") = ::Urho3D::E_PHYSICSPRESTEP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSPOSTSTEP") = ::Urho3D::E_PHYSICSPOSTSTEP; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSCOLLISIONSTART") = ::Urho3D::E_PHYSICSCOLLISIONSTART; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSCOLLISION") = ::Urho3D::E_PHYSICSCOLLISION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSCOLLISIONEND") = ::Urho3D::E_PHYSICSCOLLISIONEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODECOLLISIONSTART") = ::Urho3D::E_NODECOLLISIONSTART; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODECOLLISION") = ::Urho3D::E_NODECOLLISION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODECOLLISIONEND") = ::Urho3D::E_NODECOLLISIONEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_MAX_NETWORK_ANGULAR_VELOCITY") = ::Urho3D::DEFAULT_MAX_NETWORK_ANGULAR_VELOCITY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("USE_UPDATE") = ::Urho3D::USE_UPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("USE_POSTUPDATE") = ::Urho3D::USE_POSTUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("USE_FIXEDUPDATE") = ::Urho3D::USE_FIXEDUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("USE_FIXEDPOSTUPDATE") = ::Urho3D::USE_FIXEDPOSTUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PRIORITY_LAST") = ::Urho3D::PRIORITY_LAST; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RELOADSTARTED") = ::Urho3D::E_RELOADSTARTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RELOADFINISHED") = ::Urho3D::E_RELOADFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RELOADFAILED") = ::Urho3D::E_RELOADFAILED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_FILECHANGED") = ::Urho3D::E_FILECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_LOADFAILED") = ::Urho3D::E_LOADFAILED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RESOURCENOTFOUND") = ::Urho3D::E_RESOURCENOTFOUND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UNKNOWNRESOURCETYPE") = ::Urho3D::E_UNKNOWNRESOURCETYPE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RESOURCEBACKGROUNDLOADED") = ::Urho3D::E_RESOURCEBACKGROUNDLOADED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CHANGELANGUAGE") = ::Urho3D::E_CHANGELANGUAGE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("FIRST_REPLICATED_ID") = ::Urho3D::FIRST_REPLICATED_ID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LAST_REPLICATED_ID") = ::Urho3D::LAST_REPLICATED_ID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("FIRST_LOCAL_ID") = ::Urho3D::FIRST_LOCAL_ID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("LAST_LOCAL_ID") = ::Urho3D::LAST_LOCAL_ID; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCENEUPDATE") = ::Urho3D::E_SCENEUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCENESUBSYSTEMUPDATE") = ::Urho3D::E_SCENESUBSYSTEMUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UPDATESMOOTHING") = ::Urho3D::E_UPDATESMOOTHING; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCENEDRAWABLEUPDATEFINISHED") = ::Urho3D::E_SCENEDRAWABLEUPDATEFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TARGETPOSITION") = ::Urho3D::E_TARGETPOSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TARGETROTATION") = ::Urho3D::E_TARGETROTATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ATTRIBUTEANIMATIONUPDATE") = ::Urho3D::E_ATTRIBUTEANIMATIONUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ATTRIBUTEANIMATIONADDED") = ::Urho3D::E_ATTRIBUTEANIMATIONADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ATTRIBUTEANIMATIONREMOVED") = ::Urho3D::E_ATTRIBUTEANIMATIONREMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCENEPOSTUPDATE") = ::Urho3D::E_SCENEPOSTUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ASYNCLOADPROGRESS") = ::Urho3D::E_ASYNCLOADPROGRESS; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ASYNCLOADFINISHED") = ::Urho3D::E_ASYNCLOADFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEADDED") = ::Urho3D::E_NODEADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEREMOVED") = ::Urho3D::E_NODEREMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_COMPONENTADDED") = ::Urho3D::E_COMPONENTADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_COMPONENTREMOVED") = ::Urho3D::E_COMPONENTREMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODENAMECHANGED") = ::Urho3D::E_NODENAMECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEENABLEDCHANGED") = ::Urho3D::E_NODEENABLEDCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODETAGADDED") = ::Urho3D::E_NODETAGADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODETAGREMOVED") = ::Urho3D::E_NODETAGREMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_COMPONENTENABLEDCHANGED") = ::Urho3D::E_COMPONENTENABLEDCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEMPORARYCHANGED") = ::Urho3D::E_TEMPORARYCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODECLONED") = ::Urho3D::E_NODECLONED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_COMPONENTCLONED") = ::Urho3D::E_COMPONENTCLONED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_INTERCEPTNETWORKUPDATE") = ::Urho3D::E_INTERCEPTNETWORKUPDATE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SMOOTH_NONE") = ::Urho3D::SMOOTH_NONE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SMOOTH_POSITION") = ::Urho3D::SMOOTH_POSITION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("SMOOTH_ROTATION") = ::Urho3D::SMOOTH_ROTATION; // todo: attr docstring
  pyclass_NS__Urho3D.attr("FONT_TEXTURE_MIN_SIZE") = ::Urho3D::FONT_TEXTURE_MIN_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("FONT_DPI") = ::Urho3D::FONT_DPI; // todo: attr docstring
  pyclass_NS__Urho3D.attr("DEFAULT_FONT_SIZE") = ::Urho3D::DEFAULT_FONT_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UIMOUSECLICK") = ::Urho3D::E_UIMOUSECLICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UIMOUSECLICKEND") = ::Urho3D::E_UIMOUSECLICKEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UIMOUSEDOUBLECLICK") = ::Urho3D::E_UIMOUSEDOUBLECLICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLICK") = ::Urho3D::E_CLICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_CLICKEND") = ::Urho3D::E_CLICKEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DOUBLECLICK") = ::Urho3D::E_DOUBLECLICK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGDROPTEST") = ::Urho3D::E_DRAGDROPTEST; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGDROPFINISH") = ::Urho3D::E_DRAGDROPFINISH; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_FOCUSCHANGED") = ::Urho3D::E_FOCUSCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NAMECHANGED") = ::Urho3D::E_NAMECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RESIZED") = ::Urho3D::E_RESIZED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_POSITIONED") = ::Urho3D::E_POSITIONED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_VISIBLECHANGED") = ::Urho3D::E_VISIBLECHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_FOCUSED") = ::Urho3D::E_FOCUSED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DEFOCUSED") = ::Urho3D::E_DEFOCUSED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_LAYOUTUPDATED") = ::Urho3D::E_LAYOUTUPDATED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PRESSED") = ::Urho3D::E_PRESSED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_RELEASED") = ::Urho3D::E_RELEASED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TOGGLED") = ::Urho3D::E_TOGGLED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SLIDERCHANGED") = ::Urho3D::E_SLIDERCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SLIDERPAGED") = ::Urho3D::E_SLIDERPAGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PROGRESSBARCHANGED") = ::Urho3D::E_PROGRESSBARCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SCROLLBARCHANGED") = ::Urho3D::E_SCROLLBARCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_VIEWCHANGED") = ::Urho3D::E_VIEWCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MODALCHANGED") = ::Urho3D::E_MODALCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEXTENTRY") = ::Urho3D::E_TEXTENTRY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEXTCHANGED") = ::Urho3D::E_TEXTCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_TEXTFINISHED") = ::Urho3D::E_TEXTFINISHED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MENUSELECTED") = ::Urho3D::E_MENUSELECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ITEMSELECTED") = ::Urho3D::E_ITEMSELECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ITEMDESELECTED") = ::Urho3D::E_ITEMDESELECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_SELECTIONCHANGED") = ::Urho3D::E_SELECTIONCHANGED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ITEMCLICKED") = ::Urho3D::E_ITEMCLICKED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ITEMDOUBLECLICKED") = ::Urho3D::E_ITEMDOUBLECLICKED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UNHANDLEDKEY") = ::Urho3D::E_UNHANDLEDKEY; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_FILESELECTED") = ::Urho3D::E_FILESELECTED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_MESSAGEACK") = ::Urho3D::E_MESSAGEACK; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ELEMENTADDED") = ::Urho3D::E_ELEMENTADDED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_ELEMENTREMOVED") = ::Urho3D::E_ELEMENTREMOVED; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_HOVERBEGIN") = ::Urho3D::E_HOVERBEGIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_HOVEREND") = ::Urho3D::E_HOVEREND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGBEGIN") = ::Urho3D::E_DRAGBEGIN; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGMOVE") = ::Urho3D::E_DRAGMOVE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGEND") = ::Urho3D::E_DRAGEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_DRAGCANCEL") = ::Urho3D::E_DRAGCANCEL; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_UIDROPFILE") = ::Urho3D::E_UIDROPFILE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("PIXEL_SIZE") = ::Urho3D::PIXEL_SIZE; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSUPDATECONTACT2D") = ::Urho3D::E_PHYSICSUPDATECONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSBEGINCONTACT2D") = ::Urho3D::E_PHYSICSBEGINCONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PHYSICSENDCONTACT2D") = ::Urho3D::E_PHYSICSENDCONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEUPDATECONTACT2D") = ::Urho3D::E_NODEUPDATECONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEBEGINCONTACT2D") = ::Urho3D::E_NODEBEGINCONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_NODEENDCONTACT2D") = ::Urho3D::E_NODEENDCONTACT2D; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PARTICLESEND") = ::Urho3D::E_PARTICLESEND; // todo: attr docstring
  pyclass_NS__Urho3D.attr("E_PARTICLESDURATION") = ::Urho3D::E_PARTICLESDURATION; // todo: attr docstring
  // Namespace vars class Urho3D

  // Declare class variables
// Class AbstractFile
auto pyclass_Var_Urho3D_AbstractFile = py::class_<Urho3D::AbstractFile, Urho3D::Deserializer, Urho3D::Serializer>(pyclass_NS__Urho3D, "AbstractFile", "test doc");
// Class AllContentOctreeQuery
auto pyclass_Var_Urho3D_AllContentOctreeQuery = py::class_<Urho3D::AllContentOctreeQuery, Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "AllContentOctreeQuery", "test doc");
// Class AllocatorBlock
auto pyclass_Var_Urho3D_AllocatorBlock = py::class_<Urho3D::AllocatorBlock>(pyclass_NS__Urho3D, "AllocatorBlock", "test doc");
// Class AllocatorNode
auto pyclass_Var_Urho3D_AllocatorNode = py::class_<Urho3D::AllocatorNode>(pyclass_NS__Urho3D, "AllocatorNode", "test doc");
// Class Animatable
auto pyclass_Var_Urho3D_Animatable = py::class_<Urho3D::Animatable, Urho3D::Serializable>(pyclass_NS__Urho3D, "Animatable", "test doc");
// Class AnimatedModel
auto pyclass_Var_Urho3D_AnimatedModel = py::class_<Urho3D::AnimatedModel, Urho3D::StaticModel>(pyclass_NS__Urho3D, "AnimatedModel", "test doc");
// Class AnimatedSprite2D
auto pyclass_Var_Urho3D_AnimatedSprite2D = py::class_<Urho3D::AnimatedSprite2D, Urho3D::StaticSprite2D>(pyclass_NS__Urho3D, "AnimatedSprite2D", "test doc");
// Class Animation
auto pyclass_Var_Urho3D_Animation = py::class_<Urho3D::Animation, Urho3D::ResourceWithMetadata>(pyclass_NS__Urho3D, "Animation", "test doc");
// Class AnimationControl
auto pyclass_Var_Urho3D_AnimationControl = py::class_<Urho3D::AnimationControl>(pyclass_NS__Urho3D, "AnimationControl", "test doc");
// Class AnimationController
auto pyclass_Var_Urho3D_AnimationController = py::class_<Urho3D::AnimationController, Urho3D::Component>(pyclass_NS__Urho3D, "AnimationController", "test doc");
// Class AnimationKeyFrame
auto pyclass_Var_Urho3D_AnimationKeyFrame = py::class_<Urho3D::AnimationKeyFrame>(pyclass_NS__Urho3D, "AnimationKeyFrame", "test doc");
// Class AnimationSet2D
auto pyclass_Var_Urho3D_AnimationSet2D = py::class_<Urho3D::AnimationSet2D, Urho3D::Resource>(pyclass_NS__Urho3D, "AnimationSet2D", "test doc");
// Class AnimationState
auto pyclass_Var_Urho3D_AnimationState = py::class_<Urho3D::AnimationState, Urho3D::RefCounted>(pyclass_NS__Urho3D, "AnimationState", "test doc");
// Class AnimationStateTrack
auto pyclass_Var_Urho3D_AnimationStateTrack = py::class_<Urho3D::AnimationStateTrack>(pyclass_NS__Urho3D, "AnimationStateTrack", "test doc");
// Class AnimationTrack
auto pyclass_Var_Urho3D_AnimationTrack = py::class_<Urho3D::AnimationTrack>(pyclass_NS__Urho3D, "AnimationTrack", "test doc");
// Class AnimationTriggerPoint
auto pyclass_Var_Urho3D_AnimationTriggerPoint = py::class_<Urho3D::AnimationTriggerPoint>(pyclass_NS__Urho3D, "AnimationTriggerPoint", "test doc");
// Class Application
auto pyclass_Var_Urho3D_Application = py::class_<Urho3D::Application, Urho3D::Object>(pyclass_NS__Urho3D, "Application", "test doc");
// Class AreaAllocator
auto pyclass_Var_Urho3D_AreaAllocator = py::class_<Urho3D::AreaAllocator>(pyclass_NS__Urho3D, "AreaAllocator", "test doc");
// Class AsyncProgress
auto pyclass_Var_Urho3D_AsyncProgress = py::class_<Urho3D::AsyncProgress>(pyclass_NS__Urho3D, "AsyncProgress", "test doc");
// Class AttributeAccessor
auto pyclass_Var_Urho3D_AttributeAccessor = py::class_<Urho3D::AttributeAccessor, Urho3D::RefCounted>(pyclass_NS__Urho3D, "AttributeAccessor", "test doc");
// Class AttributeAnimationInfo
auto pyclass_Var_Urho3D_AttributeAnimationInfo = py::class_<Urho3D::AttributeAnimationInfo, Urho3D::ValueAnimationInfo>(pyclass_NS__Urho3D, "AttributeAnimationInfo", "test doc");
// Class AttributeInfo
auto pyclass_Var_Urho3D_AttributeInfo = py::class_<Urho3D::AttributeInfo>(pyclass_NS__Urho3D, "AttributeInfo", "test doc");
// Class AttributeTrait
auto pyclass_Var_Urho3D_AttributeTrait_bool = py::class_<Urho3D::AttributeTrait<bool>>(pyclass_NS__Urho3D, "AttributeTrait", "test doc");
// Class AttributeTrait
auto pyclass_Var_Urho3D_AttributeTrait_float = py::class_<Urho3D::AttributeTrait<float>>(pyclass_NS__Urho3D, "AttributeTrait", "test doc");
// Class AttributeTrait
auto pyclass_Var_Urho3D_AttributeTrait_int = py::class_<Urho3D::AttributeTrait<int>>(pyclass_NS__Urho3D, "AttributeTrait", "test doc");
// Class AttributeTrait
auto pyclass_Var_Urho3D_AttributeTrait_unsigned_int = py::class_<Urho3D::AttributeTrait<unsigned int>>(pyclass_NS__Urho3D, "AttributeTrait", "test doc");
// Class Audio
auto pyclass_Var_Urho3D_Audio = py::class_<Urho3D::Audio, Urho3D::Object>(pyclass_NS__Urho3D, "Audio", "test doc");
// Class AutoProfileBlock
auto pyclass_Var_Urho3D_AutoProfileBlock = py::class_<Urho3D::AutoProfileBlock>(pyclass_NS__Urho3D, "AutoProfileBlock", "test doc");
// Class BackgroundLoadItem
auto pyclass_Var_Urho3D_BackgroundLoadItem = py::class_<Urho3D::BackgroundLoadItem>(pyclass_NS__Urho3D, "BackgroundLoadItem", "test doc");
// Class BackgroundLoader
auto pyclass_Var_Urho3D_BackgroundLoader = py::class_<Urho3D::BackgroundLoader, Urho3D::RefCounted, Urho3D::Thread>(pyclass_NS__Urho3D, "BackgroundLoader", "test doc");
// Class Batch
auto pyclass_Var_Urho3D_Batch = py::class_<Urho3D::Batch>(pyclass_NS__Urho3D, "Batch", "test doc");
// Class BatchGroup
auto pyclass_Var_Urho3D_BatchGroup = py::class_<Urho3D::BatchGroup, Urho3D::Batch>(pyclass_NS__Urho3D, "BatchGroup", "test doc");
// Class BatchGroupKey
auto pyclass_Var_Urho3D_BatchGroupKey = py::class_<Urho3D::BatchGroupKey>(pyclass_NS__Urho3D, "BatchGroupKey", "test doc");
// Class BatchQueue
auto pyclass_Var_Urho3D_BatchQueue = py::class_<Urho3D::BatchQueue>(pyclass_NS__Urho3D, "BatchQueue", "test doc");
// Class BiasParameters
auto pyclass_Var_Urho3D_BiasParameters = py::class_<Urho3D::BiasParameters>(pyclass_NS__Urho3D, "BiasParameters", "test doc");
// Class Billboard
auto pyclass_Var_Urho3D_Billboard = py::class_<Urho3D::Billboard>(pyclass_NS__Urho3D, "Billboard", "test doc");
// Class BillboardSet
auto pyclass_Var_Urho3D_BillboardSet = py::class_<Urho3D::BillboardSet, Urho3D::Drawable>(pyclass_NS__Urho3D, "BillboardSet", "test doc");
// Class Bone
auto pyclass_Var_Urho3D_Bone = py::class_<Urho3D::Bone>(pyclass_NS__Urho3D, "Bone", "test doc");
// Class BorderImage
auto pyclass_Var_Urho3D_BorderImage = py::class_<Urho3D::BorderImage, Urho3D::UIElement>(pyclass_NS__Urho3D, "BorderImage", "test doc");
// Class BoundingBox
auto pyclass_Var_Urho3D_BoundingBox = py::class_<Urho3D::BoundingBox>(pyclass_NS__Urho3D, "BoundingBox", "test doc");
// Class BoxOctreeQuery
auto pyclass_Var_Urho3D_BoxOctreeQuery = py::class_<Urho3D::BoxOctreeQuery, Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "BoxOctreeQuery", "test doc");
// Class Button
auto pyclass_Var_Urho3D_Button = py::class_<Urho3D::Button, Urho3D::BorderImage>(pyclass_NS__Urho3D, "Button", "test doc");
// Class CScriptArray
//auto pyclass_Var_Urho3D_CScriptArray = py::class_<Urho3D::CScriptArray>(pyclass_NS__Urho3D, "CScriptArray", "test doc");
// Class CScriptDictionary
//auto pyclass_Var_Urho3D_CScriptDictionary = py::class_<Urho3D::CScriptDictionary>(pyclass_NS__Urho3D, "CScriptDictionary", "test doc");
// Class RefCounted
auto pyclass_Var_Urho3D_RefCounted = py::class_<Urho3D::RefCounted>(pyclass_NS__Urho3D, "RefCounted", "test doc");
// Class BufferedSoundStream
auto pyclass_Var_Urho3D_BufferedSoundStream = py::class_<Urho3D::BufferedSoundStream, Urho3D::SoundStream>(pyclass_NS__Urho3D, "BufferedSoundStream", "test doc");
// Class CScriptDictValue
auto pyclass_Var_Urho3D_CScriptDictValue = py::class_<Urho3D::CScriptDictValue>(pyclass_NS__Urho3D, "CScriptDictValue", "test doc");
// Class CIterator
//auto pyclass_Var_Urho3D_CScriptDictionary_CIterator = py::class_<Urho3D::CScriptDictionary::CIterator>(pyclass_Var_Urho3D_CScriptDictionary, "CIterator", "test doc");
// Class Camera
auto pyclass_Var_Urho3D_Camera = py::class_<Urho3D::Camera, Urho3D::Component>(pyclass_NS__Urho3D, "Camera", "test doc");
// Class CascadeParameters
auto pyclass_Var_Urho3D_CascadeParameters = py::class_<Urho3D::CascadeParameters>(pyclass_NS__Urho3D, "CascadeParameters", "test doc");
// Class CharLocation
auto pyclass_Var_Urho3D_CharLocation = py::class_<Urho3D::CharLocation>(pyclass_NS__Urho3D, "CharLocation", "test doc");
// Class Object
auto pyclass_Var_Urho3D_Object = py::class_<Urho3D::Object, Urho3D::RefCounted>(pyclass_NS__Urho3D, "Object", "test doc");
// Class CheckBox
auto pyclass_Var_Urho3D_CheckBox = py::class_<Urho3D::CheckBox, Urho3D::BorderImage>(pyclass_NS__Urho3D, "CheckBox", "test doc");
// Class Component
auto pyclass_Var_Urho3D_Component = py::class_<Urho3D::Component, Urho3D::Animatable>(pyclass_NS__Urho3D, "Component", "test doc");
// Class CollisionBox2D
auto pyclass_Var_Urho3D_CollisionBox2D = py::class_<Urho3D::CollisionBox2D, Urho3D::CollisionShape2D>(pyclass_NS__Urho3D, "CollisionBox2D", "test doc");
// Class CollisionChain2D
auto pyclass_Var_Urho3D_CollisionChain2D = py::class_<Urho3D::CollisionChain2D, Urho3D::CollisionShape2D>(pyclass_NS__Urho3D, "CollisionChain2D", "test doc");
// Class CollisionCircle2D
auto pyclass_Var_Urho3D_CollisionCircle2D = py::class_<Urho3D::CollisionCircle2D, Urho3D::CollisionShape2D>(pyclass_NS__Urho3D, "CollisionCircle2D", "test doc");
// Class CollisionGeometryData
auto pyclass_Var_Urho3D_CollisionGeometryData = py::class_<Urho3D::CollisionGeometryData, Urho3D::RefCounted>(pyclass_NS__Urho3D, "CollisionGeometryData", "test doc");
// Class CollisionShape
auto pyclass_Var_Urho3D_CollisionShape = py::class_<Urho3D::CollisionShape, Urho3D::Component>(pyclass_NS__Urho3D, "CollisionShape", "test doc");
// Class CollisionShape2D
auto pyclass_Var_Urho3D_CollisionShape2D = py::class_<Urho3D::CollisionShape2D, Urho3D::Component>(pyclass_NS__Urho3D, "CollisionShape2D", "test doc");
// Class CollisionEdge2D
auto pyclass_Var_Urho3D_CollisionEdge2D = py::class_<Urho3D::CollisionEdge2D, Urho3D::CollisionShape2D>(pyclass_NS__Urho3D, "CollisionEdge2D", "test doc");
// Class CollisionPolygon2D
auto pyclass_Var_Urho3D_CollisionPolygon2D = py::class_<Urho3D::CollisionPolygon2D, Urho3D::CollisionShape2D>(pyclass_NS__Urho3D, "CollisionPolygon2D", "test doc");
// Class Color
auto pyclass_Var_Urho3D_Color = py::class_<Urho3D::Color>(pyclass_NS__Urho3D, "Color", "test doc");
// Class ColorFrame
auto pyclass_Var_Urho3D_ColorFrame = py::class_<Urho3D::ColorFrame>(pyclass_NS__Urho3D, "ColorFrame", "test doc");
// Class ComponentReplicationState
auto pyclass_Var_Urho3D_ComponentReplicationState = py::class_<Urho3D::ComponentReplicationState, Urho3D::ReplicationState>(pyclass_NS__Urho3D, "ComponentReplicationState", "test doc");
// Class CompressedLevel
auto pyclass_Var_Urho3D_CompressedLevel = py::class_<Urho3D::CompressedLevel>(pyclass_NS__Urho3D, "CompressedLevel", "test doc");
// Class Condition
auto pyclass_Var_Urho3D_Condition = py::class_<Urho3D::Condition>(pyclass_NS__Urho3D, "Condition", "test doc");
// Class Connection
auto pyclass_Var_Urho3D_Connection = py::class_<Urho3D::Connection, Urho3D::Object>(pyclass_NS__Urho3D, "Connection", "test doc");
// Class Console
auto pyclass_Var_Urho3D_Console = py::class_<Urho3D::Console, Urho3D::Object>(pyclass_NS__Urho3D, "Console", "test doc");
// Class ConstantBuffer
auto pyclass_Var_Urho3D_ConstantBuffer = py::class_<Urho3D::ConstantBuffer, Urho3D::Object, Urho3D::GPUObject>(pyclass_NS__Urho3D, "ConstantBuffer", "test doc");
// Class Constraint
auto pyclass_Var_Urho3D_Constraint = py::class_<Urho3D::Constraint, Urho3D::Component>(pyclass_NS__Urho3D, "Constraint", "test doc");
// Class Constraint2D
auto pyclass_Var_Urho3D_Constraint2D = py::class_<Urho3D::Constraint2D, Urho3D::Component>(pyclass_NS__Urho3D, "Constraint2D", "test doc");
// Class ConstraintDistance2D
auto pyclass_Var_Urho3D_ConstraintDistance2D = py::class_<Urho3D::ConstraintDistance2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintDistance2D", "test doc");
// Class ConstraintFriction2D
auto pyclass_Var_Urho3D_ConstraintFriction2D = py::class_<Urho3D::ConstraintFriction2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintFriction2D", "test doc");
// Class ConstraintGear2D
auto pyclass_Var_Urho3D_ConstraintGear2D = py::class_<Urho3D::ConstraintGear2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintGear2D", "test doc");
// Class ConstraintMotor2D
auto pyclass_Var_Urho3D_ConstraintMotor2D = py::class_<Urho3D::ConstraintMotor2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintMotor2D", "test doc");
// Class ConstraintMouse2D
auto pyclass_Var_Urho3D_ConstraintMouse2D = py::class_<Urho3D::ConstraintMouse2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintMouse2D", "test doc");
// Class ConstraintPrismatic2D
auto pyclass_Var_Urho3D_ConstraintPrismatic2D = py::class_<Urho3D::ConstraintPrismatic2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintPrismatic2D", "test doc");
// Class ConstraintPulley2D
auto pyclass_Var_Urho3D_ConstraintPulley2D = py::class_<Urho3D::ConstraintPulley2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintPulley2D", "test doc");
// Class ConstraintRevolute2D
auto pyclass_Var_Urho3D_ConstraintRevolute2D = py::class_<Urho3D::ConstraintRevolute2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintRevolute2D", "test doc");
// Class ConstraintRope2D
auto pyclass_Var_Urho3D_ConstraintRope2D = py::class_<Urho3D::ConstraintRope2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintRope2D", "test doc");
// Class ConstraintWeld2D
auto pyclass_Var_Urho3D_ConstraintWeld2D = py::class_<Urho3D::ConstraintWeld2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintWeld2D", "test doc");
// Class ConstraintWheel2D
auto pyclass_Var_Urho3D_ConstraintWheel2D = py::class_<Urho3D::ConstraintWheel2D, Urho3D::Constraint2D>(pyclass_NS__Urho3D, "ConstraintWheel2D", "test doc");
// Class Context
auto pyclass_Var_Urho3D_Context = py::class_<Urho3D::Context, Urho3D::RefCounted>(pyclass_NS__Urho3D, "Context", "test doc");
// Class Controls
auto pyclass_Var_Urho3D_Controls = py::class_<Urho3D::Controls>(pyclass_NS__Urho3D, "Controls", "test doc");
// Class ConvexData
auto pyclass_Var_Urho3D_ConvexData = py::class_<Urho3D::ConvexData, Urho3D::CollisionGeometryData>(pyclass_NS__Urho3D, "ConvexData", "test doc");
// Class CrowdAgent
auto pyclass_Var_Urho3D_CrowdAgent = py::class_<Urho3D::CrowdAgent, Urho3D::Component>(pyclass_NS__Urho3D, "CrowdAgent", "test doc");
// Class CrowdManager
auto pyclass_Var_Urho3D_CrowdManager = py::class_<Urho3D::CrowdManager, Urho3D::Component>(pyclass_NS__Urho3D, "CrowdManager", "test doc");
// Class CrowdObstacleAvoidanceParams
auto pyclass_Var_Urho3D_CrowdObstacleAvoidanceParams = py::class_<Urho3D::CrowdObstacleAvoidanceParams>(pyclass_NS__Urho3D, "CrowdObstacleAvoidanceParams", "test doc");
// Class Cursor
auto pyclass_Var_Urho3D_Cursor = py::class_<Urho3D::Cursor, Urho3D::BorderImage>(pyclass_NS__Urho3D, "Cursor", "test doc");
// Class CursorShapeInfo
auto pyclass_Var_Urho3D_CursorShapeInfo = py::class_<Urho3D::CursorShapeInfo>(pyclass_NS__Urho3D, "CursorShapeInfo", "test doc");
// Class CustomGeometry
auto pyclass_Var_Urho3D_CustomGeometry = py::class_<Urho3D::CustomGeometry, Urho3D::Drawable>(pyclass_NS__Urho3D, "CustomGeometry", "test doc");
// Class CustomGeometryVertex
auto pyclass_Var_Urho3D_CustomGeometryVertex = py::class_<Urho3D::CustomGeometryVertex>(pyclass_NS__Urho3D, "CustomGeometryVertex", "test doc");
// Class DebugHud
auto pyclass_Var_Urho3D_DebugHud = py::class_<Urho3D::DebugHud, Urho3D::Object>(pyclass_NS__Urho3D, "DebugHud", "test doc");
// Class DebugLine
auto pyclass_Var_Urho3D_DebugLine = py::class_<Urho3D::DebugLine>(pyclass_NS__Urho3D, "DebugLine", "test doc");
// Class DebugRenderer
auto pyclass_Var_Urho3D_DebugRenderer = py::class_<Urho3D::DebugRenderer, Urho3D::Component>(pyclass_NS__Urho3D, "DebugRenderer", "test doc");
// Class DebugTriangle
auto pyclass_Var_Urho3D_DebugTriangle = py::class_<Urho3D::DebugTriangle>(pyclass_NS__Urho3D, "DebugTriangle", "test doc");
// Class Decal
auto pyclass_Var_Urho3D_Decal = py::class_<Urho3D::Decal>(pyclass_NS__Urho3D, "Decal", "test doc");
// Class DecalVertex
auto pyclass_Var_Urho3D_DecalVertex = py::class_<Urho3D::DecalVertex>(pyclass_NS__Urho3D, "DecalVertex", "test doc");
// Class DelayedWorldTransform2D
auto pyclass_Var_Urho3D_DelayedWorldTransform2D = py::class_<Urho3D::DelayedWorldTransform2D>(pyclass_NS__Urho3D, "DelayedWorldTransform2D", "test doc");
// Class Deserializer
auto pyclass_Var_Urho3D_Deserializer = py::class_<Urho3D::Deserializer>(pyclass_NS__Urho3D, "Deserializer", "test doc");
// Class Drawable
auto pyclass_Var_Urho3D_Drawable = py::class_<Urho3D::Drawable, Urho3D::Component>(pyclass_NS__Urho3D, "Drawable", "test doc");
// Class DecalSet
auto pyclass_Var_Urho3D_DecalSet = py::class_<Urho3D::DecalSet, Urho3D::Drawable>(pyclass_NS__Urho3D, "DecalSet", "test doc");
// Class DelayedCall
auto pyclass_Var_Urho3D_DelayedCall = py::class_<Urho3D::DelayedCall>(pyclass_NS__Urho3D, "DelayedCall", "test doc");
// Class DelayedWorldTransform
auto pyclass_Var_Urho3D_DelayedWorldTransform = py::class_<Urho3D::DelayedWorldTransform>(pyclass_NS__Urho3D, "DelayedWorldTransform", "test doc");
// Class DepthValue
auto pyclass_Var_Urho3D_DepthValue = py::class_<Urho3D::DepthValue>(pyclass_NS__Urho3D, "DepthValue", "test doc");
// Class DirtyBits
auto pyclass_Var_Urho3D_DirtyBits = py::class_<Urho3D::DirtyBits>(pyclass_NS__Urho3D, "DirtyBits", "test doc");
// Class Drawable2D
auto pyclass_Var_Urho3D_Drawable2D = py::class_<Urho3D::Drawable2D, Urho3D::Drawable>(pyclass_NS__Urho3D, "Drawable2D", "test doc");
// Class DropDownList
auto pyclass_Var_Urho3D_DropDownList = py::class_<Urho3D::DropDownList, Urho3D::Menu>(pyclass_NS__Urho3D, "DropDownList", "test doc");
// Class DynamicNavBuildData
auto pyclass_Var_Urho3D_DynamicNavBuildData = py::class_<Urho3D::DynamicNavBuildData, Urho3D::NavBuildData>(pyclass_NS__Urho3D, "DynamicNavBuildData", "test doc");
// Class DynamicNavigationMesh
auto pyclass_Var_Urho3D_DynamicNavigationMesh = py::class_<Urho3D::DynamicNavigationMesh, Urho3D::NavigationMesh>(pyclass_NS__Urho3D, "DynamicNavigationMesh", "test doc");
// Class Engine
auto pyclass_Var_Urho3D_Engine = py::class_<Urho3D::Engine, Urho3D::Object>(pyclass_NS__Urho3D, "Engine", "test doc");
// Class EventHandler
auto pyclass_Var_Urho3D_EventHandler = py::class_<Urho3D::EventHandler, Urho3D::LinkedListNode>(pyclass_NS__Urho3D, "EventHandler", "test doc");
// Class EventNameRegistrar
auto pyclass_Var_Urho3D_EventNameRegistrar = py::class_<Urho3D::EventNameRegistrar>(pyclass_NS__Urho3D, "EventNameRegistrar", "test doc");
// Class EventProfiler
auto pyclass_Var_Urho3D_EventProfiler = py::class_<Urho3D::EventProfiler, Urho3D::Profiler>(pyclass_NS__Urho3D, "EventProfiler", "test doc");
// Class EventProfilerBlock
auto pyclass_Var_Urho3D_EventProfilerBlock = py::class_<Urho3D::EventProfilerBlock, Urho3D::ProfilerBlock>(pyclass_NS__Urho3D, "EventProfilerBlock", "test doc");
// Class EventReceiverGroup
auto pyclass_Var_Urho3D_EventReceiverGroup = py::class_<Urho3D::EventReceiverGroup, Urho3D::RefCounted>(pyclass_NS__Urho3D, "EventReceiverGroup", "test doc");
// Class File
auto pyclass_Var_Urho3D_File = py::class_<Urho3D::File, Urho3D::Object, Urho3D::AbstractFile>(pyclass_NS__Urho3D, "File", "test doc");
// Class FileSelector
auto pyclass_Var_Urho3D_FileSelector = py::class_<Urho3D::FileSelector, Urho3D::Object>(pyclass_NS__Urho3D, "FileSelector", "test doc");
// Class FileSelectorEntry
auto pyclass_Var_Urho3D_FileSelectorEntry = py::class_<Urho3D::FileSelectorEntry>(pyclass_NS__Urho3D, "FileSelectorEntry", "test doc");
// Class FileSystem
auto pyclass_Var_Urho3D_FileSystem = py::class_<Urho3D::FileSystem, Urho3D::Object>(pyclass_NS__Urho3D, "FileSystem", "test doc");
// Class FileWatcher
auto pyclass_Var_Urho3D_FileWatcher = py::class_<Urho3D::FileWatcher, Urho3D::Object, Urho3D::Thread>(pyclass_NS__Urho3D, "FileWatcher", "test doc");
// Class FocusParameters
auto pyclass_Var_Urho3D_FocusParameters = py::class_<Urho3D::FocusParameters>(pyclass_NS__Urho3D, "FocusParameters", "test doc");
// Class Font
auto pyclass_Var_Urho3D_Font = py::class_<Urho3D::Font, Urho3D::Resource>(pyclass_NS__Urho3D, "Font", "test doc");
// Class FontFace
auto pyclass_Var_Urho3D_FontFace = py::class_<Urho3D::FontFace, Urho3D::RefCounted>(pyclass_NS__Urho3D, "FontFace", "test doc");
// Class FontFaceBitmap
auto pyclass_Var_Urho3D_FontFaceBitmap = py::class_<Urho3D::FontFaceBitmap, Urho3D::FontFace>(pyclass_NS__Urho3D, "FontFaceBitmap", "test doc");
// Class FontFaceFreeType
auto pyclass_Var_Urho3D_FontFaceFreeType = py::class_<Urho3D::FontFaceFreeType, Urho3D::FontFace>(pyclass_NS__Urho3D, "FontFaceFreeType", "test doc");
// Class FontGlyph
auto pyclass_Var_Urho3D_FontGlyph = py::class_<Urho3D::FontGlyph>(pyclass_NS__Urho3D, "FontGlyph", "test doc");
// Class FrameBufferObject
auto pyclass_Var_Urho3D_FrameBufferObject = py::class_<Urho3D::FrameBufferObject>(pyclass_NS__Urho3D, "FrameBufferObject", "test doc");
// Class FrameInfo
auto pyclass_Var_Urho3D_FrameInfo = py::class_<Urho3D::FrameInfo>(pyclass_NS__Urho3D, "FrameInfo", "test doc");
// Class Frustum
auto pyclass_Var_Urho3D_Frustum = py::class_<Urho3D::Frustum>(pyclass_NS__Urho3D, "Frustum", "test doc");
// Class FrustumOctreeQuery
auto pyclass_Var_Urho3D_FrustumOctreeQuery = py::class_<Urho3D::FrustumOctreeQuery, Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "FrustumOctreeQuery", "test doc");
// Class GPUObject
auto pyclass_Var_Urho3D_GPUObject = py::class_<Urho3D::GPUObject>(pyclass_NS__Urho3D, "GPUObject", "test doc");
// Class Geometry
auto pyclass_Var_Urho3D_Geometry = py::class_<Urho3D::Geometry, Urho3D::Object>(pyclass_NS__Urho3D, "Geometry", "test doc");
// Class GeometryDesc
auto pyclass_Var_Urho3D_GeometryDesc = py::class_<Urho3D::GeometryDesc>(pyclass_NS__Urho3D, "GeometryDesc", "test doc");
// Class GlyphLocation
auto pyclass_Var_Urho3D_GlyphLocation = py::class_<Urho3D::GlyphLocation>(pyclass_NS__Urho3D, "GlyphLocation", "test doc");
// Class Graphics
auto pyclass_Var_Urho3D_Graphics = py::class_<Urho3D::Graphics, Urho3D::Object>(pyclass_NS__Urho3D, "Graphics", "test doc");
// Class GraphicsImpl
auto pyclass_Var_Urho3D_GraphicsImpl = py::class_<Urho3D::GraphicsImpl>(pyclass_NS__Urho3D, "GraphicsImpl", "test doc");
// Class HashBase
auto pyclass_Var_Urho3D_HashBase = py::class_<Urho3D::HashBase>(pyclass_NS__Urho3D, "HashBase", "test doc");
// Class HashIteratorBase
auto pyclass_Var_Urho3D_HashIteratorBase = py::class_<Urho3D::HashIteratorBase>(pyclass_NS__Urho3D, "HashIteratorBase", "test doc");
// Class HashNodeBase
auto pyclass_Var_Urho3D_HashNodeBase = py::class_<Urho3D::HashNodeBase>(pyclass_NS__Urho3D, "HashNodeBase", "test doc");
// Class HeightfieldData
auto pyclass_Var_Urho3D_HeightfieldData = py::class_<Urho3D::HeightfieldData, Urho3D::CollisionGeometryData>(pyclass_NS__Urho3D, "HeightfieldData", "test doc");
// Class HiresTimer
auto pyclass_Var_Urho3D_HiresTimer = py::class_<Urho3D::HiresTimer>(pyclass_NS__Urho3D, "HiresTimer", "test doc");
// Class HttpRequest
auto pyclass_Var_Urho3D_HttpRequest = py::class_<Urho3D::HttpRequest, Urho3D::RefCounted, Urho3D::Deserializer, Urho3D::Thread>(pyclass_NS__Urho3D, "HttpRequest", "test doc");
// Class Image
auto pyclass_Var_Urho3D_Image = py::class_<Urho3D::Image, Urho3D::Resource>(pyclass_NS__Urho3D, "Image", "test doc");
// Class IndexBuffer
auto pyclass_Var_Urho3D_IndexBuffer = py::class_<Urho3D::IndexBuffer, Urho3D::Object, Urho3D::GPUObject>(pyclass_NS__Urho3D, "IndexBuffer", "test doc");
// Class IndexBufferDesc
auto pyclass_Var_Urho3D_IndexBufferDesc = py::class_<Urho3D::IndexBufferDesc>(pyclass_NS__Urho3D, "IndexBufferDesc", "test doc");
// Class Input
auto pyclass_Var_Urho3D_Input = py::class_<Urho3D::Input, Urho3D::Object>(pyclass_NS__Urho3D, "Input", "test doc");
// Class InstanceData
auto pyclass_Var_Urho3D_InstanceData = py::class_<Urho3D::InstanceData>(pyclass_NS__Urho3D, "InstanceData", "test doc");
// Class IntRect
auto pyclass_Var_Urho3D_IntRect = py::class_<Urho3D::IntRect>(pyclass_NS__Urho3D, "IntRect", "test doc");
// Class IntVector2
auto pyclass_Var_Urho3D_IntVector2 = py::class_<Urho3D::IntVector2>(pyclass_NS__Urho3D, "IntVector2", "test doc");
// Class IntVector3
auto pyclass_Var_Urho3D_IntVector3 = py::class_<Urho3D::IntVector3>(pyclass_NS__Urho3D, "IntVector3", "test doc");
// Class JSONFile
auto pyclass_Var_Urho3D_JSONFile = py::class_<Urho3D::JSONFile, Urho3D::Resource>(pyclass_NS__Urho3D, "JSONFile", "test doc");
// Class JSONValue
auto pyclass_Var_Urho3D_JSONValue = py::class_<Urho3D::JSONValue>(pyclass_NS__Urho3D, "JSONValue", "test doc");
// Class JoystickState
auto pyclass_Var_Urho3D_JoystickState = py::class_<Urho3D::JoystickState>(pyclass_NS__Urho3D, "JoystickState", "test doc");
// Class Light
auto pyclass_Var_Urho3D_Light = py::class_<Urho3D::Light, Urho3D::Drawable>(pyclass_NS__Urho3D, "Light", "test doc");
// Class LightBatchQueue
auto pyclass_Var_Urho3D_LightBatchQueue = py::class_<Urho3D::LightBatchQueue>(pyclass_NS__Urho3D, "LightBatchQueue", "test doc");
// Class LightQueryResult
auto pyclass_Var_Urho3D_LightQueryResult = py::class_<Urho3D::LightQueryResult>(pyclass_NS__Urho3D, "LightQueryResult", "test doc");
// Class LineEdit
auto pyclass_Var_Urho3D_LineEdit = py::class_<Urho3D::LineEdit, Urho3D::BorderImage>(pyclass_NS__Urho3D, "LineEdit", "test doc");
// Class LinkedListNode
auto pyclass_Var_Urho3D_LinkedListNode = py::class_<Urho3D::LinkedListNode>(pyclass_NS__Urho3D, "LinkedListNode", "test doc");
// Class ListBase
auto pyclass_Var_Urho3D_ListBase = py::class_<Urho3D::ListBase>(pyclass_NS__Urho3D, "ListBase", "test doc");
// Class ListIteratorBase
auto pyclass_Var_Urho3D_ListIteratorBase = py::class_<Urho3D::ListIteratorBase>(pyclass_NS__Urho3D, "ListIteratorBase", "test doc");
// Class ListNodeBase
auto pyclass_Var_Urho3D_ListNodeBase = py::class_<Urho3D::ListNodeBase>(pyclass_NS__Urho3D, "ListNodeBase", "test doc");
// Class ListView
auto pyclass_Var_Urho3D_ListView = py::class_<Urho3D::ListView, Urho3D::ScrollView>(pyclass_NS__Urho3D, "ListView", "test doc");
// Class Localization
auto pyclass_Var_Urho3D_Localization = py::class_<Urho3D::Localization, Urho3D::Object>(pyclass_NS__Urho3D, "Localization", "test doc");
// Class Log
auto pyclass_Var_Urho3D_Log = py::class_<Urho3D::Log, Urho3D::Object>(pyclass_NS__Urho3D, "Log", "test doc");
// Class LogicComponent
auto pyclass_Var_Urho3D_LogicComponent = py::class_<Urho3D::LogicComponent, Urho3D::Component>(pyclass_NS__Urho3D, "LogicComponent", "test doc");
// Class ManifoldPair
auto pyclass_Var_Urho3D_ManifoldPair = py::class_<Urho3D::ManifoldPair>(pyclass_NS__Urho3D, "ManifoldPair", "test doc");
// Class Material
auto pyclass_Var_Urho3D_Material = py::class_<Urho3D::Material, Urho3D::Resource>(pyclass_NS__Urho3D, "Material", "test doc");
// Class MaterialShaderParameter
auto pyclass_Var_Urho3D_MaterialShaderParameter = py::class_<Urho3D::MaterialShaderParameter>(pyclass_NS__Urho3D, "MaterialShaderParameter", "test doc");
// Class Matrix2
auto pyclass_Var_Urho3D_Matrix2 = py::class_<Urho3D::Matrix2>(pyclass_NS__Urho3D, "Matrix2", "test doc");
// Class Matrix3
auto pyclass_Var_Urho3D_Matrix3 = py::class_<Urho3D::Matrix3>(pyclass_NS__Urho3D, "Matrix3", "test doc");
// Class Matrix3x4
auto pyclass_Var_Urho3D_Matrix3x4 = py::class_<Urho3D::Matrix3x4>(pyclass_NS__Urho3D, "Matrix3x4", "test doc");
// Class Matrix4
auto pyclass_Var_Urho3D_Matrix4 = py::class_<Urho3D::Matrix4>(pyclass_NS__Urho3D, "Matrix4", "test doc");
// Class MemoryBuffer
auto pyclass_Var_Urho3D_MemoryBuffer = py::class_<Urho3D::MemoryBuffer, Urho3D::AbstractFile>(pyclass_NS__Urho3D, "MemoryBuffer", "test doc");
// Class Menu
auto pyclass_Var_Urho3D_Menu = py::class_<Urho3D::Menu, Urho3D::Button>(pyclass_NS__Urho3D, "Menu", "test doc");
// Class MessageBox
auto pyclass_Var_Urho3D_MessageBox = py::class_<Urho3D::MessageBox, Urho3D::Object>(pyclass_NS__Urho3D, "MessageBox", "test doc");
// Class Model
auto pyclass_Var_Urho3D_Model = py::class_<Urho3D::Model, Urho3D::ResourceWithMetadata>(pyclass_NS__Urho3D, "Model", "test doc");
// Class ModelMorph
auto pyclass_Var_Urho3D_ModelMorph = py::class_<Urho3D::ModelMorph>(pyclass_NS__Urho3D, "ModelMorph", "test doc");
// Class Mutex
auto pyclass_Var_Urho3D_Mutex = py::class_<Urho3D::Mutex>(pyclass_NS__Urho3D, "Mutex", "test doc");
// Class MutexLock
auto pyclass_Var_Urho3D_MutexLock = py::class_<Urho3D::MutexLock>(pyclass_NS__Urho3D, "MutexLock", "test doc");
// Class NamedPipe
auto pyclass_Var_Urho3D_NamedPipe = py::class_<Urho3D::NamedPipe, Urho3D::Object, Urho3D::AbstractFile>(pyclass_NS__Urho3D, "NamedPipe", "test doc");
// Class NavArea
auto pyclass_Var_Urho3D_NavArea = py::class_<Urho3D::NavArea, Urho3D::Component>(pyclass_NS__Urho3D, "NavArea", "test doc");
// Class NavAreaStub
auto pyclass_Var_Urho3D_NavAreaStub = py::class_<Urho3D::NavAreaStub>(pyclass_NS__Urho3D, "NavAreaStub", "test doc");
// Class NavBuildData
auto pyclass_Var_Urho3D_NavBuildData = py::class_<Urho3D::NavBuildData>(pyclass_NS__Urho3D, "NavBuildData", "test doc");
// Class Navigable
auto pyclass_Var_Urho3D_Navigable = py::class_<Urho3D::Navigable, Urho3D::Component>(pyclass_NS__Urho3D, "Navigable", "test doc");
// Class NavigationGeometryInfo
auto pyclass_Var_Urho3D_NavigationGeometryInfo = py::class_<Urho3D::NavigationGeometryInfo>(pyclass_NS__Urho3D, "NavigationGeometryInfo", "test doc");
// Class NavigationMesh
auto pyclass_Var_Urho3D_NavigationMesh = py::class_<Urho3D::NavigationMesh, Urho3D::Component>(pyclass_NS__Urho3D, "NavigationMesh", "test doc");
// Class NavigationPathPoint
auto pyclass_Var_Urho3D_NavigationPathPoint = py::class_<Urho3D::NavigationPathPoint>(pyclass_NS__Urho3D, "NavigationPathPoint", "test doc");
// Class Network
auto pyclass_Var_Urho3D_Network = py::class_<Urho3D::Network, Urho3D::Object, kNet::IMessageHandler, kNet::INetworkServerListener>(pyclass_NS__Urho3D, "Network", "test doc");
// Class NetworkPriority
auto pyclass_Var_Urho3D_NetworkPriority = py::class_<Urho3D::NetworkPriority, Urho3D::Component>(pyclass_NS__Urho3D, "NetworkPriority", "test doc");
// Class NetworkState
auto pyclass_Var_Urho3D_NetworkState = py::class_<Urho3D::NetworkState>(pyclass_NS__Urho3D, "NetworkState", "test doc");
// Class Node
auto pyclass_Var_Urho3D_Node = py::class_<Urho3D::Node, Urho3D::Animatable>(pyclass_NS__Urho3D, "Node", "test doc");
// Class NodeImpl
auto pyclass_Var_Urho3D_NodeImpl = py::class_<Urho3D::NodeImpl>(pyclass_NS__Urho3D, "NodeImpl", "test doc");
// Class NodeReplicationState
auto pyclass_Var_Urho3D_NodeReplicationState = py::class_<Urho3D::NodeReplicationState, Urho3D::ReplicationState>(pyclass_NS__Urho3D, "NodeReplicationState", "test doc");
// Class ObjectAnimation
auto pyclass_Var_Urho3D_ObjectAnimation = py::class_<Urho3D::ObjectAnimation, Urho3D::Resource>(pyclass_NS__Urho3D, "ObjectAnimation", "test doc");
// Class ObjectFactory
auto pyclass_Var_Urho3D_ObjectFactory = py::class_<Urho3D::ObjectFactory, Urho3D::RefCounted>(pyclass_NS__Urho3D, "ObjectFactory", "test doc");
// Class Obstacle
auto pyclass_Var_Urho3D_Obstacle = py::class_<Urho3D::Obstacle, Urho3D::Component>(pyclass_NS__Urho3D, "Obstacle", "test doc");
// Class OcclusionBatch
auto pyclass_Var_Urho3D_OcclusionBatch = py::class_<Urho3D::OcclusionBatch>(pyclass_NS__Urho3D, "OcclusionBatch", "test doc");
// Class OcclusionBuffer
auto pyclass_Var_Urho3D_OcclusionBuffer = py::class_<Urho3D::OcclusionBuffer, Urho3D::Object>(pyclass_NS__Urho3D, "OcclusionBuffer", "test doc");
// Class OcclusionBufferData
auto pyclass_Var_Urho3D_OcclusionBufferData = py::class_<Urho3D::OcclusionBufferData>(pyclass_NS__Urho3D, "OcclusionBufferData", "test doc");
// Class Octant
auto pyclass_Var_Urho3D_Octant = py::class_<Urho3D::Octant>(pyclass_NS__Urho3D, "Octant", "test doc");
// Class Octree
auto pyclass_Var_Urho3D_Octree = py::class_<Urho3D::Octree, Urho3D::Component, Urho3D::Octant>(pyclass_NS__Urho3D, "Octree", "test doc");
// Class OctreeQuery
auto pyclass_Var_Urho3D_OctreeQuery = py::class_<Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "OctreeQuery", "test doc");
// Class OctreeQueryResult
auto pyclass_Var_Urho3D_OctreeQueryResult = py::class_<Urho3D::OctreeQueryResult>(pyclass_NS__Urho3D, "OctreeQueryResult", "test doc");
// Class OffMeshConnection
auto pyclass_Var_Urho3D_OffMeshConnection = py::class_<Urho3D::OffMeshConnection, Urho3D::Component>(pyclass_NS__Urho3D, "OffMeshConnection", "test doc");
// Class OggVorbisSoundStream
auto pyclass_Var_Urho3D_OggVorbisSoundStream = py::class_<Urho3D::OggVorbisSoundStream, Urho3D::SoundStream>(pyclass_NS__Urho3D, "OggVorbisSoundStream", "test doc");
// Class PListFile
auto pyclass_Var_Urho3D_PListFile = py::class_<Urho3D::PListFile, Urho3D::Resource>(pyclass_NS__Urho3D, "PListFile", "test doc");
// Class PListValue
auto pyclass_Var_Urho3D_PListValue = py::class_<Urho3D::PListValue>(pyclass_NS__Urho3D, "PListValue", "test doc");
// Class PackageDownload
auto pyclass_Var_Urho3D_PackageDownload = py::class_<Urho3D::PackageDownload>(pyclass_NS__Urho3D, "PackageDownload", "test doc");
// Class PackageEntry
auto pyclass_Var_Urho3D_PackageEntry = py::class_<Urho3D::PackageEntry>(pyclass_NS__Urho3D, "PackageEntry", "test doc");
// Class PackageFile
auto pyclass_Var_Urho3D_PackageFile = py::class_<Urho3D::PackageFile, Urho3D::Object>(pyclass_NS__Urho3D, "PackageFile", "test doc");
// Class PackageUpload
auto pyclass_Var_Urho3D_PackageUpload = py::class_<Urho3D::PackageUpload>(pyclass_NS__Urho3D, "PackageUpload", "test doc");
// Class Particle
auto pyclass_Var_Urho3D_Particle = py::class_<Urho3D::Particle>(pyclass_NS__Urho3D, "Particle", "test doc");
// Class Particle2D
auto pyclass_Var_Urho3D_Particle2D = py::class_<Urho3D::Particle2D>(pyclass_NS__Urho3D, "Particle2D", "test doc");
// Class ParticleEffect
auto pyclass_Var_Urho3D_ParticleEffect = py::class_<Urho3D::ParticleEffect, Urho3D::Resource>(pyclass_NS__Urho3D, "ParticleEffect", "test doc");
// Class ParticleEffect2D
auto pyclass_Var_Urho3D_ParticleEffect2D = py::class_<Urho3D::ParticleEffect2D, Urho3D::Resource>(pyclass_NS__Urho3D, "ParticleEffect2D", "test doc");
// Class ParticleEmitter
auto pyclass_Var_Urho3D_ParticleEmitter = py::class_<Urho3D::ParticleEmitter, Urho3D::BillboardSet>(pyclass_NS__Urho3D, "ParticleEmitter", "test doc");
// Class ParticleEmitter2D
auto pyclass_Var_Urho3D_ParticleEmitter2D = py::class_<Urho3D::ParticleEmitter2D, Urho3D::Drawable2D>(pyclass_NS__Urho3D, "ParticleEmitter2D", "test doc");
// Class Pass
auto pyclass_Var_Urho3D_Pass = py::class_<Urho3D::Pass, Urho3D::RefCounted>(pyclass_NS__Urho3D, "Pass", "test doc");
// Class PerThreadSceneResult
auto pyclass_Var_Urho3D_PerThreadSceneResult = py::class_<Urho3D::PerThreadSceneResult>(pyclass_NS__Urho3D, "PerThreadSceneResult", "test doc");
// Class PhysicsRaycastResult
auto pyclass_Var_Urho3D_PhysicsRaycastResult = py::class_<Urho3D::PhysicsRaycastResult>(pyclass_NS__Urho3D, "PhysicsRaycastResult", "test doc");
// Class PhysicsRaycastResult2D
auto pyclass_Var_Urho3D_PhysicsRaycastResult2D = py::class_<Urho3D::PhysicsRaycastResult2D>(pyclass_NS__Urho3D, "PhysicsRaycastResult2D", "test doc");
// Class PhysicsWorld
auto pyclass_Var_Urho3D_PhysicsWorld = py::class_<Urho3D::PhysicsWorld, Urho3D::Component, btIDebugDraw>(pyclass_NS__Urho3D, "PhysicsWorld", "test doc");
// Class PhysicsWorld2D
auto pyclass_Var_Urho3D_PhysicsWorld2D = py::class_<Urho3D::PhysicsWorld2D, Urho3D::Component, b2ContactListener, b2Draw>(pyclass_NS__Urho3D, "PhysicsWorld2D", "test doc");
// Class PhysicsWorldConfig
auto pyclass_Var_Urho3D_PhysicsWorldConfig = py::class_<Urho3D::PhysicsWorldConfig>(pyclass_NS__Urho3D, "PhysicsWorldConfig", "test doc");
// Class Plane
auto pyclass_Var_Urho3D_Plane = py::class_<Urho3D::Plane>(pyclass_NS__Urho3D, "Plane", "test doc");
// Class PointOctreeQuery
auto pyclass_Var_Urho3D_PointOctreeQuery = py::class_<Urho3D::PointOctreeQuery, Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "PointOctreeQuery", "test doc");
// Class Polyhedron
auto pyclass_Var_Urho3D_Polyhedron = py::class_<Urho3D::Polyhedron>(pyclass_NS__Urho3D, "Polyhedron", "test doc");
// Class Profiler
auto pyclass_Var_Urho3D_Profiler = py::class_<Urho3D::Profiler, Urho3D::Object>(pyclass_NS__Urho3D, "Profiler", "test doc");
// Class ProfilerBlock
auto pyclass_Var_Urho3D_ProfilerBlock = py::class_<Urho3D::ProfilerBlock>(pyclass_NS__Urho3D, "ProfilerBlock", "test doc");
// Class ProgressBar
auto pyclass_Var_Urho3D_ProgressBar = py::class_<Urho3D::ProgressBar, Urho3D::BorderImage>(pyclass_NS__Urho3D, "ProgressBar", "test doc");
// Class PropertySet2D
auto pyclass_Var_Urho3D_PropertySet2D = py::class_<Urho3D::PropertySet2D, Urho3D::RefCounted>(pyclass_NS__Urho3D, "PropertySet2D", "test doc");
// Class Quaternion
auto pyclass_Var_Urho3D_Quaternion = py::class_<Urho3D::Quaternion>(pyclass_NS__Urho3D, "Quaternion", "test doc");
// Class Ray
auto pyclass_Var_Urho3D_Ray = py::class_<Urho3D::Ray>(pyclass_NS__Urho3D, "Ray", "test doc");
// Class RayOctreeQuery
auto pyclass_Var_Urho3D_RayOctreeQuery = py::class_<Urho3D::RayOctreeQuery>(pyclass_NS__Urho3D, "RayOctreeQuery", "test doc");
// Class RayQueryResult
auto pyclass_Var_Urho3D_RayQueryResult = py::class_<Urho3D::RayQueryResult>(pyclass_NS__Urho3D, "RayQueryResult", "test doc");
// Class RaycastVehicle
auto pyclass_Var_Urho3D_RaycastVehicle = py::class_<Urho3D::RaycastVehicle, Urho3D::LogicComponent>(pyclass_NS__Urho3D, "RaycastVehicle", "test doc");
// Class Rect
auto pyclass_Var_Urho3D_Rect = py::class_<Urho3D::Rect>(pyclass_NS__Urho3D, "Rect", "test doc");
// Class RefCount
auto pyclass_Var_Urho3D_RefCount = py::class_<Urho3D::RefCount>(pyclass_NS__Urho3D, "RefCount", "test doc");
// Class RemoteEvent
auto pyclass_Var_Urho3D_RemoteEvent = py::class_<Urho3D::RemoteEvent>(pyclass_NS__Urho3D, "RemoteEvent", "test doc");
// Class RenderPath
auto pyclass_Var_Urho3D_RenderPath = py::class_<Urho3D::RenderPath, Urho3D::RefCounted>(pyclass_NS__Urho3D, "RenderPath", "test doc");
// Class RenderPathCommand
auto pyclass_Var_Urho3D_RenderPathCommand = py::class_<Urho3D::RenderPathCommand>(pyclass_NS__Urho3D, "RenderPathCommand", "test doc");
// Class RenderSurface
auto pyclass_Var_Urho3D_RenderSurface = py::class_<Urho3D::RenderSurface, Urho3D::RefCounted>(pyclass_NS__Urho3D, "RenderSurface", "test doc");
// Class RenderTargetInfo
auto pyclass_Var_Urho3D_RenderTargetInfo = py::class_<Urho3D::RenderTargetInfo>(pyclass_NS__Urho3D, "RenderTargetInfo", "test doc");
// Class Renderer
auto pyclass_Var_Urho3D_Renderer = py::class_<Urho3D::Renderer, Urho3D::Object>(pyclass_NS__Urho3D, "Renderer", "test doc");
// Class Renderer2D
auto pyclass_Var_Urho3D_Renderer2D = py::class_<Urho3D::Renderer2D, Urho3D::Drawable>(pyclass_NS__Urho3D, "Renderer2D", "test doc");
// Class ReplicationState
auto pyclass_Var_Urho3D_ReplicationState = py::class_<Urho3D::ReplicationState>(pyclass_NS__Urho3D, "ReplicationState", "test doc");
// Class Resource
auto pyclass_Var_Urho3D_Resource = py::class_<Urho3D::Resource, Urho3D::Object>(pyclass_NS__Urho3D, "Resource", "test doc");
// Class ResourceCache
auto pyclass_Var_Urho3D_ResourceCache = py::class_<Urho3D::ResourceCache, Urho3D::Object>(pyclass_NS__Urho3D, "ResourceCache", "test doc");
// Class ResourceGroup
auto pyclass_Var_Urho3D_ResourceGroup = py::class_<Urho3D::ResourceGroup>(pyclass_NS__Urho3D, "ResourceGroup", "test doc");
// Class ResourceRef
auto pyclass_Var_Urho3D_ResourceRef = py::class_<Urho3D::ResourceRef>(pyclass_NS__Urho3D, "ResourceRef", "test doc");
// Class ResourceRefList
auto pyclass_Var_Urho3D_ResourceRefList = py::class_<Urho3D::ResourceRefList>(pyclass_NS__Urho3D, "ResourceRefList", "test doc");
// Class ResourceRouter
auto pyclass_Var_Urho3D_ResourceRouter = py::class_<Urho3D::ResourceRouter, Urho3D::Object>(pyclass_NS__Urho3D, "ResourceRouter", "test doc");
// Class ResourceWithMetadata
auto pyclass_Var_Urho3D_ResourceWithMetadata = py::class_<Urho3D::ResourceWithMetadata, Urho3D::Resource>(pyclass_NS__Urho3D, "ResourceWithMetadata", "test doc");
// Class RibbonTrail
auto pyclass_Var_Urho3D_RibbonTrail = py::class_<Urho3D::RibbonTrail, Urho3D::Drawable>(pyclass_NS__Urho3D, "RibbonTrail", "test doc");
// Class RigidBody
auto pyclass_Var_Urho3D_RigidBody = py::class_<Urho3D::RigidBody, Urho3D::Component, btMotionState>(pyclass_NS__Urho3D, "RigidBody", "test doc");
// Class RigidBody2D
auto pyclass_Var_Urho3D_RigidBody2D = py::class_<Urho3D::RigidBody2D, Urho3D::Component>(pyclass_NS__Urho3D, "RigidBody2D", "test doc");
// Class Scene
auto pyclass_Var_Urho3D_Scene = py::class_<Urho3D::Scene, Urho3D::Node>(pyclass_NS__Urho3D, "Scene", "test doc");
// Class ScenePassInfo
auto pyclass_Var_Urho3D_ScenePassInfo = py::class_<Urho3D::ScenePassInfo>(pyclass_NS__Urho3D, "ScenePassInfo", "test doc");
// Class SceneReplicationState
auto pyclass_Var_Urho3D_SceneReplicationState = py::class_<Urho3D::SceneReplicationState, Urho3D::ReplicationState>(pyclass_NS__Urho3D, "SceneReplicationState", "test doc");
// Class SceneResolver
auto pyclass_Var_Urho3D_SceneResolver = py::class_<Urho3D::SceneResolver>(pyclass_NS__Urho3D, "SceneResolver", "test doc");
// Class ScratchBuffer
auto pyclass_Var_Urho3D_ScratchBuffer = py::class_<Urho3D::ScratchBuffer>(pyclass_NS__Urho3D, "ScratchBuffer", "test doc");
// Class Script
auto pyclass_Var_Urho3D_Script = py::class_<Urho3D::Script, Urho3D::Object>(pyclass_NS__Urho3D, "Script", "test doc");
// Class ScriptEventInvoker
auto pyclass_Var_Urho3D_ScriptEventInvoker = py::class_<Urho3D::ScriptEventInvoker, Urho3D::Object>(pyclass_NS__Urho3D, "ScriptEventInvoker", "test doc");
// Class ScriptEventListener
auto pyclass_Var_Urho3D_ScriptEventListener = py::class_<Urho3D::ScriptEventListener>(pyclass_NS__Urho3D, "ScriptEventListener", "test doc");
// Class ScriptFile
auto pyclass_Var_Urho3D_ScriptFile = py::class_<Urho3D::ScriptFile, Urho3D::Resource, Urho3D::ScriptEventListener>(pyclass_NS__Urho3D, "ScriptFile", "test doc");
// Class Serializable
auto pyclass_Var_Urho3D_Serializable = py::class_<Urho3D::Serializable, Urho3D::Object>(pyclass_NS__Urho3D, "Serializable", "test doc");
// Class ScriptInstance
auto pyclass_Var_Urho3D_ScriptInstance = py::class_<Urho3D::ScriptInstance, Urho3D::Component, Urho3D::ScriptEventListener>(pyclass_NS__Urho3D, "ScriptInstance", "test doc");
// Class ScrollBar
auto pyclass_Var_Urho3D_ScrollBar = py::class_<Urho3D::ScrollBar, Urho3D::BorderImage>(pyclass_NS__Urho3D, "ScrollBar", "test doc");
// Class ScrollView
auto pyclass_Var_Urho3D_ScrollView = py::class_<Urho3D::ScrollView, Urho3D::UIElement>(pyclass_NS__Urho3D, "ScrollView", "test doc");
// Class Serializer
auto pyclass_Var_Urho3D_Serializer = py::class_<Urho3D::Serializer>(pyclass_NS__Urho3D, "Serializer", "test doc");
// Class Shader
auto pyclass_Var_Urho3D_Shader = py::class_<Urho3D::Shader, Urho3D::Resource>(pyclass_NS__Urho3D, "Shader", "test doc");
// Class ShaderParameter
auto pyclass_Var_Urho3D_ShaderParameter = py::class_<Urho3D::ShaderParameter>(pyclass_NS__Urho3D, "ShaderParameter", "test doc");
// Class ShaderParameterAnimationInfo
auto pyclass_Var_Urho3D_ShaderParameterAnimationInfo = py::class_<Urho3D::ShaderParameterAnimationInfo, Urho3D::ValueAnimationInfo>(pyclass_NS__Urho3D, "ShaderParameterAnimationInfo", "test doc");
// Class ShaderPrecache
auto pyclass_Var_Urho3D_ShaderPrecache = py::class_<Urho3D::ShaderPrecache, Urho3D::Object>(pyclass_NS__Urho3D, "ShaderPrecache", "test doc");
// Class ShaderProgram
auto pyclass_Var_Urho3D_ShaderProgram = py::class_<Urho3D::ShaderProgram, Urho3D::RefCounted, Urho3D::GPUObject>(pyclass_NS__Urho3D, "ShaderProgram", "test doc");
// Class ShaderVariation
auto pyclass_Var_Urho3D_ShaderVariation = py::class_<Urho3D::ShaderVariation, Urho3D::RefCounted, Urho3D::GPUObject>(pyclass_NS__Urho3D, "ShaderVariation", "test doc");
// Class ShadowBatchQueue
auto pyclass_Var_Urho3D_ShadowBatchQueue = py::class_<Urho3D::ShadowBatchQueue>(pyclass_NS__Urho3D, "ShadowBatchQueue", "test doc");
// Class SimpleNavBuildData
auto pyclass_Var_Urho3D_SimpleNavBuildData = py::class_<Urho3D::SimpleNavBuildData, Urho3D::NavBuildData>(pyclass_NS__Urho3D, "SimpleNavBuildData", "test doc");
// Class Skeleton
auto pyclass_Var_Urho3D_Skeleton = py::class_<Urho3D::Skeleton>(pyclass_NS__Urho3D, "Skeleton", "test doc");
// Class Skybox
auto pyclass_Var_Urho3D_Skybox = py::class_<Urho3D::Skybox, Urho3D::StaticModel>(pyclass_NS__Urho3D, "Skybox", "test doc");
// Class Slider
auto pyclass_Var_Urho3D_Slider = py::class_<Urho3D::Slider, Urho3D::BorderImage>(pyclass_NS__Urho3D, "Slider", "test doc");
// Class SmoothedTransform
auto pyclass_Var_Urho3D_SmoothedTransform = py::class_<Urho3D::SmoothedTransform, Urho3D::Component>(pyclass_NS__Urho3D, "SmoothedTransform", "test doc");
// Class Sound
auto pyclass_Var_Urho3D_Sound = py::class_<Urho3D::Sound, Urho3D::ResourceWithMetadata>(pyclass_NS__Urho3D, "Sound", "test doc");
// Class SoundListener
auto pyclass_Var_Urho3D_SoundListener = py::class_<Urho3D::SoundListener, Urho3D::Component>(pyclass_NS__Urho3D, "SoundListener", "test doc");
// Class SoundSource
auto pyclass_Var_Urho3D_SoundSource = py::class_<Urho3D::SoundSource, Urho3D::Component>(pyclass_NS__Urho3D, "SoundSource", "test doc");
// Class SoundSource3D
auto pyclass_Var_Urho3D_SoundSource3D = py::class_<Urho3D::SoundSource3D, Urho3D::SoundSource>(pyclass_NS__Urho3D, "SoundSource3D", "test doc");
// Class SoundStream
auto pyclass_Var_Urho3D_SoundStream = py::class_<Urho3D::SoundStream, Urho3D::RefCounted>(pyclass_NS__Urho3D, "SoundStream", "test doc");
// Class SourceBatch
auto pyclass_Var_Urho3D_SourceBatch = py::class_<Urho3D::SourceBatch>(pyclass_NS__Urho3D, "SourceBatch", "test doc");
// Class SourceBatch2D
auto pyclass_Var_Urho3D_SourceBatch2D = py::class_<Urho3D::SourceBatch2D>(pyclass_NS__Urho3D, "SourceBatch2D", "test doc");
// Class Sphere
auto pyclass_Var_Urho3D_Sphere = py::class_<Urho3D::Sphere>(pyclass_NS__Urho3D, "Sphere", "test doc");
// Class SphereOctreeQuery
auto pyclass_Var_Urho3D_SphereOctreeQuery = py::class_<Urho3D::SphereOctreeQuery, Urho3D::OctreeQuery>(pyclass_NS__Urho3D, "SphereOctreeQuery", "test doc");
// Class Spline
auto pyclass_Var_Urho3D_Spline = py::class_<Urho3D::Spline>(pyclass_NS__Urho3D, "Spline", "test doc");
// Class SplinePath
auto pyclass_Var_Urho3D_SplinePath = py::class_<Urho3D::SplinePath, Urho3D::Component>(pyclass_NS__Urho3D, "SplinePath", "test doc");
// Class Sprite
auto pyclass_Var_Urho3D_Sprite = py::class_<Urho3D::Sprite, Urho3D::UIElement>(pyclass_NS__Urho3D, "Sprite", "test doc");
// Class Sprite2D
auto pyclass_Var_Urho3D_Sprite2D = py::class_<Urho3D::Sprite2D, Urho3D::Resource>(pyclass_NS__Urho3D, "Sprite2D", "test doc");
// Class SpriteSheet2D
auto pyclass_Var_Urho3D_SpriteSheet2D = py::class_<Urho3D::SpriteSheet2D, Urho3D::Resource>(pyclass_NS__Urho3D, "SpriteSheet2D", "test doc");
// Class StaticModel
auto pyclass_Var_Urho3D_StaticModel = py::class_<Urho3D::StaticModel, Urho3D::Drawable>(pyclass_NS__Urho3D, "StaticModel", "test doc");
// Class StaticModelGeometryData
auto pyclass_Var_Urho3D_StaticModelGeometryData = py::class_<Urho3D::StaticModelGeometryData>(pyclass_NS__Urho3D, "StaticModelGeometryData", "test doc");
// Class StaticModelGroup
auto pyclass_Var_Urho3D_StaticModelGroup = py::class_<Urho3D::StaticModelGroup, Urho3D::StaticModel>(pyclass_NS__Urho3D, "StaticModelGroup", "test doc");
// Class StaticSprite2D
auto pyclass_Var_Urho3D_StaticSprite2D = py::class_<Urho3D::StaticSprite2D, Urho3D::Drawable2D>(pyclass_NS__Urho3D, "StaticSprite2D", "test doc");
// Class StoredLogMessage
auto pyclass_Var_Urho3D_StoredLogMessage = py::class_<Urho3D::StoredLogMessage>(pyclass_NS__Urho3D, "StoredLogMessage", "test doc");
// Class String
auto pyclass_Var_Urho3D_String = py::class_<Urho3D::String>(pyclass_NS__Urho3D, "String", "test doc");
// Class StringHash
auto pyclass_Var_Urho3D_StringHash = py::class_<Urho3D::StringHash>(pyclass_NS__Urho3D, "StringHash", "test doc");
// Class Technique
auto pyclass_Var_Urho3D_Technique = py::class_<Urho3D::Technique, Urho3D::Resource>(pyclass_NS__Urho3D, "Technique", "test doc");
// Class TechniqueEntry
auto pyclass_Var_Urho3D_TechniqueEntry = py::class_<Urho3D::TechniqueEntry>(pyclass_NS__Urho3D, "TechniqueEntry", "test doc");
// Class Terrain
auto pyclass_Var_Urho3D_Terrain = py::class_<Urho3D::Terrain, Urho3D::Component>(pyclass_NS__Urho3D, "Terrain", "test doc");
// Class TerrainPatch
auto pyclass_Var_Urho3D_TerrainPatch = py::class_<Urho3D::TerrainPatch, Urho3D::Drawable>(pyclass_NS__Urho3D, "TerrainPatch", "test doc");
// Class Text
auto pyclass_Var_Urho3D_Text = py::class_<Urho3D::Text, Urho3D::UIElement>(pyclass_NS__Urho3D, "Text", "test doc");
// Class Text3D
auto pyclass_Var_Urho3D_Text3D = py::class_<Urho3D::Text3D, Urho3D::Drawable>(pyclass_NS__Urho3D, "Text3D", "test doc");
// Class Texture
auto pyclass_Var_Urho3D_Texture = py::class_<Urho3D::Texture, Urho3D::ResourceWithMetadata, Urho3D::GPUObject>(pyclass_NS__Urho3D, "Texture", "test doc");
// Class Texture2D
auto pyclass_Var_Urho3D_Texture2D = py::class_<Urho3D::Texture2D, Urho3D::Texture>(pyclass_NS__Urho3D, "Texture2D", "test doc");
// Class Texture2DArray
auto pyclass_Var_Urho3D_Texture2DArray = py::class_<Urho3D::Texture2DArray, Urho3D::Texture>(pyclass_NS__Urho3D, "Texture2DArray", "test doc");
// Class Texture3D
auto pyclass_Var_Urho3D_Texture3D = py::class_<Urho3D::Texture3D, Urho3D::Texture>(pyclass_NS__Urho3D, "Texture3D", "test doc");
// Class TextureCube
auto pyclass_Var_Urho3D_TextureCube = py::class_<Urho3D::TextureCube, Urho3D::Texture>(pyclass_NS__Urho3D, "TextureCube", "test doc");
// Class TextureFrame
auto pyclass_Var_Urho3D_TextureFrame = py::class_<Urho3D::TextureFrame>(pyclass_NS__Urho3D, "TextureFrame", "test doc");
// Class Thread
auto pyclass_Var_Urho3D_Thread = py::class_<Urho3D::Thread>(pyclass_NS__Urho3D, "Thread", "test doc");
// Class Tile2D
auto pyclass_Var_Urho3D_Tile2D = py::class_<Urho3D::Tile2D, Urho3D::RefCounted>(pyclass_NS__Urho3D, "Tile2D", "test doc");
// Class TileMap2D
auto pyclass_Var_Urho3D_TileMap2D = py::class_<Urho3D::TileMap2D, Urho3D::Component>(pyclass_NS__Urho3D, "TileMap2D", "test doc");
// Class TileMapInfo2D
auto pyclass_Var_Urho3D_TileMapInfo2D = py::class_<Urho3D::TileMapInfo2D>(pyclass_NS__Urho3D, "TileMapInfo2D", "test doc");
// Class TileMapLayer2D
auto pyclass_Var_Urho3D_TileMapLayer2D = py::class_<Urho3D::TileMapLayer2D, Urho3D::Component>(pyclass_NS__Urho3D, "TileMapLayer2D", "test doc");
// Class TileMapObject2D
auto pyclass_Var_Urho3D_TileMapObject2D = py::class_<Urho3D::TileMapObject2D, Urho3D::RefCounted>(pyclass_NS__Urho3D, "TileMapObject2D", "test doc");
// Class Time
auto pyclass_Var_Urho3D_Time = py::class_<Urho3D::Time, Urho3D::Object>(pyclass_NS__Urho3D, "Time", "test doc");
// Class Timer
auto pyclass_Var_Urho3D_Timer = py::class_<Urho3D::Timer>(pyclass_NS__Urho3D, "Timer", "test doc");
// Class TmxFile2D
auto pyclass_Var_Urho3D_TmxFile2D = py::class_<Urho3D::TmxFile2D, Urho3D::Resource>(pyclass_NS__Urho3D, "TmxFile2D", "test doc");
// Class TmxLayer2D
auto pyclass_Var_Urho3D_TmxLayer2D = py::class_<Urho3D::TmxLayer2D, Urho3D::RefCounted>(pyclass_NS__Urho3D, "TmxLayer2D", "test doc");
// Class TmxImageLayer2D
auto pyclass_Var_Urho3D_TmxImageLayer2D = py::class_<Urho3D::TmxImageLayer2D, Urho3D::TmxLayer2D>(pyclass_NS__Urho3D, "TmxImageLayer2D", "test doc");
// Class TmxObjectGroup2D
auto pyclass_Var_Urho3D_TmxObjectGroup2D = py::class_<Urho3D::TmxObjectGroup2D, Urho3D::TmxLayer2D>(pyclass_NS__Urho3D, "TmxObjectGroup2D", "test doc");
// Class TmxTileLayer2D
auto pyclass_Var_Urho3D_TmxTileLayer2D = py::class_<Urho3D::TmxTileLayer2D, Urho3D::TmxLayer2D>(pyclass_NS__Urho3D, "TmxTileLayer2D", "test doc");
// Class ToolTip
auto pyclass_Var_Urho3D_ToolTip = py::class_<Urho3D::ToolTip, Urho3D::UIElement>(pyclass_NS__Urho3D, "ToolTip", "test doc");
// Class TouchState
auto pyclass_Var_Urho3D_TouchState = py::class_<Urho3D::TouchState>(pyclass_NS__Urho3D, "TouchState", "test doc");
// Class TrailPoint
auto pyclass_Var_Urho3D_TrailPoint = py::class_<Urho3D::TrailPoint>(pyclass_NS__Urho3D, "TrailPoint", "test doc");
// Class TriangleMeshData
auto pyclass_Var_Urho3D_TriangleMeshData = py::class_<Urho3D::TriangleMeshData, Urho3D::CollisionGeometryData>(pyclass_NS__Urho3D, "TriangleMeshData", "test doc");
// Class TypeInfo
auto pyclass_Var_Urho3D_TypeInfo = py::class_<Urho3D::TypeInfo>(pyclass_NS__Urho3D, "TypeInfo", "test doc");
// Class UI
auto pyclass_Var_Urho3D_UI = py::class_<Urho3D::UI, Urho3D::Object>(pyclass_NS__Urho3D, "UI", "test doc");
// Class DragData
auto pyclass_Var_Urho3D_UI_DragData = py::class_<Urho3D::UI::DragData>(pyclass_Var_Urho3D_UI, "DragData", "test doc");
// Class UIBatch
auto pyclass_Var_Urho3D_UIBatch = py::class_<Urho3D::UIBatch>(pyclass_NS__Urho3D, "UIBatch", "test doc");
// Class UIElement
auto pyclass_Var_Urho3D_UIElement = py::class_<Urho3D::UIElement, Urho3D::Animatable>(pyclass_NS__Urho3D, "UIElement", "test doc");
// Class UnknownComponent
auto pyclass_Var_Urho3D_UnknownComponent = py::class_<Urho3D::UnknownComponent, Urho3D::Component>(pyclass_NS__Urho3D, "UnknownComponent", "test doc");
// Class VAnimEventFrame
auto pyclass_Var_Urho3D_VAnimEventFrame = py::class_<Urho3D::VAnimEventFrame>(pyclass_NS__Urho3D, "VAnimEventFrame", "test doc");
// Class VAnimKeyFrame
auto pyclass_Var_Urho3D_VAnimKeyFrame = py::class_<Urho3D::VAnimKeyFrame>(pyclass_NS__Urho3D, "VAnimKeyFrame", "test doc");
// Class ValueAnimation
auto pyclass_Var_Urho3D_ValueAnimation = py::class_<Urho3D::ValueAnimation, Urho3D::Resource>(pyclass_NS__Urho3D, "ValueAnimation", "test doc");
// Class ValueAnimationInfo
auto pyclass_Var_Urho3D_ValueAnimationInfo = py::class_<Urho3D::ValueAnimationInfo, Urho3D::RefCounted>(pyclass_NS__Urho3D, "ValueAnimationInfo", "test doc");
// Class Variant
auto pyclass_Var_Urho3D_Variant = py::class_<Urho3D::Variant>(pyclass_NS__Urho3D, "Variant", "test doc");
// Class VariantValue
auto pyclass_Var_Urho3D_VariantValue = py::class_<Urho3D::VariantValue>(pyclass_NS__Urho3D, "VariantValue", "test doc");
// Class Vector2
auto pyclass_Var_Urho3D_Vector2 = py::class_<Urho3D::Vector2>(pyclass_NS__Urho3D, "Vector2", "test doc");
// Class Vector3
auto pyclass_Var_Urho3D_Vector3 = py::class_<Urho3D::Vector3>(pyclass_NS__Urho3D, "Vector3", "test doc");
// Class Vector4
auto pyclass_Var_Urho3D_Vector4 = py::class_<Urho3D::Vector4>(pyclass_NS__Urho3D, "Vector4", "test doc");
// Class VectorBase
auto pyclass_Var_Urho3D_VectorBase = py::class_<Urho3D::VectorBase>(pyclass_NS__Urho3D, "VectorBase", "test doc");
// Class VectorBuffer
auto pyclass_Var_Urho3D_VectorBuffer = py::class_<Urho3D::VectorBuffer, Urho3D::AbstractFile>(pyclass_NS__Urho3D, "VectorBuffer", "test doc");
// Class Vertex2D
auto pyclass_Var_Urho3D_Vertex2D = py::class_<Urho3D::Vertex2D>(pyclass_NS__Urho3D, "Vertex2D", "test doc");
// Class VertexBuffer
auto pyclass_Var_Urho3D_VertexBuffer = py::class_<Urho3D::VertexBuffer, Urho3D::Object, Urho3D::GPUObject>(pyclass_NS__Urho3D, "VertexBuffer", "test doc");
// Class VertexBufferDesc
auto pyclass_Var_Urho3D_VertexBufferDesc = py::class_<Urho3D::VertexBufferDesc>(pyclass_NS__Urho3D, "VertexBufferDesc", "test doc");
// Class VertexBufferMorph
auto pyclass_Var_Urho3D_VertexBufferMorph = py::class_<Urho3D::VertexBufferMorph>(pyclass_NS__Urho3D, "VertexBufferMorph", "test doc");
// Class VertexElement
auto pyclass_Var_Urho3D_VertexElement = py::class_<Urho3D::VertexElement>(pyclass_NS__Urho3D, "VertexElement", "test doc");
// Class View
auto pyclass_Var_Urho3D_View = py::class_<Urho3D::View, Urho3D::Object>(pyclass_NS__Urho3D, "View", "test doc");
// Class Window
auto pyclass_Var_Urho3D_Window = py::class_<Urho3D::Window, Urho3D::BorderImage>(pyclass_NS__Urho3D, "Window", "test doc");
// Class View3D
auto pyclass_Var_Urho3D_View3D = py::class_<Urho3D::View3D, Urho3D::Window>(pyclass_NS__Urho3D, "View3D", "test doc");
// Class ViewBatchInfo2D
auto pyclass_Var_Urho3D_ViewBatchInfo2D = py::class_<Urho3D::ViewBatchInfo2D>(pyclass_NS__Urho3D, "ViewBatchInfo2D", "test doc");
// Class Viewport
auto pyclass_Var_Urho3D_Viewport = py::class_<Urho3D::Viewport, Urho3D::Object>(pyclass_NS__Urho3D, "Viewport", "test doc");
// Class WString
auto pyclass_Var_Urho3D_WString = py::class_<Urho3D::WString>(pyclass_NS__Urho3D, "WString", "test doc");
// Class WorkItem
auto pyclass_Var_Urho3D_WorkItem = py::class_<Urho3D::WorkItem, Urho3D::RefCounted>(pyclass_NS__Urho3D, "WorkItem", "test doc");
// Class WorkQueue
auto pyclass_Var_Urho3D_WorkQueue = py::class_<Urho3D::WorkQueue, Urho3D::Object>(pyclass_NS__Urho3D, "WorkQueue", "test doc");
// Class XMLElement
auto pyclass_Var_Urho3D_XMLElement = py::class_<Urho3D::XMLElement>(pyclass_NS__Urho3D, "XMLElement", "test doc");
// Class XMLFile
auto pyclass_Var_Urho3D_XMLFile = py::class_<Urho3D::XMLFile, Urho3D::Resource>(pyclass_NS__Urho3D, "XMLFile", "test doc");
// Class XPathQuery
auto pyclass_Var_Urho3D_XPathQuery = py::class_<Urho3D::XPathQuery>(pyclass_NS__Urho3D, "XPathQuery", "test doc");
// Class XPathResultSet
auto pyclass_Var_Urho3D_XPathResultSet = py::class_<Urho3D::XPathResultSet>(pyclass_NS__Urho3D, "XPathResultSet", "test doc");
// Class Zone
auto pyclass_Var_Urho3D_Zone = py::class_<Urho3D::Zone, Urho3D::Drawable>(pyclass_NS__Urho3D, "Zone", "test doc");

  // Register class details

// Class AbstractFile
  pyclass_Var_Urho3D_AbstractFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AbstractFile

// Class AllContentOctreeQuery
  pyclass_Var_Urho3D_AllContentOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AllContentOctreeQuery

// Class AllocatorBlock
  pyclass_Var_Urho3D_AllocatorBlock
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("nodeSize_", &Urho3D::AllocatorBlock::nodeSize_, "todo: var docstring")
  .def_readwrite("capacity_", &Urho3D::AllocatorBlock::capacity_, "todo: var docstring")
  .def_readwrite("free_", &Urho3D::AllocatorBlock::free_, "todo: var docstring")
  .def_readwrite("next_", &Urho3D::AllocatorBlock::next_, "todo: var docstring")
; // End Class AllocatorBlock

// Class AllocatorNode
  pyclass_Var_Urho3D_AllocatorNode
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("next_", &Urho3D::AllocatorNode::next_, "todo: var docstring")
; // End Class AllocatorNode

// Class Animatable
  pyclass_Var_Urho3D_Animatable
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Animatable

// Class AnimatedModel
  pyclass_Var_Urho3D_AnimatedModel
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AnimatedModel

// Class AnimatedSprite2D
  pyclass_Var_Urho3D_AnimatedSprite2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AnimatedSprite2D

// Class Animation
  pyclass_Var_Urho3D_Animation
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Animation

// Class AnimationControl
  pyclass_Var_Urho3D_AnimationControl
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::AnimationControl::name_, "todo: var docstring")
  .def_readwrite("hash_", &Urho3D::AnimationControl::hash_, "todo: var docstring")
  .def_readwrite("speed_", &Urho3D::AnimationControl::speed_, "todo: var docstring")
  .def_readwrite("targetWeight_", &Urho3D::AnimationControl::targetWeight_, "todo: var docstring")
  .def_readwrite("fadeTime_", &Urho3D::AnimationControl::fadeTime_, "todo: var docstring")
  .def_readwrite("autoFadeTime_", &Urho3D::AnimationControl::autoFadeTime_, "todo: var docstring")
  .def_readwrite("setTimeTtl_", &Urho3D::AnimationControl::setTimeTtl_, "todo: var docstring")
  .def_readwrite("setWeightTtl_", &Urho3D::AnimationControl::setWeightTtl_, "todo: var docstring")
  .def_readwrite("setTime_", &Urho3D::AnimationControl::setTime_, "todo: var docstring")
  .def_readwrite("setWeight_", &Urho3D::AnimationControl::setWeight_, "todo: var docstring")
  .def_readwrite("setTimeRev_", &Urho3D::AnimationControl::setTimeRev_, "todo: var docstring")
  .def_readwrite("setWeightRev_", &Urho3D::AnimationControl::setWeightRev_, "todo: var docstring")
  .def_readwrite("removeOnCompletion_", &Urho3D::AnimationControl::removeOnCompletion_, "todo: var docstring")
; // End Class AnimationControl

// Class AnimationController
  pyclass_Var_Urho3D_AnimationController
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AnimationController

// Class AnimationKeyFrame
  pyclass_Var_Urho3D_AnimationKeyFrame
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("time_", &Urho3D::AnimationKeyFrame::time_, "todo: var docstring")
  .def_readwrite("position_", &Urho3D::AnimationKeyFrame::position_, "todo: var docstring")
  .def_readwrite("rotation_", &Urho3D::AnimationKeyFrame::rotation_, "todo: var docstring")
  .def_readwrite("scale_", &Urho3D::AnimationKeyFrame::scale_, "todo: var docstring")
; // End Class AnimationKeyFrame

// Class AnimationSet2D
  pyclass_Var_Urho3D_AnimationSet2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AnimationSet2D

// Class AnimationState
  pyclass_Var_Urho3D_AnimationState
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AnimationState

// Class AnimationStateTrack
  pyclass_Var_Urho3D_AnimationStateTrack
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("track_", &Urho3D::AnimationStateTrack::track_, "todo: var docstring")
  .def_readwrite("bone_", &Urho3D::AnimationStateTrack::bone_, "todo: var docstring")
  .def_readwrite("node_", &Urho3D::AnimationStateTrack::node_, "todo: var docstring")
  .def_readwrite("weight_", &Urho3D::AnimationStateTrack::weight_, "todo: var docstring")
  .def_readwrite("keyFrame_", &Urho3D::AnimationStateTrack::keyFrame_, "todo: var docstring")
; // End Class AnimationStateTrack

// Class AnimationTrack
  pyclass_Var_Urho3D_AnimationTrack
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::AnimationTrack::name_, "todo: var docstring")
  .def_readwrite("nameHash_", &Urho3D::AnimationTrack::nameHash_, "todo: var docstring")
  .def_readwrite("channelMask_", &Urho3D::AnimationTrack::channelMask_, "todo: var docstring")
  .def_readwrite("keyFrames_", &Urho3D::AnimationTrack::keyFrames_, "todo: var docstring")
; // End Class AnimationTrack

// Class AnimationTriggerPoint
  pyclass_Var_Urho3D_AnimationTriggerPoint
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("time_", &Urho3D::AnimationTriggerPoint::time_, "todo: var docstring")
  .def_readwrite("data_", &Urho3D::AnimationTriggerPoint::data_, "todo: var docstring")
; // End Class AnimationTriggerPoint

// Class Application
  pyclass_Var_Urho3D_Application
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Application

// Class AreaAllocator
  pyclass_Var_Urho3D_AreaAllocator
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AreaAllocator

// Class AsyncProgress
  pyclass_Var_Urho3D_AsyncProgress
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("file_", &Urho3D::AsyncProgress::file_, "todo: var docstring")
  .def_readwrite("xmlFile_", &Urho3D::AsyncProgress::xmlFile_, "todo: var docstring")
  .def_readwrite("jsonFile_", &Urho3D::AsyncProgress::jsonFile_, "todo: var docstring")
  .def_readwrite("xmlElement_", &Urho3D::AsyncProgress::xmlElement_, "todo: var docstring")
  .def_readwrite("jsonIndex_", &Urho3D::AsyncProgress::jsonIndex_, "todo: var docstring")
  .def_readwrite("mode_", &Urho3D::AsyncProgress::mode_, "todo: var docstring")
  .def_readwrite("resources_", &Urho3D::AsyncProgress::resources_, "todo: var docstring")
  .def_readwrite("loadedResources_", &Urho3D::AsyncProgress::loadedResources_, "todo: var docstring")
  .def_readwrite("totalResources_", &Urho3D::AsyncProgress::totalResources_, "todo: var docstring")
  .def_readwrite("loadedNodes_", &Urho3D::AsyncProgress::loadedNodes_, "todo: var docstring")
  .def_readwrite("totalNodes_", &Urho3D::AsyncProgress::totalNodes_, "todo: var docstring")
; // End Class AsyncProgress

// Class AttributeAccessor
  pyclass_Var_Urho3D_AttributeAccessor
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeAccessor

// Class AttributeAnimationInfo
  pyclass_Var_Urho3D_AttributeAnimationInfo
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeAnimationInfo

// Class AttributeInfo
  pyclass_Var_Urho3D_AttributeInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("type_", &Urho3D::AttributeInfo::type_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::AttributeInfo::name_, "todo: var docstring")
  .def_readwrite("offset_", &Urho3D::AttributeInfo::offset_, "todo: var docstring")
//  .def_readwrite("enumNames_", &Urho3D::AttributeInfo::enumNames_, "todo: var docstring")
//  .def_readwrite("variantStructureElementNames_", &Urho3D::AttributeInfo::variantStructureElementNames_, "todo: var docstring")
  .def_readwrite("accessor_", &Urho3D::AttributeInfo::accessor_, "todo: var docstring")
  .def_readwrite("defaultValue_", &Urho3D::AttributeInfo::defaultValue_, "todo: var docstring")
  .def_readwrite("mode_", &Urho3D::AttributeInfo::mode_, "todo: var docstring")
  .def_readwrite("ptr_", &Urho3D::AttributeInfo::ptr_, "todo: var docstring")
; // End Class AttributeInfo

// Class AttributeTrait
  pyclass_Var_Urho3D_AttributeTrait_bool
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeTrait

// Class AttributeTrait
  pyclass_Var_Urho3D_AttributeTrait_float
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeTrait

// Class AttributeTrait
  pyclass_Var_Urho3D_AttributeTrait_int
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeTrait

// Class AttributeTrait
  pyclass_Var_Urho3D_AttributeTrait_unsigned_int
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AttributeTrait

// Class Audio
  pyclass_Var_Urho3D_Audio
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readonly_static("SAMPLE_SIZE_MUL", &Urho3D::Audio::SAMPLE_SIZE_MUL, "todo: var docstring")
; // End Class Audio

// Class AutoProfileBlock
  pyclass_Var_Urho3D_AutoProfileBlock
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class AutoProfileBlock

// Class BackgroundLoadItem
  pyclass_Var_Urho3D_BackgroundLoadItem
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("resource_", &Urho3D::BackgroundLoadItem::resource_, "todo: var docstring")
  .def_readwrite("dependencies_", &Urho3D::BackgroundLoadItem::dependencies_, "todo: var docstring")
  .def_readwrite("dependents_", &Urho3D::BackgroundLoadItem::dependents_, "todo: var docstring")
  .def_readwrite("sendEventOnFailure_", &Urho3D::BackgroundLoadItem::sendEventOnFailure_, "todo: var docstring")
; // End Class BackgroundLoadItem

// Class BackgroundLoader
  pyclass_Var_Urho3D_BackgroundLoader
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class BackgroundLoader

// Class Batch
  pyclass_Var_Urho3D_Batch
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("sortKey_", &Urho3D::Batch::sortKey_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::Batch::distance_, "todo: var docstring")
  .def_readwrite("renderOrder_", &Urho3D::Batch::renderOrder_, "todo: var docstring")
  .def_readwrite("lightMask_", &Urho3D::Batch::lightMask_, "todo: var docstring")
  .def_readwrite("isBase_", &Urho3D::Batch::isBase_, "todo: var docstring")
  .def_readwrite("geometry_", &Urho3D::Batch::geometry_, "todo: var docstring")
  .def_readwrite("material_", &Urho3D::Batch::material_, "todo: var docstring")
  .def_readwrite("worldTransform_", &Urho3D::Batch::worldTransform_, "todo: var docstring")
  .def_readwrite("numWorldTransforms_", &Urho3D::Batch::numWorldTransforms_, "todo: var docstring")
  .def_readwrite("instancingData_", &Urho3D::Batch::instancingData_, "todo: var docstring")
  .def_readwrite("zone_", &Urho3D::Batch::zone_, "todo: var docstring")
  .def_readwrite("lightQueue_", &Urho3D::Batch::lightQueue_, "todo: var docstring")
  .def_readwrite("pass_", &Urho3D::Batch::pass_, "todo: var docstring")
  .def_readwrite("vertexShader_", &Urho3D::Batch::vertexShader_, "todo: var docstring")
  .def_readwrite("pixelShader_", &Urho3D::Batch::pixelShader_, "todo: var docstring")
  .def_readwrite("geometryType_", &Urho3D::Batch::geometryType_, "todo: var docstring")
; // End Class Batch

// Class BatchGroup
  pyclass_Var_Urho3D_BatchGroup
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("instances_", &Urho3D::BatchGroup::instances_, "todo: var docstring")
  .def_readwrite("startIndex_", &Urho3D::BatchGroup::startIndex_, "todo: var docstring")
; // End Class BatchGroup

// Class BatchGroupKey
  pyclass_Var_Urho3D_BatchGroupKey
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::BatchGroupKey (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::BatchGroupKey (), "todo: docstring")
  // Variables
  .def_readwrite("zone_", &Urho3D::BatchGroupKey::zone_, "todo: var docstring")
  .def_readwrite("lightQueue_", &Urho3D::BatchGroupKey::lightQueue_, "todo: var docstring")
  .def_readwrite("pass_", &Urho3D::BatchGroupKey::pass_, "todo: var docstring")
  .def_readwrite("material_", &Urho3D::BatchGroupKey::material_, "todo: var docstring")
  .def_readwrite("geometry_", &Urho3D::BatchGroupKey::geometry_, "todo: var docstring")
  .def_readwrite("renderOrder_", &Urho3D::BatchGroupKey::renderOrder_, "todo: var docstring")
; // End Class BatchGroupKey

// Class BatchQueue
  pyclass_Var_Urho3D_BatchQueue
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("batchGroups_", &Urho3D::BatchQueue::batchGroups_, "todo: var docstring")
  .def_readwrite("shaderRemapping_", &Urho3D::BatchQueue::shaderRemapping_, "todo: var docstring")
  .def_readwrite("materialRemapping_", &Urho3D::BatchQueue::materialRemapping_, "todo: var docstring")
  .def_readwrite("geometryRemapping_", &Urho3D::BatchQueue::geometryRemapping_, "todo: var docstring")
  .def_readwrite("batches_", &Urho3D::BatchQueue::batches_, "todo: var docstring")
  .def_readwrite("sortedBatches_", &Urho3D::BatchQueue::sortedBatches_, "todo: var docstring")
  .def_readwrite("sortedBatchGroups_", &Urho3D::BatchQueue::sortedBatchGroups_, "todo: var docstring")
  .def_readwrite("maxSortedInstances_", &Urho3D::BatchQueue::maxSortedInstances_, "todo: var docstring")
  .def_readwrite("hasExtraDefines_", &Urho3D::BatchQueue::hasExtraDefines_, "todo: var docstring")
  .def_readwrite("vsExtraDefines_", &Urho3D::BatchQueue::vsExtraDefines_, "todo: var docstring")
  .def_readwrite("psExtraDefines_", &Urho3D::BatchQueue::psExtraDefines_, "todo: var docstring")
  .def_readwrite("vsExtraDefinesHash_", &Urho3D::BatchQueue::vsExtraDefinesHash_, "todo: var docstring")
  .def_readwrite("psExtraDefinesHash_", &Urho3D::BatchQueue::psExtraDefinesHash_, "todo: var docstring")
; // End Class BatchQueue

// Class BiasParameters
  pyclass_Var_Urho3D_BiasParameters
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("constantBias_", &Urho3D::BiasParameters::constantBias_, "todo: var docstring")
  .def_readwrite("slopeScaledBias_", &Urho3D::BiasParameters::slopeScaledBias_, "todo: var docstring")
  .def_readwrite("normalOffset_", &Urho3D::BiasParameters::normalOffset_, "todo: var docstring")
; // End Class BiasParameters

// Class Billboard
  pyclass_Var_Urho3D_Billboard
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::Billboard::position_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::Billboard::size_, "todo: var docstring")
  .def_readwrite("uv_", &Urho3D::Billboard::uv_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::Billboard::color_, "todo: var docstring")
  .def_readwrite("rotation_", &Urho3D::Billboard::rotation_, "todo: var docstring")
  .def_readwrite("direction_", &Urho3D::Billboard::direction_, "todo: var docstring")
  .def_readwrite("enabled_", &Urho3D::Billboard::enabled_, "todo: var docstring")
  .def_readwrite("sortDistance_", &Urho3D::Billboard::sortDistance_, "todo: var docstring")
  .def_readwrite("screenScaleFactor_", &Urho3D::Billboard::screenScaleFactor_, "todo: var docstring")
; // End Class Billboard

// Class BillboardSet
  pyclass_Var_Urho3D_BillboardSet
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class BillboardSet

// Class Bone
  pyclass_Var_Urho3D_Bone
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::Bone::name_, "todo: var docstring")
  .def_readwrite("nameHash_", &Urho3D::Bone::nameHash_, "todo: var docstring")
  .def_readwrite("parentIndex_", &Urho3D::Bone::parentIndex_, "todo: var docstring")
  .def_readwrite("initialPosition_", &Urho3D::Bone::initialPosition_, "todo: var docstring")
  .def_readwrite("initialRotation_", &Urho3D::Bone::initialRotation_, "todo: var docstring")
  .def_readwrite("initialScale_", &Urho3D::Bone::initialScale_, "todo: var docstring")
  .def_readwrite("offsetMatrix_", &Urho3D::Bone::offsetMatrix_, "todo: var docstring")
  .def_readwrite("animated_", &Urho3D::Bone::animated_, "todo: var docstring")
  .def_readwrite("collisionMask_", &Urho3D::Bone::collisionMask_, "todo: var docstring")
  .def_readwrite("radius_", &Urho3D::Bone::radius_, "todo: var docstring")
  .def_readwrite("boundingBox_", &Urho3D::Bone::boundingBox_, "todo: var docstring")
  .def_readwrite("node_", &Urho3D::Bone::node_, "todo: var docstring")
; // End Class Bone

// Class BorderImage
  pyclass_Var_Urho3D_BorderImage
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class BorderImage

// Class BoundingBox
  pyclass_Var_Urho3D_BoundingBox
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::BoundingBox (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::BoundingBox (), "todo: docstring")
  // Variables
  .def_readwrite("min_", &Urho3D::BoundingBox::min_, "todo: var docstring")
  .def_readwrite("dummyMin_", &Urho3D::BoundingBox::dummyMin_, "todo: var docstring")
  .def_readwrite("max_", &Urho3D::BoundingBox::max_, "todo: var docstring")
  .def_readwrite("dummyMax_", &Urho3D::BoundingBox::dummyMax_, "todo: var docstring")
; // End Class BoundingBox

// Class BoxOctreeQuery
  pyclass_Var_Urho3D_BoxOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("box_", &Urho3D::BoxOctreeQuery::box_, "todo: var docstring")
; // End Class BoxOctreeQuery

// Class Button
  pyclass_Var_Urho3D_Button
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Button

// Class CScriptArray
//  pyclass_Var_Urho3D_CScriptArray
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
//      .def(py::self == Urho3D::CScriptArray (), "todo: docstring")
  // Variables
; // End Class CScriptArray

// Class CScriptDictionary
//  pyclass_Var_Urho3D_CScriptDictionary
  // Constructors
  // Methods
  // Operators
// OP operator[] len 1
//  .def("__getitem__",[]( Urho3D::CScriptDictionary& arg0, const Urho3D::String & arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
//  .def("__getitem__",[](const Urho3D::CScriptDictionary& arg0, const Urho3D::String & arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
  // Variables
; // End Class CScriptDictionary

// Class RefCounted
  pyclass_Var_Urho3D_RefCounted
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RefCounted

// Class BufferedSoundStream
  pyclass_Var_Urho3D_BufferedSoundStream
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class BufferedSoundStream

// Class CScriptDictValue
  pyclass_Var_Urho3D_CScriptDictValue
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CScriptDictValue

// Class CIterator
//  pyclass_Var_Urho3D_CScriptDictionary_CIterator
  // Constructors
  // Methods
  // Operators
// OP operator* len 0
// implement operator* for []
// OP operator== len 1
//      .def(py::self == Urho3D::CScriptDictionary::CIterator (), "todo: docstring")
// OP operator!= len 1
//      .def(py::self != Urho3D::CScriptDictionary::CIterator (), "todo: docstring")
  // Variables
; // End Class CIterator

// Class Camera
  pyclass_Var_Urho3D_Camera
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Camera

// Class CascadeParameters
  pyclass_Var_Urho3D_CascadeParameters
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::CascadeParameters::splits_ TODO: def_property with lambdas for it
  .def_readwrite("fadeStart_", &Urho3D::CascadeParameters::fadeStart_, "todo: var docstring")
  .def_readwrite("biasAutoAdjust_", &Urho3D::CascadeParameters::biasAutoAdjust_, "todo: var docstring")
; // End Class CascadeParameters

// Class CharLocation
  pyclass_Var_Urho3D_CharLocation
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::CharLocation::position_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::CharLocation::size_, "todo: var docstring")
; // End Class CharLocation

// Class Object
  pyclass_Var_Urho3D_Object
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Object

// Class CheckBox
  pyclass_Var_Urho3D_CheckBox
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CheckBox

// Class Component
  pyclass_Var_Urho3D_Component
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Component

// Class CollisionBox2D
  pyclass_Var_Urho3D_CollisionBox2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionBox2D

// Class CollisionChain2D
  pyclass_Var_Urho3D_CollisionChain2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionChain2D

// Class CollisionCircle2D
  pyclass_Var_Urho3D_CollisionCircle2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionCircle2D

// Class CollisionGeometryData
  pyclass_Var_Urho3D_CollisionGeometryData
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionGeometryData

// Class CollisionShape
  pyclass_Var_Urho3D_CollisionShape
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionShape

// Class CollisionShape2D
  pyclass_Var_Urho3D_CollisionShape2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionShape2D

// Class CollisionEdge2D
  pyclass_Var_Urho3D_CollisionEdge2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionEdge2D

// Class CollisionPolygon2D
  pyclass_Var_Urho3D_CollisionPolygon2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CollisionPolygon2D

// Class Color
  pyclass_Var_Urho3D_Color
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Color (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Color (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Color (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Color (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::Color (), "todo: docstring")
  // Variables
  .def_readwrite("r_", &Urho3D::Color::r_, "todo: var docstring")
  .def_readwrite("g_", &Urho3D::Color::g_, "todo: var docstring")
  .def_readwrite("b_", &Urho3D::Color::b_, "todo: var docstring")
  .def_readwrite("a_", &Urho3D::Color::a_, "todo: var docstring")
  .def_readonly_static("WHITE", &Urho3D::Color::WHITE, "todo: var docstring")
  .def_readonly_static("GRAY", &Urho3D::Color::GRAY, "todo: var docstring")
  .def_readonly_static("BLACK", &Urho3D::Color::BLACK, "todo: var docstring")
  .def_readonly_static("RED", &Urho3D::Color::RED, "todo: var docstring")
  .def_readonly_static("GREEN", &Urho3D::Color::GREEN, "todo: var docstring")
  .def_readonly_static("BLUE", &Urho3D::Color::BLUE, "todo: var docstring")
  .def_readonly_static("CYAN", &Urho3D::Color::CYAN, "todo: var docstring")
  .def_readonly_static("MAGENTA", &Urho3D::Color::MAGENTA, "todo: var docstring")
  .def_readonly_static("YELLOW", &Urho3D::Color::YELLOW, "todo: var docstring")
  .def_readonly_static("TRANSPARENT", &Urho3D::Color::TRANSPARENT, "todo: var docstring")
; // End Class Color

// Class ColorFrame
  pyclass_Var_Urho3D_ColorFrame
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("color_", &Urho3D::ColorFrame::color_, "todo: var docstring")
  .def_readwrite("time_", &Urho3D::ColorFrame::time_, "todo: var docstring")
; // End Class ColorFrame

// Class ComponentReplicationState
  pyclass_Var_Urho3D_ComponentReplicationState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("nodeState_", &Urho3D::ComponentReplicationState::nodeState_, "todo: var docstring")
  .def_readwrite("component_", &Urho3D::ComponentReplicationState::component_, "todo: var docstring")
  .def_readwrite("dirtyAttributes_", &Urho3D::ComponentReplicationState::dirtyAttributes_, "todo: var docstring")
; // End Class ComponentReplicationState

// Class CompressedLevel
  pyclass_Var_Urho3D_CompressedLevel
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("data_", &Urho3D::CompressedLevel::data_, "todo: var docstring")
  .def_readwrite("format_", &Urho3D::CompressedLevel::format_, "todo: var docstring")
  .def_readwrite("width_", &Urho3D::CompressedLevel::width_, "todo: var docstring")
  .def_readwrite("height_", &Urho3D::CompressedLevel::height_, "todo: var docstring")
  .def_readwrite("depth_", &Urho3D::CompressedLevel::depth_, "todo: var docstring")
  .def_readwrite("blockSize_", &Urho3D::CompressedLevel::blockSize_, "todo: var docstring")
  .def_readwrite("dataSize_", &Urho3D::CompressedLevel::dataSize_, "todo: var docstring")
  .def_readwrite("rowSize_", &Urho3D::CompressedLevel::rowSize_, "todo: var docstring")
  .def_readwrite("rows_", &Urho3D::CompressedLevel::rows_, "todo: var docstring")
; // End Class CompressedLevel

// Class Condition
  pyclass_Var_Urho3D_Condition
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Condition

// Class Connection
  pyclass_Var_Urho3D_Connection
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("controls_", &Urho3D::Connection::controls_, "todo: var docstring")
  .def_readwrite("timeStamp_", &Urho3D::Connection::timeStamp_, "todo: var docstring")
  .def_readwrite("identity_", &Urho3D::Connection::identity_, "todo: var docstring")
; // End Class Connection

// Class Console
  pyclass_Var_Urho3D_Console
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Console

// Class ConstantBuffer
  pyclass_Var_Urho3D_ConstantBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstantBuffer

// Class Constraint
  pyclass_Var_Urho3D_Constraint
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Constraint

// Class Constraint2D
  pyclass_Var_Urho3D_Constraint2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Constraint2D

// Class ConstraintDistance2D
  pyclass_Var_Urho3D_ConstraintDistance2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintDistance2D

// Class ConstraintFriction2D
  pyclass_Var_Urho3D_ConstraintFriction2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintFriction2D

// Class ConstraintGear2D
  pyclass_Var_Urho3D_ConstraintGear2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintGear2D

// Class ConstraintMotor2D
  pyclass_Var_Urho3D_ConstraintMotor2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintMotor2D

// Class ConstraintMouse2D
  pyclass_Var_Urho3D_ConstraintMouse2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintMouse2D

// Class ConstraintPrismatic2D
  pyclass_Var_Urho3D_ConstraintPrismatic2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintPrismatic2D

// Class ConstraintPulley2D
  pyclass_Var_Urho3D_ConstraintPulley2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintPulley2D

// Class ConstraintRevolute2D
  pyclass_Var_Urho3D_ConstraintRevolute2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintRevolute2D

// Class ConstraintRope2D
  pyclass_Var_Urho3D_ConstraintRope2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintRope2D

// Class ConstraintWeld2D
  pyclass_Var_Urho3D_ConstraintWeld2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintWeld2D

// Class ConstraintWheel2D
  pyclass_Var_Urho3D_ConstraintWheel2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ConstraintWheel2D

// Class Context
  pyclass_Var_Urho3D_Context
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Context

// Class Controls
  pyclass_Var_Urho3D_Controls
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("buttons_", &Urho3D::Controls::buttons_, "todo: var docstring")
  .def_readwrite("yaw_", &Urho3D::Controls::yaw_, "todo: var docstring")
  .def_readwrite("pitch_", &Urho3D::Controls::pitch_, "todo: var docstring")
  .def_readwrite("extraData_", &Urho3D::Controls::extraData_, "todo: var docstring")
; // End Class Controls

// Class ConvexData
  pyclass_Var_Urho3D_ConvexData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("vertexData_", &Urho3D::ConvexData::vertexData_, "todo: var docstring")
  .def_readwrite("vertexCount_", &Urho3D::ConvexData::vertexCount_, "todo: var docstring")
  .def_readwrite("indexData_", &Urho3D::ConvexData::indexData_, "todo: var docstring")
  .def_readwrite("indexCount_", &Urho3D::ConvexData::indexCount_, "todo: var docstring")
; // End Class ConvexData

// Class CrowdAgent
  pyclass_Var_Urho3D_CrowdAgent
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CrowdAgent

// Class CrowdManager
  pyclass_Var_Urho3D_CrowdManager
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CrowdManager

// Class CrowdObstacleAvoidanceParams
  pyclass_Var_Urho3D_CrowdObstacleAvoidanceParams
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("velBias", &Urho3D::CrowdObstacleAvoidanceParams::velBias, "todo: var docstring")
  .def_readwrite("weightDesVel", &Urho3D::CrowdObstacleAvoidanceParams::weightDesVel, "todo: var docstring")
  .def_readwrite("weightCurVel", &Urho3D::CrowdObstacleAvoidanceParams::weightCurVel, "todo: var docstring")
  .def_readwrite("weightSide", &Urho3D::CrowdObstacleAvoidanceParams::weightSide, "todo: var docstring")
  .def_readwrite("weightToi", &Urho3D::CrowdObstacleAvoidanceParams::weightToi, "todo: var docstring")
  .def_readwrite("horizTime", &Urho3D::CrowdObstacleAvoidanceParams::horizTime, "todo: var docstring")
  .def_readwrite("gridSize", &Urho3D::CrowdObstacleAvoidanceParams::gridSize, "todo: var docstring")
  .def_readwrite("adaptiveDivs", &Urho3D::CrowdObstacleAvoidanceParams::adaptiveDivs, "todo: var docstring")
  .def_readwrite("adaptiveRings", &Urho3D::CrowdObstacleAvoidanceParams::adaptiveRings, "todo: var docstring")
  .def_readwrite("adaptiveDepth", &Urho3D::CrowdObstacleAvoidanceParams::adaptiveDepth, "todo: var docstring")
; // End Class CrowdObstacleAvoidanceParams

// Class Cursor
  pyclass_Var_Urho3D_Cursor
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Cursor

// Class CursorShapeInfo
  pyclass_Var_Urho3D_CursorShapeInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("image_", &Urho3D::CursorShapeInfo::image_, "todo: var docstring")
  .def_readwrite("texture_", &Urho3D::CursorShapeInfo::texture_, "todo: var docstring")
  .def_readwrite("imageRect_", &Urho3D::CursorShapeInfo::imageRect_, "todo: var docstring")
  .def_readwrite("hotSpot_", &Urho3D::CursorShapeInfo::hotSpot_, "todo: var docstring")
//  .def_readwrite("osCursor_", &Urho3D::CursorShapeInfo::osCursor_, "todo: var docstring")
  .def_readwrite("systemDefined_", &Urho3D::CursorShapeInfo::systemDefined_, "todo: var docstring")
  .def_readwrite("systemCursor_", &Urho3D::CursorShapeInfo::systemCursor_, "todo: var docstring")
; // End Class CursorShapeInfo

// Class CustomGeometry
  pyclass_Var_Urho3D_CustomGeometry
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class CustomGeometry

// Class CustomGeometryVertex
  pyclass_Var_Urho3D_CustomGeometryVertex
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::CustomGeometryVertex::position_, "todo: var docstring")
  .def_readwrite("normal_", &Urho3D::CustomGeometryVertex::normal_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::CustomGeometryVertex::color_, "todo: var docstring")
  .def_readwrite("texCoord_", &Urho3D::CustomGeometryVertex::texCoord_, "todo: var docstring")
  .def_readwrite("tangent_", &Urho3D::CustomGeometryVertex::tangent_, "todo: var docstring")
; // End Class CustomGeometryVertex

// Class DebugHud
  pyclass_Var_Urho3D_DebugHud
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class DebugHud

// Class DebugLine
  pyclass_Var_Urho3D_DebugLine
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("start_", &Urho3D::DebugLine::start_, "todo: var docstring")
  .def_readwrite("end_", &Urho3D::DebugLine::end_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::DebugLine::color_, "todo: var docstring")
; // End Class DebugLine

// Class DebugRenderer
  pyclass_Var_Urho3D_DebugRenderer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class DebugRenderer

// Class DebugTriangle
  pyclass_Var_Urho3D_DebugTriangle
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("v1_", &Urho3D::DebugTriangle::v1_, "todo: var docstring")
  .def_readwrite("v2_", &Urho3D::DebugTriangle::v2_, "todo: var docstring")
  .def_readwrite("v3_", &Urho3D::DebugTriangle::v3_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::DebugTriangle::color_, "todo: var docstring")
; // End Class DebugTriangle

// Class Decal
  pyclass_Var_Urho3D_Decal
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("timer_", &Urho3D::Decal::timer_, "todo: var docstring")
  .def_readwrite("timeToLive_", &Urho3D::Decal::timeToLive_, "todo: var docstring")
  .def_readwrite("boundingBox_", &Urho3D::Decal::boundingBox_, "todo: var docstring")
  .def_readwrite("vertices_", &Urho3D::Decal::vertices_, "todo: var docstring")
  .def_readwrite("indices_", &Urho3D::Decal::indices_, "todo: var docstring")
; // End Class Decal

// Class DecalVertex
  pyclass_Var_Urho3D_DecalVertex
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::DecalVertex::position_, "todo: var docstring")
  .def_readwrite("normal_", &Urho3D::DecalVertex::normal_, "todo: var docstring")
  .def_readwrite("texCoord_", &Urho3D::DecalVertex::texCoord_, "todo: var docstring")
  .def_readwrite("tangent_", &Urho3D::DecalVertex::tangent_, "todo: var docstring")
 // Cannot bind &Urho3D::DecalVertex::blendWeights_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::DecalVertex::blendIndices_ TODO: def_property with lambdas for it
; // End Class DecalVertex

// Class DelayedWorldTransform2D
  pyclass_Var_Urho3D_DelayedWorldTransform2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("rigidBody_", &Urho3D::DelayedWorldTransform2D::rigidBody_, "todo: var docstring")
  .def_readwrite("parentRigidBody_", &Urho3D::DelayedWorldTransform2D::parentRigidBody_, "todo: var docstring")
  .def_readwrite("worldPosition_", &Urho3D::DelayedWorldTransform2D::worldPosition_, "todo: var docstring")
  .def_readwrite("worldRotation_", &Urho3D::DelayedWorldTransform2D::worldRotation_, "todo: var docstring")
; // End Class DelayedWorldTransform2D

// Class Deserializer
  pyclass_Var_Urho3D_Deserializer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Deserializer

// Class Drawable
  pyclass_Var_Urho3D_Drawable
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Drawable

// Class DecalSet
  pyclass_Var_Urho3D_DecalSet
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class DecalSet

// Class DelayedCall
  pyclass_Var_Urho3D_DelayedCall
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("period_", &Urho3D::DelayedCall::period_, "todo: var docstring")
  .def_readwrite("delay_", &Urho3D::DelayedCall::delay_, "todo: var docstring")
  .def_readwrite("repeat_", &Urho3D::DelayedCall::repeat_, "todo: var docstring")
  .def_readwrite("declaration_", &Urho3D::DelayedCall::declaration_, "todo: var docstring")
  .def_readwrite("parameters_", &Urho3D::DelayedCall::parameters_, "todo: var docstring")
; // End Class DelayedCall

// Class DelayedWorldTransform
  pyclass_Var_Urho3D_DelayedWorldTransform
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("rigidBody_", &Urho3D::DelayedWorldTransform::rigidBody_, "todo: var docstring")
  .def_readwrite("parentRigidBody_", &Urho3D::DelayedWorldTransform::parentRigidBody_, "todo: var docstring")
  .def_readwrite("worldPosition_", &Urho3D::DelayedWorldTransform::worldPosition_, "todo: var docstring")
  .def_readwrite("worldRotation_", &Urho3D::DelayedWorldTransform::worldRotation_, "todo: var docstring")
; // End Class DelayedWorldTransform

// Class DepthValue
  pyclass_Var_Urho3D_DepthValue
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("min_", &Urho3D::DepthValue::min_, "todo: var docstring")
  .def_readwrite("max_", &Urho3D::DepthValue::max_, "todo: var docstring")
; // End Class DepthValue

// Class DirtyBits
  pyclass_Var_Urho3D_DirtyBits
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::DirtyBits::data_ TODO: def_property with lambdas for it
  .def_readwrite("count_", &Urho3D::DirtyBits::count_, "todo: var docstring")
; // End Class DirtyBits

// Class Drawable2D
  pyclass_Var_Urho3D_Drawable2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Drawable2D

// Class DropDownList
  pyclass_Var_Urho3D_DropDownList
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class DropDownList

// Class DynamicNavBuildData
  pyclass_Var_Urho3D_DynamicNavBuildData
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("contourSet_", &Urho3D::DynamicNavBuildData::contourSet_, "todo: var docstring")
//  .def_readwrite("polyMesh_", &Urho3D::DynamicNavBuildData::polyMesh_, "todo: var docstring")
//  .def_readwrite("heightFieldLayers_", &Urho3D::DynamicNavBuildData::heightFieldLayers_, "todo: var docstring")
//  .def_readwrite("alloc_", &Urho3D::DynamicNavBuildData::alloc_, "todo: var docstring")
; // End Class DynamicNavBuildData

// Class DynamicNavigationMesh
  pyclass_Var_Urho3D_DynamicNavigationMesh
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class DynamicNavigationMesh

// Class Engine
  pyclass_Var_Urho3D_Engine
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Engine

// Class EventHandler
  pyclass_Var_Urho3D_EventHandler
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class EventHandler

// Class EventNameRegistrar
  pyclass_Var_Urho3D_EventNameRegistrar
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class EventNameRegistrar

// Class EventProfiler
  pyclass_Var_Urho3D_EventProfiler
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class EventProfiler

// Class EventProfilerBlock
  pyclass_Var_Urho3D_EventProfilerBlock
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("eventID_", &Urho3D::EventProfilerBlock::eventID_, "todo: var docstring")
; // End Class EventProfilerBlock

// Class EventReceiverGroup
  pyclass_Var_Urho3D_EventReceiverGroup
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("receivers_", &Urho3D::EventReceiverGroup::receivers_, "todo: var docstring")
; // End Class EventReceiverGroup

// Class File
  pyclass_Var_Urho3D_File
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class File

// Class FileSelector
  pyclass_Var_Urho3D_FileSelector
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FileSelector

// Class FileSelectorEntry
  pyclass_Var_Urho3D_FileSelectorEntry
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::FileSelectorEntry::name_, "todo: var docstring")
  .def_readwrite("directory_", &Urho3D::FileSelectorEntry::directory_, "todo: var docstring")
; // End Class FileSelectorEntry

// Class FileSystem
  pyclass_Var_Urho3D_FileSystem
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FileSystem

// Class FileWatcher
  pyclass_Var_Urho3D_FileWatcher
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FileWatcher

// Class FocusParameters
  pyclass_Var_Urho3D_FocusParameters
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("focus_", &Urho3D::FocusParameters::focus_, "todo: var docstring")
  .def_readwrite("nonUniform_", &Urho3D::FocusParameters::nonUniform_, "todo: var docstring")
  .def_readwrite("autoSize_", &Urho3D::FocusParameters::autoSize_, "todo: var docstring")
  .def_readwrite("quantize_", &Urho3D::FocusParameters::quantize_, "todo: var docstring")
  .def_readwrite("minView_", &Urho3D::FocusParameters::minView_, "todo: var docstring")
; // End Class FocusParameters

// Class Font
  pyclass_Var_Urho3D_Font
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Font

// Class FontFace
  pyclass_Var_Urho3D_FontFace
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FontFace

// Class FontFaceBitmap
  pyclass_Var_Urho3D_FontFaceBitmap
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FontFaceBitmap

// Class FontFaceFreeType
  pyclass_Var_Urho3D_FontFaceFreeType
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class FontFaceFreeType

// Class FontGlyph
  pyclass_Var_Urho3D_FontGlyph
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("x_", &Urho3D::FontGlyph::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::FontGlyph::y_, "todo: var docstring")
  .def_readwrite("texWidth_", &Urho3D::FontGlyph::texWidth_, "todo: var docstring")
  .def_readwrite("texHeight_", &Urho3D::FontGlyph::texHeight_, "todo: var docstring")
  .def_readwrite("width_", &Urho3D::FontGlyph::width_, "todo: var docstring")
  .def_readwrite("height_", &Urho3D::FontGlyph::height_, "todo: var docstring")
  .def_readwrite("offsetX_", &Urho3D::FontGlyph::offsetX_, "todo: var docstring")
  .def_readwrite("offsetY_", &Urho3D::FontGlyph::offsetY_, "todo: var docstring")
  .def_readwrite("advanceX_", &Urho3D::FontGlyph::advanceX_, "todo: var docstring")
  .def_readwrite("page_", &Urho3D::FontGlyph::page_, "todo: var docstring")
  .def_readwrite("used_", &Urho3D::FontGlyph::used_, "todo: var docstring")
; // End Class FontGlyph

// Class FrameBufferObject
  pyclass_Var_Urho3D_FrameBufferObject
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("fbo_", &Urho3D::FrameBufferObject::fbo_, "todo: var docstring")
 // Cannot bind &Urho3D::FrameBufferObject::colorAttachments_ TODO: def_property with lambdas for it
  .def_readwrite("depthAttachment_", &Urho3D::FrameBufferObject::depthAttachment_, "todo: var docstring")
  .def_readwrite("readBuffers_", &Urho3D::FrameBufferObject::readBuffers_, "todo: var docstring")
  .def_readwrite("drawBuffers_", &Urho3D::FrameBufferObject::drawBuffers_, "todo: var docstring")
; // End Class FrameBufferObject

// Class FrameInfo
  pyclass_Var_Urho3D_FrameInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("frameNumber_", &Urho3D::FrameInfo::frameNumber_, "todo: var docstring")
  .def_readwrite("timeStep_", &Urho3D::FrameInfo::timeStep_, "todo: var docstring")
  .def_readwrite("viewSize_", &Urho3D::FrameInfo::viewSize_, "todo: var docstring")
  .def_readwrite("camera_", &Urho3D::FrameInfo::camera_, "todo: var docstring")
; // End Class FrameInfo

// Class Frustum
  pyclass_Var_Urho3D_Frustum
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::Frustum::planes_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::Frustum::vertices_ TODO: def_property with lambdas for it
; // End Class Frustum

// Class FrustumOctreeQuery
  pyclass_Var_Urho3D_FrustumOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("frustum_", &Urho3D::FrustumOctreeQuery::frustum_, "todo: var docstring")
; // End Class FrustumOctreeQuery

// Class GPUObject
  pyclass_Var_Urho3D_GPUObject
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class GPUObject

// Class Geometry
  pyclass_Var_Urho3D_Geometry
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Geometry

// Class GeometryDesc
  pyclass_Var_Urho3D_GeometryDesc
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("type_", &Urho3D::GeometryDesc::type_, "todo: var docstring")
  .def_readwrite("vbRef_", &Urho3D::GeometryDesc::vbRef_, "todo: var docstring")
  .def_readwrite("ibRef_", &Urho3D::GeometryDesc::ibRef_, "todo: var docstring")
  .def_readwrite("indexStart_", &Urho3D::GeometryDesc::indexStart_, "todo: var docstring")
  .def_readwrite("indexCount_", &Urho3D::GeometryDesc::indexCount_, "todo: var docstring")
; // End Class GeometryDesc

// Class GlyphLocation
  pyclass_Var_Urho3D_GlyphLocation
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("x_", &Urho3D::GlyphLocation::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::GlyphLocation::y_, "todo: var docstring")
  .def_readwrite("glyph_", &Urho3D::GlyphLocation::glyph_, "todo: var docstring")
; // End Class GlyphLocation

// Class Graphics
  pyclass_Var_Urho3D_Graphics
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Graphics

// Class GraphicsImpl
  pyclass_Var_Urho3D_GraphicsImpl
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class GraphicsImpl

// Class HashBase
  pyclass_Var_Urho3D_HashBase
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readonly_static("MIN_BUCKETS", &Urho3D::HashBase::MIN_BUCKETS, "todo: var docstring")
  .def_readonly_static("MAX_LOAD_FACTOR", &Urho3D::HashBase::MAX_LOAD_FACTOR, "todo: var docstring")
; // End Class HashBase

// Class HashIteratorBase
  pyclass_Var_Urho3D_HashIteratorBase
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::HashIteratorBase (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::HashIteratorBase (), "todo: docstring")
  // Variables
  .def_readwrite("ptr_", &Urho3D::HashIteratorBase::ptr_, "todo: var docstring")
; // End Class HashIteratorBase

// Class HashNodeBase
  pyclass_Var_Urho3D_HashNodeBase
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("down_", &Urho3D::HashNodeBase::down_, "todo: var docstring")
  .def_readwrite("prev_", &Urho3D::HashNodeBase::prev_, "todo: var docstring")
  .def_readwrite("next_", &Urho3D::HashNodeBase::next_, "todo: var docstring")
; // End Class HashNodeBase

// Class HeightfieldData
  pyclass_Var_Urho3D_HeightfieldData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("heightData_", &Urho3D::HeightfieldData::heightData_, "todo: var docstring")
  .def_readwrite("spacing_", &Urho3D::HeightfieldData::spacing_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::HeightfieldData::size_, "todo: var docstring")
  .def_readwrite("minHeight_", &Urho3D::HeightfieldData::minHeight_, "todo: var docstring")
  .def_readwrite("maxHeight_", &Urho3D::HeightfieldData::maxHeight_, "todo: var docstring")
; // End Class HeightfieldData

// Class HiresTimer
  pyclass_Var_Urho3D_HiresTimer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class HiresTimer

// Class HttpRequest
  pyclass_Var_Urho3D_HttpRequest
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class HttpRequest

// Class Image
  pyclass_Var_Urho3D_Image
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Image

// Class IndexBuffer
  pyclass_Var_Urho3D_IndexBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class IndexBuffer

// Class IndexBufferDesc
  pyclass_Var_Urho3D_IndexBufferDesc
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("indexCount_", &Urho3D::IndexBufferDesc::indexCount_, "todo: var docstring")
  .def_readwrite("indexSize_", &Urho3D::IndexBufferDesc::indexSize_, "todo: var docstring")
  .def_readwrite("dataSize_", &Urho3D::IndexBufferDesc::dataSize_, "todo: var docstring")
  .def_readwrite("data_", &Urho3D::IndexBufferDesc::data_, "todo: var docstring")
; // End Class IndexBufferDesc

// Class Input
  pyclass_Var_Urho3D_Input
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Input

// Class InstanceData
  pyclass_Var_Urho3D_InstanceData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("worldTransform_", &Urho3D::InstanceData::worldTransform_, "todo: var docstring")
  .def_readwrite("instancingData_", &Urho3D::InstanceData::instancingData_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::InstanceData::distance_, "todo: var docstring")
; // End Class InstanceData

// Class IntRect
  pyclass_Var_Urho3D_IntRect
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::IntRect (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntRect (), "todo: docstring")
  // Variables
  .def_readwrite("left_", &Urho3D::IntRect::left_, "todo: var docstring")
  .def_readwrite("top_", &Urho3D::IntRect::top_, "todo: var docstring")
  .def_readwrite("right_", &Urho3D::IntRect::right_, "todo: var docstring")
  .def_readwrite("bottom_", &Urho3D::IntRect::bottom_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::IntRect::ZERO, "todo: var docstring")
; // End Class IntRect

// Class IntVector2
  pyclass_Var_Urho3D_IntVector2
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::IntVector2 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntVector2 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::IntVector2 (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::IntVector2 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * int(), "todo: docstring")
// OP operator/ len 1
      .def(py::self / int(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::IntVector2 (), "todo: docstring")
// OP operator-= len 1
      .def(py::self -= Urho3D::IntVector2 (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= int(), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= int(), "todo: docstring")
  // Variables
  .def_readwrite("x_", &Urho3D::IntVector2::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::IntVector2::y_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::IntVector2::ZERO, "todo: var docstring")
  .def_readonly_static("LEFT", &Urho3D::IntVector2::LEFT, "todo: var docstring")
  .def_readonly_static("RIGHT", &Urho3D::IntVector2::RIGHT, "todo: var docstring")
  .def_readonly_static("UP", &Urho3D::IntVector2::UP, "todo: var docstring")
  .def_readonly_static("DOWN", &Urho3D::IntVector2::DOWN, "todo: var docstring")
  .def_readonly_static("ONE", &Urho3D::IntVector2::ONE, "todo: var docstring")
; // End Class IntVector2

// Class IntVector3
  pyclass_Var_Urho3D_IntVector3
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::IntVector3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntVector3 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::IntVector3 (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::IntVector3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * int(), "todo: docstring")
// OP operator/ len 1
      .def(py::self / int(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::IntVector3 (), "todo: docstring")
// OP operator-= len 1
      .def(py::self -= Urho3D::IntVector3 (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= int(), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= int(), "todo: docstring")
  // Variables
  .def_readwrite("x_", &Urho3D::IntVector3::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::IntVector3::y_, "todo: var docstring")
  .def_readwrite("z_", &Urho3D::IntVector3::z_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::IntVector3::ZERO, "todo: var docstring")
  .def_readonly_static("LEFT", &Urho3D::IntVector3::LEFT, "todo: var docstring")
  .def_readonly_static("RIGHT", &Urho3D::IntVector3::RIGHT, "todo: var docstring")
  .def_readonly_static("UP", &Urho3D::IntVector3::UP, "todo: var docstring")
  .def_readonly_static("DOWN", &Urho3D::IntVector3::DOWN, "todo: var docstring")
  .def_readonly_static("FORWARD", &Urho3D::IntVector3::FORWARD, "todo: var docstring")
  .def_readonly_static("BACK", &Urho3D::IntVector3::BACK, "todo: var docstring")
  .def_readonly_static("ONE", &Urho3D::IntVector3::ONE, "todo: var docstring")
; // End Class IntVector3

// Class JSONFile
  pyclass_Var_Urho3D_JSONFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class JSONFile

// Class JSONValue
  pyclass_Var_Urho3D_JSONValue
  // Constructors
  // Methods
  // Operators
// OP operator[] len 1
  .def("__getitem__",[]( Urho3D::JSONValue& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
  .def("__getitem__",[](const Urho3D::JSONValue& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
  .def("__getitem__",[]( Urho3D::JSONValue& arg0, const Urho3D::String & arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
  .def("__getitem__",[](const Urho3D::JSONValue& arg0, const Urho3D::String & arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
  // Variables
  .def_readonly_static("EMPTY", &Urho3D::JSONValue::EMPTY, "todo: var docstring")
  .def_readonly_static("emptyArray", &Urho3D::JSONValue::emptyArray, "todo: var docstring")
  .def_readonly_static("emptyObject", &Urho3D::JSONValue::emptyObject, "todo: var docstring")
; // End Class JSONValue

// Class JoystickState
  pyclass_Var_Urho3D_JoystickState
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("joystick_", &Urho3D::JoystickState::joystick_, "todo: var docstring")
  .def_readwrite("joystickID_", &Urho3D::JoystickState::joystickID_, "todo: var docstring")
//  .def_readwrite("controller_", &Urho3D::JoystickState::controller_, "todo: var docstring")
  .def_readwrite("screenJoystick_", &Urho3D::JoystickState::screenJoystick_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::JoystickState::name_, "todo: var docstring")
  .def_readwrite("buttons_", &Urho3D::JoystickState::buttons_, "todo: var docstring")
  .def_readwrite("buttonPress_", &Urho3D::JoystickState::buttonPress_, "todo: var docstring")
  .def_readwrite("axes_", &Urho3D::JoystickState::axes_, "todo: var docstring")
  .def_readwrite("hats_", &Urho3D::JoystickState::hats_, "todo: var docstring")
; // End Class JoystickState

// Class Light
  pyclass_Var_Urho3D_Light
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Light

// Class LightBatchQueue
  pyclass_Var_Urho3D_LightBatchQueue
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("light_", &Urho3D::LightBatchQueue::light_, "todo: var docstring")
  .def_readwrite("negative_", &Urho3D::LightBatchQueue::negative_, "todo: var docstring")
  .def_readwrite("shadowMap_", &Urho3D::LightBatchQueue::shadowMap_, "todo: var docstring")
  .def_readwrite("litBaseBatches_", &Urho3D::LightBatchQueue::litBaseBatches_, "todo: var docstring")
  .def_readwrite("litBatches_", &Urho3D::LightBatchQueue::litBatches_, "todo: var docstring")
  .def_readwrite("shadowSplits_", &Urho3D::LightBatchQueue::shadowSplits_, "todo: var docstring")
  .def_readwrite("vertexLights_", &Urho3D::LightBatchQueue::vertexLights_, "todo: var docstring")
  .def_readwrite("volumeBatches_", &Urho3D::LightBatchQueue::volumeBatches_, "todo: var docstring")
; // End Class LightBatchQueue

// Class LightQueryResult
  pyclass_Var_Urho3D_LightQueryResult
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("light_", &Urho3D::LightQueryResult::light_, "todo: var docstring")
  .def_readwrite("litGeometries_", &Urho3D::LightQueryResult::litGeometries_, "todo: var docstring")
  .def_readwrite("shadowCasters_", &Urho3D::LightQueryResult::shadowCasters_, "todo: var docstring")
 // Cannot bind &Urho3D::LightQueryResult::shadowCameras_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::LightQueryResult::shadowCasterBegin_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::LightQueryResult::shadowCasterEnd_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::LightQueryResult::shadowCasterBox_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::LightQueryResult::shadowNearSplits_ TODO: def_property with lambdas for it
 // Cannot bind &Urho3D::LightQueryResult::shadowFarSplits_ TODO: def_property with lambdas for it
  .def_readwrite("numSplits_", &Urho3D::LightQueryResult::numSplits_, "todo: var docstring")
; // End Class LightQueryResult

// Class LineEdit
  pyclass_Var_Urho3D_LineEdit
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class LineEdit

// Class LinkedListNode
  pyclass_Var_Urho3D_LinkedListNode
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("next_", &Urho3D::LinkedListNode::next_, "todo: var docstring")
; // End Class LinkedListNode

// Class ListBase
  pyclass_Var_Urho3D_ListBase
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ListBase

// Class ListIteratorBase
  pyclass_Var_Urho3D_ListIteratorBase
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::ListIteratorBase (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::ListIteratorBase (), "todo: docstring")
  // Variables
  .def_readwrite("ptr_", &Urho3D::ListIteratorBase::ptr_, "todo: var docstring")
; // End Class ListIteratorBase

// Class ListNodeBase
  pyclass_Var_Urho3D_ListNodeBase
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("prev_", &Urho3D::ListNodeBase::prev_, "todo: var docstring")
  .def_readwrite("next_", &Urho3D::ListNodeBase::next_, "todo: var docstring")
; // End Class ListNodeBase

// Class ListView
  pyclass_Var_Urho3D_ListView
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ListView

// Class Localization
  pyclass_Var_Urho3D_Localization
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Localization

// Class Log
  pyclass_Var_Urho3D_Log
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Log

// Class LogicComponent
  pyclass_Var_Urho3D_LogicComponent
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class LogicComponent

// Class ManifoldPair
  pyclass_Var_Urho3D_ManifoldPair
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("manifold_", &Urho3D::ManifoldPair::manifold_, "todo: var docstring")
//  .def_readwrite("flippedManifold_", &Urho3D::ManifoldPair::flippedManifold_, "todo: var docstring")
; // End Class ManifoldPair

// Class Material
  pyclass_Var_Urho3D_Material
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Material

// Class MaterialShaderParameter
  pyclass_Var_Urho3D_MaterialShaderParameter
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::MaterialShaderParameter::name_, "todo: var docstring")
  .def_readwrite("value_", &Urho3D::MaterialShaderParameter::value_, "todo: var docstring")
; // End Class MaterialShaderParameter

// Class Matrix2
  pyclass_Var_Urho3D_Matrix2
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Matrix2 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix2 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector2 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Matrix2 (), "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Matrix2 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix2 (), "todo: docstring")
  // Variables
  .def_readwrite("m00_", &Urho3D::Matrix2::m00_, "todo: var docstring")
  .def_readwrite("m01_", &Urho3D::Matrix2::m01_, "todo: var docstring")
  .def_readwrite("m10_", &Urho3D::Matrix2::m10_, "todo: var docstring")
  .def_readwrite("m11_", &Urho3D::Matrix2::m11_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Matrix2::ZERO, "todo: var docstring")
  .def_readonly_static("IDENTITY", &Urho3D::Matrix2::IDENTITY, "todo: var docstring")
; // End Class Matrix2

// Class Matrix3
  pyclass_Var_Urho3D_Matrix3
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Matrix3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector3 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Matrix3 (), "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Matrix3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix3 (), "todo: docstring")
  // Variables
  .def_readwrite("m00_", &Urho3D::Matrix3::m00_, "todo: var docstring")
  .def_readwrite("m01_", &Urho3D::Matrix3::m01_, "todo: var docstring")
  .def_readwrite("m02_", &Urho3D::Matrix3::m02_, "todo: var docstring")
  .def_readwrite("m10_", &Urho3D::Matrix3::m10_, "todo: var docstring")
  .def_readwrite("m11_", &Urho3D::Matrix3::m11_, "todo: var docstring")
  .def_readwrite("m12_", &Urho3D::Matrix3::m12_, "todo: var docstring")
  .def_readwrite("m20_", &Urho3D::Matrix3::m20_, "todo: var docstring")
  .def_readwrite("m21_", &Urho3D::Matrix3::m21_, "todo: var docstring")
  .def_readwrite("m22_", &Urho3D::Matrix3::m22_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Matrix3::ZERO, "todo: var docstring")
  .def_readonly_static("IDENTITY", &Urho3D::Matrix3::IDENTITY, "todo: var docstring")
; // End Class Matrix3

// Class Matrix3x4
  pyclass_Var_Urho3D_Matrix3x4
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector4 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix4 (), "todo: docstring")
  // Variables
  .def_readwrite("m00_", &Urho3D::Matrix3x4::m00_, "todo: var docstring")
  .def_readwrite("m01_", &Urho3D::Matrix3x4::m01_, "todo: var docstring")
  .def_readwrite("m02_", &Urho3D::Matrix3x4::m02_, "todo: var docstring")
  .def_readwrite("m03_", &Urho3D::Matrix3x4::m03_, "todo: var docstring")
  .def_readwrite("m10_", &Urho3D::Matrix3x4::m10_, "todo: var docstring")
  .def_readwrite("m11_", &Urho3D::Matrix3x4::m11_, "todo: var docstring")
  .def_readwrite("m12_", &Urho3D::Matrix3x4::m12_, "todo: var docstring")
  .def_readwrite("m13_", &Urho3D::Matrix3x4::m13_, "todo: var docstring")
  .def_readwrite("m20_", &Urho3D::Matrix3x4::m20_, "todo: var docstring")
  .def_readwrite("m21_", &Urho3D::Matrix3x4::m21_, "todo: var docstring")
  .def_readwrite("m22_", &Urho3D::Matrix3x4::m22_, "todo: var docstring")
  .def_readwrite("m23_", &Urho3D::Matrix3x4::m23_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Matrix3x4::ZERO, "todo: var docstring")
  .def_readonly_static("IDENTITY", &Urho3D::Matrix3x4::IDENTITY, "todo: var docstring")
; // End Class Matrix3x4

// Class Matrix4
  pyclass_Var_Urho3D_Matrix4
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Matrix4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector4 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Matrix4 (), "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Matrix4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Matrix3x4 (), "todo: docstring")
  // Variables
  .def_readwrite("m00_", &Urho3D::Matrix4::m00_, "todo: var docstring")
  .def_readwrite("m01_", &Urho3D::Matrix4::m01_, "todo: var docstring")
  .def_readwrite("m02_", &Urho3D::Matrix4::m02_, "todo: var docstring")
  .def_readwrite("m03_", &Urho3D::Matrix4::m03_, "todo: var docstring")
  .def_readwrite("m10_", &Urho3D::Matrix4::m10_, "todo: var docstring")
  .def_readwrite("m11_", &Urho3D::Matrix4::m11_, "todo: var docstring")
  .def_readwrite("m12_", &Urho3D::Matrix4::m12_, "todo: var docstring")
  .def_readwrite("m13_", &Urho3D::Matrix4::m13_, "todo: var docstring")
  .def_readwrite("m20_", &Urho3D::Matrix4::m20_, "todo: var docstring")
  .def_readwrite("m21_", &Urho3D::Matrix4::m21_, "todo: var docstring")
  .def_readwrite("m22_", &Urho3D::Matrix4::m22_, "todo: var docstring")
  .def_readwrite("m23_", &Urho3D::Matrix4::m23_, "todo: var docstring")
  .def_readwrite("m30_", &Urho3D::Matrix4::m30_, "todo: var docstring")
  .def_readwrite("m31_", &Urho3D::Matrix4::m31_, "todo: var docstring")
  .def_readwrite("m32_", &Urho3D::Matrix4::m32_, "todo: var docstring")
  .def_readwrite("m33_", &Urho3D::Matrix4::m33_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Matrix4::ZERO, "todo: var docstring")
  .def_readonly_static("IDENTITY", &Urho3D::Matrix4::IDENTITY, "todo: var docstring")
; // End Class Matrix4

// Class MemoryBuffer
  pyclass_Var_Urho3D_MemoryBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class MemoryBuffer

// Class Menu
  pyclass_Var_Urho3D_Menu
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Menu

// Class MessageBox
  pyclass_Var_Urho3D_MessageBox
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class MessageBox

// Class Model
  pyclass_Var_Urho3D_Model
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Model

// Class ModelMorph
  pyclass_Var_Urho3D_ModelMorph
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::ModelMorph::name_, "todo: var docstring")
  .def_readwrite("nameHash_", &Urho3D::ModelMorph::nameHash_, "todo: var docstring")
  .def_readwrite("weight_", &Urho3D::ModelMorph::weight_, "todo: var docstring")
  .def_readwrite("buffers_", &Urho3D::ModelMorph::buffers_, "todo: var docstring")
; // End Class ModelMorph

// Class Mutex
  pyclass_Var_Urho3D_Mutex
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Mutex

// Class MutexLock
  pyclass_Var_Urho3D_MutexLock
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class MutexLock

// Class NamedPipe
  pyclass_Var_Urho3D_NamedPipe
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class NamedPipe

// Class NavArea
  pyclass_Var_Urho3D_NavArea
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class NavArea

// Class NavAreaStub
  pyclass_Var_Urho3D_NavAreaStub
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("bounds_", &Urho3D::NavAreaStub::bounds_, "todo: var docstring")
  .def_readwrite("areaID_", &Urho3D::NavAreaStub::areaID_, "todo: var docstring")
; // End Class NavAreaStub

// Class NavBuildData
  pyclass_Var_Urho3D_NavBuildData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("worldBoundingBox_", &Urho3D::NavBuildData::worldBoundingBox_, "todo: var docstring")
  .def_readwrite("vertices_", &Urho3D::NavBuildData::vertices_, "todo: var docstring")
  .def_readwrite("indices_", &Urho3D::NavBuildData::indices_, "todo: var docstring")
  .def_readwrite("offMeshVertices_", &Urho3D::NavBuildData::offMeshVertices_, "todo: var docstring")
  .def_readwrite("offMeshRadii_", &Urho3D::NavBuildData::offMeshRadii_, "todo: var docstring")
  .def_readwrite("offMeshFlags_", &Urho3D::NavBuildData::offMeshFlags_, "todo: var docstring")
  .def_readwrite("offMeshAreas_", &Urho3D::NavBuildData::offMeshAreas_, "todo: var docstring")
  .def_readwrite("offMeshDir_", &Urho3D::NavBuildData::offMeshDir_, "todo: var docstring")
//  .def_readwrite("ctx_", &Urho3D::NavBuildData::ctx_, "todo: var docstring")
//  .def_readwrite("heightField_", &Urho3D::NavBuildData::heightField_, "todo: var docstring")
//  .def_readwrite("compactHeightField_", &Urho3D::NavBuildData::compactHeightField_, "todo: var docstring")
  .def_readwrite("navAreas_", &Urho3D::NavBuildData::navAreas_, "todo: var docstring")
; // End Class NavBuildData

// Class Navigable
  pyclass_Var_Urho3D_Navigable
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Navigable

// Class NavigationGeometryInfo
  pyclass_Var_Urho3D_NavigationGeometryInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("component_", &Urho3D::NavigationGeometryInfo::component_, "todo: var docstring")
  .def_readwrite("lodLevel_", &Urho3D::NavigationGeometryInfo::lodLevel_, "todo: var docstring")
  .def_readwrite("transform_", &Urho3D::NavigationGeometryInfo::transform_, "todo: var docstring")
  .def_readwrite("boundingBox_", &Urho3D::NavigationGeometryInfo::boundingBox_, "todo: var docstring")
; // End Class NavigationGeometryInfo

// Class NavigationMesh
  pyclass_Var_Urho3D_NavigationMesh
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class NavigationMesh

// Class NavigationPathPoint
  pyclass_Var_Urho3D_NavigationPathPoint
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::NavigationPathPoint::position_, "todo: var docstring")
  .def_readwrite("flag_", &Urho3D::NavigationPathPoint::flag_, "todo: var docstring")
  .def_readwrite("areaID_", &Urho3D::NavigationPathPoint::areaID_, "todo: var docstring")
; // End Class NavigationPathPoint

// Class Network
  pyclass_Var_Urho3D_Network
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Network

// Class NetworkPriority
  pyclass_Var_Urho3D_NetworkPriority
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class NetworkPriority

// Class NetworkState
  pyclass_Var_Urho3D_NetworkState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("attributes_", &Urho3D::NetworkState::attributes_, "todo: var docstring")
  .def_readwrite("currentValues_", &Urho3D::NetworkState::currentValues_, "todo: var docstring")
  .def_readwrite("previousValues_", &Urho3D::NetworkState::previousValues_, "todo: var docstring")
  .def_readwrite("replicationStates_", &Urho3D::NetworkState::replicationStates_, "todo: var docstring")
  .def_readwrite("previousVars_", &Urho3D::NetworkState::previousVars_, "todo: var docstring")
  .def_readwrite("interceptMask_", &Urho3D::NetworkState::interceptMask_, "todo: var docstring")
; // End Class NetworkState

// Class Node
  pyclass_Var_Urho3D_Node
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Node

// Class NodeImpl
  pyclass_Var_Urho3D_NodeImpl
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("dependencyNodes_", &Urho3D::NodeImpl::dependencyNodes_, "todo: var docstring")
  .def_readwrite("owner_", &Urho3D::NodeImpl::owner_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::NodeImpl::name_, "todo: var docstring")
  .def_readwrite("tags_", &Urho3D::NodeImpl::tags_, "todo: var docstring")
  .def_readwrite("nameHash_", &Urho3D::NodeImpl::nameHash_, "todo: var docstring")
  .def_readwrite("attrBuffer_", &Urho3D::NodeImpl::attrBuffer_, "todo: var docstring")
  .def_readwrite("basePath_", &Urho3D::NodeImpl::basePath_, "todo: var docstring")
; // End Class NodeImpl

// Class NodeReplicationState
  pyclass_Var_Urho3D_NodeReplicationState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("sceneState_", &Urho3D::NodeReplicationState::sceneState_, "todo: var docstring")
  .def_readwrite("node_", &Urho3D::NodeReplicationState::node_, "todo: var docstring")
  .def_readwrite("dirtyAttributes_", &Urho3D::NodeReplicationState::dirtyAttributes_, "todo: var docstring")
  .def_readwrite("dirtyVars_", &Urho3D::NodeReplicationState::dirtyVars_, "todo: var docstring")
  .def_readwrite("componentStates_", &Urho3D::NodeReplicationState::componentStates_, "todo: var docstring")
  .def_readwrite("priorityAcc_", &Urho3D::NodeReplicationState::priorityAcc_, "todo: var docstring")
  .def_readwrite("markedDirty_", &Urho3D::NodeReplicationState::markedDirty_, "todo: var docstring")
; // End Class NodeReplicationState

// Class ObjectAnimation
  pyclass_Var_Urho3D_ObjectAnimation
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ObjectAnimation

// Class ObjectFactory
  pyclass_Var_Urho3D_ObjectFactory
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ObjectFactory

// Class Obstacle
  pyclass_Var_Urho3D_Obstacle
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Obstacle

// Class OcclusionBatch
  pyclass_Var_Urho3D_OcclusionBatch
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("model_", &Urho3D::OcclusionBatch::model_, "todo: var docstring")
  .def_readwrite("vertexData_", &Urho3D::OcclusionBatch::vertexData_, "todo: var docstring")
  .def_readwrite("vertexSize_", &Urho3D::OcclusionBatch::vertexSize_, "todo: var docstring")
  .def_readwrite("indexData_", &Urho3D::OcclusionBatch::indexData_, "todo: var docstring")
  .def_readwrite("indexSize_", &Urho3D::OcclusionBatch::indexSize_, "todo: var docstring")
  .def_readwrite("drawStart_", &Urho3D::OcclusionBatch::drawStart_, "todo: var docstring")
  .def_readwrite("drawCount_", &Urho3D::OcclusionBatch::drawCount_, "todo: var docstring")
; // End Class OcclusionBatch

// Class OcclusionBuffer
  pyclass_Var_Urho3D_OcclusionBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class OcclusionBuffer

// Class OcclusionBufferData
  pyclass_Var_Urho3D_OcclusionBufferData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("dataWithSafety_", &Urho3D::OcclusionBufferData::dataWithSafety_, "todo: var docstring")
  .def_readwrite("data_", &Urho3D::OcclusionBufferData::data_, "todo: var docstring")
  .def_readwrite("used_", &Urho3D::OcclusionBufferData::used_, "todo: var docstring")
; // End Class OcclusionBufferData

// Class Octant
  pyclass_Var_Urho3D_Octant
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Octant

// Class Octree
  pyclass_Var_Urho3D_Octree
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Octree

// Class OctreeQuery
  pyclass_Var_Urho3D_OctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::OctreeQuery::result_ TODO: def_property with lambdas for it
  .def_readwrite("drawableFlags_", &Urho3D::OctreeQuery::drawableFlags_, "todo: var docstring")
  .def_readwrite("viewMask_", &Urho3D::OctreeQuery::viewMask_, "todo: var docstring")
; // End Class OctreeQuery

// Class OctreeQueryResult
  pyclass_Var_Urho3D_OctreeQueryResult
  // Constructors
  // Methods
  // Operators
// OP operator!= len 1
      .def(py::self != Urho3D::OctreeQueryResult (), "todo: docstring")
  // Variables
  .def_readwrite("drawable_", &Urho3D::OctreeQueryResult::drawable_, "todo: var docstring")
  .def_readwrite("node_", &Urho3D::OctreeQueryResult::node_, "todo: var docstring")
; // End Class OctreeQueryResult

// Class OffMeshConnection
  pyclass_Var_Urho3D_OffMeshConnection
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class OffMeshConnection

// Class OggVorbisSoundStream
  pyclass_Var_Urho3D_OggVorbisSoundStream
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class OggVorbisSoundStream

// Class PListFile
  pyclass_Var_Urho3D_PListFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class PListFile

// Class PListValue
  pyclass_Var_Urho3D_PListValue
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class PListValue

// Class PackageDownload
  pyclass_Var_Urho3D_PackageDownload
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("file_", &Urho3D::PackageDownload::file_, "todo: var docstring")
  .def_readwrite("receivedFragments_", &Urho3D::PackageDownload::receivedFragments_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::PackageDownload::name_, "todo: var docstring")
  .def_readwrite("totalFragments_", &Urho3D::PackageDownload::totalFragments_, "todo: var docstring")
  .def_readwrite("checksum_", &Urho3D::PackageDownload::checksum_, "todo: var docstring")
  .def_readwrite("initiated_", &Urho3D::PackageDownload::initiated_, "todo: var docstring")
; // End Class PackageDownload

// Class PackageEntry
  pyclass_Var_Urho3D_PackageEntry
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("offset_", &Urho3D::PackageEntry::offset_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::PackageEntry::size_, "todo: var docstring")
  .def_readwrite("checksum_", &Urho3D::PackageEntry::checksum_, "todo: var docstring")
; // End Class PackageEntry

// Class PackageFile
  pyclass_Var_Urho3D_PackageFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class PackageFile

// Class PackageUpload
  pyclass_Var_Urho3D_PackageUpload
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("file_", &Urho3D::PackageUpload::file_, "todo: var docstring")
  .def_readwrite("fragment_", &Urho3D::PackageUpload::fragment_, "todo: var docstring")
  .def_readwrite("totalFragments_", &Urho3D::PackageUpload::totalFragments_, "todo: var docstring")
; // End Class PackageUpload

// Class Particle
  pyclass_Var_Urho3D_Particle
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("velocity_", &Urho3D::Particle::velocity_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::Particle::size_, "todo: var docstring")
  .def_readwrite("timer_", &Urho3D::Particle::timer_, "todo: var docstring")
  .def_readwrite("timeToLive_", &Urho3D::Particle::timeToLive_, "todo: var docstring")
  .def_readwrite("scale_", &Urho3D::Particle::scale_, "todo: var docstring")
  .def_readwrite("rotationSpeed_", &Urho3D::Particle::rotationSpeed_, "todo: var docstring")
  .def_readwrite("colorIndex_", &Urho3D::Particle::colorIndex_, "todo: var docstring")
  .def_readwrite("texIndex_", &Urho3D::Particle::texIndex_, "todo: var docstring")
; // End Class Particle

// Class Particle2D
  pyclass_Var_Urho3D_Particle2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("timeToLive_", &Urho3D::Particle2D::timeToLive_, "todo: var docstring")
  .def_readwrite("position_", &Urho3D::Particle2D::position_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::Particle2D::size_, "todo: var docstring")
  .def_readwrite("sizeDelta_", &Urho3D::Particle2D::sizeDelta_, "todo: var docstring")
  .def_readwrite("rotation_", &Urho3D::Particle2D::rotation_, "todo: var docstring")
  .def_readwrite("rotationDelta_", &Urho3D::Particle2D::rotationDelta_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::Particle2D::color_, "todo: var docstring")
  .def_readwrite("colorDelta_", &Urho3D::Particle2D::colorDelta_, "todo: var docstring")
  .def_readwrite("startPos_", &Urho3D::Particle2D::startPos_, "todo: var docstring")
  .def_readwrite("velocity_", &Urho3D::Particle2D::velocity_, "todo: var docstring")
  .def_readwrite("radialAcceleration_", &Urho3D::Particle2D::radialAcceleration_, "todo: var docstring")
  .def_readwrite("tangentialAcceleration_", &Urho3D::Particle2D::tangentialAcceleration_, "todo: var docstring")
  .def_readwrite("emitRadius_", &Urho3D::Particle2D::emitRadius_, "todo: var docstring")
  .def_readwrite("emitRadiusDelta_", &Urho3D::Particle2D::emitRadiusDelta_, "todo: var docstring")
  .def_readwrite("emitRotation_", &Urho3D::Particle2D::emitRotation_, "todo: var docstring")
  .def_readwrite("emitRotationDelta_", &Urho3D::Particle2D::emitRotationDelta_, "todo: var docstring")
; // End Class Particle2D

// Class ParticleEffect
  pyclass_Var_Urho3D_ParticleEffect
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ParticleEffect

// Class ParticleEffect2D
  pyclass_Var_Urho3D_ParticleEffect2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ParticleEffect2D

// Class ParticleEmitter
  pyclass_Var_Urho3D_ParticleEmitter
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ParticleEmitter

// Class ParticleEmitter2D
  pyclass_Var_Urho3D_ParticleEmitter2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ParticleEmitter2D

// Class Pass
  pyclass_Var_Urho3D_Pass
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Pass

// Class PerThreadSceneResult
  pyclass_Var_Urho3D_PerThreadSceneResult
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("geometries_", &Urho3D::PerThreadSceneResult::geometries_, "todo: var docstring")
  .def_readwrite("lights_", &Urho3D::PerThreadSceneResult::lights_, "todo: var docstring")
  .def_readwrite("minZ_", &Urho3D::PerThreadSceneResult::minZ_, "todo: var docstring")
  .def_readwrite("maxZ_", &Urho3D::PerThreadSceneResult::maxZ_, "todo: var docstring")
; // End Class PerThreadSceneResult

// Class PhysicsRaycastResult
  pyclass_Var_Urho3D_PhysicsRaycastResult
  // Constructors
  // Methods
  // Operators
// OP operator!= len 1
      .def(py::self != Urho3D::PhysicsRaycastResult (), "todo: docstring")
  // Variables
  .def_readwrite("position_", &Urho3D::PhysicsRaycastResult::position_, "todo: var docstring")
  .def_readwrite("normal_", &Urho3D::PhysicsRaycastResult::normal_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::PhysicsRaycastResult::distance_, "todo: var docstring")
  .def_readwrite("hitFraction_", &Urho3D::PhysicsRaycastResult::hitFraction_, "todo: var docstring")
  .def_readwrite("body_", &Urho3D::PhysicsRaycastResult::body_, "todo: var docstring")
; // End Class PhysicsRaycastResult

// Class PhysicsRaycastResult2D
  pyclass_Var_Urho3D_PhysicsRaycastResult2D
  // Constructors
  // Methods
  // Operators
// OP operator!= len 1
      .def(py::self != Urho3D::PhysicsRaycastResult2D (), "todo: docstring")
  // Variables
  .def_readwrite("position_", &Urho3D::PhysicsRaycastResult2D::position_, "todo: var docstring")
  .def_readwrite("normal_", &Urho3D::PhysicsRaycastResult2D::normal_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::PhysicsRaycastResult2D::distance_, "todo: var docstring")
  .def_readwrite("body_", &Urho3D::PhysicsRaycastResult2D::body_, "todo: var docstring")
; // End Class PhysicsRaycastResult2D

// Class PhysicsWorld
  pyclass_Var_Urho3D_PhysicsWorld
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite_static("config", &Urho3D::PhysicsWorld::config, "todo: var docstring")
; // End Class PhysicsWorld

// Class PhysicsWorld2D
  pyclass_Var_Urho3D_PhysicsWorld2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class PhysicsWorld2D

// Class PhysicsWorldConfig
  pyclass_Var_Urho3D_PhysicsWorldConfig
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("collisionConfig_", &Urho3D::PhysicsWorldConfig::collisionConfig_, "todo: var docstring")
; // End Class PhysicsWorldConfig

// Class Plane
  pyclass_Var_Urho3D_Plane
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("normal_", &Urho3D::Plane::normal_, "todo: var docstring")
  .def_readwrite("absNormal_", &Urho3D::Plane::absNormal_, "todo: var docstring")
  .def_readwrite("d_", &Urho3D::Plane::d_, "todo: var docstring")
  .def_readonly_static("UP", &Urho3D::Plane::UP, "todo: var docstring")
; // End Class Plane

// Class PointOctreeQuery
  pyclass_Var_Urho3D_PointOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("point_", &Urho3D::PointOctreeQuery::point_, "todo: var docstring")
; // End Class PointOctreeQuery

// Class Polyhedron
  pyclass_Var_Urho3D_Polyhedron
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("faces_", &Urho3D::Polyhedron::faces_, "todo: var docstring")
; // End Class Polyhedron

// Class Profiler
  pyclass_Var_Urho3D_Profiler
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Profiler

// Class ProfilerBlock
  pyclass_Var_Urho3D_ProfilerBlock
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::ProfilerBlock::name_, "todo: var docstring")
  .def_readwrite("timer_", &Urho3D::ProfilerBlock::timer_, "todo: var docstring")
  .def_readwrite("time_", &Urho3D::ProfilerBlock::time_, "todo: var docstring")
  .def_readwrite("maxTime_", &Urho3D::ProfilerBlock::maxTime_, "todo: var docstring")
  .def_readwrite("count_", &Urho3D::ProfilerBlock::count_, "todo: var docstring")
  .def_readwrite("parent_", &Urho3D::ProfilerBlock::parent_, "todo: var docstring")
  .def_readwrite("children_", &Urho3D::ProfilerBlock::children_, "todo: var docstring")
  .def_readwrite("frameTime_", &Urho3D::ProfilerBlock::frameTime_, "todo: var docstring")
  .def_readwrite("frameMaxTime_", &Urho3D::ProfilerBlock::frameMaxTime_, "todo: var docstring")
  .def_readwrite("frameCount_", &Urho3D::ProfilerBlock::frameCount_, "todo: var docstring")
  .def_readwrite("intervalTime_", &Urho3D::ProfilerBlock::intervalTime_, "todo: var docstring")
  .def_readwrite("intervalMaxTime_", &Urho3D::ProfilerBlock::intervalMaxTime_, "todo: var docstring")
  .def_readwrite("intervalCount_", &Urho3D::ProfilerBlock::intervalCount_, "todo: var docstring")
  .def_readwrite("totalTime_", &Urho3D::ProfilerBlock::totalTime_, "todo: var docstring")
  .def_readwrite("totalMaxTime_", &Urho3D::ProfilerBlock::totalMaxTime_, "todo: var docstring")
  .def_readwrite("totalCount_", &Urho3D::ProfilerBlock::totalCount_, "todo: var docstring")
; // End Class ProfilerBlock

// Class ProgressBar
  pyclass_Var_Urho3D_ProgressBar
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ProgressBar

// Class PropertySet2D
  pyclass_Var_Urho3D_PropertySet2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class PropertySet2D

// Class Quaternion
  pyclass_Var_Urho3D_Quaternion
  // Constructors
  // Methods
  // Operators
// OP operator+= len 1
      .def(py::self += Urho3D::Quaternion (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= float(), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Quaternion (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Quaternion (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Quaternion (), "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Quaternion (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Quaternion (), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector3 (), "todo: docstring")
  // Variables
  .def_readwrite("w_", &Urho3D::Quaternion::w_, "todo: var docstring")
  .def_readwrite("x_", &Urho3D::Quaternion::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::Quaternion::y_, "todo: var docstring")
  .def_readwrite("z_", &Urho3D::Quaternion::z_, "todo: var docstring")
  .def_readonly_static("IDENTITY", &Urho3D::Quaternion::IDENTITY, "todo: var docstring")
; // End Class Quaternion

// Class Ray
  pyclass_Var_Urho3D_Ray
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Ray (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Ray (), "todo: docstring")
  // Variables
  .def_readwrite("origin_", &Urho3D::Ray::origin_, "todo: var docstring")
  .def_readwrite("direction_", &Urho3D::Ray::direction_, "todo: var docstring")
; // End Class Ray

// Class RayOctreeQuery
  pyclass_Var_Urho3D_RayOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::RayOctreeQuery::result_ TODO: def_property with lambdas for it
  .def_readwrite("ray_", &Urho3D::RayOctreeQuery::ray_, "todo: var docstring")
  .def_readwrite("drawableFlags_", &Urho3D::RayOctreeQuery::drawableFlags_, "todo: var docstring")
  .def_readwrite("viewMask_", &Urho3D::RayOctreeQuery::viewMask_, "todo: var docstring")
  .def_readwrite("maxDistance_", &Urho3D::RayOctreeQuery::maxDistance_, "todo: var docstring")
  .def_readwrite("level_", &Urho3D::RayOctreeQuery::level_, "todo: var docstring")
; // End Class RayOctreeQuery

// Class RayQueryResult
  pyclass_Var_Urho3D_RayQueryResult
  // Constructors
  // Methods
  // Operators
// OP operator!= len 1
      .def(py::self != Urho3D::RayQueryResult (), "todo: docstring")
  // Variables
  .def_readwrite("position_", &Urho3D::RayQueryResult::position_, "todo: var docstring")
  .def_readwrite("normal_", &Urho3D::RayQueryResult::normal_, "todo: var docstring")
  .def_readwrite("textureUV_", &Urho3D::RayQueryResult::textureUV_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::RayQueryResult::distance_, "todo: var docstring")
  .def_readwrite("drawable_", &Urho3D::RayQueryResult::drawable_, "todo: var docstring")
  .def_readwrite("node_", &Urho3D::RayQueryResult::node_, "todo: var docstring")
  .def_readwrite("subObject_", &Urho3D::RayQueryResult::subObject_, "todo: var docstring")
; // End Class RayQueryResult

// Class RaycastVehicle
  pyclass_Var_Urho3D_RaycastVehicle
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RaycastVehicle

// Class Rect
  pyclass_Var_Urho3D_Rect
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Rect (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Rect (), "todo: docstring")
  // Variables
  .def_readwrite("min_", &Urho3D::Rect::min_, "todo: var docstring")
  .def_readwrite("max_", &Urho3D::Rect::max_, "todo: var docstring")
  .def_readonly_static("FULL", &Urho3D::Rect::FULL, "todo: var docstring")
  .def_readonly_static("POSITIVE", &Urho3D::Rect::POSITIVE, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Rect::ZERO, "todo: var docstring")
; // End Class Rect

// Class RefCount
  pyclass_Var_Urho3D_RefCount
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("refs_", &Urho3D::RefCount::refs_, "todo: var docstring")
  .def_readwrite("weakRefs_", &Urho3D::RefCount::weakRefs_, "todo: var docstring")
; // End Class RefCount

// Class RemoteEvent
  pyclass_Var_Urho3D_RemoteEvent
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("senderID_", &Urho3D::RemoteEvent::senderID_, "todo: var docstring")
  .def_readwrite("eventType_", &Urho3D::RemoteEvent::eventType_, "todo: var docstring")
  .def_readwrite("eventData_", &Urho3D::RemoteEvent::eventData_, "todo: var docstring")
  .def_readwrite("inOrder_", &Urho3D::RemoteEvent::inOrder_, "todo: var docstring")
; // End Class RemoteEvent

// Class RenderPath
  pyclass_Var_Urho3D_RenderPath
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("renderTargets_", &Urho3D::RenderPath::renderTargets_, "todo: var docstring")
  .def_readwrite("commands_", &Urho3D::RenderPath::commands_, "todo: var docstring")
; // End Class RenderPath

// Class RenderPathCommand
  pyclass_Var_Urho3D_RenderPathCommand
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("tag_", &Urho3D::RenderPathCommand::tag_, "todo: var docstring")
  .def_readwrite("type_", &Urho3D::RenderPathCommand::type_, "todo: var docstring")
  .def_readwrite("sortMode_", &Urho3D::RenderPathCommand::sortMode_, "todo: var docstring")
  .def_readwrite("pass_", &Urho3D::RenderPathCommand::pass_, "todo: var docstring")
  .def_readwrite("passIndex_", &Urho3D::RenderPathCommand::passIndex_, "todo: var docstring")
  .def_readwrite("basePath_", &Urho3D::RenderPathCommand::basePath_, "todo: var docstring")
  .def_readwrite("metadata_", &Urho3D::RenderPathCommand::metadata_, "todo: var docstring")
  .def_readwrite("vertexShaderName_", &Urho3D::RenderPathCommand::vertexShaderName_, "todo: var docstring")
  .def_readwrite("pixelShaderName_", &Urho3D::RenderPathCommand::pixelShaderName_, "todo: var docstring")
  .def_readwrite("vertexShaderDefines_", &Urho3D::RenderPathCommand::vertexShaderDefines_, "todo: var docstring")
  .def_readwrite("pixelShaderDefines_", &Urho3D::RenderPathCommand::pixelShaderDefines_, "todo: var docstring")
 // Cannot bind &Urho3D::RenderPathCommand::textureNames_ TODO: def_property with lambdas for it
  .def_readwrite("shaderParameters_", &Urho3D::RenderPathCommand::shaderParameters_, "todo: var docstring")
  .def_readwrite("outputs_", &Urho3D::RenderPathCommand::outputs_, "todo: var docstring")
  .def_readwrite("depthStencilName_", &Urho3D::RenderPathCommand::depthStencilName_, "todo: var docstring")
  .def_readwrite("clearFlags_", &Urho3D::RenderPathCommand::clearFlags_, "todo: var docstring")
  .def_readwrite("clearColor_", &Urho3D::RenderPathCommand::clearColor_, "todo: var docstring")
  .def_readwrite("clearDepth_", &Urho3D::RenderPathCommand::clearDepth_, "todo: var docstring")
  .def_readwrite("clearStencil_", &Urho3D::RenderPathCommand::clearStencil_, "todo: var docstring")
  .def_readwrite("blendMode_", &Urho3D::RenderPathCommand::blendMode_, "todo: var docstring")
  .def_readwrite("enabled_", &Urho3D::RenderPathCommand::enabled_, "todo: var docstring")
  .def_readwrite("useFogColor_", &Urho3D::RenderPathCommand::useFogColor_, "todo: var docstring")
  .def_readwrite("markToStencil_", &Urho3D::RenderPathCommand::markToStencil_, "todo: var docstring")
  .def_readwrite("useLitBase_", &Urho3D::RenderPathCommand::useLitBase_, "todo: var docstring")
  .def_readwrite("vertexLights_", &Urho3D::RenderPathCommand::vertexLights_, "todo: var docstring")
  .def_readwrite("eventName_", &Urho3D::RenderPathCommand::eventName_, "todo: var docstring")
; // End Class RenderPathCommand

// Class RenderSurface
  pyclass_Var_Urho3D_RenderSurface
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RenderSurface

// Class RenderTargetInfo
  pyclass_Var_Urho3D_RenderTargetInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("name_", &Urho3D::RenderTargetInfo::name_, "todo: var docstring")
  .def_readwrite("tag_", &Urho3D::RenderTargetInfo::tag_, "todo: var docstring")
  .def_readwrite("format_", &Urho3D::RenderTargetInfo::format_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::RenderTargetInfo::size_, "todo: var docstring")
  .def_readwrite("sizeMode_", &Urho3D::RenderTargetInfo::sizeMode_, "todo: var docstring")
  .def_readwrite("multiSample_", &Urho3D::RenderTargetInfo::multiSample_, "todo: var docstring")
  .def_readwrite("autoResolve_", &Urho3D::RenderTargetInfo::autoResolve_, "todo: var docstring")
  .def_readwrite("enabled_", &Urho3D::RenderTargetInfo::enabled_, "todo: var docstring")
  .def_readwrite("cubemap_", &Urho3D::RenderTargetInfo::cubemap_, "todo: var docstring")
  .def_readwrite("filtered_", &Urho3D::RenderTargetInfo::filtered_, "todo: var docstring")
  .def_readwrite("sRGB_", &Urho3D::RenderTargetInfo::sRGB_, "todo: var docstring")
  .def_readwrite("persistent_", &Urho3D::RenderTargetInfo::persistent_, "todo: var docstring")
; // End Class RenderTargetInfo

// Class Renderer
  pyclass_Var_Urho3D_Renderer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Renderer

// Class Renderer2D
  pyclass_Var_Urho3D_Renderer2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Renderer2D

// Class ReplicationState
  pyclass_Var_Urho3D_ReplicationState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("connection_", &Urho3D::ReplicationState::connection_, "todo: var docstring")
; // End Class ReplicationState

// Class Resource
  pyclass_Var_Urho3D_Resource
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Resource

// Class ResourceCache
  pyclass_Var_Urho3D_ResourceCache
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ResourceCache

// Class ResourceGroup
  pyclass_Var_Urho3D_ResourceGroup
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("memoryBudget_", &Urho3D::ResourceGroup::memoryBudget_, "todo: var docstring")
  .def_readwrite("memoryUse_", &Urho3D::ResourceGroup::memoryUse_, "todo: var docstring")
  .def_readwrite("resources_", &Urho3D::ResourceGroup::resources_, "todo: var docstring")
; // End Class ResourceGroup

// Class ResourceRef
  pyclass_Var_Urho3D_ResourceRef
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::ResourceRef (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::ResourceRef (), "todo: docstring")
  // Variables
  .def_readwrite("type_", &Urho3D::ResourceRef::type_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::ResourceRef::name_, "todo: var docstring")
; // End Class ResourceRef

// Class ResourceRefList
  pyclass_Var_Urho3D_ResourceRefList
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::ResourceRefList (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::ResourceRefList (), "todo: docstring")
  // Variables
  .def_readwrite("type_", &Urho3D::ResourceRefList::type_, "todo: var docstring")
  .def_readwrite("names_", &Urho3D::ResourceRefList::names_, "todo: var docstring")
; // End Class ResourceRefList

// Class ResourceRouter
  pyclass_Var_Urho3D_ResourceRouter
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ResourceRouter

// Class ResourceWithMetadata
  pyclass_Var_Urho3D_ResourceWithMetadata
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ResourceWithMetadata

// Class RibbonTrail
  pyclass_Var_Urho3D_RibbonTrail
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RibbonTrail

// Class RigidBody
  pyclass_Var_Urho3D_RigidBody
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RigidBody

// Class RigidBody2D
  pyclass_Var_Urho3D_RigidBody2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RigidBody2D

// Class Scene
  pyclass_Var_Urho3D_Scene
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Scene

// Class ScenePassInfo
  pyclass_Var_Urho3D_ScenePassInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("passIndex_", &Urho3D::ScenePassInfo::passIndex_, "todo: var docstring")
  .def_readwrite("allowInstancing_", &Urho3D::ScenePassInfo::allowInstancing_, "todo: var docstring")
  .def_readwrite("markToStencil_", &Urho3D::ScenePassInfo::markToStencil_, "todo: var docstring")
  .def_readwrite("vertexLights_", &Urho3D::ScenePassInfo::vertexLights_, "todo: var docstring")
  .def_readwrite("batchQueue_", &Urho3D::ScenePassInfo::batchQueue_, "todo: var docstring")
; // End Class ScenePassInfo

// Class SceneReplicationState
  pyclass_Var_Urho3D_SceneReplicationState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("nodeStates_", &Urho3D::SceneReplicationState::nodeStates_, "todo: var docstring")
  .def_readwrite("dirtyNodes_", &Urho3D::SceneReplicationState::dirtyNodes_, "todo: var docstring")
; // End Class SceneReplicationState

// Class SceneResolver
  pyclass_Var_Urho3D_SceneResolver
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SceneResolver

// Class ScratchBuffer
  pyclass_Var_Urho3D_ScratchBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("data_", &Urho3D::ScratchBuffer::data_, "todo: var docstring")
  .def_readwrite("size_", &Urho3D::ScratchBuffer::size_, "todo: var docstring")
  .def_readwrite("reserved_", &Urho3D::ScratchBuffer::reserved_, "todo: var docstring")
; // End Class ScratchBuffer

// Class Script
  pyclass_Var_Urho3D_Script
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Script

// Class ScriptEventInvoker
  pyclass_Var_Urho3D_ScriptEventInvoker
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScriptEventInvoker

// Class ScriptEventListener
  pyclass_Var_Urho3D_ScriptEventListener
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScriptEventListener

// Class ScriptFile
  pyclass_Var_Urho3D_ScriptFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScriptFile

// Class Serializable
  pyclass_Var_Urho3D_Serializable
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Serializable

// Class ScriptInstance
  pyclass_Var_Urho3D_ScriptInstance
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScriptInstance

// Class ScrollBar
  pyclass_Var_Urho3D_ScrollBar
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScrollBar

// Class ScrollView
  pyclass_Var_Urho3D_ScrollView
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ScrollView

// Class Serializer
  pyclass_Var_Urho3D_Serializer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Serializer

// Class Shader
  pyclass_Var_Urho3D_Shader
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Shader

// Class ShaderParameter
  pyclass_Var_Urho3D_ShaderParameter
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("type_", &Urho3D::ShaderParameter::type_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::ShaderParameter::name_, "todo: var docstring")
  .def_readwrite("buffer_", &Urho3D::ShaderParameter::buffer_, "todo: var docstring")
  .def_readwrite("bufferPtr_", &Urho3D::ShaderParameter::bufferPtr_, "todo: var docstring")
; // End Class ShaderParameter

// Class ShaderParameterAnimationInfo
  pyclass_Var_Urho3D_ShaderParameterAnimationInfo
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ShaderParameterAnimationInfo

// Class ShaderPrecache
  pyclass_Var_Urho3D_ShaderPrecache
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ShaderPrecache

// Class ShaderProgram
  pyclass_Var_Urho3D_ShaderProgram
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ShaderProgram

// Class ShaderVariation
  pyclass_Var_Urho3D_ShaderVariation
  // Constructors
  // Methods
  // Operators
  // Variables
 // Cannot bind &Urho3D::ShaderVariation::elementSemanticNames TODO: def_property with lambdas for it
; // End Class ShaderVariation

// Class ShadowBatchQueue
  pyclass_Var_Urho3D_ShadowBatchQueue
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("shadowCamera_", &Urho3D::ShadowBatchQueue::shadowCamera_, "todo: var docstring")
  .def_readwrite("shadowViewport_", &Urho3D::ShadowBatchQueue::shadowViewport_, "todo: var docstring")
  .def_readwrite("shadowBatches_", &Urho3D::ShadowBatchQueue::shadowBatches_, "todo: var docstring")
  .def_readwrite("nearSplit_", &Urho3D::ShadowBatchQueue::nearSplit_, "todo: var docstring")
  .def_readwrite("farSplit_", &Urho3D::ShadowBatchQueue::farSplit_, "todo: var docstring")
; // End Class ShadowBatchQueue

// Class SimpleNavBuildData
  pyclass_Var_Urho3D_SimpleNavBuildData
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("contourSet_", &Urho3D::SimpleNavBuildData::contourSet_, "todo: var docstring")
//  .def_readwrite("polyMesh_", &Urho3D::SimpleNavBuildData::polyMesh_, "todo: var docstring")
//  .def_readwrite("polyMeshDetail_", &Urho3D::SimpleNavBuildData::polyMeshDetail_, "todo: var docstring")
; // End Class SimpleNavBuildData

// Class Skeleton
  pyclass_Var_Urho3D_Skeleton
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Skeleton

// Class Skybox
  pyclass_Var_Urho3D_Skybox
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Skybox

// Class Slider
  pyclass_Var_Urho3D_Slider
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Slider

// Class SmoothedTransform
  pyclass_Var_Urho3D_SmoothedTransform
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SmoothedTransform

// Class Sound
  pyclass_Var_Urho3D_Sound
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Sound

// Class SoundListener
  pyclass_Var_Urho3D_SoundListener
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SoundListener

// Class SoundSource
  pyclass_Var_Urho3D_SoundSource
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SoundSource

// Class SoundSource3D
  pyclass_Var_Urho3D_SoundSource3D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SoundSource3D

// Class SoundStream
  pyclass_Var_Urho3D_SoundStream
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SoundStream

// Class SourceBatch
  pyclass_Var_Urho3D_SourceBatch
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("distance_", &Urho3D::SourceBatch::distance_, "todo: var docstring")
  .def_readwrite("geometry_", &Urho3D::SourceBatch::geometry_, "todo: var docstring")
  .def_readwrite("material_", &Urho3D::SourceBatch::material_, "todo: var docstring")
  .def_readwrite("worldTransform_", &Urho3D::SourceBatch::worldTransform_, "todo: var docstring")
  .def_readwrite("numWorldTransforms_", &Urho3D::SourceBatch::numWorldTransforms_, "todo: var docstring")
  .def_readwrite("instancingData_", &Urho3D::SourceBatch::instancingData_, "todo: var docstring")
  .def_readwrite("geometryType_", &Urho3D::SourceBatch::geometryType_, "todo: var docstring")
; // End Class SourceBatch

// Class SourceBatch2D
  pyclass_Var_Urho3D_SourceBatch2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("owner_", &Urho3D::SourceBatch2D::owner_, "todo: var docstring")
  .def_readwrite("distance_", &Urho3D::SourceBatch2D::distance_, "todo: var docstring")
  .def_readwrite("drawOrder_", &Urho3D::SourceBatch2D::drawOrder_, "todo: var docstring")
  .def_readwrite("material_", &Urho3D::SourceBatch2D::material_, "todo: var docstring")
  .def_readwrite("vertices_", &Urho3D::SourceBatch2D::vertices_, "todo: var docstring")
; // End Class SourceBatch2D

// Class Sphere
  pyclass_Var_Urho3D_Sphere
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Sphere (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Sphere (), "todo: docstring")
  // Variables
  .def_readwrite("center_", &Urho3D::Sphere::center_, "todo: var docstring")
  .def_readwrite("radius_", &Urho3D::Sphere::radius_, "todo: var docstring")
; // End Class Sphere

// Class SphereOctreeQuery
  pyclass_Var_Urho3D_SphereOctreeQuery
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("sphere_", &Urho3D::SphereOctreeQuery::sphere_, "todo: var docstring")
; // End Class SphereOctreeQuery

// Class Spline
  pyclass_Var_Urho3D_Spline
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Spline (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Spline (), "todo: docstring")
  // Variables
; // End Class Spline

// Class SplinePath
  pyclass_Var_Urho3D_SplinePath
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SplinePath

// Class Sprite
  pyclass_Var_Urho3D_Sprite
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Sprite

// Class Sprite2D
  pyclass_Var_Urho3D_Sprite2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Sprite2D

// Class SpriteSheet2D
  pyclass_Var_Urho3D_SpriteSheet2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SpriteSheet2D

// Class StaticModel
  pyclass_Var_Urho3D_StaticModel
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class StaticModel

// Class StaticModelGeometryData
  pyclass_Var_Urho3D_StaticModelGeometryData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("center_", &Urho3D::StaticModelGeometryData::center_, "todo: var docstring")
  .def_readwrite("lodLevel_", &Urho3D::StaticModelGeometryData::lodLevel_, "todo: var docstring")
; // End Class StaticModelGeometryData

// Class StaticModelGroup
  pyclass_Var_Urho3D_StaticModelGroup
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class StaticModelGroup

// Class StaticSprite2D
  pyclass_Var_Urho3D_StaticSprite2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class StaticSprite2D

// Class StoredLogMessage
  pyclass_Var_Urho3D_StoredLogMessage
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("message_", &Urho3D::StoredLogMessage::message_, "todo: var docstring")
  .def_readwrite("level_", &Urho3D::StoredLogMessage::level_, "todo: var docstring")
  .def_readwrite("error_", &Urho3D::StoredLogMessage::error_, "todo: var docstring")
; // End Class StoredLogMessage

// Class String
  pyclass_Var_Urho3D_String
  // Constructors
  // Methods
  // Operators
// OP operator+= len 1
      .def(py::self += Urho3D::String (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += ((const char *)0), "todo: docstring")
// OP operator+= len 1
      .def(py::self += char(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += int(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += short(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += long(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += longlong(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += unsignedint(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += unsignedshort(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += unsignedlong(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += unsignedlonglong(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += float(), "todo: docstring")
// OP operator+= len 1
      .def(py::self += bool(), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::String (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + ((char *)0), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::String (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::String (), "todo: docstring")
// OP operator< len 1
      .def(py::self < Urho3D::String (), "todo: docstring")
// OP operator> len 1
      .def(py::self > Urho3D::String (), "todo: docstring")
// OP operator== len 1
      .def(py::self == ((char *)0), "todo: docstring")
// OP operator!= len 1
      .def(py::self != ((char *)0), "todo: docstring")
// OP operator< len 1
      .def(py::self < ((char *)0), "todo: docstring")
// OP operator> len 1
      .def(py::self > ((char *)0), "todo: docstring")
// OP operator[] len 1
  .def("__getitem__",[]( Urho3D::String& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
  .def("__getitem__",[](const Urho3D::String& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
  // Variables
  .def_readonly_static("NPOS", &Urho3D::String::NPOS, "todo: var docstring")
  .def_readonly_static("MIN_CAPACITY", &Urho3D::String::MIN_CAPACITY, "todo: var docstring")
  .def_readonly_static("EMPTY", &Urho3D::String::EMPTY, "todo: var docstring")
; // End Class String

// Class StringHash
  pyclass_Var_Urho3D_StringHash
  // Constructors
  // Methods
  // Operators
// OP operator+ len 1
      .def(py::self + Urho3D::StringHash (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::StringHash (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::StringHash (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::StringHash (), "todo: docstring")
// OP operator< len 1
      .def(py::self < Urho3D::StringHash (), "todo: docstring")
// OP operator> len 1
      .def(py::self > Urho3D::StringHash (), "todo: docstring")
  // Variables
  .def_readonly_static("ZERO", &Urho3D::StringHash::ZERO, "todo: var docstring")
; // End Class StringHash

// Class Technique
  pyclass_Var_Urho3D_Technique
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite_static("basePassIndex", &Urho3D::Technique::basePassIndex, "todo: var docstring")
  .def_readwrite_static("alphaPassIndex", &Urho3D::Technique::alphaPassIndex, "todo: var docstring")
  .def_readwrite_static("materialPassIndex", &Urho3D::Technique::materialPassIndex, "todo: var docstring")
  .def_readwrite_static("deferredPassIndex", &Urho3D::Technique::deferredPassIndex, "todo: var docstring")
  .def_readwrite_static("lightPassIndex", &Urho3D::Technique::lightPassIndex, "todo: var docstring")
  .def_readwrite_static("litBasePassIndex", &Urho3D::Technique::litBasePassIndex, "todo: var docstring")
  .def_readwrite_static("litAlphaPassIndex", &Urho3D::Technique::litAlphaPassIndex, "todo: var docstring")
  .def_readwrite_static("shadowPassIndex", &Urho3D::Technique::shadowPassIndex, "todo: var docstring")
; // End Class Technique

// Class TechniqueEntry
  pyclass_Var_Urho3D_TechniqueEntry
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("technique_", &Urho3D::TechniqueEntry::technique_, "todo: var docstring")
  .def_readwrite("original_", &Urho3D::TechniqueEntry::original_, "todo: var docstring")
  .def_readwrite("qualityLevel_", &Urho3D::TechniqueEntry::qualityLevel_, "todo: var docstring")
  .def_readwrite("lodDistance_", &Urho3D::TechniqueEntry::lodDistance_, "todo: var docstring")
; // End Class TechniqueEntry

// Class Terrain
  pyclass_Var_Urho3D_Terrain
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Terrain

// Class TerrainPatch
  pyclass_Var_Urho3D_TerrainPatch
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TerrainPatch

// Class Text
  pyclass_Var_Urho3D_Text
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Text

// Class Text3D
  pyclass_Var_Urho3D_Text3D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Text3D

// Class Texture
  pyclass_Var_Urho3D_Texture
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Texture

// Class Texture2D
  pyclass_Var_Urho3D_Texture2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Texture2D

// Class Texture2DArray
  pyclass_Var_Urho3D_Texture2DArray
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Texture2DArray

// Class Texture3D
  pyclass_Var_Urho3D_Texture3D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Texture3D

// Class TextureCube
  pyclass_Var_Urho3D_TextureCube
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TextureCube

// Class TextureFrame
  pyclass_Var_Urho3D_TextureFrame
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("uv_", &Urho3D::TextureFrame::uv_, "todo: var docstring")
  .def_readwrite("time_", &Urho3D::TextureFrame::time_, "todo: var docstring")
; // End Class TextureFrame

// Class Thread
  pyclass_Var_Urho3D_Thread
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Thread

// Class Tile2D
  pyclass_Var_Urho3D_Tile2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Tile2D

// Class TileMap2D
  pyclass_Var_Urho3D_TileMap2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TileMap2D

// Class TileMapInfo2D
  pyclass_Var_Urho3D_TileMapInfo2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("orientation_", &Urho3D::TileMapInfo2D::orientation_, "todo: var docstring")
  .def_readwrite("width_", &Urho3D::TileMapInfo2D::width_, "todo: var docstring")
  .def_readwrite("height_", &Urho3D::TileMapInfo2D::height_, "todo: var docstring")
  .def_readwrite("tileWidth_", &Urho3D::TileMapInfo2D::tileWidth_, "todo: var docstring")
  .def_readwrite("tileHeight_", &Urho3D::TileMapInfo2D::tileHeight_, "todo: var docstring")
; // End Class TileMapInfo2D

// Class TileMapLayer2D
  pyclass_Var_Urho3D_TileMapLayer2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TileMapLayer2D

// Class TileMapObject2D
  pyclass_Var_Urho3D_TileMapObject2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TileMapObject2D

// Class Time
  pyclass_Var_Urho3D_Time
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Time

// Class Timer
  pyclass_Var_Urho3D_Timer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Timer

// Class TmxFile2D
  pyclass_Var_Urho3D_TmxFile2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TmxFile2D

// Class TmxLayer2D
  pyclass_Var_Urho3D_TmxLayer2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TmxLayer2D

// Class TmxImageLayer2D
  pyclass_Var_Urho3D_TmxImageLayer2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TmxImageLayer2D

// Class TmxObjectGroup2D
  pyclass_Var_Urho3D_TmxObjectGroup2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TmxObjectGroup2D

// Class TmxTileLayer2D
  pyclass_Var_Urho3D_TmxTileLayer2D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TmxTileLayer2D

// Class ToolTip
  pyclass_Var_Urho3D_ToolTip
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ToolTip

// Class TouchState
  pyclass_Var_Urho3D_TouchState
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("touchID_", &Urho3D::TouchState::touchID_, "todo: var docstring")
  .def_readwrite("position_", &Urho3D::TouchState::position_, "todo: var docstring")
  .def_readwrite("lastPosition_", &Urho3D::TouchState::lastPosition_, "todo: var docstring")
  .def_readwrite("delta_", &Urho3D::TouchState::delta_, "todo: var docstring")
  .def_readwrite("pressure_", &Urho3D::TouchState::pressure_, "todo: var docstring")
  .def_readwrite("touchedElement_", &Urho3D::TouchState::touchedElement_, "todo: var docstring")
; // End Class TouchState

// Class TrailPoint
  pyclass_Var_Urho3D_TrailPoint
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::TrailPoint::position_, "todo: var docstring")
  .def_readwrite("forward_", &Urho3D::TrailPoint::forward_, "todo: var docstring")
  .def_readwrite("parentPos_", &Urho3D::TrailPoint::parentPos_, "todo: var docstring")
  .def_readwrite("elapsedLength_", &Urho3D::TrailPoint::elapsedLength_, "todo: var docstring")
  .def_readwrite("next_", &Urho3D::TrailPoint::next_, "todo: var docstring")
  .def_readwrite("lifetime_", &Urho3D::TrailPoint::lifetime_, "todo: var docstring")
  .def_readwrite("sortDistance_", &Urho3D::TrailPoint::sortDistance_, "todo: var docstring")
; // End Class TrailPoint

// Class TriangleMeshData
  pyclass_Var_Urho3D_TriangleMeshData
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("meshInterface_", &Urho3D::TriangleMeshData::meshInterface_, "todo: var docstring")
//  .def_readwrite("shape_", &Urho3D::TriangleMeshData::shape_, "todo: var docstring")
//  .def_readwrite("infoMap_", &Urho3D::TriangleMeshData::infoMap_, "todo: var docstring")
; // End Class TriangleMeshData

// Class TypeInfo
  pyclass_Var_Urho3D_TypeInfo
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class TypeInfo

// Class UI
  pyclass_Var_Urho3D_UI
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class UI

// Class DragData
  pyclass_Var_Urho3D_UI_DragData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("dragButtons", &Urho3D::UI::DragData::dragButtons, "todo: var docstring")
  .def_readwrite("numDragButtons", &Urho3D::UI::DragData::numDragButtons, "todo: var docstring")
  .def_readwrite("sumPos", &Urho3D::UI::DragData::sumPos, "todo: var docstring")
  .def_readwrite("dragBeginPending", &Urho3D::UI::DragData::dragBeginPending, "todo: var docstring")
  .def_readwrite("dragBeginTimer", &Urho3D::UI::DragData::dragBeginTimer, "todo: var docstring")
  .def_readwrite("dragBeginSumPos", &Urho3D::UI::DragData::dragBeginSumPos, "todo: var docstring")
; // End Class DragData

// Class UIBatch
  pyclass_Var_Urho3D_UIBatch
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("element_", &Urho3D::UIBatch::element_, "todo: var docstring")
  .def_readwrite("blendMode_", &Urho3D::UIBatch::blendMode_, "todo: var docstring")
  .def_readwrite("scissor_", &Urho3D::UIBatch::scissor_, "todo: var docstring")
  .def_readwrite("texture_", &Urho3D::UIBatch::texture_, "todo: var docstring")
  .def_readwrite("invTextureSize_", &Urho3D::UIBatch::invTextureSize_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::UIBatch::color_, "todo: var docstring")
  .def_readwrite("vertexData_", &Urho3D::UIBatch::vertexData_, "todo: var docstring")
  .def_readwrite("vertexStart_", &Urho3D::UIBatch::vertexStart_, "todo: var docstring")
  .def_readwrite("vertexEnd_", &Urho3D::UIBatch::vertexEnd_, "todo: var docstring")
  .def_readwrite("useGradient_", &Urho3D::UIBatch::useGradient_, "todo: var docstring")
  .def_readwrite_static("posAdjust", &Urho3D::UIBatch::posAdjust, "todo: var docstring")
; // End Class UIBatch

// Class UIElement
  pyclass_Var_Urho3D_UIElement
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class UIElement

// Class UnknownComponent
  pyclass_Var_Urho3D_UnknownComponent
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class UnknownComponent

// Class VAnimEventFrame
  pyclass_Var_Urho3D_VAnimEventFrame
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("time_", &Urho3D::VAnimEventFrame::time_, "todo: var docstring")
  .def_readwrite("eventType_", &Urho3D::VAnimEventFrame::eventType_, "todo: var docstring")
  .def_readwrite("eventData_", &Urho3D::VAnimEventFrame::eventData_, "todo: var docstring")
; // End Class VAnimEventFrame

// Class VAnimKeyFrame
  pyclass_Var_Urho3D_VAnimKeyFrame
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("time_", &Urho3D::VAnimKeyFrame::time_, "todo: var docstring")
  .def_readwrite("value_", &Urho3D::VAnimKeyFrame::value_, "todo: var docstring")
; // End Class VAnimKeyFrame

// Class ValueAnimation
  pyclass_Var_Urho3D_ValueAnimation
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ValueAnimation

// Class ValueAnimationInfo
  pyclass_Var_Urho3D_ValueAnimationInfo
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class ValueAnimationInfo

// Class Variant
  pyclass_Var_Urho3D_Variant
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Variant (), "todo: docstring")
// OP operator== len 1
      .def(py::self == int(), "todo: docstring")
// OP operator== len 1
      .def(py::self == unsignedint(), "todo: docstring")
// OP operator== len 1
      .def(py::self == longlong(), "todo: docstring")
// OP operator== len 1
      .def(py::self == unsignedlonglong(), "todo: docstring")
// OP operator== len 1
      .def(py::self == bool(), "todo: docstring")
// OP operator== len 1
      .def(py::self == float(), "todo: docstring")
// OP operator== len 1
      .def(py::self == double(), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Vector2 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Vector3 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Vector4 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Quaternion (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Color (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::String (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::PODVector<unsigned char> (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::VectorBuffer (), "todo: docstring")
// OP operator== len 1
      .def(py::self == ((void *)0), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::ResourceRef (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::ResourceRefList (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Vector<Urho3D::Variant> (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Vector<Urho3D::String> (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::HashMap<Urho3D::StringHash, Urho3D::Variant> (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Rect (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::IntRect (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::IntVector2 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::IntVector3 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::StringHash (), "todo: docstring")
// OP operator== len 1
      .def(py::self == ((Urho3D::RefCounted *)0), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Matrix3 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator== len 1
      .def(py::self == Urho3D::Matrix4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Variant (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != int(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != unsignedint(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != longlong(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != unsignedlonglong(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != bool(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != float(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != double(), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector2 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Quaternion (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::String (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::PODVector<unsigned char> (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::VectorBuffer (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != ((void *)0), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::ResourceRef (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::ResourceRefList (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector<Urho3D::Variant> (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector<Urho3D::String> (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::HashMap<Urho3D::StringHash, Urho3D::Variant> (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Rect (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntRect (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntVector2 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::IntVector3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::StringHash (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != ((Urho3D::RefCounted *)0), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix3x4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Matrix4 (), "todo: docstring")
  // Variables
  .def_readonly_static("EMPTY", &Urho3D::Variant::EMPTY, "todo: var docstring")
  .def_readonly_static("emptyBuffer", &Urho3D::Variant::emptyBuffer, "todo: var docstring")
  .def_readonly_static("emptyResourceRef", &Urho3D::Variant::emptyResourceRef, "todo: var docstring")
  .def_readonly_static("emptyResourceRefList", &Urho3D::Variant::emptyResourceRefList, "todo: var docstring")
  .def_readonly_static("emptyVariantMap", &Urho3D::Variant::emptyVariantMap, "todo: var docstring")
  .def_readonly_static("emptyVariantVector", &Urho3D::Variant::emptyVariantVector, "todo: var docstring")
  .def_readonly_static("emptyStringVector", &Urho3D::Variant::emptyStringVector, "todo: var docstring")
; // End Class Variant

// Class VariantValue
  pyclass_Var_Urho3D_VariantValue
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class VariantValue

// Class Vector2
  pyclass_Var_Urho3D_Vector2
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Vector2 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector2 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Vector2 (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Vector2 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector2 (), "todo: docstring")
// OP operator/ len 1
      .def(py::self / float(), "todo: docstring")
// OP operator/ len 1
      .def(py::self / Urho3D::Vector2 (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::Vector2 (), "todo: docstring")
// OP operator-= len 1
      .def(py::self -= Urho3D::Vector2 (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= float(), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= Urho3D::Vector2 (), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= float(), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= Urho3D::Vector2 (), "todo: docstring")
  // Variables
  .def_readwrite("x_", &Urho3D::Vector2::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::Vector2::y_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Vector2::ZERO, "todo: var docstring")
  .def_readonly_static("LEFT", &Urho3D::Vector2::LEFT, "todo: var docstring")
  .def_readonly_static("RIGHT", &Urho3D::Vector2::RIGHT, "todo: var docstring")
  .def_readonly_static("UP", &Urho3D::Vector2::UP, "todo: var docstring")
  .def_readonly_static("DOWN", &Urho3D::Vector2::DOWN, "todo: var docstring")
  .def_readonly_static("ONE", &Urho3D::Vector2::ONE, "todo: var docstring")
; // End Class Vector2

// Class Vector3
  pyclass_Var_Urho3D_Vector3
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Vector3 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector3 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Vector3 (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Vector3 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector3 (), "todo: docstring")
// OP operator/ len 1
      .def(py::self / float(), "todo: docstring")
// OP operator/ len 1
      .def(py::self / Urho3D::Vector3 (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::Vector3 (), "todo: docstring")
// OP operator-= len 1
      .def(py::self -= Urho3D::Vector3 (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= float(), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= Urho3D::Vector3 (), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= float(), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= Urho3D::Vector3 (), "todo: docstring")
  // Variables
  .def_readwrite("x_", &Urho3D::Vector3::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::Vector3::y_, "todo: var docstring")
  .def_readwrite("z_", &Urho3D::Vector3::z_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Vector3::ZERO, "todo: var docstring")
  .def_readonly_static("LEFT", &Urho3D::Vector3::LEFT, "todo: var docstring")
  .def_readonly_static("RIGHT", &Urho3D::Vector3::RIGHT, "todo: var docstring")
  .def_readonly_static("UP", &Urho3D::Vector3::UP, "todo: var docstring")
  .def_readonly_static("DOWN", &Urho3D::Vector3::DOWN, "todo: var docstring")
  .def_readonly_static("FORWARD", &Urho3D::Vector3::FORWARD, "todo: var docstring")
  .def_readonly_static("BACK", &Urho3D::Vector3::BACK, "todo: var docstring")
  .def_readonly_static("ONE", &Urho3D::Vector3::ONE, "todo: var docstring")
; // End Class Vector3

// Class Vector4
  pyclass_Var_Urho3D_Vector4
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::Vector4 (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::Vector4 (), "todo: docstring")
// OP operator+ len 1
      .def(py::self + Urho3D::Vector4 (), "todo: docstring")
// OP operator- len 0
  .def(-py::self, "todo: docstring")
// OP operator- len 1
      .def(py::self - Urho3D::Vector4 (), "todo: docstring")
// OP operator* len 1
      .def(py::self * float(), "todo: docstring")
// OP operator* len 1
      .def(py::self * Urho3D::Vector4 (), "todo: docstring")
// OP operator/ len 1
      .def(py::self / float(), "todo: docstring")
// OP operator/ len 1
      .def(py::self / Urho3D::Vector4 (), "todo: docstring")
// OP operator+= len 1
      .def(py::self += Urho3D::Vector4 (), "todo: docstring")
// OP operator-= len 1
      .def(py::self -= Urho3D::Vector4 (), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= float(), "todo: docstring")
// OP operator*= len 1
      .def(py::self *= Urho3D::Vector4 (), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= float(), "todo: docstring")
// OP operator/= len 1
      .def(py::self /= Urho3D::Vector4 (), "todo: docstring")
  // Variables
  .def_readwrite("x_", &Urho3D::Vector4::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::Vector4::y_, "todo: var docstring")
  .def_readwrite("z_", &Urho3D::Vector4::z_, "todo: var docstring")
  .def_readwrite("w_", &Urho3D::Vector4::w_, "todo: var docstring")
  .def_readonly_static("ZERO", &Urho3D::Vector4::ZERO, "todo: var docstring")
  .def_readonly_static("ONE", &Urho3D::Vector4::ONE, "todo: var docstring")
; // End Class Vector4

// Class VectorBase
  pyclass_Var_Urho3D_VectorBase
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class VectorBase

// Class VectorBuffer
  pyclass_Var_Urho3D_VectorBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class VectorBuffer

// Class Vertex2D
  pyclass_Var_Urho3D_Vertex2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("position_", &Urho3D::Vertex2D::position_, "todo: var docstring")
  .def_readwrite("color_", &Urho3D::Vertex2D::color_, "todo: var docstring")
  .def_readwrite("uv_", &Urho3D::Vertex2D::uv_, "todo: var docstring")
; // End Class Vertex2D

// Class VertexBuffer
  pyclass_Var_Urho3D_VertexBuffer
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class VertexBuffer

// Class VertexBufferDesc
  pyclass_Var_Urho3D_VertexBufferDesc
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("vertexCount_", &Urho3D::VertexBufferDesc::vertexCount_, "todo: var docstring")
  .def_readwrite("vertexElements_", &Urho3D::VertexBufferDesc::vertexElements_, "todo: var docstring")
  .def_readwrite("dataSize_", &Urho3D::VertexBufferDesc::dataSize_, "todo: var docstring")
  .def_readwrite("data_", &Urho3D::VertexBufferDesc::data_, "todo: var docstring")
; // End Class VertexBufferDesc

// Class VertexBufferMorph
  pyclass_Var_Urho3D_VertexBufferMorph
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("elementMask_", &Urho3D::VertexBufferMorph::elementMask_, "todo: var docstring")
  .def_readwrite("vertexCount_", &Urho3D::VertexBufferMorph::vertexCount_, "todo: var docstring")
  .def_readwrite("dataSize_", &Urho3D::VertexBufferMorph::dataSize_, "todo: var docstring")
  .def_readwrite("morphData_", &Urho3D::VertexBufferMorph::morphData_, "todo: var docstring")
; // End Class VertexBufferMorph

// Class VertexElement
  pyclass_Var_Urho3D_VertexElement
  // Constructors
  // Methods
  // Operators
// OP operator== len 1
      .def(py::self == Urho3D::VertexElement (), "todo: docstring")
// OP operator!= len 1
      .def(py::self != Urho3D::VertexElement (), "todo: docstring")
  // Variables
  .def_readwrite("type_", &Urho3D::VertexElement::type_, "todo: var docstring")
  .def_readwrite("semantic_", &Urho3D::VertexElement::semantic_, "todo: var docstring")
  .def_readwrite("index_", &Urho3D::VertexElement::index_, "todo: var docstring")
  .def_readwrite("perInstance_", &Urho3D::VertexElement::perInstance_, "todo: var docstring")
  .def_readwrite("offset_", &Urho3D::VertexElement::offset_, "todo: var docstring")
; // End Class VertexElement

// Class View
  pyclass_Var_Urho3D_View
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class View

// Class Window
  pyclass_Var_Urho3D_Window
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Window

// Class View3D
  pyclass_Var_Urho3D_View3D
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class View3D

// Class ViewBatchInfo2D
  pyclass_Var_Urho3D_ViewBatchInfo2D
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("vertexBufferUpdateFrameNumber_", &Urho3D::ViewBatchInfo2D::vertexBufferUpdateFrameNumber_, "todo: var docstring")
  .def_readwrite("indexCount_", &Urho3D::ViewBatchInfo2D::indexCount_, "todo: var docstring")
  .def_readwrite("vertexCount_", &Urho3D::ViewBatchInfo2D::vertexCount_, "todo: var docstring")
  .def_readwrite("vertexBuffer_", &Urho3D::ViewBatchInfo2D::vertexBuffer_, "todo: var docstring")
  .def_readwrite("batchUpdatedFrameNumber_", &Urho3D::ViewBatchInfo2D::batchUpdatedFrameNumber_, "todo: var docstring")
  .def_readwrite("sourceBatches_", &Urho3D::ViewBatchInfo2D::sourceBatches_, "todo: var docstring")
  .def_readwrite("batchCount_", &Urho3D::ViewBatchInfo2D::batchCount_, "todo: var docstring")
  .def_readwrite("distances_", &Urho3D::ViewBatchInfo2D::distances_, "todo: var docstring")
  .def_readwrite("materials_", &Urho3D::ViewBatchInfo2D::materials_, "todo: var docstring")
  .def_readwrite("geometries_", &Urho3D::ViewBatchInfo2D::geometries_, "todo: var docstring")
; // End Class ViewBatchInfo2D

// Class Viewport
  pyclass_Var_Urho3D_Viewport
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Viewport

// Class WString
  pyclass_Var_Urho3D_WString
  // Constructors
  // Methods
  // Operators
// OP operator[] len 1
  .def("__getitem__",[]( Urho3D::WString& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
// OP operator[] len 1
  .def("__getitem__",[](const Urho3D::WString& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
  // Variables
; // End Class WString

// Class WorkItem
  pyclass_Var_Urho3D_WorkItem
  // Constructors
  // Methods
  // Operators
  // Variables
//  .def_readwrite("workFunction_", &Urho3D::WorkItem::workFunction_, "todo: var docstring")
  .def_readwrite("start_", &Urho3D::WorkItem::start_, "todo: var docstring")
  .def_readwrite("end_", &Urho3D::WorkItem::end_, "todo: var docstring")
  .def_readwrite("aux_", &Urho3D::WorkItem::aux_, "todo: var docstring")
  .def_readwrite("priority_", &Urho3D::WorkItem::priority_, "todo: var docstring")
  .def_readwrite("sendEvent_", &Urho3D::WorkItem::sendEvent_, "todo: var docstring")
  .def_readwrite("completed_", &Urho3D::WorkItem::completed_, "todo: var docstring")
; // End Class WorkItem

// Class WorkQueue
  pyclass_Var_Urho3D_WorkQueue
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class WorkQueue

// Class XMLElement
  pyclass_Var_Urho3D_XMLElement
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readonly_static("EMPTY", &Urho3D::XMLElement::EMPTY, "todo: var docstring")
; // End Class XMLElement

// Class XMLFile
  pyclass_Var_Urho3D_XMLFile
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class XMLFile

// Class XPathQuery
  pyclass_Var_Urho3D_XPathQuery
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class XPathQuery

// Class XPathResultSet
  pyclass_Var_Urho3D_XPathResultSet
  // Constructors
  // Methods
  // Operators
// OP operator[] len 1
  .def("__getitem__",[](const Urho3D::XPathResultSet& arg0, unsigned int arg1) { return arg0[arg0, arg1];}, "todo: docstring, argnames", py::is_operator())
  // Variables
; // End Class XPathResultSet

// Class Zone
  pyclass_Var_Urho3D_Zone
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class Zone

//-------------------------------------------
// Export AnimationFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAnimationFinished {};

auto pyclass_NS__Urho3D_AnimationFinished = py::class_<PythonBindingsFakeModuleUrho3DAnimationFinished>(m, "AnimationFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::AnimationFinished::P_NODE, "todo: var docstring")
  .def_readonly_static("P_ANIMATION", &::Urho3D::AnimationFinished::P_ANIMATION, "todo: var docstring")
  .def_readonly_static("P_NAME", &::Urho3D::AnimationFinished::P_NAME, "todo: var docstring")
  .def_readonly_static("P_LOOPED", &::Urho3D::AnimationFinished::P_LOOPED, "todo: var docstring")
; // End Namespace Class AnimationFinished
  // Namespace vars class AnimationFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AnimationTrigger namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAnimationTrigger {};

auto pyclass_NS__Urho3D_AnimationTrigger = py::class_<PythonBindingsFakeModuleUrho3DAnimationTrigger>(m, "AnimationTrigger")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::AnimationTrigger::P_NODE, "todo: var docstring")
  .def_readonly_static("P_ANIMATION", &::Urho3D::AnimationTrigger::P_ANIMATION, "todo: var docstring")
  .def_readonly_static("P_NAME", &::Urho3D::AnimationTrigger::P_NAME, "todo: var docstring")
  .def_readonly_static("P_TIME", &::Urho3D::AnimationTrigger::P_TIME, "todo: var docstring")
  .def_readonly_static("P_DATA", &::Urho3D::AnimationTrigger::P_DATA, "todo: var docstring")
; // End Namespace Class AnimationTrigger
  // Namespace vars class AnimationTrigger

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AsyncExecFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAsyncExecFinished {};

auto pyclass_NS__Urho3D_AsyncExecFinished = py::class_<PythonBindingsFakeModuleUrho3DAsyncExecFinished>(m, "AsyncExecFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_REQUESTID", &::Urho3D::AsyncExecFinished::P_REQUESTID, "todo: var docstring")
  .def_readonly_static("P_EXITCODE", &::Urho3D::AsyncExecFinished::P_EXITCODE, "todo: var docstring")
; // End Namespace Class AsyncExecFinished
  // Namespace vars class AsyncExecFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AsyncLoadFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAsyncLoadFinished {};

auto pyclass_NS__Urho3D_AsyncLoadFinished = py::class_<PythonBindingsFakeModuleUrho3DAsyncLoadFinished>(m, "AsyncLoadFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::AsyncLoadFinished::P_SCENE, "todo: var docstring")
; // End Namespace Class AsyncLoadFinished
  // Namespace vars class AsyncLoadFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AsyncLoadProgress namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAsyncLoadProgress {};

auto pyclass_NS__Urho3D_AsyncLoadProgress = py::class_<PythonBindingsFakeModuleUrho3DAsyncLoadProgress>(m, "AsyncLoadProgress")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::AsyncLoadProgress::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_PROGRESS", &::Urho3D::AsyncLoadProgress::P_PROGRESS, "todo: var docstring")
  .def_readonly_static("P_LOADEDNODES", &::Urho3D::AsyncLoadProgress::P_LOADEDNODES, "todo: var docstring")
  .def_readonly_static("P_TOTALNODES", &::Urho3D::AsyncLoadProgress::P_TOTALNODES, "todo: var docstring")
  .def_readonly_static("P_LOADEDRESOURCES", &::Urho3D::AsyncLoadProgress::P_LOADEDRESOURCES, "todo: var docstring")
  .def_readonly_static("P_TOTALRESOURCES", &::Urho3D::AsyncLoadProgress::P_TOTALRESOURCES, "todo: var docstring")
; // End Namespace Class AsyncLoadProgress
  // Namespace vars class AsyncLoadProgress

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AttributeAnimationAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAttributeAnimationAdded {};

auto pyclass_NS__Urho3D_AttributeAnimationAdded = py::class_<PythonBindingsFakeModuleUrho3DAttributeAnimationAdded>(m, "AttributeAnimationAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_OBJECTANIMATION", &::Urho3D::AttributeAnimationAdded::P_OBJECTANIMATION, "todo: var docstring")
  .def_readonly_static("P_ATTRIBUTEANIMATIONNAME", &::Urho3D::AttributeAnimationAdded::P_ATTRIBUTEANIMATIONNAME, "todo: var docstring")
; // End Namespace Class AttributeAnimationAdded
  // Namespace vars class AttributeAnimationAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AttributeAnimationRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAttributeAnimationRemoved {};

auto pyclass_NS__Urho3D_AttributeAnimationRemoved = py::class_<PythonBindingsFakeModuleUrho3DAttributeAnimationRemoved>(m, "AttributeAnimationRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_OBJECTANIMATION", &::Urho3D::AttributeAnimationRemoved::P_OBJECTANIMATION, "todo: var docstring")
  .def_readonly_static("P_ATTRIBUTEANIMATIONNAME", &::Urho3D::AttributeAnimationRemoved::P_ATTRIBUTEANIMATIONNAME, "todo: var docstring")
; // End Namespace Class AttributeAnimationRemoved
  // Namespace vars class AttributeAnimationRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export AttributeAnimationUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DAttributeAnimationUpdate {};

auto pyclass_NS__Urho3D_AttributeAnimationUpdate = py::class_<PythonBindingsFakeModuleUrho3DAttributeAnimationUpdate>(m, "AttributeAnimationUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::AttributeAnimationUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::AttributeAnimationUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class AttributeAnimationUpdate
  // Namespace vars class AttributeAnimationUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export BeginFrame namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DBeginFrame {};

auto pyclass_NS__Urho3D_BeginFrame = py::class_<PythonBindingsFakeModuleUrho3DBeginFrame>(m, "BeginFrame")
  // Functions
  // Variables
  
  .def_readonly_static("P_FRAMENUMBER", &::Urho3D::BeginFrame::P_FRAMENUMBER, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::BeginFrame::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class BeginFrame
  // Namespace vars class BeginFrame

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export BeginRendering namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DBeginRendering {};

auto pyclass_NS__Urho3D_BeginRendering = py::class_<PythonBindingsFakeModuleUrho3DBeginRendering>(m, "BeginRendering")
  // Functions
  // Variables
  
; // End Namespace Class BeginRendering
  // Namespace vars class BeginRendering

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export BeginViewRender namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DBeginViewRender {};

auto pyclass_NS__Urho3D_BeginViewRender = py::class_<PythonBindingsFakeModuleUrho3DBeginViewRender>(m, "BeginViewRender")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::BeginViewRender::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::BeginViewRender::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::BeginViewRender::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::BeginViewRender::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::BeginViewRender::P_CAMERA, "todo: var docstring")
; // End Namespace Class BeginViewRender
  // Namespace vars class BeginViewRender

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export BeginViewUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DBeginViewUpdate {};

auto pyclass_NS__Urho3D_BeginViewUpdate = py::class_<PythonBindingsFakeModuleUrho3DBeginViewUpdate>(m, "BeginViewUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::BeginViewUpdate::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::BeginViewUpdate::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::BeginViewUpdate::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::BeginViewUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::BeginViewUpdate::P_CAMERA, "todo: var docstring")
; // End Namespace Class BeginViewUpdate
  // Namespace vars class BeginViewUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export BoneHierarchyCreated namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DBoneHierarchyCreated {};

auto pyclass_NS__Urho3D_BoneHierarchyCreated = py::class_<PythonBindingsFakeModuleUrho3DBoneHierarchyCreated>(m, "BoneHierarchyCreated")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::BoneHierarchyCreated::P_NODE, "todo: var docstring")
; // End Namespace Class BoneHierarchyCreated
  // Namespace vars class BoneHierarchyCreated

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ChangeLanguage namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DChangeLanguage {};

auto pyclass_NS__Urho3D_ChangeLanguage = py::class_<PythonBindingsFakeModuleUrho3DChangeLanguage>(m, "ChangeLanguage")
  // Functions
  // Variables
  
; // End Namespace Class ChangeLanguage
  // Namespace vars class ChangeLanguage

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Click namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClick {};

auto pyclass_NS__Urho3D_Click = py::class_<PythonBindingsFakeModuleUrho3DClick>(m, "Click")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Click::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::Click::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::Click::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::Click::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::Click::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::Click::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class Click
  // Namespace vars class Click

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ClickEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClickEnd {};

auto pyclass_NS__Urho3D_ClickEnd = py::class_<PythonBindingsFakeModuleUrho3DClickEnd>(m, "ClickEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ClickEnd::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_BEGINELEMENT", &::Urho3D::ClickEnd::P_BEGINELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::ClickEnd::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::ClickEnd::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::ClickEnd::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::ClickEnd::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::ClickEnd::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class ClickEnd
  // Namespace vars class ClickEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ClientConnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClientConnected {};

auto pyclass_NS__Urho3D_ClientConnected = py::class_<PythonBindingsFakeModuleUrho3DClientConnected>(m, "ClientConnected")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::ClientConnected::P_CONNECTION, "todo: var docstring")
; // End Namespace Class ClientConnected
  // Namespace vars class ClientConnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ClientDisconnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClientDisconnected {};

auto pyclass_NS__Urho3D_ClientDisconnected = py::class_<PythonBindingsFakeModuleUrho3DClientDisconnected>(m, "ClientDisconnected")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::ClientDisconnected::P_CONNECTION, "todo: var docstring")
; // End Namespace Class ClientDisconnected
  // Namespace vars class ClientDisconnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ClientIdentity namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClientIdentity {};

auto pyclass_NS__Urho3D_ClientIdentity = py::class_<PythonBindingsFakeModuleUrho3DClientIdentity>(m, "ClientIdentity")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::ClientIdentity::P_CONNECTION, "todo: var docstring")
  .def_readonly_static("P_ALLOW", &::Urho3D::ClientIdentity::P_ALLOW, "todo: var docstring")
; // End Namespace Class ClientIdentity
  // Namespace vars class ClientIdentity

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ClientSceneLoaded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DClientSceneLoaded {};

auto pyclass_NS__Urho3D_ClientSceneLoaded = py::class_<PythonBindingsFakeModuleUrho3DClientSceneLoaded>(m, "ClientSceneLoaded")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::ClientSceneLoaded::P_CONNECTION, "todo: var docstring")
; // End Namespace Class ClientSceneLoaded
  // Namespace vars class ClientSceneLoaded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ComponentAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DComponentAdded {};

auto pyclass_NS__Urho3D_ComponentAdded = py::class_<PythonBindingsFakeModuleUrho3DComponentAdded>(m, "ComponentAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::ComponentAdded::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::ComponentAdded::P_NODE, "todo: var docstring")
  .def_readonly_static("P_COMPONENT", &::Urho3D::ComponentAdded::P_COMPONENT, "todo: var docstring")
; // End Namespace Class ComponentAdded
  // Namespace vars class ComponentAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ComponentCloned namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DComponentCloned {};

auto pyclass_NS__Urho3D_ComponentCloned = py::class_<PythonBindingsFakeModuleUrho3DComponentCloned>(m, "ComponentCloned")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::ComponentCloned::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_COMPONENT", &::Urho3D::ComponentCloned::P_COMPONENT, "todo: var docstring")
  .def_readonly_static("P_CLONECOMPONENT", &::Urho3D::ComponentCloned::P_CLONECOMPONENT, "todo: var docstring")
; // End Namespace Class ComponentCloned
  // Namespace vars class ComponentCloned

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ComponentEnabledChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DComponentEnabledChanged {};

auto pyclass_NS__Urho3D_ComponentEnabledChanged = py::class_<PythonBindingsFakeModuleUrho3DComponentEnabledChanged>(m, "ComponentEnabledChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::ComponentEnabledChanged::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::ComponentEnabledChanged::P_NODE, "todo: var docstring")
  .def_readonly_static("P_COMPONENT", &::Urho3D::ComponentEnabledChanged::P_COMPONENT, "todo: var docstring")
; // End Namespace Class ComponentEnabledChanged
  // Namespace vars class ComponentEnabledChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ComponentRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DComponentRemoved {};

auto pyclass_NS__Urho3D_ComponentRemoved = py::class_<PythonBindingsFakeModuleUrho3DComponentRemoved>(m, "ComponentRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::ComponentRemoved::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::ComponentRemoved::P_NODE, "todo: var docstring")
  .def_readonly_static("P_COMPONENT", &::Urho3D::ComponentRemoved::P_COMPONENT, "todo: var docstring")
; // End Namespace Class ComponentRemoved
  // Namespace vars class ComponentRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ConnectFailed namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DConnectFailed {};

auto pyclass_NS__Urho3D_ConnectFailed = py::class_<PythonBindingsFakeModuleUrho3DConnectFailed>(m, "ConnectFailed")
  // Functions
  // Variables
  
; // End Namespace Class ConnectFailed
  // Namespace vars class ConnectFailed

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ConsoleCommand namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DConsoleCommand {};

auto pyclass_NS__Urho3D_ConsoleCommand = py::class_<PythonBindingsFakeModuleUrho3DConsoleCommand>(m, "ConsoleCommand")
  // Functions
  // Variables
  
  .def_readonly_static("P_COMMAND", &::Urho3D::ConsoleCommand::P_COMMAND, "todo: var docstring")
  .def_readonly_static("P_ID", &::Urho3D::ConsoleCommand::P_ID, "todo: var docstring")
; // End Namespace Class ConsoleCommand
  // Namespace vars class ConsoleCommand

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentFailure namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentFailure {};

auto pyclass_NS__Urho3D_CrowdAgentFailure = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentFailure>(m, "CrowdAgentFailure")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentFailure::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentFailure::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentFailure::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentFailure::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT_STATE", &::Urho3D::CrowdAgentFailure::P_CROWD_AGENT_STATE, "todo: var docstring")
  .def_readonly_static("P_CROWD_TARGET_STATE", &::Urho3D::CrowdAgentFailure::P_CROWD_TARGET_STATE, "todo: var docstring")
; // End Namespace Class CrowdAgentFailure
  // Namespace vars class CrowdAgentFailure

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentFormation namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentFormation {};

auto pyclass_NS__Urho3D_CrowdAgentFormation = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentFormation>(m, "CrowdAgentFormation")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentFormation::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentFormation::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_INDEX", &::Urho3D::CrowdAgentFormation::P_INDEX, "todo: var docstring")
  .def_readonly_static("P_SIZE", &::Urho3D::CrowdAgentFormation::P_SIZE, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentFormation::P_POSITION, "todo: var docstring")
; // End Namespace Class CrowdAgentFormation
  // Namespace vars class CrowdAgentFormation

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentNodeFailure namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentNodeFailure {};

auto pyclass_NS__Urho3D_CrowdAgentNodeFailure = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentNodeFailure>(m, "CrowdAgentNodeFailure")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentNodeFailure::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentNodeFailure::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentNodeFailure::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentNodeFailure::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT_STATE", &::Urho3D::CrowdAgentNodeFailure::P_CROWD_AGENT_STATE, "todo: var docstring")
  .def_readonly_static("P_CROWD_TARGET_STATE", &::Urho3D::CrowdAgentNodeFailure::P_CROWD_TARGET_STATE, "todo: var docstring")
; // End Namespace Class CrowdAgentNodeFailure
  // Namespace vars class CrowdAgentNodeFailure

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentNodeFormation namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentNodeFormation {};

auto pyclass_NS__Urho3D_CrowdAgentNodeFormation = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentNodeFormation>(m, "CrowdAgentNodeFormation")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentNodeFormation::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentNodeFormation::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_INDEX", &::Urho3D::CrowdAgentNodeFormation::P_INDEX, "todo: var docstring")
  .def_readonly_static("P_SIZE", &::Urho3D::CrowdAgentNodeFormation::P_SIZE, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentNodeFormation::P_POSITION, "todo: var docstring")
; // End Namespace Class CrowdAgentNodeFormation
  // Namespace vars class CrowdAgentNodeFormation

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentNodeReposition namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentNodeReposition {};

auto pyclass_NS__Urho3D_CrowdAgentNodeReposition = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentNodeReposition>(m, "CrowdAgentNodeReposition")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentNodeReposition::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentNodeReposition::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentNodeReposition::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentNodeReposition::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_ARRIVED", &::Urho3D::CrowdAgentNodeReposition::P_ARRIVED, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::CrowdAgentNodeReposition::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class CrowdAgentNodeReposition
  // Namespace vars class CrowdAgentNodeReposition

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentNodeStateChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentNodeStateChanged {};

auto pyclass_NS__Urho3D_CrowdAgentNodeStateChanged = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentNodeStateChanged>(m, "CrowdAgentNodeStateChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentNodeStateChanged::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentNodeStateChanged::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentNodeStateChanged::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentNodeStateChanged::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT_STATE", &::Urho3D::CrowdAgentNodeStateChanged::P_CROWD_AGENT_STATE, "todo: var docstring")
  .def_readonly_static("P_CROWD_TARGET_STATE", &::Urho3D::CrowdAgentNodeStateChanged::P_CROWD_TARGET_STATE, "todo: var docstring")
; // End Namespace Class CrowdAgentNodeStateChanged
  // Namespace vars class CrowdAgentNodeStateChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentReposition namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentReposition {};

auto pyclass_NS__Urho3D_CrowdAgentReposition = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentReposition>(m, "CrowdAgentReposition")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentReposition::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentReposition::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentReposition::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentReposition::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_ARRIVED", &::Urho3D::CrowdAgentReposition::P_ARRIVED, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::CrowdAgentReposition::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class CrowdAgentReposition
  // Namespace vars class CrowdAgentReposition

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export CrowdAgentStateChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DCrowdAgentStateChanged {};

auto pyclass_NS__Urho3D_CrowdAgentStateChanged = py::class_<PythonBindingsFakeModuleUrho3DCrowdAgentStateChanged>(m, "CrowdAgentStateChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::CrowdAgentStateChanged::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT", &::Urho3D::CrowdAgentStateChanged::P_CROWD_AGENT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::CrowdAgentStateChanged::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_VELOCITY", &::Urho3D::CrowdAgentStateChanged::P_VELOCITY, "todo: var docstring")
  .def_readonly_static("P_CROWD_AGENT_STATE", &::Urho3D::CrowdAgentStateChanged::P_CROWD_AGENT_STATE, "todo: var docstring")
  .def_readonly_static("P_CROWD_TARGET_STATE", &::Urho3D::CrowdAgentStateChanged::P_CROWD_TARGET_STATE, "todo: var docstring")
; // End Namespace Class CrowdAgentStateChanged
  // Namespace vars class CrowdAgentStateChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Defocused namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDefocused {};

auto pyclass_NS__Urho3D_Defocused = py::class_<PythonBindingsFakeModuleUrho3DDefocused>(m, "Defocused")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Defocused::P_ELEMENT, "todo: var docstring")
; // End Namespace Class Defocused
  // Namespace vars class Defocused

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DeviceLost namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDeviceLost {};

auto pyclass_NS__Urho3D_DeviceLost = py::class_<PythonBindingsFakeModuleUrho3DDeviceLost>(m, "DeviceLost")
  // Functions
  // Variables
  
; // End Namespace Class DeviceLost
  // Namespace vars class DeviceLost

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DeviceReset namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDeviceReset {};

auto pyclass_NS__Urho3D_DeviceReset = py::class_<PythonBindingsFakeModuleUrho3DDeviceReset>(m, "DeviceReset")
  // Functions
  // Variables
  
; // End Namespace Class DeviceReset
  // Namespace vars class DeviceReset

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DoubleClick namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDoubleClick {};

auto pyclass_NS__Urho3D_DoubleClick = py::class_<PythonBindingsFakeModuleUrho3DDoubleClick>(m, "DoubleClick")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::DoubleClick::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::DoubleClick::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::DoubleClick::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::DoubleClick::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::DoubleClick::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::DoubleClick::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class DoubleClick
  // Namespace vars class DoubleClick

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragBegin namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragBegin {};

auto pyclass_NS__Urho3D_DragBegin = py::class_<PythonBindingsFakeModuleUrho3DDragBegin>(m, "DragBegin")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::DragBegin::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::DragBegin::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::DragBegin::P_Y, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::DragBegin::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::DragBegin::P_ELEMENTY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::DragBegin::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_NUMBUTTONS", &::Urho3D::DragBegin::P_NUMBUTTONS, "todo: var docstring")
; // End Namespace Class DragBegin
  // Namespace vars class DragBegin

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragCancel namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragCancel {};

auto pyclass_NS__Urho3D_DragCancel = py::class_<PythonBindingsFakeModuleUrho3DDragCancel>(m, "DragCancel")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::DragCancel::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::DragCancel::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::DragCancel::P_Y, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::DragCancel::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::DragCancel::P_ELEMENTY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::DragCancel::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_NUMBUTTONS", &::Urho3D::DragCancel::P_NUMBUTTONS, "todo: var docstring")
; // End Namespace Class DragCancel
  // Namespace vars class DragCancel

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragDropFinish namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragDropFinish {};

auto pyclass_NS__Urho3D_DragDropFinish = py::class_<PythonBindingsFakeModuleUrho3DDragDropFinish>(m, "DragDropFinish")
  // Functions
  // Variables
  
  .def_readonly_static("P_SOURCE", &::Urho3D::DragDropFinish::P_SOURCE, "todo: var docstring")
  .def_readonly_static("P_TARGET", &::Urho3D::DragDropFinish::P_TARGET, "todo: var docstring")
  .def_readonly_static("P_ACCEPT", &::Urho3D::DragDropFinish::P_ACCEPT, "todo: var docstring")
; // End Namespace Class DragDropFinish
  // Namespace vars class DragDropFinish

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragDropTest namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragDropTest {};

auto pyclass_NS__Urho3D_DragDropTest = py::class_<PythonBindingsFakeModuleUrho3DDragDropTest>(m, "DragDropTest")
  // Functions
  // Variables
  
  .def_readonly_static("P_SOURCE", &::Urho3D::DragDropTest::P_SOURCE, "todo: var docstring")
  .def_readonly_static("P_TARGET", &::Urho3D::DragDropTest::P_TARGET, "todo: var docstring")
  .def_readonly_static("P_ACCEPT", &::Urho3D::DragDropTest::P_ACCEPT, "todo: var docstring")
; // End Namespace Class DragDropTest
  // Namespace vars class DragDropTest

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragEnd {};

auto pyclass_NS__Urho3D_DragEnd = py::class_<PythonBindingsFakeModuleUrho3DDragEnd>(m, "DragEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::DragEnd::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::DragEnd::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::DragEnd::P_Y, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::DragEnd::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::DragEnd::P_ELEMENTY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::DragEnd::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_NUMBUTTONS", &::Urho3D::DragEnd::P_NUMBUTTONS, "todo: var docstring")
; // End Namespace Class DragEnd
  // Namespace vars class DragEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DragMove namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDragMove {};

auto pyclass_NS__Urho3D_DragMove = py::class_<PythonBindingsFakeModuleUrho3DDragMove>(m, "DragMove")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::DragMove::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::DragMove::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::DragMove::P_Y, "todo: var docstring")
  .def_readonly_static("P_DX", &::Urho3D::DragMove::P_DX, "todo: var docstring")
  .def_readonly_static("P_DY", &::Urho3D::DragMove::P_DY, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::DragMove::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::DragMove::P_ELEMENTY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::DragMove::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_NUMBUTTONS", &::Urho3D::DragMove::P_NUMBUTTONS, "todo: var docstring")
; // End Namespace Class DragMove
  // Namespace vars class DragMove

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export DropFile namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DDropFile {};

auto pyclass_NS__Urho3D_DropFile = py::class_<PythonBindingsFakeModuleUrho3DDropFile>(m, "DropFile")
  // Functions
  // Variables
  
  .def_readonly_static("P_FILENAME", &::Urho3D::DropFile::P_FILENAME, "todo: var docstring")
; // End Namespace Class DropFile
  // Namespace vars class DropFile

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ElementAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DElementAdded {};

auto pyclass_NS__Urho3D_ElementAdded = py::class_<PythonBindingsFakeModuleUrho3DElementAdded>(m, "ElementAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_ROOT", &::Urho3D::ElementAdded::P_ROOT, "todo: var docstring")
  .def_readonly_static("P_PARENT", &::Urho3D::ElementAdded::P_PARENT, "todo: var docstring")
  .def_readonly_static("P_ELEMENT", &::Urho3D::ElementAdded::P_ELEMENT, "todo: var docstring")
; // End Namespace Class ElementAdded
  // Namespace vars class ElementAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ElementRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DElementRemoved {};

auto pyclass_NS__Urho3D_ElementRemoved = py::class_<PythonBindingsFakeModuleUrho3DElementRemoved>(m, "ElementRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_ROOT", &::Urho3D::ElementRemoved::P_ROOT, "todo: var docstring")
  .def_readonly_static("P_PARENT", &::Urho3D::ElementRemoved::P_PARENT, "todo: var docstring")
  .def_readonly_static("P_ELEMENT", &::Urho3D::ElementRemoved::P_ELEMENT, "todo: var docstring")
; // End Namespace Class ElementRemoved
  // Namespace vars class ElementRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export EndAllViewsRender namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DEndAllViewsRender {};

auto pyclass_NS__Urho3D_EndAllViewsRender = py::class_<PythonBindingsFakeModuleUrho3DEndAllViewsRender>(m, "EndAllViewsRender")
  // Functions
  // Variables
  
; // End Namespace Class EndAllViewsRender
  // Namespace vars class EndAllViewsRender

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export EndFrame namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DEndFrame {};

auto pyclass_NS__Urho3D_EndFrame = py::class_<PythonBindingsFakeModuleUrho3DEndFrame>(m, "EndFrame")
  // Functions
  // Variables
  
; // End Namespace Class EndFrame
  // Namespace vars class EndFrame

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export EndRendering namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DEndRendering {};

auto pyclass_NS__Urho3D_EndRendering = py::class_<PythonBindingsFakeModuleUrho3DEndRendering>(m, "EndRendering")
  // Functions
  // Variables
  
; // End Namespace Class EndRendering
  // Namespace vars class EndRendering

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export EndViewRender namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DEndViewRender {};

auto pyclass_NS__Urho3D_EndViewRender = py::class_<PythonBindingsFakeModuleUrho3DEndViewRender>(m, "EndViewRender")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::EndViewRender::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::EndViewRender::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::EndViewRender::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::EndViewRender::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::EndViewRender::P_CAMERA, "todo: var docstring")
; // End Namespace Class EndViewRender
  // Namespace vars class EndViewRender

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export EndViewUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DEndViewUpdate {};

auto pyclass_NS__Urho3D_EndViewUpdate = py::class_<PythonBindingsFakeModuleUrho3DEndViewUpdate>(m, "EndViewUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::EndViewUpdate::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::EndViewUpdate::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::EndViewUpdate::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::EndViewUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::EndViewUpdate::P_CAMERA, "todo: var docstring")
; // End Namespace Class EndViewUpdate
  // Namespace vars class EndViewUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ExitRequested namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DExitRequested {};

auto pyclass_NS__Urho3D_ExitRequested = py::class_<PythonBindingsFakeModuleUrho3DExitRequested>(m, "ExitRequested")
  // Functions
  // Variables
  
; // End Namespace Class ExitRequested
  // Namespace vars class ExitRequested

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export FileChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DFileChanged {};

auto pyclass_NS__Urho3D_FileChanged = py::class_<PythonBindingsFakeModuleUrho3DFileChanged>(m, "FileChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_FILENAME", &::Urho3D::FileChanged::P_FILENAME, "todo: var docstring")
  .def_readonly_static("P_RESOURCENAME", &::Urho3D::FileChanged::P_RESOURCENAME, "todo: var docstring")
; // End Namespace Class FileChanged
  // Namespace vars class FileChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export FileSelected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DFileSelected {};

auto pyclass_NS__Urho3D_FileSelected = py::class_<PythonBindingsFakeModuleUrho3DFileSelected>(m, "FileSelected")
  // Functions
  // Variables
  
  .def_readonly_static("P_FILENAME", &::Urho3D::FileSelected::P_FILENAME, "todo: var docstring")
  .def_readonly_static("P_FILTER", &::Urho3D::FileSelected::P_FILTER, "todo: var docstring")
  .def_readonly_static("P_OK", &::Urho3D::FileSelected::P_OK, "todo: var docstring")
; // End Namespace Class FileSelected
  // Namespace vars class FileSelected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export FocusChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DFocusChanged {};

auto pyclass_NS__Urho3D_FocusChanged = py::class_<PythonBindingsFakeModuleUrho3DFocusChanged>(m, "FocusChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::FocusChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_CLICKEDELEMENT", &::Urho3D::FocusChanged::P_CLICKEDELEMENT, "todo: var docstring")
; // End Namespace Class FocusChanged
  // Namespace vars class FocusChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Focused namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DFocused {};

auto pyclass_NS__Urho3D_Focused = py::class_<PythonBindingsFakeModuleUrho3DFocused>(m, "Focused")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Focused::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_BYKEY", &::Urho3D::Focused::P_BYKEY, "todo: var docstring")
; // End Namespace Class Focused
  // Namespace vars class Focused

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export GestureInput namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DGestureInput {};

auto pyclass_NS__Urho3D_GestureInput = py::class_<PythonBindingsFakeModuleUrho3DGestureInput>(m, "GestureInput")
  // Functions
  // Variables
  
  .def_readonly_static("P_GESTUREID", &::Urho3D::GestureInput::P_GESTUREID, "todo: var docstring")
  .def_readonly_static("P_CENTERX", &::Urho3D::GestureInput::P_CENTERX, "todo: var docstring")
  .def_readonly_static("P_CENTERY", &::Urho3D::GestureInput::P_CENTERY, "todo: var docstring")
  .def_readonly_static("P_NUMFINGERS", &::Urho3D::GestureInput::P_NUMFINGERS, "todo: var docstring")
  .def_readonly_static("P_ERROR", &::Urho3D::GestureInput::P_ERROR, "todo: var docstring")
; // End Namespace Class GestureInput
  // Namespace vars class GestureInput

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export GestureRecorded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DGestureRecorded {};

auto pyclass_NS__Urho3D_GestureRecorded = py::class_<PythonBindingsFakeModuleUrho3DGestureRecorded>(m, "GestureRecorded")
  // Functions
  // Variables
  
  .def_readonly_static("P_GESTUREID", &::Urho3D::GestureRecorded::P_GESTUREID, "todo: var docstring")
; // End Namespace Class GestureRecorded
  // Namespace vars class GestureRecorded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export HoverBegin namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DHoverBegin {};

auto pyclass_NS__Urho3D_HoverBegin = py::class_<PythonBindingsFakeModuleUrho3DHoverBegin>(m, "HoverBegin")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::HoverBegin::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::HoverBegin::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::HoverBegin::P_Y, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::HoverBegin::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::HoverBegin::P_ELEMENTY, "todo: var docstring")
; // End Namespace Class HoverBegin
  // Namespace vars class HoverBegin

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export HoverEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DHoverEnd {};

auto pyclass_NS__Urho3D_HoverEnd = py::class_<PythonBindingsFakeModuleUrho3DHoverEnd>(m, "HoverEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::HoverEnd::P_ELEMENT, "todo: var docstring")
; // End Namespace Class HoverEnd
  // Namespace vars class HoverEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export InputBegin namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DInputBegin {};

auto pyclass_NS__Urho3D_InputBegin = py::class_<PythonBindingsFakeModuleUrho3DInputBegin>(m, "InputBegin")
  // Functions
  // Variables
  
; // End Namespace Class InputBegin
  // Namespace vars class InputBegin

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export InputEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DInputEnd {};

auto pyclass_NS__Urho3D_InputEnd = py::class_<PythonBindingsFakeModuleUrho3DInputEnd>(m, "InputEnd")
  // Functions
  // Variables
  
; // End Namespace Class InputEnd
  // Namespace vars class InputEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export InputFocus namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DInputFocus {};

auto pyclass_NS__Urho3D_InputFocus = py::class_<PythonBindingsFakeModuleUrho3DInputFocus>(m, "InputFocus")
  // Functions
  // Variables
  
  .def_readonly_static("P_FOCUS", &::Urho3D::InputFocus::P_FOCUS, "todo: var docstring")
  .def_readonly_static("P_MINIMIZED", &::Urho3D::InputFocus::P_MINIMIZED, "todo: var docstring")
; // End Namespace Class InputFocus
  // Namespace vars class InputFocus

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export InterceptNetworkUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DInterceptNetworkUpdate {};

auto pyclass_NS__Urho3D_InterceptNetworkUpdate = py::class_<PythonBindingsFakeModuleUrho3DInterceptNetworkUpdate>(m, "InterceptNetworkUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_SERIALIZABLE", &::Urho3D::InterceptNetworkUpdate::P_SERIALIZABLE, "todo: var docstring")
  .def_readonly_static("P_TIMESTAMP", &::Urho3D::InterceptNetworkUpdate::P_TIMESTAMP, "todo: var docstring")
  .def_readonly_static("P_INDEX", &::Urho3D::InterceptNetworkUpdate::P_INDEX, "todo: var docstring")
  .def_readonly_static("P_NAME", &::Urho3D::InterceptNetworkUpdate::P_NAME, "todo: var docstring")
  .def_readonly_static("P_VALUE", &::Urho3D::InterceptNetworkUpdate::P_VALUE, "todo: var docstring")
; // End Namespace Class InterceptNetworkUpdate
  // Namespace vars class InterceptNetworkUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ItemClicked namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DItemClicked {};

auto pyclass_NS__Urho3D_ItemClicked = py::class_<PythonBindingsFakeModuleUrho3DItemClicked>(m, "ItemClicked")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ItemClicked::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_ITEM", &::Urho3D::ItemClicked::P_ITEM, "todo: var docstring")
  .def_readonly_static("P_SELECTION", &::Urho3D::ItemClicked::P_SELECTION, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::ItemClicked::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::ItemClicked::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::ItemClicked::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class ItemClicked
  // Namespace vars class ItemClicked

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ItemDeselected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DItemDeselected {};

auto pyclass_NS__Urho3D_ItemDeselected = py::class_<PythonBindingsFakeModuleUrho3DItemDeselected>(m, "ItemDeselected")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ItemDeselected::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_SELECTION", &::Urho3D::ItemDeselected::P_SELECTION, "todo: var docstring")
; // End Namespace Class ItemDeselected
  // Namespace vars class ItemDeselected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ItemDoubleClicked namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DItemDoubleClicked {};

auto pyclass_NS__Urho3D_ItemDoubleClicked = py::class_<PythonBindingsFakeModuleUrho3DItemDoubleClicked>(m, "ItemDoubleClicked")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ItemDoubleClicked::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_ITEM", &::Urho3D::ItemDoubleClicked::P_ITEM, "todo: var docstring")
  .def_readonly_static("P_SELECTION", &::Urho3D::ItemDoubleClicked::P_SELECTION, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::ItemDoubleClicked::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::ItemDoubleClicked::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::ItemDoubleClicked::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class ItemDoubleClicked
  // Namespace vars class ItemDoubleClicked

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ItemSelected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DItemSelected {};

auto pyclass_NS__Urho3D_ItemSelected = py::class_<PythonBindingsFakeModuleUrho3DItemSelected>(m, "ItemSelected")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ItemSelected::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_SELECTION", &::Urho3D::ItemSelected::P_SELECTION, "todo: var docstring")
; // End Namespace Class ItemSelected
  // Namespace vars class ItemSelected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickAxisMove namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickAxisMove {};

auto pyclass_NS__Urho3D_JoystickAxisMove = py::class_<PythonBindingsFakeModuleUrho3DJoystickAxisMove>(m, "JoystickAxisMove")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickAxisMove::P_JOYSTICKID, "todo: var docstring")
  .def_readonly_static("P_AXIS", &::Urho3D::JoystickAxisMove::P_AXIS, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::JoystickAxisMove::P_POSITION, "todo: var docstring")
; // End Namespace Class JoystickAxisMove
  // Namespace vars class JoystickAxisMove

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickButtonDown namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickButtonDown {};

auto pyclass_NS__Urho3D_JoystickButtonDown = py::class_<PythonBindingsFakeModuleUrho3DJoystickButtonDown>(m, "JoystickButtonDown")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickButtonDown::P_JOYSTICKID, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::JoystickButtonDown::P_BUTTON, "todo: var docstring")
; // End Namespace Class JoystickButtonDown
  // Namespace vars class JoystickButtonDown

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickButtonUp namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickButtonUp {};

auto pyclass_NS__Urho3D_JoystickButtonUp = py::class_<PythonBindingsFakeModuleUrho3DJoystickButtonUp>(m, "JoystickButtonUp")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickButtonUp::P_JOYSTICKID, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::JoystickButtonUp::P_BUTTON, "todo: var docstring")
; // End Namespace Class JoystickButtonUp
  // Namespace vars class JoystickButtonUp

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickConnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickConnected {};

auto pyclass_NS__Urho3D_JoystickConnected = py::class_<PythonBindingsFakeModuleUrho3DJoystickConnected>(m, "JoystickConnected")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickConnected::P_JOYSTICKID, "todo: var docstring")
; // End Namespace Class JoystickConnected
  // Namespace vars class JoystickConnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickDisconnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickDisconnected {};

auto pyclass_NS__Urho3D_JoystickDisconnected = py::class_<PythonBindingsFakeModuleUrho3DJoystickDisconnected>(m, "JoystickDisconnected")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickDisconnected::P_JOYSTICKID, "todo: var docstring")
; // End Namespace Class JoystickDisconnected
  // Namespace vars class JoystickDisconnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export JoystickHatMove namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DJoystickHatMove {};

auto pyclass_NS__Urho3D_JoystickHatMove = py::class_<PythonBindingsFakeModuleUrho3DJoystickHatMove>(m, "JoystickHatMove")
  // Functions
  // Variables
  
  .def_readonly_static("P_JOYSTICKID", &::Urho3D::JoystickHatMove::P_JOYSTICKID, "todo: var docstring")
  .def_readonly_static("P_HAT", &::Urho3D::JoystickHatMove::P_HAT, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::JoystickHatMove::P_POSITION, "todo: var docstring")
; // End Namespace Class JoystickHatMove
  // Namespace vars class JoystickHatMove

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export KeyDown namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DKeyDown {};

auto pyclass_NS__Urho3D_KeyDown = py::class_<PythonBindingsFakeModuleUrho3DKeyDown>(m, "KeyDown")
  // Functions
  // Variables
  
  .def_readonly_static("P_KEY", &::Urho3D::KeyDown::P_KEY, "todo: var docstring")
  .def_readonly_static("P_SCANCODE", &::Urho3D::KeyDown::P_SCANCODE, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::KeyDown::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::KeyDown::P_QUALIFIERS, "todo: var docstring")
  .def_readonly_static("P_REPEAT", &::Urho3D::KeyDown::P_REPEAT, "todo: var docstring")
; // End Namespace Class KeyDown
  // Namespace vars class KeyDown

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export KeyUp namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DKeyUp {};

auto pyclass_NS__Urho3D_KeyUp = py::class_<PythonBindingsFakeModuleUrho3DKeyUp>(m, "KeyUp")
  // Functions
  // Variables
  
  .def_readonly_static("P_KEY", &::Urho3D::KeyUp::P_KEY, "todo: var docstring")
  .def_readonly_static("P_SCANCODE", &::Urho3D::KeyUp::P_SCANCODE, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::KeyUp::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::KeyUp::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class KeyUp
  // Namespace vars class KeyUp

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export LayoutUpdated namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DLayoutUpdated {};

auto pyclass_NS__Urho3D_LayoutUpdated = py::class_<PythonBindingsFakeModuleUrho3DLayoutUpdated>(m, "LayoutUpdated")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::LayoutUpdated::P_ELEMENT, "todo: var docstring")
; // End Namespace Class LayoutUpdated
  // Namespace vars class LayoutUpdated

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export LoadFailed namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DLoadFailed {};

auto pyclass_NS__Urho3D_LoadFailed = py::class_<PythonBindingsFakeModuleUrho3DLoadFailed>(m, "LoadFailed")
  // Functions
  // Variables
  
  .def_readonly_static("P_RESOURCENAME", &::Urho3D::LoadFailed::P_RESOURCENAME, "todo: var docstring")
; // End Namespace Class LoadFailed
  // Namespace vars class LoadFailed

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export LogMessage namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DLogMessage {};

auto pyclass_NS__Urho3D_LogMessage = py::class_<PythonBindingsFakeModuleUrho3DLogMessage>(m, "LogMessage")
  // Functions
  // Variables
  
  .def_readonly_static("P_MESSAGE", &::Urho3D::LogMessage::P_MESSAGE, "todo: var docstring")
  .def_readonly_static("P_LEVEL", &::Urho3D::LogMessage::P_LEVEL, "todo: var docstring")
; // End Namespace Class LogMessage
  // Namespace vars class LogMessage

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MenuSelected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMenuSelected {};

auto pyclass_NS__Urho3D_MenuSelected = py::class_<PythonBindingsFakeModuleUrho3DMenuSelected>(m, "MenuSelected")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::MenuSelected::P_ELEMENT, "todo: var docstring")
; // End Namespace Class MenuSelected
  // Namespace vars class MenuSelected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MessageACK namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMessageACK {};

auto pyclass_NS__Urho3D_MessageACK = py::class_<PythonBindingsFakeModuleUrho3DMessageACK>(m, "MessageACK")
  // Functions
  // Variables
  
  .def_readonly_static("P_OK", &::Urho3D::MessageACK::P_OK, "todo: var docstring")
; // End Namespace Class MessageACK
  // Namespace vars class MessageACK

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ModalChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DModalChanged {};

auto pyclass_NS__Urho3D_ModalChanged = py::class_<PythonBindingsFakeModuleUrho3DModalChanged>(m, "ModalChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ModalChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_MODAL", &::Urho3D::ModalChanged::P_MODAL, "todo: var docstring")
; // End Namespace Class ModalChanged
  // Namespace vars class ModalChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseButtonDown namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseButtonDown {};

auto pyclass_NS__Urho3D_MouseButtonDown = py::class_<PythonBindingsFakeModuleUrho3DMouseButtonDown>(m, "MouseButtonDown")
  // Functions
  // Variables
  
  .def_readonly_static("P_BUTTON", &::Urho3D::MouseButtonDown::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::MouseButtonDown::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::MouseButtonDown::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class MouseButtonDown
  // Namespace vars class MouseButtonDown

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseButtonUp namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseButtonUp {};

auto pyclass_NS__Urho3D_MouseButtonUp = py::class_<PythonBindingsFakeModuleUrho3DMouseButtonUp>(m, "MouseButtonUp")
  // Functions
  // Variables
  
  .def_readonly_static("P_BUTTON", &::Urho3D::MouseButtonUp::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::MouseButtonUp::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::MouseButtonUp::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class MouseButtonUp
  // Namespace vars class MouseButtonUp

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseModeChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseModeChanged {};

auto pyclass_NS__Urho3D_MouseModeChanged = py::class_<PythonBindingsFakeModuleUrho3DMouseModeChanged>(m, "MouseModeChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_MODE", &::Urho3D::MouseModeChanged::P_MODE, "todo: var docstring")
  .def_readonly_static("P_MOUSELOCKED", &::Urho3D::MouseModeChanged::P_MOUSELOCKED, "todo: var docstring")
; // End Namespace Class MouseModeChanged
  // Namespace vars class MouseModeChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseMove namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseMove {};

auto pyclass_NS__Urho3D_MouseMove = py::class_<PythonBindingsFakeModuleUrho3DMouseMove>(m, "MouseMove")
  // Functions
  // Variables
  
  .def_readonly_static("P_X", &::Urho3D::MouseMove::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::MouseMove::P_Y, "todo: var docstring")
  .def_readonly_static("P_DX", &::Urho3D::MouseMove::P_DX, "todo: var docstring")
  .def_readonly_static("P_DY", &::Urho3D::MouseMove::P_DY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::MouseMove::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::MouseMove::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class MouseMove
  // Namespace vars class MouseMove

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseVisibleChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseVisibleChanged {};

auto pyclass_NS__Urho3D_MouseVisibleChanged = py::class_<PythonBindingsFakeModuleUrho3DMouseVisibleChanged>(m, "MouseVisibleChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_VISIBLE", &::Urho3D::MouseVisibleChanged::P_VISIBLE, "todo: var docstring")
; // End Namespace Class MouseVisibleChanged
  // Namespace vars class MouseVisibleChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MouseWheel namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMouseWheel {};

auto pyclass_NS__Urho3D_MouseWheel = py::class_<PythonBindingsFakeModuleUrho3DMouseWheel>(m, "MouseWheel")
  // Functions
  // Variables
  
  .def_readonly_static("P_WHEEL", &::Urho3D::MouseWheel::P_WHEEL, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::MouseWheel::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::MouseWheel::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class MouseWheel
  // Namespace vars class MouseWheel

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export MultiGesture namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DMultiGesture {};

auto pyclass_NS__Urho3D_MultiGesture = py::class_<PythonBindingsFakeModuleUrho3DMultiGesture>(m, "MultiGesture")
  // Functions
  // Variables
  
  .def_readonly_static("P_CENTERX", &::Urho3D::MultiGesture::P_CENTERX, "todo: var docstring")
  .def_readonly_static("P_CENTERY", &::Urho3D::MultiGesture::P_CENTERY, "todo: var docstring")
  .def_readonly_static("P_NUMFINGERS", &::Urho3D::MultiGesture::P_NUMFINGERS, "todo: var docstring")
  .def_readonly_static("P_DTHETA", &::Urho3D::MultiGesture::P_DTHETA, "todo: var docstring")
  .def_readonly_static("P_DDIST", &::Urho3D::MultiGesture::P_DDIST, "todo: var docstring")
; // End Namespace Class MultiGesture
  // Namespace vars class MultiGesture

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NameChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNameChanged {};

auto pyclass_NS__Urho3D_NameChanged = py::class_<PythonBindingsFakeModuleUrho3DNameChanged>(m, "NameChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::NameChanged::P_ELEMENT, "todo: var docstring")
; // End Namespace Class NameChanged
  // Namespace vars class NameChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NavigationAreaRebuilt namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNavigationAreaRebuilt {};

auto pyclass_NS__Urho3D_NavigationAreaRebuilt = py::class_<PythonBindingsFakeModuleUrho3DNavigationAreaRebuilt>(m, "NavigationAreaRebuilt")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::NavigationAreaRebuilt::P_NODE, "todo: var docstring")
  .def_readonly_static("P_MESH", &::Urho3D::NavigationAreaRebuilt::P_MESH, "todo: var docstring")
  .def_readonly_static("P_BOUNDSMIN", &::Urho3D::NavigationAreaRebuilt::P_BOUNDSMIN, "todo: var docstring")
  .def_readonly_static("P_BOUNDSMAX", &::Urho3D::NavigationAreaRebuilt::P_BOUNDSMAX, "todo: var docstring")
; // End Namespace Class NavigationAreaRebuilt
  // Namespace vars class NavigationAreaRebuilt

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NavigationMeshRebuilt namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNavigationMeshRebuilt {};

auto pyclass_NS__Urho3D_NavigationMeshRebuilt = py::class_<PythonBindingsFakeModuleUrho3DNavigationMeshRebuilt>(m, "NavigationMeshRebuilt")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::NavigationMeshRebuilt::P_NODE, "todo: var docstring")
  .def_readonly_static("P_MESH", &::Urho3D::NavigationMeshRebuilt::P_MESH, "todo: var docstring")
; // End Namespace Class NavigationMeshRebuilt
  // Namespace vars class NavigationMeshRebuilt

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NavigationObstacleAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNavigationObstacleAdded {};

auto pyclass_NS__Urho3D_NavigationObstacleAdded = py::class_<PythonBindingsFakeModuleUrho3DNavigationObstacleAdded>(m, "NavigationObstacleAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::NavigationObstacleAdded::P_NODE, "todo: var docstring")
  .def_readonly_static("P_OBSTACLE", &::Urho3D::NavigationObstacleAdded::P_OBSTACLE, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::NavigationObstacleAdded::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_RADIUS", &::Urho3D::NavigationObstacleAdded::P_RADIUS, "todo: var docstring")
  .def_readonly_static("P_HEIGHT", &::Urho3D::NavigationObstacleAdded::P_HEIGHT, "todo: var docstring")
; // End Namespace Class NavigationObstacleAdded
  // Namespace vars class NavigationObstacleAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NavigationObstacleRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNavigationObstacleRemoved {};

auto pyclass_NS__Urho3D_NavigationObstacleRemoved = py::class_<PythonBindingsFakeModuleUrho3DNavigationObstacleRemoved>(m, "NavigationObstacleRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::NavigationObstacleRemoved::P_NODE, "todo: var docstring")
  .def_readonly_static("P_OBSTACLE", &::Urho3D::NavigationObstacleRemoved::P_OBSTACLE, "todo: var docstring")
  .def_readonly_static("P_POSITION", &::Urho3D::NavigationObstacleRemoved::P_POSITION, "todo: var docstring")
  .def_readonly_static("P_RADIUS", &::Urho3D::NavigationObstacleRemoved::P_RADIUS, "todo: var docstring")
  .def_readonly_static("P_HEIGHT", &::Urho3D::NavigationObstacleRemoved::P_HEIGHT, "todo: var docstring")
; // End Namespace Class NavigationObstacleRemoved
  // Namespace vars class NavigationObstacleRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NetworkMessage namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNetworkMessage {};

auto pyclass_NS__Urho3D_NetworkMessage = py::class_<PythonBindingsFakeModuleUrho3DNetworkMessage>(m, "NetworkMessage")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::NetworkMessage::P_CONNECTION, "todo: var docstring")
  .def_readonly_static("P_MESSAGEID", &::Urho3D::NetworkMessage::P_MESSAGEID, "todo: var docstring")
  .def_readonly_static("P_DATA", &::Urho3D::NetworkMessage::P_DATA, "todo: var docstring")
; // End Namespace Class NetworkMessage
  // Namespace vars class NetworkMessage

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NetworkSceneLoadFailed namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNetworkSceneLoadFailed {};

auto pyclass_NS__Urho3D_NetworkSceneLoadFailed = py::class_<PythonBindingsFakeModuleUrho3DNetworkSceneLoadFailed>(m, "NetworkSceneLoadFailed")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::NetworkSceneLoadFailed::P_CONNECTION, "todo: var docstring")
; // End Namespace Class NetworkSceneLoadFailed
  // Namespace vars class NetworkSceneLoadFailed

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NetworkUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNetworkUpdate {};

auto pyclass_NS__Urho3D_NetworkUpdate = py::class_<PythonBindingsFakeModuleUrho3DNetworkUpdate>(m, "NetworkUpdate")
  // Functions
  // Variables
  
; // End Namespace Class NetworkUpdate
  // Namespace vars class NetworkUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NetworkUpdateSent namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNetworkUpdateSent {};

auto pyclass_NS__Urho3D_NetworkUpdateSent = py::class_<PythonBindingsFakeModuleUrho3DNetworkUpdateSent>(m, "NetworkUpdateSent")
  // Functions
  // Variables
  
; // End Namespace Class NetworkUpdateSent
  // Namespace vars class NetworkUpdateSent

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeAdded {};

auto pyclass_NS__Urho3D_NodeAdded = py::class_<PythonBindingsFakeModuleUrho3DNodeAdded>(m, "NodeAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeAdded::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_PARENT", &::Urho3D::NodeAdded::P_PARENT, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeAdded::P_NODE, "todo: var docstring")
; // End Namespace Class NodeAdded
  // Namespace vars class NodeAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeBeginContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeBeginContact2D {};

auto pyclass_NS__Urho3D_NodeBeginContact2D = py::class_<PythonBindingsFakeModuleUrho3DNodeBeginContact2D>(m, "NodeBeginContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeBeginContact2D::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeBeginContact2D::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeBeginContact2D::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::NodeBeginContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPE", &::Urho3D::NodeBeginContact2D::P_SHAPE, "todo: var docstring")
  .def_readonly_static("P_OTHERSHAPE", &::Urho3D::NodeBeginContact2D::P_OTHERSHAPE, "todo: var docstring")
; // End Namespace Class NodeBeginContact2D
  // Namespace vars class NodeBeginContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeCloned namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeCloned {};

auto pyclass_NS__Urho3D_NodeCloned = py::class_<PythonBindingsFakeModuleUrho3DNodeCloned>(m, "NodeCloned")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeCloned::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeCloned::P_NODE, "todo: var docstring")
  .def_readonly_static("P_CLONENODE", &::Urho3D::NodeCloned::P_CLONENODE, "todo: var docstring")
; // End Namespace Class NodeCloned
  // Namespace vars class NodeCloned

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeCollision namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeCollision {};

auto pyclass_NS__Urho3D_NodeCollision = py::class_<PythonBindingsFakeModuleUrho3DNodeCollision>(m, "NodeCollision")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeCollision::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeCollision::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeCollision::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::NodeCollision::P_TRIGGER, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::NodeCollision::P_CONTACTS, "todo: var docstring")
; // End Namespace Class NodeCollision
  // Namespace vars class NodeCollision

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeCollisionEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeCollisionEnd {};

auto pyclass_NS__Urho3D_NodeCollisionEnd = py::class_<PythonBindingsFakeModuleUrho3DNodeCollisionEnd>(m, "NodeCollisionEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeCollisionEnd::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeCollisionEnd::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeCollisionEnd::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::NodeCollisionEnd::P_TRIGGER, "todo: var docstring")
; // End Namespace Class NodeCollisionEnd
  // Namespace vars class NodeCollisionEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeCollisionStart namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeCollisionStart {};

auto pyclass_NS__Urho3D_NodeCollisionStart = py::class_<PythonBindingsFakeModuleUrho3DNodeCollisionStart>(m, "NodeCollisionStart")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeCollisionStart::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeCollisionStart::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeCollisionStart::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::NodeCollisionStart::P_TRIGGER, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::NodeCollisionStart::P_CONTACTS, "todo: var docstring")
; // End Namespace Class NodeCollisionStart
  // Namespace vars class NodeCollisionStart

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeEnabledChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeEnabledChanged {};

auto pyclass_NS__Urho3D_NodeEnabledChanged = py::class_<PythonBindingsFakeModuleUrho3DNodeEnabledChanged>(m, "NodeEnabledChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeEnabledChanged::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeEnabledChanged::P_NODE, "todo: var docstring")
; // End Namespace Class NodeEnabledChanged
  // Namespace vars class NodeEnabledChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeEndContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeEndContact2D {};

auto pyclass_NS__Urho3D_NodeEndContact2D = py::class_<PythonBindingsFakeModuleUrho3DNodeEndContact2D>(m, "NodeEndContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeEndContact2D::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeEndContact2D::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeEndContact2D::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::NodeEndContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPE", &::Urho3D::NodeEndContact2D::P_SHAPE, "todo: var docstring")
  .def_readonly_static("P_OTHERSHAPE", &::Urho3D::NodeEndContact2D::P_OTHERSHAPE, "todo: var docstring")
; // End Namespace Class NodeEndContact2D
  // Namespace vars class NodeEndContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeNameChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeNameChanged {};

auto pyclass_NS__Urho3D_NodeNameChanged = py::class_<PythonBindingsFakeModuleUrho3DNodeNameChanged>(m, "NodeNameChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeNameChanged::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeNameChanged::P_NODE, "todo: var docstring")
; // End Namespace Class NodeNameChanged
  // Namespace vars class NodeNameChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeRemoved {};

auto pyclass_NS__Urho3D_NodeRemoved = py::class_<PythonBindingsFakeModuleUrho3DNodeRemoved>(m, "NodeRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeRemoved::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_PARENT", &::Urho3D::NodeRemoved::P_PARENT, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeRemoved::P_NODE, "todo: var docstring")
; // End Namespace Class NodeRemoved
  // Namespace vars class NodeRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeTagAdded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeTagAdded {};

auto pyclass_NS__Urho3D_NodeTagAdded = py::class_<PythonBindingsFakeModuleUrho3DNodeTagAdded>(m, "NodeTagAdded")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeTagAdded::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeTagAdded::P_NODE, "todo: var docstring")
  .def_readonly_static("P_TAG", &::Urho3D::NodeTagAdded::P_TAG, "todo: var docstring")
; // End Namespace Class NodeTagAdded
  // Namespace vars class NodeTagAdded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeTagRemoved namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeTagRemoved {};

auto pyclass_NS__Urho3D_NodeTagRemoved = py::class_<PythonBindingsFakeModuleUrho3DNodeTagRemoved>(m, "NodeTagRemoved")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::NodeTagRemoved::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_NODE", &::Urho3D::NodeTagRemoved::P_NODE, "todo: var docstring")
  .def_readonly_static("P_TAG", &::Urho3D::NodeTagRemoved::P_TAG, "todo: var docstring")
; // End Namespace Class NodeTagRemoved
  // Namespace vars class NodeTagRemoved

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export NodeUpdateContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DNodeUpdateContact2D {};

auto pyclass_NS__Urho3D_NodeUpdateContact2D = py::class_<PythonBindingsFakeModuleUrho3DNodeUpdateContact2D>(m, "NodeUpdateContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_BODY", &::Urho3D::NodeUpdateContact2D::P_BODY, "todo: var docstring")
  .def_readonly_static("P_OTHERNODE", &::Urho3D::NodeUpdateContact2D::P_OTHERNODE, "todo: var docstring")
  .def_readonly_static("P_OTHERBODY", &::Urho3D::NodeUpdateContact2D::P_OTHERBODY, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::NodeUpdateContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPE", &::Urho3D::NodeUpdateContact2D::P_SHAPE, "todo: var docstring")
  .def_readonly_static("P_OTHERSHAPE", &::Urho3D::NodeUpdateContact2D::P_OTHERSHAPE, "todo: var docstring")
  .def_readonly_static("P_ENABLED", &::Urho3D::NodeUpdateContact2D::P_ENABLED, "todo: var docstring")
; // End Namespace Class NodeUpdateContact2D
  // Namespace vars class NodeUpdateContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ParticleEffectFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DParticleEffectFinished {};

auto pyclass_NS__Urho3D_ParticleEffectFinished = py::class_<PythonBindingsFakeModuleUrho3DParticleEffectFinished>(m, "ParticleEffectFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::ParticleEffectFinished::P_NODE, "todo: var docstring")
  .def_readonly_static("P_EFFECT", &::Urho3D::ParticleEffectFinished::P_EFFECT, "todo: var docstring")
; // End Namespace Class ParticleEffectFinished
  // Namespace vars class ParticleEffectFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ParticlesDuration namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DParticlesDuration {};

auto pyclass_NS__Urho3D_ParticlesDuration = py::class_<PythonBindingsFakeModuleUrho3DParticlesDuration>(m, "ParticlesDuration")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::ParticlesDuration::P_NODE, "todo: var docstring")
  .def_readonly_static("P_EFFECT", &::Urho3D::ParticlesDuration::P_EFFECT, "todo: var docstring")
; // End Namespace Class ParticlesDuration
  // Namespace vars class ParticlesDuration

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ParticlesEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DParticlesEnd {};

auto pyclass_NS__Urho3D_ParticlesEnd = py::class_<PythonBindingsFakeModuleUrho3DParticlesEnd>(m, "ParticlesEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::ParticlesEnd::P_NODE, "todo: var docstring")
  .def_readonly_static("P_EFFECT", &::Urho3D::ParticlesEnd::P_EFFECT, "todo: var docstring")
; // End Namespace Class ParticlesEnd
  // Namespace vars class ParticlesEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsBeginContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsBeginContact2D {};

auto pyclass_NS__Urho3D_PhysicsBeginContact2D = py::class_<PythonBindingsFakeModuleUrho3DPhysicsBeginContact2D>(m, "PhysicsBeginContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsBeginContact2D::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsBeginContact2D::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsBeginContact2D::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsBeginContact2D::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsBeginContact2D::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::PhysicsBeginContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPEA", &::Urho3D::PhysicsBeginContact2D::P_SHAPEA, "todo: var docstring")
  .def_readonly_static("P_SHAPEB", &::Urho3D::PhysicsBeginContact2D::P_SHAPEB, "todo: var docstring")
; // End Namespace Class PhysicsBeginContact2D
  // Namespace vars class PhysicsBeginContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsCollision namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsCollision {};

auto pyclass_NS__Urho3D_PhysicsCollision = py::class_<PythonBindingsFakeModuleUrho3DPhysicsCollision>(m, "PhysicsCollision")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsCollision::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsCollision::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsCollision::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsCollision::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsCollision::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::PhysicsCollision::P_TRIGGER, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::PhysicsCollision::P_CONTACTS, "todo: var docstring")
; // End Namespace Class PhysicsCollision
  // Namespace vars class PhysicsCollision

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsCollisionEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsCollisionEnd {};

auto pyclass_NS__Urho3D_PhysicsCollisionEnd = py::class_<PythonBindingsFakeModuleUrho3DPhysicsCollisionEnd>(m, "PhysicsCollisionEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsCollisionEnd::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsCollisionEnd::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsCollisionEnd::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsCollisionEnd::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsCollisionEnd::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::PhysicsCollisionEnd::P_TRIGGER, "todo: var docstring")
; // End Namespace Class PhysicsCollisionEnd
  // Namespace vars class PhysicsCollisionEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsCollisionStart namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsCollisionStart {};

auto pyclass_NS__Urho3D_PhysicsCollisionStart = py::class_<PythonBindingsFakeModuleUrho3DPhysicsCollisionStart>(m, "PhysicsCollisionStart")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsCollisionStart::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsCollisionStart::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsCollisionStart::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsCollisionStart::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsCollisionStart::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_TRIGGER", &::Urho3D::PhysicsCollisionStart::P_TRIGGER, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::PhysicsCollisionStart::P_CONTACTS, "todo: var docstring")
; // End Namespace Class PhysicsCollisionStart
  // Namespace vars class PhysicsCollisionStart

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsEndContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsEndContact2D {};

auto pyclass_NS__Urho3D_PhysicsEndContact2D = py::class_<PythonBindingsFakeModuleUrho3DPhysicsEndContact2D>(m, "PhysicsEndContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsEndContact2D::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsEndContact2D::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsEndContact2D::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsEndContact2D::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsEndContact2D::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::PhysicsEndContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPEA", &::Urho3D::PhysicsEndContact2D::P_SHAPEA, "todo: var docstring")
  .def_readonly_static("P_SHAPEB", &::Urho3D::PhysicsEndContact2D::P_SHAPEB, "todo: var docstring")
; // End Namespace Class PhysicsEndContact2D
  // Namespace vars class PhysicsEndContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsPostStep namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsPostStep {};

auto pyclass_NS__Urho3D_PhysicsPostStep = py::class_<PythonBindingsFakeModuleUrho3DPhysicsPostStep>(m, "PhysicsPostStep")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsPostStep::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::PhysicsPostStep::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class PhysicsPostStep
  // Namespace vars class PhysicsPostStep

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsPreStep namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsPreStep {};

auto pyclass_NS__Urho3D_PhysicsPreStep = py::class_<PythonBindingsFakeModuleUrho3DPhysicsPreStep>(m, "PhysicsPreStep")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsPreStep::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::PhysicsPreStep::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class PhysicsPreStep
  // Namespace vars class PhysicsPreStep

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PhysicsUpdateContact2D namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPhysicsUpdateContact2D {};

auto pyclass_NS__Urho3D_PhysicsUpdateContact2D = py::class_<PythonBindingsFakeModuleUrho3DPhysicsUpdateContact2D>(m, "PhysicsUpdateContact2D")
  // Functions
  // Variables
  
  .def_readonly_static("P_WORLD", &::Urho3D::PhysicsUpdateContact2D::P_WORLD, "todo: var docstring")
  .def_readonly_static("P_BODYA", &::Urho3D::PhysicsUpdateContact2D::P_BODYA, "todo: var docstring")
  .def_readonly_static("P_BODYB", &::Urho3D::PhysicsUpdateContact2D::P_BODYB, "todo: var docstring")
  .def_readonly_static("P_NODEA", &::Urho3D::PhysicsUpdateContact2D::P_NODEA, "todo: var docstring")
  .def_readonly_static("P_NODEB", &::Urho3D::PhysicsUpdateContact2D::P_NODEB, "todo: var docstring")
  .def_readonly_static("P_CONTACTS", &::Urho3D::PhysicsUpdateContact2D::P_CONTACTS, "todo: var docstring")
  .def_readonly_static("P_SHAPEA", &::Urho3D::PhysicsUpdateContact2D::P_SHAPEA, "todo: var docstring")
  .def_readonly_static("P_SHAPEB", &::Urho3D::PhysicsUpdateContact2D::P_SHAPEB, "todo: var docstring")
  .def_readonly_static("P_ENABLED", &::Urho3D::PhysicsUpdateContact2D::P_ENABLED, "todo: var docstring")
; // End Namespace Class PhysicsUpdateContact2D
  // Namespace vars class PhysicsUpdateContact2D

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Positioned namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPositioned {};

auto pyclass_NS__Urho3D_Positioned = py::class_<PythonBindingsFakeModuleUrho3DPositioned>(m, "Positioned")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Positioned::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::Positioned::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::Positioned::P_Y, "todo: var docstring")
; // End Namespace Class Positioned
  // Namespace vars class Positioned

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PostRenderUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPostRenderUpdate {};

auto pyclass_NS__Urho3D_PostRenderUpdate = py::class_<PythonBindingsFakeModuleUrho3DPostRenderUpdate>(m, "PostRenderUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_TIMESTEP", &::Urho3D::PostRenderUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class PostRenderUpdate
  // Namespace vars class PostRenderUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export PostUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPostUpdate {};

auto pyclass_NS__Urho3D_PostUpdate = py::class_<PythonBindingsFakeModuleUrho3DPostUpdate>(m, "PostUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_TIMESTEP", &::Urho3D::PostUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class PostUpdate
  // Namespace vars class PostUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Pressed namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DPressed {};

auto pyclass_NS__Urho3D_Pressed = py::class_<PythonBindingsFakeModuleUrho3DPressed>(m, "Pressed")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Pressed::P_ELEMENT, "todo: var docstring")
; // End Namespace Class Pressed
  // Namespace vars class Pressed

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ProgressBarChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DProgressBarChanged {};

auto pyclass_NS__Urho3D_ProgressBarChanged = py::class_<PythonBindingsFakeModuleUrho3DProgressBarChanged>(m, "ProgressBarChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ProgressBarChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_VALUE", &::Urho3D::ProgressBarChanged::P_VALUE, "todo: var docstring")
; // End Namespace Class ProgressBarChanged
  // Namespace vars class ProgressBarChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Released namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DReleased {};

auto pyclass_NS__Urho3D_Released = py::class_<PythonBindingsFakeModuleUrho3DReleased>(m, "Released")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Released::P_ELEMENT, "todo: var docstring")
; // End Namespace Class Released
  // Namespace vars class Released

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ReloadFailed namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DReloadFailed {};

auto pyclass_NS__Urho3D_ReloadFailed = py::class_<PythonBindingsFakeModuleUrho3DReloadFailed>(m, "ReloadFailed")
  // Functions
  // Variables
  
; // End Namespace Class ReloadFailed
  // Namespace vars class ReloadFailed

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ReloadFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DReloadFinished {};

auto pyclass_NS__Urho3D_ReloadFinished = py::class_<PythonBindingsFakeModuleUrho3DReloadFinished>(m, "ReloadFinished")
  // Functions
  // Variables
  
; // End Namespace Class ReloadFinished
  // Namespace vars class ReloadFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ReloadStarted namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DReloadStarted {};

auto pyclass_NS__Urho3D_ReloadStarted = py::class_<PythonBindingsFakeModuleUrho3DReloadStarted>(m, "ReloadStarted")
  // Functions
  // Variables
  
; // End Namespace Class ReloadStarted
  // Namespace vars class ReloadStarted

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export RemoteEventData namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DRemoteEventData {};

auto pyclass_NS__Urho3D_RemoteEventData = py::class_<PythonBindingsFakeModuleUrho3DRemoteEventData>(m, "RemoteEventData")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONNECTION", &::Urho3D::RemoteEventData::P_CONNECTION, "todo: var docstring")
; // End Namespace Class RemoteEventData
  // Namespace vars class RemoteEventData

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export RenderPathEvent namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DRenderPathEvent {};

auto pyclass_NS__Urho3D_RenderPathEvent = py::class_<PythonBindingsFakeModuleUrho3DRenderPathEvent>(m, "RenderPathEvent")
  // Functions
  // Variables
  
  .def_readonly_static("P_NAME", &::Urho3D::RenderPathEvent::P_NAME, "todo: var docstring")
; // End Namespace Class RenderPathEvent
  // Namespace vars class RenderPathEvent

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export RenderSurfaceUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DRenderSurfaceUpdate {};

auto pyclass_NS__Urho3D_RenderSurfaceUpdate = py::class_<PythonBindingsFakeModuleUrho3DRenderSurfaceUpdate>(m, "RenderSurfaceUpdate")
  // Functions
  // Variables
  
; // End Namespace Class RenderSurfaceUpdate
  // Namespace vars class RenderSurfaceUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export RenderUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DRenderUpdate {};

auto pyclass_NS__Urho3D_RenderUpdate = py::class_<PythonBindingsFakeModuleUrho3DRenderUpdate>(m, "RenderUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_TIMESTEP", &::Urho3D::RenderUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class RenderUpdate
  // Namespace vars class RenderUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Resized namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DResized {};

auto pyclass_NS__Urho3D_Resized = py::class_<PythonBindingsFakeModuleUrho3DResized>(m, "Resized")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Resized::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_WIDTH", &::Urho3D::Resized::P_WIDTH, "todo: var docstring")
  .def_readonly_static("P_HEIGHT", &::Urho3D::Resized::P_HEIGHT, "todo: var docstring")
  .def_readonly_static("P_DX", &::Urho3D::Resized::P_DX, "todo: var docstring")
  .def_readonly_static("P_DY", &::Urho3D::Resized::P_DY, "todo: var docstring")
; // End Namespace Class Resized
  // Namespace vars class Resized

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ResourceBackgroundLoaded namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DResourceBackgroundLoaded {};

auto pyclass_NS__Urho3D_ResourceBackgroundLoaded = py::class_<PythonBindingsFakeModuleUrho3DResourceBackgroundLoaded>(m, "ResourceBackgroundLoaded")
  // Functions
  // Variables
  
  .def_readonly_static("P_RESOURCENAME", &::Urho3D::ResourceBackgroundLoaded::P_RESOURCENAME, "todo: var docstring")
  .def_readonly_static("P_SUCCESS", &::Urho3D::ResourceBackgroundLoaded::P_SUCCESS, "todo: var docstring")
  .def_readonly_static("P_RESOURCE", &::Urho3D::ResourceBackgroundLoaded::P_RESOURCE, "todo: var docstring")
; // End Namespace Class ResourceBackgroundLoaded
  // Namespace vars class ResourceBackgroundLoaded

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ResourceNotFound namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DResourceNotFound {};

auto pyclass_NS__Urho3D_ResourceNotFound = py::class_<PythonBindingsFakeModuleUrho3DResourceNotFound>(m, "ResourceNotFound")
  // Functions
  // Variables
  
  .def_readonly_static("P_RESOURCENAME", &::Urho3D::ResourceNotFound::P_RESOURCENAME, "todo: var docstring")
; // End Namespace Class ResourceNotFound
  // Namespace vars class ResourceNotFound

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SDLRawInput namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSDLRawInput {};

auto pyclass_NS__Urho3D_SDLRawInput = py::class_<PythonBindingsFakeModuleUrho3DSDLRawInput>(m, "SDLRawInput")
  // Functions
  // Variables
  
  .def_readonly_static("P_SDLEVENT", &::Urho3D::SDLRawInput::P_SDLEVENT, "todo: var docstring")
  .def_readonly_static("P_CONSUMED", &::Urho3D::SDLRawInput::P_CONSUMED, "todo: var docstring")
; // End Namespace Class SDLRawInput
  // Namespace vars class SDLRawInput

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SceneDrawableUpdateFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSceneDrawableUpdateFinished {};

auto pyclass_NS__Urho3D_SceneDrawableUpdateFinished = py::class_<PythonBindingsFakeModuleUrho3DSceneDrawableUpdateFinished>(m, "SceneDrawableUpdateFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::SceneDrawableUpdateFinished::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::SceneDrawableUpdateFinished::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class SceneDrawableUpdateFinished
  // Namespace vars class SceneDrawableUpdateFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ScenePostUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DScenePostUpdate {};

auto pyclass_NS__Urho3D_ScenePostUpdate = py::class_<PythonBindingsFakeModuleUrho3DScenePostUpdate>(m, "ScenePostUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::ScenePostUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::ScenePostUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class ScenePostUpdate
  // Namespace vars class ScenePostUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SceneSubsystemUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSceneSubsystemUpdate {};

auto pyclass_NS__Urho3D_SceneSubsystemUpdate = py::class_<PythonBindingsFakeModuleUrho3DSceneSubsystemUpdate>(m, "SceneSubsystemUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::SceneSubsystemUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::SceneSubsystemUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class SceneSubsystemUpdate
  // Namespace vars class SceneSubsystemUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SceneUpdate namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSceneUpdate {};

auto pyclass_NS__Urho3D_SceneUpdate = py::class_<PythonBindingsFakeModuleUrho3DSceneUpdate>(m, "SceneUpdate")
  // Functions
  // Variables
  
  .def_readonly_static("P_SCENE", &::Urho3D::SceneUpdate::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_TIMESTEP", &::Urho3D::SceneUpdate::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class SceneUpdate
  // Namespace vars class SceneUpdate

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ScreenMode namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DScreenMode {};

auto pyclass_NS__Urho3D_ScreenMode = py::class_<PythonBindingsFakeModuleUrho3DScreenMode>(m, "ScreenMode")
  // Functions
  // Variables
  
  .def_readonly_static("P_WIDTH", &::Urho3D::ScreenMode::P_WIDTH, "todo: var docstring")
  .def_readonly_static("P_HEIGHT", &::Urho3D::ScreenMode::P_HEIGHT, "todo: var docstring")
  .def_readonly_static("P_FULLSCREEN", &::Urho3D::ScreenMode::P_FULLSCREEN, "todo: var docstring")
  .def_readonly_static("P_BORDERLESS", &::Urho3D::ScreenMode::P_BORDERLESS, "todo: var docstring")
  .def_readonly_static("P_RESIZABLE", &::Urho3D::ScreenMode::P_RESIZABLE, "todo: var docstring")
  .def_readonly_static("P_HIGHDPI", &::Urho3D::ScreenMode::P_HIGHDPI, "todo: var docstring")
  .def_readonly_static("P_MONITOR", &::Urho3D::ScreenMode::P_MONITOR, "todo: var docstring")
  .def_readonly_static("P_REFRESHRATE", &::Urho3D::ScreenMode::P_REFRESHRATE, "todo: var docstring")
; // End Namespace Class ScreenMode
  // Namespace vars class ScreenMode

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ScrollBarChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DScrollBarChanged {};

auto pyclass_NS__Urho3D_ScrollBarChanged = py::class_<PythonBindingsFakeModuleUrho3DScrollBarChanged>(m, "ScrollBarChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ScrollBarChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_VALUE", &::Urho3D::ScrollBarChanged::P_VALUE, "todo: var docstring")
; // End Namespace Class ScrollBarChanged
  // Namespace vars class ScrollBarChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SelectionChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSelectionChanged {};

auto pyclass_NS__Urho3D_SelectionChanged = py::class_<PythonBindingsFakeModuleUrho3DSelectionChanged>(m, "SelectionChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::SelectionChanged::P_ELEMENT, "todo: var docstring")
; // End Namespace Class SelectionChanged
  // Namespace vars class SelectionChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ServerConnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DServerConnected {};

auto pyclass_NS__Urho3D_ServerConnected = py::class_<PythonBindingsFakeModuleUrho3DServerConnected>(m, "ServerConnected")
  // Functions
  // Variables
  
; // End Namespace Class ServerConnected
  // Namespace vars class ServerConnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ServerDisconnected namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DServerDisconnected {};

auto pyclass_NS__Urho3D_ServerDisconnected = py::class_<PythonBindingsFakeModuleUrho3DServerDisconnected>(m, "ServerDisconnected")
  // Functions
  // Variables
  
; // End Namespace Class ServerDisconnected
  // Namespace vars class ServerDisconnected

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SliderChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSliderChanged {};

auto pyclass_NS__Urho3D_SliderChanged = py::class_<PythonBindingsFakeModuleUrho3DSliderChanged>(m, "SliderChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::SliderChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_VALUE", &::Urho3D::SliderChanged::P_VALUE, "todo: var docstring")
; // End Namespace Class SliderChanged
  // Namespace vars class SliderChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SliderPaged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSliderPaged {};

auto pyclass_NS__Urho3D_SliderPaged = py::class_<PythonBindingsFakeModuleUrho3DSliderPaged>(m, "SliderPaged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::SliderPaged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_OFFSET", &::Urho3D::SliderPaged::P_OFFSET, "todo: var docstring")
  .def_readonly_static("P_PRESSED", &::Urho3D::SliderPaged::P_PRESSED, "todo: var docstring")
; // End Namespace Class SliderPaged
  // Namespace vars class SliderPaged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export SoundFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSoundFinished {};

auto pyclass_NS__Urho3D_SoundFinished = py::class_<PythonBindingsFakeModuleUrho3DSoundFinished>(m, "SoundFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::SoundFinished::P_NODE, "todo: var docstring")
  .def_readonly_static("P_SOUNDSOURCE", &::Urho3D::SoundFinished::P_SOUNDSOURCE, "todo: var docstring")
  .def_readonly_static("P_SOUND", &::Urho3D::SoundFinished::P_SOUND, "todo: var docstring")
; // End Namespace Class SoundFinished
  // Namespace vars class SoundFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Spriter namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DSpriter {};

auto pyclass_NS__Urho3D_Spriter = py::class_<PythonBindingsFakeModuleUrho3DSpriter>(m, "Spriter")
  // Functions
  // Variables
  
; // End Namespace Class Spriter
  // Namespace vars class Spriter

  // Declare class variables
// Class Animation
auto pyclass_Var_Urho3D_Spriter_Animation = py::class_<Urho3D::Spriter::Animation>(pyclass_NS__Urho3D_Spriter, "Animation", "test doc");
// Class BoneTimelineKey
auto pyclass_Var_Urho3D_Spriter_BoneTimelineKey = py::class_<Urho3D::Spriter::BoneTimelineKey, Urho3D::Spriter::SpatialTimelineKey>(pyclass_NS__Urho3D_Spriter, "BoneTimelineKey", "test doc");
// Class CharacterMap
auto pyclass_Var_Urho3D_Spriter_CharacterMap = py::class_<Urho3D::Spriter::CharacterMap>(pyclass_NS__Urho3D_Spriter, "CharacterMap", "test doc");
// Class Entity
auto pyclass_Var_Urho3D_Spriter_Entity = py::class_<Urho3D::Spriter::Entity>(pyclass_NS__Urho3D_Spriter, "Entity", "test doc");
// Class File
auto pyclass_Var_Urho3D_Spriter_File = py::class_<Urho3D::Spriter::File>(pyclass_NS__Urho3D_Spriter, "File", "test doc");
// Class Folder
auto pyclass_Var_Urho3D_Spriter_Folder = py::class_<Urho3D::Spriter::Folder>(pyclass_NS__Urho3D_Spriter, "Folder", "test doc");
// Class MainlineKey
auto pyclass_Var_Urho3D_Spriter_MainlineKey = py::class_<Urho3D::Spriter::MainlineKey>(pyclass_NS__Urho3D_Spriter, "MainlineKey", "test doc");
// Class MapInstruction
auto pyclass_Var_Urho3D_Spriter_MapInstruction = py::class_<Urho3D::Spriter::MapInstruction>(pyclass_NS__Urho3D_Spriter, "MapInstruction", "test doc");
// Class Ref
auto pyclass_Var_Urho3D_Spriter_Ref = py::class_<Urho3D::Spriter::Ref>(pyclass_NS__Urho3D_Spriter, "Ref", "test doc");
// Class SpatialInfo
auto pyclass_Var_Urho3D_Spriter_SpatialInfo = py::class_<Urho3D::Spriter::SpatialInfo>(pyclass_NS__Urho3D_Spriter, "SpatialInfo", "test doc");
// Class TimelineKey
auto pyclass_Var_Urho3D_Spriter_TimelineKey = py::class_<Urho3D::Spriter::TimelineKey>(pyclass_NS__Urho3D_Spriter, "TimelineKey", "test doc");
// Class SpatialTimelineKey
auto pyclass_Var_Urho3D_Spriter_SpatialTimelineKey = py::class_<Urho3D::Spriter::SpatialTimelineKey, Urho3D::Spriter::TimelineKey>(pyclass_NS__Urho3D_Spriter, "SpatialTimelineKey", "test doc");
// Class SpriteTimelineKey
auto pyclass_Var_Urho3D_Spriter_SpriteTimelineKey = py::class_<Urho3D::Spriter::SpriteTimelineKey, Urho3D::Spriter::SpatialTimelineKey>(pyclass_NS__Urho3D_Spriter, "SpriteTimelineKey", "test doc");
// Class SpriterData
auto pyclass_Var_Urho3D_Spriter_SpriterData = py::class_<Urho3D::Spriter::SpriterData>(pyclass_NS__Urho3D_Spriter, "SpriterData", "test doc");
// Class SpriterInstance
auto pyclass_Var_Urho3D_Spriter_SpriterInstance = py::class_<Urho3D::Spriter::SpriterInstance>(pyclass_NS__Urho3D_Spriter, "SpriterInstance", "test doc");
// Class Timeline
auto pyclass_Var_Urho3D_Spriter_Timeline = py::class_<Urho3D::Spriter::Timeline>(pyclass_NS__Urho3D_Spriter, "Timeline", "test doc");

  // Register class details

// Class Animation
  pyclass_Var_Urho3D_Spriter_Animation
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::Animation::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::Animation::name_, "todo: var docstring")
  .def_readwrite("length_", &Urho3D::Spriter::Animation::length_, "todo: var docstring")
  .def_readwrite("looping_", &Urho3D::Spriter::Animation::looping_, "todo: var docstring")
  .def_readwrite("mainlineKeys_", &Urho3D::Spriter::Animation::mainlineKeys_, "todo: var docstring")
  .def_readwrite("timelines_", &Urho3D::Spriter::Animation::timelines_, "todo: var docstring")
; // End Class Animation

// Class BoneTimelineKey
  pyclass_Var_Urho3D_Spriter_BoneTimelineKey
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("length_", &Urho3D::Spriter::BoneTimelineKey::length_, "todo: var docstring")
  .def_readwrite("width_", &Urho3D::Spriter::BoneTimelineKey::width_, "todo: var docstring")
; // End Class BoneTimelineKey

// Class CharacterMap
  pyclass_Var_Urho3D_Spriter_CharacterMap
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::CharacterMap::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::CharacterMap::name_, "todo: var docstring")
  .def_readwrite("maps_", &Urho3D::Spriter::CharacterMap::maps_, "todo: var docstring")
; // End Class CharacterMap

// Class Entity
  pyclass_Var_Urho3D_Spriter_Entity
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::Entity::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::Entity::name_, "todo: var docstring")
  .def_readwrite("characterMaps_", &Urho3D::Spriter::Entity::characterMaps_, "todo: var docstring")
  .def_readwrite("animations_", &Urho3D::Spriter::Entity::animations_, "todo: var docstring")
; // End Class Entity

// Class File
  pyclass_Var_Urho3D_Spriter_File
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("folder_", &Urho3D::Spriter::File::folder_, "todo: var docstring")
  .def_readwrite("id_", &Urho3D::Spriter::File::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::File::name_, "todo: var docstring")
  .def_readwrite("width_", &Urho3D::Spriter::File::width_, "todo: var docstring")
  .def_readwrite("height_", &Urho3D::Spriter::File::height_, "todo: var docstring")
  .def_readwrite("pivotX_", &Urho3D::Spriter::File::pivotX_, "todo: var docstring")
  .def_readwrite("pivotY_", &Urho3D::Spriter::File::pivotY_, "todo: var docstring")
; // End Class File

// Class Folder
  pyclass_Var_Urho3D_Spriter_Folder
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::Folder::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::Folder::name_, "todo: var docstring")
  .def_readwrite("files_", &Urho3D::Spriter::Folder::files_, "todo: var docstring")
; // End Class Folder

// Class MainlineKey
  pyclass_Var_Urho3D_Spriter_MainlineKey
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::MainlineKey::id_, "todo: var docstring")
  .def_readwrite("time_", &Urho3D::Spriter::MainlineKey::time_, "todo: var docstring")
  .def_readwrite("boneRefs_", &Urho3D::Spriter::MainlineKey::boneRefs_, "todo: var docstring")
  .def_readwrite("objectRefs_", &Urho3D::Spriter::MainlineKey::objectRefs_, "todo: var docstring")
; // End Class MainlineKey

// Class MapInstruction
  pyclass_Var_Urho3D_Spriter_MapInstruction
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("folder_", &Urho3D::Spriter::MapInstruction::folder_, "todo: var docstring")
  .def_readwrite("file_", &Urho3D::Spriter::MapInstruction::file_, "todo: var docstring")
  .def_readwrite("targetFolder_", &Urho3D::Spriter::MapInstruction::targetFolder_, "todo: var docstring")
  .def_readwrite("targetFile_", &Urho3D::Spriter::MapInstruction::targetFile_, "todo: var docstring")
; // End Class MapInstruction

// Class Ref
  pyclass_Var_Urho3D_Spriter_Ref
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::Ref::id_, "todo: var docstring")
  .def_readwrite("parent_", &Urho3D::Spriter::Ref::parent_, "todo: var docstring")
  .def_readwrite("timeline_", &Urho3D::Spriter::Ref::timeline_, "todo: var docstring")
  .def_readwrite("key_", &Urho3D::Spriter::Ref::key_, "todo: var docstring")
  .def_readwrite("zIndex_", &Urho3D::Spriter::Ref::zIndex_, "todo: var docstring")
; // End Class Ref

// Class SpatialInfo
  pyclass_Var_Urho3D_Spriter_SpatialInfo
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("x_", &Urho3D::Spriter::SpatialInfo::x_, "todo: var docstring")
  .def_readwrite("y_", &Urho3D::Spriter::SpatialInfo::y_, "todo: var docstring")
  .def_readwrite("angle_", &Urho3D::Spriter::SpatialInfo::angle_, "todo: var docstring")
  .def_readwrite("scaleX_", &Urho3D::Spriter::SpatialInfo::scaleX_, "todo: var docstring")
  .def_readwrite("scaleY_", &Urho3D::Spriter::SpatialInfo::scaleY_, "todo: var docstring")
  .def_readwrite("alpha_", &Urho3D::Spriter::SpatialInfo::alpha_, "todo: var docstring")
  .def_readwrite("spin", &Urho3D::Spriter::SpatialInfo::spin, "todo: var docstring")
; // End Class SpatialInfo

// Class TimelineKey
  pyclass_Var_Urho3D_Spriter_TimelineKey
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("timeline_", &Urho3D::Spriter::TimelineKey::timeline_, "todo: var docstring")
  .def_readwrite("id_", &Urho3D::Spriter::TimelineKey::id_, "todo: var docstring")
  .def_readwrite("time_", &Urho3D::Spriter::TimelineKey::time_, "todo: var docstring")
  .def_readwrite("curveType_", &Urho3D::Spriter::TimelineKey::curveType_, "todo: var docstring")
  .def_readwrite("c1_", &Urho3D::Spriter::TimelineKey::c1_, "todo: var docstring")
  .def_readwrite("c2_", &Urho3D::Spriter::TimelineKey::c2_, "todo: var docstring")
; // End Class TimelineKey

// Class SpatialTimelineKey
  pyclass_Var_Urho3D_Spriter_SpatialTimelineKey
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("info_", &Urho3D::Spriter::SpatialTimelineKey::info_, "todo: var docstring")
; // End Class SpatialTimelineKey

// Class SpriteTimelineKey
  pyclass_Var_Urho3D_Spriter_SpriteTimelineKey
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("folderId_", &Urho3D::Spriter::SpriteTimelineKey::folderId_, "todo: var docstring")
  .def_readwrite("fileId_", &Urho3D::Spriter::SpriteTimelineKey::fileId_, "todo: var docstring")
  .def_readwrite("useDefaultPivot_", &Urho3D::Spriter::SpriteTimelineKey::useDefaultPivot_, "todo: var docstring")
  .def_readwrite("pivotX_", &Urho3D::Spriter::SpriteTimelineKey::pivotX_, "todo: var docstring")
  .def_readwrite("pivotY_", &Urho3D::Spriter::SpriteTimelineKey::pivotY_, "todo: var docstring")
  .def_readwrite("zIndex_", &Urho3D::Spriter::SpriteTimelineKey::zIndex_, "todo: var docstring")
; // End Class SpriteTimelineKey

// Class SpriterData
  pyclass_Var_Urho3D_Spriter_SpriterData
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("scmlVersion_", &Urho3D::Spriter::SpriterData::scmlVersion_, "todo: var docstring")
  .def_readwrite("generator_", &Urho3D::Spriter::SpriterData::generator_, "todo: var docstring")
  .def_readwrite("generatorVersion_", &Urho3D::Spriter::SpriterData::generatorVersion_, "todo: var docstring")
  .def_readwrite("folders_", &Urho3D::Spriter::SpriterData::folders_, "todo: var docstring")
  .def_readwrite("entities_", &Urho3D::Spriter::SpriterData::entities_, "todo: var docstring")
; // End Class SpriterData

// Class SpriterInstance
  pyclass_Var_Urho3D_Spriter_SpriterInstance
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class SpriterInstance

// Class Timeline
  pyclass_Var_Urho3D_Spriter_Timeline
  // Constructors
  // Methods
  // Operators
  // Variables
  .def_readwrite("id_", &Urho3D::Spriter::Timeline::id_, "todo: var docstring")
  .def_readwrite("name_", &Urho3D::Spriter::Timeline::name_, "todo: var docstring")
  .def_readwrite("objectType_", &Urho3D::Spriter::Timeline::objectType_, "todo: var docstring")
  .def_readwrite("keys_", &Urho3D::Spriter::Timeline::keys_, "todo: var docstring")
; // End Class Timeline

//-------------------------------------------
// Export TargetPositionChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTargetPositionChanged {};

auto pyclass_NS__Urho3D_TargetPositionChanged = py::class_<PythonBindingsFakeModuleUrho3DTargetPositionChanged>(m, "TargetPositionChanged")
  // Functions
  // Variables
  
; // End Namespace Class TargetPositionChanged
  // Namespace vars class TargetPositionChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TargetRotationChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTargetRotationChanged {};

auto pyclass_NS__Urho3D_TargetRotationChanged = py::class_<PythonBindingsFakeModuleUrho3DTargetRotationChanged>(m, "TargetRotationChanged")
  // Functions
  // Variables
  
; // End Namespace Class TargetRotationChanged
  // Namespace vars class TargetRotationChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TemporaryChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTemporaryChanged {};

auto pyclass_NS__Urho3D_TemporaryChanged = py::class_<PythonBindingsFakeModuleUrho3DTemporaryChanged>(m, "TemporaryChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_SERIALIZABLE", &::Urho3D::TemporaryChanged::P_SERIALIZABLE, "todo: var docstring")
; // End Namespace Class TemporaryChanged
  // Namespace vars class TemporaryChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TerrainCreated namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTerrainCreated {};

auto pyclass_NS__Urho3D_TerrainCreated = py::class_<PythonBindingsFakeModuleUrho3DTerrainCreated>(m, "TerrainCreated")
  // Functions
  // Variables
  
  .def_readonly_static("P_NODE", &::Urho3D::TerrainCreated::P_NODE, "todo: var docstring")
; // End Namespace Class TerrainCreated
  // Namespace vars class TerrainCreated

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TextChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTextChanged {};

auto pyclass_NS__Urho3D_TextChanged = py::class_<PythonBindingsFakeModuleUrho3DTextChanged>(m, "TextChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::TextChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_TEXT", &::Urho3D::TextChanged::P_TEXT, "todo: var docstring")
; // End Namespace Class TextChanged
  // Namespace vars class TextChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TextEditing namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTextEditing {};

auto pyclass_NS__Urho3D_TextEditing = py::class_<PythonBindingsFakeModuleUrho3DTextEditing>(m, "TextEditing")
  // Functions
  // Variables
  
  .def_readonly_static("P_COMPOSITION", &::Urho3D::TextEditing::P_COMPOSITION, "todo: var docstring")
  .def_readonly_static("P_CURSOR", &::Urho3D::TextEditing::P_CURSOR, "todo: var docstring")
  .def_readonly_static("P_SELECTION_LENGTH", &::Urho3D::TextEditing::P_SELECTION_LENGTH, "todo: var docstring")
; // End Namespace Class TextEditing
  // Namespace vars class TextEditing

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TextEntry namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTextEntry {};

auto pyclass_NS__Urho3D_TextEntry = py::class_<PythonBindingsFakeModuleUrho3DTextEntry>(m, "TextEntry")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::TextEntry::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_TEXT", &::Urho3D::TextEntry::P_TEXT, "todo: var docstring")
; // End Namespace Class TextEntry
  // Namespace vars class TextEntry

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TextFinished namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTextFinished {};

auto pyclass_NS__Urho3D_TextFinished = py::class_<PythonBindingsFakeModuleUrho3DTextFinished>(m, "TextFinished")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::TextFinished::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_TEXT", &::Urho3D::TextFinished::P_TEXT, "todo: var docstring")
  .def_readonly_static("P_VALUE", &::Urho3D::TextFinished::P_VALUE, "todo: var docstring")
; // End Namespace Class TextFinished
  // Namespace vars class TextFinished

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TextInput namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTextInput {};

auto pyclass_NS__Urho3D_TextInput = py::class_<PythonBindingsFakeModuleUrho3DTextInput>(m, "TextInput")
  // Functions
  // Variables
  
  .def_readonly_static("P_TEXT", &::Urho3D::TextInput::P_TEXT, "todo: var docstring")
; // End Namespace Class TextInput
  // Namespace vars class TextInput

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Toggled namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DToggled {};

auto pyclass_NS__Urho3D_Toggled = py::class_<PythonBindingsFakeModuleUrho3DToggled>(m, "Toggled")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::Toggled::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_STATE", &::Urho3D::Toggled::P_STATE, "todo: var docstring")
; // End Namespace Class Toggled
  // Namespace vars class Toggled

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TouchBegin namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTouchBegin {};

auto pyclass_NS__Urho3D_TouchBegin = py::class_<PythonBindingsFakeModuleUrho3DTouchBegin>(m, "TouchBegin")
  // Functions
  // Variables
  
  .def_readonly_static("P_TOUCHID", &::Urho3D::TouchBegin::P_TOUCHID, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::TouchBegin::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::TouchBegin::P_Y, "todo: var docstring")
  .def_readonly_static("P_PRESSURE", &::Urho3D::TouchBegin::P_PRESSURE, "todo: var docstring")
; // End Namespace Class TouchBegin
  // Namespace vars class TouchBegin

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TouchEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTouchEnd {};

auto pyclass_NS__Urho3D_TouchEnd = py::class_<PythonBindingsFakeModuleUrho3DTouchEnd>(m, "TouchEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_TOUCHID", &::Urho3D::TouchEnd::P_TOUCHID, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::TouchEnd::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::TouchEnd::P_Y, "todo: var docstring")
; // End Namespace Class TouchEnd
  // Namespace vars class TouchEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export TouchMove namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DTouchMove {};

auto pyclass_NS__Urho3D_TouchMove = py::class_<PythonBindingsFakeModuleUrho3DTouchMove>(m, "TouchMove")
  // Functions
  // Variables
  
  .def_readonly_static("P_TOUCHID", &::Urho3D::TouchMove::P_TOUCHID, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::TouchMove::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::TouchMove::P_Y, "todo: var docstring")
  .def_readonly_static("P_DX", &::Urho3D::TouchMove::P_DX, "todo: var docstring")
  .def_readonly_static("P_DY", &::Urho3D::TouchMove::P_DY, "todo: var docstring")
  .def_readonly_static("P_PRESSURE", &::Urho3D::TouchMove::P_PRESSURE, "todo: var docstring")
; // End Namespace Class TouchMove
  // Namespace vars class TouchMove

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UIDropFile namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUIDropFile {};

auto pyclass_NS__Urho3D_UIDropFile = py::class_<PythonBindingsFakeModuleUrho3DUIDropFile>(m, "UIDropFile")
  // Functions
  // Variables
  
  .def_readonly_static("P_FILENAME", &::Urho3D::UIDropFile::P_FILENAME, "todo: var docstring")
  .def_readonly_static("P_ELEMENT", &::Urho3D::UIDropFile::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::UIDropFile::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::UIDropFile::P_Y, "todo: var docstring")
  .def_readonly_static("P_ELEMENTX", &::Urho3D::UIDropFile::P_ELEMENTX, "todo: var docstring")
  .def_readonly_static("P_ELEMENTY", &::Urho3D::UIDropFile::P_ELEMENTY, "todo: var docstring")
; // End Namespace Class UIDropFile
  // Namespace vars class UIDropFile

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UIMouseClick namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUIMouseClick {};

auto pyclass_NS__Urho3D_UIMouseClick = py::class_<PythonBindingsFakeModuleUrho3DUIMouseClick>(m, "UIMouseClick")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::UIMouseClick::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::UIMouseClick::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::UIMouseClick::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::UIMouseClick::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::UIMouseClick::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::UIMouseClick::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class UIMouseClick
  // Namespace vars class UIMouseClick

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UIMouseClickEnd namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUIMouseClickEnd {};

auto pyclass_NS__Urho3D_UIMouseClickEnd = py::class_<PythonBindingsFakeModuleUrho3DUIMouseClickEnd>(m, "UIMouseClickEnd")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::UIMouseClickEnd::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_BEGINELEMENT", &::Urho3D::UIMouseClickEnd::P_BEGINELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::UIMouseClickEnd::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::UIMouseClickEnd::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::UIMouseClickEnd::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::UIMouseClickEnd::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::UIMouseClickEnd::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class UIMouseClickEnd
  // Namespace vars class UIMouseClickEnd

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UIMouseDoubleClick namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUIMouseDoubleClick {};

auto pyclass_NS__Urho3D_UIMouseDoubleClick = py::class_<PythonBindingsFakeModuleUrho3DUIMouseDoubleClick>(m, "UIMouseDoubleClick")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::UIMouseDoubleClick::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::UIMouseDoubleClick::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::UIMouseDoubleClick::P_Y, "todo: var docstring")
  .def_readonly_static("P_BUTTON", &::Urho3D::UIMouseDoubleClick::P_BUTTON, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::UIMouseDoubleClick::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::UIMouseDoubleClick::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class UIMouseDoubleClick
  // Namespace vars class UIMouseDoubleClick

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UnhandledKey namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUnhandledKey {};

auto pyclass_NS__Urho3D_UnhandledKey = py::class_<PythonBindingsFakeModuleUrho3DUnhandledKey>(m, "UnhandledKey")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::UnhandledKey::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_KEY", &::Urho3D::UnhandledKey::P_KEY, "todo: var docstring")
  .def_readonly_static("P_BUTTONS", &::Urho3D::UnhandledKey::P_BUTTONS, "todo: var docstring")
  .def_readonly_static("P_QUALIFIERS", &::Urho3D::UnhandledKey::P_QUALIFIERS, "todo: var docstring")
; // End Namespace Class UnhandledKey
  // Namespace vars class UnhandledKey

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UnknownResourceType namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUnknownResourceType {};

auto pyclass_NS__Urho3D_UnknownResourceType = py::class_<PythonBindingsFakeModuleUrho3DUnknownResourceType>(m, "UnknownResourceType")
  // Functions
  // Variables
  
  .def_readonly_static("P_RESOURCETYPE", &::Urho3D::UnknownResourceType::P_RESOURCETYPE, "todo: var docstring")
; // End Namespace Class UnknownResourceType
  // Namespace vars class UnknownResourceType

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export Update namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUpdate {};

auto pyclass_NS__Urho3D_Update = py::class_<PythonBindingsFakeModuleUrho3DUpdate>(m, "Update")
  // Functions
  // Variables
  
  .def_readonly_static("P_TIMESTEP", &::Urho3D::Update::P_TIMESTEP, "todo: var docstring")
; // End Namespace Class Update
  // Namespace vars class Update

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export UpdateSmoothing namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DUpdateSmoothing {};

auto pyclass_NS__Urho3D_UpdateSmoothing = py::class_<PythonBindingsFakeModuleUrho3DUpdateSmoothing>(m, "UpdateSmoothing")
  // Functions
  // Variables
  
  .def_readonly_static("P_CONSTANT", &::Urho3D::UpdateSmoothing::P_CONSTANT, "todo: var docstring")
  .def_readonly_static("P_SQUAREDSNAPTHRESHOLD", &::Urho3D::UpdateSmoothing::P_SQUAREDSNAPTHRESHOLD, "todo: var docstring")
; // End Namespace Class UpdateSmoothing
  // Namespace vars class UpdateSmoothing

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ViewBuffersReady namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DViewBuffersReady {};

auto pyclass_NS__Urho3D_ViewBuffersReady = py::class_<PythonBindingsFakeModuleUrho3DViewBuffersReady>(m, "ViewBuffersReady")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::ViewBuffersReady::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::ViewBuffersReady::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::ViewBuffersReady::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::ViewBuffersReady::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::ViewBuffersReady::P_CAMERA, "todo: var docstring")
; // End Namespace Class ViewBuffersReady
  // Namespace vars class ViewBuffersReady

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ViewChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DViewChanged {};

auto pyclass_NS__Urho3D_ViewChanged = py::class_<PythonBindingsFakeModuleUrho3DViewChanged>(m, "ViewChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::ViewChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_X", &::Urho3D::ViewChanged::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::ViewChanged::P_Y, "todo: var docstring")
; // End Namespace Class ViewChanged
  // Namespace vars class ViewChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export ViewGlobalShaderParameters namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DViewGlobalShaderParameters {};

auto pyclass_NS__Urho3D_ViewGlobalShaderParameters = py::class_<PythonBindingsFakeModuleUrho3DViewGlobalShaderParameters>(m, "ViewGlobalShaderParameters")
  // Functions
  // Variables
  
  .def_readonly_static("P_VIEW", &::Urho3D::ViewGlobalShaderParameters::P_VIEW, "todo: var docstring")
  .def_readonly_static("P_TEXTURE", &::Urho3D::ViewGlobalShaderParameters::P_TEXTURE, "todo: var docstring")
  .def_readonly_static("P_SURFACE", &::Urho3D::ViewGlobalShaderParameters::P_SURFACE, "todo: var docstring")
  .def_readonly_static("P_SCENE", &::Urho3D::ViewGlobalShaderParameters::P_SCENE, "todo: var docstring")
  .def_readonly_static("P_CAMERA", &::Urho3D::ViewGlobalShaderParameters::P_CAMERA, "todo: var docstring")
; // End Namespace Class ViewGlobalShaderParameters
  // Namespace vars class ViewGlobalShaderParameters

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export VisibleChanged namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DVisibleChanged {};

auto pyclass_NS__Urho3D_VisibleChanged = py::class_<PythonBindingsFakeModuleUrho3DVisibleChanged>(m, "VisibleChanged")
  // Functions
  // Variables
  
  .def_readonly_static("P_ELEMENT", &::Urho3D::VisibleChanged::P_ELEMENT, "todo: var docstring")
  .def_readonly_static("P_VISIBLE", &::Urho3D::VisibleChanged::P_VISIBLE, "todo: var docstring")
; // End Namespace Class VisibleChanged
  // Namespace vars class VisibleChanged

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export WindowPos namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DWindowPos {};

auto pyclass_NS__Urho3D_WindowPos = py::class_<PythonBindingsFakeModuleUrho3DWindowPos>(m, "WindowPos")
  // Functions
  // Variables
  
  .def_readonly_static("P_X", &::Urho3D::WindowPos::P_X, "todo: var docstring")
  .def_readonly_static("P_Y", &::Urho3D::WindowPos::P_Y, "todo: var docstring")
; // End Namespace Class WindowPos
  // Namespace vars class WindowPos

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export WorkItemCompleted namespace as a class
//-------------------------------------------

class PythonBindingsFakeModuleUrho3DWorkItemCompleted {};

auto pyclass_NS__Urho3D_WorkItemCompleted = py::class_<PythonBindingsFakeModuleUrho3DWorkItemCompleted>(m, "WorkItemCompleted")
  // Functions
  // Variables
  
  .def_readonly_static("P_ITEM", &::Urho3D::WorkItemCompleted::P_ITEM, "todo: var docstring")
; // End Namespace Class WorkItemCompleted
  // Namespace vars class WorkItemCompleted

  // Declare class variables

  // Register class details

//-------------------------------------------
// Export kNet namespace as a class
//-------------------------------------------

class PythonBindingsFakeModulekNet {};

auto pyclass_NS__kNet = py::class_<PythonBindingsFakeModulekNet>(m, "kNet")
  // Functions
  // Variables
  
; // End Namespace Class kNet
  // Namespace vars class kNet

  // Declare class variables
// Class IMessageHandler
auto pyclass_Var_kNet_IMessageHandler = py::class_<kNet::IMessageHandler>(pyclass_NS__kNet, "IMessageHandler", "test doc");
// Class INetworkServerListener
auto pyclass_Var_kNet_INetworkServerListener = py::class_<kNet::INetworkServerListener>(pyclass_NS__kNet, "INetworkServerListener", "test doc");
// Class RefCountable
auto pyclass_Var_kNet_RefCountable = py::class_<kNet::RefCountable>(pyclass_NS__kNet, "RefCountable", "test doc");

  // Register class details

// Class IMessageHandler
  pyclass_Var_kNet_IMessageHandler
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class IMessageHandler

// Class INetworkServerListener
  pyclass_Var_kNet_INetworkServerListener
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class INetworkServerListener

// Class RefCountable
  pyclass_Var_kNet_RefCountable
  // Constructors
  // Methods
  // Operators
  // Variables
; // End Class RefCountable

//-------------------------------------------
// Export pugi namespace as a class
//-------------------------------------------

class PythonBindingsFakeModulepugi {};

auto pyclass_NS__pugi = py::class_<PythonBindingsFakeModulepugi>(m, "pugi")
  // Functions
  // Variables
  
; // End Namespace Class pugi
  // Namespace vars class pugi

  // Declare class variables

  // Register class details


}

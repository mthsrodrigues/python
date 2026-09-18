// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME eventdict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "MyParticle.h"
#include "MyEvent.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_MyParticle(void *p = nullptr);
   static void *newArray_MyParticle(Long_t size, void *p);
   static void delete_MyParticle(void *p);
   static void deleteArray_MyParticle(void *p);
   static void destruct_MyParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyParticle*)
   {
      ::MyParticle *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyParticle >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("MyParticle", ::MyParticle::Class_Version(), "MyParticle.h", 8,
                  typeid(::MyParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MyParticle::Dictionary, isa_proxy, 4,
                  sizeof(::MyParticle) );
      instance.SetNew(&new_MyParticle);
      instance.SetNewArray(&newArray_MyParticle);
      instance.SetDelete(&delete_MyParticle);
      instance.SetDeleteArray(&deleteArray_MyParticle);
      instance.SetDestructor(&destruct_MyParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyParticle*)
   {
      return GenerateInitInstanceLocal(static_cast<::MyParticle*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::MyParticle*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyEvent(void *p = nullptr);
   static void *newArray_MyEvent(Long_t size, void *p);
   static void delete_MyEvent(void *p);
   static void deleteArray_MyEvent(void *p);
   static void destruct_MyEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyEvent*)
   {
      ::MyEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("MyEvent", ::MyEvent::Class_Version(), "MyEvent.h", 8,
                  typeid(::MyEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::MyEvent::Dictionary, isa_proxy, 4,
                  sizeof(::MyEvent) );
      instance.SetNew(&new_MyEvent);
      instance.SetNewArray(&newArray_MyEvent);
      instance.SetDelete(&delete_MyEvent);
      instance.SetDeleteArray(&deleteArray_MyEvent);
      instance.SetDestructor(&destruct_MyEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::MyEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::MyEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr MyParticle::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *MyParticle::Class_Name()
{
   return "MyParticle";
}

//______________________________________________________________________________
const char *MyParticle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyParticle*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int MyParticle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyParticle*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyParticle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyParticle*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyParticle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyParticle*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *MyEvent::Class_Name()
{
   return "MyEvent";
}

//______________________________________________________________________________
const char *MyEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int MyEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void MyParticle::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyParticle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyParticle::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyParticle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyParticle(void *p) {
      return  p ? new(p) ::MyParticle : new ::MyParticle;
   }
   static void *newArray_MyParticle(Long_t nElements, void *p) {
      return p ? new(p) ::MyParticle[nElements] : new ::MyParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyParticle(void *p) {
      delete (static_cast<::MyParticle*>(p));
   }
   static void deleteArray_MyParticle(void *p) {
      delete [] (static_cast<::MyParticle*>(p));
   }
   static void destruct_MyParticle(void *p) {
      typedef ::MyParticle current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::MyParticle

//______________________________________________________________________________
void MyEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyEvent(void *p) {
      return  p ? new(p) ::MyEvent : new ::MyEvent;
   }
   static void *newArray_MyEvent(Long_t nElements, void *p) {
      return p ? new(p) ::MyEvent[nElements] : new ::MyEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyEvent(void *p) {
      delete (static_cast<::MyEvent*>(p));
   }
   static void deleteArray_MyEvent(void *p) {
      delete [] (static_cast<::MyEvent*>(p));
   }
   static void destruct_MyEvent(void *p) {
      typedef ::MyEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::MyEvent

namespace ROOT {
   static TClass *vectorlEMyParticlegR_Dictionary();
   static void vectorlEMyParticlegR_TClassManip(TClass*);
   static void *new_vectorlEMyParticlegR(void *p = nullptr);
   static void *newArray_vectorlEMyParticlegR(Long_t size, void *p);
   static void delete_vectorlEMyParticlegR(void *p);
   static void deleteArray_vectorlEMyParticlegR(void *p);
   static void destruct_vectorlEMyParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyParticle>*)
   {
      vector<MyParticle> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyParticle>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyParticle>", -2, "vector", 428,
                  typeid(vector<MyParticle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEMyParticlegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyParticle>) );
      instance.SetNew(&new_vectorlEMyParticlegR);
      instance.SetNewArray(&newArray_vectorlEMyParticlegR);
      instance.SetDelete(&delete_vectorlEMyParticlegR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyParticlegR);
      instance.SetDestructor(&destruct_vectorlEMyParticlegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyParticle> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<MyParticle>","std::vector<MyParticle, std::allocator<MyParticle> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<MyParticle>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<MyParticle>*>(nullptr))->GetClass();
      vectorlEMyParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyParticlegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<MyParticle> : new vector<MyParticle>;
   }
   static void *newArray_vectorlEMyParticlegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<MyParticle>[nElements] : new vector<MyParticle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyParticlegR(void *p) {
      delete (static_cast<vector<MyParticle>*>(p));
   }
   static void deleteArray_vectorlEMyParticlegR(void *p) {
      delete [] (static_cast<vector<MyParticle>*>(p));
   }
   static void destruct_vectorlEMyParticlegR(void *p) {
      typedef vector<MyParticle> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<MyParticle>

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_eventdict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_eventdict) = RecordReadRules_eventdict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_eventdict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_eventdict_Impl() {
    static const char* headers[] = {
"MyParticle.h",
"MyEvent.h",
nullptr
    };
    static const char* includePaths[] = {
"/snap/root-framework/current/include",
"/snap/root-framework/954/usr/local/include/",
"/home/mdias/posdoc/unicamp/F056/git/Exemplos/Interfaces/Example4_rootcint/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "eventdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$MyParticle.h")))  MyParticle;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$MyEvent.h")))  MyEvent;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "eventdict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "MyParticle.h"
#include "MyEvent.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"MyEvent", payloadCode, "@",
"MyParticle", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("eventdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_eventdict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_eventdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_eventdict() {
  TriggerDictionaryInitialization_eventdict_Impl();
}

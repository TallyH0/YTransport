//
// File generated by rootcint at Thu Nov 23 23:22:05 2017

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME DopingDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "DopingDict.h"

#include "TClass.h"
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

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOTShadow {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOTShadow
// END OF SHADOWS

namespace ROOTDict {
   void Doping_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_Doping(void *p = 0);
   static void *newArray_Doping(Long_t size, void *p);
   static void delete_Doping(void *p);
   static void deleteArray_Doping(void *p);
   static void destruct_Doping(void *p);
   static void streamer_Doping(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::Doping*)
   {
      ::Doping *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Doping >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Doping", ::Doping::Class_Version(), "./Doping.h", 13,
                  typeid(::Doping), ::ROOT::DefineBehavior(ptr, ptr),
                  &::Doping::Dictionary, isa_proxy, 0,
                  sizeof(::Doping) );
      instance.SetNew(&new_Doping);
      instance.SetNewArray(&newArray_Doping);
      instance.SetDelete(&delete_Doping);
      instance.SetDeleteArray(&deleteArray_Doping);
      instance.SetDestructor(&destruct_Doping);
      instance.SetStreamerFunc(&streamer_Doping);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::Doping*)
   {
      return GenerateInitInstanceLocal((::Doping*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Doping*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOTDict

//______________________________________________________________________________
atomic_TClass_ptr Doping::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Doping::Class_Name()
{
   return "Doping";
}

//______________________________________________________________________________
const char *Doping::ImplFileName()
{
   return ::ROOTDict::GenerateInitInstanceLocal((const ::Doping*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Doping::ImplFileLine()
{
   return ::ROOTDict::GenerateInitInstanceLocal((const ::Doping*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void Doping::Dictionary()
{
   fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::Doping*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *Doping::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gCINTMutex); if(!fgIsA) {fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::Doping*)0x0)->GetClass();} }
   return fgIsA;
}

//______________________________________________________________________________
void Doping::Streamer(TBuffer &R__b)
{
   // Stream an object of class Doping.

   ::Error("Doping::Streamer", "version id <=0 in ClassDef, dummy Streamer() called"); if (R__b.IsReading()) { }
}

//______________________________________________________________________________
void Doping::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class Doping.
      TClass *R__cl = ::Doping::IsA();
      if (R__cl || R__insp.IsA()) { }
}

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_Doping(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Doping : new ::Doping;
   }
   static void *newArray_Doping(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Doping[nElements] : new ::Doping[nElements];
   }
   // Wrapper around operator delete
   static void delete_Doping(void *p) {
      delete ((::Doping*)p);
   }
   static void deleteArray_Doping(void *p) {
      delete [] ((::Doping*)p);
   }
   static void destruct_Doping(void *p) {
      typedef ::Doping current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Doping(TBuffer &buf, void *obj) {
      ((::Doping*)obj)->::Doping::Streamer(buf);
   }
} // end of namespace ROOTDict for class ::Doping

/********************************************************
* DopingDict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableDopingDict();

extern "C" void G__set_cpp_environmentDopingDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("Doping.h");
  G__cpp_reset_tagtableDopingDict();
}
#include <new>
extern "C" int G__cpp_dllrevDopingDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* Doping */
static int G__DopingDict_185_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   Doping* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new Doping[n];
     } else {
       p = new((void*) gvp) Doping[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new Doping;
     } else {
       p = new((void*) gvp) Doping;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__DopingDictLN_Doping));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) Doping::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Doping::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) Doping::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      Doping::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((const Doping*) G__getstructoffset())->IsA());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Doping*) G__getstructoffset())->ShowMembers(*(TMemberInspector*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Doping*) G__getstructoffset())->Streamer(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((Doping*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Doping::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) Doping::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) Doping::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__DopingDict_185_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) Doping::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__DopingDict_185_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   Doping* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new Doping(*(Doping*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__DopingDictLN_Doping));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef Doping G__TDoping;
static int G__DopingDict_185_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 0
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (Doping*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((Doping*) (soff+(sizeof(Doping)*i)))->~G__TDoping();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (Doping*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((Doping*) (soff))->~G__TDoping();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__DopingDict_185_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   Doping* dest = (Doping*) G__getstructoffset();
   *dest = *(Doping*) libp->para[0].ref;
   const Doping& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* Doping */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncDopingDict {
 public:
  G__Sizep2memfuncDopingDict(): p(&G__Sizep2memfuncDopingDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncDopingDict::*p)();
};

size_t G__get_sizep2memfuncDopingDict()
{
  G__Sizep2memfuncDopingDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceDopingDict() {

   /* Setting up class inheritance */
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableDopingDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__DopingDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__DopingDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__DopingDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__DopingDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* Doping */
static void G__setup_memvarDoping(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__DopingDictLN_Doping));
   { Doping *p; p=(Doping*)0x1000; if (p) { }
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__DopingDictLN_TClass),G__defined_typename("atomic_TClass_ptr"),-2,4,"fgIsA=",0,(char*)NULL);
   G__memvar_setup((void*)0,108,0,0,-1,-1,-1,4,"G__virtualinfo=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarDopingDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncDoping(void) {
   /* Doping */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__DopingDictLN_Doping));
   G__memfunc_setup("Doping",609,G__DopingDict_185_0_1, 105, G__get_linked_tagnum(&G__DopingDictLN_Doping), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__DopingDict_185_0_2, 85, G__get_linked_tagnum(&G__DopingDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&Doping::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__DopingDict_185_0_3, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&Doping::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__DopingDict_185_0_4, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&Doping::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__DopingDict_185_0_5, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&Doping::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,G__DopingDict_185_0_6, 85, G__get_linked_tagnum(&G__DopingDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,G__DopingDict_185_0_7, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,G__DopingDict_185_0_8, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__DopingDict_185_0_9, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__DopingDict_185_0_10, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&Doping::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__DopingDict_185_0_11, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&Doping::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__DopingDict_185_0_12, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&Doping::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__DopingDict_185_0_13, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&Doping::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("Doping", 609, G__DopingDict_185_0_14, (int) ('i'), G__get_linked_tagnum(&G__DopingDictLN_Doping), -1, 0, 1, 1, 1, 0, "u 'Doping' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~Doping", 735, G__DopingDict_185_0_15, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__DopingDict_185_0_16, (int) ('u'), G__get_linked_tagnum(&G__DopingDictLN_Doping), -1, 1, 1, 1, 1, 0, "u 'Doping' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncDopingDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalDopingDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {
}

static void G__cpp_setup_func14() {
}

static void G__cpp_setup_func15() {
}

static void G__cpp_setup_func16() {
}

static void G__cpp_setup_func17() {
}

static void G__cpp_setup_func18() {
}

static void G__cpp_setup_func19() {
}

static void G__cpp_setup_func20() {
}

static void G__cpp_setup_func21() {
}

static void G__cpp_setup_func22() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcDopingDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
  G__cpp_setup_func14();
  G__cpp_setup_func15();
  G__cpp_setup_func16();
  G__cpp_setup_func17();
  G__cpp_setup_func18();
  G__cpp_setup_func19();
  G__cpp_setup_func20();
  G__cpp_setup_func21();
  G__cpp_setup_func22();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__DopingDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__DopingDictLN_Doping = { "Doping" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableDopingDict() {
  G__DopingDictLN_TClass.tagnum = -1 ;
  G__DopingDictLN_TBuffer.tagnum = -1 ;
  G__DopingDictLN_TMemberInspector.tagnum = -1 ;
  G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__DopingDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__DopingDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__DopingDictLN_Doping.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableDopingDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__DopingDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__DopingDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__DopingDictLN_Doping),sizeof(Doping),-1,256,(char*)NULL,G__setup_memvarDoping,G__setup_memfuncDoping);
}
extern "C" void G__cpp_setupDopingDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupDopingDict()");
  G__set_cpp_environmentDopingDict();
  G__cpp_setup_tagtableDopingDict();

  G__cpp_setup_inheritanceDopingDict();

  G__cpp_setup_typetableDopingDict();

  G__cpp_setup_memvarDopingDict();

  G__cpp_setup_memfuncDopingDict();
  G__cpp_setup_globalDopingDict();
  G__cpp_setup_funcDopingDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncDopingDict();
  return;
}
class G__cpp_setup_initDopingDict {
  public:
    G__cpp_setup_initDopingDict() { G__add_setup_func("DopingDict",(G__incsetup)(&G__cpp_setupDopingDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initDopingDict() { G__remove_setup_func("DopingDict"); }
};
G__cpp_setup_initDopingDict G__cpp_setup_initializerDopingDict;


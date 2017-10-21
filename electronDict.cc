//
// File generated by rootcint at Sat Oct 21 15:03:57 2017

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME electronDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "electronDict.h"

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
   void electron_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_electron(void *p = 0);
   static void *newArray_electron(Long_t size, void *p);
   static void delete_electron(void *p);
   static void deleteArray_electron(void *p);
   static void destruct_electron(void *p);
   static void streamer_electron(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::electron*)
   {
      ::electron *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::electron >(0);
      static ::ROOT::TGenericClassInfo 
         instance("electron", ::electron::Class_Version(), "./electron.h", 19,
                  typeid(::electron), ::ROOT::DefineBehavior(ptr, ptr),
                  &::electron::Dictionary, isa_proxy, 0,
                  sizeof(::electron) );
      instance.SetNew(&new_electron);
      instance.SetNewArray(&newArray_electron);
      instance.SetDelete(&delete_electron);
      instance.SetDeleteArray(&deleteArray_electron);
      instance.SetDestructor(&destruct_electron);
      instance.SetStreamerFunc(&streamer_electron);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::electron*)
   {
      return GenerateInitInstanceLocal((::electron*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::electron*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOTDict

//______________________________________________________________________________
atomic_TClass_ptr electron::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *electron::Class_Name()
{
   return "electron";
}

//______________________________________________________________________________
const char *electron::ImplFileName()
{
   return ::ROOTDict::GenerateInitInstanceLocal((const ::electron*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int electron::ImplFileLine()
{
   return ::ROOTDict::GenerateInitInstanceLocal((const ::electron*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void electron::Dictionary()
{
   fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::electron*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *electron::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gCINTMutex); if(!fgIsA) {fgIsA = ::ROOTDict::GenerateInitInstanceLocal((const ::electron*)0x0)->GetClass();} }
   return fgIsA;
}

//______________________________________________________________________________
void electron::Streamer(TBuffer &R__b)
{
   // Stream an object of class electron.

   ::Error("electron::Streamer", "version id <=0 in ClassDef, dummy Streamer() called"); if (R__b.IsReading()) { }
}

//______________________________________________________________________________
void electron::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class electron.
      TClass *R__cl = ::electron::IsA();
      if (R__cl || R__insp.IsA()) { }
      R__insp.Inspect(R__cl, R__insp.GetParent(), "x", &x);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "y", &y);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "z", &z);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "m", &m);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "q", &q);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "t", &t);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "path", &path);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "cnt", &cnt);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "status_val", &status_val);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "x0", &x0);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "y0", &y0);
      R__insp.Inspect(R__cl, R__insp.GetParent(), "z0", &z0);
}

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_electron(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::electron : new ::electron;
   }
   static void *newArray_electron(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::electron[nElements] : new ::electron[nElements];
   }
   // Wrapper around operator delete
   static void delete_electron(void *p) {
      delete ((::electron*)p);
   }
   static void deleteArray_electron(void *p) {
      delete [] ((::electron*)p);
   }
   static void destruct_electron(void *p) {
      typedef ::electron current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_electron(TBuffer &buf, void *obj) {
      ((::electron*)obj)->::electron::Streamer(buf);
   }
} // end of namespace ROOTDict for class ::electron

/********************************************************
* electronDict.cc
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

extern "C" void G__cpp_reset_tagtableelectronDict();

extern "C" void G__set_cpp_environmentelectronDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("electron.h");
  G__cpp_reset_tagtableelectronDict();
}
#include <new>
extern "C" int G__cpp_dllrevelectronDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* electron */
static int G__electronDict_185_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   electron* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new electron[n];
     } else {
       p = new((void*) gvp) electron[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new electron;
     } else {
       p = new((void*) gvp) electron;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__electronDictLN_electron));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      {
         const electron& obj = ((electron*) G__getstructoffset())->operator=(*(electron*) libp->para[0].ref);
         result7->ref = (long) (&obj);
         result7->obj.i = (long) (&obj);
      }
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((electron*) G__getstructoffset())->step(*((const vector<E_field>*) G__int(libp->para[0])));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letdouble(result7, 100, (double) ((electron*) G__getstructoffset())->mean_free_path());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((electron*) G__getstructoffset())->status());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) electron::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) electron::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) electron::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      electron::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) ((const electron*) G__getstructoffset())->IsA());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((electron*) G__getstructoffset())->ShowMembers(*(TMemberInspector*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((electron*) G__getstructoffset())->Streamer(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((electron*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) electron::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) electron::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) electron::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__electronDict_185_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) electron::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__electronDict_185_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   electron* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new electron(*(electron*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__electronDictLN_electron));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef electron G__Telectron;
static int G__electronDict_185_0_23(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
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
       delete[] (electron*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((electron*) (soff+(sizeof(electron)*i)))->~G__Telectron();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (electron*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((electron*) (soff))->~G__Telectron();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* electron */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncelectronDict {
 public:
  G__Sizep2memfuncelectronDict(): p(&G__Sizep2memfuncelectronDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncelectronDict::*p)();
};

size_t G__get_sizep2memfuncelectronDict()
{
  G__Sizep2memfuncelectronDict a;
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
extern "C" void G__cpp_setup_inheritanceelectronDict() {

   /* Setting up class inheritance */
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableelectronDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<E_field>",117,G__get_linked_tagnum(&G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<doping_value>",117,G__get_linked_tagnum(&G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<electron>",117,G__get_linked_tagnum(&G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__electronDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* electron */
static void G__setup_memvarelectron(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__electronDictLN_electron));
   { electron *p; p=(electron*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->x)-(long)(p)),100,0,0,-1,-1,-1,1,"x=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->y)-(long)(p)),100,0,0,-1,-1,-1,1,"y=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->z)-(long)(p)),100,0,0,-1,-1,-1,1,"z=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->m)-(long)(p)),100,0,1,-1,-1,-1,1,"m=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->q)-(long)(p)),100,0,1,-1,-1,-1,1,"q=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->t)-(long)(p)),100,0,0,-1,-1,-1,1,"t=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->path)-(long)(p)),100,0,0,-1,-1,-1,1,"path=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__electronDictLN_TClass),G__defined_typename("atomic_TClass_ptr"),-2,4,"fgIsA=",0,(char*)NULL);
   G__memvar_setup((void*)0,108,0,0,-1,-1,-1,4,"G__virtualinfo=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"cnt=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"status_val=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"x0=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"y0=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"z0=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarelectronDict() {
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
static void G__setup_memfuncelectron(void) {
   /* electron */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__electronDictLN_electron));
   G__memfunc_setup("electron",860,G__electronDict_185_0_1, 105, G__get_linked_tagnum(&G__electronDictLN_electron), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("operator=",937,G__electronDict_185_0_2, 117, G__get_linked_tagnum(&G__electronDictLN_electron), -1, 1, 1, 1, 1, 0, "u 'electron' - 11 - -", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("step",444,G__electronDict_185_0_3, 121, -1, -1, 0, 1, 1, 1, 0, "u 'vector<E_field,allocator<E_field> >' 'vector<E_field>' 10 - -", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("mean_free_path",1454,G__electronDict_185_0_4, 100, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("status",676,G__electronDict_185_0_5, 105, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__electronDict_185_0_6, 85, G__get_linked_tagnum(&G__electronDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&electron::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__electronDict_185_0_7, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&electron::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__electronDict_185_0_8, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&electron::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__electronDict_185_0_9, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&electron::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,G__electronDict_185_0_10, 85, G__get_linked_tagnum(&G__electronDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,G__electronDict_185_0_11, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,G__electronDict_185_0_12, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__electronDict_185_0_13, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__electronDict_185_0_14, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&electron::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__electronDict_185_0_15, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&electron::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__electronDict_185_0_16, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&electron::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__electronDict_185_0_17, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&electron::DeclFileLine) ), 0);
   G__memfunc_setup("collision_time",1498,(G__InterfaceMethod) NULL, 100, -1, -1, 0, 0, 1, 4, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("D_n",273,(G__InterfaceMethod) NULL, 100, -1, -1, 0, 0, 1, 4, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("rebound",751,(G__InterfaceMethod) NULL, 121, -1, -1, 0, 0, 1, 4, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("In_anode",797,(G__InterfaceMethod) NULL, 103, -1, -1, 0, 0, 1, 4, 0, "", (char*)NULL, (void*) NULL, 0);
   // automatic copy constructor
   G__memfunc_setup("electron", 860, G__electronDict_185_0_22, (int) ('i'), G__get_linked_tagnum(&G__electronDictLN_electron), -1, 0, 1, 1, 1, 0, "u 'electron' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~electron", 986, G__electronDict_185_0_23, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncelectronDict() {
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
extern "C" void G__cpp_setup_globalelectronDict() {
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
}

static void G__cpp_setup_func23() {
}

static void G__cpp_setup_func24() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcelectronDict() {
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
  G__cpp_setup_func23();
  G__cpp_setup_func24();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__electronDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__electronDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__electronDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__electronDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__electronDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__electronDictLN_electron = { "electron" , 99 , -1 };
G__linked_taginfo G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR = { "vector<E_field,allocator<E_field> >" , 99 , -1 };
G__linked_taginfo G__electronDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<E_field,allocator<E_field> >::iterator>" , 99 , -1 };
G__linked_taginfo G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR = { "vector<doping_value,allocator<doping_value> >" , 99 , -1 };
G__linked_taginfo G__electronDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR = { "reverse_iterator<vector<doping_value,allocator<doping_value> >::iterator>" , 99 , -1 };
G__linked_taginfo G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR = { "vector<electron,allocator<electron> >" , 99 , -1 };
G__linked_taginfo G__electronDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR = { "reverse_iterator<vector<electron,allocator<electron> >::iterator>" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableelectronDict() {
  G__electronDictLN_TClass.tagnum = -1 ;
  G__electronDictLN_TBuffer.tagnum = -1 ;
  G__electronDictLN_TMemberInspector.tagnum = -1 ;
  G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__electronDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__electronDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__electronDictLN_electron.tagnum = -1 ;
  G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR.tagnum = -1 ;
  G__electronDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR.tagnum = -1 ;
  G__electronDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR.tagnum = -1 ;
  G__electronDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableelectronDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__electronDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__electronDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__electronDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__electronDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__electronDictLN_electron),sizeof(electron),-1,2304,(char*)NULL,G__setup_memvarelectron,G__setup_memfuncelectron);
   G__get_linked_tagnum_fwd(&G__electronDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR);
   G__get_linked_tagnum_fwd(&G__electronDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR);
}
extern "C" void G__cpp_setupelectronDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupelectronDict()");
  G__set_cpp_environmentelectronDict();
  G__cpp_setup_tagtableelectronDict();

  G__cpp_setup_inheritanceelectronDict();

  G__cpp_setup_typetableelectronDict();

  G__cpp_setup_memvarelectronDict();

  G__cpp_setup_memfuncelectronDict();
  G__cpp_setup_globalelectronDict();
  G__cpp_setup_funcelectronDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncelectronDict();
  return;
}
class G__cpp_setup_initelectronDict {
  public:
    G__cpp_setup_initelectronDict() { G__add_setup_func("electronDict",(G__incsetup)(&G__cpp_setupelectronDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initelectronDict() { G__remove_setup_func("electronDict"); }
};
G__cpp_setup_initelectronDict G__cpp_setup_initializerelectronDict;


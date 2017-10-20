//
// File generated by rootcint at Fri Oct 20 20:48:04 2017

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME E_fieldDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "E_fieldDict.h"

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
   void E_field_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void E_field_Dictionary();
   static void *new_E_field(void *p = 0);
   static void *newArray_E_field(Long_t size, void *p);
   static void delete_E_field(void *p);
   static void deleteArray_E_field(void *p);
   static void destruct_E_field(void *p);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::E_field*)
   {
      ::E_field *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::E_field),0);
      static ::ROOT::TGenericClassInfo 
         instance("E_field", "./E_field.h", 17,
                  typeid(::E_field), ::ROOT::DefineBehavior(ptr, ptr),
                  0, &E_field_Dictionary, isa_proxy, 0,
                  sizeof(::E_field) );
      instance.SetNew(&new_E_field);
      instance.SetNewArray(&newArray_E_field);
      instance.SetDelete(&delete_E_field);
      instance.SetDeleteArray(&deleteArray_E_field);
      instance.SetDestructor(&destruct_E_field);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::E_field*)
   {
      return GenerateInitInstanceLocal((::E_field*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::E_field*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void E_field_Dictionary() {
      ::ROOTDict::GenerateInitInstanceLocal((const ::E_field*)0x0)->GetClass();
   }

} // end of namespace ROOTDict

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_E_field(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::E_field : new ::E_field;
   }
   static void *newArray_E_field(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::E_field[nElements] : new ::E_field[nElements];
   }
   // Wrapper around operator delete
   static void delete_E_field(void *p) {
      delete ((::E_field*)p);
   }
   static void deleteArray_E_field(void *p) {
      delete [] ((::E_field*)p);
   }
   static void destruct_E_field(void *p) {
      typedef ::E_field current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOTDict for class ::E_field

/********************************************************
* E_fieldDict.cc
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

extern "C" void G__cpp_reset_tagtableE_fieldDict();

extern "C" void G__set_cpp_environmentE_fieldDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("E_field.h");
  G__cpp_reset_tagtableE_fieldDict();
}
#include <new>
extern "C" int G__cpp_dllrevE_fieldDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* E_field */
// automatic default constructor
static int G__E_fieldDict_196_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   E_field *p;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new E_field[n];
     } else {
       p = new((void*) gvp) E_field[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new E_field;
     } else {
       p = new((void*) gvp) E_field;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__E_fieldDictLN_E_field));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__E_fieldDict_196_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   E_field* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new E_field(*(E_field*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__E_fieldDictLN_E_field));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef E_field G__TE_field;
static int G__E_fieldDict_196_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
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
       delete[] (E_field*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((E_field*) (soff+(sizeof(E_field)*i)))->~G__TE_field();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (E_field*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((E_field*) (soff))->~G__TE_field();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__E_fieldDict_196_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   E_field* dest = (E_field*) G__getstructoffset();
   *dest = *(E_field*) libp->para[0].ref;
   const E_field& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* E_field */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncE_fieldDict {
 public:
  G__Sizep2memfuncE_fieldDict(): p(&G__Sizep2memfuncE_fieldDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncE_fieldDict::*p)();
};

size_t G__get_sizep2memfuncE_fieldDict()
{
  G__Sizep2memfuncE_fieldDict a;
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
extern "C" void G__cpp_setup_inheritanceE_fieldDict() {

   /* Setting up class inheritance */
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableE_fieldDict() {

   /* Setting up typedef entry */
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<doping_value>",117,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<E_field>",117,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<electron>",117,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__E_fieldDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* E_field */
static void G__setup_memvarE_field(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__E_fieldDictLN_E_field));
   { E_field *p; p=(E_field*)0x1000; if (p) { }
   G__memvar_setup((void*)((long)(&p->n)-(long)(p)),105,0,0,-1,-1,-1,1,"n=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->x)-(long)(p)),100,0,0,-1,-1,-1,1,"x=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->y)-(long)(p)),100,0,0,-1,-1,-1,1,"y=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->z)-(long)(p)),100,0,0,-1,-1,-1,1,"z=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->Ex)-(long)(p)),100,0,0,-1,-1,-1,1,"Ex=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->Ey)-(long)(p)),100,0,0,-1,-1,-1,1,"Ey=",0,(char*)NULL);
   G__memvar_setup((void*)((long)(&p->Ez)-(long)(p)),100,0,0,-1,-1,-1,1,"Ez=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarE_fieldDict() {
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
static void G__setup_memfuncE_field(void) {
   /* E_field */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__E_fieldDictLN_E_field));
   // automatic default constructor
   G__memfunc_setup("E_field", 680, G__E_fieldDict_196_0_1, (int) ('i'), G__get_linked_tagnum(&G__E_fieldDictLN_E_field), -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
   // automatic copy constructor
   G__memfunc_setup("E_field", 680, G__E_fieldDict_196_0_2, (int) ('i'), G__get_linked_tagnum(&G__E_fieldDictLN_E_field), -1, 0, 1, 1, 1, 0, "u 'E_field' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~E_field", 806, G__E_fieldDict_196_0_3, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 0);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__E_fieldDict_196_0_4, (int) ('u'), G__get_linked_tagnum(&G__E_fieldDictLN_E_field), -1, 1, 1, 1, 1, 0, "u 'E_field' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncE_fieldDict() {
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
extern "C" void G__cpp_setup_globalE_fieldDict() {
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

extern "C" void G__cpp_setup_funcE_fieldDict() {
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
G__linked_taginfo G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR = { "vector<doping_value,allocator<doping_value> >" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR = { "reverse_iterator<vector<doping_value,allocator<doping_value> >::iterator>" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_E_field = { "E_field" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR = { "vector<E_field,allocator<E_field> >" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<E_field,allocator<E_field> >::iterator>" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR = { "vector<electron,allocator<electron> >" , 99 , -1 };
G__linked_taginfo G__E_fieldDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR = { "reverse_iterator<vector<electron,allocator<electron> >::iterator>" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableE_fieldDict() {
  G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__E_fieldDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__E_fieldDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR.tagnum = -1 ;
  G__E_fieldDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__E_fieldDictLN_E_field.tagnum = -1 ;
  G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR.tagnum = -1 ;
  G__E_fieldDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR.tagnum = -1 ;
  G__E_fieldDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableE_fieldDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_vectorlEdoping_valuecOallocatorlEdoping_valuegRsPgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_reverse_iteratorlEvectorlEdoping_valuecOallocatorlEdoping_valuegRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__E_fieldDictLN_E_field),sizeof(E_field),-1,0,(char*)NULL,G__setup_memvarE_field,G__setup_memfuncE_field);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_vectorlEE_fieldcOallocatorlEE_fieldgRsPgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_reverse_iteratorlEvectorlEE_fieldcOallocatorlEE_fieldgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_vectorlEelectroncOallocatorlEelectrongRsPgR);
   G__get_linked_tagnum_fwd(&G__E_fieldDictLN_reverse_iteratorlEvectorlEelectroncOallocatorlEelectrongRsPgRcLcLiteratorgR);
}
extern "C" void G__cpp_setupE_fieldDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupE_fieldDict()");
  G__set_cpp_environmentE_fieldDict();
  G__cpp_setup_tagtableE_fieldDict();

  G__cpp_setup_inheritanceE_fieldDict();

  G__cpp_setup_typetableE_fieldDict();

  G__cpp_setup_memvarE_fieldDict();

  G__cpp_setup_memfuncE_fieldDict();
  G__cpp_setup_globalE_fieldDict();
  G__cpp_setup_funcE_fieldDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncE_fieldDict();
  return;
}
class G__cpp_setup_initE_fieldDict {
  public:
    G__cpp_setup_initE_fieldDict() { G__add_setup_func("E_fieldDict",(G__incsetup)(&G__cpp_setupE_fieldDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initE_fieldDict() { G__remove_setup_func("E_fieldDict"); }
};
G__cpp_setup_initE_fieldDict G__cpp_setup_initializerE_fieldDict;


#ifndef UTILS_H
#define UTILS_H

typedef enum { FALSE, TRUE } Bool;

/* 記号表の管理 + 変数・定数の区別用 */
typedef enum {
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  GLOBAL_ARRAY,
  LOCAL_ARRAY,
  PROC_NAME, /* 手続き   */
  FUNC_NAME, /* 関数     */
  CONSTANT   /* 定数     */
} Scope;

typedef enum { INT, VOID } Type;

/* 変数もしくは定数の型 */
typedef struct {
  Scope type;     /* 変数（のレジスタ）か整数の区別 */
  char name[256]; /* 変数の場合の変数名 */
  int val; /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

typedef struct {
  Factor element[100];
  unsigned int top;
} FactorStack;

typedef struct {
  int element[100];
  unsigned int top;
} Stack;

/* LLVM命令名の定義 */
typedef enum {
  Alloca,   /* alloca */
  Store,    /* store  */
  Load,     /* load   */
  BrUncond, /* br     */
  BrCond,   /* brc    */
  Label,    /* label  */
  Add,      /* add    */
  Sub,      /* sub    */
  Mult,     /* mult   */
  Div,      /* div    */
  Icmp,     /* icmp   */
  Ret,      /* ret    */
  Proc,     /* proc   */
  Func,     /* func   */
  Read,     /* read   */
  Write,    /* write  */
  GEP,      /* getelementptr */
  Sext      /* sext */
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum {
  EQUAL, /* eq （==）*/
  NE,    /* ne （!=）*/
  SLT,   /* slt （<，符号付き） */
  SLE,   /* sle （<=，符号付き）*/
  SGT,   /* sgt （>，符号付き） */
  SGE    /* sge （>=，符号付き）*/
} Cmptype;

typedef struct llvmcode {
  LLVMcommand command; /* 命令名 */
  union {              /* 命令の引数 */
    struct {           /* alloca */
      Factor retval;
    } alloca;
    struct { /* store  */
      Factor arg1;
      Factor arg2;
    } store;
    struct { /* load   */
      Factor arg1;
      Factor retval;
    } load;
    struct { /* br     */
      int arg1;
    } bruncond;
    struct { /* brc    */
      Factor arg1;
      int arg2;
      int arg3;
    } brcond;
    struct { /* label  */
      int l;
    } label;
    struct { /* add    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } add;
    struct { /* sub    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } sub;
    struct { /* mult   */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } mult;
    struct { /* div    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } div;
    struct { /* icmp   */
      Cmptype type;
      Factor arg1;
      Factor arg2;
      Factor retval;
    } icmp;
    struct { /* ret    */
      Factor arg1;
      Type ret_type;
    } ret;
    struct { /* proc   */
      Factor arg1;
      Factor element[100];
      unsigned int top;
    } proc;
    struct { /* func   */
      Factor arg1;
      Factor retval;
      Factor element[100];
      unsigned int top;
    } func;
    struct { /* ret    */
      Factor arg1;
      Factor retval;
    } read;
    struct { /* ret    */
      Factor arg1;
      Factor retval;
    } write;
    struct { /* ret    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } gep;
    struct { /* sext   */
      Factor arg1;
      Factor retval;
    } sext;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

typedef struct fundecl {
  char fname[256];      /* 関数名                      */
  unsigned arity;       /* 引数個数                    */
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
  Type ret_type;
} Fundecl;

typedef struct _Symbol {
  Scope type;
  int val;
  char *name;
  int arity_num;
  int start;
  int end;
  struct _Symbol *next;
  struct _Symbol *prev;
} Symbol;

typedef struct {
  int label[100];
  unsigned int top;
} LabelStack;

typedef struct {
  int *address[100];
  unsigned int top;
} BrAddressStack;

typedef struct {
  Factor element[100];
  unsigned int top;
} ArityStack;

Factor factor_pop();
void factor_push(Factor x);
int label_pop();
void label_push(int label);
int *address_pop();
void address_push(int *address);
void arity_push(Factor x);
Factor arity_pop();
void insert_code(LLVMcommand command);
LLVMcode *generate_code(LLVMcommand command);
void insert_decl(char *fname, int arity, Factor *args, Type ret_type);
void back_patch();
Factor create_factor_by_name(char *name);
Factor create_proc_or_func_factor(char *name, int arity_num);

Fundecl *get_decl_head_ptr();
void set_cmp_type(Cmptype type);
void set_read_flag(Bool flag);
Bool get_read_flag();
void set_write_flag(Bool flag);
Bool get_write_flag();

void display_llvm_fun_decl(Fundecl *decl_ptr);
void display_factor(Factor x);
void display_llvm_codes(LLVMcode *code_ptr);
void display_global_var();
void display_llvm();

void insert_symbol(Scope type, char *name, int val);
Symbol *lookup_symbol(char *name);
Symbol *lookup_proc_or_func_symbol(char *name, int arity_num);
void delete_local_symbol();
Symbol *get_symbol_head_ptr();
void insert_array_symbol(Scope type, char *name, int val, int start, int end);

#endif

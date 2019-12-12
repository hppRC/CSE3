typedef enum {
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  CONSTANT    /* 定数     */
} Scope;


/* 変数もしくは定数の型 */
typedef struct {
  Scope type;      /* 変数（のレジスタ）か整数の区別 */
  char vname[256]; /* 変数の場合の変数名 */
  int val;         /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct {
  Factor element[100];  /* スタック（最大要素数は100まで） */
  unsigned int top;     /* スタックのトップの位置         */
} Factorstack;

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}

Factor fuctorpop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void fuctorpush(Factor x) {
  fstack.top ++;
  fstack.element[fstack.top] = x;
  return;
}

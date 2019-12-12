typedef enum {
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  CONSTANT    /* 定数     */
} Scope;


/* 変数もしくは定数の型 */
typedef struct {
  Scope type;      /* 変数（のレジスタ）か整数の区別 */
  char *vname; /* 変数の場合の変数名 */
  int val;         /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct {
  Factor element[100];  /* スタック（最大要素数は100まで） */
  unsigned int top;     /* スタックのトップの位置         */
} Factorstack;

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */
int scope = GLOBAL_VAR;

Factor factorpop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void print_all_factor() {
  printf("-------------\n");
  int now = fstack.top;
  while (now > 0) {
    printf("%d, %s, %d\n",fstack.element[now].type, fstack.element[now].vname, fstack.element[now].val);
    now--;
  }
  return;
}

void factorpush(Factor x) {
  fstack.top++;
  fstack.element[fstack.top].type = x.type;
  fstack.element[fstack.top].vname = (char *)malloc(sizeof(char) * (strlen(x.vname) + 1));
  strcpy(fstack.element[fstack.top].vname, x.vname);
  fstack.element[fstack.top].val = x.val;
  return;
}


Factor lookup_data(char *name) {
  int now = fstack.top;
  while (now > 0) {
    Factor x = fstack.element[now];
    if (strcmp(x.vname, name) == 0) {
      return x;
    }
    now--;
  }
}

void delete_data() {
  int now = fstack.top;
  while (now > 0) {
    if (fstack.element[now].type == LOCAL_VAR) {
      free(fstack.element[now].vname);
      fstack.top--;
    }
    now--;
  }
  return;
}


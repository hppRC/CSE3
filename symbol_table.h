typedef enum {
  GLOBAL_VAR,
  LOCAL_VAR,
  PROC_NAME,
  CONSTANT
} Scope;


typedef struct _Node {
  Scope type;
  char name[255];
  int val;
  struct _Node *next;
} Node;


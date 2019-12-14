typedef enum
{
  GLOBAL_VAR,
  LOCAL_VAR,
  PROC_NAME,
  CONSTANT
} Scope;

typedef struct _Node
{
  Scope type;
  char *name;
  int val;
  struct _Node *next;
  struct _Node *prev;
} Node;

void insert(int type, char *name, int val);
Node *lookup(char *name);
void delete ();
typedef enum {
  GLOBAL_VAR,
  LOCAL_VAR,
  PROC_NAME,
  CONSTANT
} Scope;

typedef struct _Node {
  Scope type;
  char *name;
  int val;
  struct _Node *next;
  struct _Node *prev;
} Node;


Node *head;
Node *tail;


void insert_data(int type, char *name, int val);
Node *lookup_data(char *name);
void delete_data();
void print_all_node();
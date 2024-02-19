#define max_nodes 100

typedef struct node {
    const char * name;
    struct node * childs[max_nodes];
    size_t childs_num;
    struct node * parent;
    int weights[max_nodes];
} node;

extern node a, b, start;

node finish = {
  .name = "finish",
  .childs = { NULL },
  .childs_num = 0,
  .weights = { 0 },
  .parent = NULL,
};

node a = {
  .name = "a",
  .childs = { &finish },
  .weights = { 1 },
  .childs_num = 1,
  .parent = &start,
};

node b = {
  .name = "b",
  .childs = { &a, &finish },
  .weights = { 3, 5 },
  .childs_num = 2,
  .parent = &start,
};

node start = {
  .name = "start",
  .childs = { &a, &b },
  .weights = { 6, 2 },
  .childs_num = 2,
  .parent = NULL,
};

node weight_table = {
    .childs = { &a, &b, &finish },
    .weights = { 6, 2, -1 },
    .childs_num = 3,
};

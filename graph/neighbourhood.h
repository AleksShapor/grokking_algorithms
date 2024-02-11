
#define max_neighbors 100

typedef struct person {
    char * name;
    struct person * neighbors[max_neighbors];
    size_t neighbors_count;
    int checked;
} person;

person tom = {
  .name = "Tom",
  .neighbors = NULL,
  .neighbors_count = 0,
  .checked = 0,
};

person jonni = {
  .name = "Jonni",
  .neighbors = NULL,
  .neighbors_count = 0,
  .checked = 0,
};

person peggi = {
  .name = "Peggi",
  .neighbors = NULL,
  .neighbors_count = 0,
  .checked = 0,
};

person anuj = {
  .name = "Anuj",
  .neighbors = NULL,
  .neighbors_count = 0,
  .checked = 0,
};

person bob = {
  .name = "Bob",
  .neighbors = { &anuj, &peggi },
  .neighbors_count = 2,
  .checked = 0,
};

person alice = {
  .name = "Alice",
  .neighbors = { &peggi },
  .neighbors_count = 1,
  .checked = 0,
};

person claire = {
  .name = "Claire",
  .neighbors = { &tom, &jonni },
  .neighbors_count = 2,
  .checked = 0,
};

person you = {
  .name = "Oleksandr",
  .neighbors = { &bob, &alice, &claire },
  .neighbors_count = 3,
  .checked = 0,
};

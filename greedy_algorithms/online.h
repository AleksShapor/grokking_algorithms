#define max_stations 8

typedef struct state {
    const char * name;
    int covered;
} state;

typedef struct radiostation {
    const char * name;
    struct state * states[max_stations];
    size_t state_num;
    int is_used;
} radiostation;

state id = {
    .name = "id",
    .covered = 0,
};

state nv = {
    .name = "nv",
    .covered = 0,
};

state ut = {
    .name = "ut",
    .covered = 0,
};

state wa = {
    .name = "wa",
    .covered = 0,
};

state mt = {
    .name = "mt",
    .covered = 0,
};

state ori = {
    .name = "ori",
    .covered = 0,
};

state ca = {
    .name = "ca",
    .covered = 0,
};

state az = {
    .name = "az",
    .covered = 0,
};

radiostation kone = {
    .name = "kone",
    .states = { &id, &nv, &ut },
    .state_num = 3,
    .is_used = 0,
};

radiostation ktwo = {
    .name = "ktwo",
    .states = { &wa, &id, &mt },
    .state_num = 3,
    .is_used = 0,
};

radiostation kthree = {
    .name = "kthree",
    .states = { &ori, &nv, &ca },
    .state_num = 3,
    .is_used = 0,
};

radiostation kfour = {
    .name = "kfour",
    .states = { &nv, &ut },
    .state_num = 2,
    .is_used = 0,
};

radiostation kfive = {
    .name = "kfive",
    .states = { &ca, &az },
    .state_num = 2,
    .is_used = 0,
};

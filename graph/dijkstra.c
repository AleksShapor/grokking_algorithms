#include <stdio.h>
#include "graph.h"

node *node_done[max_nodes] = { NULL };

void append_to_done(node * input_node) {
    for(int it = 0; it < max_nodes; it++) {
        if(node_done[it] == NULL) {
            node_done[it] = input_node;
            break;
        }
    }
}

int find_in_done(node * input_node) {
    for(int it = 0; it < max_nodes; it++) {
        if(node_done[it] == input_node)
            return 1;
    }
    
    return 0;
}

void print_table(void) {
    printf("=== START PRICES ===\n");
    for(int it = 0; it < weight_table.childs_num; it++) {
        printf("%s : %d : %s\n", 
            weight_table.childs[it]->name, weight_table.weights[it], 
                weight_table.childs[it]->parent ? weight_table.childs[it]->parent->name : "NULL");
    }
    printf("=== END PRICES ===\n");
}

int get_lowest_node(void) {
    int tmp_lowest_weight = -1, saved_index = -1;
    
    // 1. Get lowest node
    for(int it = 0; it < weight_table.childs_num; it++) {
        if(find_in_done(weight_table.childs[it]))
            continue;
        
        if((tmp_lowest_weight == -1 || tmp_lowest_weight > weight_table.weights[it]) && weight_table.weights[it] != -1) {
            tmp_lowest_weight = weight_table.weights[it];
            saved_index = it;
        }
    }

    return saved_index;
}

void update_tables(int index) {
    node * tmp_lowest_node = weight_table.childs[index];
    int tmp_price = 0, tmp_lowest_weight = weight_table.weights[index];
  
    // 2. Update price table for lowest neighbour
    if(tmp_lowest_node->childs) {
        // 2.1 Go though all childs
        for(int it_p = 0; it_p < tmp_lowest_node->childs_num; it_p++) {
            // 2.2 If child present in weight_table
            for(int it_ch = 0; it_ch < weight_table.childs_num; it_ch++) {
                if(tmp_lowest_node->childs[it_p] == weight_table.childs[it_ch]) {
                    // 2.3 Compare child weight_table with lowest_node current child + lowest_node current weight
                    tmp_price = tmp_lowest_weight + tmp_lowest_node->weights[it_p];
                    if((tmp_price < weight_table.weights[it_ch]) || !weight_table.childs[it_ch]->parent) {
                        // 2.4 Update price entry
                        weight_table.weights[it_ch] = tmp_price;
                        // 2.5 Update parent also
                        weight_table.childs[it_ch]->parent = tmp_lowest_node;
                    }
                        
                    break;
                }
            }
        }
    }
    
    append_to_done(tmp_lowest_node);
}

int main()
{
    print_table();
    int index = get_lowest_node();
    // 3. Repeat!
    while(index != -1) {
        update_tables(index);
        index = get_lowest_node();
    }
    print_table();
    return 0;
}

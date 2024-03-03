#include <stdio.h>
#include <stdlib.h>
#include "items.h"

#define max_weight 6 // columns
#define max_items 5  // rows

item * items[max_items] = { &water, &book, &food, &jacket, &camera };

void print_table(int **price_table) {
    for(int i = 0; i < max_weight/2 - 1; i++)
        printf("\t");
        
    printf("PRICE TABLE\n");
    for (int i = 0; i < max_items; ++i) {
        for (int j = 0; j < max_weight; ++j) {
            printf("%d\t", price_table[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // 1. Create table
    int **price_table = NULL; 
    int current_price_tmp = 0;
    int current_weight_tmp = 0;
    int prev_max_price_tmp = 0;
    int prev_max_price_left = 0;
    
    // 1.1 Allocate memory for each row
    price_table = (int**)malloc(sizeof(int*) * max_items);
    for(int i = 0; i < max_items; i++) {
        // 1.2 Then allocate memory for each column
        price_table[i] = (int*)malloc(sizeof(int) * max_weight);
    }
    
    print_table(price_table);
    // 1.3 Fill table (calculate solution)
    for (int i = 0; i < max_items; ++i) {
        for (int j = 0; j < max_weight; ++j) {
            // Weight could not be zero
            current_weight_tmp = j + 1;
            
            // If it is first row - fill price from first item
            if(!i) {
                price_table[i][j] = current_weight_tmp >= items[i]->weight ? items[i]->price : 0;
                continue;
            }
            
            // If current item weight is not fit - fill form previous
            if(items[i]->weight > current_weight_tmp) {
                price_table[i][j] = price_table[i - 1][j];
                continue;
            }
            
            // 1.4 Get price from previous row
            prev_max_price_tmp = price_table[i - 1][j];
            
            // 1.5 Find sum of current item price + price of the rest of the free space
            current_price_tmp = items[i]->price +
                                ((current_weight_tmp - items[i]->weight) >= 0 ? price_table[i - 1][j - items[i]->weight] : 0);
                
            // 1.6 Find which price is more valuable
            price_table[i][j] = prev_max_price_tmp > current_price_tmp ? prev_max_price_tmp : current_price_tmp;
        }
    }
    print_table(price_table);
    
    // Free memory
    for(int i = 0; i < max_items; ++i) {
        free(price_table[i]);
    }
    free(price_table);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char blues[] = "blues", clues[] = "clutet";
const int rows = strlen(blues), colums = strlen(clues);

void print_table(int **price_table) {
    for(int i = 0; i < colums/2 - 1; i++)
        printf("\t");
        
    printf("PRICE TABLE\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            printf("%d\t", price_table[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // 1. Create table
    int **price_table = NULL; 
    
    // 1.1 Allocate memory for each row
    price_table = (int**)malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++) {
        // 1.2 Then allocate memory for each column
        price_table[i] = (int*)malloc(sizeof(int) * colums);
    }
    
    print_table(price_table);
    // 1.3 Fill table (calculate solution)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            
            // If current symbol is fit - +1 + previous colum and row sum
            if(blues[i] == clues[j])
                price_table[i][j] = price_table[i ? (i - 1) : 0][j ? (j - 1) : 0] + 1;
        }
    }
    print_table(price_table);
    
    // Free memory
    for(int i = 0; i < rows; ++i) {
        free(price_table[i]);
    }
    free(price_table);
    
    return 0;
}


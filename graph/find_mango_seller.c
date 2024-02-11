#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neighbourhood.h"

typedef struct queue_entry {
    person * seller;
    struct queue_entry * next;
} queue_entry;

const char * mango_seller = "Tom";

static queue_entry * head = NULL;
static queue_entry * end = NULL;

void print_queue(void) {
    queue_entry * tmp_entry = head;
    printf("QUEUE:");
    while(tmp_entry) {
        printf(" %s", tmp_entry->seller->name);
        tmp_entry = tmp_entry->next;
    }
    printf("\n");
}

void enqueue(person * seller) {
    queue_entry * tmp_queue_entry = NULL;
    
    if(!seller)
        return;
        
    for(size_t it = 0; it < seller->neighbors_count; it++) {
        
        // If seller is checked -> skip seller
        if(seller->neighbors[it]->checked)
            continue;

        tmp_queue_entry = malloc(sizeof(queue_entry));
        tmp_queue_entry->seller = seller->neighbors[it];
        seller->neighbors[it]->checked = 1;
        tmp_queue_entry->next = NULL;
        
        // Put entry to the end
        if(end)
            end->next = tmp_queue_entry;

        end = tmp_queue_entry;
        
        // Insert first element if queue is empty
        if(!head)
            head = tmp_queue_entry;
    }
}

void dequeue(void) {
    queue_entry * tmp_queue_entry = head;
    head = head->next;
    free(tmp_queue_entry);
}

person * find_mango_seller(person * seller) {
    
    if(!seller)
        return NULL;
        
    // Add first level links to queue
    enqueue(seller);
    
    // Go through all sellers in queue
    while(head) {
        
        // If first seller in queue is mango seller -> return ptr on seller
        if(!strcmp(mango_seller, head->seller->name))
            return head->seller;
        
        // Mark checked seller
        head->seller->checked = 1;

        // If neighbor is not mango seller -> push all his/her neighbor to queue
        enqueue(head->seller);

        // Dequeue current seller
        dequeue();
    }
    
    return NULL;
}

int main()
{
    person * mango = NULL;
    mango = find_mango_seller(&you);
    printf("THE SELLER IS AT: %p", mango);
    return 0;
}

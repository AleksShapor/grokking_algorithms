#include <stdio.h>
#include "online.h"

radiostation *radiostations[5] = { &kone, &ktwo, &kthree, &kfour, &kfive };
state *states[max_stations] = { &id, &nv, &ut, &wa, &mt, &ori, &ca, &az };

void print_station_states(radiostation * station) {
    if(!station || !station->state_num)
        return;
    
    printf("\nSTATION: %s\n", station->name);
    printf("STATES:");
    for(int i = 0; i < station->state_num && station->states[i]; i++) {
        printf(" %s ", station->states[i]->name);
    }
    printf("\n");
}

// 1. Find state which covers most of uncovered states
radiostation * find_most_eff_radiostation(void) {
    radiostation * radiostation_most_eff = NULL;
    size_t uncovered_states_num_tmp = 0;
    size_t uncovered_states_max = 0;
    
    // Go through all radiostations
    for(int i = 0; i < sizeof(radiostations)/sizeof(radiostations[0]); i++) {
        
        // Skip used stations
        if(radiostations[i]->is_used)
            continue;
        
        // Go through all radiostation states and find max uncovered states
        for(int j = 0 ; j < radiostations[i]->state_num; j++) {
            uncovered_states_num_tmp = 0;
            if(!radiostations[i]->states[j]->covered)
                uncovered_states_num_tmp++;
        }
        
        if(uncovered_states_num_tmp > uncovered_states_max) {
            uncovered_states_max = uncovered_states_num_tmp;
            radiostation_most_eff = radiostations[i];
        }
    }
    
    return radiostation_most_eff;
}

state * find_first_uncovered_state(void) {
    for(int i = 0; i < max_stations; i++) {
        if(!states[i]->covered)
            return states[i];
    }
    
    return NULL;
}

void get_radiostations(radiostation * radiostation_return) {

    radiostation * radiostation_most_eff = NULL;
    
    if(!radiostation_return)
        return;
    
    // Repeat until all states are not covered
    while(find_first_uncovered_state()) {
        
        // Find radiostation which covers most of states
        radiostation_most_eff = find_most_eff_radiostation();
        
        // Mark as used station and covered stations
        if(radiostation_most_eff) {
            radiostation_most_eff->is_used = 1;
            for(int i = 0; i < radiostation_most_eff->state_num; i++)
                radiostation_most_eff->states[i]->covered = 1;
            
            // 2. Put station to array
            *radiostation_return = *radiostation_most_eff;
            radiostation_return++;
        } else
        // Unexpected case - no left stations
            break;
    }
}

int main()
{
    radiostation radiostations_covered[5] = {0};
    
    printf("=== INPUT ===");
    for(int i = 0; i < sizeof(radiostations)/sizeof(radiostations[0]); i++) {
        print_station_states(radiostations[i]);
    }
    printf("=== INPUT ===\n");
    get_radiostations(radiostations_covered);
    printf("=== ANSWER ===\n");
    for(int i = 0; i < sizeof(radiostations_covered)/sizeof(radiostations_covered[0]); i++) {
        if(radiostations_covered[i].name)
            printf(" %s ", radiostations_covered[i].name);
    }
    printf("\n=== ANSWER ===\n");
    
    return 0;
}


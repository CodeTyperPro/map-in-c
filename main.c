#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Map map;

    // INIT
    init(&map);

    // READ FROM THE FILE
    const char filename[] = "input.txt";

    FILE* input;
    input = fopen(filename, "r");

    if(input == NULL){
        printf("File does not exist, or something went wrong.\n");
    } else {
        char str[WORD_BUFFER_SIZE];
        while(fscanf(input, "%s", str) == 1){
            int num = get(&map, str);
            set(&map, str, num + 1);
        }
    }

    fclose(input);

    // SET
    /*set(&map, "Hi", 12);
    set(&map, "Hello", 2);*/

    // FIND
    
    char str[] = "orange";
    Pair* pair;
    pair = find(&map, str);

    if(pair == NULL){
        printf("Pair not found.\n");
    } else{
        printf("%s - %d\n", pair->str, pair->num);
    }

    // GET
    /* int num = get(&map, str);
    printf("%s => %d\n", str, num);*/

    // PRINT
    print(&map);

    // DESTROY
    dest(&map);

    return 0;
}
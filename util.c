#include "util.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void init(Map* map){
    map->size = 0;
    map->items = NULL;
}

void dest(Map* map){
    if(map->items != NULL){
        free(map->items);
    }
}

Pair* find(Map* map, char* str){
    for (size_t i = 0; i < map->size; ++i){
        if(strcmp(map->items[i].str, str) == 0){
            return &map->items[i];
        }
    } return NULL;
}

void set(Map* map, char* str, int num){
    Pair* pair;
    pair = find(map, str);

    if(pair != NULL){
        pair->num = num;
    } else {

        if(map->size == 0){
            map->items = (Pair*) malloc(sizeof(Pair));
        } else{
            map->items = (Pair*) realloc(map->items, sizeof(Pair)*(map->size + 1));
        }

        Pair new_pair;
        new_pair.num = num;
        strcpy(new_pair.str, str);
        map->items[map->size] = new_pair;
        map->size++;
    }
}

int get(Map* map, char* str){    
    Pair* pair;
    pair = find(map, str);

    if(pair == NULL){
        set(map, str, 0);
        return 0;
    }

    return pair->num;
}

void print(Map* map){
    printf("\nOutput\n------\n");
    if(map->size == 0){
        printf("Empty! There is no pair to print.\n");
    } else {
        for (size_t i = 0; i < map->size; ++i){
            printf("%s -> %d\n", map->items[i].str, map->items[i].num);
        }
    }
}
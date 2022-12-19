#ifndef UTIL_H
#define UTIL_H

#define WORD_BUFFER_SIZE 32

#include <stdlib.h>

typedef struct Pair{
    char str[WORD_BUFFER_SIZE];
    int num;
} Pair;

typedef struct Map{
    size_t size;
    Pair* items; 
} Map;


void init(Map* map);
void dest(Map* map);
Pair* find(Map* map, char* str);
void set(Map* map, char* str, int num);
int get(Map* map, char* str);
void print();

#endif
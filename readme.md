Count unique words
In this task we implement a dictionary data structure which is able to assign a number to a string. In some other languages like C++ or Java these are also called maps because these are mapping some keys to some values. We'll use this data structure for determining the multiplicity of the words in a file.

Implementation of a map
Define a macro token named WORD_BUFFER_SIZE with value 32.

Create a structure Pair with the following attributes:

str: A character array of WORD_BUFFER_SIZE elements.
num: An integer which is mapped to the string.
Create a structure Map with the following attributes:

items: An array of Pair objects stored in heap memory.
size: The length of the array.
Implement the following operations. These functions shouldn't print anything except for print().

init(): This function gets a Map as parameter and initializes it so the array length is 0 and items is a NULL pointer.
dest(): Destructs the map, i.e. deallocates items array from the heap.
find(): This function gets a Map and a string as parameter and finds this string in the map. The function returns a pointer to a Pair of which the str attribute is the string to find. If the string is not found in the data structure then NULL returns.
set(): This function gets a Map, a string and an integer as parameter. Create a Pair with these and insert them to the map. After the insertion the array size increments by 1. We know that this is the least efficient way of implementing a map, but for sake of simplicity we choose this representation.
Make sure to have the string only once in the map. If the string is in the map already then the assigned integer is overwritten.
get(): This function gets a string as parameter and returns the integer assigned to that string. If the string is not in the map then insert it first with 0 and return this number.
print(): Print the string-int pairs according to the output format below.
Read a file
Read the content of a text file word by word. You may assume that no word in the processed file is longer than WORD_BUFFER_SIZE including the \0 terminator. Count the occurrences of each word using the Map data structure.

Input
-----
apple orange apple peach pear
pear pear orange peach orange

Output
------
apple -> 2
orange -> 3
peach -> 2
pear -> 3
Modularity
Separate the program to translation units. Function definitions should go to separate translation units to which a header file belongs. Don't forget header guards.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//type == 1: maxheap
//type == 0: minheap

typedef struct heap_struct
{
    int size;
    int taken;
    int type;
    int *content;
}heap;

//Returns a new heap
heap hCreate(int type, int initialSize)
{
    heap* aHeap = (heap*)malloc(sizeof(heap));
    aHeap->size = initialSize; //stores the size of the heap
    aHeap->taken = 0; //stores the size taken
    aHeap->type = type; //stores whether the heap is a minheap (0) or maxheap (1)

    aHeap->content = (int*)malloc(sizeof(int) * (initialSize));

    return *aHeap;
}

//Insert in heap
void hInsert(heap* aHeap, int value)
{
    //Insert as leaf node
    aHeap->content[aHeap->taken] = value;
    aHeap->taken++;

    //Doubling size, in case it's not enough
    if(aHeap->taken == aHeap->size)
    {
        aHeap->content = (int*)realloc(aHeap->content, sizeof(int)*(aHeap->size*2));
        aHeap->size *= 2;
    }
    
    //Checking if it's still ordered
    //Start with the current element inserted, then check if the father is ordered, according to heap type
    int child = aHeap->taken-1;
    int parent = floor((child-1)/2);
    
        //printf("%d <= %d : %d\n", aHeap->content[parent], aHeap->content[child], aHeap->content[parent] <= aHeap->content[child]);
        
        //while unordered, keep swapping
        while(
            ((aHeap->type == 0 && aHeap->content[parent] > aHeap->content[child]) ||
            (aHeap->type == 1 && aHeap->content[parent] < aHeap->content[child])) &&
            parent >= 0)
        {
            //Not ordered: swap them
            //printf("Swapping %d and %d\n", aHeap->content[parent], aHeap->content[child]);
            int aux = aHeap->content[child];
            aHeap->content[child] = aHeap->content[parent];
            aHeap->content[parent] = aux;

            //Updating Indexes through analysis
            child = parent;
            if(parent == 0) parent = -1;
            parent = floor((child-1)/2);
        };
    
}

//Removes last element in heap. Also returns the element removed.
int hPop(heap* aHeap)
{
    int removed = aHeap->content[aHeap->taken-1];
    aHeap->content[aHeap->taken-1] = 0;
    aHeap->taken--;
    return removed;
}

//Prints heap (as an array)
void printHeapArray(heap aHeap)
{
    for(int i = 0; i < aHeap.taken-1; i++)
    {
        printf("%d ", aHeap.content[i]);
    }
    printf("%d", aHeap.content[aHeap.taken-1]);
}

void printHeapLevel(heap aHeap, int index, int level, int levelToPrint)
{
    //If the index is within element reach
    if(index <= aHeap.taken - 1)
    {
        if(level == levelToPrint)
        {
            printf("%d ", aHeap.content[index]);
        }
        else
        {
            printHeapLevel(aHeap, index * 2 + 1, level+1, levelToPrint);
            printHeapLevel(aHeap, index *2  + 2, level+1, levelToPrint);
        }
    }
}

int recursiveHeight(heap aHeap, int index, int height)
{
    if(index <= aHeap.taken - 1)
    {
        int leftHeight = recursiveHeight(aHeap, index * 2 + 1, height+1);
        int rightHeight = recursiveHeight(aHeap, index *2  + 2, height+1);
        return leftHeight >= rightHeight ? leftHeight : rightHeight;
    }
    else return height;
}
//Returns the height of a heap, as with levels defined like a tree.
int heapHeight(heap aHeap)
{
    return recursiveHeight(aHeap, 0, 0);
}

//Prints a heap per level, like a tree.
void printHeap(heap aHeap)
{
    for(int i = 0; i < heapHeight(aHeap); i++)
    {
        printHeapLevel(aHeap, 0, 0, i);
        printf("\n");
    }
}

//Returns whether an element is inside the heap or not.
int hExists(heap aHeap, int value)
{
    for(int i = 0; i < aHeap.taken; i++)
    {
        if(aHeap.content[i] == value) return 1;
    }
    return 0;
}
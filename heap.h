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

//Create heap
heap hCreate(int type, int initialSize)
{
    heap* aHeap = (heap*)malloc(sizeof(heap));
    aHeap->size = initialSize; //stores the size of the heap
    aHeap->taken = 0; //tores the size taken
    aHeap->type = type; //stores wether the heap is a minheap (0) or maxheap (1)

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
    
    while(parent >= 0)
    {
        //Ordered
        if(
            (aHeap->type == 0 && aHeap->content[parent] <= aHeap->content[child]) ||
            (aHeap->type == 1 && aHeap->content[parent] >= aHeap->content[child])
            )
        {
            break;
        }
        //Not ordered: switch them
        else
        {
            int aux = aHeap->content[child];
            aHeap->content[child] = aHeap->content[parent];
            aHeap->content[parent] = aux;
        }

        //Updating Indexes through analysis
        child = parent;
        if(parent == 0) parent = -1;
        parent = floor((child-1)/2);
    }
    
}

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
    if(index < aHeap.taken - 1)
    {
        int leftHeight = recursiveHeight(aHeap, index * 2 + 1, height+1);
        int rightHeight = recursiveHeight(aHeap, index *2  + 2, height+1);
        return leftHeight >= rightHeight ? leftHeight : rightHeight;
    }
    else return height;
}
int heapHeight(heap aHeap)
{
    recursiveHeight(aHeap, 0, 0);
}

void printHeap(heap aHeap)
{
    for(int i = 0; i < heapHeight(aHeap); i++)
    {
        printHeapLevel(aHeap, 0, 0, i);
        printf("\n");
    }
    //printHeapLevel(aHeap, 0, 0, 0); printf("\n");
    //printHeapLevel(aHeap, 0, 0, 1);
    
}
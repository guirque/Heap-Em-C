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

//Reorder
void reorderHeapInsertion(heap *aHeap)
{
    int child = aHeap->taken-1; //Start from last element present
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
        }
}

void reorderHeapPop(heap *aHeap)
{
    //Start from parent. Check children. Switch with children until ordered.
    int parent = 0;
    int child1 = 1;
    int child2 = 2;

    //While swapping is necessary

    //MAXHEAP
    if(aHeap->type) 
    while
    (
        (child1 != -1 && aHeap->content[child1] > aHeap->content[parent]) 
        || (child2 != -1 && aHeap->content[child2] > aHeap->content[parent])
    )
    {
        //Choose biggest child (to replace parent)
        int chosenChild;
        if(child1 != -1 && child2 != -1) 
            chosenChild = aHeap->content[child1] > aHeap->content[child2] ? child1 : child2;
        else if(child1 != -1)
            chosenChild = child1;
        else
            chosenChild = child2;

        //Changing Parent and Children
        int aux = aHeap->content[chosenChild];
        aHeap->content[chosenChild] = aHeap->content[parent];
        aHeap->content[parent] = aux;

        //Changing Parent and Children Indexes, for next iteration
        parent = chosenChild;
        child1 = parent*2 + 1;
        child2 = child1 + 1;
        if(child1 > aHeap->taken-1) child1 = -1;
        if(child2 > aHeap->taken-1) child2 = -1;
    }
    else
    //MINHEAP
    while
    (
        (child1 != -1 && aHeap->content[child1] < aHeap->content[parent]) 
        || (child2 != -1 && aHeap->content[child2] < aHeap->content[parent])
    )
    {
        //Choose smallest child (to replace parent)
        int chosenChild;
        if(child1 != -1 && child2 != -1) 
            chosenChild = aHeap->content[child1] < aHeap->content[child2] ? child1 : child2;
        else if(child1 != -1)
            chosenChild = child1;
        else
            chosenChild = child2;

        //Changing Parent and Children
        int aux = aHeap->content[chosenChild];
        aHeap->content[chosenChild] = aHeap->content[parent];
        aHeap->content[parent] = aux;

        //Changing Parent and Children Indexes, for next iteration
        parent = chosenChild;
        child1 = parent*2 + 1;
        child2 = child1 + 1;
        if(child1 > aHeap->taken-1) child1 = -1;
        if(child2 > aHeap->taken-1) child2 = -1;
    }
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
    reorderHeapInsertion(aHeap);
    
}

//Removes root element in heap. Also returns the element removed.
int hPop(heap* aHeap)
{
    int removed = aHeap->content[0];

    aHeap->content[0] = aHeap->content[aHeap->taken - 1];
    aHeap->taken--;
    reorderHeapPop(aHeap);
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
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    heap aMinheap = hCreate(0, 2);
    hInsert(&aMinheap, 5);
    hInsert(&aMinheap, 3);
    hInsert(&aMinheap, 4);
    hInsert(&aMinheap, 20);
    hInsert(&aMinheap, 30);
    hInsert(&aMinheap, 40);
    hInsert(&aMinheap, 8);
    hInsert(&aMinheap, 2);
    printf("Height: %d\n", heapHeight(aMinheap));

    printf("Printing heap like a tree: \n");
    printHeap(aMinheap);
    printf("Printing heap like an array: \n");
    printHeapArray(aMinheap);

    pause;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define pause int pause; scanf("%d", &pause);

int main()
{

    //.insert()
    //.pop()
    //minheap || maxheap

    //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    //0 -> 2 && 0 -> 3
    // 1 -> 3 && 1 -> 4

    //parent: floor(i-1/2)
    //child 1: 2i + 1
    //child 2: 2i + 2
    heap aMinheap = hCreate(1, 2);
    hInsert(&aMinheap, 5);
    hInsert(&aMinheap, 3);
    hInsert(&aMinheap, 4);
    hInsert(&aMinheap, 20);
    hInsert(&aMinheap, 30);
    hInsert(&aMinheap, 40);
    hInsert(&aMinheap, 8);
    hInsert(&aMinheap, 2);
    //printHeapArray(aMinheap);
    printf("Height: %d\n", heapHeight(aMinheap));

    printf("Printing heap like a tree: \n");
    printHeap(aMinheap);
    printf("Printing heap like an array: \n");
    printHeapArray(aMinheap);

    pause;
    return 0;
}
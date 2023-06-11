#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    heap aMinheap = hCreate(0, 2);
    
    hInsert(&aMinheap, 20);
    hInsert(&aMinheap, 10);
    hInsert(&aMinheap, 5);
    hInsert(&aMinheap, 19);
    hInsert(&aMinheap, 4);
    hInsert(&aMinheap, 17);
    hInsert(&aMinheap, 12);
    hInsert(&aMinheap, 98);
    hInsert(&aMinheap, 3);
    
    printf("Height: %d\n", heapHeight(aMinheap));

    printf("\nPrinting heap like a tree: \n");
    printHeap(aMinheap);
    
    printf("\nPrinting heap like an array: \n");
    printHeapArray(aMinheap);

    int lookForMe = 20;
    printf("\n\nIs %d in the heap? %d\n", lookForMe, hExists(aMinheap, lookForMe));

    printf("\n- Deleting some values -\n");
    printf("Removed %d\n", hPop(&aMinheap));
    printHeap(aMinheap); printf("\n");
    printf("Removed %d\n", hPop(&aMinheap));
    printHeap(aMinheap);
    
    pause;
    return 0;
}
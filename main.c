#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    heap aMinheap = hCreate(1, 2);
    hInsert(&aMinheap, 5);
    hInsert(&aMinheap, 3);
    hInsert(&aMinheap, 4);
    hInsert(&aMinheap, 20);
    hInsert(&aMinheap, 30);
    hInsert(&aMinheap, 40);
    hInsert(&aMinheap, 8);
    hInsert(&aMinheap, 2);
    printf("Height: %d\n", heapHeight(aMinheap));

    printf("\nPrinting heap like a tree: \n");
    printHeap(aMinheap);
    printf("\nPrinting heap like an array: \n");
    printHeapArray(aMinheap);

    int lookForMe = 20;
    printf("\n\nIs %d in the heap? %d\n", lookForMe, hExists(aMinheap, lookForMe));

    printf("\n- Deleting some values -\n");
    printf("Removed %d\n", hPop(&aMinheap));
    printf("Removed %d\n", hPop(&aMinheap));
    printf("Heap after calling hPop twice:\n");
    printHeap(aMinheap);

    pause;
    return 0;
}
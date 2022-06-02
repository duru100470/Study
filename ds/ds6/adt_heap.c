#include <stdio.h>
#include <stdlib.h> // malloc, realloc

#include "adt_heap.h"

/* Reestablishes heap by moving data in child up to correct location heap array
 */
static void _reheapUp(HEAP *heap, int index)
{
    int newIndex;

    while (index != 0)
    {
        newIndex = ((index + 1) / 2) - 1;

        if (heap->compare(heap->heapArr[index], heap->heapArr[newIndex]) > 0)
        {
            void *tmpPtr = heap->heapArr[newIndex];
            heap->heapArr[newIndex] = heap->heapArr[index];
            heap->heapArr[index] = tmpPtr;
            index = newIndex;
        }
        else
        {
            break;
        }
    }
}

/* Reestablishes heap by moving data in root down to its correct location in the heap
 */
static void _reheapDown(HEAP *heap, int index)
{
    int newIndex = ((index + 1) * 2) - 1;

    while (newIndex <= heap->last)
    {
        if (newIndex + 1 <= heap->last)
        {
            if (heap->compare(heap->heapArr[newIndex], heap->heapArr[newIndex + 1]) < 0)
            {
                newIndex++;
            }
        }
        if (heap->compare(heap->heapArr[index], heap->heapArr[newIndex]) < 0)
        {
            void *tmpPtr = heap->heapArr[newIndex];
            heap->heapArr[newIndex] = heap->heapArr[index];
            heap->heapArr[index] = tmpPtr;
            index = newIndex;
        }
        else
        {
            break;
        }

        newIndex = ((index + 1) * 2) - 1;
    }
}

/* Allocates memory for heap and returns address of heap head structure
if memory overflow, NULL returned
*/
HEAP *heap_Create(int capacity, int (*compare)(void *arg1, void *arg2))
{
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    if (heap == NULL)
        return NULL;

    heap->capacity = capacity;
    heap->last = -1;
    heap->compare = compare;
    heap->heapArr = (void **)malloc(sizeof(void *) * capacity);

    return heap;
}

/* Free memory for heap
 */
void heap_Destroy(HEAP *heap)
{
    for (int i = 0; i < heap->last + 1; i++)
    {
        free(heap->heapArr[i]);
    }

    free(heap->heapArr);
    free(heap);
}

/* Inserts data into heap
return 1 if successful; 0 if heap full
*/
int heap_Insert(HEAP *heap, void *dataPtr)
{
    if (heap->capacity == heap->last + 1)
    {
        heap->capacity *= 2;
        heap->heapArr = (void **)realloc(heap->heapArr, sizeof(void *) * heap->capacity);
        if (heap->heapArr == NULL)
            return 0;
    }

    heap->heapArr[heap->last + 1] = dataPtr;
    _reheapUp(heap, heap->last + 1);

    heap->last += 1;
    return 1;
}

/* Deletes root of heap and passes data back to caller
return 1 if successful; 0 if heap empty
*/
int heap_Delete(HEAP *heap, void **dataOutPtr)
{
    if (heap_Empty(heap))
        return 0;

    void *tmpPtr = heap->heapArr[0];
    heap->heapArr[0] = heap->heapArr[heap->last];
    heap->heapArr[heap->last] = tmpPtr;

    *dataOutPtr = tmpPtr;
    heap->last -= 1;
    _reheapDown(heap, 0);
    return 1;
}

/*
return 1 if the heap is empty; 0 if not
*/
int heap_Empty(HEAP *heap)
{
    if (heap->last == -1)
        return 1;
    else
        return 0;
}

/* Print heap array */
void heap_Print(HEAP *heap, void (*print_func)(void *data))
{
    for (int i = 0; i < heap->last + 1; i++)
    {
        print_func(heap->heapArr[i]);
    }
    printf("\n");
}
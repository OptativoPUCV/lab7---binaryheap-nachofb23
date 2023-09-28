#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0) {
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac) {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
    if (pq->heapArray == NULL) {
      perror("Error al redimensionar el arreglo");
      exit(EXIT_FAILURE);
    }
  }

  heapElem newElem;
  newElem.data = data;
  newElem.priority = priority;

  int index = pq->size;
  pq->heapArray[index] = newElem;
  pq->size++;

  while (index > 0) {
    int parentIndex = (index - 1) / 2;
    if (pq->heapArray[index].priority < pq->heapArray[parentIndex].priority) {
      heapElem temp = pq->heapArray[index];
      pq->heapArray[index] = pq->heapArray[parentIndex];
      pq->heapArray[parentIndex] = temp;
      index = parentIndex;
    } else {
        break;
    }
  }
}


void heap_pop(Heap* pq){
  if (pq->size == 0) {
    return;
  }

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  while (1) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild > pq->size && pq->heapArray[leftChild].priority < pq->heapArray[smallest]. priority) {
      smallest = leftChild;
    }
    if (rightChild < pq->size && pq->heapArray[rightChild].priority < pq->heapArray[smallest]. priority) {
      smallest = rightChild;
    }

    if (smallest == index) {
      heapElem temp = pq->heapArray[index];
      pq->heapArray[index] = pq->heapArray[smallest];
      pq->heapArray[smallest] = temp;
      index = smallest;
    } else {
      break;
    }
  }
}

Heap* createHeap(){
  Heap* pq = (Heap*)malloc(sizeof(Heap));
  if (pq == NULL) {
    perror("Error al crear el Heap");
    exit(EXIT_FAILURE);
  }

  pq->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
  if (pq->heapArray == NULL) {
    perror("Error al reservar memoria del arreglo");
    free(pq);
    exit(EXIT_FAILURE);
  }

  pq->size = 0;
  pq->capac = 3;
  
   return pq;
}

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
  
  int index = pq->size;
  pq->heapArray[index].data = data;
  pq->heapArray[index].priority = priority;

  pq->size++;

  while (index > 0 && priority > pq->heapArray[(index - 1) / 2].priority) {
    heapElem temp = pq->heapArray[index];
    pq->heapArray[index] = pq->heapArray[(index - 1) / 2];
    pq->heapArray[(index - 1) / 2] = temp;
    index = (index - 1) / 2;
  }
}


void heap_pop(Heap* pq){
  if (pq->size == 0) {
    return;
  }

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  int index = 0;
  while (1) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->heapArray[leftChild].priority > pq->heapArray[largest]. priority) {
      largest = leftChild;
    }
    if (rightChild < pq->size && pq->heapArray[rightChild].priority > pq->heapArray[largest]. priority) {
      largest = rightChild;
    }

    if (largest != index) {
      heapElem temp = pq->heapArray[index];
      pq->heapArray[index] = pq->heapArray[largest];
      pq->heapArray[largest] = temp;
      index = largest;
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

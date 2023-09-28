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

}


void heap_pop(Heap* pq){

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

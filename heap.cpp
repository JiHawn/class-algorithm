#include <iostream>

#define HEAP_SIZE 256

using namespace std;

int heap[HEAP_SIZE]; // max heap
int heap_count = 0;

void swap(int *a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// void push(int data) {
//     heap[++heap_count] = data;
//     int child = heap_count;
//     int parent = child / 2;
//     while(heap[child] > heap[parent] && child > 1) {
//         swap(&heap[child], &heap[parent]);
//         child = parent;
//         parent = child/2;
//     }
// }

// int pop() {
//     int res = heap[1];
//     swap(&heap[1], &heap[heap_count]);
//     heap_count--;
//     int parent = 1;
//     int child = parent * 2;
//     if(child + 1 <= heap_count) {
//         child = (heap[child] > heap[child+1]) ? child : child + 1;
//     }
//     while(child <= heap_count && heap[parent] < heap[child]) {
//         swap(&heap[parent], &heap[child]);
//         parent = child;
//         child = parent * 2;
//         if(child + 1 <= heap_count) {
//             child = (heap[child] > heap[child+1]) ? child : child + 1;
//         }
//     }
//     return res;
// }

void push(int data) {
    heap[++heap_count] = data;
    int child = heap_count;
    int parent = heap_count/2;

    while(heap[child] > heap[parent] && child != 1) {
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child/2;
    }
}

int pop() {
    int res = heap[1];
    swap(&heap[1], &heap[heap_count]);
    heap_count--;
    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= heap_count) child = heap[child] > heap[child+1] ? child : child + 1;
    while(heap[parent] < heap[child] && parent <= heap_count) {
        swap(heap[parent], heap[child]);
        parent = child;
        child = parent * 2;
        if(child + 1 <= heap_count) child = heap[child] > heap[child+1] ? child : child + 1;
    }
    return res;
}

int main(void) {
    push(10);
    push(5);
    push(11);
    push(12);
    push(1);
    pop();
    pop();

    for(int i=1; i<heap_count+1; i++) {
        cout << heap[i] << endl;
    }
}
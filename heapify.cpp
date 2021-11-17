#include <iostream>

#define HEAP_SIZE 100

using namespace std;

int heap_size = 0;
int heap_length = 0;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArr(int *a) {
    for(int i=0; i<heap_length; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// void maxHeapify(int *a, int index) {
//     int largest = index;
//     int left = index*2 + 1;
//     int right = index*2 + 2;
//     if(left <= heap_size && a[left] > a[largest]) {
//         largest = left;
//     }
//     if(right <= heap_size && a[right] > a[largest]) {
//         largest = right;
//     }
//     if(largest != index) {
//         swap(&a[index], &a[largest]);
//         maxHeapify(a, largest);
//     }
// }

void maxHeapify(int *a, int index) {
    int largest = index;
    int left = (index*2) + 1;
    int right = (index*2) + 2;
    if(heap_size >= left && a[largest] < a[left]) largest = left;
    if(heap_size >= right && a[largest] < a[right]) largest = right;
    if(largest != index) {
        swap(&a[largest], &a[index]);
        maxHeapify(a, largest);
    }
}

void buildHeap(int *a, int size) {
    heap_size = size;
    for(int i=(heap_size-1)/2; i>=0; i--) {
        maxHeapify(a, i);
    }
}

void heapSort(int *a, int length) {
    heap_length = length;
    buildHeap(a, length);
    for(int i=length; i>=0; i--) {
        swap(&a[0], &a[heap_size]);
        heap_size--;
        maxHeapify(a, 0);
    }
}

int main(void) {
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heapSort(a, 9);
    printArr(a);
}
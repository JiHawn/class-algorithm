#include <iostream>
#include <vector>
#include <queue>
#define HEAP_SIZE 100001

using namespace std;

int max_heap[HEAP_SIZE];
int min_heap[HEAP_SIZE];
int max_heap_count = 0;
int min_heap_count = 0;

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

void max_push(int data) {
    max_heap[++max_heap_count] = data;
    int child = max_heap_count;
    int parent = child / 2;
    while(max_heap[child] > max_heap[parent] && child > 1) {
        swap(&max_heap[child], &max_heap[parent]);
        child = parent;
        parent = child/2;
    }
}

int max_pop() {
    int res = max_heap[1];
    swap(&max_heap[1], &max_heap[max_heap_count]);
    max_heap_count--;
    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= max_heap_count) {
        child = (max_heap[child] > max_heap[child+1]) ? child : child + 1;
    }
    while(child <= max_heap_count && max_heap[parent] < max_heap[child]) {
        swap(&max_heap[parent], &max_heap[child]);
        parent = child;
        child = parent * 2;
        if(child + 1 <= max_heap_count) {
            child = (max_heap[child] > max_heap[child+1]) ? child : child + 1;
        }
    }
    return res;
}

void min_push(int data) {
    min_heap[++min_heap_count] = data;
    int child = min_heap_count;
    int parent = child / 2;
    while(min_heap[child] < min_heap[parent] && child > 1) {
        swap(&min_heap[child], &min_heap[parent]);
        child = parent;
        parent = child/2;
    }
}

int min_pop() {
    int res = min_heap[1];
    swap(&min_heap[1], &min_heap[min_heap_count]);
    min_heap_count--;
    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= min_heap_count) {
        child = (min_heap[child] < min_heap[child+1]) ? child : child + 1;
    }
    while(child <= min_heap_count && min_heap[parent] > min_heap[child]) {
        swap(&min_heap[parent], &min_heap[child]);
        parent = child;
        child = parent * 2;
        if(child + 1 <= min_heap_count) {
            child = (min_heap[child] < min_heap[child+1]) ? child : child + 1;
        }
    }
    return res;
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        max_heap_count = 0;
        min_heap_count = 0;
        int n;
        cin >> n;
        int mid;
        unsigned int sum = 0;
        for(int j=0; j<n; j++) {
            int num;
            cin >> num;
            if(j==0) {
                mid = num;
                max_push(num);
                sum += (mid%10);
                continue;
            }
            if(num <= mid) {
                if(max_heap_count > min_heap_count) {
                    min_push(max_pop());
                    max_push(num);
                } else {
                    max_push(num);
                }
            } else {
                if(min_heap_count > max_heap_count) {
                    max_push(min_pop());
                    min_push(num);
                } else {
                    min_push(num);
                }
            }
            if(max_heap_count > min_heap_count) mid = max_heap[1];
            else if(min_heap_count > max_heap_count) mid = min_heap[1];
            else mid = (max_heap[1] + min_heap[1]) / 2;
            sum += (mid%10);
        }
        cout << sum%10 << endl;
    }
    return 0;
}
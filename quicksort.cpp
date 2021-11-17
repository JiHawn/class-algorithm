#include <iostream>
#include <vector>

using namespace std;

int h_swap = 0;
int l_swap = 0;
int h_compare = 0;
int l_compare = 0;

int h(vector<int> *a, int low, int high) {
    int pivot = (*a)[low];
    int i = low-1;
    int j = high + 1;
    int tmp;
    while(true) {
        h_compare += 2;
        while((*a)[++i] < pivot) {h_compare++;}
        while((*a)[--j] > pivot) {h_compare++;}
        if(i<j) { // swap
            tmp = (*a)[i];
            (*a)[i] = (*a)[j];
            (*a)[j] = tmp;
            h_swap++;
        } else {
            return j;
        }
    }
}

int l(vector<int> *a, int low, int high) {
    int pivot = (*a)[low];
    int j = low;
    int tmp;
    int pivot_pos;
    for(int i=low+1; i<=high; i++) {
        l_compare++;
        if((*a)[i] < pivot) { // swap
            l_swap++;
            j++;
            tmp = (*a)[i];
            (*a)[i] = (*a)[j];
            (*a)[j] = tmp;
        }
    }
    pivot_pos = j;
    l_swap++;
    tmp = (*a)[pivot_pos];
    (*a)[pivot_pos] = (*a)[low];
    (*a)[low] = tmp; // swap
    return pivot_pos;
}

void h_quicksort(vector<int> *a, int low, int high) {
    int pivot;
    if(low >= high) {
        return;
    }
    pivot = h(a, low, high);
    h_quicksort(a, low, pivot);
    h_quicksort(a, pivot+1, high);
}

void l_quicksort(vector<int> *a, int low, int high) {
    int pivot;
    if(low >= high) {
        return;
    }
    pivot = l(a, low, high);
    l_quicksort(a, low, pivot-1);
    l_quicksort(a, pivot+1, high);
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> h_v(n,0);
        for(int j=0; j<n; j++) {
            cin >> h_v[j];
        }
        vector<int> l_v(h_v);
        h_quicksort(&h_v, 0, h_v.size()-1);
        l_quicksort(&l_v, 0, l_v.size()-1);
        cout << h_swap << " " << l_swap << " " << h_compare << " " << l_compare << endl;
        h_swap = 0;
        l_swap = 0;
        h_compare = 0;
        l_compare = 0;
    }
}
#include <iostream>
#include <vector>

using namespace std;

// void merge(vector<int> *v, int low, int mid, int high) {
//     vector<int> tmp(100);
//     int i, j, k;
//     for(int a=low; a<=high; a++) {
//         tmp[a] = (*v)[a];
//     }
//     i = low;
//     k = low;
//     j = mid+1;
//     while(i <= mid && j <= high) {
//         if(tmp[i] <= tmp[j]) (*v)[k++] = tmp[i++];
//         else (*v)[k++] = tmp[j++];
//     }
//     while(i <= mid) (*v)[k++] = tmp[i++];
//     while(j <= high) (*v)[k++] = tmp[j++];
// }

void merge(vector<int> *v, int begin, int mid, int end) {
    vector<int> tmp(100);
    int i,j,k;
    for(int a=begin; a<=end; a++) {
        tmp[a] = (*v)[a];
    }
    i = begin;
    j = mid+1;
    k = begin;
    while(i<=mid && j<=end) {
        if(tmp[i] < tmp[j]) (*v)[k++] = tmp[i++];
        else (*v)[k++] = tmp[j++];
    }
    while(i<=mid) (*v)[k++] = tmp[i++];
    while(j<=end) (*v)[k++] = tmp[j++];
}

void mergeSort(vector<int> *v, int low, int high) {
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v, low, mid, high);
}

int main(void) {
    vector<int> v = {9,8,7,6,5,4,3,2,1};
    mergeSort(&v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
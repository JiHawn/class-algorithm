#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


// int partition(vector<int> *v, int begin, int end) {
//     int pivot = (*v)[begin];
//     int j = begin;
//     for(int i=begin+1; i<=end; i++) {
//         if((*v)[i] < pivot) {
//             j++;
//             swap(&(*v)[i], &(*v)[j]);
//         }
//     }
//     int pivotPosition = j;
//     swap(&(*v)[begin], &(*v)[j]);
//     return pivotPosition;
// }

int partition(vector<int> *v, int begin, int end) {
    int pivot = (*v)[begin];
    int j = begin;
    for(int i=begin+1; i<=end; i++) {
        if((*v)[i] < pivot) {
            j++;
            swap(&(*v)[j], &(*v)[i]);
        }
    }
    int pivotPosition = j;
    swap(&(*v)[begin], &(*v)[pivotPosition]);
    return pivotPosition;
}

void quickSort(vector<int> *v, int begin, int end) {
    if(end > begin) {
        int pivotPosition = partition(v, begin, end);
        quickSort(v, begin, pivotPosition);
        quickSort(v, pivotPosition+1, end);
    }
}

int main(void) {
    vector<int> v = {15,22,13,27,12,10,20,25};
    quickSort(&v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
}
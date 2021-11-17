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
//     int i = begin - 1;
//     int j = end + 1;
    
//     while(true) {
//         while((*v)[++i] < pivot);
//         while((*v)[--j] > pivot);
        
//         if(i >= j)
//             return j;
//         else {
//             int tmp = (*v)[i]; (*v)[i] = (*v)[j]; (*v)[j] = tmp;
//         }
//     }
// }

int partition(vector<int> *v, int begin, int end) {
    int pivot = (*v)[begin];
    int i = begin - 1;
    int j = end + 1;
    while(true) {
        while((*v)[++i] < pivot);
        while((*v)[--j] > pivot);
        if(i >= j)
            return j;
        else
            swap((*v)[i], (*v)[j]);
    }
}

void quickSort(vector<int> *v, int begin, int end) {
    if(end > begin) {
        int pivotPosition = partition(v, begin, end);
        quickSort(v, begin, pivotPosition);
        quickSort(v, pivotPosition+1, end);
    }
}

int main(void) {
    vector<int> v = {4, 7, 3, 9, 2, 5, 8, 1, 6};
    quickSort(&v, 0, v.size()-1);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
     cout << endl;
}
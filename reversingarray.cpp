#include<iostream>
#include<vector>

using namespace std;

void reverseArray(vector<int> *v, int i, int j) {
    if(i >= j) return;
    int tmp = (*v)[i];
    (*v)[i] = (*v)[j];
    (*v)[j] = tmp;
    reverseArray(v, i+1, j-1);
}

int main(void) {
    vector<int> original = {4,7,6,2,9,2,1};
    reverseArray(&original, 0, original.size()-1);
    for(int i=0; i<original.size(); i++) {
        cout << original[i] << " ";
    }
}
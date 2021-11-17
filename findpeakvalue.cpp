#include <iostream>
#include <vector>

using namespace std;

int findPeakValue(vector<int> v, int begin, int end) {
    if(end-begin <= 1) return v[begin];
    int mid = (end + begin)/2;
    if(v[mid-1] <= v[mid] && v[mid+1] <= v[mid]) return v[mid];
    else {
        if(v[mid+1] > v[mid]) return findPeakValue(v, mid+1, end);
        else if(v[mid-1] > v[mid]) return findPeakValue(v, begin, mid);
    }
}

int main(void) {
    vector<int> v = {12, 15, 20, 25, 32, 35, 40, 45, 31, 26};
    vector<int> v2= {53, 60, 74, 30, 25, 20, 15, 13, 12, 10};
    vector<int> v3 = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
    cout << findPeakValue(v3, 0, v3.size());
}
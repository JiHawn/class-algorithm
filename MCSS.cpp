#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int mcss(vector<int> v, int begin, int end) {
//     if(begin == end) return v[begin];
//     int mid = (begin+end) / 2;
//     int left = mcss(v, begin, mid);
//     int right = mcss(v, mid+1, end);
//     int sum = 0;
//     int left_max = 0;
//     int mid_max;
//     for(int i=mid; i>=begin; i--) {
//         sum += v[i];
//         if(left_max < sum) left_max = sum;
//     }
//     sum = 0;
//     int right_max = 0;
//     for(int i=mid+1; i<=end; i++) {
//         sum += v[i];
//         if(right_max < sum) right_max = sum;
//     }
//     mid_max = left_max + right_max;
//     priority_queue<int, vector<int>> pq;
//     pq.push(mid_max);
//     pq.push(left);
//     pq.push(right);
//     return pq.top();
// }

int mcss(vector<int> v, int begin, int end) {
    if(begin >= end) return v[begin];
    int left = 0;
    int right = 0;
    int left_max = 0;
    int right_max = 0;
    int mid = (begin+end) / 2;
    int left_mcss = mcss(v, begin, mid);
    int right_mcss = mcss(v, mid+1, end);

    for(int i=mid; i>=begin; i--) {
        left += v[i];
        if(left > left_max) left_max = left;
    }

    for(int i=mid+1; i<=end; i++) {
        right += v[i];
        if(right > right_max) right_max = right;
    }

    int mid_mcss = left_max + right_max;
    int max;
    if(mid_mcss > left_mcss) max = mid_mcss;
    else max = left_mcss;
    if(right_mcss > max) max = right_mcss;
    return max;
}

int main(void) {
    vector<int> v = {5, -7, 2, 3, -4, 5, 2, -7, 8, -7};
    cout << mcss(v, 0, v.size()-1) << endl;
}
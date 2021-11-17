#include <iostream>
#include <vector>

using namespace std;

int minmult(vector<int> d) {
    int n = d.size()-1;
    int M[n+1][n+1];
    for(int i=0; i<=n; i++) {
        M[i][i] = 0;
    }
    for(int diagonal = 1; diagonal <= n-1; diagonal++) {
        for(int i=1; i<=n-diagonal; i++) {
            int j = i + diagonal;
            int min = 99999999999;
            for(int k=i; k<=j-1; k++) {
                int m = M[i][k] + M[k+1][j] + (d[i-1]*d[k]*d[j]);
                if(min > m) min = m;
            }
            // cout << "i= " << i << " j= " << j << " min= " << min << endl;
            M[i][j] = min;
        }
    }
    return M[1][n];
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        vector<int> d;
        cin >> n;
        for(int i=0; i<n+1; i++) {
            int num;
            cin >> num;
            d.push_back(num);
        }
        int res = minmult(d);
        cout << res << endl;
    }
}
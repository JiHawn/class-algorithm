#include <iostream>
#include <vector>
#include <string>

#define MAX(a,b) ((a)>(b) ? (a):(b))

using namespace std;

int LCS(string s, string t) {
    int L[101][101];
    for(int i=0; i<101; i++) {
        L[0][i] = 0;
    }
    for(int i=0; i<101; i++) {
        L[i][0] = 0;
    }

    for(int i=1; i<=s.size(); i++) {
        for(int j=1; j<=t.size(); j++) {
            if(s[i-1] == t[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = MAX(L[i][j-1], L[i-1][j]);
            }
        }
    }
    return L[s.size()][t.size()];
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        string a, b;
        cin >> a;
        cin >> b;
        int res = LCS(a,b);
        cout << res << endl;
    }
}

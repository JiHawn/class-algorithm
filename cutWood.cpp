#include <iostream>
#include <vector>

using namespace std;

int cutWood(vector<int> location, int length) {
    int N[length+1][length+1] = {0};
    
    for(int n=1; n<=length; n++) {
        for(int a=0; a<=length-1; a++) {
            if(a+n > length) break;
            int b = a + n;
            int min = 9999999;
            vector<int> inRange;
            for(int i=0; i<location.size(); i++) {
                if(location[i] > a && location[i] < b) inRange.push_back(location[i]);
            }
            if(inRange.size() != 0) {
                for(int i=0; i<inRange.size(); i++) {
                    int value = N[a][inRange[i]] + N[inRange[i]][b];
                    if(min > value) min = value;
                }
                N[a][b] = min + b-a;
            }
        }
    }
    return N[0][length];
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int length;
        int num;
        cin >> length;
        cin >> num;
        vector<int> v;
        for(int j=0; j<num; j++) {
            int l;
            cin >> l;
            v.push_back(l);
        }
        cout << cutWood(v, length) << endl;
    }
}
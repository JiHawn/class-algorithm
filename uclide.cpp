#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(void) {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
}
#include <iostream>

using namespace std;

int fibonachi(int n) {
    if(n < 3) {
        return n;
    }
    else {
        int f = fibonachi(n-2) + fibonachi(n-1);
        return f;
    }
}

int main(void) {
    int c;
    cin >> c;
    for(int i=1; i<c+1; i++) {
        cout << fibonachi(i) << " ";
    }
}
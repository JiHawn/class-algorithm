#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checkPalindrom(string s, int i, int j) {
    if(i >= j) return 1;
    if(s[i] != s[j]) return 0;
    return checkPalindrom(s, i+1, j-1);
}

int main(void) {
    string s;
    cin >> s;
    int res = checkPalindrom(s, 0, s.length()-1);
    cout << res;    
}
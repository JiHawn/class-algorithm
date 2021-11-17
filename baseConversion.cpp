#include <iostream>
#include <vector>

using namespace std;

const char baseTable[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

void baseConversion(int num, int base) {
    if(num >= base) baseConversion(num/base, base);
    cout << baseTable[num%base];
}

int main(void) {
    int num;
    int base;
    cin >> num >> base;
    baseConversion(num, base);
}
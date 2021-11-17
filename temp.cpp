#include <iostream>

using namespace std;

int main(){
	unsigned long long int a = 9223372036854775808;
	a = a >> 63;
	cout << a << endl;
}
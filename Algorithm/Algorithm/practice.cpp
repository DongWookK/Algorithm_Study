#include <iostream>
#include <vector>
using namespace std;
int main() {

	char a = 'z';
	int ia = (int)a;
	cout << ia;


	int temp = (char)ia+4 %122;
	ia = 97 + temp;
	a = (char)ia;
	string str;
	str.append(1, a);
	cout << str;

	return 0;
}
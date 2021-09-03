#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void Print(stack<char> &s)
{
	while (s.empty() == false)
	{
		cout << s.top();
			s.pop();
	}
}

int main()
{
	string str;
	getline(cin, str);
	bool tag = false;
	stack<char> s;
	for (char ch : str)
	{
		if (ch == '<'){
			tag = true;
			Print(s);
			cout << ch;
		}
		else if (ch == '>') {
			tag = false;
			cout << ch;
		}
		else if (tag) {
			cout << ch;
		}
		else {
			if (ch == ' ') {
				Print(s);
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}

	}
	Print(s);
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	char prev = '0';
	string str;
	int res=0;
	getline(cin, str);
	stack<char> s;


	for(char ch : str)
	{
		if (ch == '('){
			s.push(ch);
		}
		else if (ch == ')'){
			s.pop();
			if (prev == '(')
			{
				res += s.size();
			}
			else
			{	
				res++;
			}
		}
		prev = ch;
	}
	cout << res;
	return 0;
}
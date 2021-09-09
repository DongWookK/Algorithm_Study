#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n,i;
	int score = 1;
	int totalScore = 0;
	stack<char> s;
	cin >> n;
	cin.ignore();
	vector<string> temp(n);
	for (i = 0; i < n; i++)
		getline(cin, temp[i]);

	for (i = 0; i < n; i++)
	{
		for (char ch : temp[i])
		{
			if (ch == 'O')
			{
				if (!s.empty()){
					score = s.size() + 1;
				}
				totalScore += score;
				s.push(ch);
			}
			else {
				score = 1;
				while (!s.empty()) {
					s.pop();
				}
			}

		}
		cout << totalScore << endl;;
		totalScore = 0;
		score = 1;
		while (!s.empty()) {
			s.pop();
		}
	}

	return 0;
}
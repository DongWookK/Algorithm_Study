#define CRT_SECURE_NO_WARNING
#include <iostream>
#include <stack>
#include <vector>
#define size 9
using namespace std;

//첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.


int main()
{
	int n,i;
	stack<int> s;
	cin >> n;

	vector<int> A(n);
	vector<int> res(n);
	for (i = 0; i < n; i++) cin >> A[i];

	for (i = 0; i < n; i++)
	{
		if (s.empty() == true)
			s.push(i);
		while (s.empty() == false && A[s.top()] < A[i])
		{
			res[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
		
	}
	
	while (s.empty() == false)
	{
		res[s.top()] = -1;
		s.pop();
	}
	
	for (i = 0; i < n; i++)
		cout << res[i] << " ";

	return 0;
}
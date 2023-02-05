#include <iostream>
#include <vector>
using namespace std;

int GetGCD(int a, int b)
{
	if (b == 0)
		return a;
	return GetGCD(b, a % b);
}

int main()
{
	int n, s;
	int i;
	int gcd = 0;
	cin >> n >> s;
	vector<int>A(n);
	
	for (int i = 0; i < n; i++)	cin >> A[i];
	for (int i = 0; i < n; i++) A[i] = A[i] - s;

	if (n == 1)
	{
		gcd = A[0];
	}
	else {
		for (i = 0; i < n-1; i++)
		{
			if (i == 0)
				gcd = GetGCD(A[i], A[i + 1]);
			gcd = GetGCD(gcd, A[i + 1]);

		}
	}
	if (gcd < 0)
		gcd *= -1;
	cout << gcd;


	return 0;
}
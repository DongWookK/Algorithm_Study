#define CRT_SECURE_NO_WARNING
#include <iostream>
#include <vector>
using namespace std;

bool IsPrimeNumber(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
	
}

int main()
{
	int n, i;
	int res = 0;
	cin >> n;
	vector<int> num(n);
	for (i = 0; i < n; i++) cin >> num[i];

	for (i = 0; i < n; i++)
	{
		if (IsPrimeNumber(num[i]))
			res++;
	}
	cout << res;
	return 0;
}
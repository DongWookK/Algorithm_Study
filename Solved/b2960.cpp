#include <iostream>
#include <vector>
using namespace std;


//에라스토테네스의 체

int main()
{
	int n;
	int pn = 0;
	int count = 0;
	int k,result;
	cin >> n;
	cin >> k;
	int size = n + 1;
	vector<int> prime(size);
	vector<bool> check(size,false);
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == false) {
			prime[pn++] = i;
			count++;
			if (count == k) {
				result = i;
			}
			for (int j = i * 2; j <= n; j += i)
			{
				//이미 지워진 수는 스킵하게끔
				if (check[j] == true)
					continue;

				check[j] = true;
				count++;
				if (count == k)
				{
					result = j;
				}
			}
		}
	
	}
	cout << result;
	return 0;
}
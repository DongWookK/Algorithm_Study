#include <iostream>
#include <vector>
using namespace std;


//�������׳׽��� ü

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
				//�̹� ������ ���� ��ŵ�ϰԲ�
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
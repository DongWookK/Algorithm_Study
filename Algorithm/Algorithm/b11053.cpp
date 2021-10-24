#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n;
	int a;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int>s(n);//벡터 초기화파라미터? n개만큼 0으로

	//0부터 순회하며
	//이전것중에 가장 크고 카운트가 큰 애에서 +1
	for (int i = 0; i < n; i++) {
		s[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && s[i] < s[j]+1) {
				s[i] = s[j] + 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] > answer) {
			answer = s[i];
		}
	}
	cout << answer;
	return 0;
}
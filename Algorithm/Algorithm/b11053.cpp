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

	vector<int>s(n);//���� �ʱ�ȭ�Ķ����? n����ŭ 0����

	//0���� ��ȸ�ϸ�
	//�������߿� ���� ũ�� ī��Ʈ�� ū �ֿ��� +1
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
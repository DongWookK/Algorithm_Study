#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<pair<int,int>>s(n);// first -> 수열 수  second -> 해당 값을 도출한 인덱스 // 굳이 페어로 안만들고 어레이하나 더만들어될듯.

	for (int i = 0; i < n; i++) {
		s[i].first = 1;
		s[i].second = -1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && s[i].first < s[j].first + 1) {
				s[i].first = s[j].first + 1;
				s[i].second = j;
			}
		}
	}
	

	int max = 0;
	int idx;
	for (int i = 0; i < n; i++) {
		if (s[i].first > max) {
			max = s[i].first;
			idx = i;
		}
		
	}

	vector<int>ans;
	while (1) {
		ans.push_back(v[idx]);
		if (s[idx].second == -1) {
			break;
		}
		idx = s[idx].second;
	}
	/*
	for (int i = 0; i < s.size(); i++) {
		cout << s[i].first << " " << s[i].second << endl;
	}
	*/
	int len = ans.size() - 1;
	cout << max << endl;
	for(int i = len; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}
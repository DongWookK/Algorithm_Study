#include <iostream>
#include <vector>
using namespace std;

int memo[100];
int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		if (memo[n] > 0) {
			return memo[n];
		}
		else {
			memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return memo[n];
		}
	}
}

int main() {
	cout << memo[1] << endl;
	vector<int> memo2(100);
	fill(memo2.begin(), memo2.end(),-1);
	cout << memo2[0] << endl;
}
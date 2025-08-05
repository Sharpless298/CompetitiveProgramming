#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) 
			cout << i % (n < (m + 1) * k ? k : n / (m + 1)) << " \n"[i == n - 1];
	}
}

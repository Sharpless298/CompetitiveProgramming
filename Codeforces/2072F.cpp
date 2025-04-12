#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		n--;
		for (int i = 0; i <= n; i++)
			cout << ((n & i) == i ? k : 0) << " \n"[i == n];
	}
}

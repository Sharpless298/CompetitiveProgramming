#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> b(n - 2);
		for (int &i : b)
			cin >> i;

		bool ok = true;
		for (int i = 1; i < n - 3; i++) {
			if (b[i] == 0 && b[i - 1] == 1 && b[i + 1] == 1) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

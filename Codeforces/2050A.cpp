#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		cin.ignore();
		int ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			sum += (int)s.size();
			if (sum <= m)
				ans = i + 1;
		}

		cout << ans << '\n';
	}
}

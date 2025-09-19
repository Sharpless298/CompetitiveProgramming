#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		string ans;
		for (int i = 0; i < m; i++) {
			string tmp = s[0];
			for (char j = 'a'; j <= 'z'; j++) {
				tmp[i] = j;

				bool ok = true;
				for (int k = 1; k < n; k++) {
					int cnt = 0;
					for (int l = 0; l < m; l++) {
						cnt += (tmp[l] != s[k][l]);
					}
					if (cnt > 1) {
						ok = false;
					}
				}
				if (ok) {
					ans = tmp;
				}
			}
		}
		cout << (ans.empty() ? "-1" : ans) << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int n = (int)s.size();
		vector<int> pref_0(n + 1), pref_1(n + 1);
		pref_0[0] = pref_1[0] = 0;
		for (int i = 0; i < n; i++) {
			pref_0[i + 1] = pref_0[i] + (s[i] == '0');
			pref_1[i + 1] = pref_1[i] + (s[i] == '1');
		}

		int ans = 0x3f3f3f3f;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && pref_0[j] - pref_0[i] < pref_1[i] + pref_1[n] - pref_1[j]) j++;
			ans = min(ans, max(pref_0[j] - pref_0[i], pref_1[i] + pref_1[n] - pref_1[j]));
		}
		cout << ans << '\n';
	}
}

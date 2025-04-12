#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<unsigned long long> mp(1000001);
	for (int i = 1; i < 1000001; i++)
		mp[i] = rng();

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<unsigned long long> pref(n + 1);
		pref[0] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pref[i + 1] = pref[i] ^ mp[x];
		}

		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << (pref[l - 1] == pref[r] ? "YES\n" : "NO\n");
		}
	}
}

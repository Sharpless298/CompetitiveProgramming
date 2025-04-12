#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
const long long P = rng() % MOD + 26;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int n = (int)s.size();
		vector<int> nxt(n, n);
		nxt[n - 1] = n;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] != 'a')
				nxt[i] = i;
			else if (i + 1 < n)
				nxt[i] = nxt[i + 1];
		}

		if (nxt[0] == n) {
			cout << n - 1 << '\n';
			continue;
		}

		vector<long long> pref(n + 1);
		pref[0] = 0;
		for (int i = 1; i <= n; i++)
			pref[i] = (pref[i - 1] * P + (s[i - 1] - 'a')) % MOD;
		vector<long long> p(n + 1);
		p[0] = 1;
		for (int i = 1; i <= n; i++)
			p[i] = p[i - 1] * P % MOD;

		auto f = [&](int i, int len) { return ((pref[i + len] - pref[i] * p[len]) % MOD + MOD) % MOD; };
		long long ans = 0;
		for (int len = 1; nxt[0] + len <= n; len++) {
			int i = nxt[0] + len, mn = nxt[0];
			long long h = f(nxt[0], len);
			bool ok = true;
			while (i < n) {
				if (nxt[i] == n)
					break;
				int c = nxt[i] - i;
				mn = min(mn, c);
				i += c;
				if (i + len > n || f(i, len) != h) {
					ok = false;
					break;
				}
				i += len;
			}
			if (ok)
				ans += mn + 1;
		}
		cout << ans << '\n';
	}
}

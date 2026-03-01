#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<int, uint64_t> mp;
	vector<uint64_t> a(n);
	{
		set<int> aa;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (aa.count(x)) {
				a[i] = 0;
			} else {
				aa.insert(x);
				if (!mp.count(x)) {
					mp[x] = rng();
				}
				a[i] = mp[x];
			}
		}
	}
	vector<uint64_t> b(n);
	{
		set<int> bb;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (bb.count(x)) {
				b[i] = 0;
			} else {
				bb.insert(x);
				if (!mp.count(x)) {
					mp[x] = rng();
				}
				b[i] = mp[x];
			}
		}
	}
	vector<uint64_t> pref_a(n + 1), pref_b(n + 1);
	for (int i = 0; i < n; i++) {
		pref_a[i + 1] = pref_a[i] ^ a[i];
		pref_b[i + 1] = pref_b[i] ^ b[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (pref_a[x] == pref_b[y] ? "Yes\n" : "No\n");
	}
}

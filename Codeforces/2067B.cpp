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
		vector<int> a(n);
		map<int, int> mp;
		for (int &i : a) {
			cin >> i;
			mp[i]++;
		}

		bool ok = true;
		for (auto p : mp) {
			if (p.second == 1) {
				ok = false;
				break;
			}
			if (p.second >= 3)
				mp[p.first + 1] += p.second - 2;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

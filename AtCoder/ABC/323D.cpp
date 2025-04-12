#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<long long, long long> mp;
	for (int i = 0; i < n; i++) {
		int s, c;
		cin >> s >> c;
		mp[s] = c;
	}

	for (auto &p : mp) {
		if (p.second >= 2)
			mp[p.first * 2] += p.second / 2;
		p.second %= 2;
	}

	int ans = 0;
	for (auto p : mp)
		if (p.second != 0)
			ans++;

	cout << ans << '\n';
}

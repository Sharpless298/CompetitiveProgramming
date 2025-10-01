#include <bits/stdc++.h>
using namespace std;

int solve(int n, string s) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			v.push_back(i);
		}
	}

	int ret = 0, t = (int)v.size() / 2;
	for (int i = 0; i < (int)v.size(); i++) {
		ret += abs(v[t] - v[i]) - abs(t - i);
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int ans = 0x3f3f3f3f;
		ans = min(ans, solve(n, s));
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a') {
				s[i] = 'b';
			} else {
				s[i] = 'a';
			}
		}
		ans = min(ans, solve(n, s));
		cout << ans << '\n';
	}
}

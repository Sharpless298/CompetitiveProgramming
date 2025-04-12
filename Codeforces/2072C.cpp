#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		vector<int> ans;
		int k = 0;
		for (int i = 1; i <= 30; i++) {
			if ((x & ((1 << i) - 1)) == (1 << i) - 1) {
				k = (1 << i) - 1;
			}
		}

		int t = 0, tt = 0;
		while (t <= k && (int)ans.size() + 1 < n)
			tt |= t, ans.push_back(t++);
		if ((tt | t) == x)
			ans.push_back(t);
		while ((int)ans.size() < n)
			ans.push_back(x);
		for (int i : ans)
			cout << i << ' ';
		cout << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		multiset<int> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}

		int ans = 0;
		while (!s.empty()) {
			int t = *s.begin();
			s.erase(s.begin());
			if (s.count(k - t)) {
				ans++;
				s.erase(s.find(k - t));
			}
		}
		cout << ans << '\n';
	}
}

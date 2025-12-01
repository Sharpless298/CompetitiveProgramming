#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		long long ans = 0;
		vector<int> stk;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				ans += 1LL * (i + 1) * (n - i);
			} else {
				int x = max(a[i], b[i]);
				int l = -1, r = (int)stk.size();
				while (r - l > 1) {
					int m = (l + r) / 2;
					if (a[stk[m]] >= x) {
						l = m;
					} else {
						r = m;
					}
				}

				if (l > -1) {
					ans += 1LL * (stk[l] + 1) * (n - i);
				}
			}
			while (!stk.empty() && a[stk[stk.size() - 1]] < a[i]) {
				stk.pop_back();
			}
			stk.push_back(i);
		}

		cout << ans << '\n';
	}
}

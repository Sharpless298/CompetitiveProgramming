#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());

	vector<long long> pref(n + 1);
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + x[i];
	}
	function<long long(int, int, int)> f = [&](int y, int a, int b) {
		int idx = (int)(lower_bound(x.begin(), x.end(), y) - x.begin());
		return 1LL * a * (1LL * idx * y - pref[idx]) + 1LL * b * ((pref[n] - pref[idx]) - 1LL * y * (n - idx));
	};

	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;

		int l = -1, r = 1e6 + 1;
		while (r - l > 2) {
			int ml = l + (r - l) / 3;
			int mr = r - (r - l) / 3;

			f(ml, a, b) < f(mr, a, b) ? r = mr : l = ml;
		}

		cout << f(l + 1, a, b) << '\n';
	}
}

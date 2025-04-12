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
		for (int &i : a)
			cin >> i;

		vector<long long> pref(n + 1);
		pref[0] = 0;
		for (int i = 0; i < n; i++)
			pref[i + 1] = pref[i] + (a[i] > 0 ? a[i] : 0);
		vector<long long> suf(n + 1);
		suf[0] = 0;
		for (int i = 0; i < n; i++)
			suf[i + 1] = suf[i] + (a[n - i - 1] < 0 ? -a[n - i - 1] : 0);

		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, pref[i + 1] + suf[n - i]);
		cout << ans << '\n';
	}
}

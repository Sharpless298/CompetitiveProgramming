#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, x;

	cin >> T;
	while (T--) {
		cin >> n >> x;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<lli> pref(n + 1);
		for (int i = 0; i < n; i++)
			pref[i + 1] = pref[i] + a[i];

		vector<int> dp(n + 2);
		for (int i = n - 1; i >= 0; i--) {
			int k = (int)(upper_bound(pref.begin(), pref.end(), pref[i] + x) - pref.begin());
			dp[i] = dp[k] + k - i - 1;
		}

		cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
	}
}

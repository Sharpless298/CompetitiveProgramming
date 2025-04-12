#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		int n;
		lli m;

		cin >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());
		lli sum = 0, ans = 0;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && (a[j] - a[i]) <= 1 && sum + a[j] <= m) {
				sum += a[j++];
				if (sum <= m)
					ans = max(ans, sum);
			}

			sum -= a[i];
		}

		cout << ans << '\n';
	}
}

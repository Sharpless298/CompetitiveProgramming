#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(2);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<double> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());
		double ans = 0;
		for (int i = 2; i < n; i++) {
			double s = (a[i - 2] + a[i - 1] + a[i]) / 2;
			ans = max(ans, sqrt(s * (s - a[i - 2]) * (s - a[i - 1]) * (s - a[i])));
		}

		cout << ans << '\n';
	}
}

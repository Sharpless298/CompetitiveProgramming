#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	while (q--) {
		int b, k;
		cin >> b >> k;

		int l = 0, r = 2e8 + 5;
		while (l < r) {
			int m = (l + r) / 2;

			int t = (int)(upper_bound(a.begin(), a.end(), b + m) - lower_bound(a.begin(), a.end(), b - m));

			if (t < k)
				l = m + 1;
			else
				r = m;
		}

		cout << l << '\n';
	}
}

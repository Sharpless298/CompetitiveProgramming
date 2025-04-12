#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	lli l = a[n / 2], r = 1e18 + 5;
	while (l < r) {
		lli m = (l + r) / 2;

		lli sum = 0;
		for (int i = n / 2; i < n; i++) {
			sum += max(0LL, m - a[i]);
			if (sum > k)
				break;
		}

		if (sum <= k)
			l = m + 1;
		else
			r = m;
	}

	cout << l - 1 << '\n';
}

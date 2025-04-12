#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	int l = *a.begin(), r = *a.rbegin();

	int ans = INT_MAX;
	for (int i = l; i <= r; i++) {
		int res = 0;

		for (int j = 0; j < n; j++)
			res += (a[j] - i) * (a[j] - i);

		ans = min(ans, res);
	}

	cout << ans << '\n';
}

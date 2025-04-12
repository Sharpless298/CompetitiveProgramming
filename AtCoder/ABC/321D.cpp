#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m);
	for (int &i : a)
		cin >> i;
	for (int &i : b)
		cin >> i;
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	vector<long long> pref(m + 1);
	for (int i = 0; i < m; i++)
		pref[i + 1] = pref[i] + b[i];

	long long ans = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && a[i] + b[j] <= p)
			j++;

		ans += 1LL * a[i] * j + pref[j] + 1LL * p * (m - j);
	}

	cout << ans << '\n';
}

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
	vector<long long> pref(n + 1);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << pref[r] - pref[l] << '\n';
	}
}

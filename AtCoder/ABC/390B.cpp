#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n);
	for (long long &i : a)
		cin >> i;

	bool ok = true;
	for (int i = 1; i < n - 1; i++)
		if (a[i] * a[i] != a[i - 1] * a[i + 1])
			ok = false;
	cout << (ok ? "Yes\n" : "No\n");
}

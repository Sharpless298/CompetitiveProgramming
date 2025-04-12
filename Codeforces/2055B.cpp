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
		vector<int> a(n), b(n);
		for (int &i : a)
			cin >> i;
		for (int &i : b)
			cin >> i;

		vector<int> c;
		for (int i = 0; i < n; i++)
			c.push_back(a[i] - b[i]);
		sort(c.begin(), c.end());

		if (c[0] < 0 && -c[0] > c[1])
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}

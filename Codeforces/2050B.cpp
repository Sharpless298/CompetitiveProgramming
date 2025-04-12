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
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		long long suma = 0, sumb = 0;
		for (int i = 0; i < n; i += 2)
			suma += a[i];
		for (int i = 1; i < n; i += 2)
			sumb += a[i];

		if (suma % ((n + 1) / 2) != 0 || sumb % (n / 2) != 0 || (suma / ((n + 1) / 2) != sumb / (n / 2)))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}

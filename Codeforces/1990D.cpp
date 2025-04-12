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
		int ans = 0;
		for (int &i : a)
			cin >> i, ans += (i > 0);

		for (int i = 0; i < n; i++) {
			if (a[i] == 0 || a[i] > 2)
				continue;
			else {
				int j = i + 1;
				while (j < n && (a[j] == 3 || a[j] == 4))
					j++;
				if (j < n && ((a[j] == 1 || a[j] == 2) && (j - i) & 1)) {
					ans--;
					i = j;
				}
			}
		}

		cout << ans << '\n';
	}
}

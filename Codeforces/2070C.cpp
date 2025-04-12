#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		int l = 0, r = 1000000001;
		while (l < r) {
			int m = (l + r) / 2;

			int cnt = 0;
			char prv = 'c';
			for (int i = 0; i < n; i++) {
				if (a[i] > m) {
					if (s[i] == 'B' && prv != 'B')
						cnt++;
					prv = s[i];
				}
			}

			if (cnt > k)
				l = m + 1;
			else
				r = m;
		}

		cout << l << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			a[i] = s[i] - '0';
		for (int i = 0; i < n - 1; i++) {
			int mx = a[i], pos = -1;
			for (int j = 1; j <= min(n - i - 1, 9 - a[i] - 1); j++)
				if (a[i + j] - j > mx)
					mx = max(mx, a[i + j] - j), pos = j;

			if (pos != -1) {
				a[i + pos] = mx;
				for (int k = i + pos; k > i; k--)
					swap(a[k - 1], a[k]);
			}
		}

		for (int i : a)
			cout << i;
		cout << '\n';
	}
}

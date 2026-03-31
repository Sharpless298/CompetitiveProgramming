#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> p;
		for (int i = 0; i < n / 6; i++) {
			vector<int> v;
			v.push_back(2 + 6 * i);
			v.push_back(1 + 6 * i);
			v.push_back(4 + 6 * i);
			v.push_back(6 + 6 * i);
			v.push_back(5 + 6 * i);
			v.push_back(3 + 6 * i);
			if (i & 1) {
				reverse(v.begin(), v.end());
			}
			p.insert(p.end(), v.begin(), v.end());
		}
		for (int i = n / 6 * 6 + 1; i <= n; i++) {
			p.push_back(i);
		}

		for (int i = 0; i < n; i++) {
			cout << p[i] << " \n"[i + 1 == n];
		}
	}
}

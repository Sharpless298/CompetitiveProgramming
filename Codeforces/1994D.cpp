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

		vector<int> pos(n);
		vector<pair<int, int>> ans;
		iota(pos.begin(), pos.end(), 0);
		for (int i = n - 1; i >= 1; i--) {
			vector<int> b(i, -1);
			for (int j : pos) {
				if (b[a[j] % i] != -1) {
					ans.push_back({j, b[a[j] % i]});
					pos.erase(find(pos.begin(), pos.end(), j));
					break;
				}
				b[a[j] % i] = j;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << "YES\n";
		for (auto [p, q] : ans)
			cout << p + 1 << ' ' << q + 1 << '\n';
	}
}

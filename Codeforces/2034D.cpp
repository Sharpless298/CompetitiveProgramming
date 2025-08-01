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
		int k;
		vector<int> a(n), cnt(3);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
			if (a[i] == 1) k = i;
		}

		vector<pair<int, int>> ans;
		for (int i = 0, j = n - 1; i < cnt[0]; i++) {
			while (j >= cnt[0] && a[j] != 0) j--;
			if (a[i] == 1) {
				swap(a[i], a[j]);
				ans.push_back({i + 1, j + 1});
				k = j;
			} else if (a[i] == 2) {
				swap(a[i], a[k]);
				ans.push_back({i + 1, k + 1});
				swap(a[i], a[j]);
				ans.push_back({i + 1, j + 1});
				k = j;
			}
		}

		for (int i = cnt[0], j = cnt[0] + cnt[1]; i < cnt[0] + cnt[1]; i++) {
			if (a[i] == 1) continue;

			while (j < n && a[j] != 1) j++;
			swap(a[i], a[j]);
			ans.push_back({i + 1, j + 1});
		}

		cout << ans.size() << '\n';
		for (pair<int, int> p : ans)
			cout << p.first << ' ' << p.second << '\n';
	}
}

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
		vector<int> a(n), cnt(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}

		pair<int, int> ans = {-1, -1};
		for (int i = 0, j = 0; i < n; i++) {
			j = i;
			while (j < n && cnt[a[j]] == 1)
				j++;
			if (j - i > ans.second - ans.first)
				ans = {i, j};
			i = j;
		}
		if (ans == make_pair(-1, -1))
			cout << 0 << '\n';
		else
			cout << ans.first + 1 << ' ' << ans.second << '\n';
	}
}

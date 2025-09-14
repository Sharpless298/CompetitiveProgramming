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
		vector<int> cnt(n + 1);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			cnt[x]++;
		}

		vector<int> cnt_cnt(n + 1);
		for (int i = 1; i <= n; i++) {
			cnt_cnt[cnt[i]]++;
		}

		int temp = n;
		while (cnt_cnt[temp] == 0) {
			temp--;
		}

		cout << cnt_cnt[temp] + (n - cnt_cnt[temp] * temp) / (temp - 1) - 1 << '\n';
	}
}

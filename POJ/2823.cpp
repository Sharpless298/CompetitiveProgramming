#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int64_t> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	deque<pair<int, int64_t> > mn, mx;
	vector<pair<int64_t, int64_t> > ans(n - k + 1);
	for (int i = 0; i < n; i++) {
		while (!mn.empty() && mn.front().first <= i - k) {
			mn.pop_front();
		}
		while (!mn.empty() && mn.back().second >= a[i]) {
			mn.pop_back();
		}
		while (!mx.empty() && mx.front().first <= i - k) {
			mx.pop_front();
		}
		while (!mx.empty() && mx.back().second <= a[i]) {
			mx.pop_back();
		}
		mn.push_back(make_pair(i, a[i]));
		mx.push_back(make_pair(i, a[i]));
		if (i >= k - 1) {
			ans[i - k + 1] = make_pair(mn.front().second, mx.front().second);
		}
	}
	for (int i = 0; i < n - k + 1; i++) {
		cout << ans[i].first << " \n"[i + 1 == n - k + 1];
	}
	for (int i = 0; i < n - k + 1; i++) {
		cout << ans[i].second << " \n"[i + 1 == n - k + 1];
	}
}

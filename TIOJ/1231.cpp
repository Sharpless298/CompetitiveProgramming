#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, t, idx = 0, ans = 0;
pair<int, int> p[100005];
priority_queue<int> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	cin >> t;

	sort(p, p + n, cmp);
	while (t) {
		while (idx < n && p[idx].second >= t) {
			pq.push(p[idx].first);
			idx++;
		}
		if (pq.empty()) {
			ans -= t - p[idx].second;
			t = p[idx].second;
		} else {
			ans += pq.top();
			pq.pop();
			t--;
		}
	}

	cout << ans << '\n';
}

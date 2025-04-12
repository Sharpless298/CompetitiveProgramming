#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e6;

pair<int, int> ary[MAXN + 5];
priority_queue<int> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans, n, k, T;

	cin >> T;

	while (T--) {
		ans = 2e9;
		while (!pq.empty())
			pq.pop();

		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> ary[i].first >> ary[i].second;

		sort(ary, ary + n);
		for (int i = 0; i < n; i++) {
			pq.push(ary[i].second);
			if ((int)pq.size() > k)
				pq.pop();
			if ((int)pq.size() == k)
				ans = min(ans, ary[i].first + pq.top());
		}

		cout << ans << '\n';
	}
}

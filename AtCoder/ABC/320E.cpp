#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	set<int> st;
	for (int i = 0; i < n; i++)
		st.insert(i);

	vector<long long> ans(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		int t, w, s;
		cin >> t >> w >> s;

		while (!pq.empty() && pq.top().first <= t) {
			st.insert(pq.top().second);
			pq.pop();
		}
		if (st.empty())
			continue;

		int j = *st.begin();
		st.erase(st.begin());
		ans[j] += w;
		pq.push({t + s, j});
	}

	for (auto i : ans)
		cout << i << '\n';
}

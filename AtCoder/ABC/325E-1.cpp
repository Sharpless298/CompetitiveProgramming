#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<vector<long long>> d(n, vector<long long>(n));
	for (auto &i : d)
		for (auto &j : i)
			cin >> j;

	vector<long long> dist1(n, 0x3fffffffffffffff), dist2(n, 0x3fffffffffffffff);
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>
		pq;
	dist1[0] = 0;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [dd, u] = pq.top();
		pq.pop();

		if (dd != dist1[u])
			continue;

		for (int v = 0; v < n; v++)
			if (dist1[u] + d[u][v] * a < dist1[v])
				dist1[v] = dist1[u] + d[u][v] * a, pq.push({dist1[v], v});
	}
	dist2[n - 1] = 0;
	pq.push({0, n - 1});
	while (!pq.empty()) {
		auto [dd, u] = pq.top();
		pq.pop();

		if (dd != dist2[u])
			continue;

		for (int v = 0; v < n; v++)
			if (dist2[u] + d[u][v] * b + c < dist2[v])
				dist2[v] = dist2[u] + d[u][v] * b + c, pq.push({dist2[v], v});
	}

	long long ans = 0x3fffffffffffffff;
	for (int i = 0; i < n; i++)
		ans = min(ans, dist1[i] + dist2[i]);
	cout << ans << '\n';
}

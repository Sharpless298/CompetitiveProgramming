void Dijkstra() {
	vector<int> dis(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[s] = 0;
	pq.emplace(dis[s], s);

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (dis[u] != d) continue;
		for (auto &[v, w] : G[u])
			if (dis[u] + w < dis[v]) dis[v] = dis[u] + w, pq.emplace(dis[v], v);
	}
}

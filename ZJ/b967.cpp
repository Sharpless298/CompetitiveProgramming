#include <iostream>
#include <vector>
using namespace std;

int ans, k, n;
vector<int> G[100005];

void DFS(int u, int f, int depth) {
	if (depth > ans)
		k = u, ans = depth;

	for (int v : G[u])
		if (v != f)
			DFS(v, u, depth + 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(0, -1, 0);
	DFS(k, -1, 0);

	cout << ans << '\n';
}

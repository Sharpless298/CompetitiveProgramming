#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool f, vis[805];
int n, m, A, B;
vector<int> G[805];

void DFS(int u) {
	if (f)
		return;

	vis[u] = true;
	for (int i : G[u]) {
		if (i == B) {
			f = true;
			return;
		}

		if (!vis[i])
			DFS(i);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> m) {
		f = false;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 805; i++)
			G[i].clear();

		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			G[u].push_back(v);
		}
		cin >> A >> B;
		DFS(A);

		if (f)
			cout << "Yes!!!\n";
		else
			cout << "No!!!\n";
	}
}

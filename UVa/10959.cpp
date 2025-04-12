#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool vis[1005];
int a, b, P, D, number[1005], f;
vector<int> G[1005];

void BFS(int u) {
	int v;
	queue<int> q;

	q.push(u);
	vis[u] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i : G[v]) {
			if (!vis[i]) {
				q.push(i);
				vis[i] = true;
				number[i] = number[v] + 1;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	cin >> t;

	while (t--) {
		if (f++)
			cout << '\n';

		number[0] = 0;
		for (int i = 0; i < 1005; i++)
			G[i].clear();
		memset(vis, 0, sizeof(vis));

		cin >> P >> D;
		for (int i = 0; i < D; i++) {
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		BFS(0);

		for (int i = 1; i < P; i++)
			cout << number[i] << '\n';
	}
}

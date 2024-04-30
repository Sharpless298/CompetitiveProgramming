#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool vis[100005];
int ans, k, n;
vector<int> G[100005];

void DFS(int u, int depth) {
	if(depth > ans) k = u, ans = depth;

	vis[u] = true;
	
	for(int v:G[u])
		if(!vis[v]) DFS(v, depth+1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i=0, u, v; i<n-1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	DFS(0, 0);
	memset(vis, 0, sizeof(vis));
	DFS(k, 0);

	cout << ans << '\n';
}

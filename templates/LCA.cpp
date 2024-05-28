#include <iostream>
using namespace std;

bool ancestor(int u, int v) {
	return in[u]<=in[v] && out[u]>=out[v];
}

void DFS(int u, int f) {
	in[u] = ++t;
	for(int v:G[u])
		if(v != f) DFS(v, u);
	out[u] = t;
}

int LCA(int u, int v) {
	if(ancestor(u, v)) return u;

	for(int i=lgN; i>=0; i--)
		if(!ancestor(ac[u][i], v)) u = ac[u][i];

	return ac[0][u];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	DFS(root);
	ac[0][root] = root;
	lgN = __lg(N);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=lgN; j++)
			ac[i][j] = ac[ac[i][j-1]][j-1];
}

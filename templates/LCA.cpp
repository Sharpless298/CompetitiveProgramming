void DFS(int u, int f) {
	in[u] = ++t;
	for(int &v:G[u]) {
		if(v == f) continue;

		ac[v][0] = u;
		for(int i=1; i<=lgN; i++) 
			ac[v][i] = ac[ac[v][i-1]][i-1];
		DFS(v, u);
	}
	out[u] = ++t;
}

bool ancestor(int u, int v) {
	return in[u]<=in[v] && out[u]>=out[v];
}

int LCA(int u, int v) {
	if(ancestor(u, v)) return u;

	for(int i=lgN; i>=0; i--)
		if(!ancestor(ac[u][i], v)) u = ac[u][i];

	return ac[u][0];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lgN = __lg(N);
	ac[root][0] = root;
	DFS(root);
	/*
	for(int i=1; i<=lgN; i++)
		for(int j=1; j<=N; j++)
			ac[j][i] = ac[ac[j][i-1]][i-1];*/
}

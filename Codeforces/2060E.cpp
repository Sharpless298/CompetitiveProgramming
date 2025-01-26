#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sizes;
void init() {
	iota(parent.begin(), parent.end(), 0);
	fill(sizes.begin(), sizes.end(), 1);
}
int find(int x) {
	return x==parent[x] ? x : parent[x] = find(parent[x]);
}
void unite(int a, int b) {
	a = find(a), b = find(b);

	if(a == b) return;
	
	if(sizes[a] > sizes[b]) swap(a, b);
	parent[a] = b;
	sizes[b] += sizes[a];
}

vector<int> parent1, sizes1;
void init1() {
	iota(parent1.begin(), parent1.end(), 0);
	fill(sizes1.begin(), sizes1.end(), 1);
}
int find1(int x) {
	return x==parent1[x] ? x : parent1[x] = find1(parent1[x]);
}
void unite1(int a, int b) {
	a = find1(a), b = find1(b);

	if(a == b) return;
	
	if(sizes1[a] > sizes1[b]) swap(a, b);
	parent1[a] = b;
	sizes1[b] += sizes1[a];
}

set<pair<int, int>> s;
int ans = 0;
vector<bool> vis;
vector<vector<int>> F;
void DFS(int u) {
	vis[u] = true;
	for(int v : F[u]) {
		if(find(u) != find(v)) {
			s.erase({u, v});
			s.erase({v, u});
			ans++;
		}
		if(vis[v]) continue;
		DFS(v);
	}
}

vector<bool> vis1;
vector<vector<int>> G;
void DFS2(int u) {
	vis1[u] = true;
	for(int v : G[u]) {
		if(find1(u) != find1(v)) {
			unite1(u, v);
			ans++;
		}
		if(vis1[v]) continue;
		DFS2(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		s.clear();
		int n, m1, m2;
		cin >> n >> m1 >> m2;
		F.resize(n);
		for(int i=0; i<n; i++)
			F[i].clear();
		for(int i=0; i<m1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			F[u].push_back(v);
			F[v].push_back(u);
			s.insert({u, v});
			s.insert({v, u});
		}
		parent.resize(n);
		sizes.resize(n);
		init();
		G.resize(n);
		for(int i=0; i<n; i++)
			G[i].clear();
		for(int i=0; i<m2; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			unite(u, v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		ans = 0;
		vis.resize(n);
		fill(vis.begin(), vis.end(), 0);
		for(int i=0; i<n; i++)
			if(!vis[i]) DFS(i);

		parent1.resize(n);
		sizes1.resize(n);
		init1();
		for(auto p : s) 
			unite1(p.first, p.second);
		
		ans /= 2;
		vis1.resize(n);
		fill(vis1.begin(), vis1.end(), 0);
		for(int i=0; i<n; i++)
			if(!vis1[i]) DFS2(i);

		cout << ans << '\n';
	}
}

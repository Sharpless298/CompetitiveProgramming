#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
int conv(int x) {
	return (x<n ? x+n : x-n);
}

void add_clause(int x, int y) {
	G[conv(x)].push_back(y);
	G[conv(y)].push_back(x);
}

int timer = 0, cnt;
vector<bool> f;
vector<int> id, low, scc_id;
stack<int> stk;

void DFS(int u) {
	f[u] = true;
	id[u] = low[u] = ++timer;
	stk.push(u);
	for(int v : G[u]) {
		if(!id[v]) 
			DFS(v), low[u] = min(low[u], low[v]);
		else if(f[v])
			low[u] = min(low[u], id[v]);
	}
	if(id[u] == low[u]) {
		for(int v=-1; v!=u; stk.pop())
			v = stk.top(), f[v] = false, scc_id[v] = cnt;
		cnt++;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		vector a(3, vector<int>(n));
		for(auto &i : a)
			for(auto &j : i) cin >> j;

		G.assign(2*n, vector<int>());
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				for(int k=j+1; k<3; k++) {
					int x = (a[j][i]>0 ? a[j][i]-1 : conv(-a[j][i]-1));
					int y = (a[k][i]>0 ? a[k][i]-1 : conv(-a[k][i]-1));
					add_clause(x, y);
				}
			}
		}

		f.assign(2*n, false), id.assign(2*n, 0), low.assign(2*n, 0), scc_id.assign(2*n, 0);
		for(int i=0; i<2*n; i++)
			if(!id[i]) DFS(i);

		bool ok = true;
		for(int i=0; i<n; i++) 
			if(scc_id[i] == scc_id[i+n]) { ok = false; break; };
		
		cout << (ok ? "YES\n" : "NO\n");
	}
}

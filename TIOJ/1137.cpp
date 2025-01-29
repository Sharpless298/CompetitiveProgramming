#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> D, L, AP;
int timestamp = 1;
void DFS(int u, int p) {
	int cnt = 0;
	D[u] = L[u] = timestamp++;
	bool f = false;
	for(int v : G[u]) {
		if(v == p) continue;
		if(!D[v]) {
			DFS(v, u), cnt++;
			if(D[u] <= L[v]) f = true;
			L[u] = min(L[u], L[v]);
		}
		L[u] = min(L[u], D[v]);
	}
	if(u==p && cnt<2) f = false;
	if(f) AP.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		G.assign(n, vector<int>());
		for(int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		AP.clear();
		D.assign(n, 0), L.assign(n, 0);
		DFS(0, 0);
		
		cout << AP.size() << '\n';
		if(AP.empty()) 
			cout << 0 << '\n';
		else {
			sort(AP.begin(), AP.end());
			for(int i : AP) cout << i+1 << ' ';
			cout << '\n';
		}
	}
}

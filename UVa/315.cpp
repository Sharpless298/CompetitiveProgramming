#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> L, D;

int timestamp = 1, ans;
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
	if(f) ans++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while(cin>>n && n) {
		G.assign(n, vector<int>());

		string s;
		while(getline(cin, s)) {
			if(s == "0") break;
			stringstream ss(s);
			int u;
			ss >> u;
			u--;
			int v;
			while(ss >> v) {
				v--;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		ans = 0;
		D.assign(n, 0), L.assign(n, 0);
		DFS(0, 0);
		
		cout << ans << '\n';
	}
}

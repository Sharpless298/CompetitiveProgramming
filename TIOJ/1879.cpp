#include <bits/stdc++.h>
using namespace std;

int timestamp = 1;
vector<int> D, L, E;
vector<vector<int>> G, bcc;
stack<int> stk;
void DFS(int u, int p) {
	D[u] = L[u] = timestamp++;
	stk.push(u);

	for(int idx : G[u]) {
		int v = E[idx];
		if(!D[v]) {
			DFS(v, idx^1);
			L[u] = min(L[u], L[v]);
		}
		else if(idx != p) L[u] = min(L[u], D[v]);
	}
	
	if(D[u] == L[u]) {
		vector<int> a;
		while(stk.top() != u) {
			a.push_back(stk.top());
			stk.pop();
		}
		a.push_back(stk.top()); stk.pop();
		bcc.push_back(a);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	G.assign(n, vector<int>());
	set<pair<int, int>> st;
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back((int)E.size());
		E.push_back(v);
		G[v].push_back((int)E.size());
		E.push_back(u);
	}

	D.assign(n, 0), L.assign(n, 0);

	DFS(0, -1);
	for(auto &i : bcc) sort(i.begin(), i.end());
	sort(bcc.begin(), bcc.end());

	for(int i=0; i<(int)bcc.size(); i++) {
		cout << i+1 << ':';
		for(auto j : bcc[i]) cout << ' ' << j;
		cout << '\n';
	}
}

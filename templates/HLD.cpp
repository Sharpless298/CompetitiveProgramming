#include <iostream>
using namespace std;

int DFS(int u, int p) {
	sz[u] = 1;
	parent[u] = p;
	for (int v : G[u]) {
		if (v == p) {
			continue;
		}
		sz[u] += DFS(v);
	}
	return sz[u];
}

int cnt = 0;
void HLD(int u, int p, int t) {
	id[u] = cnt++;
	top[u] = t;
	// update();
	int h_child = -1, h_sz = -1;
	for (int v : G[u]) {
		if (v == p) {
			continue;
		}
		if (h_sz < sz[v]) {
			h_sz = sz[v];
			h_child = v;
		}
	}
	if (h_child == -1) {
		return;
	}

	DFS(h_child, u, t);
	for (int v : G[u]) {
		if (v == p || v == h_child) {
			continue;
		}
		HLD(v, u, v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
}

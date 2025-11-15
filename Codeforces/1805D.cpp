#include <bits/stdc++.h>
using namespace std;

vector<int> d;
vector<vector<int>> G, ac;
int lgN, t;
vector<int> in, out;

void DFS(int u, int p) {
	for (int v : G[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			DFS(v, u);
		}
	}
}

void build(int u, int f) {
	in[u] = t++;
	for (int &v : G[u]) {
		if (v == f) {
			continue;
		}

		ac[v][0] = u;
		for (int i = 1; i <= lgN; i++) {
			ac[v][i] = ac[ac[v][i - 1]][i - 1];
		}
		build(v, u);
	}
	out[u] = t;
}

bool ancestor(int u, int v) {
	return in[u] <= in[v] && out[u] >= out[v];
}

int LCA(int u, int v) {
	if (ancestor(u, v)) {
		return u;
	}

	for (int i = lgN; i >= 0; i--) {
		if (!ancestor(ac[u][i], v)) {
			u = ac[u][i];
		}
	}

	return ac[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	G.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	d.assign(n, 0);
	d[0] = 0;
	DFS(0, -1);
	int x = (int)(max_element(d.begin(), d.end()) - d.begin());
	d[x] = 0;
	DFS(x, -1);
	int y = (int)(max_element(d.begin(), d.end()) - d.begin());

	d[0] = 0;
	DFS(0, -1);

	lgN = __lg(n);
	in.resize(n);
	out.resize(n);
	ac.resize(n, vector<int>(lgN + 1));
	ac[0][0] = 0;
	build(0, -1);

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = d[i] + max(d[x] - 2 * d[LCA(i, x)], d[y] - 2 * d[LCA(i, y)]);
	}

	sort(v.begin(), v.end());
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && v[j] < i + 1) {
			j++;
		}
		cout << (j == n ? n : j + 1) << " \n"[i + 1 == n];
	}
}

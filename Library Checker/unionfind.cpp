#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
using namespace std;

vector<int> parent(200000), sz(200000);

void init() {
	iota(parent.begin(), parent.end(), 0);
	fill(sz.begin(), sz.end(), 1);
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if(a == b) return;
	
	if(sz[a] > sz[b]) swap(a, b);
	parent[a] = b;
	sz[b] += sz[a];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n, q;
	cin >> n >> q;
	while(q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 0) 
			Union(u, v);
		else
			cout << (Find(u)==Find(v) ? 1 : 0) << '\n';
	}
}


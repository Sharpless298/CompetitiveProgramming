#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

bool c[200005];
int parent[200005];
vector<int> v[200005];

void init(int n) {
	iota(parent, parent+n, 0);
	for(int i=0; i<n; i++) v[i].push_back(i);
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	bool k = c[a] ^ c[b] ^ 1;
	a = Find(a), b = Find(b);

	if(v[a].size() > v[b].size()) swap(a, b);
	if(k) for(int i:v[b]) c[i] ^= 1;
	for(int i:v[b]) v[a].push_back(i);
	parent[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, shift = 0, t, x, y;
	
	cin >> n >> m;
	init(n);
	while(m--) {
		cin >> t >> x >> y;
		x = (x+shift)%n, y = (y+shift)%n;
		
		if(t == 0) 
			Union(x, y);
		else {
			if(c[x] == c[y]) cout << "YES\n", shift++;
			else cout << "NO\n";
		}
	}
}

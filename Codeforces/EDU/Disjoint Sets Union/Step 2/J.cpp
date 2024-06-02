#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

bool c[300005];
int parent[300005], rk[300005];
vector<int> v[300005];

void init(int n) {
	iota(parent, parent+n+1, 0);
	memset(rk, 0, sizeof(int)*n);
	for(int i=1; i<=n; i++) v[i].push_back(i);
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	bool k = c[a] ^ c[b] ^ 1;
	a = Find(a), b = Find(b);

	if(a == b) return;
	
	if(v[a].size() < v[b].size()) swap(a, b);
	if(k) for(int i:v[b]) c[i] ^= 1;
	for(int i:v[b]) v[a].push_back(i);
	parent[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans = -1;

	cin >> n >> m;

	init(n);
	for(int i=0, a, b; i<m; i++) {
	 	cin >> a >> b;
		
		if(Find(a)==Find(b) && c[a]==c[b]) {
			ans = i+1;
			break;
		}
	
		Union(a, b);		
	}

	cout << ans << '\n';
}

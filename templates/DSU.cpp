#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int parent[200005], sz[200005];

void init(int n) {
	iota(parent, parent+n+1, 0);
	fill(sz, sz+n+1, 1);
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

}

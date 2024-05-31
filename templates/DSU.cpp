#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int parent[200005], rk[200005];

void init(int n) {
	iota(parent, parent+n+1, 0);
	memset(rk, 0, sizeof(rk));
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);

	if(a == b) return;
	
	if(rk[a] < rk[b]) swap(a, b);
	if(rk[a] == rk[b]) rk[a]++;
	parent[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}

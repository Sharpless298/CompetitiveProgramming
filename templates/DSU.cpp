#include <iostream>
using namespace std;

int parent[200005], rk[200005];

void init(int n) {
	for(int i=1; i<=n; i++)
		parent[i] = i, rk[i] = 1;
}

int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a), b = find(b);

	if(a == b) return;
	
	if(rk[a] < rk[b]) swap(a, b);
	parent[b] = a;
	if(rk[a] == rk[b]) rk[a]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}

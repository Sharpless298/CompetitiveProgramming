#include <iostream>
using namespace std;

void init(int n) {
	for(int i=1; i<=n; i++)
		parent[i] = i, rk[i] = 1;
}

int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = query(a), b = query(b);

	if(a == b) return;
	if(rk[a] < rk[b]) parent[a] = b;
	else if(rk[a] > rk[a]) parent[b] = a;
	else parent[a] = b, rk[b]++;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}

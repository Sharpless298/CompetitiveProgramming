#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> parent(200000), sizes(200000);

void init() {
	iota(parent.begin(), parent.end(), 0);
	fill(sizes.begin(), sizes.end(), 1);
}

int find(int x) {
	return x==parent[x] ? x : parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a), b = find(b);

	if(a == b) return;
	
	if(sizes[a] > sizes[b]) swap(a, b);
	parent[a] = b;
	sizes[b] += sizes[a];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}

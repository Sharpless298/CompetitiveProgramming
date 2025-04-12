#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool c[200005];
int parent[200005], sz[200005];

void init(int n) {
	iota(parent, parent + n + 1, 0);
	fill(sz, sz + n + 1, 1);
}

int Find(int x) {
	if (parent[x] == x)
		return x;

	int root = Find(parent[x]);
	c[x] ^= c[parent[x]];
	return parent[x] = root;
}

void Union(int a, int b) {
	int fa = Find(a), fb = Find(b);

	if (sz[fa] < sz[fb])
		swap(fa, fb);
	parent[fa] = fb;
	c[fa] = c[a] ^ c[b] ^ 1;
	sz[fb] += sz[fa];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, shift = 0, t, x, y;

	cin >> n >> m;
	init(n);
	while (m--) {
		cin >> t >> x >> y;
		x = (x + shift) % n, y = (y + shift) % n;

		if (t == 0)
			Union(x, y);
		else {
			Find(x), Find(y);
			if (c[x] == c[y])
				cout << "YES\n", shift++;
			else
				cout << "NO\n";
		}
	}
}

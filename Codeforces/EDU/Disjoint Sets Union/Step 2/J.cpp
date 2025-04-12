#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool c[300005];
int parent[300005], sz[300005];

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

	int n, m, a, b, ans;

	ans = 0;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		if (Find(a) == Find(b) && c[a] == c[b]) {
			ans = i + 1;
			break;
		}

		Union(a, b);
	}

	if (ans)
		cout << ans << '\n';
	else
		cout << -1 << '\n';
}

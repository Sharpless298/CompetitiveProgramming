#include <iostream>
#include <numeric>
using namespace std;

int parent[300005], depth[300005];

int Find(int x) {
	if (x == parent[x])
		return x;

	int root = Find(parent[x]);
	depth[x] += depth[parent[x]];
	return parent[x] = root;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t, a, b;

	cin >> n >> m;

	iota(parent, parent + n + 1, 0);

	while (m--) {
		cin >> t;

		if (t == 1) {
			cin >> a >> b;
			parent[a] = b;
			depth[a]++;
		} else {
			cin >> a;
			Find(a);
			cout << depth[a] << '\n';
		}
	}
}

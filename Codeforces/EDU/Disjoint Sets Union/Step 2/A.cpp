#include <iostream>
using namespace std;

int parent[1000005];

int Find(int x) {
	if (x == -1)
		return -1;
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char c;
	int n, m, k;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;
	parent[n + 1] = -1;

	while (m--) {
		cin >> c >> k;

		if (c == '-')
			parent[k] = Find(k + 1);
		else
			cout << Find(k) << '\n';
	}
}

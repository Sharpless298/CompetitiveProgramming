#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> a(n + 1, vector<bool>(n + 1)), b(n + 1, vector<bool>(n + 1));
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		a[u][v] = a[v][u] = true;
	}
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		b[u][v] = b[v][u] = true;
	}

	vector<int> P;
	for (int i = 0; i < n; i++)
		P.push_back(i);

	do {
		bool f = true;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (a[i][j] != b[P[i]][P[j]])
					f = false;

		if (f) {
			cout << "Yes\n";
			return 0;
		}
	} while (next_permutation(P.begin(), P.end()));

	cout << "No\n";
}

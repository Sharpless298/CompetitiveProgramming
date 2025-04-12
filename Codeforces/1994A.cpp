#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, m;

	cin >> T;
	while (T--) {
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (auto &i : a)
			for (auto &j : i)
				cin >> j;

		if (n * m == 1)
			cout << "-1\n";
		else {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					cout << a[(i + 1) % n][(j + 1) % m] << " \n"[j + 1 == m];
		}
	}
}

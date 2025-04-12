#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<vector<char>> G(n, vector<char>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> G[i][j];
		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < n; j += k)
				cout << G[i][j];
			cout << '\n';
		}
	}
}

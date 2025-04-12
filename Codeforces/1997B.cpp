#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> G(2);
		for (auto &s : G)
			cin >> s;

		int ans = 0;
		for (int i = 1; i < n - 1; i++) {
			if (G[0][i] == 'x')
				continue;

			if (G[0][i - 1] == '.' && G[0][i + 1] == '.' && G[1][i - 1] == 'x' && G[1][i] == '.' && G[1][i + 1] == 'x')
				ans++;
		}
		for (int i = 1; i < n - 1; i++) {
			if (G[1][i] == 'x')
				continue;

			if (G[1][i - 1] == '.' && G[1][i + 1] == '.' && G[0][i - 1] == 'x' && G[0][i] == '.' && G[0][i + 1] == 'x')
				ans++;
		}
		cout << ans << '\n';
	}
}

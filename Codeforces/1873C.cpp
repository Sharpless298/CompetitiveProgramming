#include <iostream>
using namespace std;

int G[16][16] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
	{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
	{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
	{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
	{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
	{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char c;
	int t, ans;

	cin >> t;

	while (t--) {
		ans = 0;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> c;
				if (c == 'X')
					ans += G[i][j];
			}
		}

		cout << ans << '\n';
	}
}

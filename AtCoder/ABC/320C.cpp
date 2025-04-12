#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1e7 + 5;

string s[3];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, ans = INF;

	cin >> M;
	for (int i = 0; i < 3; i++)
		cin >> s[i];

	for (int i = 0; i < 3 * M; i++) {
		for (int j = 0; j < 3 * M; j++) {
			for (int k = 0; k < 3 * M; k++) {
				if (i == j || j == k || k == i)
					continue;
				if (s[0][i % M] == s[1][j % M] && s[1][j % M] == s[2][k % M] && s[2][k % M] == s[0][i % M])
					ans = min(ans, max({i, j, k}));
			}
		}
	}

	if (ans == INF)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}

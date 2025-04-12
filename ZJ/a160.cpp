#include <iostream>
using namespace std;

bool p[32], q[32], c[32];
char G[32][32];
int n, ans;

void DFS(int depth) {
	if (depth == n) {
		ans++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << G[i][j];
			cout << '\n';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!p[i + depth] && !q[i - depth + n] && !c[i]) {
			G[depth][i] = 'Q';
			p[i + depth] = q[i - depth + n] = c[i] = true;
			DFS(depth + 1);
			G[depth][i] = 'x';
			p[i + depth] = q[i - depth + n] = c[i] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n && n) {
		ans = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				G[i][j] = 'x';

		DFS(0);

		cout << ans << "\n\n";
	}
}

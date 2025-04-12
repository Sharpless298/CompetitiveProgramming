#include <iomanip>
#include <iostream>
using namespace std;

bool p[32], q[32], c[32];
int ans;
int G[16][16];
int path[16];

void DFS(int depth) {
	if (depth == 8) {
		int t = 0;
		for (int i = 0; i < 8; i++) {
			t += G[i][path[i]];
			ans = max(ans, t);
		}
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (!c[i] && !p[depth - i + 8] && !q[depth + i]) {
			c[i] = p[depth - i + 8] = q[depth + i] = true;
			path[depth] = i;
			DFS(depth + 1);
			c[i] = p[depth - i + 8] = q[depth + i] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	while (k--) {
		ans = 0;
		for (int i = 0; i < 32; i++)
			c[i] = p[i] = q[i];

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> G[i][j];

		DFS(0);

		cout << setw(5) << ans << '\n';
	}
}

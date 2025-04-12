#include <iostream>
#include <vector>
using namespace std;

int ans;
vector<vector<bool>> reserved(8, vector<bool>(8));
vector<bool> p(16), m(16), q(16);

void DFS(int depth) {
	if (depth == 8) {
		ans++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (reserved[depth][i] || p[depth + i] || m[i] || q[depth - i + 8])
			continue;

		p[depth + i] = m[i] = q[depth - i + 8] = true;
		DFS(depth + 1);
		p[depth + i] = m[i] = q[depth - i + 8] = false;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<char>> G(8, vector<char>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> G[i][j];
			if (G[i][j] == '*')
				reserved[i][j] = true;
		}
	}

	DFS(0);

	cout << ans << '\n';
}

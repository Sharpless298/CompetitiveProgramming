#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[512][512];
int ans1, ans2, M, N;
string G[512];

bool check(int r, int c) {
	if (r >= 0 && r < M && c >= 0 && c < N && G[r][c] == 'J' && !vis[r][c])
		return true;
	return false;
}

int BFS(int r, int c) {
	int cnt;
	pair<int, int> cur, nxt;
	queue<pair<int, int>> q;

	vis[r][c] = true;
	cnt = 1;
	q.push({r, c});

	while (!q.empty()) {
		cur = q.front(), q.pop();

		for (int i = 0; i < 4; i++) {
			nxt = cur;
			nxt.first += dy[i];
			nxt.second += dx[i];

			if (check(nxt.first, nxt.second)) {
				vis[nxt.first][nxt.second] = true;
				cnt++;
				q.push(nxt);
			}
		}
	}

	return cnt;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> M >> N) {
		ans1 = ans2 = 0;
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < M; i++)
			cin >> G[i];

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (G[i][j] == 'J' && !vis[i][j])
					ans1++, ans2 = max(BFS(i, j), ans2);

		cout << ans1 << ' ' << ans2 << '\n';
	}
}

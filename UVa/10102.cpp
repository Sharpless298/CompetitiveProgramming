#include <cstring>
#include <iostream>
using namespace std;

struct node {
	int x, y;
	int dis;
};

char G[128][128];
bool vis[128][128];
int M, S, ans;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
node q[10005], start[10005];

bool check(int a, int b) {
	if (a >= 0 && a < M && b >= 0 && b < M && !vis[a][b])
		return true;
	return false;
}

int BFS(int id) {
	node cur, nxt;

	memset(vis, 0, sizeof(vis));

	q[0] = start[id];
	vis[q[0].y][q[0].x] = true;

	for (int i = 0, j = 1; i < j; i++) {
		cur = q[i];

		if (G[cur.y][cur.x] == '3')
			return cur.dis;

		for (int k = 0; k < 4; k++) {
			nxt = cur;
			nxt.x += dx[k];
			nxt.y += dy[k];
			nxt.dis++;

			if (check(nxt.y, nxt.x)) {
				vis[nxt.y][nxt.x] = true;
				q[j] = nxt;
				j++;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> M) {
		S = 0;
		ans = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				cin >> G[i][j];
				if (G[i][j] == '1') {
					start[S].x = j;
					start[S].y = i;
					start[S].dis = 0;
					S++;
				}
			}
		}

		for (int i = 0; i < S; i++)
			ans = max(ans, BFS(i));

		cout << ans << '\n';
	}
}

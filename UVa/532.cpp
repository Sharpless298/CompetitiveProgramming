#include <cstring>
#include <iostream>
using namespace std;

struct node {
	int x, y, z;
	int dis;
};

bool vis[64][64][64];
char G[64][64][64];
int L, R, C, stx, sty, stz;
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
node E;
node q[30000];

bool check(int a, int b, int c) {
	if (a >= 0 && a < L && b >= 0 && b < R && c >= 0 && c < C && G[a][b][c] != '#' && !vis[a][b][c])
		return true;
	return false;
}

int BFS() {
	node cur, nxt;

	q[0].x = stx;
	q[0].y = sty;
	q[0].z = stz;
	q[0].dis = 0;
	vis[stz][sty][stx] = true;

	for (int i = 0, j = 1; i < j; i++) {
		cur = q[i];

		if (cur.x == E.x && cur.y == E.y && cur.z == E.z)
			return cur.dis;

		for (int k = 0; k < 6; k++) {
			nxt = cur;
			nxt.x += dx[k];
			nxt.y += dy[k];
			nxt.z += dz[k];
			nxt.dis++;
			if (check(nxt.z, nxt.y, nxt.x)) {
				vis[nxt.z][nxt.y][nxt.x] = true;
				q[j] = nxt;
				j++;
			}
		}
	}
	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans;

	while (cin >> L >> R >> C && L) {
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> G[i][j][k];
					if (G[i][j][k] == 'S') {
						stz = i;
						sty = j;
						stx = k;
					}
					if (G[i][j][k] == 'E') {
						E.z = i;
						E.y = j;
						E.x = k;
					}
				}
			}
		}
		ans = BFS();

		if (ans != -1)
			cout << "Escaped in " << ans << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
}

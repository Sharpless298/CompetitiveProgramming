#include <cstring>
#include <iostream>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[128][128][64];
char G[128][128];
int x, y, nx, ny, key, nkey, res, sx, sy, R, C;
int key_id[64];
int q[10005][3];
int dis[128][128][64];
string keys = "RGBY";

int BFS() {
	q[0][0] = sy;
	q[0][1] = sx;
	q[0][2] = 0;
	dis[sy][sx][0] = 0;
	vis[sy][sx][0] = true;

	for (int i = 0, j = 1; i < j; i++) {
		x = q[i][1];
		y = q[i][0];
		key = q[i][2];

		if (G[y][x] == 'X')
			return dis[y][x][key];

		for (int k = 0; k < 4; k++) {
			nx = x + dx[k];
			ny = y + dy[k];
			nkey = key;

			if (ny < 0 || ny >= R || nx < 0 || nx >= C || G[ny][nx] == '#')
				continue;
			if (G[ny][nx] == 'R' || G[ny][nx] == 'G' || G[ny][nx] == 'B' || G[ny][nx] == 'Y')
				if ((key & (1 << key_id[G[ny][nx] - 'A'])) == 0)
					continue;
			if (G[ny][nx] == 'r' || G[ny][nx] == 'g' || G[ny][nx] == 'b' || G[ny][nx] == 'y')
				nkey = (key | (1 << (key_id[G[ny][nx] - 'a'])));

			if (!vis[ny][nx][nkey]) {
				vis[ny][nx][nkey] = true;
				q[j][0] = ny;
				q[j][1] = nx;
				q[j][2] = nkey;
				dis[ny][nx][nkey] = dis[y][x][key] + 1;
				j++;
			}
		}
	}

	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < (int)keys.size(); i++)
		key_id[(int)(keys[i] - 'A')] = i;

	while (cin >> R >> C) {
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> G[i][j];
				if (G[i][j] == '*') {
					sx = j;
					sy = i;
				}
			}
		}
	}

	res = BFS();

	if (res == -1)
		cout << "The poor student is trapped!\n";
	else
		cout << "Escape possible in " << res << " steps.\n";
}

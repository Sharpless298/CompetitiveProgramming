#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct node {
	int y, x, dis;
};

bool vis[128][128];
char G[128][128];
int dx[] = {1, -1, -3, -3, -1, 1, 3, 3};
int dy[] = {3, 3, 1, -1, -3, -3, -1, 1};
int dx2[] = {0, -1, 0, 1};
int dy2[] = {1, 0, -1, 0};

bool check1(node a, int b) {
	if (a.x + dx2[b] >= 0 && a.x + dx2[b] < 100 && a.y + dy2[b] >= 0 && a.y + dy2[b] < 100)
		if (G[a.y + dy2[b]][a.x + dx2[b]] != '#')
			return true;
	return false;
}

bool check2(node a) {
	if (a.x >= 0 && a.x < 100 && a.y >= 0 && a.y < 100 && G[a.y][a.x] != '#' && !vis[a.y][a.x])
		return true;
	return false;
}

int BFS(node S, node E) {
	node cur, nxt;
	queue<node> q;

	q.push(S);
	vis[S.y][S.x] = true;

	while (!q.empty()) {
		cur = q.front(), q.pop();

		if (cur.y == E.y && cur.x == E.x)
			return cur.dis;

		for (int i = 0; i < 8; i++) {
			nxt = cur;
			if (!check1(cur, i / 2))
				continue;
			nxt.x += dx[i];
			nxt.y += dy[i];
			nxt.dis++;

			if (check2(nxt)) {
				q.push(nxt);
				vis[nxt.y][nxt.x] = true;
			}
		}
	}

	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, sy, sx, ey, ex, res;

	cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> y >> x;
		G[y][x] = '#';
	}
	cin >> sy >> sx;
	cin >> ey >> ex;

	res = BFS({sy, sx, 0}, {ey, ex, 0});

	if (res != -1)
		cout << res << '\n';
	else
		cout << "impossible\n";
}

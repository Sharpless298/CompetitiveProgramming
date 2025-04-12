#include <iostream>
using namespace std;

struct node {
	int x, y;
};

bool vis[1005][1005];
int N, M, edx, edy, F;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
node q[1000005];

bool check(int a, int b) {
	if (a >= 1 && a <= N && b >= 1 && b <= M && !vis[a][b])
		return true;
	return false;
}

bool BFS() {
	node cur, nxt;

	vis[q[0].x][q[0].y] = true;

	for (int i = 0, j = 1; i < j; i++) {
		cur = q[i];

		if (cur.x == edx && cur.y == edy)
			return true;

		for (int k = 0; k < 4; k++) {
			nxt = cur;
			nxt.x += dx[k];
			nxt.y += dy[k];

			if (check(nxt.x, nxt.y)) {
				vis[nxt.x][nxt.y] = true;
				q[j] = nxt;
				j++;
			}
		}
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cin >> q[0].x >> q[0].y;
	cin >> edx >> edy;
	cin >> F;
	for (int i = 0, a, b; i < F; i++) {
		cin >> a >> b;
		vis[a][b] = true;
	}

	if (BFS())
		cout << "Cool!\n";
	else
		cout << "Harakiri!\n";
}

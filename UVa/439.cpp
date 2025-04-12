#include <cstring>
#include <iostream>
using namespace std;

struct node {
	int x, y;
	int dis;
};

bool vis[16][16];
int stx, sty, edx, edy;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
string s;
node q[128];

bool check(int a, int b) {
	if (a >= 0 && a < 8 && b >= 0 && b < 8 && !vis[a][b])
		return true;
	return false;
}

int BFS() {
	node cur, nxt;

	q[0].x = stx;
	q[0].y = sty;
	q[0].dis = 0;
	vis[stx][sty] = true;

	for (int i = 0, j = 1; i < j; i++) {
		cur = q[i];

		if (cur.x == edx && cur.y == edy)
			return cur.dis;

		for (int k = 0; k < 8; k++) {
			nxt = cur;
			nxt.x += dx[k];
			nxt.y += dy[k];
			nxt.dis++;
			if (check(nxt.x, nxt.y)) {
				vis[nxt.x][nxt.y] = true;
				q[j] = nxt;
				j++;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (getline(cin, s)) {
		memset(vis, 0, sizeof(vis));

		stx = s[0] - 'a';
		sty = s[1] - '1';
		edx = s[3] - 'a';
		edy = s[4] - '1';

		cout << "To get from " << s[0] << s[1] << " to " << s[3] << s[4] << " takes " << BFS() << " knight moves.\n";
	}
}

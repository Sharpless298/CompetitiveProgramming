#include <iostream>
using namespace std;

struct node {
	int a, b;
};

bool s[16][16], r[16][128], c[16][128], block[16][128], f;
char t;
char id[16] = {'R', 'O', 'Y', 'G', 'B', 'I', 'P', 'L', 'W'};
char G[16][16];
int n;
node ary[128];

int check(int a, int b) {
	a /= 3;
	b /= 3;
	return a * 3 + b;
}

void DFS(int depth) {
	if (depth == n) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				if (s[i][j])
					cout << G[i][j];
			cout << '\n';
		}
		f = true;
		return;
	}

	int p = ary[depth].a;
	int q = ary[depth].b;
	for (int j = 0; j < 9; j++) {
		char t = id[j];
		if (!f && !r[p][t] && !c[q][t] && !block[check(p, q)][t]) {
			G[p][q] = id[j];
			r[p][t] = c[q][t] = block[check(p, q)][t] = true;
			DFS(depth + 1);
			G[p][q] = '*';
			r[p][t] = c[q][t] = block[check(p, q)][t] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> G[i][j];
			if (G[i][j] != '*')
				r[i][G[i][j]] = c[j][G[i][j]] = block[check(i, j)][G[i][j]] = true;
			else {
				s[i][j] = true;
				ary[n].a = i;
				ary[n].b = j;
				n++;
			}
		}
	}
	DFS(0);
}

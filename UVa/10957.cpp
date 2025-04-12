#include <iostream>
using namespace std;

struct node {
	int x, y;
};

bool r[16][16], c[16][16], block[16][16];
int id = 1, n, res;
int G[16][16];
node ary[128];

int check(int a, int b) {
	a /= 3;
	b /= 3;
	return a * 3 + b;
}

void DFS(int depth) {
	if (depth == n) {
		res++;
		return;
	}

	int p = ary[depth].x, q = ary[depth].y;
	for (int i = 1; i <= 9; i++) {
		if (res == 2)
			return;

		if (!r[p][i] && !c[q][i] && !block[check(p, q)][i]) {
			r[p][i] = c[q][i] = block[check(p, q)][i] = true;
			DFS(depth + 1);
			r[p][i] = c[q][i] = block[check(p, q)][i] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> G[0][0]) {
		n = 0;
		res = 0;
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 16; j++)
				r[i][j] = c[i][j] = block[i][j] = false;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!(i == 0 && j == 0))
					cin >> G[i][j];

				if (G[i][j] != 0) {
					if (r[i][G[i][j]] || c[j][G[i][j]] || block[check(i, j)][G[i][j]])
						res = -1;
					r[i][G[i][j]] = c[j][G[i][j]] = block[check(i, j)][G[i][j]] = true;
				} else {
					ary[n].x = i;
					ary[n].y = j;
					n++;
				}
			}
		}

		cout << "Case " << id++ << ": ";
		if (res == -1)
			cout << "Illegal.\n";
		else {
			DFS(0);
			if (res == 2)
				cout << "Ambiguous.\n";
			else if (res == 1)
				cout << "Unique.\n";
			else
				cout << "Impossible.\n";
		}
	}
}

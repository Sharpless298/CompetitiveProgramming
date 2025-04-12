#include <cstring>
#include <iostream>
using namespace std;

struct node {
	int a, b;
	int step;
	int prev;
};

bool vis[1005][1005];
int Ca, Cb, N;
string steps[7] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A", "success"};
node q[1000005];

void trace(int idx) {
	if (q[idx].prev != -1)
		trace(q[idx].prev);
	if (q[idx].step != -1)
		cout << steps[q[idx].step] << '\n';
}

int BFS() {
	q[0].a = q[0].b = 0;
	q[0].step = -1;
	q[0].prev = -1;
	vis[0][0] = true;

	for (int i = 0, j = 1;; i++) {
		if (q[i].a == N || q[i].b == N)
			return i;

		if (q[i].a < Ca && !vis[Ca][q[i].b]) {
			vis[Ca][q[i].b] = true;
			q[j].a = Ca;
			q[j].b = q[i].b;
			q[j].step = 0;
			q[j].prev = i;
			j++;
		}
		if (q[i].b < Cb && !vis[q[i].a][Cb]) {
			vis[q[i].a][Cb] = true;
			q[j].a = q[i].a;
			q[j].b = Cb;
			q[j].step = 1;
			q[j].prev = i;
			j++;
		}
		if (q[i].a != 0 && !vis[0][q[i].b]) {
			vis[0][q[i].b] = true;
			q[j].a = 0;
			q[j].b = q[i].b;
			q[j].step = 2;
			q[j].prev = i;
			j++;
		}
		if (q[i].b != 0 && !vis[q[i].a][0]) {
			vis[q[i].a][0] = true;
			q[j].a = q[i].a;
			q[j].b = 0;
			q[j].step = 3;
			q[j].prev = i;
			j++;
		}
		if (q[i].a != 0) {
			if (q[i].a + q[i].b <= Cb) {
				if (!vis[0][q[i].a + q[i].b]) {
					vis[0][q[i].a + q[i].b] = true;
					q[j].a = 0;
					q[j].b = q[i].a + q[i].b;
					q[j].step = 4;
					q[j].prev = i;
					j++;
				}
			} else {
				if (!vis[q[i].a - Cb + q[i].b][Cb]) {
					vis[q[i].a - Cb + q[i].b][Cb] = true;
					q[j].a = q[i].a - Cb + q[i].b;
					q[j].b = Cb;
					q[j].step = 4;
					q[j].prev = i;
					j++;
				}
			}
		}
		if (q[i].b != 0) {
			if (q[i].a + q[i].b <= Ca) {
				if (!vis[q[i].a + q[i].b][0]) {
					vis[q[i].a + q[i].b][0] = true;
					q[j].a = q[i].a + q[i].b;
					q[j].b = 0;
					q[j].step = 5;
					q[j].prev = i;
					j++;
				}
			} else {
				if (!vis[Ca][q[i].b - Ca + q[i].a]) {
					vis[Ca][q[i].b - Ca + q[i].a] = true;
					q[j].a = Ca;
					q[j].b = q[i].b - Ca + q[i].a;
					q[j].step = 5;
					q[j].prev = i;
					j++;
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> Ca >> Cb >> N) {
		memset(vis, 0, sizeof(vis));

		trace(BFS());
		cout << steps[6] << '\n';
	}
}

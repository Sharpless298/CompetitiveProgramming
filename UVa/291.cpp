#include <iostream>
using namespace std;

bool edge[8][8];
int path[16];

void DFS(int depth) {
	if (depth == 9) {
		for (int i = 0; i < 9; i++)
			cout << path[i];
		cout << '\n';
		return;
	}

	for (int i = 1; i <= 5; i++) {
		int prev = path[depth - 1];

		if (prev != i && edge[i][prev]) {
			edge[i][prev] = edge[prev][i] = false;
			path[depth] = i;
			DFS(depth + 1);
			edge[i][prev] = edge[prev][i] = true;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	edge[1][2] = edge[1][3] = edge[1][5] = true;
	edge[2][1] = edge[2][3] = edge[2][5] = true;
	edge[3][1] = edge[3][2] = edge[3][4] = edge[3][5] = true;
	edge[4][3] = edge[4][5] = true;
	edge[5][1] = edge[5][2] = edge[5][3] = edge[5][4] = true;
	path[0] = 1;

	DFS(1);
}

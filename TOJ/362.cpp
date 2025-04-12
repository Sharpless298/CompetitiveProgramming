#include <iostream>
using namespace std;

bool f;
int ary[8][32];
int p[8];

void DFS(int depth) {
	if (depth == 26) {
		f = true;
		return;
	}

	for (int i = 0; !f && i < 3; i++) {
		for (int j = i + 1; !f && j < 4; j++) {
			if (p[i] == 13 || p[j] == 13)
				continue;

			if (ary[i][p[i]] == ary[j][p[j]]) {
				p[i]++;
				p[j]++;
				DFS(depth + 1);
				p[i]--;
				p[j]--;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			cin >> ary[i][j];

	DFS(0);

	if (f)
		cout << "YES\n";
	else
		cout << "NO\n";
}

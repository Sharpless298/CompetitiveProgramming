#include <iostream>
using namespace std;

bool f, vis[32];
int n;
int ary[32], res[8];

void DFS(int depth, int id) {
	if (depth == 6) {
		cout << res[0];
		for (int i = 1; i < 6; i++)
			cout << ' ' << res[i];
		cout << '\n';
		return;
	}

	for (int i = id; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			res[depth] = ary[i];
			DFS(depth + 1, i + 1);
			vis[i] = false;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> n && n) {
		if (f)
			cout << '\n';
		f = true;

		for (int i = 0; i < n; i++)
			cin >> ary[i];

		DFS(0, 0);
	}
}

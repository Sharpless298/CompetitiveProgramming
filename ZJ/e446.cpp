#include <iostream>
using namespace std;

bool vis[16];
int n, path[16];
string ans;

void DFS(int depth) {
	if (depth == n) {
		for (int i = 0; i < n; i++) {
			if (path[i] != 10)
				ans += path[i] + '0';
			else
				ans += "10";
			ans += ' ';
		}
		ans += '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			path[depth] = i;
			DFS(depth + 1);
			vis[i] = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	DFS(0);

	cout << ans;
}

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> vis;
vector<int> stk;

void DFS(int depth) {
	if (depth == n) {
		for (int i : stk)
			cout << "    " << i;
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;

		stk.push_back(i);
		vis[i] = true;
		DFS(depth + 1);
		stk.pop_back();
		vis[i] = false;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vis.resize(n + 1);
	DFS(0);
}

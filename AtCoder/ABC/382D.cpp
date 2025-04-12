#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> ans;

void DFS(int depth) {
	if (depth == n) {
		ans.push_back(v);
		return;
	}

	for (int i = (depth == 0 ? 1 : v.back() + 10); i <= m - 10 * (n - depth - 1); i++) {
		v.push_back(i);
		DFS(depth + 1);
		v.pop_back();
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	DFS(0);
	cout << ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++)
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << " \n"[j == n - 1];
}

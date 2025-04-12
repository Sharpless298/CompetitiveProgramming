#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

multiset<int> ms[500];
vector<int> ans;

void DFS(int u) {
	while (ms[u].size()) {
		int nxt = *ms[u].begin();
		ms[u].erase(ms[u].find(nxt));
		ms[nxt].erase(ms[nxt].find(u));
		DFS(nxt);
	}
	ans.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	while (cin >> m && m) {
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			ms[u].insert(v);
			ms[v].insert(u);
		}

		int st;
		for (int i = 0; i < 500; i++) {
			if (ms[i].size() & 1) {
				st = i;
				break;
			}
		}

		ans.clear();
		DFS(st);
		reverse(ans.begin(), ans.end());
		for (int i : ans)
			cout << i + 1 << '\n';
		cout << '\n';
	}
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int in[200005];
vector<int> G[200005], ans;
priority_queue<int, vector<int>, greater<int>> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		in[b]++;
	}

	for (int i = 0; i < n; i++)
		if (in[i] == 0)
			pq.push(i);
	while (!pq.empty()) {
		int v = pq.top();
		pq.pop();
		ans.push_back(v);

		for (int i : G[v])
			if (--in[i] == 0)
				pq.push(i);
	}

	if ((int)ans.size() == n) {
		for (int i : ans)
			cout << i + 1 << ' ';
		cout << '\n';
	} else
		cout << -1 << '\n';
}

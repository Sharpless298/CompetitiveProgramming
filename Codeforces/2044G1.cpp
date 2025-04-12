#include <iostream>
#include <queue>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> r(n), in(n);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
			r[i]--;
			in[r[i]]++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (in[i] == 0)
				q.push(i);

		vector<int> dp(n);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			in[r[u]]--;
			dp[r[u]] = max(dp[r[u]], dp[u] + 1);
			if (in[r[u]] == 0)
				q.push(r[u]);
		}

		cout << *max_element(dp.begin(), dp.end()) + 2 << '\n';
	}
}

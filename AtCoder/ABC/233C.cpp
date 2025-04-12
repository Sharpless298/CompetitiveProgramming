#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int n, ans;
lli x;
vector<vector<int>> a;

void DFS(int depth, lli res) {
	if (depth == n) {
		ans += (res == x);
		return;
	}

	for (auto &i : a[depth]) {
		if (res > x / i)
			continue;
		DFS(depth + 1, res * i);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		for (int j = 0; j < l; j++) {
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}

	DFS(0, 1);

	cout << ans << '\n';
}

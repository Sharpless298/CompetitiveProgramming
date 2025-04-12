#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> vis1(100000), vis2(100000);
vector<int> G[100000];

void DFSa(int u) {
	vis1[u] = true;
	for (int v : G[u]) {
		if (vis1[v])
			continue;
		DFSa(v);
	}
}

void DFSb(int u) {
	vis2[u] = true;
	for (int v : G[u]) {
		if (vis2[v])
			continue;
		DFSb(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i].first;
			b[i].second = i;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 1; i < n; i++) {
			G[a[i - 1].second].push_back(a[i].second);
			G[b[i - 1].second].push_back(b[i].second);
		}

		for (int i = 0; i < n; i++)
			vis1[i] = vis2[i] = false;
		DFSa(a[n - 1].second);
		DFSb(b[n - 1].second);

		for (int i = 0; i < n; i++)
			cout << (vis1[i] || vis2[i] ? 1 : 0);
		cout << '\n';
	}
}

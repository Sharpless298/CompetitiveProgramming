#include <iostream>
#include <vector>
using namespace std;

int query(int a, int b) {
	cout << "? " << a + 1 << ' ' << b + 1 << '\n';
	fflush(stdout);
	int x;
	cin >> x;
	return x - 1;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<bool> in_tree(n, false);
		vector<int> stk;
		for (int i = 1; i < n; i++)
			stk.push_back(i);

		vector<pair<int, int>> edges;
		in_tree[0] = true;
		while (!stk.empty()) {
			int u = stk.back();
			stk.pop_back();
			if (in_tree[u])
				continue;
			int l = 0, r = u;
			while (true) {
				int q = query(l, r);
				if (q == l) {
					in_tree[r] = true;
					edges.push_back({l, r});
					break;
				}
				if (in_tree[q])
					l = q;
				else
					r = q;
			}
			stk.push_back(u);
		}
		cout << "! ";
		for (auto &[u, v] : edges)
			cout << u + 1 << ' ' << v + 1 << ' ';
		cout << '\n';
		fflush(stdout);
	}
}

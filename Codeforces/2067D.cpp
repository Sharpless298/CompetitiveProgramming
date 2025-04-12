#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int res;
	cin >> res;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		set<int> s;
		for (int i = 0; i < n; i++)
			s.insert(i + 1);
		vector<int> pos(n + 1);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pos[x] = i + 1;
			s.erase(x);
		}

		if (!s.empty()) {
			if (query(*s.begin(), *s.begin() % n + 1) == 0)
				cout << "! A" << endl;
			else
				cout << "! B" << endl;
		} else {
			if (query(pos[1], pos[n]) >= n - 1 && query(pos[n], pos[1]) >= n - 1)
				cout << "! B" << endl;
			else
				cout << "! A" << endl;
		}
	}
}

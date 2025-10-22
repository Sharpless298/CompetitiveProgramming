#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	string t;
	map<string, int> mp;
	function<void(int, int)> DFS = [&](int depth, int n) {
		if (depth == n) {
			mp[t] = ++cnt;
			return;
		}

		for (char i = (depth == 0 ? 'a' : t.back() + 1); i <= 'z'; i++) {
			t.push_back(i);
			DFS(depth + 1, n);
			t.pop_back();
		}
	};

	for (int i = 1; i <= 5; i++) {
		DFS(0, i);
	}

	string s;
	while (cin >> s) {
		cout << mp[s] << '\n';
	}
}

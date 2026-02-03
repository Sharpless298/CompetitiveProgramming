#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	vector<array<int, 26>> trie(500001);
	vector<bool> f(500001), tag(500001);
	function<void(string &)> insert = [&](string &s) {
		int p = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			int c = (int)(s[i] - 'a');
			if (!trie[p][c]) {
				trie[p][c] = ++cnt;
			}
			p = trie[p][c];
		}
		f[p] = true;
	};
	function<int(string &)> find = [&](string &s) {
		int p = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			int c = (int)(s[i] - 'a');
			if (!trie[p][c]) {
				return 0;
			}
			p = trie[p][c];
		}
		if (!f[p]) {
			return 0;
		} else {
			if (tag[p]) {
				return 2;
			} else {
				tag[p] = true;
				return 1;
			}
		}
	};

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int ret = find(s);
		if (ret == 0) {
			cout << "WRONG\n";
		} else if (ret == 1) {
			cout << "OK\n";
		} else {
			cout << "REPEAT\n";
		}
	}
}

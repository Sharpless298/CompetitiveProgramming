#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> p(n);
		for (int &i : p) {
			cin >> i;
			i--;
		}
		string s;
		cin >> s;

		vector<int> mx = p;
		for (int i = 1; i < n; i++) {
			mx[i]  = max(mx[i], mx[i - 1]);
		}

		int cnt = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == 'L' && s[i + 1] == 'R' && mx[i] != i) {
				cnt++;
			}
		}

		while (q--) {
			int pos;
			cin >> pos; pos--;

			for (int i : {pos - 1, pos}) {
				if (0 < i && i < n - 1 && s[i] == 'L' && s[i + 1] == 'R' && mx[i] != i) {
					cnt--;
				}
			}

			s[pos] = 'L' + 'R' - s[pos];
			for (int i : {pos - 1, pos}) {
				if (0 < i && i < n - 1 && s[i] == 'L' && s[i + 1] == 'R' && mx[i] != i) {
					cnt++;
				}
			}

			cout << (cnt ? "NO\n" : "YES\n");
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (s.empty() || s.back() != c)
				s.push_back(c);
		}

		cout << (s.back() == '0' ? s.size() / 2 * 2 : (s.size() - 1) / 2 * 2 + 1) << '\n';
	}
}

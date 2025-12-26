#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string t;
	cin >> t;
	if (t == "first") {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cout << (char)(x + 'a' - 1);
		}
		cout << '\n';
	} else {
		string s;
		cin >> s;
		cout << s.size() << '\n';
		for (int i = 0; i < (int)s.size(); i++) {
			cout << s[i] - 'a' + 1 << " \n"[i + 1 == (int)s.size()];
		}
	}
}

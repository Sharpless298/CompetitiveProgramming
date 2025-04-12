#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int len, ans = 0;
	string s;

	cin >> s;

	len = (int)s.size();
	for (int i = 0; i < len; i++) {
		for (int j = 1; j <= len - i; j++) {
			string a = s.substr(i, j);
			string b(a.rbegin(), a.rend());
			if (a == b)
				ans = max(ans, (int)a.size());
		}
	}

	cout << ans << '\n';
}

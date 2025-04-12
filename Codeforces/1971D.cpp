#include <algorithm>
#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		string t = s;
		sort(t.begin(), t.end());
		if (t == s) {
			cout << 1 << '\n';
			continue;
		}

		bool f = false;
		int ans = 1;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] != s[i - 1])
				ans++;
			if (s[i - 1] == '0' && s[i] == '1')
				f = true;
		}

		if (f)
			ans--;

		cout << ans << '\n';
	}
}

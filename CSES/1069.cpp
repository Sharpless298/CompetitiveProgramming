#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 1, cnt;
	string s;

	cin >> s;
	for (int i = 1; i < (int)s.size(); i++) {
		cnt = 1;
		while (i < (int)s.size() && s[i - 1] == s[i])
			cnt++, i++;
		ans = max(ans, cnt);
	}

	cout << ans << '\n';
}

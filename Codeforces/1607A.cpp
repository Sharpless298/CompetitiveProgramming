#include <iostream>
using namespace std;

int T, ans, a[32];
string s, k;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		ans = 0;

		cin >> s >> k;

		for (int i = 0; i < 26; i++)
			a[s[i] - 'a'] = i;
		for (int i = 1; i < (int)k.size(); i++)
			ans += abs(a[k[i] - 'a'] - a[k[i - 1] - 'a']);

		cout << ans << '\n';
	}
}

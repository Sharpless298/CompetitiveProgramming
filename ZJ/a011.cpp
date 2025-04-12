#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans;
	string s;

	while (getline(cin, s)) {
		ans = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				ans++;
			while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				i++;
		}
		cout << ans << '\n';
	}
}

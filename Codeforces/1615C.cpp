#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		string s1, s2;
		cin >> n >> s1 >> s2;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			a[i] = (s1[i] == '0' ? 0 : 1);
			b[i] = (s2[i] == '0' ? 0 : 1);
		}

		int ans = 0x3f3f3f3f;
		for (int t = 0; t < 2; t++) {
			int c[2] = {0, 0};
			for (int i = 0; i < n; i++) {
				if ((a[i] ^ t) != b[i])
					c[(a[i] ^ t) < b[i]]++;
			}
			if (c[1] == c[0] + t)
				ans = min(ans, c[1] + c[0]);
		}

		if (ans == 0x3f3f3f3f)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
}

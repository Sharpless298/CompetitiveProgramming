#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int ans = 1;
		{
			int t = a + b, cnt = 1;
			if (b + t == c)
				cnt++;
			if (t + c == d)
				cnt++;
			ans = max(ans, cnt);
		}
		{
			int t = c - b, cnt = 1;
			if (a + b == t)
				cnt++;
			if (t + c == d)
				cnt++;
			ans = max(ans, cnt);
		}
		{
			int t = d - c, cnt = 1;
			if (a + b == t)
				cnt++;
			if (b + t == c)
				cnt++;
			ans = max(ans, cnt);
		}
		cout << ans << '\n';
	}
}

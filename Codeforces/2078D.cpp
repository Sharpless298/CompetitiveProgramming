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
		vector<tuple<char, long long, char, long long>> v(n);
		for (auto &[a, b, c, d] : v)
			cin >> a >> b >> c >> d;

		vector<int> g(n + 1);
		for (int i = n - 1, now = 0; i >= 0; i--) {
			auto [a, b, c, d] = v[i];

			if (a != c)
				now = (a == 'x' ? 0 : 1);
			else if (a == 'x' && c == 'x')
				now = (b == d ? now : (b > d ? 0 : 1));
			g[i] = now;
		}
		g[n] = 0;

		long long L = 1, R = 1;
		for (int i = 0; i < n; i++) {
			auto [a, b, c, d] = v[i];
			long long t = (a == 'x' ? L * (b - 1) : b) + (c == 'x' ? R * (d - 1) : d);
			(g[i + 1] == 0 ? L : R) += t;
		}
		cout << L + R << '\n';
	}
}

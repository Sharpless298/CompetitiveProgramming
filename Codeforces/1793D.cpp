#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> q[i];
		q[i]--;
	}

	vector<int> pos_p(n), pos_q(n);
	for (int i = 0; i < n; i++) {
		pos_p[p[i]] = i;
		pos_q[q[i]] = i;
	}

	long long ans = 0;
	int x = min(pos_p[0], pos_q[0]), y = max(pos_p[0], pos_q[0]);
	ans += (1LL + x) * x / 2;
	ans += (1LL + (y - x - 1)) * (y - x - 1) / 2;
	ans += (1LL + (n - y - 1)) * (n - y - 1) / 2;

	for (int i = 0, l = n, r = -1; i < n - 1; i++) {
		l = min({l, pos_p[i], pos_q[i]});
		r = max({r, pos_p[i], pos_q[i]});

		if (pos_p[i + 1] < l && pos_q[i + 1] < l) {
			ans += 1LL * (l - max(pos_p[i + 1], pos_q[i + 1])) * (n - r);
		} else if (pos_p[i + 1] > r && pos_q[i + 1] > r) {
			ans += 1LL * (l + 1) * (min(pos_p[i + 1], pos_q[i + 1]) - r);
		} else if (min(pos_p[i + 1], pos_q[i + 1]) < l && max(pos_p[i + 1], pos_q[i + 1]) > r) {
			ans += 1LL * (l - min(pos_p[i + 1], pos_q[i + 1])) * (max(pos_p[i + 1], pos_q[i + 1]) - r);
		}
	}
	ans++;

	cout << ans << '\n';
}

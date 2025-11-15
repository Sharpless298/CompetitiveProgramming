#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		int cnt = 0;
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (s[i] & 1) {
				cnt++;
			}
		}

		long long ans = 1LL * (c + 2) * (c + 1) / 2;
		for (int i = 0; i < n; i++) {
			ans -= s[i] / 2 + 1;
			ans -= c - s[i] + 1;
		}
		ans += 1LL * (cnt + 1) * cnt / 2 + 1LL * (n - cnt + 1) * (n - cnt) / 2;
		cout << ans << '\n';
	}
}

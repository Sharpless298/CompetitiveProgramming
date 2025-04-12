#include <bits/stdc++.h>
using namespace std;

vector<int> p, lpf(200001);
void sieve(int n) {
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			p.push_back(i);
		}
		for (int j : p) {
			if (i * j > n)
				break;
			lpf[i * j] = j;
			if (j == lpf[i])
				break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(200000);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		vector<int> cnt(200001, 0);
		long long ans = 0;
		for (int i = 0, tot = 0; i < n; i++) {
			if (lpf[a[i]] == a[i]) {
				ans += tot - cnt[a[i]];
				cnt[a[i]]++;
				tot++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (lpf[a[i]] != a[i]) {
				for (int j = 2; j * j <= n; j++) {
					if (a[i] % j == 0) {
						if (lpf[j] == j && lpf[a[i] / j] == a[i] / j) {
							ans += cnt[j];
							if (j != a[i] / j)
								ans += cnt[a[i] / j];
							cnt[a[i]]++;
							ans += cnt[a[i]];
						}
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}

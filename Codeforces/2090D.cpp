#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> prime(100001, true);
	prime[1] = false;
	for (int i = 2; i * i < 100001; i++)
		if (prime[i])
			for (int j = i * i; j < 100001; j += i)
				prime[j] = false;

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		int p;
		for (int i = (n + 1) / 3; i <= 2 * (n + 1) / 3; i++) {
			if (prime[i]) {
				p = i;
				break;
			}
		}

		vector<int> ans;
		vector<bool> used(n + 1);
		ans.push_back(p);
		used[p] = true;
		for (int i = 1; ; i++) {
			if (p - i < 1 || p + i > n) break;

			for (int j = 0; j < 2; j++) {
				if (j & 1) ans.push_back(p - i);
				else ans.push_back(p + i);
			}
			used[p - i] = used[p + i] = true;
		}

		for (int i = 1; i <= n; i++) 
			if (!used[i]) ans.push_back(i);

		for (int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i + 1 == n];
	}
}

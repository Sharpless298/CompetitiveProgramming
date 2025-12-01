#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> h(n);
	int vmax = 0;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		vmax = max(vmax, h[i]);
	}

	int V = vmax;
	int64 ans = 0;
	for (int d = -V; d <= V; ++d) {
		vector<int> cnt(V + 1, 0);
		vector<int> g(V + 1, 0);

		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int prev = h[i] - d;
			int k = 0;
			if (0 <= prev && prev <= V) {
				k = (cnt[prev] + g[prev]) % MOD;
			}

			sum = (sum + k) % MOD;
			cnt[h[i]]++;
			g[h[i]] = (g[h[i]] + k) % MOD;
		}

		ans = (ans + sum) % MOD;
	}
	ans = (ans + n) % MOD;
	cout << ans << "\n";
}

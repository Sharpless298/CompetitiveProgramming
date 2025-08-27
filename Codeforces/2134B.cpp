#include <bits/stdc++.h>
using namespace std;

vector<int> primes, lpf;
void sieve(int n) {
	lpf.assign(n + 1, 1);
	fill(lpf.begin(), lpf.end(), 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (i * p > n) {
				break;
			}
			lpf[i * p] = p;
			if (p == lpf[i]) {
				break;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sieve(100000);
		int p = -1;
		for (int i = 0; i < (int)primes.size(); i++) {
			if (k % primes[i] != 0) {
				p = primes[i];
				break;
			}
		}
		assert(p != -1);

		for (int i = 0; i < n; i++) {
			while (a[i] % p != 0) {
				a[i] += k;
			}
			cout << a[i] << " \n"[i + 1 == n];
		}
	}
}

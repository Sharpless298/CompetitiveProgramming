#include <bits/stdc++.h>
using namespace std;

const int N = 4000000;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> phi(N + 1), f(N + 1), sum(N + 1);
	for (int i = 1; i <= N; i++) {
		phi[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			f[j] += 1LL * i * phi[j / i];
		}
	}
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + f[i] - i;
	}
	int n;
	while (cin >> n && n) {
		cout << sum[n] << '\n';
	}
}

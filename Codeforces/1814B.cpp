#include <bits/stdc++.h>
using namespace std;

int a, b;
int f(int k) {
	return (a - 1) / k + 1 + (b - 1) / k + 1 + (k - 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;

		int N = (int)ceil(sqrt(2 * max(a, b)));
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= N; i++) {
			ans = min(ans, ((a - 1) / i + 1) + ((b - 1) / i + 1) + (i - 1));
		}
		cout << ans << '\n';
	}
}

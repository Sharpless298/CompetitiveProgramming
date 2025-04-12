#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long dp0 = 0, dp1 = -0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		long long tmp = dp0;
		dp0 = max(dp0, dp1 + a[i] * 2);
		dp1 = max(dp1, tmp + a[i]);
	}

	cout << max(dp0, dp1) << '\n';
}

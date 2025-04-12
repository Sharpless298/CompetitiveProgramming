#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	lli sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];

	lli ans = 0x3f3f3f3f;
	for (int i = 1; i < (1 << n); i++) {
		int t = i;
		lli tmp = 0;
		for (int j = 0; t; j++, t >>= 1)
			if (t & 1)
				tmp += a[j];

		ans = min(ans, abs(sum - 2 * tmp));
	}

	cout << ans << '\n';
}

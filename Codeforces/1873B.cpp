#include <algorithm>
#include <iostream>
using namespace std;

int ary[16];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n, ans;

	cin >> t;

	while (t--) {
		ans = 1;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		sort(ary, ary + n);
		ary[0]++;
		for (int i = 0; i < n; i++)
			ans *= ary[i];

		cout << ans << '\n';
	}
}

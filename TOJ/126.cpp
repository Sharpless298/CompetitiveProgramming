#include <bitset>
#include <iostream>
using namespace std;

int n, q, t, ans[30005];
bitset<20005> b;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	b[10000] = 1;

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> t;
		b = (b << t) | (b >> t);
	}

	for (int i = 20000, pre = i; i >= 0; i--) {
		if (b[i])
			pre = i;
		ans[i] = pre;
	}

	while (q--) {
		cin >> t;

		cout << ans[t + 10000] - 10000 << '\n';
	}
}

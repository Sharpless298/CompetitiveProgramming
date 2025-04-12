#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> cnt(n + 1);
		for (int i = 0, x; i < n; i++)
			cin >> x, cnt[x]++;

		int mx = 0;
		for (int i = 1; i <= n; i++)
			mx = max(mx, cnt[i]);

		cout << n - mx << '\n';
	}
}

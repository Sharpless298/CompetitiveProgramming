#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

lli f(int x1, int y1, int x2, int y2) {
	return 1LL * (x2 - x1) * (x2 - x1) + 1LL * (y2 - y1) * (y2 - y1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;

		int xs, ys, xt, yt;
		cin >> xs >> ys >> xt >> yt;

		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (f(xt, yt, v[i].first, v[i].second) <= f(xt, yt, xs, ys)) {
				ok = false;
				break;
			}
		}

		cout << (ok ? "YES\n" : "NO\n");
	}
}

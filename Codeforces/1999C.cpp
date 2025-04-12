#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, s, m;
	cin >> n >> s >> m;
	vector<int> l(n), r(n);
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	if (l[0] >= s) {
		cout << "YES\n";
		return;
	}
	for (int i = 1; i < n; i++) {
		if (l[i] - r[i - 1] >= s) {
			cout << "YES\n";
			return;
		}
	}
	if (m - r[n - 1] >= s) {
		cout << "YES\n";
		return;
	}

	cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}

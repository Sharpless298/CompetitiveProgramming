#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, a, b;
		cin >> n >> a >> b;
		cout << (abs(a - b) & 1 ? "NO\n" : "YES\n");
	}
}

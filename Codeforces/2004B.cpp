#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		pair<int, int> a, b;
		cin >> a.first >> a.second >> b.first >> b.second;
		if (a > b) {
			swap(a, b);
		}

		if (b.first > a.second) {
			cout << 1 << '\n';
		} else if (b.first > a.first && a.second > b.second) {
			cout << (b.second - b.first) + 2 << '\n';
		} else {
			cout << (a.second - b.first) + (a.first != b.first) + (a.second != b.second) << '\n';
		}
	}
}

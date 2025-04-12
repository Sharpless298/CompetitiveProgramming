#include <iostream>
using namespace std;

int ary[100005];

bool binary_search(int l, int r, int k) {
	while (l < r) {
		int m = (l + r) / 2;

		if (ary[m] < k)
			l = m + 1;
		else
			r = m;
	}

	if (ary[l] == k)
		return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q, k;

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	while (q--) {
		cin >> k;
		if (binary_search(0, n, k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

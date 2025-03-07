#include <iostream>
using namespace std;

#define int long long int

bool bsearch(int l, int r, int k) {
	int m;

	while (l < r) {
		m = (l + r) / 2;
		if (m * m == k)
			return true;
		else if (m * m < k)
			l = m + 1;
		else
			r = m;
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (cin >> n && n) {
		if (bsearch(1, 1 << 16, n))
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}

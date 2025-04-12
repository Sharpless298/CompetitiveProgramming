#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k, t;
int ary[MAXN];

int bsearch(int x) {
	int l = 0, r = n, m;

	while (l < r) {
		m = (l + r) / 2;
		if (ary[m] == x)
			return m + 1;
		else if (ary[m] > x)
			r = m;
		else
			l = m + 1;
	}
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> ary[i];
	for (int i = 0; i < k; i++) {
		cin >> t;

		cout << bsearch(t) << '\n';
	}
}

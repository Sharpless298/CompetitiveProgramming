#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<long long> a, block, lazy;

void update(int l, int r, int x) {
	for (int i = l; i < r; i++) {
		if (i / k != l / k)
			break;
		a[i] += x;
		block[i / k] += x;
	}
	for (int i = l / k + 1; i < (r - 1) / k; i++)
		lazy[i] += x;

	if (l / k == (r - 1) / k)
		return;

	for (int i = r - 1; i >= l; i--) {
		if (i / k != (r - 1) / k)
			break;
		a[i] += x;
		block[i / k] += x;
	}
}

long long query(int l, int r) {
	long long sum = 0;
	for (int i = l; i < r; i++) {
		if (i / k != l / k)
			break;
		sum += a[i] + lazy[i / k];
	}
	for (int i = l / k + 1; i < (r - 1) / k; i++)
		sum += block[i] + lazy[i] * k;

	if (l / k == (r - 1) / k)
		return sum;

	for (int i = r - 1; i >= l; i--) {
		if (i / k != (r - 1) / k)
			break;
		sum += a[i] + lazy[i / k];
	}

	return sum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	k = (int)sqrt(n);
	block.resize(n / k + 1);
	lazy.resize(n / k + 1);
	for (int i = 0; i < n; i++)
		block[i / k] += a[i];

	int q;
	cin >> q;
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;

		if (t == 1) {
			int x;
			cin >> x;
			update(l - 1, r, x);
		} else
			cout << query(l - 1, r) << '\n';
	}
}

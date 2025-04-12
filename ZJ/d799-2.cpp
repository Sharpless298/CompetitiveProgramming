#include <array>
#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x & -x

int n;
array<vector<long long>, 2> BIT;

void update(int k, int i, long long x) {
	for (; i <= n; i += lowbit(i))
		BIT[k][i] += x;
}

long long query(int k, int i) {
	long long sum = 0;
	for (; i; i -= lowbit(i))
		sum += BIT[k][i];
	return sum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + a[i];

	/*
	vector<long long> d(n+1);
	d[0] = 0;
	for(int i=1; i<=n; i++)
		d[i] = a[i] - a[i-1];*/

	BIT[0].resize(n + 1);
	BIT[1].resize(n + 1);
	/*
	for(int i=1; i<=n; i++)
		update(0, i, d[i]);

	for(int i=1; i<=n; i++)
		update(1, i, i*d[i]);*/

	int q;
	cin >> q;
	while (q--) {
		int v, l, r;
		cin >> v;

		if (v == 1) {
			int k;
			cin >> l >> r >> k;
			update(0, l, k);
			update(0, r + 1, -k);

			update(1, l, l * k);
			update(1, r + 1, (r + 1) * (-k));
		} else {
			cin >> l >> r;
			// cout << ((r+1)*query(0, r)-query(1, r)) - (l*query(0, l-1)-query(1, l-1)) << '\n';
			cout << (pref[r] - pref[l - 1]) + ((r + 1) * query(0, r) - query(1, r)) -
						(l * query(0, l - 1) - query(1, l - 1))
				 << '\n';
		}
	}
}

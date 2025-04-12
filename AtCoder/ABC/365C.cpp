#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli M;
	cin >> n >> M;

	lli sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];

	if (sum <= M) {
		cout << "infinite\n";
		return 0;
	}

	int l = 0, r = 1e9 + 5;
	while (l < r) {
		int m = (l + r) / 2;

		sum = 0;
		for (int i = 0; i < n; i++)
			sum += min(m, a[i]);

		if (sum <= M)
			l = m + 1;
		else
			r = m;
	}

	cout << l - 1 << '\n';
}

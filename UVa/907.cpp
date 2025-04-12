#include <iostream>
using namespace std;

typedef long long int lli;

int n, k;
lli ary[1024];

int f(lli a) {
	int res = 0;
	lli cur = 0;

	for (int i = 0; i < n; i++) {
		if (cur + ary[i] > a) {
			res++;
			cur = ary[i];
		} else
			cur += ary[i];
	}
	if (cur)
		res++;

	return res;
}

lli binary_search(lli l, lli r) {
	lli m;

	while (l < r) {
		m = (l + r) / 2;
		if (f(m) > k)
			l = m + 1;
		else
			r = m;
	}

	return l;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli mx, sum;

	while (cin >> n >> k) {
		mx = sum = 0;
		n++, k++;

		for (int i = 0; i < n; i++) {
			cin >> ary[i];

			mx = max(mx, ary[i]);
			sum += ary[i];
		}

		cout << binary_search(mx, sum + 1) << '\n';
	}
}

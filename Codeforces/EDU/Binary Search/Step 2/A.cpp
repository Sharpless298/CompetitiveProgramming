#include <iostream>
using namespace std;

typedef long long int lli;

lli w, h, n;

bool f(lli x) {
	return (x / w) * (x / h) >= n;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> w >> h >> n;

	lli l = 0, r = 1;
	while (!f(r))
		r *= 2;

	while (l < r) {
		lli m = (l + r) / 2;

		if (f(m))
			r = m;
		else
			l = m + 1;
	}

	cout << l << '\n';
}

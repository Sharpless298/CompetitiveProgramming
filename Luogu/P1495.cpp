#include <iostream>
using namespace std;

typedef long long int lli;

int n;
lli a[16], b[16], M[16], t[16];

pair<lli, lli> exgcd(lli x, lli y) {
	if (y == 0)
		return make_pair(1, 0);
	pair<lli, lli> res = exgcd(y, x % y);
	return make_pair(res.second, res.first - x / y * res.second);
}

lli f(lli x, lli y, lli m) {
	lli res = 0;

	x %= m, y %= m;
	while (y) {
		if (y & 1)
			res = (res + x) % m;
		x = x * 2 % m, y >>= 1;
	}
	return res;
}

lli CRT() {
	lli MM = 1;
	for (int i = 0; i < n; i++)
		MM *= a[i];
	for (int i = 0; i < n; i++) {
		M[i] = MM / a[i];
		t[i] = (exgcd(M[i], a[i]).first % a[i] + a[i]) % a[i];
	}

	lli ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + f(b[i], f(M[i], t[i], MM), MM)) % MM;

	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	cout << CRT() << '\n';
}

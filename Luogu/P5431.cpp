#include <iostream>
using namespace std;

typedef long long int lli;

lli p;
lli a[5000005], pre[5000005], suf[5000005];

template <typename T>
inline void readint(T &x) {
	char c;
	x = 0;
	int f = 1;
	c = (char)getchar();
	while (c > 57 || c < 48) {
		if (c == 45) {
			f = -1;
		}
		c = (char)getchar();
	}
	while (c <= 57 && c >= 48) {
		x = (x << 3) + (x << 1) + c - 48;
		c = (char)getchar();
	}
	x *= f;
}

lli inv(lli t) {
	if (t == 1)
		return 1;
	return ((p - p / t) * inv(p % t)) % p;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli k, ans = 0;

	readint(n), readint(p), readint(k);
	for (int i = 1; i <= n; i++)
		readint(a[i]);

	pre[0] = 1;
	for (int i = 1; i <= n; i++)
		pre[i] = (pre[i - 1] * a[i]) % p;
	suf[n + 1] = 1;
	for (int i = n; i >= 1; i--)
		suf[i] = (suf[i + 1] * a[i]) % p;

	lli t = k;
	for (int i = 1; i <= n; i++) {
		ans = (ans + t * pre[i - 1] % p * suf[i + 1]) % p;
		t = (t * k) % p;
	}

	cout << (ans * inv(pre[n])) % p << '\n';
}

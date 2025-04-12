#include <iostream>
using namespace std;

#define lli long long int

const int MAXN = 1e5 + 1;
const lli INF = 1e18 + 1;

lli fib[100005];

void solve(int n, lli k) {
	if (n == 1) {
		cout << 'N' << '\n';
		return;
	}
	if (n == 2) {
		cout << 'A' << '\n';
		return;
	}

	if (k <= fib[n - 2])
		solve(n - 2, k);
	else
		solve(n - 1, k - fib[n - 2]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	lli k;

	cin >> n >> k;

	fib[1] = fib[2] = 1;
	for (int i = 3; i < MAXN; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > INF)
			break;
	}
	solve(n, k);
}

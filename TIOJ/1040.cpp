#include <algorithm>
#include <iostream>
using namespace std;

void solve(int a, int b) {
	if (a % b == 0) {
		cout << a / b;
		return;
	}

	cout << a / b << "+1/";
	if (b % (a % b) != 0)
		cout << '{';
	solve(b, a % b);
	if (b % (a % b) != 0)
		cout << '}';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, P, Q;

	cin >> T;
	while (T--) {
		cin >> P >> Q;
		cout << P << '/' << Q << " = ";
		solve(P, Q);
		cout << '\n';
	}
}

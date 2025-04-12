#include <iostream>
using namespace std;

bool f[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0, x; i < n - 1; i++)
		cin >> x, f[x] = true;

	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			cout << i << '\n';
			break;
		}
	}
}

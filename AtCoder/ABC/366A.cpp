#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t, a;
	cin >> n >> t >> a;

	n = n - t - a;

	cout << (n + min(t, a) > max(t, a) ? "No" : "Yes") << '\n';
}

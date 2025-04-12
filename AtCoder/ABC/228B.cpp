#include <iostream>
using namespace std;

bool b[100005];
int a[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, ans = 0;

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	do {
		b[x] = true;
		x = a[x];
	} while (!b[x]);

	for (int i = 1; i <= n; i++)
		if (b[i])
			ans++;

	cout << ans << '\n';
}

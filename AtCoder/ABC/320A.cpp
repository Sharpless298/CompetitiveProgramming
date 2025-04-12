#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, ans = 0, res;

	cin >> a >> b;

	res = 1;
	for (int i = 0; i < b; i++)
		res *= a;
	ans += res;
	res = 1;
	for (int i = 0; i < a; i++)
		res *= b;
	ans += res;

	cout << ans << '\n';
}

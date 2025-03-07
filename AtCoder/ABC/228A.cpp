#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int s, t, x;
	cin >> s >> t >> x;

	if (s < t)
		cout << (s <= x && x < t ? "Yes\n" : "No\n");
	else
		cout << (x < t || s <= x ? "Yes\n" : "No\n");
}

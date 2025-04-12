#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int r;

	cin >> r;

	if (100 - r > 0)
		cout << 100 - r << '\n';
	else if (200 - r > 0)
		cout << 200 - r << '\n';
	else if (300 - r > 0)
		cout << 300 - r << '\n';
	else
		cout << 400 - r << '\n';
}

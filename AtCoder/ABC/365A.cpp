#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int y;
	cin >> y;

	if (y % 400 == 0)
		cout << 366 << '\n';
	else if (y % 100 == 0)
		cout << 365 << '\n';
	else if (y % 4 == 0)
		cout << 366 << '\n';
	else
		cout << 365 << '\n';
}

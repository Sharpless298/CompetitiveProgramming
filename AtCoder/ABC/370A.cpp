#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int l, r;
	cin >> l >> r;
	if ((l && r) || (!l && !r))
		cout << "Invalid\n";
	else if (l)
		cout << "Yes\n";
	else
		cout << "No\n";
}

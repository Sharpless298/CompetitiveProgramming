#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char mid) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(n - 1, from, mid, to);
	cout << from << ' ' << to << '\n';
	hanoi(n - 1, mid, to, from);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	cout << (1 << n) - 1 << '\n';
	hanoi(n, '1', '3', '2');
}

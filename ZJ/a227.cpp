#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char mid) {
	if (n == 1) {
		cout << "Move ring " << n << " from " << from << " to " << to << '\n';
		return;
	}

	hanoi(n - 1, from, mid, to);
	cout << "Move ring " << n << " from " << from << " to " << to << '\n';
	hanoi(n - 1, mid, to, from);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (cin >> n) {
		hanoi(n, 'A', 'C', 'B');
		cout << '\n';
	}
}

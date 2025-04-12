#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d, cnt = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '.')
			cnt++;
	}

	cout << cnt + d << '\n';
}

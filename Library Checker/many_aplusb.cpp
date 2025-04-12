#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	long long int a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
}

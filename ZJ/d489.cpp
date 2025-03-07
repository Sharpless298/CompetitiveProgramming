#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int s = (a + b + c) / 2;
	cout << s * (s - a) * (s - b) * (s - c) << '\n';
}

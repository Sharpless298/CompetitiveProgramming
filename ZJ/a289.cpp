#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> extgcd(int a, int b) {
	if (b == 0)
		return make_pair(1, 0);
	pair<int, int> res = extgcd(b, a % b);
	return make_pair(res.second, res.first - a / b * res.second);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, n;

	while (cin >> a >> n) {
		if (__gcd(a, n) != 1 || n == 1) {
			cout << "No Inverse\n";
			continue;
		}
		cout << (extgcd(a, n).first % n + n) % n << '\n';
	}
}

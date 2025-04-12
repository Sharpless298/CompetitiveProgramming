#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> exgcd(int a, int b) {
	if (b == 0)
		return make_pair(1, 0);
	pair<int, int> res = exgcd(b, a % b);
	return make_pair(res.second, res.first - a / b * res.second);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;

	cin >> a >> b;
	pair<int, int> eg = exgcd(a, b);
	cout << eg.first << ' ' << eg.second << '\n';
}

#include <iostream>
using namespace std;

pair<int, int> extgcd(int a, int b) {
	if(b == 0) return make_pair(1, 0);
	pair<int, int> res = extgcd(b, a%b);
	return make_pair(res.second, res.first-a/b*res.second);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;

	cin >> a >> b;
	cout << (extgcd(a, b).first%b+b)%b << '\n';
}

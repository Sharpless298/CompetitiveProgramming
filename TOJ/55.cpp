#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;

	cin >> n;
	for (int i = 0, x; i < n; i++)
		cin >> x, mp[x]++;
	cin >> q;
	for (int i = 0, x; i < q; i++)
		cin >> x, cout << mp[x] << '\n';
}

#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> p[1005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n);

	for (int i = 0; i < n; i++)
		cout << p[i].first << ' ' << p[i].second << '\n';
}

#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 1e4 + 5;

pair<int, int> p[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, r, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n);
	l = p[0].first, r = p[0].second;
	for (int i = 1; i < n; i++) {
		if (p[i].first > r) {
			ans += (r - l);
			l = p[i].first, r = p[i].second;
		} else if (p[i].first <= r && p[i].second > r)
			r = p[i].second;
		else
			continue;
	}
	ans += (r - l);
	if (n == 1)
		cout << (r - l) << '\n';
	else
		cout << ans << '\n';
}

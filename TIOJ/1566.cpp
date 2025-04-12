#include <deque>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const int MAXN = 1e7;

int n, m, k;
lli ary[MAXN + 5];
vector<pair<int, int>> ans;
deque<pair<int, lli>> mx, mn;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int i = 0; i < n; i++) {
		if (!mx.empty() && mx[0].first <= i - m)
			mx.pop_front();
		if (!mn.empty() && mn[0].first <= i - m)
			mn.pop_front();
		while (!mx.empty() && mx[mx.size() - 1].second < ary[i])
			mx.pop_back();
		while (!mn.empty() && mn[mn.size() - 1].second > ary[i])
			mn.pop_back();

		mx.emplace_back(i, ary[i]);
		mn.emplace_back(i, ary[i]);

		if (mx[0].second - mn[0].second == k) {
			if (i < m)
				ans.emplace_back(0, i);
			else
				ans.emplace_back(i - m + 1, i);
		}
	}
	for (int i = n; i < n + m - 2; i++) {
		if (!mx.empty() && mx[0].first <= i - m)
			mx.pop_front();
		if (!mn.empty() && mn[0].first <= i - m)
			mn.pop_front();
		if (mx[0].second - mn[0].second == k)
			ans.emplace_back(i - m + 1, n - 1);
	}

	cout << ans.size() << '\n';
	for (pair<int, int> i : ans)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

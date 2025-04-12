#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const int INF = 2e9;
const int MAXN = 1e6;

int ary[MAXN + 5], pre[MAXN + 5], nxt[MAXN + 5];
vector<pair<int, int>> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli ans = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
		pre[i] = i - 1;
		nxt[i] = i + 1;
		v.emplace_back(ary[i], i);
	}

	ary[0] = ary[n + 1] = INF;
	pre[n + 1] = n;
	nxt[0] = 1;
	sort(v.begin(), v.end());

	for (int i = 0, idx; i < n - 1; i++) {
		idx = v[i].second;

		if (ary[pre[idx]] < ary[nxt[idx]])
			ans += ary[pre[idx]];
		else
			ans += ary[nxt[idx]];

		pre[nxt[idx]] = pre[idx];
		nxt[pre[idx]] = nxt[idx];
	}

	cout << ans << '\n';
}

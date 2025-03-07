#include <iostream>
#include <queue>
using namespace std;

const int INF = 2e9;

bool in[100005];
int n, k, p, mp[100005], ary[500005], nxt[500005], ans, t;
priority_queue<pair<int, int>> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(mp, mp + 100005, INF);
	fill(nxt, nxt + 500005, INF);

	cin >> n >> k >> p;
	for (int i = 0; i < p; i++) {
		cin >> ary[i];
		if (mp[ary[i]] != INF) {
			nxt[mp[ary[i]]] = i;
			mp[ary[i]] = i;
		} else
			mp[ary[i]] = i;
	}

	for (int i = 0, j = 0; i < p; i++) {
		if (!in[ary[i]]) {
			ans++;
			if (j < k)
				j++;
			else
				in[pq.top().second] = false, pq.pop();
		}
		in[ary[i]] = true;
		pq.push(make_pair(nxt[i], ary[i]));
	}

	cout << ans << '\n';
}

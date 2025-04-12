#include <iostream>
#include <queue>
using namespace std;

typedef long long int lli;

priority_queue<lli, vector<lli>, greater<lli>> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli p, q, ans = 0;

	while (cin >> n && n) {
		ans = 0;
		while (!pq.empty())
			pq.pop();

		for (int i = 0, k; i < n; i++) {
			cin >> k;
			pq.push(k);
		}

		for (int i = 0; i < n - 1; i++) {
			p = pq.top();
			pq.pop();
			q = pq.top();
			pq.pop();

			ans += p + q;
			pq.push(p + q);
		}

		cout << ans << '\n';
	}
}

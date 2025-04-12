#include <deque>
#include <iostream>
using namespace std;

typedef long long int lli;

const int MAXN = 500000;

int h[MAXN + 5], b[MAXN + 5], p, n, k;
lli q, cur;
deque<pair<int, int>> dq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++) {
		if (!dq.empty() && dq[0].first <= i - k) {
			cur -= b[dq[0].first];
			dq.pop_front();
		}
		while (!dq.empty() && dq[dq.size() - 1].second <= h[i]) {
			cur -= b[dq[dq.size() - 1].first];
			dq.pop_back();
		}
		dq.emplace_back(i, h[i]);
		cur += b[i];
		if (cur > q) {
			p = i;
			q = cur;
		}
	}

	cout << p + 1 << ' ' << q << '\n';
}

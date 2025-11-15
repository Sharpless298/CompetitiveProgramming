#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
		}

		sort(x.begin(), x.end());
		int ans = -0x3f3f3f3f;
		for (int l = 0, r = 0; l < n; l++) {
			while (r < n && x[r] - x[l] <= 2 * k) {
				r++;
			}

			ans = max(ans, r - l);
		}

		priority_queue<tuple<int, int, int>> pq;
		for (int l = 0, r = 0; l < n; l++) {
			while (r < n && x[r] - x[l] <= k) {
				r++;
			}

			pq.push(make_tuple(r - l, l, r));
		}
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && x[j] - x[i] <= k) {
				j++;
			}

			while (!pq.empty()) {
				auto [v, l, r] = pq.top();
				if (j > l) {
					pq.pop();
				} else {
					ans = max(ans, j - i + r - l);
					break;
				}
			}
		}

		cout << ans << '\n';
	}
}

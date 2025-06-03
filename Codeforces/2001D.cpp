#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;	
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &i : a) cin >> i, i--;

		vector<int> l(n + 1, INT_MAX);
		for (int i = 0; i < n; i++)
			l[a[i]] = i;

		priority_queue<int, vector<int>, greater<int>> ls(l.begin(), l.end());
		priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> mx_cand, mn_cand;

		for (int i = 0; i <= ls.top(); i++) {
			mx_cand.push({-a[i], i});
			mn_cand.push({a[i], i});
		}

		int cur = 0;
		vector<bool> used(n, false);
		vector<int> ans;
		while (!mn_cand.empty()) {
			auto [x, pos] = (ans.size() & 1 ? mn_cand.top() : mx_cand.top());

			if (ans.size() & 1) {
				mn_cand.pop();
			} else {
				mx_cand.pop();
				x *= -1;
			}
			
			ans.push_back(x);
			cur = pos + 1;
			used[x] = true;

			while (ls.top() != INT_MAX && used[a[ls.top()]]) {
				int t = ls.top(); ls.pop();
				for (int i = t + 1; i <= min(ls.top(), n - 1); i++) {
					mx_cand.push({-a[i], i});
					mn_cand.push({a[i], i});
				}
			}

			while (!mx_cand.empty() && (used[-mx_cand.top()[0]] || mx_cand.top()[1] < cur)) mx_cand.pop();
			while (!mn_cand.empty() && (used[mn_cand.top()[0]] || mn_cand.top()[1] < cur)) mn_cand.pop();
		}

		cout << ans.size() << '\n';
		for (int i : ans) cout << i + 1 << ' ';
		cout << '\n';
	}
}

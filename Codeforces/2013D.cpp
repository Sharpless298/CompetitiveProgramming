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
		vector<long long> a(n);
		for (long long &i : a)
			cin >> i;

		stack<pair<long long, int>> stk;
		for (int i = 0; i < n; i++) {
			long long sum = a[i], cnt = 1;
			while (!stk.empty() && stk.top().first >= (sum / cnt)) {
				sum += stk.top().first * stk.top().second;
				cnt += stk.top().second;
				stk.pop();
			}
			stk.push({sum / cnt, cnt - sum % cnt});
			if (sum % cnt != 0) {
				stk.push({sum / cnt + 1, sum % cnt});
			}
		}

		long long mx = stk.top().first;
		while (stk.size() > 1)
			stk.pop();
		cout << mx - stk.top().first << '\n';
	}
}

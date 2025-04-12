#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

const int MAXN = 1e6 + 5;

int ary[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	for (int t = 0; t < 2; t++) {
		stack<pair<int, int>> stk;

		for (int i = 0; i < n; i++) {
			while (!stk.empty() && stk.top().first < ary[i]) {
				ans += stk.top().second;
				stk.pop();
			}
			if (!stk.empty() && stk.top().first == ary[i]) {
				pair<int, int> temp = stk.top();
				stk.pop();
				if (!stk.empty())
					ans++;
				ans += temp.second;
				stk.emplace(temp.first, temp.second + 1);
			} else {
				if (!stk.empty())
					ans++;
				stk.emplace(ary[i], 1);
			}
		}
		reverse(ary, ary + n);
	}

	cout << ans << '\n';
}

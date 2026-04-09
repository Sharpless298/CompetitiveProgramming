#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & -x)

const int N = 5000;
vector<vector<int>> BIT(N + 1, vector<int>(N + 1, 0));
vector<int64_t> dp;
void update(int r, int c, int p) {
	r++, c++;
	for (; r <= N; r += lowbit(r)) {
		for (int i = c; i <= N; i += lowbit(i)) {
			if (dp[BIT[r][i]] < dp[p]) {
				BIT[r][i] = p;
			}
		}
	}
}

int query(int r, int c) {
	int ret = 0;
	for (; r > 0; r -= lowbit(r)) {
		for (int i = c; i > 0; i -= lowbit(i)) {
			if (dp[ret] < dp[BIT[r][i]]) {
				ret = BIT[r][i];
			}
		}
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	dp.assign(n + 1, 0);
	vector<array<int, 5>> a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
		a[i][0]--, a[i][1]--;
		if (a[i][0] > a[i][1]) {
			swap(a[i][0], a[i][1]);
		}
		a[i][4] = i;
	}
	sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
		if (x[2] != y[2]) {
			return x[2] < y[2];
		}
		if (x[0] == y[0]) {
			return x[1] < y[1];
		}
		return x[0] < y[0];
	});
	vector<int> prev(n + 1, 0);
	for (int i = 0; i < n; i++) {
		prev[a[i][4] + 1] = query(a[i][0] + 1, a[i][1] + 1);
		dp[a[i][4] + 1] = dp[prev[a[i][4] + 1]] + a[i][3];
		update(a[i][0], a[i][1], a[i][4] + 1);
	}
	int idx = query(N, N);
	cout << dp[idx] << '\n';
	vector<int> v;
	while (idx != 0) {
		v.push_back(idx);
		idx = prev[idx];
	}
	cout << v.size() << '\n';
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " \n"[i + 1 == (int)v.size()];
	}
}

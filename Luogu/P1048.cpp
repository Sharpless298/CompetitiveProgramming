#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, M;
	cin >> T >> M;
	vector<int> t(M), v(M);
	for (int i = 0; i < M; i++) {
		cin >> t[i] >> v[i];
	}

	vector<int> dp(T + 1);
	for (int i = 0; i < M; i++) {
		for (int j = T; j >= t[i]; j--) {
			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

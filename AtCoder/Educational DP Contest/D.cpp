#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, W;

	cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];

	vector<lli> dp(W + 1);
	for (int i = 0; i < n; i++)
		for (int j = W; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

	cout << dp[W] << '\n';
}

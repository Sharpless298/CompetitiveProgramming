#include <iostream>
using namespace std;

int n;
int ary[100005], dp[100005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	dp[0] = 0;
	dp[1] = abs(ary[1] - ary[0]);
	for (int i = 2; i < n; i++)
		dp[i] = min(dp[i - 1] + abs(ary[i] - ary[i - 1]), dp[i - 2] + abs(ary[i] - ary[i - 2]));

	cout << dp[n - 1] << '\n';
}

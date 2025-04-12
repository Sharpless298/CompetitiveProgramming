#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<lli> pref(n + 1);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];

	lli ans = 0;
	map<lli, lli> mp;
	for (int i = 1; i <= n; i++) {
		mp[pref[i - 1]]++;
		ans += mp[pref[i] - k];
	}

	cout << ans << '\n';
}

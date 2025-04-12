#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int x, t, a[510000];
vector<int> v, LIS, ans;
vector<int>::iterator k;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> x)
		v.push_back(x);

	LIS.push_back(v[0]);
	a[0] = 1;
	for (int i = 1; i < (int)v.size(); i++) {
		if (v[i] > LIS[LIS.size() - 1]) {
			LIS.push_back(v[i]);
			a[i] = (int)LIS.size();
		} else {
			k = lower_bound(LIS.begin(), LIS.end(), v[i]);
			*k = v[i];
			a[i] = (int)(k - LIS.begin() + 1);
		}
	}
	t = (int)LIS.size();
	for (int i = (int)v.size() - 1; i >= 0; i--)
		if (a[i] == t)
			ans.push_back(v[i]), t--;
	reverse(ans.begin(), ans.end());

	cout << LIS.size() << '\n';
	cout << '-' << '\n';
	for (int i : ans)
		cout << i << '\n';
}

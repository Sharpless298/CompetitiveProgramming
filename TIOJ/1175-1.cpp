#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[100005];
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	vector<int>::iterator iter;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		iter = lower_bound(v.begin(), v.end(), a[i]);

		if (iter == v.end())
			v.push_back(a[i]);
		else
			*iter = a[i];
	}

	cout << v.size() << '\n';
}

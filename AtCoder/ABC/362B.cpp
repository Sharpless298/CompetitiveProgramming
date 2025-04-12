#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int x[3], y[3];
vector<int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < 3; i++)
		v.push_back((x[(i + 1) % 3] - x[i]) * (x[(i + 1) % 3] - x[i]) +
					(y[(i + 1) % 3] - y[i]) * (y[(i + 1) % 3] - y[i]));

	sort(v.begin(), v.end());

	if (v[0] + v[1] == v[2])
		cout << "Yes\n";
	else
		cout << "No\n";
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long int x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int mn = 0x3f3f3f3f;
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum <= x)
			sum += a[i];
		else {
			mn = i;
			break;
		}
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum <= y)
			sum += b[i];
		else {
			mn = min(mn, i);
			break;
		}
	}

	cout << (mn == 0x3f3f3f3f ? n : mn) << '\n';
}

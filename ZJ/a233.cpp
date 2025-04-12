#include <algorithm>
#include <iostream>
using namespace std;

int ary[1000005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n);

	for (int i = 0; i < n; i++)
		cout << ary[i] << ' ';
	cout << '\n';
}

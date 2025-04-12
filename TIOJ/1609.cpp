#include <algorithm>
#include <iostream>
using namespace std;

int n;
int ary[1000005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	sort(ary, ary + n);

	for (int i = 0; i < n; i++) {
		if (i)
			cout << ' ';
		cout << ary[i];
	}
	cout << '\n';
}

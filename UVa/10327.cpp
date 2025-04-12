#include <iostream>
using namespace std;

int ary[1005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, cnt;

	while (cin >> n) {
		cnt = 0;

		for (int i = 0; i < n; i++)
			cin >> ary[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j + 1 < n - i; j++) {
				if (ary[j] > ary[j + 1]) {
					swap(ary[j], ary[j + 1]);
					cnt++;
				}
			}
		}

		cout << "Minimum exchange operations : " << cnt << '\n';
	}
}

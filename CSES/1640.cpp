#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;

bool f;
int n, x;
int ary[MAXN], sorted_ary[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> ary[i];

	memcpy(sorted_ary, ary, sizeof(int) * n);
	sort(sorted_ary, sorted_ary + n);
	for (int i = 0; !f && i < n; i++) {
		if (x == ary[i] * 2) {
			auto iter = lower_bound(sorted_ary, sorted_ary + n, ary[i]);
			if (*iter == *next(iter)) {
				cout << i + 1 << ' ';
				for (int j = i + 1; j < n; j++) {
					if (ary[j] == ary[i]) {
						cout << j + 1 << '\n';
						break;
					}
				}
				f = true;
			}
		} else {
			if (binary_search(sorted_ary, sorted_ary + n, x - ary[i])) {
				cout << i + 1 << ' ';
				for (int j = i + 1; j < n; j++) {
					if (ary[j] == (x - ary[i])) {
						cout << j + 1 << '\n';
						break;
					}
				}
				f = true;
			}
		}
	}

	if (!f)
		cout << "IMPOSSIBLE\n";
}

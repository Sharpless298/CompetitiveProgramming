#include <iostream>
using namespace std;

char temp[32];
char c[32][32];
int k, q, r;
int ary[32][32];
string t;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k >> q >> r;
	cin >> t;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < k; j++)
			cin >> ary[i][j];
	}

	for (int i = 0; i < q; i++) {
		for (int j = 0; j < k; j++) {
			if (i == 0)
				temp[ary[i][j] - 1] = t[j];
			else
				temp[ary[i][j] - 1] = c[i - 1][j];
		}
		for (int p = 0; p < k; p++)
			c[i][p] = temp[p];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < q; j++)
			cout << c[j][i];
		cout << '\n';
	}
}

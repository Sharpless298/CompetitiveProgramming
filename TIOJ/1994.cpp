#include <iostream>
using namespace std;

const int MAXN = (1 << 11) + 5;

int tbl[2][MAXN][MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, L = 1, d = 1;

	cin >> n;

	for (int p = 0; p < n; p++) {
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				tbl[d][i][j] = tbl[!d][j][i];
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				tbl[d][i + L][j] = tbl[!d][i][j] + L * L;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				tbl[d][i + L][j + L] = tbl[!d][i][j] + L * L * 2;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				tbl[d][i][j + L] = tbl[!d][L - 1 - j][L - 1 - i] + L * L * 3;
		L <<= 1;
		d = !d;
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++)
			cout << tbl[!d][i][j] << ' ';
		cout << '\n';
	}
}

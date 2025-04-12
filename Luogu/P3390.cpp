#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

int n;

vector<vector<lli>> mul(vector<vector<lli>> &a, vector<vector<lli>> &b) {
	vector<vector<lli>> res(n, vector<lli>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli k;

	cin >> n >> k;
	vector<vector<lli>> A(n, vector<lli>(n));
	for (int i = 0; i < n; i++)
		A[i][i] = 1;
	vector<vector<lli>> B(n, vector<lli>(n));
	for (auto &i : B)
		for (auto &j : i)
			cin >> j;

	while (k) {
		if (k & 1)
			A = mul(A, B);
		B = mul(B, B), k >>= 1;
	}

	for (auto &i : A) {
		for (auto &j : i)
			cout << j << ' ';
		cout << '\n';
	}
}

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

vector<vector<lli>> mul(vector<vector<lli>> &a, vector<vector<lli>> &b) {
	vector<vector<lli>> res(2, vector<lli>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	lli x1, x2, a, b;

	cin >> x1 >> x2 >> a >> b >> n;
	n -= 2;
	vector<vector<lli>> A(2, vector<lli>(2));
	A[0][0] = A[1][1] = 1;
	vector<vector<lli>> B(2, vector<lli>(2));
	B[0] = {b, 1}, B[1] = {a, 0};
	while (n) {
		if (n & 1)
			A = mul(A, B);
		B = mul(B, B), n >>= 1;
	}

	cout << (x2 * A[0][0] + x1 * A[1][0]) % MOD << '\n';
}

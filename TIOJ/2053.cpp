#include <iostream>
using namespace std;

typedef long long int lli;

struct Matrix {
	lli m[2][2];
};

const lli MOD = 1e9+7;

int x1, x2, a, b, n;
Matrix A;

Matrix mul(Matrix &x, Matrix &y) {
	Matrix t;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			t.m[i][j] = 0;
			for(int k=0; k<2; k++)
				t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j]) % MOD;
		}
	}

	return t;
}

void fpow() {
	for(int i=0; i<2; i++)
		A.m[i][i] = 1;
	Matrix B = {b, 1, a, 0};

	while(n) {
		if(n & 1) A = mul(A, B); 
		B = mul(B, B), n >>= 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> x1 >> x2 >> a >> b >> n;
	n -= 2;
	fpow();
	
	cout << (x2*A.m[0][0]%MOD + x1*A.m[1][0]%MOD) % MOD << '\n';
}

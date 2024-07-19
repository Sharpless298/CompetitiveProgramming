#include <iostream>
using namespace std;

typedef long long int lli;

struct matrix {
	lli m[128][128];
};

const lli MOD = 1e9+7;

int n;
matrix A, ans;

matrix mul(matrix &a, matrix &b) {
	matrix t;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			t.m[i][j] = 0;

	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			for(int k=0; k<n; k++)
				t.m[i][j] = (t.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
		
	return t;
}

void fpow(lli k) {
	matrix B = A;

	while(k) {
		if(k & 1) ans = mul(ans, B);
		B = mul(B, B), k >>= 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	lli k;

	cin >> n >> k;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> A.m[i][j];
	
	for(int i=0; i<n; i++)
		ans.m[i][i] = 1;

	fpow(k);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cout << ans.m[i][j] << ' ';
		cout << '\n';
	}
}

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9+7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	vector<lli> fact(2197157), inv(1148581), fact_inv(1148581);
	fact[0] = 1;
	for(int i=1; i<=2197152; i++) fact[i] = fact[i-1]*i%MOD;
	inv[1] = 1;
	for(int i=2; i<=1148576; i++) inv[i] = inv[MOD%i]*(MOD-MOD/i)%MOD;
	fact_inv[0] = 1;
	for(int i=1; i<=1148576; i++) fact_inv[i] = fact_inv[i-1]*inv[i]%MOD;

	cin >> T;
	while(T--) {
		int n;

		cin >> n;

		cout << fact[2*n]*fact_inv[n]%MOD*fact_inv[n+1]%MOD << '\n';
	}
}



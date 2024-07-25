#include <iostream>
using namespace std;

typedef long long int lli;

int n, p;
lli inv[3000005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> p;
	inv[1] = 1;
	for(int i=2; i<=n; i++)
		inv[i] = (p-p/i) * inv[p%i] % p;

	for(int i=1; i<=n; i++)
		cout << inv[i] << '\n';
}



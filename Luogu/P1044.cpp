#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	vector<lli> f(20);
	f[0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++)
			f[i] += f[j]*f[i-j-1];

	cout << f[n] << '\n';
}




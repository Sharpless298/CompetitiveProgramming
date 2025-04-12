#include <iostream>
#include <vector>
using namespace std;

int lpf[100005];
vector<int> p, ans;

void sieve(int n) {
	fill(lpf, lpf + n + 1, 1);

	for (int i = 2; i <= n; i++) {
		if (lpf[i] == 1) {
			lpf[i] = i;
			p.push_back(i);
		}
		for (int j : p) {
			if (i * j > n)
				break;
			lpf[i * j] = j;
			if (j == lpf[i])
				break;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	cout << n << ": ";
	sieve(100000);

	for (int i : p)
		while (n % i == 0)
			n /= i, ans.push_back(i);

	if (ans.empty())
		cout << n << '\n';
	else {
		for (int i = 0; i < (int)ans.size(); i++)
			cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
	}
}

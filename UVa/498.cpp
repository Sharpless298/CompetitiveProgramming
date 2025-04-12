#include <iostream>
#include <sstream>
using namespace std;

int p, k;
int poly[100000];
long long int xpow[10000];
long long int sum;
stringstream ss;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	xpow[0] = 1;
	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);

		ss.str(s1);
		p = 0;
		while (ss >> poly[p]) {
			p++;
		}
		ss.clear();
		ss.str(s2);
		bool f = false;
		while (ss >> k) {
			if (f)
				cout << ' ';
			f = true;

			sum = 0;
			for (int i = 1; i < p; i++)
				xpow[i] = xpow[i - 1] * k;
			for (int i = p - 1, j = 0; i >= 0; i--, j++)
				sum += poly[j] * xpow[i];
			cout << sum;
		}
		cout << '\n';
		ss.clear();
	}
}

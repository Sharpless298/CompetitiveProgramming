#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &a) {
	int sum = accumulate(a.begin(), a.end(), 0);
	bitset<2048> bs;
	bs[0] = 1;
	for (int i = 0; i < n; i++) {
		bs |= (bs << a[i]);
	}

	int mn = 0x3f3f3f3f, ret = 0x3f3f3f3f;
	for (int i = sum; i >= 0; i--) {
		if (bs[i] && abs(sum - 2 * i) < mn) {
			mn = abs(sum - 2 * i);
			ret = i;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	vector<int> a(s1), b(s2), c(s3), d(s4);
	for (int i = 0; i < s1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < s2; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < s3; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < s4; i++) {
		cin >> d[i];
	}
	cout << f(s1, a) + f(s2, b) + f(s3, c) + f(s4, d) << '\n';
}

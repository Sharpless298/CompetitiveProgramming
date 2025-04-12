#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
inline void readint(T &x) {
	char c;
	x = 0;
	int f = 1;
	c = (char)getchar();
	while (c > 57 || c < 48) {
		if (c == 45) {
			f = -1;
		}
		c = (char)getchar();
	}
	while (c <= 57 && c >= 48) {
		x = (x << 3) + (x << 1) + c - 48;
		c = (char)getchar();
	}
	x *= f;
}

string to_string(__int128 x) {
	if (x < 0)
		return "-" + to_string(-x);

	string s;
	while (s.empty() || x)
		s += (char)(x % 10 + '0'), x /= 10;
	reverse(s.begin(), s.end());
	return s;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		__int128 a, b;
		readint(a), readint(b);
		cout << to_string(a + b) << '\n';
	}
}

#include <iostream>
using namespace std;

struct myst{
	int x;
	int y;
	myst(int _x, int _y):x(_x),y(_y){}
	bool operator <(const myst &a) {
		return y > a.x;
	}
};

signed main() {
	myst p(5, 7);
	myst q(6, 2);
	cout << (p < q) << '\n';
}

#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x) x&-x

vector<int> BIT;

void update(int i, int x) {
	for(; i<=n; i+=lowbit(i)) BIT[i] += x;
}

int query(int i) {
	int sum = 0;
	for(; i; i-=lowbit(i)) sum += BIT[i];
	return sum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

}

#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int ans = 0;
	for(int i=1; i<1000; i++) 
		if(i%3==0 || i%5==0) ans += i;
	
	cout << ans << '\n';
}

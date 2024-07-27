#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

/*
const double EPS = 1e-12;
pair<double, double> operator+(pair<double, double> &a, pair<double, double> &b) 
{ return make_pair(a.first+b.first, a.second+b.second); }
pair<double, double> operator-(pair<double, double> &a, pair<double, double> &b) 
{ return make_pair(a.first-b.first, a.second-b.second); }
pair<double, double> operator*(pair<double, double> &a, double b) 
{ return make_pair(a.first*b, a.second*b); }
pair<double, double> operator/(pair<double, double> &a, double b) 
{ return make_pair(a.first/b, a.second/b); }
double dot(pair<double, double> a, pair<double, double> b) 
{ return a.first*b.first + a.second*b.second; }
double cross(pair<double, double> a, pair<double, double> b) 
{ return a.first*b.second - a.second*b.first; }
double abs2(pair<double, double> &a) 
{ return dot(a, a); }
double abs(pair<double, double> &a) 
{ return sqrt(dot(a, a)); }
*/

template<typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b) { return make_pair(a.first+b.first, a.second+b.second); }
template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b) { return make_pair(a.first-b.first, a.second-b.second); }
template<typename T>
pair<T, T> operator*(pair<T, T> a, const T b) { return make_pair(a.first*b, a.second*b); }
template<typename T>
pair<T, T> operator/(pair<T, T> a, const T b) { return make_pair(a.first/b, a.second/b); }
template<typename T>
T dot(pair<T, T> a, pair<T, T> b) { return a.first*b.first + a.second*b.second; }
template<typename T>
T cross(pair<T, T> a, pair<T, T> b) { return a.first*b.second - a.second*b.first; }
template<typename T>
T abs2(pair<T, T> a) { return dot(a, a); }
template<typename T>
T abs(pair<T, T> a) { return sqrt(dot(a, a)); }

template<typename T>
bool collinear(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	return fabs(cross(a-p, b-p)) < 0;
}

template<typename T>
bool onSegment(pair<T, T> &a, pair<T, T> &b, pair<T, T> &p) {
	return collinear(a, b, p) && dot(a-p, b-p)<0;
}

template<typename T>
bool intersect(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	return (cross(b-a, c-a)*cross(b-a, d-a)<0 && cross(d-c, a-c)*cross(d-c, b-c)<0) ||
		(onSegment(a, b, c)||onSegment(a, b, d)||onSegment(c, d, a)||onSegment(c, d, b));
}

template<typename T>
pair<T, T> intersection(pair<T, T> &a, pair<T, T> &b, pair<T, T> &c, pair<T, T> &d) {
	assert(intersect(a, b, c, d));
	return a + (b-a) * cross(a-c, d-c) / cross(d-c, b-a);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pair<double, double> a = {8, 9};
	pair<double, double> b = {2, 0};
	pair<double ,double> c = {1, 1};
	pair<double ,double> d = {1, -1};
	//double c = 4;
	auto e = intersection(a, b, c, d);
	cout << e.first << ' ' << e.second << '\n';
}

#include <iostream>
#include <vector>

using namespace std;

struct Point {

  int x;
  int y;
  int not_initiated = -9999;
  
  Point() :x(not_initiated), y(not_initiated) {}
  Point(int xx, int yy) :x(xx), y(yy) {}
  

};

  istream& operator>>(istream& is, Point& p) {
  	int x,y;
  	char ch1, ch2;
  	is >> x >> ch1 >> y >> ch2;

  	if(!is) return is;
  	if(ch1 != ',' || ch2 != ';') {
  		is.clear(ios_base::failbit);
  		return is;
  	}
  	p = Point(x,y);

  	return is;

  }

  ostream& operator<<(ostream& os, Point& p) {
  	
  	os << p.x << ',' << p.y << ';';

  	return os;

  }

int main() {

  vector<Point> pts;
  cout << "Please enter 3 points: " << endl;

  Point p;
  while (cin >> p) pts.push_back(p);

  for(int i = 0; i < pts.size(); ++i) cout << pts[i];
}
#include <iostream>
#include <cmath>

using namespace std;

class Sphere {
private:
	double radius;
public:
	
	Sphere() { this->radius = 0; }
	Sphere(double radius) { this->radius = radius; }

	double getRadius() { return this->radius; }
	void setRadius(double radius) { this->radius = radius; }

	double getVolume() { return(pow(this->radius, 2) * 3.1415); }

	Sphere operator +(Sphere& obj) { 
		Sphere a(sqrt((this->getVolume() + obj.getVolume()) / 3.1415));
		return a; 
	}
	Sphere operator ++() { this->radius++; return *this; }

	Sphere operator ++(int notused) {
		Sphere t = *this;
		this->radius++;
		return t;
	}

	friend ostream& operator << (ostream& t, Sphere& obj);
};

ostream& operator << (ostream& t, Sphere& obj) {
	t << "Radius: " << obj.radius << " | Volume: " << obj.getVolume();
	return t;
}

int main() {
	Sphere a(5.0), b(2.5);
	Sphere c = a + b;

	cout << "a = " << a << endl << "b = " << b << endl;
	cout << "c = a + b = " << c << endl;

	a = b++;
	cout << "Result of postfix operation ++" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;

	a = ++b;
	cout << "Result of prefix operation ++" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
}
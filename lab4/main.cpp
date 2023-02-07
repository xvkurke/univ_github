#include <iostream>
#include <list>

using namespace std;

class numbers {
private:
	list<double> num;
	int size;

public:
	numbers(int size) {

		this->size = size;

		for (int i = 0; i < size; i++) {

			if (i % 2 == 0) this->num.push_back(i - 3.8);
			else this->num.push_back(i + 1.5);

		}
		cout << endl << "Main constructor init" << endl;
	}

	list<double> getNums() { return this->num; }
	int getSize() { return this->size; }

	~numbers() { this->num.clear(); this->num.empty(); }
};

double operateNumbers(numbers num) {

	double res = 0;
	list<double> nums = num.getNums();

	cout << endl;

	for (int n: nums) { if (n > 0) res += n; }
	return res;
}

int main() {
	int size;

	cout << "Write size: ";
	cin >> size;

	numbers num = numbers(size);

	list<double> nums = num.getNums();

	for (double n : nums) { cout << n << " "; }

	cout << endl << "Result is: " << operateNumbers(num) << endl;
}

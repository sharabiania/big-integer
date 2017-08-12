#include <iostream>
#include <list>

typedef unsigned int uint;

using std::cout;
using std::cin;
using std::list;
using std::ostream;
using std::endl;


class BigInt {

private:
	list<uint> digits;

public:

	/* overload ctor. */
	BigInt(char value[]) {
		// will call assignment operator
		*this = value;
	}

	/* copy constructor */
	BigInt(const BigInt& obj) {

		// will call copy assignment constructor.
		*this = obj;
	}

	/* copy assignment */
	BigInt& operator=(const BigInt& other) {
		digits = other.digits;
		return *this;
	}
	

	/* assignment */
	BigInt& operator=(char rhs[]) {
		digits.clear();
		for (int i = 0; i < strlen(rhs); i++)
			digits.push_front(rhs[i] - '0');

		return *this;
	}

	/* prefix increment */
	BigInt& operator++() {
		int carry = 0;
		for (auto digit = digits.begin(); digit != digits.end(); ++digit) {

			if (++*digit == 10) {
				*digit = 0;
				carry = 1;
			}
			else {
				*digit += carry;	
				break;
			}
		}
		if (carry == 1)
			digits.push_back(1);
		return *this;
	}

	/* postfix increament */
	BigInt operator++(int) {

		// save the original value.
		BigInt temp = *this;

		// increment this object.
		++*this;

		// return old original value.
		return temp;
	}



	friend ostream& operator<<(ostream& os, const BigInt& obj) {
		for (auto i = obj.digits.rbegin(); i != obj.digits.rend(); ++i)
			os << *i;

		return os;
	}
};


void main() {

	// overload ctor.
	BigInt a = "123";

	cout << a++ << endl;
	cout << ++a << endl;

	cin.get();
}

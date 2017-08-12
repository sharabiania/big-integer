#include <iostream>
#include <list>
#include <cstring>
#include <stdint.h>



using std::cout;
using std::cin;
using std::list;
using std::ostream;
using std::endl;

typedef short unsigned int uint;

class bigint {

private:
	list<uint> digits;

public:

	/* overload ctor. */
	bigint(const char value[]) {
		// will call assignment operator
		*this = value;
	}

	/* copy constructor */
	bigint(const bigint& obj) {

		// will call copy assignment constructor.
		*this = obj;
	}

	/* copy assignment */
	bigint& operator=(const bigint& other) {
		digits = other.digits;
		return *this;
	}
	

	/* assignment */
	bigint& operator=(const char rhs[]) {
		digits.clear();
		for (unsigned int i = 0; i < strlen(rhs); i++)
			digits.push_front(rhs[i] - '0');

		return *this;
	}

	/* prefix increment */
	bigint& operator++() {
		int carry = 0;
		for (list<uint>::iterator digit = digits.begin(); digit != digits.end(); ++digit) {

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
	bigint operator++(int) {

		// save the original value.
		bigint temp = *this;

		// increment this object.
		++*this;

		// return old original value.
		return temp;
	}



	friend ostream& operator<<(ostream& os, const bigint& obj) {
		for (list<uint>::const_reverse_iterator i = obj.digits.rbegin(); i != obj.digits.rend(); ++i)
			os << *i;

		return os;
	}
};


int main() {

	// overload ctor.
	bigint a = "123";

	cout << a++ << endl;
	cout << ++a << endl;
    

	cin.get();
    return 0;
}

#include <iostream>

typedef unsigned int uint;

using namespace std;

class BigInt {

private:
	uint *digits = nullptr;
	uint size;
public:
	BigInt(uint size) {
		digits = new uint[size];
		this->size = size;
		for (int i = 0; i < size; i++) 
			digits[i] = 0;
	}
	
	BigInt(char value[]) {
		*this = value;
	}

	/* copy constructor */
	BigInt(const BigInt& obj) {
		
		*this = obj;
	}

	/* copy assignment */
	BigInt& operator=(const BigInt& other) {		
		size = other.size;
		digits = new uint[size];
		for (int i = 0; i < size; i++)
			digits[i] = other.digits[i];

		return *this;
	}

	~BigInt() {
		delete[] digits;
		digits = nullptr;
		size = 0;
	}

	/* assignment */
	BigInt& operator=(char rhs[]) {
		delete[] digits;
		digits = nullptr;
		size = strlen(rhs);
		digits = new uint[size];
		for (int i = 0; i < size; i++) {
			digits[i] = rhs[i] - '0';
		}
		return *this;
	}	

	/* prefix increment */
	BigInt& operator++() {

		for (int i = size - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i]++;
				return *this;
			}
		}
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

	friend ostream& operator<<(ostream& os, const BigInt& bigInt) {
		for(int i = 0; i < bigInt.size; i++)
		{
			os << bigInt.digits[i];
		}
		return os;
	}
};


void main() {

	BigInt a = "199";	
	cout << a++ << endl;
	cout << ++a << endl;
	
	

	cin.get();
}

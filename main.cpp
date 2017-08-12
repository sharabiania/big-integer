#include <iostream>

typedef unsigned int uint;

using namespace std;

class BigInt {

private:
	uint *digits;
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

	BigInt& operator=(const BigInt& other) {

		delete[] digits;
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

	friend ostream& operator<<(ostream& os, const BigInt& bigInt) {
		for(int i = 0; i < bigInt.size; i++)
		{
			os << bigInt.digits[i];
		}
		return os;
	}
};


void main() {

	BigInt a = "123";	
	cout << a;
	cin.get();
}

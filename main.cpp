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
    bool sign = false;
	list<uint> digits;

public:
    /* default ctor */
    bigint() {}

	/* overload ctor */
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
        bool skip = true; // skip consecutive preceding zeros.
        unsigned int i = 0;
        if(rhs[0] == '-')
        {   
            sign = true;
            ++i;
        }
		for (; i < strlen(rhs); i++) {
            if(skip) {
                if(rhs[i] != '0') {
                    digits.push_front(rhs[i] - '0');
                    skip = false;
                }
            }            
            else
                digits.push_front(rhs[i] - '0');
        }        

		return *this;
	}

    int compare(const bigint& other){
        if(other.sign && !this->sign) return 1;
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

   
    /* add two bigints */
    bigint operator+(const bigint& rhs){
        
        list<uint>::const_iterator it1 = digits.begin();
        list<uint>::const_iterator it2 = rhs.digits.begin();
        bigint temp;
        uint carry = 0;
        
        while(it1 != digits.end() || it2 != rhs.digits.end()){
            uint a = 0, b = 0;
            if(it1 != digits.end()) a = *(it1++);
            if(it2 != rhs.digits.end()) b = *(it2++);
            uint sum = a + b + carry;
            carry = 0;
            if(sum >= 10) {
                sum %= 10;
                carry = 1;
            }
            
            temp.digits.push_back(sum);
          
        }
        if(carry == 1)
            temp.digits.push_back(1);
    
        return temp;
    }

    /* TODO: subtract two bigints */
    bigint operator-(const bigint& rhs){
        list<uint>::const_iterator it1 = digits.begin();
        list<uint>::const_iterator it2 = rhs.digits.begin();
        
        bigint temp;
        while(it1 != digits.end()|| it2 != rhs.digits.end()){
            uint a = 0, b = 0, carry = 0;
            if(it1 != digits.end()) a = *(it1++);
            if(it2 != rhs.digits.end()) b = *(it2++);
            if(a < b) carry = 10;
            if(carry != 0) --a;
            int sub = carry + a - b;
            temp.digits.push_back(sub);
        }
        return temp;
    }
    

	friend ostream& operator<<(ostream& os, const bigint& obj) {
        if(obj.sign) os << '-';
		for (list<uint>::const_reverse_iterator i = obj.digits.rbegin(); i != obj.digits.rend(); ++i)
			os << *i;

		return os;
	}
};


int main() {

	// overload ctor.
	bigint a = "-000123000";
    bigint b = "9";

	cout << a << endl;    

	cin.get();
    return 0;
}

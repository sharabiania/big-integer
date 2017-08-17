#include <iostream>
#include <list>
#include <cstring>

using std::cout;
using std::cin;
using std::list;
using std::ostream;
using std::endl;

typedef short int sint;

class bigint {

private:
    bool negative;
	list<sint> digits;

public:
    /* default ctor */
    bigint() {
        negative = false;        
    }

	/* overload ctor */
	bigint(const char value[]):bigint() {
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
        negative = other.negative;
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
            negative = true;
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

        if(digits.empty()) {
            digits.push_back(0);
            negative = false;
        }
        
		return *this;
	}


    int compare(const bigint& other) const{
        int check = 1;
        if(other.negative && !negative) return 1;
        if(!other.negative && negative) return -1;
        if(other.negative && negative) check = -1;
        if(other.digits.size() < digits.size()) return 1 * check;
        if(other.digits.size() > digits.size()) return -1 * check;
        list<sint>::const_reverse_iterator it1 = digits.rbegin();
        list<sint>::const_reverse_iterator it2 = other.digits.rbegin();
        while(it1 != digits.rend()){
            if(*it1 > *it2 ) return 1 * check;
            if(*it1 < *it2) return -1 * check;
            ++it1;
            ++it2;
        }
        return 0;
    }

    bool operator>(const bigint& rhs){
        if (compare(rhs) > 0) return true;
        else return false;
    }
    
    bool operator<(const bigint& rhs){
        if(compare(rhs) < 0) return true;
        else return false;
    }
    
    bool operator==(const bigint& rhs) const{
        if(compare(rhs) == 0) return true;
        else return false;
    }

    bool operator!=(const bigint& rhs) {
        if(compare(rhs) == 0) return false;
        else return true;
    }
    
    bigint& operator-(){
        negative = true;
        return *this;
    }
    
	/* prefix increment */
	bigint& operator++() {
        if(!negative) {
            int carry = 0;
            for(auto it = digits.begin(); it != digits.end(); ++it) {
                if(*it == 9) {
                    *it = 0;
                    carry = 1;
                }
                else{
                    ++*it; 
                    carry = 0;
                    break;
                }
            }
            if(carry == 1)
                digits.push_back(1);
        
            return *this;
        }
        else {
          
            for(auto it = digits.begin(); it != digits.end(); ++it) {
               
                if(*it == 0) {
                    *it = 9;
                }
                else {
                    --*it;
                    break;
                }
                
                
            }
            
          
            if(digits.back() < 1)
                digits.pop_back();
                
            if(digits.empty()) {
                digits.push_back(0);
                negative = false;
            }
            return *this;
        }
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
        
        if(negative && !rhs.negative) {
            bigint a = *this;
            a.negative = false;
            bigint b = rhs;
            bigint temp = b - a;
            return temp;
        }
        
        if(!negative && rhs.negative) {
            bigint a = *this;            
            bigint b = rhs;
            b.negative = false;
            bigint temp = a - b;
            return temp;
        }
        
        if(!negative && rhs.negative) {
            bigint a = *this;
            a.negative = false;
            bigint b = rhs;
            b.negative = false;
            bigint temp = a + b;
            temp.negative = true;
            return temp;
        }
        
        list<sint>::const_iterator it1 = digits.begin();
        list<sint>::const_iterator it2 = rhs.digits.begin();
        bigint temp;
        sint carry = 0;
        
        while(it1 != digits.end() || it2 != rhs.digits.end()){
            sint a = 0, b = 0;
            if(it1 != digits.end()) a = *(it1++);
            if(it2 != rhs.digits.end()) b = *(it2++);
            sint sum = a + b + carry;
            carry = 0;
            if(sum >= 10) {
                sum %= 10;
                carry = 1;
            }
            
            temp.digits.push_back(sum);
          
        }
        if(carry > 0)
            temp.digits.push_back(carry);
    
        return temp;
    }

    /* TODO: subtract two bigints */
    bigint operator-(const bigint& rhs){
        
        if(!negative && rhs.negative) {
            bigint a = rhs;
            a.negative = false;
            bigint b = *this;
            b.negative = false;
            bigint temp = a + b;
            return temp;
        }
        
        if(negative && !rhs.negative) {
            bigint a = rhs;
            a.negative = false;
            bigint b = *this;
            b.negative = false;
            bigint temp = a + b;
            temp.negative = true;
            return temp;
        }
        
        if(negative && rhs.negative){
            bigint a = *this;
            a.negative = false;
            bigint b = rhs;
            b.negative = false;
            bigint temp =  b - a;
            return temp;
        }
        
        int c = compare(rhs);        

        if(c == 0) return bigint("0");         
   
        list<sint>::const_iterator end1 = digits.end();
        list<sint>::const_iterator end2 = rhs.digits.end();
        list<sint>::const_iterator it1 = digits.begin();
        list<sint>::const_iterator it2 = rhs.digits.begin();
        
        bigint temp;
               
        if(c < 0) 
        {
            temp.negative = true;
            end1 = rhs.digits.end();
            end2 = digits.end();
            it1 = rhs.digits.begin();
            it2 = digits.begin();
        }
               
                
        bool flag = false;
        while(it1 != end1|| it2 != end2){
            sint a = 0, b = 0, carry = 0;
            if(it1 != end1) a = *it1;            
            if(it2 != end2) b = *it2;
            
            if(flag) {
                --a; 
                flag = false;
            }
            
            if(a < b) {
                flag = true;
                carry = 10;
            }
            int sub = carry + a - b;
            if(it1 != end1) ++it1;                    
            if(it2 != end2) ++it2;
            temp.digits.push_back(sub);
        }
        
        
        // remove the preceding zeros if any.
        for(auto it = temp.digits.rbegin(); it != temp.digits.rend(); ++it){
            if(*it == 0) 
                temp.digits.pop_back();
            else break;
        }
    
        
        return temp;
    }
    
    bigint operator*(const bigint& rhs){

        if(*this == "0" || rhs == "0")
            return "0";
       
        bigint temp;
        bigint sum;
        
        int zeros = 0;
        for(auto it1 = digits.begin(); it1 != digits.end(); ++it1){
            uint carry = 0;
            uint a = *it1;
            temp.digits.clear();
            for(auto it2 = rhs.digits.begin(); it2 != rhs.digits.end(); ++it2) {
                uint b = *it2;
                uint c = a * b;
                
                c += carry;
                carry = 0;
                temp.digits.push_back((c % 10));
              
                if(c > 9) 
                    carry = (c - (c % 10)) / 10;                                            
            }
            
             if(carry > 0)
                temp.digits.push_back(carry);
                
            for(int i = 0; i < zeros; ++i)
                temp.digits.push_front(0);
           
            ++zeros;
            sum = sum + temp;
           
        }
       
            
        if(!negative && !rhs.negative) sum.negative = false;
        else if(!negative && rhs.negative) sum.negative = true;
        else if(negative && !rhs.negative) sum.negative = true;
        else sum.negative = false;
        
        return sum;
    }

	friend ostream& operator<<(ostream& os, const bigint& obj) {
        if(obj.negative) os << '-';
		for (list<sint>::const_reverse_iterator i = obj.digits.rbegin(); i != obj.digits.rend(); ++i)
			os << *i;

		return os;
	}
};

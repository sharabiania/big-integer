#include <iostream>
#include <string>

 using std::cout;
 using std::endl;
 using std::string;

template <class type>
void assert(type expected, type actual, string message = "") {
    if(expected != actual) {
        if(message == "")
            cout << " - failed" << endl;
        else
            cout << " - failed: " << message << endl;
    }
    else {
        cout << " - passed" << endl;
    }
}


void compareTest() {
    cout << "# compareTest" << endl;
   
    /// greater than tests
   
    // both negative: same length
    assert(-1, bigint("-12").compare((bigint)"-11"), "both negative, same lenghts, lhs smaller value");
    assert(1, bigint("-11").compare(bigint("-12")), "both negative, same length, lhs bigger value");
    
    // both negative different length
    assert(1, bigint("-9999").compare(bigint("-99999")), "both negative, different lengths, lhs shorter lenght");
    assert(-1, bigint("-988").compare(bigint("98")), "both negative, different lengths, lhs longer.");
    
    // one negative.
    assert(1, bigint("123").compare(bigint("-23")), "one negative with smaller lengths");
    assert(-1, bigint("-129").compare(bigint("192")), "one negatvie same lenghts");
    assert(1, bigint("29").compare(bigint("-123")), "one negative with longer lenght");
    
    // both positive
    assert(1, bigint("19").compare(bigint("2")), "both positive, lhs longer lenght");
    assert(1, bigint("199").compare(bigint("179")), "both positive same lenghts, lhs bigger value");
    assert(-1, bigint("900").compare(bigint("991")), "both positive, same length, lhs smaller value");
    assert(-1, bigint("2").compare(bigint("19")), "both positive, lhs smaller lenght");
    
    // compare with zero.
    assert(1, bigint("0").compare(bigint("-1")), "zero and negative rhs");
    assert(-1, bigint("-1").compare(bigint("0")), "zero and negative lfs");
    assert(1, bigint("1").compare(bigint("0")), "zero and positive");
    assert(0, bigint("00").compare(bigint("0")), "both zeros, different lengths");
    assert(0, bigint("000").compare(bigint("000")), "both zeros, same lenghts");
    
    
}

void increamentTest() {
    
    cout << "# incrementTest" << endl;
    
    /// # prefix increament tests
    
    // zero
    assert(true, ++bigint("0") == bigint("1"), "increment zero");
    assert(true, ++bigint("-1") == bigint("0"), "increment -1");
    
    // positive 
    assert(true, ++bigint("12") == bigint("13"), "increment a positive integer");
    assert(true, ++bigint("1239") == bigint("1240"), "increment positive bigint with 1 carry");
    assert(true, ++bigint("12999") == bigint("13000"), "increment positive bigint with multiple carried.");
    assert(true, ++bigint("999") == bigint("1000"), "increment positive int with carry overflow.");
    
    // negative
    assert(true, ++bigint("-12") == bigint("-11"), "increment negative bigint");
    assert(true, ++bigint("-120") == bigint("-119"), "increment negative with 1 carry");
    assert(true, ++bigint("-1200") == bigint("-1199"), "increment negative with multiple carries");
    assert(true, ++bigint("-1000") == bigint("-999"), "increment negative with reduces length.");
}

void additionTest(){
    
    cout << "# addition test" << endl;
    
    /// zero
    
    assert(bigint("1"), bigint("0") + bigint("1"), "zero and positive rhs");
    assert(bigint("123"),  bigint("123") + bigint("0"), "zero and positive lhs");
    assert(bigint("0"), bigint("0") + bigint("0"), "zero and zero");
    assert(bigint("103"), bigint("103") + bigint("0"), "zero and a positive number including a 0 digit.");
    assert(bigint("199"), bigint("199") + bigint("0"), "zero and a positive number including a 9 digit.");
    
    assert(bigint("-1"), bigint("0") + bigint("-1"), "zero and negative rhs");
    assert(bigint("-123"),  bigint("-123") + bigint("0"), "zero and negative lhs");
    assert(bigint("-103"), bigint("-103") + bigint("0"), "zero and a negative number including a 0 digit.");
    assert(bigint("-199"), bigint("-199") + bigint("0"), "zero and a negative number including a 9 digit.");
    
    
    /// both positive
    
    assert(bigint("12"), bigint("1") + bigint("11"), "both positive, longer lenght lhs");
    assert(bigint("23"), bigint("13") + bigint("10"), "both positive, same lenght lhs");
    assert(bigint("222"), bigint("123") + bigint("99"), "both positive, shorter lenghs lhs, carry");
    assert(bigint("1021"), bigint("922") + bigint("99"), "both positive shorter lenght lhs, carry overflow");
    
    assert(bigint("12"), bigint("11") + bigint("1"), "both positive, shorter lenght lhs");
    assert(bigint("23"), bigint("10") + bigint("13"), "both positive, same lenght lhs");
    assert(bigint("222"), bigint("99") + bigint("123"), "both positive, shorter lenghs lhs, carry");
    assert(bigint("1021"), bigint("99") + bigint("922"), "both positive shorter lenght lhs, carry overflow");
    
    /// TODO: one negative
    
    /// TODO: both negative
}
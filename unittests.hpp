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
   
    /// operator> tests
   
    // both negative: same length
    assert(false, (bigint)"-12" > (bigint)"-11", "both negative, same lenghts, lhs smaller value");
    assert(true, bigint("-11") > bigint("-12"), "both negative, same length, lhs bigger value");
    
    // both negative different length
    assert(true, bigint("-9999") > bigint("-99999"), "both negative, different lengths, lhs shorter lenght");
    assert(false, bigint("-988") > bigint("98"), "both negative, different lengths, lhs longer.");
    
    // one negative.
    assert(true, bigint("123") > bigint("-23"), "one negative with smaller lengths");
    assert(false, bigint("-129") > bigint("192"), "one negatvie same lenghts");
    assert(true, bigint("29") > bigint("-123"), "one negative with longer lenght");
    
    // both positive
    assert(true, bigint("19") > bigint("2"), "both positive, lhs longer lenght");
    assert(true, bigint("199") > bigint("179"), "both positive same lenghts, lhs bigger value");
    assert(false, bigint("900") > bigint("991"), "both positive, same length, lhs smaller value");
    assert(false, bigint("2") > bigint("19"), "both positive, lhs smaller lenght");
    
    // compare with zero.
    assert(true, bigint("0") > bigint("-1"), "zero and negative");
    assert(true, bigint("1") > bigint("0"), "zero and positive");
    assert(false, bigint("00") > bigint("0"), "both zeros, different lengths");
    assert(false, bigint("000") > bigint("000"), "both zeros, same lenghts");
    
    
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
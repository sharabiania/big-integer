#include <iostream>
#include <string>
#include <vector>

 using std::cout;
 using std::endl;
 using std::string;
 using std::vector;

template <class type>
void assert(type expected, type actual, string message = "") {
    if(expected != actual) {
        cout << " - failed: ";
        if(message != "")                
            cout << message;
            
        cout << " - [expected: "<< expected << ", actual: " << actual << "]" << endl;
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

void subtractionTest() {
    
    /// TODO: zero
    
    /// both positive
    assert(bigint("111"), bigint("321") - bigint("210"), "both positive, same length, bigger lhs");
    assert(bigint("-111"), bigint("210") - bigint("321"), "both positive, same length, smaller lhs");
    assert(bigint("199"), bigint("323") - bigint("124"), "both positive, same length, carry");
    assert(bigint("99"), bigint("223") - bigint("124"), "both positive, same length, carry overflow");
    assert(bigint("100"), bigint("123") - bigint("23"), "both positive, longer lhs");
    assert(bigint("893"), bigint("923") - bigint("30"), "both positive, longer lhs, carry");
    assert(bigint("24"),  bigint("123") - bigint("99"), "both positive, longer lhs, carry overflow");
    assert(bigint("-100"), bigint("23") - bigint("123"), "both positive, shorter lhs");
    assert(bigint("-893"), bigint("30") - bigint("923"), "both positive, shorter lhs, carry");
    assert(bigint("-24"),  bigint("99") - bigint("123"), "both positive, shorter lhs, carry overflow");
    
    // TODO: one negative
    assert(bigint("357"), bigint("234") - bigint("-123"), "rhs negative, same length");
    assert(bigint("-357"),bigint("-123") - bigint("234"), "lhs negative, same length");
    assert(bigint("-310"), bigint("-123") - bigint("187"), "rhs negative, same length, carry");
    assert(bigint("310"), bigint("123") - bigint("-187"), "lhs negative, same lenght, carry");
    assert(bigint("-1110"), bigint("-123") - bigint("987"), "rhs negative, same length, carry overflow");
    assert(bigint("1110"), bigint("123") - bigint("-987"), "lhs negative, same lenght, carry overflow");
    assert(bigint("1010"), bigint("923") - bigint("-87"), "lhs negative, longer lhs, carry overflow");
    assert(bigint("210"), bigint("23") - bigint("-187"), "lhs negative, longer lhs, carry");
    
    // TODO: both negative
    assert(bigint("0"), bigint("-123") - bigint("-123"), "both negative, same length");
}

void multiplicationTest() {
    
    cout << "# multiplication test" << endl;
    
    std::vector<std::vector<std::string>> testingData = {
        {"5", "0", "0", "one zero, same length"},
        {"123", "0", "0", "one zero, different lengths"},
        {"0", "0", "0", "both zeros, same length"},
        {"1", "123", "123", "multiply by 1"},
        {"12", "11", "132", "same length"},        
        {"56", "24", "1344", "same length, carry overflow"},
        {"123", "3", "369", "lhs longer"},
        {"3", "123", "369", "rhs longer"},
        {"456", "2", "912", "different length, carry"},
        {"1234", "45", "55530", "different length, carry overflow"},
        {"12345679", "72", "888888888", "lhs longer, carry overflow"},
        {"9", "12345679", "111111111", "rhs longer, carry overflow"},
        {"-21", "2", "-42", "lhs negative"},
        {"22", "-3", "-66", "rhs negative"},
        {"-32", "-20", "640", "both negative"}
    };
   
   for(int i = 0; i < testingData.size(); ++i) {
   
        assert(
        bigint(testingData[i][2].c_str()), 
        bigint(testingData[i][0].c_str()) * bigint(testingData[i][1].c_str()),
        testingData[i][3]);       
   
   }
   
}
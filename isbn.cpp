// Damaris Garcia
// ISBN Check for 10 digit values
// Confirm correct values with: http://www.isbn-check.com/
// 2 Oct 2015
// Assignment to read code, modify as required and collaborate.

// CSS-1 HW due 8 Oct
// Correct functions for ISBN10 and ISBN13 are listed below
// Add two new tests each for ISBN10 and ISBN13 which pass
// Issue git commit
// Add two new tests each or ISBN10 and ISBN13 which fail
// Issue git commit
// Add your name to line 1, "Joe Welch, and xxxxxxx"
// Issue git commit
// Change the user.name and user.email to your name and email
// Issue git commit
// Issue git push to your GitHub account

#include <iostream>
#include <typeinfo>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cassert>
using namespace std;

// must use these two functions
int sumISBN10Digits(string val);
int sumISBN13Digits(string val);

// you may use or discard these functions
int charToInt(char ch);
bool isValidISBN10(int val);
bool isValidISBN13(int val);

int main()
{

    string strA = "0385353308";      // test case for ISBN10
    string strA1 = "1587133253";
    string strA2 = "1444444449";
    string strA3 = "1290864041";
    string strB = "9780136091813";   // test case for ISBN13
    string strB1 = "9781587133282";
    string strB2 = "1862400927134";
    string strB3 = "2763334890127";
    
    if(sumISBN10Digits(strA) % 11 == 0)
    {
        cout << "Is valid" <<endl;
    }
    
    //These are test for ISBN10
    assert(sumISBN10Digits(strA) % 11 == 0); //assert pass
    assert(sumISBN10Digits(strA1) % 11 == 0); //assert pass
    assert(sumISBN10Digits(strA2) % 11 != 0); //assert fail
    assert(sumISBN10Digits(strA3) % 11 != 0); //assert fail
    
    //These are tests for ISBN13
     assert(sumISBN13Digits(strB) % 10 == 0); //assert pass
     assert(sumISBN13Digits(strB1) % 10 == 0); //assert pass
     assert(sumISBN13Digits(strB2) % 10 != 0); //assert fail
     assert(sumISBN13Digits(strB3) % 10 != 0); //assert fail
  
    
        
    
    
    
      
    return 0;
    
}// end main()

// ****************************
int sumISBN10Digits(string val)
{
    int sum = 0;
    int num;
    
    // Sum : positional value x digit value, except rightmost digit (may be 'X')
    for(int ix = 0; ix < val.length() - 1 ; ix++)
    {
        num = charToInt(val.at(ix) ) * (10 - ix);
        sum += num;       
    }// end for
    
    // account for case if rightmost digit is an 'X'
    if( (val.at(9) == 'X'))
    {
        num = 10;
    }
    else
    {
        num = charToInt(val.at(val.length() - 1) );
    }
    sum += num;
    
    return sum;
}// endl;

// ***************************
int charToInt(char ch)
{
    return (int(ch) - 48);

}// charToInt(char ch)

// ****************************
bool isValidISBN10(int val)
{
    if ((val % 11) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }       

}//end bool isValid(int val)

// ******************************
int sumISBN13Digits(string val)
{
    int sum = 0;
    int p;
    int num;
    
    for(int ix = 0; ix < val.length() ; ix++)
    {
        p = charToInt(val.at(ix) ) ;
        
        if (( ix % 2) == 0)
        {
            num = p;
        }
        else
        {
            num = 3 * p;
         }
    
       sum += num;
    }//end for()
    return sum;

}// int sumISBN13Digits(string val)

// **********************************
bool isValidISBN13(int val)
{
    if ((val % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}// end bool isValidISBN13(int val)

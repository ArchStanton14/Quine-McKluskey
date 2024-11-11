//Nathaniel Stanford
//10-31-2024
//declarations for Logic object for QM
#ifndef LOGIC_
#define LOGIC_

#include <unordered_set>//order doesn't matter
#include <string>
#include <vector>
class Logic{
    public:
        /*Default constructor*/
        Logic();
        /*Parameterized constructor
        *   @param expression the logical expression
        */
        Logic(std::string const &expression);

        /*
        * @return minterms of the function
        */
        //std::unordered_set<int> getminterms() const;
        std::vector<std::string> getminterms() const;
        /*
        * @param new minterms
        * @post sets new minterms
        */

        std::vector<std::string> setminterms( std::vector<std::string> terms);
        /*
        * @return Maxterms of the function
        */
        
        //std::unordered_set<int> getMaxterms() const;
        std::vector<std::string> getMaxterms() const;
        
        /*
        * generates min and max terms from the expression
        * @post sets the minterms and maxterms
        */

        void getTerms();

        /*
        * uses Quine Mckluskey to simplify function
        * @post sets the expression to the simplified version
        */

        void QM();
        
        /*
        * counts the number of 1s in a binary string
        * @return the number of ones as a int
        */
        int countOnes(std::string s);
        //later add function to get/set notation and symbology
    private:
        //std::unordered_set<int> minterms;   //the minterms of the function (binary numbers)
        //std::unordered_set<int> Maxterms;   //the Maxterms of the function (binary numbers)
        std::vector<std::string> minterms; // the minterms of the function as binary strings
        //std::vector<std::string> Maxterms; // the Maxterms of the function as binary strings        
        int size;   //the number of possible terms for the variable number
        //std::string expression; //the function expression
        //later add member for infix/postfix/prefix notation
        //later add member for symbology (+,^,*,etc)
        std::string bitDifference(std::string str1, std::string str2);  //auxilary function to compare single bit differences
        
};
#endif
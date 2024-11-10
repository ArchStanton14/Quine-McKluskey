//Nathaniel Stanford
//10-31-2024
//declarations for Logic object for QM
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

        //later add function to get/set notation and symbology
    private:
        //std::unordered_set<int> minterms;   //the minterms of the function (binary numbers)
        //std::unordered_set<int> Maxterms;   //the Maxterms of the function (binary numbers)
        std::vector<std::string> minterms; // the minterms of the function as binary strings
        std::vector<std::string> Maxterms; // the Maxterms of the function as binary strings        
        std::string expression; //the function expression
        //later add member for infix/postfix/prefix notation
        //later add member for symbology (+,^,*,etc)
        std::string bitDifference(std::string str1, std::string str2);  //auxilary function to compare single bit differences

};
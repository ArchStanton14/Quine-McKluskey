//Nathaniel Stanford
//10-31-2024
//declarations for Logic object for QM
#include <unordered_set>//order doesn't matter
#include <string>
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
        std::unordered_set<int> getminterms() const;
        
        /*
        * @return Maxterms of the function
        */
        
        std::unordered_set<int> getMaxterms() const;

        /*
        * uses Quine Mckluskey to simplify function
        * @post sets the expression to the simplified version
        */

        void QM();

        //later add function to get/set notation and symbology
    private:
        std::unordered_set<int> minterms;   //the minterms of the function 
        std::unordered_set<int> Maxterms;   //the Maxterms of the function
        std::string expression; //the function expression
        //later add member for infix/postfix/prefix notation
        //later add member for symbology (+,^,*,etc)

};
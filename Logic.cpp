
#include "Logic.hpp"
/*Default constructor*/
Logic::Logic(){

}
/*Parameterized constructor
*   @param expression the logical expression
*/
Logic::Logic(std::string const &expression){
    this->expression = expression;
}

/*
* @return minterms of the function
*/
//std::unordered_set<int> Logic::getminterms() const{
std::vector<std::string> Logic::getminterms() const{
    return minterms;
}

/*
* @return Maxterms of the function
*/

//std::unordered_set<int> Logic::getMaxterms() const{
std::vector<std::string> Logic::getMaxterms() const{
    return Maxterms;
}


/*
* generates min and max terms from the expression
* @post sets the minterms and maxterms
*/

void getTerms(){
    
}

/*
* uses Quine Mckluskey to simplify function
* @post sets the expression to the simplified version
*/

void Logic::QM(){
   //arrange by single bit differences
   //look for additional bit differences
   for (int i = 0; i < minterms.size() - 1; i++){
        minterms.insert(minterms.begin(), bitDifference(minterms[i], minterms[i + 1]));
        minterms.erase(minterms.begin() + i + 1);
        minterms.erase(minterms.begin() + i + 2);   //very inneficient

   }
   //what's the base case? 
}

std::string bitDifference(std::string str1, std::string str2){
    //probably easier to do this mathematically
}

/*
std::unordered_set<int> minterms;   //the minterms of the function 
std::unordered_set<int> Maxterms;   //the Maxterms of the function
std::string expression; //the function expression
*/
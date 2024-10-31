
#include "Logic.hpp"
/*Default constructor*/
Logic::Logic(){

}
/*Parameterized constructor
*   @param expression the logical expression
*/
Logic::Logic(std::string const &expression){

}

/*
* @return minterms of the function
*/
std::unordered_set<int> Logic::getminterms() const{

}

/*
* @return Maxterms of the function
*/

std::unordered_set<int> Logic::getMaxterms() const{

}

/*
* uses Quine Mckluskey to simplify function
* @post sets the expression to the simplified version
*/

void Logic::QM(){

}


std::unordered_set<int> minterms;   //the minterms of the function 
std::unordered_set<int> Maxterms;   //the Maxterms of the function
std::string expression; //the function expression


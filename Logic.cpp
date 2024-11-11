
#include "Logic.hpp"
#include <iostream>
/*Default constructor*/
Logic::Logic(){

}
/*Parameterized constructor
*   @param expression the logical expression
*/
/*
Logic::Logic(std::string const &expression){
    this->expression = expression;
}
*/
/*
* @return minterms of the function
*/
//std::unordered_set<int> Logic::getminterms() const{
std::vector<std::string> Logic::getminterms() const{
    return minterms;
}

std::vector<std::string> Logic::setminterms(std::vector<std::string> terms){
    minterms = terms;
}

/*
* @return Maxterms of the function
*/
/*
//std::unordered_set<int> Logic::getMaxterms() const{
std::vector<std::string> Logic::getMaxterms() const{
    return Maxterms;
}
*/

/*
* generates min and max terms from the expression
* @post sets the minterms and maxterms
*/

void getTerms(){
    
}

int countOnes(std::string s){
    int count  = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '1'){
            count++;
        }
    }
    return count;
}

/*
* uses Quine Mckluskey to simplify function
* @post sets the expression to the simplified version
*/

void Logic::QM(){
    //create columns based on size
    std::vector<std::vector<std::string>> columns;
    for (int i = 0; i < size; i++){
            columns.push_back({});
            for(int j = 0; j < minterms.size(); j++){
                /*  //can't figure out why this causes an error  
                if (countOnes(minterms[j]) == i){       //can be made more efficient by taking the ones count once and attaching it to the minterm
                    columns[i].push_back(minterms[j]);
                }
                */
            }
            //temporary, for testing
            columns[i].push_back(minterms[i]);
        }
    int count = 0;
    int previousCount = 0;
    //while total size is getting smaller
    while (previousCount > count){
        std::cout << "\n count: " << count << " previouscount: " << previousCount;
        std::vector<std::vector<std::string>> changed;
        //bitDifference compare each term to every term in adjacent columns
        for (int i = 0; i < columns.size() - 1; i++){
            std::vector<std::string> v1;
            std::vector<std::string> v2;
            for (int j = 0; j < columns[i].size(); j++){
                for (int k = 0; k < columns[i + 1].size(); k++){
                    std::cout << "\n i: " << i << " j: " << j << " k: " << k << std::endl << "col1: " << columns[i][j] << " col2: " << columns[i+1][k] << " Bitdifference: " << bitDifference(columns[i][j], columns[i + 1][k]);
                    
                    if (bitDifference(columns[i][j], columns[i + 1][k]) != ""){
                        //check which column the new term should go in to
                        //remove columns?
                            
                            //add combined implicate to both columns
                            v1.push_back(bitDifference(columns[i][j], columns[i + 1][k]));
                            v2.push_back(bitDifference(columns[i][j], columns[i + 1][k]));
                            //columns[i][j] = bitDifference(columns[i][j], columns[i + 1][k]);
                            //can't erace combined implcates yet because they might have to combine further.
                            //columns[i + 1].erase(columns[i + 1].begin() + k);
                    }
                    else{
                        v1.push_back(columns[i][j]);
                        v2.push_back(columns[i + 1][k]);
                    }
                }
            }
           // changed[i] += v1;
           // changed[i+1] += v2;
           changed[i].insert(changed[i].end(), v1.begin(), v1.end());   //adds the changed values to a new vector so we can still continue combining the old values
           changed[i + 1].insert(changed[i + 1].end(), v2.begin(), v2.end());
        }
        columns = changed;  //now we change to the new combined terms

        //recalculate the size to see if we're done
        previousCount = count;
        count = 0;
        for (int i = 0; i < columns.size(); i++){
            count += columns[i].size();
        }
    }
    //what's the base case? 
}

std::string bitDifference(std::string str1, std::string str2){
    //probably easier to do this mathematically
    int diff = 0;
    std::string out = "";
    for (int  i = 0; i < str1.length(); i ++){
        if (str1[i] != str2[i]){
            out += 'X';
            diff += 1;
        }
        else{
            out += str1[i];
        }
    }
    if (diff > 1){
        return "";
    }
    else{
        return out;
    }
}


/*
int main(){
    std::cout << bitDifference("1101", "1111");
}


std::unordered_set<int> minterms;   //the minterms of the function 
std::unordered_set<int> Maxterms;   //the Maxterms of the function
std::string expression; //the function expression
*/
#include "cpu.h"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <vector>
using namespace std;

/**
 * @brief Construct a new CPU object
 * @param value stack value
 */
CPU::CPU(){}

/**
 * @brief operator << for out to console                                                            
 * @param out ostream object
 * @param cpu CPU object
 * @return ostream& an ostream object
 */
ostream &operator<<(ostream& out, CPU& cpu){
     //out << "Stack: ";
 cout<<cpu.currStack[0];
 for (int i = 1; i <= cpu.currStack.size() - 1; i++) {
   out << ", " << cpu.currStack[i];
 }
 return out;
}

/**
 * @brief loads a program stored in the filename location. 
 * Ensures that the stack is empty and any previous program 
 * is removed.
 * @param filename file contaning stack 
 */
void CPU::LoadProgram(string filename){
    tempStack.clear();
    currStack.clear();
    ifstream MyReadFile(filename);
    string myText;
    // Use a while loop together with the getline() 
    //function to read the file line by line
    while (getline (MyReadFile, myText)) {
            tempStack.push_back(myText);
    }
    MyReadFile.close();
}

/**
 * @brief pushes values into the stack
 * @param psh 
 * @return true if push was successful
 * @return false if push was unseccessful
 */
bool CPU::PSH(string psh){
    //using stringstream to convert string to int
    stringstream ss (psh); 
    int x = 0;
    ss >> x;
    currStack.push_back(x);
    return true;
}

/**
 * @brief pops the top two values from the stack
 * @param val1 
 * @param val2 
 * @return true 
 * @return false 
 */
void CPU::POP(int& val){
    val = currStack[currStack.size()-1];
    //pop first value
    currStack.pop_back();
}

/**
 * @brief  runs the next line of the program and returns 0. 
 * If there are no more lines it returns -1.
 * @return int 0 or -1 depending 
 */
int CPU::Next(){
    //returns -1 if there are no more lines
    if(tempStack.size() == 0){
        return -1;
    }
   
    string  top = *tempStack.begin();
    tempStack.erase(tempStack.begin());
    string line = top;
    //array to keep track of what is in file 
    string arr[3];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 3){
        //arr[0] holds the first string.
        //arr[1] holds the second string.
        ssin >> arr[i];
        ++i;
    }
    string operation = arr[0];  
    //doing the following operations depending 
    //on the string in operation (arr[0]).
    if(operation == "ADD" ){
        ADD();
    }if(operation == "MULT"){
        MULT();
    }
    if(operation == "SUB"){
        SUB();   
    }
    if(operation == "DIV"){
        DIV();
    }
     if(operation == "PSH"){
        PSH(arr[1]);
    }
     if(operation ==  "CMP" ){
        CMP();
    }
    //returns 0 when next() is finished
    return 0;
}

/**
 * @brief Pops the top two values from the stack and 
 * pushes the sum of them onto the stack
 * @return int sum of two top values
 */
void CPU::ADD(){
    int val1;
    int val2;
    if(currStack.size() >= 2){
        //pops top two value from the stack 
        POP(val1);
        POP(val2);
        currStack.push_back(val1 + val2);//sum
    }
    // else {
    //     throw runtime_error("stack size is less than 2");
    // }
}

/**
 * @brief Pops the top two values from the stack and pushes 
 * the product of them onto the stack
 * @return int product of two top values
 */
void CPU::MULT(){
    int val1;
    int val2;
    if(currStack.size() >= 2){
        POP(val1);
        POP(val2);
        currStack.push_back(val1 * val2);//product
    }
    // else {
    //     throw runtime_error("stack size is less than 2");
    // }
}

/**
 * @brief Pops the top two values from the stack 
 * and pushes the difference of the second value minus 
 * the first onto the stack
 * @return int difference of two top values 
 */
 void CPU::SUB(){
    int val1;
    int val2;
    if(currStack.size() >= 2){
        POP(val1);
        POP(val2);
        currStack.push_back(val2-val1);//difference
    }
    // else {
    //     throw runtime_error("stack size is less than 2");
    // }
}

/**
 * @brief Pops the top two values from the stack and pushes 
 * the second value divided by the first onto the stack 
 * (note: only the integer portion).  
 * Div by 0 should throw an error.
 * @return int 
 */
void CPU::DIV(){
    int val1;
    int val2;
    if(val1 == 0){
        throw runtime_error("cannot divide by 0!");
    }
    if(currStack.size() >= 2){
        POP(val1);
        POP(val2);
        currStack.push_back(val2 / val1);//divides
    }
    // else {
    //     throw runtime_error("stack size is less than 2");
    // }
}

/**
 * @brief Pops the top two values from the stack.  
 * If the first is greater than the second, push 1.  
 * If they are equal, push 0, if the second is greater 
 * than the first, push -1 
 * @return true
 * @return false 
 */
void CPU::CMP(){

    int val1;
    int val2;
    if(currStack.size() >= 2){ 
        POP(val1);
        POP(val2);
        if(val1 > val2){
        currStack.push_back(1);
        }
        if(val1 == val2){
            currStack.push_back(0);
        }
        if(val2 > val1){
            currStack.push_back(-1);
        }
    }
    // else {
    //     throw runtime_error("stack size is less than 2");
    // }
}

/**
 * @brief runs the entire program and returns the final value 
 * (the only one left in the stack).  If there is more than 
 * one value in the stack, throw an error.
 */
 int CPU::Run(){
     while(Next() == 0 );
     return currStack[0];
     if(currStack.size() > 1){
        throw runtime_error("stack must have only one value remaining!");
     }
}

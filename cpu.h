#ifndef _ASSIGNMENT3
#define _ASSIGNMENT3
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

class CPU{
    private:
    //items loaded from the files
    vector<string> tempStack;
    //items to pop from the stack
    vector<int> currStack;
    
    public:
        /**
         * @brief Construct a new CPU object
         * @param value stack value
         * @param value 
         */
        CPU();
        friend ostream& operator<<(ostream& out, CPU& cpu);
        /**
         * @brief loads a program stored in the filename location. 
         * Ensures that the stack is empty and any previous 
         * program is removed.
         * @param filename file containing stack
         * @param filename 
         */
        void LoadProgram(string filename);

        /**
         * @brief runs the entire program and returns
         * the final value (the only one left on the stack
         * @return int last remaining value 
         */
        int Run();

        /**
         * @brief runs the next line of the program
         * and returns 0. if there are no more line
         * it will return -1
         * @return int 0 or -1 depending 
         */
        int Next();

        /**
         * @brief Pushes values into the stack
         * @return true if the push was successful
         * @return false if the push was unsuccessful
         */
        bool PSH(string psh);
        
        /**
         * @brief pops values from the stack
         * @param pop value to pop
         * @return true if successful
         * @return false is unseccessful
         */
        void POP(int& val);
        /**
         * @brief pops the tops two values from the stack
         * and pushes the sum of them onto the stack
         * @return int the sum 
         */
        void ADD();

        /**
         * @brief pops the tops two values from the stack
         * and pushes the product of them onto the stack
         * @return int the product 
         */
        void MULT();

        /**
         * @brief pops the top two values from the stack
         * and pushes the difference of the second value 
         * minus the first value onto the stack 
         * @return int the difference 
         */
        void SUB();

        /**
         * @brief pops the two values from the stack
         * and pushes the second values divided by the 
         * first onto the stack. (only integer division)
         * Divide by 0 will throw an error.
         * @return int division 
         */
        void DIV();

        /**
         * @brief pops the top two elements from from 
         * the stack. If the first is greater than the 
         * second, pushes 1. If they are equal, pushes 0. 
         * if the second is greater than the first, pushes
         * -1
         * @return true 
         * @return false 
         */
        void CMP();

};
#endif
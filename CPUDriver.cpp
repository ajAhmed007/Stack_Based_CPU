#include<iostream>
#include "cpu.h"

using namespace std;

int main () {

	CPU myCPU;

	myCPU.LoadProgram("Prog1.asm");
	cout << myCPU.Run() << endl;
	myCPU.LoadProgram("Prog1.asm");
	while (myCPU.Next() == 0) {
		cout << myCPU << endl;
	}
	cout << endl;
		
	myCPU.LoadProgram("Prog2.asm");
	cout << myCPU.Run() << endl;
	myCPU.LoadProgram("Prog2.asm");
	while (myCPU.Next() == 0) {
  		cout << myCPU << endl;
	}
	cout << endl;
	
	return 0;
}
		

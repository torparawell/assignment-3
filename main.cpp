#include "GenStack.h"
#include "Assignment-3.h"

int main (int argc, char *argv[]) {
    // Creates an instance of the RunChecker class. 
    RunChecker *run = new RunChecker();
    // Runs the runProgram in the RunChecker Class.
    run->runProgram();
    
    delete run; // Garbage collection.
    return 0;
}
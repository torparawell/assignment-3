#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
class RunChecker {
  public: 
    void runProgram(); // Runs the program and all user interactions.
};
class FileIO {
  public:
    string readFile(string filename, int lineCountNumber); // Reads from the file.
    int getNumberOfLines(string filename); // Gets the number of lines in the file. 
};
class SyntaxChecker {
  public:
    bool checkSyntax(string line, int lineNumber, int fileLineCount); // Checks the syntax of the file.
};
#include "Assignment-3.h"

void RunChecker::runProgram() {
   // Declaration of Variables
   bool goodSyntax = true;
   bool playAgain = true;  
   
   string filename;
   string line;
   char response;

   int totalFileLines;
   // Create objects for the classes
   FileIO *f = new FileIO();
   SyntaxChecker *s = new SyntaxChecker();

   // While the user wants to play again and the syntax is good.
   while (goodSyntax == true && playAgain == true) {
       cout << "Enter a file to check the syntax: ";
       cin >> filename;
       totalFileLines = f->getNumberOfLines(filename); // Gets the total number of lines in the file (starting at 0)
       for (int currentLine = 0; currentLine < totalFileLines; ++currentLine) {
           line = f->readFile(filename, currentLine); // Reads file
           goodSyntax = s->checkSyntax(line, currentLine, totalFileLines); // Checks the files syntax.
       }
       if (goodSyntax) {
           bool validResponse = false; // Valid response is current false.
           while (!validResponse) {
                cout << "Do you want to play again? (Y/N): " << endl;
                cin >> response;
                if (toupper(response) == 'Y') { // User wants to play again
                    validResponse = true;
                    playAgain = true;
                }
                else if (toupper(response) == 'N') { // User does not want to play again.
                    validResponse = true;
                    playAgain = false;
                }
                else {
                    cout << "Bad input, try again." << endl;
                }
            }
       }
   }
   delete f;
   delete s;
}
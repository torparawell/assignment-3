#include "Assignment-3.h"
#include "GenStack.h"


bool SyntaxChecker::checkSyntax(string line, int lineNumber, int fileLineCount) {
    GenStack<char> stack(128); // Creates a genstack that can hold up to 128 characters.
    //cout << line << endl; 

    for (int index = 0; index < line.length(); ++index) {
        if (line[index] == '(' || line[index] == '[' || line[index] == '{' || line[index] == ')' || line[index] == ']' || line[index] == '}') {
            // All good conditions
            if (stack.peek() == '(' && line[index] == ')') {
                stack.pop();
            }
            else if (stack.peek() == '[' && line[index] == ']') {
                stack.pop();
            }
            else if (stack.peek() == '{' && line[index] == '}') {
                stack.pop();
            }
            
            // In the case of '(' not equaling ')'
            else if (stack.peek() == '(' && line[index] == '}') {
                cout << "Line " << lineNumber + 1 << ": Expected ')' and found '}'" << endl;
                stack.pop();
                return false;
            } 
            else if (stack.peek() == '(' && line[index] == ']') {
                cout << "Line " << lineNumber + 1 << ": Expected ')' and found ']" << endl;
                stack.pop(); 
                return false;
            } 

            // In the case of '[' not equaling ']'
            else if (stack.peek() == '[' && line[index] == ')') {
                cout << "Line " << lineNumber + 1 << ": Expected ']' and found ')'" << endl; 
                stack.pop();
                return false;
            } 
            else if (stack.peek() == '[' && line[index] == '}') {
                cout << "Line " << lineNumber + 1 << ": Expected ']' and found '}'" << endl; 
                stack.pop();
                return false;
            } 

            // In the case of '{' not equaling '}'
            else if (stack.peek() == '{' && line[index] == ')') {
                cout << "Line " << lineNumber + 1 << ": Expected '}' and found ')'" << endl; 
                stack.pop();
                return false;
            }
            else if (stack.peek() == '{' && line[index] == ']') {
                cout << "Line " << lineNumber + 1 << ": Expected '}' and found ']'" << endl; 
                stack.pop();
                return false;
            } 
            else {
                if (line[index] == '(' || line[index] == '[' || line[index] == '{' )
                    stack.push(line[index]);
            }
        }
    }
    if (lineNumber == fileLineCount-1) { //When it reaches the end of a file.
        if (stack.isEmpty()) {
            cout << "Delimiter Syntax is Correct." << endl;
            return true;
        }
        while (!stack.isEmpty()) {
            char missingParameter = stack.pop();
            cout << "Reached end of file: Missing " << missingParameter << endl;
        }

    }
    return true;
}
#include "Assignment-3.h"

string FileIO::readFile(string filename, int currentLineNumber) {
    // Readsfile
    fstream newfile;
    int lineCount = 0;
    string line; // String line
    newfile.open(filename,ios::in); // Opens a file
        if (newfile.is_open()){ //Opening file.
            string currentLine;
            while(getline(newfile, currentLine)){
                if (currentLineNumber == lineCount) {
                    line = currentLine;
                    break;
                }
                else {
                    lineCount++;
                }
            }
        }
    // Returns the current line.
    return line;
}

int FileIO::getNumberOfLines(string filename) {
    fstream newfile;
    int lineCount = 0;
    newfile.open(filename,ios::in); // Opens the file
        if (newfile.is_open()) {
            string cl;
            while(getline(newfile, cl)) {
                lineCount++; // Adds to linecount for each line.
            }
        }
    // Returns the line count.
    return lineCount;
}
#include <iostream>
#include <string>
using namespace std;

// TODO: write the function here
void replaceLetters(string findThis, string replace, string &phrase) {
    int index = phrase.find(findThis); // Start by finding the first occurrence

    // Loop while there are still instances of findThis in phrase
    while (index != string::npos) {
        phrase.replace(index, findThis.length(), replace); // Replace substring
        index = phrase.find(findThis, index + replace.length()); // Find next occurrence
    }
}




// Driver program to test the function
// You don't have to change any of this code
int main() {
    
    cout << "Type some words and hit enter." << endl;
    string someWords;
    getline(cin,someWords);

    cout << "What string do you want to find?" << endl;
    string whatToFind;
    getline(cin,whatToFind);

    cout << "What do you want to replace it with?" << endl;
    string whatToReplace;
    getline(cin,whatToReplace);

    replaceLetters(whatToFind, whatToReplace, someWords);

    cout << "Here's your new words!" << endl;
    cout << someWords << endl;


}
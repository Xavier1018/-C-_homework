#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string Replace(string input) {
    stringstream ss(input);
    string word;
    string result = "";
    char punct;

    while (ss >> word) {
        punct = word.back(); // Get the last character (possible punctuation)
        if (ispunct(punct)) {
            word.pop_back(); // Remove punctuation from the word
        }
        if (word.length() == 4) {
            if (isupper(word[0])) {
                result += "Love";
            }
            else {
                result += "love";
            }
        }
        else {
            result += word;
        }
        // Add back punctuation if it existed
        if (ispunct(punct)) {
            result += punct;
        }
        result += " "; // Add space after each word
    }

    return result;
}


int main() {
    string input;
    char choice;

    do {
        cout << "Enter a line of text: ";
        getline(cin, input);

        // Replace four-letter words with "love"
        string output = Replace(input);
        cout << "Output: " << output << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

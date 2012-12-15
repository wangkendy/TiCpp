// hangman_game.cpp
// Create a kind of "hangman" game. Create a class that contains a char and a
// bool to indicate whether that char has been guessed yet. Randomly select a 
// word from a file, and read it into a vector of your new type. Repeatedly 
// ask the user for a character guess, and after each guess disply the
// characters in the word that have been guessed, and underscores for the
// characters that haven't. Allow a way for the user to guess the whole word.
// Decrement a value for each guess, and if the user can get the word before
// the value goes to zero, they win.
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Character {
    char ch_;
    bool guessed_;
public:
    Character(char ch) : ch_(ch), guessed_(false) {}
    bool is_guessed() { return guessed_; }
    char ch() { 
        if (guessed_)
            return ch_;
        else
            return '_';
    }
    bool guess(char ch) {
         if (ch == ch_) {
             guessed_ = true;
             return true;
         }
         return false;
    }
};

int main(int argc, char* argv[])
{
    // TODO: random select a word from file
    string word = "apple";
    vector<Character> vc;
    for (int i = 0; i < word.size(); i++)
        vc.push_back(Character(word[i]));

    // TODO: Decrement a value for each value
    char ch;
    while (true) {
        cout << "Input your guess:";
        cin >> ch;
        for (int i = 0; i < vc.size(); i++)
            if (!vc[i].is_guessed() && vc[i].guess(ch))
                break;

        int count = 0;
        for (int i = 0; i < vc.size(); i++) {
            if (vc[i].is_guessed())
                count++;
            cout << vc[i].ch();
        }
        cout << endl;
        if (count == vc.size()) {
            cout << "Congratulations!!" << endl;
            break;
        }
    }
    return 0;
}

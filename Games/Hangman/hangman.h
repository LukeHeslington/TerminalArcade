#ifndef HANGMAN_H
#define HANGMAN_H

#include <vector>

class Hangman
{
private:
    int incorrectGuesses;
    char word[100];
    int correctGuesses;
    std::vector<char> guessedLetters;
    char guess;
    char playAgain;

public:
    Hangman();
    ~Hangman();
    void play();
    void choose_random_word_and_setup();
    void print_hangman_image(int guesses);
};





#endif

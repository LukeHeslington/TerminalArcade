#include "hangman.h"
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>


Hangman::Hangman()
{
}

Hangman::~Hangman()
{
}

void Hangman::play()
{
    // 1. Choose a random word.
    choose_random_word_and_setup();

    // 2. Display the word as underscores.

    incorrectGuesses = 0;
    correctGuesses = 0;
    guessedLetters.clear();
    playAgain = 'y';
    
    //std::cout << "\033[25;1H"; // Move cursor to the bottom


    while(true){
        //std::cout << "\033[25;1H";
        system("clear");

        print_hangman_image(incorrectGuesses);

        std::cout << std::endl << std::endl << std::endl;
        for (int i = 0; i < strlen(word); i++)
        {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), word[i]) != guessedLetters.end()) {
                std::cout << word[i];
            }
            else
            {
                std::cout << "_";
            }
        
        }

        if (correctGuesses == strlen(word))
        {
            std::cout << "\nYou won!" << std::endl;
            std::cout << "Would you like to play again? (y/n): ";
                std::cin >> playAgain;
                if (playAgain == 'y')
                {
                    guessedLetters.clear();
                    incorrectGuesses = 0;
                    correctGuesses = 0;
                    choose_random_word_and_setup();
                    continue;
                }
                else
                {
                    std::cout << "Thanks for playing!" << std::endl;
                    break;
                }
        }

        std::cout << "\n" << std::endl;

        //std::cout << "The word is: " << word << std::endl;
        //std::cout << "incorrectGuesses = " << incorrectGuesses << std::endl;
        std::cout << "Guess a letter: ";

        //while guess is already in guessedLetters
        while (true)
        {
            std::cin >> guess;
            if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end())
            {
                std::cout << "You already guessed that letter. Try again: ";
            }
            else
            {
                guessedLetters.push_back(guess);
                break;
            }
        }

        if (strchr(word, guess) == nullptr)
        {
            incorrectGuesses++;
            if (incorrectGuesses > 7)
            {
                std::cout << "You lost!" << std::endl;
                std::cout << "The word was " << word << std::endl;
                std::cout << "Would you like to play again? (y/n): ";
                std::cin >> playAgain;
                if (playAgain == 'y')
                {
                    guessedLetters.clear();
                    incorrectGuesses = 0;
                    correctGuesses = 0;
                    choose_random_word_and_setup();
                    continue;
                }
                else
                {
                    std::cout << "Thanks for playing!" << std::endl;
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < strlen(word); i++)
            {
                if (word[i] == guess)
                {
                    correctGuesses++;
                }
            }
        }        
    }


    // 4. If the letter is in the word, display the word with the letter(s) filled in.
    // 5. If the letter is not in the word, display the word as it was.
    // 6. If the user has guessed all the letters, display a message saying they won.
    // 7. If the user has guessed 6 wrong letters, display a message saying they lost.
    // 8. Ask the user if they want to play again.
    // 9. If they do, go back to step 1.
    // 10. If they don't, exit the program.
    // 11. Display a message saying "Thanks for playing!"
    // 12. Exit the program.

}

void Hangman::choose_random_word_and_setup()
{
    srand(time(nullptr));
    int randomNumber = rand() % 5000;

    FILE* file = fopen("dictionary.txt", "r");

    if (file == nullptr)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < randomNumber; i++)
    {
        fscanf(file, "%s", word);
    }

    fclose(file);
}

void Hangman::print_hangman_image(int incorrectGuesses)
{
    if (incorrectGuesses == 0) {
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |"<< std::endl;
        std::cout << "|    |  /              | |" << std::endl;
        std::cout << "|    | /               |_|" << std::endl;
        std::cout << "|    |/                " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |               " << std::endl;
        std::cout << "|    |              " << std::endl;
        std::cout << "|    |              " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        
    }
    else if (incorrectGuesses == 1){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |               " << std::endl;
        std::cout << "|    |              " << std::endl;
        std::cout << "|    |              " << std::endl;
        std::cout << "|    |                     " << std::endl;
        std::cout << "|    |             " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |             " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }
    else if (incorrectGuesses == 2){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|" << std::endl;
        std::cout << "|    |                   .  ." << std::endl;
        std::cout << "|    |                  |   | " << std::endl;
        std::cout << "|    |                  | . |   " << std::endl;
        std::cout << "|    |                  |___|  " << std::endl;
        std::cout << "|    |               " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |                " << std::endl;
        std::cout << "|    |                  " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }else if (incorrectGuesses == 3){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|" << std::endl;
        std::cout << "|    |                /Y .  ." << std::endl;
        std::cout << "|    |               // |   | " << std::endl;
        std::cout << "|    |              | | | . | " << std::endl;
        std::cout << "|    |              ' ) |___| " << std::endl;
        std::cout << "|    |                    " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                  " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

        }else if (incorrectGuesses == 4){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|_'." << std::endl;
        std::cout << "|    |                /Y .  . Y\\" << std::endl;
        std::cout << "|    |               // |   |  \\\\" << std::endl;
        std::cout << "|    |              | | | . |   \\\\" << std::endl;
        std::cout << "|    |              ' ) |___|    ('" << std::endl;
        std::cout << "|    |                    " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                 " << std::endl;
        std::cout << "|    |                  " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }else if (incorrectGuesses == 5){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|_'." << std::endl;
        std::cout << "|    |                /Y .  . Y\\" << std::endl;
        std::cout << "|    |               // |   |  \\\\" << std::endl;
        std::cout << "|    |              | | | . |   \\\\" << std::endl;
        std::cout << "|    |              ' ) |___|    ('" << std::endl;
        std::cout << "|    |                  ||    " << std::endl;
        std::cout << "|    |                  || " << std::endl;
        std::cout << "|    |                  || " << std::endl;
        std::cout << "|    |                  || " << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }else if (incorrectGuesses == 6){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|_'." << std::endl;
        std::cout << "|    |                /Y .  . Y\\" << std::endl;
        std::cout << "|    |               // |   |  \\\\" << std::endl;
        std::cout << "|    |              | | | . |   \\\\" << std::endl;
        std::cout << "|    |              ' ) |___|    ('" << std::endl;
        std::cout << "|    |                  || ||   " << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"           \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }else if (incorrectGuesses == 7){
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|_'." << std::endl;
        std::cout << "|    |                /Y .  . Y\\" << std::endl;
        std::cout << "|    |               // |   |  \\\\" << std::endl;
        std::cout << "|    |              | | | . |   \\\\" << std::endl;
        std::cout << "|    |              ' ) |___|    ('" << std::endl;
        std::cout << "|    |                  || ||   " << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"  / | |   \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"  \\_|     \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }else{
        std::cout << " ______________________._.________" << std::endl;
        std::cout << "|    ._________________)_)_______|" << std::endl;
        std::cout << "|    |   /   /         | |        " << std::endl;
        std::cout << "|    |  /   /          | |        " << std::endl;
        std::cout << "|    | /   /           | |        " << std::endl;
        std::cout << "|    |/   /            | |        " << std::endl;
        std::cout << "|    |   /             | |.-''." << std::endl;
        std::cout << "|    |  /              | /  _  \\" << std::endl;
        std::cout << "|    | /               | |  '/,|" << std::endl;
        std::cout << "|    |/                {  \\__-'  " << std::endl;
        std::cout << "|    |                 .\\--|_'." << std::endl;
        std::cout << "|    |                /Y .  . Y\\" << std::endl;
        std::cout << "|    |               // |   |  \\\\" << std::endl;
        std::cout << "|    |              | | | . |   \\\\" << std::endl;
        std::cout << "|    |              ' ) |___|    ('" << std::endl;
        std::cout << "|    |                  || ||   " << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|    |                  || ||" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"  / | | \\ \"\"|\"\"|" << std::endl;
        std::cout << "|\"\"\"\"|\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"  \\_| |_/ \"\"|\"\"|" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;
        std::cout << "|    |                           |  |" << std::endl;

    }

}


//  ______________________._.________
// |    ._________________)_)_______|
// |    |   /   /         | |
// |    |  /   /          | |
// |    | /   /           | |
// |    |/   /            | |
// |    |   /             | |.-''.
// |    |  /              | /  _  \
// |    | /               | |  '/,|
// |    |/                {  \__-'   
// |    |                 .__-__'.
// |    |                /Y .  . Y\
// |    |               // |   |  \\
// |    |              | | | . |   \\
// |    |              ' ) |___|    ('
// |    |                  || ||   
// |    |                  || ||
// |    |                  || ||
// |    |                  || ||
// """"""""""""""""""""""  / | | \ |""|
// |""""|""""""""""""""""  \_| |_/ |""|
// |    |                          |  |
// |    |                          |  |
// |    |                          |  |

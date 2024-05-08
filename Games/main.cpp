#include "Hangman/hangman.h"
#include <iostream>



int main()
{
    //Display the menu on the screen, but for now just assume the input is a 1.
    int userinput = 1;
    Hangman hangman;
    while (true)
    {
        switch (userinput)
        {
            case 1:
                std::cout << "Let's play Hangman!" << std::endl;
                hangman.play();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
        std::cout << "Would you like to play another game? (y\\n)" << std::endl;
        char response;
        std::cin >> response;
        if (response == 'n')
        {
            break;
        }
    }

}
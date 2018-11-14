#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <fstream>

int main()
{

    const int MAX_WRONG = 8;

    std::vector<std::string> words;
    int diff;
    std::cout << "Please choose a difficulty:";
    std::cin >> diff;
    std::string buffer;
    std::ifstream wordFile;
    switch (diff)
    {
    case 0:
        wordFile.open("./words/easy.txt");
        while (getline(wordFile, buffer))
            words.push_back(buffer);
        break;
    case 1:
        wordFile.open("./words/medium.txt");
        while (getline(wordFile, buffer))
            words.push_back(buffer);
        break;
    case 2:
        wordFile.open("./words/hard.txt");
        while (getline(wordFile, buffer))
            words.push_back(buffer);
        break;
    }

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const std::string THE_WORD = words[0];
    int wrong = 0;
    std::string soFar(THE_WORD.size(), '-');
    std::string used = "";

    std::cout << "\t\t\tWelcome to Hangman!";
    std::cout << "\n\t\t\t-------------------\n\n";
    std::cout << "You have exactly " << (MAX_WRONG - wrong) << " guesses, goodluck!";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        std::cout << "\nYou've used the following letters:\n"
                  << used << std::endl;
        std::cout << "So far, the word is: " << soFar << std::endl;

        char guess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        // guess = toupper(guess); //make uppercase since secret word in uppercase

        while (used.find(guess) != std::string::npos)
        {
            std::cout << "\nYou've already guessed " << guess << std::endl;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
        }

        used += guess;

        if (THE_WORD.find(guess) != std::string::npos)
        {
            std::cout << "That's right! " << guess << " is in the word.\n";
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            ++wrong;
            std::cout << "Sorry, " << guess << " isn't in the word.\n";
            std::cout << "You have " << (MAX_WRONG - wrong) << " guesses left.\n";
        }
    }
    if (wrong == MAX_WRONG)
    {
        std::cout << "Game over, you've been hanged!";
    }
    else
    {
        std::cout << "Congratulation! You've successfully guessed the secret word!";
    }

    //This is a little something i like to do at the end of my games ;)
    std::cout << "\nThe word was " << THE_WORD << "\n\n";
    int rate;
    std::cout << "Please take a moment of your time and rate the game\n";
    std::cout << "1 - It was fun!\n";
    std::cout << "2 - It was ok\n";
    std::cout << "3 - It was bad\n";
    std::cin >> rate;
    switch (rate)
    {
    case 1:
        std::cout << "We are so glad to hear that! thanks for the positive feedback!\n";
        break;
    case 2:
        std::cout << "We'll do better next time, thanks for your feedback!\n";
        break;
    case 3:
        std::cout << "We are terribly sorry about that, we'll do better next time\n";
        break;
    default:
        std::cout << "Good-bye\n";
        break;
    }
    system("pause");
    return 0;
}
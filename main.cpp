#include "Game.h"

int main() {
    srand(time(0)); // Seed the random number generator
    Game gameInstance; // Create an instance of the Game class
    GameData gameDataInstance; // Create an instance of the GameData class
    int menuChoice; // Variable to store the user's menu choice
    char gd; // Variable to store the chosen difficulty level
    Highscore highscoreInstance; // Create an instance of the Highscore class

    do {
        menuChoice = gameInstance.displayMenu(); // Display the main menu and get the user's choice

        switch (menuChoice) {
        case 1:
            do {
                setColor(1);
                cout << "Please enter 'h' for hard mode and 'e' for easy mode: ";
                gd = _getch(); // Capture single character without Enter

                cout << gd << endl;

                if (gd != 'h' && gd != 'e') {
                    system("cls"); // Clear the screen after handling invalid input
                    setColor(4);
                    displayGui(0, 0, 2000, ' ');
                    cout << "Invalid choice. Please enter 'h' or 'e':\n";
                    displayGui(0, 0, 2000, ' ');
                }

                while (_kbhit()) _getch(); // Clear the keyboard buffer if any key is pressed
            } while (gd != 'h' && gd != 'e'); // Repeat until a valid input is entered
            setColor(2);
            cout << "Starting the game";
            displayGui(4, 2, 500, '.');
            system("cls");
            {
                start(gd); // Start the game with the chosen difficulty
            }
            break;
        case 2:
            system("cls");
            setColor(2);
            cout << "Displaying instructions";
            displayGui(4, 2, 500, '.');
            setColor(3);
            cout << endl;
            gameDataInstance.displayInstructions(); // Display game instructions
            break;
        case 3:
            system("cls");
            setColor(2);
            cout << "Showing high scores";
            displayGui(4, 1, 500, '.');
            setColor(4);
            highscoreInstance.readScoresFromFile();  // Load high scores from file
            highscoreInstance.displayHighScores();  // Display high scores
            break;
        case 4:
            system("cls");
            setColor(2);
            cout << "About us section";
            displayGui(4, 2, 500, '.');
            setColor(3);
            gameDataInstance.displayAboutUs(); // Display information about the game
            break;
        case 5:
            setColor(4);
            cout << "Exiting!";
            displayGui(4, 2, 500, '.');
            break;
        default:
            break;
        }
    } while (menuChoice != 5); // Continue looping until the user exits the game

    system("Pause");
    return 0;
}

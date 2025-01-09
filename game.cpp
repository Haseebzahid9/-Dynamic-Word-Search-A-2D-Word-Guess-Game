#include "Game.h"

char gd = ' ';
int l = 1;
int dimension = 0;

string l1[9] = { "at", "it", "am", "go", "up", "on", "an", "do", "by" };
string l2[30] = { "cat", "bat", "rat", "dog", "ant", "pig", "cow", "owl", "bee", "fox", "sun", "run", "ice", "pen", "mat", "cup", "bug", "toy", "car", "pot", "lip", "hen", "tap", "bow", "ape", "hat", "bed", "egg", "pit" };
string l3[10] = { "tree", "ship", "home", "frog", "barn", "fish", "milk", "snow", "gold" };
string l4[10] = { "apple", "bread", "chair", "grape", "table", "pearl", "stone", "flame", "piano", "beach" };
string l5[30] = { "spring", "planet", "forest", "orange", "wizard", "friend", "soccer", "garden", "candle", "rocket", "bridge", "camera", "farmer", "animal", "shadow", "cotton", "jacket", "driver", "button", "parrot", "muscle", "jungle", "desert", "cheese", "letter", "tunnel", "basket", "stream" };
string l6[10] = { "picture", "blanket", "monster", "morning", "stomach", "sunbeam", "library", "teacher", "hanging" };

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayGui(int a, int b, int c, char d) {
    for (int i = 0; i < a; i++) {
        setColor(b);
        cout << d;
        this_thread::sleep_for(chrono::milliseconds(c));
    }
}

// Game class handles game initialization, menu display, and user interactions.
Game::Game() {
    cout << endl;
    displayGui(22, 1, 30, '-');
    cout << "\n\n";
    setColor(4);
    cout << " Welcome to Ultimate!\n\n";
    displayGui(22, 1, 30, '-');
    cout << "\n\n";
    setColor(2);
    cout << "      Word Guesser    \n\n";
    displayGui(22, 1, 30, '-');
    cout << "\n\nloading";
    displayGui(4, 1, 500, '.');
    system("cls");
    displayGui(39, 4, 30, '-');
    setColor(1);
}

// Displays the main menu and handles user input for different options.
int Game::displayMenu() {
    char choice;
    do {
        setColor(1);
        cout << "\n\nPress 1 for Start\n" << endl;
        cout << "Press 2 for instructions/rules\n" << endl;
        cout << "Press 3 for High Score\n" << endl;
        cout << "Press 4 for About us\n" << endl;
        cout << "Press 5 for Exit\n" << endl;
        displayGui(39, 4, 30, '-');

        displayGui(1, 2, 400, ' ');
        cout << "\n\nEnter your choice: ";
        choice = _getch(); // Capture input without requiring Enter
        system("cls");

        switch (choice) {
        case '1': return 1;  // Start game
        case '2': return 2;  // Show instructions
        case '3': return 3;  // Show high score
        case '4': return 4;  // About us
        case '5': return 5;  // Exit game
        default:
            displayGui(1, 2, 400, ' ');
            cout << "Invalid Input. Please enter again" << endl;

            while (_kbhit()) _getch();  // Clear keyboard buffer
        }
    } while (true);
}

// GameData class handles the display of game instructions and about us information.
void GameData::displayInstructions() {
    cout << "Welcome to the Game!" << endl;
    cout << "Here are the instructions to play:" << endl;
    cout << "1. Start the game by selecting 'Play' from the main menu." << endl;
    cout << "2. Choose a difficulty level (Easy or Hard)." << endl;
    cout << "3. The objective is to complete all levels with the highest score." << endl;
    cout << "4. Use arrow keys to navigate through the menus and interact with the game press escape to select a word and press enter when you think word is colpeted press Enter." << endl;
    cout << "5. Press 'f' to end the game and access options." << endl;
    cout << "6. Good luck and have fun!" << endl;
}

void GameData::displayAboutUs() {
    cout << "About Us:" << endl;
    cout << "This game was created by a team of passionate developers." << endl;
    cout << "Our goal is to provide an exciting and engaging gaming experience for players." << endl;
    cout << "Thank you for playing, and we hope you enjoy the game!" << endl;
}

// Grid class handles grid initialization, word placement, and grid manipulation.
Grid::Grid(int rowCount, int colCount) {
    rows = rowCount;
    cols = colCount;

    // Dynamically allocate the main array for the grid
    gridArray = new char* [rows];
    for (int i = 0; i < rows; i++) {
        gridArray[i] = new char[cols];
    }

    gridCopy = new char* [rows];
    for (int i = 0; i < rows; i++) {
        gridCopy[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            gridCopy[i][j] = ' '; // Initialize with spaces
        }
    }

    // Initialize the entire grid with empty spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            gridArray[i][j] = ' ';
        }
    }

    // Add the boundaries for the grid
    for (int i = 0; i < cols; i++) {
        gridArray[0][i] = '-';
        gridArray[rows - 1][i] = '-';
    }
    for (int i = 1; i < rows - 1; i++) {
        gridArray[i][0] = '|';
        gridArray[i][cols - 1] = '|';
    }

    decideLevel();  // Decide the difficulty and level settings
}

// This function decides the grid level based on difficulty and game settings.
void Grid::decideLevel() {
    srand(time(0));  // Seed for random number generation

    if (gd == 'e') {  // Easy difficulty
        if (l == 1 && dimension == 12) {
            int spaceLength = 2;
            int num1 = 7;
            initializeWordTracking();
            placewords(l1, spaceLength, num1, 9);
        }
        else if (l == 2 && dimension == 17) {
            int spaceLength = 3;
            int num1 = 7;
            initializeWordTracking();
            placewords(l2, spaceLength, num1, 30);
        }
        else if (l == 3 && dimension == 22) {
            int spaceLength = 4;
            int num1 = 7;
            initializeWordTracking();
            placewords(l3, spaceLength, num1, 10);
        }
    }
    else if (gd == 'h') {  // Hard difficulty
        if (l == 1 && dimension == 12) {
            int spaceLength = 5;
            int num1 = 5;
            initializeWordTracking();
            placewords(l4, spaceLength, num1, 9);
        }
        else if (l == 2 && dimension == 17) {
            int spaceLength = 6;
            int num1 = 6;
            initializeWordTracking();
            placewords(l5, spaceLength, num1, 30);
        }
        else if (l == 3 && dimension == 22) {
            int spaceLength = 7;
            int num1 = 7;
            initializeWordTracking();
            placewords(l6, spaceLength, num1, 10);
        }
    }

    fillRemainingWithRandomChars();  // Fill remaining spaces with random characters
}

// Initializes the word tracking array to false, indicating no word is placed yet.
void Grid::initializeWordTracking() {
    for (int i = 0; i < 100; i++) {  // Initialize all entries to false
        wordPlaced[i] = false;
    }
}

// Places words randomly in the grid, checking for available spaces and valid placement directions (horizontal, vertical, diagonal).
void Grid::placewords(string words[], int spaceLength, int num, int Count) {
    srand(time(0));

    for (int i = 0; i < num; i++) {
        string currentWord;
        bool placed = false;
        int attempts = 0;  // Counter to track placement attempts

        while (!placed && attempts < 100) {  // Limit to 100 attempts per word
            attempts++;
            int index = rand() % Count;
            if (!wordPlaced[index]) {
                currentWord = words[index];
                int direction = rand() % 3;
                int row = rand() % rows;
                int col = rand() % cols;

                // Horizontal placement
                if (direction == 0 && col + currentWord.length() <= cols) {
                    bool canPlace = true;
                    for (int j = 0; j < currentWord.length(); j++) {
                        if (gridArray[row][col + j] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }

                    if (canPlace) {
                        for (int j = 0; j < currentWord.length(); j++) {
                            gridArray[row][col + j] = currentWord[j];
                            gridCopy[row][col + j] = currentWord[j];  // Update gridCopy
                        }
                        wordPlaced[index] = true;
                        placed = true;
                    }
                }
                // Vertical placement
                else if (direction == 1 && row + currentWord.length() <= rows) {
                    bool canPlace = true;
                    for (int j = 0; j < currentWord.length(); j++) {
                        if (gridArray[row + j][col] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }

                    if (canPlace) {
                        for (int j = 0; j < currentWord.length(); j++) {
                            gridArray[row + j][col] = currentWord[j];
                            gridCopy[row + j][col] = currentWord[j];  // Update gridCopy
                        }
                        wordPlaced[index] = true;
                        placed = true;
                    }
                }
                // Diagonal placement
                else if (direction == 2 && row + currentWord.length() <= rows && col + currentWord.length() <= cols) {
                    bool canPlace = true;
                    for (int j = 0; j < currentWord.length(); j++) {
                        if (gridArray[row + j][col + j] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }

                    if (canPlace) {
                        for (int j = 0; j < currentWord.length(); j++) {
                            gridArray[row + j][col + j] = currentWord[j];
                            gridCopy[row + j][col + j] = currentWord[j];  // Update gridCopy
                        }
                        wordPlaced[index] = true;
                        placed = true;
                    }
                }
            }
        }
    }
    system("cls");
    cout << "Protip solution grid!" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (gridArray[i][j] == '-' || gridArray[i][j] == '|') {
                setColor(7);  // Set color for grid borders
                cout << gridArray[i][j] << " ";
            }
            else {
                setColor(1);  // Set color for regular grid characters
                cout << gridArray[i][j] << " ";
            }
        }
        cout << endl;
    }
    displayGui(1, 2, 3000, ' ');
    system("cls");
}

// Fills all empty grid positions with random characters.
void Grid::fillRemainingWithRandomChars() {
    srand(time(0));
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (gridArray[i][j] == ' ') {
                gridArray[i][j] = rand() % 26 + 'a';  // Fill with random uppercase letters
            }
        }
    }
}

// Destructor to frre the array.
Grid::~Grid() {
    for (int i = 0; i < rows; i++) {
        delete[] gridArray[i];
        delete[] gridCopy[i];
    }
    delete[] gridArray;
    delete[] gridCopy;
}

// Constructor for Highscore class
Highscore::Highscore() {
    for (int i = 0; i < 5; i++) {
        easyScores[i] = { "", 0, 0 };
        hardScores[i] = { "", 0, 0 };
    }
}

// Parse a line from the file
// Extracts the mode, player name, score, and level from a line in the file
void Highscore::parseLine(const string& line, char& mode, string& name, int& score, int& level) {
    size_t firstSpace = line.find(' ');
    size_t secondSpace = line.find(' ', firstSpace + 1);
    size_t thirdSpace = line.find(' ', secondSpace + 1);

    mode = line[0];
    name = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);
    score = stoi(line.substr(secondSpace + 1, thirdSpace - secondSpace - 1));
    level = stoi(line.substr(thirdSpace + 1));
}

// Read scores from the file
// Opens the file, reads each line, and inserts scores into the appropriate array
void Highscore::readScoresFromFile() {
    ifstream file("s1.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            char mode;
            string name;
            int score, level;

            parseLine(line, mode, name, score, level);

            PlayerScore player = { name, score, level };

            if (mode == 'e') {
                insertScore(easyScores, player);
            }
            else if (mode == 'h') {
                insertScore(hardScores, player);
            }
        }
        file.close();
    }
}

// Insert a new score into the list
// Inserts the score into the appropriate position if it's better than the last score in the list
void Highscore::insertScore(PlayerScore scores[5], PlayerScore newScore) {
    if (newScore.score > scores[4].score) {
        scores[4] = newScore;
        sortScores(scores);
    }
}

// Sort the scores in descending order
// Sorts the scores array from highest to lowest
void Highscore::sortScores(PlayerScore scores[5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (scores[i].score < scores[j].score) {
                PlayerScore temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

// Write the scores to the file
// Writes the sorted high scores to the file, one mode (easy/hard) at a time
void Highscore::writeScoresToFile() {
    ofstream file("s1.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << "e " << easyScores[i].name << " " << easyScores[i].score << " " << easyScores[i].level << "\n";
        }
        for (int i = 0; i < 5; i++) {
            file << "h " << hardScores[i].name << " " << hardScores[i].score << " " << hardScores[i].level << "\n";
        }
        file.close();
    }
}

// Add a new score
// Reads the current scores, inserts the new score, and writes the updated scores to the file
void Highscore::addScore(string name, int score) {
    PlayerScore newScore = { name, score, l };  // Use global 'l' for level

    readScoresFromFile();

    if (gd == 'e') {
        insertScore(easyScores, newScore);
    }
    else if (gd == 'h') {
        insertScore(hardScores, newScore);
    }

    writeScoresToFile();
}

// Display the high scores
// Displays the high scores for both easy and hard modes
void Highscore::displayHighScores() {
    cout << "\nEasy Mode High Scores:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << easyScores[i].name << " - Score: " << easyScores[i].score << " Level: " << easyScores[i].level << endl;
    }

    cout << "\nHard Mode High Scores:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << hardScores[i].name << " - Score: " << hardScores[i].score << " Level: " << hardScores[i].level << endl;
    }
}

// Display scores
// Displays the scores from a given array of PlayerScore
void Highscore::displayScores(PlayerScore scores[5]) {
    for (int i = 0; i < 5; i++) {
        if (scores[i].score > 0) {
            cout << i + 1 << ". " << scores[i].name << " - " << scores[i].score << " (Level " << scores[i].level << ")" << endl;
        }
    }
}

// Constructor initializes the game grid, sets initial positions, scores, and game status.
Play::Play(int gridRows, int gridCols) : Grid(gridRows, gridCols) {
    cursorRow = 1;
    cursorCol = 1;
    selectedWord = "";
    selectedCount = 0;
    score = 0;
    correctGuesses = 0;
    chances = 5;
}

// Displays the game grid with a cursor. Highlights the current position of the cursor and displays the current word and selected characters.
void Play::displayGridWithCursor() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == cursorRow && j == cursorCol) {
                setColor(4);  // Set color for the cursor position
                cout << ". ";
            }
            else {
                if (gridArray[i][j] == '-' || gridArray[i][j] == '|') {
                    setColor(7);  // Set color for grid borders
                    cout << gridArray[i][j] << " ";
                }
                else {
                    setColor(1);  // Set color for regular grid characters
                    cout << gridArray[i][j] << " ";
                }
            }
        }
        cout << endl;
    }

    setColor(6);
    cout << "\nCurrent Word: " << selectedWord << endl;  // Display the current word being formed
    cout << "Selected Characters (Row, Col, Character):" << endl;

    for (int i = 0; i < selectedCount; i++) {
        cout << "Position: (" << selectedCharacters[i].row << ", " << selectedCharacters[i].col
            << ") -> " << selectedCharacters[i].character << endl;  // Show the selected characters' positions
    }

    setColor(7);
}

// Handles the movement of the cursor within the grid based on user input (w, a, s, d for up, left, down, right).
void Play::moveCursor(char moveKey) {
    switch (moveKey) {
    case 'w':
        if (cursorRow > 1) cursorRow--;  // Move up if not at the top
        break;
    case 's':
        if (cursorRow < rows - 2) cursorRow++;  // Move down if not at the bottom
        break;
    case 'a':
        if (cursorCol > 1) cursorCol--;  // Move left if not at the left edge
        break;
    case 'd':
        if (cursorCol < cols - 2) cursorCol++;  // Move right if not at the right edge
        break;
    default:
        break;
    }
}

// Adds the selected character to the current word and updates the selection count.
void Play::selectCharacter() {
    if (selectedCount < 100) {
        char selectedChar = gridArray[cursorRow][cursorCol];  // Get character at cursor position
        selectedWord += selectedChar;  // Add it to the selected word
        selectedCharacters[selectedCount] = { cursorRow, cursorCol, selectedChar };  // Store the selected character info
        selectedCount++;  // Increment the count of selected characters
    }
    else {
        cout << "Maximum selection limit reached!" << endl;  // Warn if the selection limit is reached
    }
}

void Play::validate() {
    // Check if the game is over first
    if (chances == 0) {
        cout << "Game over!" << endl;
        askForName();  // Ask for the player's name after completing the game
        exit(0);  // Exit the game
    }

    bool isValid = true;

    if (selectedWord.empty()) {
        cout << "You must enter a valid word!" << endl;
        cout << "Remaining chances: " << --chances << endl;  // Decrement chances and display the remaining chances
        displayGui(1, 2, 2500, ' ');
        return;
    }

    for (int i = 0; i < validatedCount; i++) {
        if (validatedWords[i] == selectedWord) {
            isValid = false;
            break;  // Word has already been validated, so it's not valid
        }
    }

    if (!isValid) {
        cout << "The word \"" << selectedWord << "\" has already been validated!" << endl;
        cout << "Remaining chances: " << --chances << endl;  // Decrement chances and display the remaining chances
        displayGui(1, 2, 3000, ' ');
        resetSelectedWord();
        return;
    }

    for (int i = 0; i < selectedCount; i++) {
        int row = selectedCharacters[i].row;
        int col = selectedCharacters[i].col;

        if (gridCopy[row][col] != selectedCharacters[i].character) {
            isValid = false;  // Check if the selected characters match the grid
            break;
        }
    }

    if (isValid) {
        cout << "The word \"" << selectedWord << "\" is valid!" << endl;
        score += (gd == 'e') ? (l == 1 ? 5 : (l == 2 ? 7 : 10)) : (gd == 'h') ? (l == 1 ? 10 : (l == 2 ? 15 : 20)) : 0;
        correctGuesses++;  // Increase correct guess count
        cout << "Your score is now: " << score << endl;
        displayGui(1, 2, 2500, ' ');

        if (correctGuesses == 5) {
            levelUp();  // Move to the next level after 5 correct guesses
        }

        validatedWords[validatedCount] = selectedWord;
        validatedCount++;  // Add the validated word to the list of validated words
    }
    else {
        cout << "The word \"" << selectedWord << "\" is invalid!" << endl;
        cout << "Remaining chances: " << --chances << endl;  // Decrement chances and display the remaining chances
        displayGui(1, 4, 3000, ' ');
    }

    resetSelectedWord();  // Reset the selected word for the next attempt
}

// Advances to the next level if the current level is completed. Ends the game if the last level is reached.
void Play::levelUp() {
    if (l == 3) {
        cout << "Congratulations! You have completed all the levels!" << endl;
        cout << "Your final score is: " << score << endl;
        displayGui(1, 2, 3000, ' ');
        askForName();  // Ask for the player's name after completing the game
        exit(0);  // Exit the game
    }
    else {
        l++;
        correctGuesses = 0;  // Reset the correct guess count for the next level
        cout << "Moving to Level " << l << "!" << endl;
        start(gd);  // Start the new level
        displayGui(1, 2, 3000, ' ');
        system("cls");  // Clear the screen for the next level
    }
}

// Prompts the player to enter their name and saves the high score.
void Play::askForName() {
    string playerName;
    setColor(6);
    cout << "Please enter your name: ";
    cin >> playerName;

    Highscore h;
    h.addScore(playerName, score);  // Save the player's name and score to the highscore list

    cout << "Thank you for playing, " << playerName << "!" << endl;
    cout << "Goodbye! See you next time!" << endl;
    setColor(7);
}

// Controls the game flow, allowing the player to move the cursor, select characters, and validate words.
void Play::controlCursor() {
    char moveKey;
    do {
        displayGridWithCursor();  // Display the grid with the current cursor position

        moveKey = _getch();  // Get the user's input key

        if (moveKey == 'f') {
            cout << "Game Over!" << endl;
            displayGui(1, 4, 3000, ' ');  // End the game if 'f' is pressed
            askForName();  // Prompt for name if the game ends
            break;
        }

        if (moveKey == ' ') {
            selectCharacter();  // Select a character if spacebar is pressed
        }
        else if (moveKey == '\r') {
            validate();  // Validate the selected word if Enter is pressed
        }
        else {
            moveCursor(moveKey);  // Move the cursor if other keys are pressed
        }

        system("cls");  // Clear the screen for the next iteration

    } while (true);
}

// Resets the selected word and character count to start a new word selection.
void Play::resetSelectedWord() {
    selectedWord = "";
    selectedCount = 0;
}

// Function to start the game with a specified difficulty level
void start(char difficultyLevel) {
    char difficulty;
    gd = difficultyLevel;
    difficulty = difficultyLevel; // Store the passed difficulty level in the variable

    // If the difficulty level is 'e' (easy)
    if (difficulty == 'e') {
        // Check the value of 'l' to determine grid size
        if (l == 1) {
            dimension = 12; // Set grid dimension to 12 for level 1
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
        else if (l == 2) {
            dimension = 17; // Set grid dimension to 17 for level 2
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
        else if (l == 3) {
            dimension = 22; // Set grid dimension to 22 for level 3
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
    }
    // If the difficulty level is 'h' (hard)
    else if (difficulty == 'h') {
        // Check the value of 'l' to determine grid size
        if (l == 1) {
            dimension = 12; // Set grid dimension to 12 for level 1
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
        else if (l == 2) {
            dimension = 17; // Set grid dimension to 17 for level 2
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
        else if (l == 3) {
            dimension = 22; // Set grid dimension to 22 for level 3
            Grid gridGame(dimension, dimension);
            Play playGame(dimension, dimension);
            playGame.controlCursor();
        }
    }
}

string toLower(const string& str) {
    string result = str;
    for (char& ch : result) {
        ch = tolower(ch);
    }
    return result;
}

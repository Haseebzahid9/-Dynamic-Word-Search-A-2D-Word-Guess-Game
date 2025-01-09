//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//#include <thread>
//#include <chrono>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>
//#include <cstring>
//
//using namespace std;
//
//char gd = ' ';
//int l = 1;
//string l1[9] = { "at", "it", "am", "go", "up", "on", "an", "do", "by" };
//string l2[30] = { "cat", "bat", "rat", "dog", "ant", "pig", "cow", "owl", "bee", "fox", "sun", "run", "ice", "pen", "mat", "cup", "bug", "toy", "car", "pot", "lip", "hen", "tap", "bow", "ape", "hat", "bed", "egg", "pit" };
//string l3[10] = { "tree", "ship", "home", "frog", "barn", "fish", "milk", "snow", "gold" };
//
//string l4[10] = { "apple", "bread", "chair", "grape", "table", "pearl", "stone", "flame", "piano", "beach" };
//string l5[30] = { "spring", "planet", "forest", "orange", "wizard", "friend", "soccer", "garden", "candle", "rocket", "bridge", "camera", "farmer", "animal", "shadow", "cotton", "jacket", "driver", "button", "parrot", "muscle", "jungle", "desert", "cheese", "letter", "tunnel", "basket", "stream" };
//string l6[10] = { "picture", "blanket", "monster", "morning", "stomach", "sunbeam", "library", "teacher", "hanging" };
//
//template<typename T>
//void input(T& a)
//{
//    cin >> a;
//    while (cin.fail())
//    {
//        cin.clear();
//        cin.ignore(100, '\n');
//        cout << "Wrong Input!\nInput Again : ";
//        cin >> a;
//    }
//}
//
//float level = 0;
//int dimension = 0;
//
//void setColor(int color) {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hConsole, color);
//}
//
//void displayGui(int a, int b, int c, char d) {
//    for (int i = 0; i < a; i++) {
//        setColor(b);
//        cout << d;
//        this_thread::sleep_for(chrono::milliseconds(c));
//    }
//}
//
//class Game {
//public:
//    Game() {
//        cout << endl;
//        displayGui(22, 1, 30, '-');
//        cout << "\n\n";
//        setColor(4);
//        cout << " Welcome to Ultimate!\n\n";
//        displayGui(22, 1, 30, '-');
//        cout << "\n\n";
//        setColor(2);
//        cout << "      Word Guesser    \n\n";
//        displayGui(22, 1, 30, '-');
//        cout << "\n\nloading";
//        displayGui(4, 1, 500, '.');
//        system("cls");
//        displayGui(39, 4, 30, '-');
//        setColor(1);
//    }
//
//    int displayMenu() {
//        char choice;
//        do {
//            cout << "\n\nPress 1 for Start\n" << endl;
//            cout << "Press 2 for instructions/rules\n" << endl;
//            cout << "Press 3 for High Score\n" << endl;
//            cout << "Press 4 for About us\n" << endl;
//            cout << "Press 5 for Exit\n" << endl;
//            displayGui(39, 4, 30, '-');
//
//            displayGui(1, 2, 400, ' ');
//            cout << "\n\nEnter your choice: ";
//            choice = _getch(); // Capture input without requiring Enter
//            system("cls");
//
//            // Process only the first character
//            switch (choice) {
//            case '1': return 1;
//            case '2': return 2;
//            case '3': return 3;
//            case '4': return 4;
//            case '5': return 5;
//            default:
//                displayGui(1, 2, 400, ' ');
//                cout << "Invalid Input. Please enter again" << endl;
//
//                while (_kbhit()) _getch();
//            }
//        } while (true); // Loop until a valid choice (or '5') is entere
//    }
//      
//};
//
//class GameData {
//public:
//    void displayInstructions() {};
//    void displayAboutUs() {};
//};
//
//class Grid {
//public:
//    int rows, cols;
//    char** gridArray;
//    char** gridCopy;
//    bool wordPlaced[100]; // Array to track if a word has already been placed
//
//public:
//    Grid(int rowCount, int colCount) {
//        rows = rowCount;
//        cols = colCount;
//
//        // Dynamically allocate the main array
//        gridArray = new char* [rows];
//        for (int i = 0; i < rows; i++) {
//            gridArray[i] = new char[cols];
//        }
//
//        gridCopy = new char* [rows];
//        for (int i = 0; i < rows; i++) {
//            gridCopy[i] = new char[cols];
//            for (int j = 0; j < cols; j++) {
//                gridCopy[i][j] = ' '; // Initialize with spaces
//            }
//        }
//
//
//        // Initialize the entire grid with empty spaces
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                gridArray[i][j] = ' ';
//            }
//        }
//
//        // Add the boundaries for the grid
//        for (int i = 0; i < cols; i++) {
//            gridArray[0][i] = '-';
//            gridArray[rows-1][i] = '-';
//        }
//        for (int i = 1; i < rows - 1; i++) {
//            gridArray[i][0] = '|';
//            gridArray[i][cols - 1] = '|';
//        }
//
//        decideLevel();
//    }
//
//    void decideLevel() {
//        srand(time(0));
//
//        if (gd == 'e') {
//            if (l == 1 && dimension == 12) {
//                int spaceLength = 2;
//                int num1 = 7;
//                initializeWordTracking();
//                placewords(l1, spaceLength, num1, 9);
//            }
//            else if (l == 2 && dimension == 17) {
//                int spaceLength = 3;
//                int num1 = 7;
//                initializeWordTracking();
//                placewords(l2, spaceLength, num1, 30);
//            }
//            else if (l == 3 && dimension == 22) {
//                int spaceLength = 4;
//                int num1 = 7;
//                initializeWordTracking();
//                placewords(l3, spaceLength, num1, 10);
//            }
//        }
//        else if (gd == 'h') {
//            if (l == 1 && dimension == 12) {
//                int spaceLength = 5;
//                int num1 = 5;
//                initializeWordTracking();
//                placewords(l4, spaceLength, num1, 9);
//            }
//            else if (l == 2 && dimension == 17) {
//                int spaceLength = 6;
//                int num1 = 6;
//                initializeWordTracking();
//                placewords(l5, spaceLength, num1, 30);
//            }
//            else if (l == 3 && dimension == 22) {
//                int spaceLength = 7;
//                int num1 = 7;
//                initializeWordTracking();
//                placewords(l6, spaceLength, num1, 10);
//            }
//        }
//
//        fillRemainingWithRandomChars();
//    }
//
//    void initializeWordTracking() {
//        for (int i = 0; i < 100; i++) { // Initialize all entries to false
//            wordPlaced[i] = false;
//        }
//    }
//
//    void placewords(string words[], int spaceLength, int num, int Count) {
//        srand(time(0));
//
//        for (int i = 0; i < num; i++) {
//            string currentWord;
//            bool placed = false;
//            int attempts = 0; // Counter to track placement attempts
//
//            while (!placed && attempts < 100) { // Limit to 100 attempts per word
//                attempts++;
//                int index = rand() % Count;
//                if (!wordPlaced[index]) {
//                    currentWord = words[index];
//                    int direction = rand() % 3;
//                    int row = rand() % rows;
//                    int col = rand() % cols;
//
//                    if (direction == 0 && col + currentWord.length() <= cols) { // Horizontal
//                        bool canPlace = true;
//                        for (int j = 0; j < currentWord.length(); j++) {
//                            if (gridArray[row][col + j] != ' ') {
//                                canPlace = false;
//                                break;
//                            }
//                        }
//
//                        if (canPlace) {
//                            for (int j = 0; j < currentWord.length(); j++) {
//                                gridArray[row][col + j] = currentWord[j];
//                                gridCopy[row][col + j] = currentWord[j]; // Update gridCopy
//                            }
//                            wordPlaced[index] = true;
//                            placed = true;
//                        }
//                    }
//                    else if (direction == 1 && row + currentWord.length() <= rows) { // Vertical
//                        bool canPlace = true;
//                        for (int j = 0; j < currentWord.length(); j++) {
//                            if (gridArray[row + j][col] != ' ') {
//                                canPlace = false;
//                                break;
//                            }
//                        }
//
//                        if (canPlace) {
//                            for (int j = 0; j < currentWord.length(); j++) {
//                                gridArray[row + j][col] = currentWord[j];
//                                gridCopy[row + j][col] = currentWord[j]; // Update gridCopy
//                            }
//                            wordPlaced[index] = true;
//                            placed = true;
//                        }
//                    }
//                    else if (direction == 2 && row + currentWord.length() <= rows && col + currentWord.length() <= cols) { // Diagonal
//                        bool canPlace = true;
//                        for (int j = 0; j < currentWord.length(); j++) {
//                            if (gridArray[row + j][col + j] != ' ') {
//                                canPlace = false;
//                                break;
//                            }
//                        }
//
//                        if (canPlace) {
//                            for (int j = 0; j < currentWord.length(); j++) {
//                                gridArray[row + j][col + j] = currentWord[j];
//                                gridCopy[row + j][col + j] = currentWord[j]; // Update gridCopy
//                            }
//                            wordPlaced[index] = true;
//                            placed = true;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    void fillRemainingWithRandomChars() {
//        srand(time(0));
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                if (gridArray[i][j] == ' ') {
//                    gridArray[i][j] = 'a' + rand() % 26;
//                }
//            }
//        }
//    }
//
//    ~Grid() {
//        for (int i = 0; i < rows; i++) {
//            delete[] gridArray[i];
//            delete[] gridCopy[i];
//        }
//        delete[] gridArray;
//        delete[] gridCopy;
//    }
//};
//
//class HighScore {
//public:
//    struct PlayerScore {
//        string name;
//        int score;
//        int level;
//    };
//
//    // Array to store the top 3 scores for easy and hard mode
//    PlayerScore easyScores[3];
//    PlayerScore hardScores[3];
//
//    // Initialize arrays to empty or default values
//    HighScore() {
//        for (int i = 0; i < 3; i++) {
//            easyScores[i] = { "", 0, 0 };  // Empty name, score 0, level 0
//            hardScores[i] = { "", 0, 0 };
//        }
//    }
//
//    // Method to parse a line manually
//    void parseLine(const string& line, char& mode, string& name, int& score, int& level) {
//        size_t firstSpace = line.find(' ');
//        size_t secondSpace = line.find(' ', firstSpace + 1);
//        size_t thirdSpace = line.find(' ', secondSpace + 1);
//
//        mode = line[0];
//        name = line.substr(firstSpace + 1, secondSpace - firstSpace - 1);
//        score = stoi(line.substr(secondSpace + 1, thirdSpace - secondSpace - 1));
//        level = stoi(line.substr(thirdSpace + 1));
//    }
//
//    // Method to read scores from the file and fill easy and hard scores
//    void readScoresFromFile() {
//        ifstream file("score.txt");
//        if (file.is_open()) {
//            string line;
//            while (getline(file, line)) {
//                char mode;
//                string name;
//                int score, level;
//
//                parseLine(line, mode, name, score, level);
//
//                PlayerScore player = { name, score, level };
//
//                if (mode == 'e') {
//                    insertScore(easyScores, player);  // Insert into easyScores
//                }
//                else if (mode == 'h') {
//                    insertScore(hardScores, player);  // Insert into hardScores
//                }
//            }
//            file.close();
//        }
//    }
//
//    // Method to insert a new score into the appropriate list, maintaining top 3 scores
//    void insertScore(PlayerScore scores[3], PlayerScore newScore) {
//        if (newScore.score > scores[2].score) {
//            scores[2] = newScore;
//            sortScores(scores);  // Sort scores after updating
//        }
//    }
//
//    // Method to sort the scores in descending order manually
//    void sortScores(PlayerScore scores[3]) {
//        for (int i = 0; i < 2; i++) {
//            for (int j = i + 1; j < 3; j++) {
//                if (scores[i].score < scores[j].score) {
//                    // Swap scores
//                    PlayerScore temp = scores[i];
//                    scores[i] = scores[j];
//                    scores[j] = temp;
//                }
//            }
//        }
//    }
//
//    // Method to write the top 3 scores of both modes to the file
//    void writeScoresToFile() {
//        ofstream file("score.txt", ios::trunc);
//        if (file.is_open()) {
//            for (int i = 0; i < 3; i++) {
//                if (easyScores[i].score > 0) {
//                    file << "e " << easyScores[i].name << " " << easyScores[i].score << " " << easyScores[i].level << "\n";
//                }
//            }
//            for (int i = 0; i < 3; i++) {
//                if (hardScores[i].score > 0) {
//                    file << "h " << hardScores[i].name << " " << hardScores[i].score << " " << hardScores[i].level << "\n";
//                }
//            }
//            file.close();
//        }
//    }
//
//    // Method to add a score to the file (called after each game ends)
//    void addScore(string name, int score, int level, char mode) {
//        PlayerScore newScore = { name, score, level };
//
//        readScoresFromFile();
//
//        if (mode == 'e') {
//            insertScore(easyScores, newScore);
//        }
//        else if (mode == 'h') {
//            insertScore(hardScores, newScore);
//        }
//
//        writeScoresToFile();
//    }
//
//    // Method to display the top 3 scores for both modes
//    void displayHighScores() {
//        cout << "High Scores - Easy Mode:" << endl;
//        displayScores(easyScores);
//        cout << endl;
//
//        cout << "High Scores - Hard Mode:" << endl;
//        displayScores(hardScores);
//    }
//
//    // Helper method to display scores
//    void displayScores(PlayerScore scores[3]) {
//        for (int i = 0; i < 3; i++) {
//            if (scores[i].score > 0) {
//                cout << i + 1 << ". " << scores[i].name << " - " << scores[i].score << " (Level " << scores[i].level << ")" << endl;
//            }
//        }
//    }
//};
//
//class Play : public Grid {
//public:
//    int cursorRow, cursorCol;
//    string selectedWord;  // To store the word formed by selected characters
//    int score;  // To keep track of the score
//    int correctGuesses;  // To track the number of correct guesses in the current level
//    int chances;  // To track the remaining chances
//    int level;  // Current level of the game
//
//    struct SelectedCharacter { // Struct to store row, column, and character
//        int row, col;
//        char character;
//    };
//
//    SelectedCharacter selectedCharacters[100]; // Fixed-size array to store selected characters
//    int selectedCount;  // To track the number of selected characters
//
//    // Constructor inherits from Grid class
//    Play(int gridRows, int gridCols) : Grid(gridRows, gridCols) {
//        cursorRow = 1;  // Initial position (row)
//        cursorCol = 1;  // Initial position (col)
//        selectedWord = "";  // Initialize selected word as an empty string
//        selectedCount = 0;  // Initialize selected count to 0
//        score = 0;  // Initialize score to 0
//        correctGuesses = 0;  // Initialize correct guesses to 0
//        chances = 3;  // Set the initial chances to 3
//    }
//
//    // Function to display the grid with the cursor (.),
//    // along with the current selected word and selected characters.
//    void displayGridWithCursor() {
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                if (i == cursorRow && j == cursorCol) {
//                    setColor(4);  // Red for the cursor
//                    cout << ". ";
//                }
//                else {
//                    if (gridArray[i][j] == '-' || gridArray[i][j] == '|') {
//                        setColor(7);  // White for borders
//                        cout << gridCopy[i][j] << " ";
//                    }
//                    else {
//                        setColor(1);  // Blue for random filled characters
//                        cout << gridCopy[i][j] << " ";
//                    }
//                }
//            }
//            cout << endl;
//        }
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                if (i == cursorRow && j == cursorCol) {
//                    setColor(4);  // Red for the cursor
//                    cout << ". ";
//                }
//                else {
//                    if (gridArray[i][j] == '-' || gridArray[i][j] == '|') {
//                        setColor(7);  // White for borders
//                        cout << gridArray[i][j] << " ";
//                    }
//                    else {
//                        setColor(1);  // Blue for random filled characters
//                        cout << gridArray[i][j] << " ";
//                    }
//                }
//            }
//            cout << endl;
//        }
//
//        // Display the currently selected word and positions below the grid
//        setColor(6); // Yellow for the selected word display
//        cout << "\nCurrent Word: " << selectedWord << endl;
//        cout << "Selected Characters (Row, Col, Character):" << endl;
//
//        for (int i = 0; i < selectedCount; i++) { // Display all selected characters and their positions
//            cout << "Position: (" << selectedCharacters[i].row << ", " << selectedCharacters[i].col
//                << ") -> " << selectedCharacters[i].character << endl;
//        }
//
//        setColor(7);  // Reset to white
//    }
//
//    // Move the cursor based on input (W, A, S, D)
//    void moveCursor(char moveKey) {
//        switch (moveKey) {
//        case 'w':  // Move up
//            if (cursorRow > 1) cursorRow--;
//            break;
//        case 's':  // Move down
//            if (cursorRow < rows - 2) cursorRow++;
//            break;
//        case 'a':  // Move left
//            if (cursorCol > 1) cursorCol--;
//            break;
//        case 'd':  // Move right
//            if (cursorCol < cols - 2) cursorCol++;
//            break;
//        default:
//            break;
//        }
//    }
//
//    // Handle character selection and track the position
//    void selectCharacter() {
//        if (selectedCount < 100) {  // Ensure we don't exceed the array limit
//            char selectedChar = gridArray[cursorRow][cursorCol];
//            selectedWord += selectedChar;  // Add the selected character to the word
//
//            // Store the selected character along with its position (row, col)
//            selectedCharacters[selectedCount] = { cursorRow, cursorCol, selectedChar };
//            selectedCount++;  // Increment the count of selected characters
//        }
//        else {
//            cout << "Maximum selection limit reached!" << endl;
//        }
//    }
//
//    // Validate the word against gridCopy
//    void validate() {
//        bool isValid = true;
//
//        // Compare each selected character with gridCopy
//        for (int i = 0; i < selectedCount; i++) {
//            int row = selectedCharacters[i].row;
//            int col = selectedCharacters[i].col;
//
//            // If any character or position doesn't match, the word is invalid
//            if (gridCopy[row][col] != selectedCharacters[i].character) {
//                isValid = false;
//                break;
//            }
//        }
//
//        // Output the result of the validation
//        if (isValid) {
//            cout << "The word \"" << selectedWord << "\" is valid!" << endl;
//
//            // Update score based on the level
//            if (gd == 'e') {
//                if (level == 1) score += 5;
//                else if (level == 2) score += 7;
//                else if (level == 3) score += 10;
//            }
//            else if (gd == 'h') {
//                if (level == 1) score += 10;
//                else if (level == 2) score += 15;
//                else if (level == 3) score += 20;
//            }
//
//            correctGuesses++;  // Increment correct guesses
//
//            cout << "Your score is now: " << score << endl;
//            displayGui(1, 2, 3000, ' ');  // Pause for 3 seconds
//
//            // Check if 5 words are guessed correctly, and move to the next level
//            if (correctGuesses == 5) {
//                levelUp();
//            }
//        }
//        else {
//            cout << "The word \"" << selectedWord << "\" is invalid!" << endl;
//            displayGui(1, 4, 3000, ' ');  // Pause for 3 seconds
//        }
//
//        // Reset the selection after validation
//        resetSelectedWord();
//    }
//
//    // Level Up Logic
//    void levelUp() {
//        // Check if the user has completed level 3
//        if (l == 3) {
//            cout << "Congratulations! You have completed all the levels!" << endl;
//            cout << "Your final score is: " << score << endl;
//            displayGui(1, 2, 3000, ' ');  // Pause for 3 seconds
//            askForName();  // Ask for the user's name
//            exit(0);  // End the game
//        }
//        else {
//            l++;  // Move to the next level
//            correctGuesses = 0;  // Reset correct guesses for the new level
//            cout << "Moving to Level " << level << "!" << endl;
//            displayGui(1, 2, 3000, ' ');  // Pause for 3 seconds
//            system("cls");  // Clear the screen and start the new level
//           // Start Start(gd);
//        }
//    }
//
//    // Function to ask for the user's name
//    void askForName() {
//        string playerName;
//        setColor(6);  // Yellow color for the message
//        cout << "Please enter your name: ";
//        cin >> playerName;  // Get the player's name
//        cout << "Thank you for playing, " << playerName << "!" << endl;
//        cout << "Goodbye! See you next time!" << endl;
//        setColor(7);  // Reset to default color
//    }
//
//    // Control cursor movement with W, A, S, D and character selection with Space
//    void controlCursor() {
//        char moveKey;
//        do {
//            displayGridWithCursor();  // Display the grid with the cursor
//
//            moveKey = _getch();  // Capture input without requiring Enter
//
//            if (moveKey == 'f') {  // End the game if 'f' is pressed
//                cout << "Game Over!" << endl;
//                displayGui(1, 4, 3000, ' ');
//                askForName();  // Ask for the player's name and end the game
//                break;  // Exit the loop and end the game
//            }
//
//            if (moveKey == ' ') {
//                selectCharacter();  // Select character at current cursor position
//            }
//            else if (moveKey == '\r') {  // Enter key for validation
//                validate();  // Validate the selected word
//            }
//            else {
//                moveCursor(moveKey);  // Move the cursor based on the key pressed
//            }
//
//            system("cls");  // Clear the screen for the next frame
//
//        } while (true);  // Keep looping to allow the user to move the cursor and select characters
//    }
//
//    // Optional: Reset the selected word and positions
//    void resetSelectedWord() {
//        selectedWord = "";
//        selectedCount = 0;  // Reset the count of selected characters
//    }
//};
//
//class Start {
//public:
//    int chances;
//    char difficulty;
//
//public:
//    Start(char difficultyLevel) {
//        difficulty = difficultyLevel;
//        if (difficulty == 'e') {
//            if (l == 1) {
//                dimension = 12;
//                Grid gridGame(dimension, dimension);
//               
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//            else if (l == 2) {
//                dimension = 17;
//                Grid gridGame(dimension, dimension);
//                
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//            else if (l == 3) {
//                dimension = 22;
//                Grid gridGame(dimension, dimension);
//                
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//        }
//        else if (difficulty == 'h') {
//            if (l == 1) {
//                dimension = 12;
//                Grid gridGame(dimension, dimension);
//                
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//            else if (l == 2) {
//                dimension = 17;
//                Grid gridGame(dimension, dimension);
//
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//            else if (l == 3) {
//                dimension = 22;
//                Grid gridGame(dimension, dimension);
//
//                Play playGame(dimension, dimension);
//                playGame.controlCursor();  // Enter the play mode
//            }
//        }
//    }
//};
//
//
//int main() {
//    srand(time(0));
//    Game gameInstance;
//    GameData gameDataInstance;
//    int menuChoice = gameInstance.displayMenu();
//    switch (menuChoice) {
//    case 1:
//        do {
//            setColor(1);
//            cout << "Please enter 'h' for hard mode and 'e' for easy mode: ";
//            gd = _getch(); // Capture single character without Enter
//
//            cout << gd << endl;
//
//            if (gd != 'h' && gd != 'e') {
//                system("cls"); // Clear the screen after handling invalid input
//                setColor(4);
//                displayGui(0, 0, 2000, ' ');
//                cout << "Invalid choice. Please enter 'h' or 'e':\n";
//                displayGui(0 , 0, 2000, ' ');
//            }
//      
//            while (_kbhit()) _getch();
//        } while (gd != 'h' && gd != 'e');
//        setColor(2);
//        cout << "Starting the game";
//        displayGui(4, 2, 500, '.');
//        system("cls");
//        {
//            Start startGame(gd);
//        }
//        break;
//    case 2:
//        setColor(2);
//        cout << "Displaying instructions";
//        displayGui(4, 2, 500, '.');
//        cout << endl;
//        gameDataInstance.displayInstructions();
//        system("cls");
//        break;
//    case 3:
//        setColor(2);
//        cout << "Showing high scores";
//        displayGui(4, 1, 500, '.');
//        system("cls");
//        break;
//    case 4:
//        setColor(2);
//        cout << "About us section";
//        displayGui(4, 2, 500, '.');
//        system("cls");
//        break;
//    case 5:
//        setColor(4);
//        cout << "Exiting!";
//        displayGui(4, 2, 500, '.');
//        break;
//    default:
//        break;
//    }
//    system("Pause");
//    return 0;
//}
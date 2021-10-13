/* ---------------------------------------------
Program 3: Typing

Course: CS 141, Fall 2021. Tues 12pm lab
System: Mac using CLion
Author: Maxwell Olmen
---------------------------------------------
*/
#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <vector>     // Input file is stored in a vector
#include <cassert>    // For the assert statement used to validate file open
using namespace std;

// Read words from a text file into a vector
void readWordsIntoVector(vector<string>& v, string fileName) {
    ifstream inStream;                      // Declare an input stream for reading
    inStream.open( fileName);       // Open dictionary file
    assert( inStream.fail() == false );     // Ensure file open worked

    // If you had previously used vector dictionary, then you might want to clear it
    // before continuing to use it, though that is not the case here.
    v.clear();

    // Keep repeating while input from the file yields a word
    string newWord;                         // Store a single input word
    while( inStream >> newWord) {           // While there is another word to be read
        // Add this new word to the end of the vector, growing it in the process
        v.push_back( newWord);
    }

    // Close the dictionary file
    inStream.close();
}

// Displays dictionary words within a specified range
void displayDictionary(vector<string> dictionary, int start, int end) {
    // Iterate over range
    for (int i = start; i <= end; i++) {
        // Print word
        cout << "      " << i << ". " << dictionary.at(i) << "\n";
    }

    cout << "\n";
}

// Displays commonly misspelled words within a specified range
// Depending on bool correct, it may show correct or incorrect versions of the spelling
void displayMisspelledWords(vector<string> misspelledWords, int start, int end, bool correct) {
    // Iterate over range
    for (int i = start; i <= end; i++) {
        cout << "      " << i << ". " << misspelledWords.at(i * 2 + (correct ? 1 : 0)) << "\n";
    }

    cout << "\n";
}

// Run search algorithm to find any word within the full dictionary
void search(vector<string> dictionary, string word) {
    // Start count at 1
    int count = 1;
    int current;
    // Initialize minimum and maximum at entire range of dictionary
    int min = 0;
    int max = dictionary.size() - 1;

    // Run the while loop up until minimum and maximum meet (all words searched)
    while (min <= max) {
        // Set the middle point evenly between the minimum and maximum
        current = (min + max) / 2;

        // Print comparison word
        cout << "     " << count << ". Comparing to: " << dictionary.at(current) << "\n";

        if (dictionary.at(current) == word) {
            // Word found
            cout << word << " was found.\n\n";
            break;
        } else {
            // Word not found
            if (dictionary.at(current) < word) {
                // Current word is too early, set minimum as one word after
                min = current + 1;
            } else {
                // Current word is too late, set maximum as one word before
                max = current - 1;
            }

            // Increment the count for the next loop
            count++;
        }
    }

    // Acknoledge that the word was not found
    if (min > max) {
        cout << word << " was NOT found.\n";
    }
}

// Find the next random word within the full dictionary that satisfies the required word length
string findDictionaryWord(vector<string> dictionary, int size) {
    while (true) {
        // Find random word
        string word = dictionary.at(rand() % dictionary.size());

        if ((int) word.size() == size) {
            // Random word is the correct length, return it
            return word;
        }

        // Random word is not correct length, start loop over
    }

    // Special case if no words exist at that length
    return "cant";
}

// Play the typing game with the specified five words, and the amount of points for every correct word
int playTyping(string words[5], int correctPoints) {
    // Initialize array of words that the user typed
    string typedWords[5];

    cout << "Type in those words within goal of 15 seconds:";

    // Store start time
    // Create variables for total elapsed seconds and misspelled words
    time_t startTime = time(NULL);
    int elapsedSeconds;
    vector<int> misspelledWords;

    // Run 5 times
    for (int i = 0; i < 5; i++) {
        // Receive typed word
        cin >> typedWords[i];

        if (typedWords[i] != words[i]) {
            // If word was typed incorrectly, add to misspelled words
            misspelledWords.push_back(i);
        }
    }

    // Calculate total time used
    elapsedSeconds = difftime(time(NULL), startTime);

    // Check if any misspelled words
    if (misspelledWords.empty()) {
        cout << "   No misspelled words!\n";
    } else {
        cout << "   Misspelled words:\n";

        // If there are misspelled words, iterate over them and print them out
        for (int i = 0; i < (int) misspelledWords.size(); i++) {
            cout << "       " << typedWords[misspelledWords.at(i)] << " should be: " << words[misspelledWords.at(i)] << "\n";
        }
    }

    // Calculate score differential for amount of time used
    int diff = elapsedSeconds <= 15 ? (15 - elapsedSeconds) * 2 : (elapsedSeconds - 15) * -3;
    int score = diff;

    // Add to score for correct words
    score += (5 - (int) misspelledWords.size()) * correctPoints;
    // Subtract from score for incorrect words
    score -= (int) misspelledWords.size() * correctPoints * 2;

    // Print specifications for scoring
    cout << "   Elapsed time: " << elapsedSeconds << " seconds. " << abs(diff) << " point " << (diff >= 0 ? "bonus" : "penalty") << " for finishing " << (diff >= 0 ? 15 - elapsedSeconds : elapsedSeconds - 15) << " seconds " << (diff >= 0 ? "early" : "late") << ".\n";
    cout << "   " << (5 - (int) misspelledWords.size()) * correctPoints << " points: " << 5 - (int) misspelledWords.size() << " spelled correctly x " << correctPoints << " points each\n";

    if (!misspelledWords.empty()) {
        // If any misspelled words, print out penalty specification
        cout << "   " << (int) misspelledWords.size() * correctPoints * 2 << " point penalty: " << (int) misspelledWords.size() << " spelled incorrectly x " << correctPoints * 2 << " points each\n";
    }

    // Print final score
    cout << "   Score: " << score << "\n\n";

    // Return score for main block
    return score;
}

// Run choice one
void runChoiceOne(vector<string> misspelledWords, int& bestScore) {
    cout << "Using commonly misspelled words\n";

    // Create arrays for right and wrong words
    string wrongWords[5], rightWords[5];

    // Run 5 times
    for (int i = 0; i < 5; i++) {
        // Generate random location for a commonly misspelled word
        int r = rand() % 114 * 2;

        // Store wrong word
        wrongWords[i] = misspelledWords.at(r);
        // Store right word, located exactly one ahead
        rightWords[i] = misspelledWords.at(r + 1);

        // Print the wrong word
        cout << wrongWords[i] << " ";
    }

    cout << "\n";

    // Play the game and receive the score
    int score = playTyping(rightWords, 3);

    // If score is highest yet, overwrite bestScore with new high score
    if (score > bestScore) {
        bestScore = score;
    }
}

// Run choice two
void runChoiceTwo(vector<string> dictionary, int& choiceTwoSize, int& bestScore) {
    cout << "Using full dictionary\n";

    // Create array for random words
    string words[5];

    // Run 5 times
    for (int i = 0; i < 5; i++) {
        // Find a random word with right word length
        words[i] = findDictionaryWord(dictionary, choiceTwoSize);

        // If there exists no word with that length, try running the game with words that are one character shorter
        if (words[i] == "cant") {
            // Decrement the word length and find a new first word
            choiceTwoSize--;
            words[i] = findDictionaryWord(dictionary, choiceTwoSize);
        }

        // Print word
        cout << words[i] << " ";
    }

    cout << "\n";

    // Play game and receice score
    int score = playTyping(words, choiceTwoSize - 4);

    // If score is highest yet, overwrite bestScore with new high score
    if (score > bestScore) {
        bestScore = score;
    }

    // Increment the word length for the next run
    choiceTwoSize++;
}

// Run choice three
void runChoiceThree(vector<string> dictionary, vector<string> misspelledWords) {
    cout << "   Displaying word list entries.\n";
    cout << "   Which words do you want to display?\n";
    cout << "      A. Dictionary of all words\n";
    cout << "      B. Wrongly spelled common misspelled words\n";
    cout << "      C. Correctly spelled common misspelled words\n";
    cout << "   Your choice --> ";

    // Within option 3, take in user's second choice
    char subChoice;
    cin >> subChoice;
    subChoice = tolower(subChoice);

    if (subChoice == 'a') {
        // User chose A
        cout << "   Enter the start and end indices between 0 and 263532: ";

        // Take in start and end
        int start, end;
        cin >> start >> end;

        // Display words within range
        displayDictionary(dictionary, start, end);
    } else if (subChoice == 'b') {
        // User chose B
        cout << "   Enter the start and end indices between 0 and 113: ";

        // Take in start and end
        int start, end;
        cin >> start >> end;

        // Display MISSPELLED words within range
        displayMisspelledWords(misspelledWords, start, end, false);
    } else if (subChoice == 'c') {
        // User choice C
        cout << "   Enter the start and end indices between 0 and 113: ";

        // Take in start and end
        int start, end;
        cin >> start >> end;

        // Take in CORRECTLY SPELLED words within range
        displayMisspelledWords(misspelledWords, start, end, true);
    }
}

int main() {
    srand(1);

    // Create vectors for dictionary.txt and misspelledWords.txt
    vector<string> dictionary, misspelledWords;
    readWordsIntoVector(dictionary, "dictionary.txt");
    readWordsIntoVector(misspelledWords, "misspelledWords.txt");

    cout << "There are 263533 words in the full dictionary.\nThere are 114 commonly misspelled words.\n\n";

    // Store bestScore and the size of words for option 2
    int bestScore = 0;
    int choiceTwoSize = 5;

    // Run until player exits
    while (true) {
        cout << "Select a menu option:\n   1. Spell commonly misspelled words (timed)\n";
        cout << "   2. Type random words from full dictionary (timed)\n   3. Display some words from one of the lists\n";
        cout << "   4. Use binary search to lookup a word in full dictionary\n   5. Set word length to use with full dictionary\n";
        cout << "   6. Exit the program\nYour choice --> ";

        // Receive menu choice
        int choice;
        cin >> choice;

        if (choice == 1) {
            // User chose 1, run accordingly
            runChoiceOne(misspelledWords, bestScore);
        } else if (choice == 2) {
            // User chose 2, run accordingly
            runChoiceTwo(dictionary, choiceTwoSize, bestScore);
        } else if (choice == 3) {
            // User chose 3, run accordingly
            runChoiceThree(dictionary, misspelledWords);
        } else if (choice == 4) {
            // User chose 4
            cout << "Enter the word to lookup: ";

            // Take in word to search
            string word;
            cin >> word;

            // Run search algorithm for the word
            search(dictionary, word);
        } else if (choice == 5) {
            // User chose 5
            cout << "Enter new wordLength: ";

            // Take in user input and insert into word length for option 2
            cin >> choiceTwoSize;
        } else {
            // User chose 6
            // Break program loop
            cout << "Exiting program\n"
                    "Best score was " << bestScore;
            break;
        }
    }

    // Exit the program
    return 0;
}
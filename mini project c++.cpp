#include <iostream>  

 // For measuring the time user takes 
#include <ctime>  

// For rand() and srand() to get random numbers
#include <cstdlib>    

#include <string> 

 // For storing  list of words
#include <vector>     

using namespace std;

// to display the results at the end of  game
void displayResults(int correctWords, double totalTime) {
  
  // Display game over message
    cout << "\nGame Over!\n"; 
    
     // Show the number of words typed
    cout << "Correct words: " << correctWords << endl; 
    
    // Show the total time taken
    cout << "Total time: " << totalTime << " seconds" << endl; 
    
    // Show typing speed
    cout << "Typing speed: " << correctWords / totalTime << " words per second" << endl; 
}

int main() {
    // list of words for  player to type
    vector<string> words = {"apple", "banana", "orange", "grape", "mango", "pear", "cherry", "peach", "melon", "plum"};
    
    
    // Number of words the player will type 
    int numWords = 5; 
    
     // stores what the player types
    string userInput;
    
    // shows how many words player types correctly
    int correctWords = 0; 

    //random number generator that rand() generates 
    srand(time(0));

    // Tell the player what to do
    cout << "Type the following words as quickly as possible!\n";

    // Start the timer 
    time_t startTime = time(0);

    // Loop to give the player words to type
    for (int i = 0; i < numWords; ++i) {
        
        // Pick  random word from 'words' list
        string randomWord = words[rand() % words.size()];

        // Show random word to the player
        cout << randomWord << ": ";

        // Get the word by the player
        cin >> userInput;

        // Check if the word is correct
        if (userInput == randomWord) {
            ++correctWords; 
            // If correct, increase the count of correct words
        }
    }

    // Stop the timer and record time
    time_t endTime = time(0);

    // Calculate  total time taken by player
    double totalTime = difftime(endTime, startTime);

    // display the game results
    displayResults(correctWords, totalTime);

    return 0;
}
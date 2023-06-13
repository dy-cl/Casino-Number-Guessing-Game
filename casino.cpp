#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Select stakes function
int GetUserChoice()
{
    int choice;    

    while (true){
        cout << "1. 0 - 1 (2x your money)\n"
            "2. 0 - 4 (5x your money)\n"
            "3. 0 - 9 (10x your money)\n"
            "Choose your stakes: \n";
    
            cin >> choice; 

            if (choice == 1 || choice == 2 || choice == 3){
                break;
            } else {
                cout << "Invalid Choice. Please choose again\n";
            }
    } 
    return choice;
}

// Select wager function
int SelectWager(int money)
{
    double wager;

    while (true) {
        cout << "Select amount of money to wager: ";
        cin >> wager;

        if (wager > money){
            cout << "You don't have enough money. Please choose again\n";
        } else if (wager <= 0){
            cout << "Wager cannot be zero or negative. Please choose again\n";
        } else {
            break;
        }
    }    
    return static_cast<int>(wager); 
}
    

// Guess number function
int GuessNumber(int random, int N)
{
    int guess;

    while (true){
        cout << "Guess a number between 0 and " << N-1 << ": ";
        cin >> guess;

        if (0 <= guess && guess <= N-1) { // If guess is in possible values
            break;
        } else {
            cout << "Invalid guess. Please choose again\n";
        }
    }
    return guess;
}

// Main
int main()
{   
    // Set starting money
    int money = 100;

    while (money > 0) {

        int UserChoice = GetUserChoice();

        cout << "Your money is: " << money << endl;
        
        int N;

        // Set N depending upon user stakes selection
        if (UserChoice == 1){
            N = 2;
        } else if (UserChoice == 2){
            N = 5;
        } else if (UserChoice == 3){
            N = 10;
        }

        // Generate random number using current time as seed
        srand(time(0));
        int random = rand() % N;

        // Get user wager and guess
        int wager = SelectWager(money);
        int guess = GuessNumber(random, N);

        // Update money
        if (guess == random){
            money = money + (wager*N);
        } else {
            money = money - wager;
        }
        
        cout << "Number was : " << random << ", " << "You guessed: " << guess << endl;
        cout << "Your money is: " << money << endl;

        // Game ending logic
        if (money <= 0) {
            cout << "Game over. You have run out of money.\n";
        } else {
            char playAgain;
            cout << "Do you want to play again? (Y/N): ";
            cin >> playAgain;

            if (playAgain != 'Y' && playAgain != 'y'){
                break;
            }
        }
    }
    
    return 0;
}  
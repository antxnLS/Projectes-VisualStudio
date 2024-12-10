#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int getCard() {
    vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 }; // 11 is Ace
    return cards[rand() % cards.size()];
}

int calculateTotal(vector<int>& hand) {
    int total = 0, aces = 0;
    for (int card : hand) {
        total += card;
        if (card == 11) aces++;
    }
    while (total > 21 && aces > 0) { // Adjust for Aces
        total -= 10;
        aces--;
    }
    return total;
}

void printHand(const vector<int>& hand) {
    for (int card : hand) cout << card << " ";
    cout << "(Total: " << calculateTotal(const_cast<vector<int>&>(hand)) << ")" << endl;
}

int main() {
    srand(time(0));  // Seed for random cards
    int balance = 100, bet;
    char choice;

    cout << "Welcome to Blackjack! You start with 100 euros." << endl;

    while (balance > 0) {
        cout << "\nCurrent balance: " << balance << " euros" << endl;
        do {
            cout << "Enter your bet (up to " << balance << " euros): ";
            cin >> bet;
        } while (bet <= 0 || bet > balance);

        vector<int> playerHand, dealerHand;

        // Initial cards
        playerHand.push_back(getCard());
        playerHand.push_back(getCard());
        dealerHand.push_back(getCard());
        dealerHand.push_back(getCard());

        cout << "\nYour hand: ";
        printHand(playerHand);
        cout << "Dealer's visible card: " << dealerHand[0] << endl;

        // Player turn
        while (true) {
            cout << "Hit or Stand? (h/s): ";
            cin >> choice;
            if (choice == 'h') {
                playerHand.push_back(getCard());
                cout << "Your hand: ";
                printHand(playerHand);
                if (calculateTotal(playerHand) > 21) {
                    cout << "You busted! Dealer wins." << endl;
                    balance -= bet;
                    break;
                }
            }
            else if (choice == 's') {
                break;
            }
            else {
                cout << "Invalid choice, please enter 'h' or 's'." << endl;
            }
        }

        // Dealer turn
        if (calculateTotal(playerHand) <= 21) {
            cout << "\nDealer's hand: ";
            printHand(dealerHand);
            while (calculateTotal(dealerHand) < 17) {
                dealerHand.push_back(getCard());
                cout << "Dealer hits: ";
                printHand(dealerHand);
            }

            int playerTotal = calculateTotal(playerHand);
            int dealerTotal = calculateTotal(dealerHand);

            if (dealerTotal > 21) {
                cout << "Dealer busts! You win." << endl;
                balance += bet;
            }
            else if (playerTotal > dealerTotal) {
                cout << "You win!" << endl;
                balance += bet;
            }
            else if (playerTotal < dealerTotal) {
                cout << "Dealer wins." << endl;
                balance -= bet;
            }
            else {
                cout << "It's a draw." << endl;
            }
        }

        if (balance == 0) {
            cout << "\nYou're out of money! Game over." << endl;
            break;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        if (choice != 'y') break;
    }

    cout << "Thanks for playing! Your final balance is " << balance << " euros " << endl;
    cout << "Your winnings are: " << balance - 100 << " euros ";
    return 0;
}


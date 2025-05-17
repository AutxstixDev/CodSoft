#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0, lower = 1, upper = 100;

    cout << "?? Welcome to the Number Guessing Game!\n";

    while (true) {
        cout << "Guess the number (" << lower << "-" << upper << "): ";
        cin >> guess;
        attempts++;

        if (guess == secret) {
            cout << "? You guessed it in " << attempts << " attempt(s)!\n";
            break;
        } else if (guess < secret) {
            cout << "Too low!\n";
            if (guess >= lower) lower = guess + 1;
        } else {
            cout << "Too high!\n";
            if (guess <= upper) upper = guess - 1;
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int myrandom(int max) {
    return rand() % max + 1; 
}

int main() {
    int balance = 1000, bet, guess, dice;

    srand(getpid()); 

    while (1) {
        printf("Your current balance: %d\n", balance);
        printf("Enter your bet amount: ");
        scanf("%d", &bet);

        if (bet <= 0 || bet > balance) {
            printf("Invalid bet amount! Please enter a value between 1 and %d.\n", balance);
            continue;
        }

        printf("Guess a number between 1 and 6 (or 0 to quit): ");
        scanf("%d", &guess);

        if (guess == 0) {
            printf("Game over! Your final balance: %d\n", balance);
            return 0;
        }

        if (guess < 1 || guess > 6) {
            printf("Invalid guess! Please choose a number between 1 and 6.\n");
            continue;
        }

        printf("Throwing the die...\n");
        sleep(2);
        dice = myrandom(6);
        printf("The die shows: %d\n", dice);

        if (guess == dice) {
            int winnings = bet * 3;
            balance += winnings;
            printf("Congratulations! You won %d.\n", winnings);
        } else {
            balance -= bet;
            printf("You lost %d.\n", bet);
        }
        printf("your balance %d\n",balance);
        if (balance <= 0) {
            printf("GAME OVER! Your balance is zero.\n");
            return 0;
        }
    }
}

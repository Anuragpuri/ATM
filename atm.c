#include <stdio.h>

// Function prototypes
void check_balance(float balance);
float deposit_money(float balance);
float withdraw_money(float balance);
void atm_menu();

int main() {
    float balance = 10000.0; // Initial balance
    int choice;

    do {
        atm_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                check_balance(balance);
                break;
            case 2:
                balance = deposit_money(balance);
                break;
            case 3:
                balance = withdraw_money(balance);
                break;
            case 0:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}

// Function to display the ATM menu
void atm_menu() {
    printf("\n===== ATM Menu =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("0. Exit\n");
}

// Function to check balance
void check_balance(float balance) {
    printf("Your current balance is: ₹%.2f\n", balance);
}

// Function to deposit money
float deposit_money(float balance) {
    float amount;
    printf("Enter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Deposit must be greater than zero.\n");
    } else {
        balance += amount;
        printf("₹%.2f deposited successfully.\n", amount);
        printf("New balance: ₹%.2f\n", balance);
    }

    return balance;
}

// Function to withdraw money
float withdraw_money(float balance) {
    float amount;
    printf("Enter amount to withdraw: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be greater than zero.\n");
    } else if (amount > balance) {
        printf("Insufficient balance! You have ₹%.2f\n", balance);
    } else {
        balance -= amount;
        printf("₹%.2f withdrawn successfully.\n", amount);
        printf("Remaining balance: ₹%.2f\n", balance);
    }

    return balance;
}

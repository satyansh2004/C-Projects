// ATM machine simulator
#include <stdio.h>

// Check balance
void checkBalance(int balance)
{
    printf("Your Bank Balance is: %d", balance);
}

// Deposit
void deposit(int balance)
{
    int amount;
    printf("\nEnter amount to Deposit: ");
    scanf("%d", &amount);

    printf("Deposited: %d\nYour Balance: %d", amount, balance + amount);
}

// Withdraw
void withdraw(int balance)
{
    int amount;
    printf("\nEnter amount to Withdraw: ");
    scanf("%d", &amount);

    if (amount > balance)
    {
        printf("\nInsufficient Balance");
    }
    else
    {
        printf("Deducted: %d\nYour Balance: %d", amount, balance - amount);
        // return balance - amount;
    }
}

int main(void)
{
    int balance = 10000;
    // int deposit, withdraw;
    int service;

    printf("\nWelcome to the Bank!\n\nChoose your service:\n(Type 1): Check Balance\n(Type 2): Withdraw\n(Type 3): Deposit\n");
    printf("\nEnter service: ");
    scanf("%d", &service);

    switch (service)
    {
    case 1:
        checkBalance(balance);
        break;
    case 2:
        withdraw(balance);
        break;

    case 3:
        deposit(balance);
        break;
    default:
        printf("\nService not available");
        break;
    }
}
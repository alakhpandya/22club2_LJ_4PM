/*
#include<stdio.h>

int main()
{
    int balance = 1000, dep;
    printf("Your current balance = %d", balance);
    printf("\nAmount to deposite: ");
    scanf("%d", &dep);
    balance += dep;
    printf("\nNew Balance = %d", balance);
    return 0;
}
*/

// File handling:
#include<stdio.h>
#include<stdlib.h>

void updateBalance(int balance){
    FILE *fp;
    fp = fopen("account.txt", "w");
    fprintf(fp, "%d", balance);
    fclose(fp);
}
void updateTransactions(int amount){
    FILE *fp;
    fp = fopen("transactions.txt", "a");
    fprintf(fp, "%d\n", amount);
    fclose(fp);
}
void getLastTransaction(){
    FILE *fp;
    fp = fopen("transactions.txt", "r");
    
    fclose(fp);
}

int main()
{
    int balance = 1000, amount, current_bill, op;
    FILE *fp;
    fp = fopen("account.txt", "r");
    // scanf("%d", &balance);
    fscanf(fp, "%d", &balance);
    FILE *bill_file;
    bill_file = fopen("bills.txt", "r");
    fscanf(bill_file, "%d", &current_bill);
    fclose(bill_file);
    fclose(fp);
    while (1){
        printf("\nPress:\n");
        printf("1 for deposit\n");
        printf("2 for withdrawl\n");
        printf("3 to check balance\n");
        printf("4 to view the last transaction\n");
        printf("9 to exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nAmount to deposite: ");
            scanf("%d", &amount);
            balance += amount;
            printf("\nNew Balance = %d\n", balance);
            updateBalance(balance);
            updateTransactions(amount);
            break;
        
        case 2:
            printf("\nAmount to withdraw: ");
            scanf("%d", &amount);
            balance -= amount;
            printf("\nNew Balance = %d\n", balance);
            updateBalance(balance);
            updateTransactions(-amount);
            break;
        
        case 3:
            printf("\nCurrent Balance = %d\n", balance);
            printf("Your current bill = %d\n", current_bill);
            break;
        
        case 9:
            exit(0);

        default:
            break;
        }
    }
    return 0;
}

// Next Class: ftell, fseek (in getLastTransaction function) and strings in file
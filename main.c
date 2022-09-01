int main(int num[])
{
    system("cls");
    printf("                   Welcome to 'Hamro Bank'              ");
    int choice;
    top:
    printf("\n\n\nPlease choose an option:\n");
    printf("1. Services\n2. Loans\n3. Exit\n");
    printf("Enter your choice(1/2/3):\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        top1:
        system("cls");
        printf("Please choose an option.\n");
        printf("\n1. Already have an account.\n2. Create a new account.\n3. Exit\n");
        printf("\n Enter your choice(1/2/3):\n");
        scanf("%d",&choice);
        if (choice==1)
         services1(num);

        else if (choice==2)
        card();
         
         else if (choice==3)
         ex();

        else
        {
            printf("Invalid Choice!! Try again.");
            getch();
            goto top1;
        }
    }
    else if (choice==2)
    {

        system("cls");
        loan(num);
        e:
        printf("\nDo you want to exit?(1/0)\n");
        scanf("%d",&choice);
        if (choice==0)
        {
        system("cls");
        goto top;
        }
        else if (choice==1)
        ex(); 
        else
        {
        printf("Invalid choice!!"); 
        goto e;
        }
    }
    else if (choice==3)
    ex();

    else
    {
        printf("Invalid choice!!");
        getch();
        goto top;
    }
}

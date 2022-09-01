void regis(int num[])
{
    FILE *fp;
    struct member mb;
    int choice,i;
    fp = fopen("regis.txt","ab");
    printf("\nPlease fill in the details: \n\n");
    while(1)
    {
    printf("First Name: ");
    fflush(stdin);
    gets(mb.fname);
    printf("Surname: ");
    fflush(stdin);
    gets(mb.sname);
    printf("Age: ");
    scanf("%d",&mb.age);
    printf("Address: ");
    fflush(stdin);
    gets(mb.address);
    printf("Date of birth(yyyy-mm-dd): ");
    fflush(stdin);
    gets(mb.dob);
    printf("Gender: ");
    fflush(stdin);
    gets(mb.gender);
    printf("Phone number: ");
    scanf("%s",mb.phone);
    printf("Add a password: ");
    fflush(stdin);
    gets(mb.password);
    uff:
    printf("Enter your account number: ");
    scanf("%d",&mb.code);
    for(i=0;i<1;i++)
    {
        if(num[i]==mb.code)
        {
            printf("\nMinimum Amount for Account opening is Rs. 1000.\n\n");
            eta:
            printf("\nEnter the amount you want to deposit: ");
            scanf("%f",&mb.money);
            if (mb.money>=1000)
            {
                fwrite(&mb,sizeof(mb),1,fp);
                printf("New member registered.\n");
                getch();
                ex();
            }
            else
            {
            printf("Amount not sufficient.\n\n");
            getch();
            goto eta;
            }
            break;
            ex();
            }
        else 
        {
            printf("\n!!Account number not matched.Please enter the given account number.!!\n\n");
            getch();
            goto uff;
        }
    }
    }
    
}

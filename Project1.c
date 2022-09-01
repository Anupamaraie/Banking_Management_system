#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define underline "\033[4m"
#define closeunderline "\033[0m"
#define N 1000
struct member
{
    char fname[50];
    char sname[50];
    int age;
    char address[30];
    char gender[20];
    char phone[20];
    int code;
    float money;
    int year;
    int month;
    int days;
    char dob[50];
    char dob1[50];
    int codes;
    int amt;
    char password[50];
};
void home();
void regis();
void card();
void ex();
void login();
void services1();
void loan();
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
            printf("Invalid Choice!!! Try again.");
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
void loan(int num[])
{
    int choice,c;
    int idn,ch;
    int y, m,d,y1,m1,d1;
    char yn[20];
    int j = 0;
    char s[]= "y";
    char S[]="Y";
    char T[]="N";
    char t[]="n";
    struct member mb;
    FILE *fp, *fp1, *fp2, *fp3;
    l:
    system("cls");
    printf("Enter:\n1. Payment\n2. Loan\n3. Display\n4. Delete\n5. Exit\n\nYour Choice: ");
    scanf("%d",&choice);
    if (choice==1)
    {
        la:
        system("cls");
        printf("Choose:\n1. Interest\t\t\t2.Principal\n\nEnter your choice: ");
        scanf("%d",&c);
      if (c==1)
      {
        system("cls");
        printf("THE PAYMENT DUE CANNOT EXCEED THREE MONTHS.!!\n\n\n");
         fp1 = fopen("loan.txt","rb");
        printf("Enter your account number: ");
        scanf("%d",&idn);
        printf("Enter your first name: ");
        fflush(stdin);
        gets(yn);
        rewind(fp1);
        while(fread(&mb,sizeof(mb),1,fp1)==1)
        {
            if(strcmp(yn,mb.fname)==0 && mb.codes == idn)
            {
                printf("Record Found.\n\n");
                if(mb.amt<=100000)
                choice=15;
                if(mb.amt<=500000 && mb.amt>100000)
                choice=10;
                if(mb.amt<=1000000 && mb.amt>500000)
                choice=5;
                printf("Enter the Date of Payment (yyyy mm dd): ");
                scanf("%d%d%d",&y,&m,&d);
                printf("Enter the last date of Payment (yyyy mm dd): ");
                scanf("%d%d%d",&y1,&m1,&d1);
                if (m<13 && d<33)
                {
                    rewind(fp1);
                    while(fread(&mb,sizeof(mb),1,fp1)==1)
                    {
                        if(abs(m-m1)==1 && choice == 15 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = (0.15*mb.amt)/12;
                            printf("The amount you have to pay is %d rupees. You cannot pay any less or any more.\n",d);
                            printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m-m1)==2 && choice == 15 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.15*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any lessor any more.\n",d);
                             printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                         else if(abs(m1-m)==3 && choice == 15 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.15*mb.amt)/12) + ((0.02*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any less or any more.\n",d);
                                 printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==1 && choice == 10 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = (0.10*mb.amt)/12;
                            printf("The amount you have to pay is %d rupees. You cannot pay any less or any more.\n",d);
                            printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==2 && choice == 10 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.10*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any less or any more.\n",d);
                             printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==3 && choice == 10 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.10*mb.amt)/12) + ((0.02*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any less or any more.\n",d);
                                 printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==1 && choice == 5 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = (0.05*mb.amt)/12;
                            printf("The amount you have to pay is %d rupees. You cannot pay any less or any more.\n",d);
                            printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==2 && choice == 5 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.05*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any less or any more.\n",d);
                             printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if(abs(m1-m)==3 && choice == 5 && (abs(d1-d)<6 && abs(d1-d)>0) && abs(y1-y)==0)
                        {
                            int d = ((0.05*mb.amt)/12) + ((0.02*mb.amt)/12) + ((0.02*mb.amt)/12);
                            printf("The amount you have to pay is %d rupees (Including the 2per charge). You cannot pay any less or any more.\n",d);
                                 printf("Enter the amount: ");
                                scanf("%d",&ch);
                            if(ch==d)
                            {
                                printf("Payment successful.\n");
                                getch();
                                
                                ex();
                            }
                            else
                            {
                            printf("Error!!\n");
                            getch();
                            ex();
                            }
                        }
                        else if (abs(m1-m)>3)
                        {
                            printf("The interest due has finished. We will be seizing the item.\n");
                            getch();
                            
                                ex();
                        }
                        else
                        {
                            printf("\n\nError!!\n");
                            getch();
                            ex();
                        }

                    }
                }
            }
        }
        fclose(fp1);
        }
        
    else if (c==2)
    {
        printf("\nEnter your account number: ");
        scanf("%d",&idn);
        printf("Enter your first name: ");
        fflush(stdin);
        gets(yn);
        fp1 = fopen("loan.txt","rb");
        fp3 = fopen("p.txt","wb");
        rewind(fp1);
        while(fread(&mb,sizeof(mb),1,fp1)==1)
        {
            if(mb.codes == idn && strcmp(yn,mb.fname)==0)
            {
                printf("Record found.\n\n");
                printf("Enter the Date of payment: ");
                scanf("%d%d%d",&y1,&m1,&d1);
                k:
                printf("Enter the amount: ");
                scanf("%d",&c);
                if (c<mb.amt)
                {
                    mb.amt = mb.amt-c;
                    if(fwrite(&mb,sizeof(mb),1,fp3)==1)
                    printf("Payment Successful.");

                    printf("%d rupees is paid. The remaining amount to be paid is %d rupees.\n\n",c,mb.amt);
                    getch();
                }
                else if (c>mb.amt)
                {
                    printf("Error!!\n Entered amount more than payment amount.\n\n");
                    getch();
                    goto k;
                }
                else if (c==mb.amt)
                {
                    rewind(fp1);
                    while(fread(&mb,sizeof(mb),1,fp1)==1)
                    {
                        if(mb.codes != idn && strcmp(mb.fname,yn) !=0)
                        fwrite(&mb,sizeof(mb),1,fp3);

                        printf("Payment fully done.\n\n");
                    }
                }
                else
                fwrite(&mb,sizeof(mb),1,fp3);

                fclose(fp1);
                fclose(fp3);
                remove("loan.txt");
                rename("p.txt","loan.txt");
                getch();
                ex();
            }
        }
    }
    else
    {
        printf("Invalid Choice!! Try again\n\n");
        getch();
        goto la;
    }
      
    }

    else if (choice==2)
    {
    system("cls");
    printf("Reminder: For the loan, you need to have an normal account in our bank.\n");
    yo:
    printf("\nDo you want to apply for loan?(y/n)\nYour Choice: ");
    fflush(stdin);
    gets(yn);
    if(strcmp(yn,s)==0 || strcmp(yn,S)==0)
    {
        system("cls");
        printf("\n\n\nEnter your account number: ");
        scanf("%d",&idn);
        fp = fopen("regis.txt","rb");
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
            if (mb.code == idn)
            {
                printf("The details of the given account number:\n\n");
            printf(underline"Name"closeunderline": %s %s\t"underline"Age"closeunderline": %d\t\t"underline"Address"closeunderline": %s\t\t"underline"Gender"closeunderline": %s\n",mb.fname,mb.sname,mb.age,mb.address,mb.gender);
            getch();
            printf("\n\nIs this your details?(y/n)\nYour Choice: ");
            fflush(stdin);
            gets(yn);
            if(strcmp(yn,s)==0 || strcmp(yn,S)==0)
            {
                system("cls");
                printf("Please learn about the details of interest:\n\n1. If the amount is less than 1,00,000 rupees then the interest is 15 percent per annum.\n");
                printf("2. If the amount is less than 5,00,000 rupees then the interest is 10 percent per annum.\n");
                printf("3. If the amount is less than 10,00,000 rupees then the interest is 5 percent per annum.\n");
                printf("4. The loan amount cannot exceed 10,00,000 rupees.\n");
                printf("5. If the principal amount is paid, the interest for the next month will be from the remaining payment amount.\n");
                getch();
                system("cls");
                 fp1 = fopen("loan.txt","ab");
                 lo:
                printf(underline"'LOAN Procedures'           \n"closeunderline);
                printf("\nPlease fill up the details:\n\n");
                printf("First Name: ");
                fflush(stdin);
                gets(mb.fname);
                 printf("Surname: ");
                fflush(stdin);
                gets(mb.sname);
                 printf("Date of Birth(yyyy-mm-dd): ");
                fflush(stdin);
                gets(mb.dob1);
                printf("Date of loan withdrawal:- ");
                 printf("Year Month Days: ");
                scanf("%d%d%d",&mb.year,&mb.month,&mb.days);
                printf("Enter your account number (of the bank): ");
                scanf("%d",&mb.codes);
                 printf("Amount: ");
                 scanf("%d",&mb.amt);
                if(mb.month<13 && mb.days<33)
                {
                 if(mb.code == mb.codes)
                     {
                 if( mb.amt<100000)
                 {
                     float d = (0.15*mb.amt)/12;
                     printf("Since the amount is lesser than 1,00,000. The interest is 15 percent per annum. You have to pay %0.3f rupees monthly. If not, you have to pay 2 percent extra.\n ",d);
                     getch();
                 }
                 else if (mb.amt<500000)
                 {
                      float d = (0.10*mb.amt)/12;
                     printf("Since the amount is lesser than 5,00,000. The interest is 10 percent per annum. You have to pay %0.3f rupees monthly. If not, you have to pay 2 percent extra.\n ",d);
                      getch();
                 }
                 else if (mb.amt<1000000)
                 {
                      float d = (0.05*mb.amt)/12;
                     printf("Since the amount is lesser than 10,00,000. The interest is 5 percent per annum. You have to pay %0.3f rupees monthly. If not, you have to pay 2 percent extra.\n ",d);
                       getch();                  
                 }
                 else
                 {
                     printf("\n\nWe are sorry to inform that the amount exceeds the bank limitations. So, we cannot provide you loan you need.\n");
                    ex();
                 }
                 if (fwrite(&mb,sizeof(mb),1,fp1))
                 printf("\nLoan Successfully Provided. Please pay the interest monthly without delay.\n");
                 fclose(fp1);
                 fclose(fp2);
                  getch();
                  ex();
                   break;
                    } 
                    else
                    {
                        printf("\nAccount number not matched. PLease Try again!!\n");
                        getch();
                        system("cls");
                        goto lo;
                    }
                }
                else
                {
                    printf("Month and Days cannot exceed 12 and 32 respectively.");
                    getch();
                    goto lo;
                }
            }
            }
        }
        printf("It seems you dont have a normal account in our bank. Please open the account account to follow loan procedures.");
    }
    else if(strcmp(yn,t)==0 || strcmp(yn,T)==0)
    {
        getch();
        ex();
    }
    else
    {
        printf("Invalid Choice!! Try Again.");
        goto yo;
    }
    }

    else if(choice==3)
    {
        fp1 = fopen("loan.txt","rb");
        printf("\nOnly office personnel have the access to this option. Please login to verify your identity.\n");
        getch();
        system("cls");
        int i=0;
    char pn[20],pw[20],str[20], c = ' ';
    char ad[] = "1234567890";
    char ap[] = "password";
    int a=0;
    printf("Deletes and spaces count as letter in delete. Please enter your password carefully.!!\n\n");
    printf("                    !!! LOGIN !!!\n\n");
    printf(underline"PHONE NUMBER"closeunderline":\n ");
    fflush(stdin);
    gets(pn);
    printf(underline"\nPASSWORD"closeunderline":\n ");
    fflush(stdin);
    while (i <= 100)
    {
        str[i] = getch();
        if (str[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    str[i] = '\0';
    int j = 1;
    if((strcmp(pn,ad)==0) && (strcmp(str,ap)==0))
    {
        search:
        system("cls");
        printf("                       WELCOME!! Boss             \n\n\n\nHere is the data you required.\n\n");
        getch();
        rewind(fp1);
        while(fread(&mb,sizeof(mb),1,fp1)==1)
        {
            printf("%d.\n",j);
        printf(underline"Name"closeunderline": %s %s\n"underline"Date of birth"closeunderline": %s\n"underline"Date of loan withdrawal"closeunderline":%d-%d-%d\n"underline"Amount"closeunderline":%d rupees\n",mb.fname,mb.sname,mb.dob,mb.year,mb.month,mb.days,mb.amt);
        printf(underline"Account Number"closeunderline": %d\n",mb.codes);
        if(mb.amt<=100000)
        printf(underline"Interest Rate"closeunderline": 15 percent\n");
        if(mb.amt<500000 && mb.amt>100000)
        printf(underline"Interest Rate"closeunderline": 10 percent\n");
        if(mb.amt<1000000 && mb.amt>500000)
        printf(underline"Interest Rate"closeunderline": 5 percent\n");
        j++;
        }
        getch();
        ex();
        fclose(fp1);
    }
    }
    else if (choice==4)
    {
        printf("\nOnly office personnel have the access to this option. Please login to verify your identity.\n");
        getch();
        system("cls");
        int i=0;
    char pn[20],pw[20],str[20], c = ' ';
    char ad[] = "1234567890";
    char ap[] = "password";
    int a=0;
    printf("Deletes and spaces count as letter in delete. Please enter your password carefully.!!\n\n");
    printf("                    !!! LOGIN !!!\n\n");
    printf(underline"PHONE NUMBER"closeunderline":\n ");
    fflush(stdin);
    gets(pn);
    printf(underline"\nPASSWORD"closeunderline":\n ");
    fflush(stdin);
    while (i <= 100)
    {
        str[i] = getch();
        if (str[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    str[i] = '\0';
    int j = 1;
    if((strcmp(pn,ad)==0) && (strcmp(str,ap)==0))
    {
         system("cls");
           printf("WELCOME!!\n\n");
           fp1 = fopen("loan.txt","rb");
    fp2 = fopen("delete.txt","wb");
    printf("Enter your account number: ");
    scanf("%d",&idn);
    rewind(fp1);
    while(fread(&mb,sizeof(mb),1,fp1)==1)
    {
        if (idn == mb.codes)
        {
        printf(underline"Name"closeunderline": %s %s\n"underline"Date of birth"closeunderline": %s\n"underline"Date of loan withdrawal"closeunderline":%d-%d-%d\n"underline"Amount"closeunderline":%d rupees\n",mb.fname,mb.sname,mb.dob,mb.year,mb.month,mb.days,mb.amt);
        printf(underline"Account Number"closeunderline": %d\n",mb.codes);
        if(mb.amt<=100000)
        printf(underline"Interest Rate"closeunderline": 15 percent");
        if(mb.amt<500000 && mb.amt>100000)
        printf(underline"Interest Rate"closeunderline": 10 percent");
        if(mb.amt<1000000 && mb.amt>500000)
        printf(underline"Interest Rate"closeunderline": 5 percent");
        printf("\n\nIs this the record do you want to delete?(y/n)\n\n");
        hmm:
        printf("Enter your choice: ");
        fflush(stdin);
        gets(yn);
        if(strcmp(yn,s)==0 || strcmp(yn,S)==0)
        {
            rewind(fp1);
        while(fread(&mb,sizeof(mb),1,fp1)==1)
        {
        if(idn != mb.code)
        fwrite(&mb,sizeof(mb),1,fp2);
        }
        printf("Record deleted successfully.\n");
        }
        else if (strcmp(yn,t)==0 || strcmp(yn,T)==0)
        {
        rewind(fp1);
        while(fread(&mb,sizeof(mb),1,fp1)==1)
        {
        fwrite(&mb,sizeof(mb),1,fp2);
        }
        printf("Record found but not deleted.\n");
        }
        else
        {
        printf("Invalid choice!!\n");
        goto hmm;
        }
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("loan.txt");
    rename("delete.txt","loan.txt");
    getch();
    ex();
    }
    else
    {
        printf("Invalid Login. Try Again\n\n");
        getch();
        ex();
    }

    }
    else if (choice==5)
    ex();
    
    else
    {
        printf("Invalid Choice!! Try again\n\n");
        getch();
        goto l;
    }
}
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
void services1(int num[])
{
    system("cls");
    FILE *fp, *fp1;
    struct member mb;
    int choice,a,c=0;
    char yn,pw[50],name[20],name1[20];
    char str[] = "staffonly";
    float am;
    int idn;
    s:
        printf(underline"For Official Use"closeunderline":""                                                                                        "underline"For customer use"closeunderline":\n");
        printf("1. Update the details of a member                                                                      4. Deposit/Withdraw Money\n");
        printf("2. Delete the details of a member                                                                      5. Transfer Money\n");
        printf("3. Show the details of all the members\n");
        printf("\n\n                                               "underline"Neutral Use"closeunderline":\n");
        printf("                                                6. Search for the details of a member\n");
        printf("                                                7. Exit\n");

         printf("\n\nChoose a number according to your need(1-8):\n");
        scanf("%d",&choice);
        if (choice>=1 || choice<=7)
        {
            switch(choice)
            {
                case 6:
                system("cls");
                goto search;
                break;

                case 1:
                system("cls");
                goto update;
                break;
                     
                case 2:
                system("cls");
                goto delete;

                case 3:
                system("cls");
                goto details;
                break;

                case 4:
                system("cls");
                goto dw;
                break;

                case 5:
                system("cls");
                goto transfer;;
                break;

                case 7:
                system("cls");
                ex();
                break;
    
            default:
            printf("Invalid choice!!\n\n");
            getch();
            }
        uff:
        printf("Do you want to :\n 1. Continue?\n 2. Exit?\n\nEnter your choice: ");
        scanf("%d",&choice);
        if (choice==2)
        ex();
        else if (choice==1)
        {
            system("cls");
           goto s;
        }
        else
        {
            printf("Invalid choice!!\n");
            goto uff;
        }
        }


transfer:
       printf("Enter the "underline"password"closeunderline": ");
       fflush(stdin);
       gets(pw);
       fp =fopen("regis.txt","rb");
       while(fread(&mb,sizeof(mb),1,fp)==1)
       if(strcmp(mb.password,pw)==0)
       {
        system("cls");
        printf("WELCOME!! %s\n\n\n",mb.fname);
        int idn1;
        ufff:
        printf("Enter the SENDER's account number: ");
        scanf("%d",&idn);
        printf("Enter the SENDER's first name: ");
        fflush(stdin);
        gets(name);
        rewind(fp);
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
            if(idn == mb.code && (strcmp(name,mb.fname)==0))
            {
                fp1 = fopen("tf.txt","wb");
                printf("Enter the amount: ");
                scanf("%f",&am);
                printf("\nEnter the RECEIVER's account number: ");
                scanf("%d",&idn1);
                printf("Enter the RECEIVER's first name: ");
                fflush(stdin);
                gets(name1);
                mb.money = mb.money-am;
                fwrite(&mb,sizeof(mb),1,fp1);
                rewind(fp);
                while(fread(&mb,sizeof(mb),1,fp))
                {
                    if (idn1 == mb.code && (strcmp(name1,mb.fname)))
                    {
                        mb.money = mb.money+am;
                        fwrite(&mb,sizeof(mb),1,fp1);
                        printf("\n%0.3f rupees transfered from account number %d to %d successfully.\n",am,idn,idn1);
                        getch();
                    }
                    else
                    {
                        fwrite(&mb,sizeof(mb),1,fp1);
                    }
                }   
            }
            else
            {
                fwrite(&mb,sizeof(mb),1,fp1);
            }
        }
                        fclose(fp);
                        fclose(fp1);
                        remove("regis.txt");
                        rename("tf.txt","regis.txt");
                        system("cls");
                        ok:
            printf("\nEnter '1' to see the updated details, '2' to exit.\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
            goto search;
        }
        else if (choice==2)
        ex();
        else
        {
            printf("Invalid Choice!! Try Again\n");
            goto ok;
        }
        fclose(fp);
       }
       else
       {
           printf("Invalid password.!!\n");
           goto transfer;
       }



    dw:
          printf("Enter the "underline"password"closeunderline": ");
       fflush(stdin);
       gets(pw);
       fp =fopen("regis.txt","rb");
       while(fread(&mb,sizeof(mb),1,fp)==1)
       if(strcmp(mb.password,pw)==0)
       {
        system("cls");
        printf("WELCOME!! %s\n\n",mb.fname);
        n:
        printf("Choose:\n1. Deposit\n2. Withdraw\n\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
        printf("                 DEPOSIT!!            \n\n");
        printf("Enter your account number: ");
        scanf("%d",&idn);
        printf("Enter your first name: ");
        fflush(stdin);
        gets(name);
        fp1 = fopen("deposit.txt","wb");
        rewind(fp);
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
           if (mb.code != idn && (strcmp(name,mb.fname)!=0))
               fwrite(&mb,sizeof(mb),1,fp1);
            else
           {
               printf("The current balance of %s %s is %0.3f rupees.",mb.fname,mb.sname,mb.money);
               getch();
               printf("\nEnter the amount: ");
               scanf("%f",&am);
               mb.money = mb.money+am;
               if ((fwrite(&mb,sizeof(mb),1,fp1))==1)
               printf("Amount is deposited. The new amount is %0.3f rupees.",mb.money);
           }
        }
        fclose(fp);
         fclose(fp1);
        remove("regis.txt");
        rename("deposit.txt","regis.txt");
        getch();
        printf("\n\nEnter '1' to see the updated details, '2' to exit.\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
            goto search;
        }
        else if (choice==2)
        ex();
        else
        {
            printf("Invalid Choice!! Try Again");
            goto ok;
        }
        }
        else if(choice==2)
        {
        system("cls");
        printf("            WITHDRAW!!       \n\n");
        printf("Enter your account number: ");
        scanf("%d",&idn);
        printf("Enter your first name: ");
        fflush(stdin);
        gets(name);
        fp1 = fopen("withdraw.txt","wb");
        rewind(fp);
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
            if (idn == mb.code && (strcmp(name,mb.fname)==0))
            {
                if (mb.money>am)
                {
                     printf("The current balance of %s %s is %0.3f rupees.\n",mb.fname,mb.sname,mb.money);
                      printf("Enter the amount: ");
                    scanf("%f",&am);
                mb.money = mb.money-am;
                if (fwrite(&mb,sizeof(mb),1,fp1)==1);
                printf("Amount Withdrawn Successfully. The new amount is %0.3f rupees.\n",mb.money);
                }

                else
                printf("Not sufficient amount.\n");
            }
            else
            fwrite(&mb,sizeof(mb),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        remove("regis.txt");
        rename("withdraw.txt","regis.txt");
        getch();
        printf("\nEnter '1' to see the updated details, '2' to exit.\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
            goto search;
        }
        else if (choice==2)
        ex();
        else
        {
            printf("Invalid Choice!! Try Again\n");
            goto ok;
        }
        }
        else
        {
            printf("Invalid Choice.\n");
            goto n;
        }
       }
        else
       {
           printf("Invalid password.!!\n");
           goto dw;
       }

search:
        system("cls");
         printf("Enter the "underline"password"closeunderline": ");
       fflush(stdin);
       gets(pw);
       system("cls");
       fp =fopen("regis.txt","rb");
       while(fread(&mb,sizeof(mb),1,fp)==1)
       {
       if(strcmp(mb.password,pw)==0 || strcmp(str,pw)==0)
       {
        fp = fopen("regis.txt","rb");
        printf("Enter your account number: ");
        scanf("%d",&idn);
        while(fread(&mb,sizeof(mb),1,fp)==1)
         {
           if (idn == mb.code)
            {
            printf("The details of the given account number:\n\n");
            printf(underline"Name"closeunderline": %s %s\n"underline"Date of birth"closeunderline": %s\n"underline"Age"closeunderline": %d\n"underline"Address"closeunderline": %s\n"underline"Gender"closeunderline": %s\n"underline"Account number"closeunderline": %d\n"underline"Phone"closeunderline": %s\n",mb.fname,mb.sname,mb.dob,mb.age,mb.address,mb.gender,mb.code,mb.phone);
            printf(underline"Total Amount"closeunderline": %0.3f rupees\n",mb.money);
            getch();
            ex();
            }
         }   
        printf("Account number not found!!");
        getch();
        goto search;
        }
        else
       {
           printf("Invalid password.!!\n");
           getch();
           goto search;
       }
       }

 update:
  printf("Enter the "underline"password"closeunderline": ");
     fflush(stdin);
     gets(pw);
       if(strcmp(pw,str)==0)
       {
           system("cls");
           printf("WELCOME!!\n\n");
        printf("Enter your account number: ");
        scanf("%d",&idn);
        fp = fopen("regis.txt","rb");
        fp1 = fopen("update.txt","wb");
        while(fread(&mb,sizeof(mb),1,fp)==1)
         {
            if (idn != mb.code)
                fwrite(&mb,sizeof(mb),1,fp1);
            else
              {
                printf("Record found.\nOld record is: \n\n");
                printf(underline"Name"closeunderline": %s %s\n"underline"Date of birth"closeunderline": %s\n"underline"Age"closeunderline": %d\n"underline"Address"closeunderline": %s\n"underline"Gender"closeunderline": %s\t\t\t"underline"Account number"closeunderline": %d\n"underline"Phone"closeunderline": %s\n",mb.fname,mb.sname,mb.dob,mb.age,mb.address,mb.gender,mb.code,mb.phone);
                printf(underline"Total Amount"closeunderline": %0.3f rupees\n\n",mb.money);
                getch();

            printf("Enter the new details of %s:\n\n",mb.fname);
            printf("First Name: ");
            fflush(stdin);
            gets(mb.fname);
            printf("Surname: ");
            fflush(stdin);
            gets(mb.sname);
             printf("Date of birth(yyyy-mm-dd): ");
            fflush(stdin);
            gets(mb.dob);
            printf("Age: ");
            scanf("%d",&mb.age);
            printf("Address: ");
            fflush(stdin);
            gets(mb.address);
            printf("Gender: ");
            fflush(stdin);
            gets(mb.gender);
            printf("*Account number: %d\n",mb.code);
            printf("Phone no.: ");
            scanf("%s",mb.phone);
            printf("Password: ");
            fflush(stdin);
            gets(mb.password);
            printf("*Total money: %0.3f rupees\n",mb.money);
            fwrite(&mb,sizeof(mb),1,fp1);
            printf("Updated successfully.\n\n");
            break;
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("regis.txt");
    rename("update.txt","regis.txt");
    getch();
    printf("\nEnter '1' to see the updated details, '2' to exit.\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
            goto search;
        }
        else if (choice==2)
        ex();
        else
        {
            printf("Invalid Choice!! Try Again\n");
            goto ok;
        }
         }
        else
       {
           printf("Invalid password.!!\n");
           goto update;
       }


    delete:
     printf("Enter the "underline"password"closeunderline": ");
     fflush(stdin);
     gets(pw);
       if(strcmp(pw,str)==0)
       {
           system("cls");
           printf("WELCOME!!\n\n");
    printf("Enter your account number: ");
    scanf("%d",&idn);
    fp = fopen("regis.txt","rb");
    fp1 = fopen("delete.txt","wb");
    while(fread(&mb,sizeof(mb),1,fp)==1)
    {
       
        if (idn == mb.code)
        {
        printf(underline"Name"closeunderline": %s %s\n"underline"Date of birth"closeunderline": %s\n"underline"Age"closeunderline": %d\n"underline"Address"closeunderline": %s\n"underline"Gender"closeunderline": %s\t\t\t"underline"Account number"closeunderline": %d\n"underline"Phone"closeunderline": %s\n",mb.fname,mb.sname,mb.dob,mb.age,mb.address,mb.gender,mb.code,mb.phone);
        printf(underline"Total Amount"closeunderline": %0.3f rupees\n\n",mb.money);
        printf("\n\nIs this the record do you want to delete?(y/n)\n\n");
        hmm:
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c",&yn);
        if ((yn == 'y') || (yn == 'Y'))
        {
            rewind(fp);
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
        if(idn != mb.code)
        fwrite(&mb,sizeof(mb),1,fp1);
        }
        printf("Record deleted successfully.\n");
        }
        else if ((yn == 'n') || (yn == 'N'))
        {
        rewind(fp);
        while(fread(&mb,sizeof(mb),1,fp)==1)
        {
        fwrite(&mb,sizeof(mb),1,fp1);
        }
        printf("Record found but not deleted.\n");
        }
        else
        {
        printf("Invalid choice!!\n");
        goto hmm;
        }
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("regis.txt");
    rename("delete.txt","regis.txt");
    getch();
    printf("\nEnter '1' to see the updated details, '2' to exit.\nYour Choice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            system("cls");
            goto search;
        }
        else if (choice==2)
        ex();
        else
        {
            printf("\nInvalid Choice!! Try Again\n");
            goto ok;
        }
         }
        else
       {
           printf("Invalid password.!!\n");
           goto delete;
       }


    details:
    printf("Enter the "underline"password"closeunderline": ");
     fflush(stdin);
     gets(pw);
       if(strcmp(pw,str)==0)
       {
           system("cls");
           printf("WELCOME!!\n\n");
    fp = fopen("regis.txt","rb");
    if(fread(&mb,sizeof(mb),1,fp)==1)
    printf(underline"Name\t\tAge\tAddress\t\tGender\t\tPhone\t\tId\n\n"closeunderline);
    else
    printf("No Data Found.\n");
    while(fread(&mb,sizeof(mb),1,fp)==1)
    printf("%s %s\t\t%d\t%s\t\t%s\t\t%s\t\t%d\n",mb.fname,mb.sname,mb.age,mb.address,mb.gender,mb.phone,mb.code);
    
    getch();
    ex();
       }
        else
       {
           printf("Invalid identity code.!!\n");
           goto details;
       }
}
void card()
{
    system("cls");
    FILE *fp;
    struct member mb;
    int choice;
    fp = fopen("regis.txt","a+");
    int num[100],n,low,up,i,k=0;
    low=1000, up=2000;
    srand(time(NULL));
     for (i=1;i<10;i++)
     {
         n = (rand() % (up-low+1))+low;
         num[k]=n;
         k++;
     }
     for(i=0;i<1;i++)
     {
     printf("Your account number is %d.\n ",num[i]);
     }
     getch();
    regis(num);
     main(num);
 }
void ex()
{
    system("cls");
    printf("\n\n\n\n\nThank you for choosing us.\n\n\n\n\n");
    exit(0);
}


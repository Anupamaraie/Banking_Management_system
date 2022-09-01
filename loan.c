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

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

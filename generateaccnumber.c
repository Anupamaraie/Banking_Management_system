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

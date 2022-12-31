    #define FILE_NAME "EMP.dat"
    FILE *fp, *ft;
    char another, choice;

    struct emp
    {
        char name[40];
        int age;                     // age
        float bs;                    // basic salary
        float ma, rent, da, pf, ins; // ins-->insurance pf-->provident fund da-->dearness allowance ma-->medcal ...
        long long int number;        // mobile number
        float gross, net;
    };

    struct emp employee;

    char empname[40];

    long int recsize;






void add_record(void)
{
    system("cls");
    printf("\n\t\t\t====================ENTER EMPLOYEE DETAILS======================\n\n\n");
    fseek(fp, 0, SEEK_END);
    another = 'y';
    while (another == 'y')
    {
        printf("\n\t\t\t\tEnter Employee name: ");
        gets(employee.name);

        printf("\n\t\t\t\tEnter Employee age: ");
        scanf("%d", &employee.age);

        printf("\n\t\t\t\tEnter Employee basic salary: ");
        scanf("%f", &employee.bs);

        printf("\n\t\t\t\tEnter Employee mobile number: (+880)");
        scanf("%lld", &employee.number);

        printf("\n\t\t\t\tEnter Medical Allowance: ");
        scanf("%f", &employee.ma);

        printf("\n\t\t\t\tEnter Dearness Allowance: ");
        scanf("%f", &employee.da);

        printf("\n\t\t\t\tEnter the deductions ");
        printf("\n\t\t\t\t____________________");

        printf("\n\n\t\t\t\tEnter Provident Fund: ");
        scanf("%f", &employee.pf);

        printf("\n\t\t\t\tEnter Insurance Amount: ");
        scanf("%f", &employee.ins);

        employee.gross = employee.bs + employee.ma + employee.da;
        employee.net = employee.gross - (employee.pf + employee.ins);

        printf("\n\t\t\t\tGross Salary: %.2f", employee.gross);
        printf("\n\n\t\t\t\tNet Salary: %.2f", employee.net);

        fwrite(&employee, recsize, 1, fp);

        printf("\n\n\nWant to Add Another Record? (press y)");
        printf("\n\nReturn to main menu screen. (press n)\n");

        fflush(stdin);
        another = getche();
    }
}

void list_record(void)
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t\t\t\t\tLIST OF ALL EMPLOYEE\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t____________________\n\n\n");
    fseek(fp, 0, SEEK_SET);
    printf("NAME \t\tAGE \t\tBASIC SALARY \t\tMOBILE NUMBER \t\tMEDICAL ALLOWANCE    \tDEARNESS ALLOWANCE\t\tPROVIDENT FUND \t\tINSURANCE AMOUNT   NET SALRAY\n\n");
    while (fread(&employee, recsize, 1, fp))
        printf("%s \t\t%d \t\t%f \t\t(+88)%lld \t\t%.2f  \t\t%.2f \t\t\t%.2f \t\t%.2f        \t%.2f\n\n", employee.name, employee.age, employee.bs, employee.number, employee.ma, employee.da, employee.pf, employee.ins, employee.net);

    printf("\n\n\n\nEnter Any Key To Go Back.");
    getch();
}

void delete_record(){
                system("cls");
            rewind(fp);
            printf("NAME \t\tAGE \t\tBASIC SALARY \t\tMOBILE NUMBER");
            while (fread(&employee, recsize, 1, fp) == 1)

            {
                printf("\n\n%s \t\t%d \t\t%.2f \t\t(+880)%d", employee.name, employee.age, employee.bs, employee.number);
            }
            another = 'y';
            while (another == 'y')
            {
                printf("\n\n\nEnter Name of Employee To Delete: ");
                scanf("%s", empname);
                ft = fopen("Temp.dat", "wb");
                rewind(fp);
                while (fread(&employee, recsize, 1, fp) == 1)
                {
                    if (strcmp(employee.name, empname) != 0)
                    {
                        fwrite(&employee, recsize, 1, ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove(FILE_NAME);
                rename("Temp.dat", FILE_NAME);
                fp = fopen(FILE_NAME, "rb+");

                printf("\nWant to Delete Another Record? (press y)");
                printf("\n\nReturn to main menu screen. (press n)\n");
                fflush(stdin);
                another = getche();
            }
}

void menu(void){

      fp = fopen(FILE_NAME, "rb+");
    if (fp == NULL)
    {
        fp = fopen(FILE_NAME, "wb+");
        if (fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }

    recsize = sizeof(employee);




    while (1)
    {
        system("cls");
        printf("\n========================EMPLOYEE SALARY MANAGEMENT SYSTEM=====================\n\n\n\n\n");

        printf("\t\t\t\t1. Add Record");

        printf("\n\n\t\t\t\t2. List Records");

        printf("\n\n\t\t\t\t3. Delete Records");

        printf("\n\n\t\t\t\t4. Exit\n\n\n");

        printf("-------------------------------------------------------------------------------\n\n");

        printf("\n\n\t\t\t\tYour Choice: ");
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':
            add_record();
            break;

        case '2':
            list_record();
            break;

        case '3':
            delete_record();
            break;

        case '4':
            fclose(fp);
            exit(0);
        }
    }
    
}
void login(void)
{
    char USERNAME[40];
    char PASS[33];

    char username[100]; /*this is for user input*/
    char pass[33];

    // taking username and pass from textfile
    FILE *ptr_u;
    FILE *ptr_p;
    ptr_u = fopen("username.txt", "r");
    ptr_p = fopen("pass.txt", "r");

    char *status1 = fgets(USERNAME, U_SIZE, ptr_u);
    while (status1 != NULL)
    {

        status1 = fgets(USERNAME, U_SIZE, ptr_u);
    }
    // fgets(USERNAME, 7, ptr_u);
    // fgets(PASS, 5, ptr_p);
    char *status = fgets(PASS, P_SIZE, ptr_p);
    while (status != NULL)
    {

        status = fgets(PASS, P_SIZE, ptr_p);
    }
    // puts(USERNAME);
    // puts(PASS);
    fclose(ptr_p);
    fclose(ptr_u);

    printf("\v\v");
    printf("\t\t\t\t\t\t\t\t\t\tUsername : ");
    gets(username);
    printf("\t\t\t\t\t\t\t\t\t\tPassword : ");
    gets(pass);
    system("cls");

    if ((strcmp(USERNAME, username) != 0) || (strcmp(PASS, pass) != 0))
    {
        printf("\t\t\t\t\t\t\t\t\t%sInvalid username or password%s\v\v", KRED, KNRM);
        login();
    }
}




void login(void)
{
    char USERNAME[50];
    char PASS[33];

    char username[100]; /*this is for user input*/
    char pass[33];

    // taking username and pass from textfile
    FILE *ptr_u;
    FILE *ptr_p;
    ptr_u = fopen("username.txt", "r");
    ptr_p = fopen("pass.txt", "r");

    fgets(USERNAME, 7, ptr_u);
    fgets(PASS, 5, ptr_p);
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
    while (log == 0)
    {
        if ((strcmp(USERNAME, username) == 0) && (strcmp(PASS, pass) == 0))
        {
            log = 1;
            break;
        }
        printf("\t\t\t\t\t\t\t\t\t%sInvalid username or password%s\v\v", KRED, KNRM);
        printf("\t\t\t\t\t\t\t\t\t\tUsername : ");
        gets(username);
        printf("\t\t\t\t\t\t\t\t\t\tPassword : ");
        gets(pass);
        system("cls");
    }
}
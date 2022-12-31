#include<stdio.h>
#include<windows.h>
#include<direct.h>
#include<string.h>
#include<conio.h>

#define P_SIZE 50
#define U_SIZE 50
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"


#include"splash.h"
#include"login.h"
#include"menu.h"


int main(void)
{



splash();
login();
menu();


    return 0;
}

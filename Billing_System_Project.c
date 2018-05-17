#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rlutil.h"//downloaded header file for colors,etc
#include <time.h>
#include <windows.h>
#define space "\t\t\t"
//for aligning cursor position
COORD coord= {0,0};
void gotoxy1(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void add_products();
void delete_product();
void modify_product();
void view_products();
void admin_menu();
void billing();
void cashier_menu();
char admin_username[100],admin_password[100],cashier_user[100],cashier_password[100],*tempstr,account[100];
int count = 0;

struct bill
{
    char name[100];
    int quantity;
    char code[100];
    double rate;
} bill[100];

void main_menu()//home page
{
    setBackgroundColor(WHITE);
    system("cls");
    char user[100];
    setColor(BLUE);
    int i,j,a=219;
    char anm[10][50] =
    {
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
    system("cls");
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 10; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 24; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(GREEN);
    printf(space space"\t\tSuperMarkets\n");
    Sleep(100);
    setColor(BLACK);
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    char ch;
    printf(space"1.Admin Login\n\n");
    printf(space"2.Cashier Login\n\n");
    printf(space"3.Exit\n\n");
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    printf(space"Enter your choice:");
    fflush(stdin);
    ch=_getch();
    if(ch=='1')
    {
        system("cls");
        admin_account_login(user);
    }
    else if(ch=='2')
    {
        system("cls");
        cashier_account_login(user);
    }
    else
        exit(0);
}

int admin_account_login(char *user)//admin login
{
    system("cls");
    int i, j, a = 219;
    char x, n;
    FILE *fp;
    tempstr=(char*)malloc(sizeof(char));
    char anm[10][50] =
    {
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
label2 :
    system("cls");
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 10; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 24; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(GREEN);
    printf(space space"\t\tSuperMarkets\n");
    Sleep(100);
    setColor(BLACK);
    i = 0;
    char BS = 8;
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    printf(space"1) Login\n\n");
    printf(space"2) Sign up\n\n");
    printf(space"3) Main Menu\n\n");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Enter your choice:");
    fflush(stdin);
    n = _getch();
    if(n == '1')//login page
    {
        system("cls");
        printf("\n\n\n\n"space space"Admin Portal");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", admin_username);
        i = 0;
        while(admin_username[i] != '\0')
        {
            user[i] = admin_username[i];
            i++;
        }
        user[i] = '&';
        user[i + 1] = '\0';
        i = 0;
        printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tPassword : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,15);
        i = 0;
        while((x = _getch()) != '\r')
        {
            if(x != BS)
            {
                printf("*");
                admin_password[i++] = x;
            }
        }
        admin_password[i] = '\0';
        i = 0;
        strcat(admin_username,admin_password);
        fp = fopen("billing_system_admin_DB.txt","r");
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        account[i] = '\0';
        fclose(fp);
        if(NULL == strstr(account, admin_username))
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
        else
        {
            tempstr = strstr(account, admin_username);
        }
        i = 0;
        while(tempstr[i] != '|')
        {
            i++;
        }
        if(i == strlen(admin_username))
        {
            admin_menu();
        }
        else
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
    }
    else if(n == '2')//sign up page
    {
label1 :
        system("cls");
        printf("\n\n\n\n"space space"Create Admin Account");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", admin_username);
        i = 0;
        while((x = admin_username[i]) != '\0')
        {
            if(x == '*' || x == '@' || x == '|')
            {
                printf("\n"space space "*Username must not contain special characters like |, *, @, # etc.");
                _getch();
                goto label1;
            }
            i++;
        }
        fp = fopen("billing_system_admin_DB.txt","r");
        i = 0;
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        fclose(fp);
        if(NULL == strstr(account, admin_username))
        {
            printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space "\t\tPassword : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(53,15);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x == '&' || x == '|' || x == ')')
                {
                    printf("\n"space space"*Password must not contain special characters like |, &, $, ), ( etc.");
                    _getch();
                    goto label1;
                }
                if(x != BS)
                {
                    printf("*");
                    admin_password[i++] = x;
                }
            }
            admin_password[i] = '\0';
            printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space "    Enter password again : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy(53,18);
            i = 0;
            while((x = _getch()) != '\r')
            {
                printf("*");
                tempstr[i++] = x;
            }
            tempstr[i] = '\0';
            if(strcmp(admin_password, tempstr) == 0)
            {
                i = 0;
                fp = fopen("billing_system_admin_DB.txt","a");
                fputc('|',fp);
                while((x = admin_username[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                i = 0;
                while((x = admin_password[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                fputc('|',fp);
                fclose(fp);
                printf("\n\n"space space"Sign up successful");
                _getch();
                goto label2;
            }
            else
            {
                printf("\n\n"space space"*Passwords do not match, try again");
                _getch();
                goto label1;
            }
        }
        else
        {
            printf("\n"space space"     *Username is already taken");
            _getch();
            goto label1;
        }
    }
    else if(n == '3')//return back to home page
        main_menu();
    else
    {
        setColor(RED);
        printf(space"Invalid entry\n");
        setColor(BLACK);
        _getch();
        goto label2;
    }
}
void admin_menu()//admin page/portal
{
    system("cls");
    char a = 219;
    int i,j;
    char anm[10][50] =
    {
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
label2 :
    system("cls");
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 10; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 24; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(GREEN);
    printf(space space "\t\tSuperMarkets\n");
    Sleep(100);
    setColor(BLACK);
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    FILE *fp;
    //gotoxy(30,12);
    printf(space"1--->View Products\n\n");
    //gotoxy(30,13);
    printf(space"2--->Add Products\n\n");
    //gotoxy(30,14);
    printf(space"3--->Modify Product\n\n");
    //gotoxy(30,15);
    printf(space"4--->Delete Product\n\n");
    //gotoxy(30,16);
    printf(space"5--->Logout\n");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Enter your choice:");
    char ch;
    fflush(stdin);
    ch = _getch();
    if(ch == '1')
    {
        view_products();
    }
    else if(ch == '2')
    {
        add_products();
    }
    else if(ch == '3')
    {
        modify_product();
    }
    else if(ch == '4')
    {
        delete_product();
    }
    else if(ch == '5')
    {
        main_menu();
    }
    goto label2;
}
void view_products()//display available products
{
    system("cls");
    FILE *fp, *fp1;
    char x;
    int size;
    fp = fopen("billing_system_products_DB.txt","r");
    if(fp != NULL)
    {
        fseek (fp, 0, 2);
        size = ftell(fp);
        fclose(fp);
        int i;
        if (size == 0)
        {
            setColor(RED);
            for(i = 0; i < 10; i++)
            {
                printf("\n");
            }
            printf(space space"No products Available!!\n");
            setColor(BLACK);
            _getch();
        }
        else
        {
            fp = fopen("billing_system_products_DB.txt","r");
            printf("\n\n");
            printf(space"\t   product code\t   product price\tproduct name\n");
            printf(space);
            for(i = 0; i < 72; i++)
            {
                printf("%c", 205);
            }
            printf("\n\n");
            while((x = fgetc(fp))!=EOF)
            {
                if(x == '*'||x == '$')
                {
                    printf("\t\t");
                }
                else if(x == '|')
                {
                    printf("\n\t\t"space);
                }
                else
                {
                    setColor(GREEN);
                    printf("%c",x);
                }
            }
            setColor(BLACK);
            fclose(fp);
            int i;
            printf("\n"space);
            for(i = 0; i < 72; i++)
            {
                printf("%c", 205);
            }
            _getch();
        }
    }
    else
    {
        fclose(fp);
        setColor(RED);
        printf("\n\n"space"No products Available!!\n");
        setColor(BLACK);
        _getch();
    }
}
void add_products()//adding products to database
{
    while(1)
    {
        system("cls");
        FILE *fp;
        char product_no[100],product_name[100],product_price[100],x;
        printf("\n\n\n\n\n\n\n\n\n"space space"Add Products");
        int i;
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"\t    product name : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,12);
        fflush(stdin);
        gets(product_name);
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"        Enter product no : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        printf("\n"space space"   **Enter 3 digit product no");
        gotoxy1(53,16);
        scanf("%s",product_no);
        printf("\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"     Enter product price : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,21);
        scanf("%s",product_price);
        i = 0;
        fp = fopen("billing_system_products_DB.txt","a");
        fputc('|',fp);
        while((x = product_no[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        i = 0;
        fputc('*',fp);
        while((x = product_price[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        fputc('$',fp);
        i = 0;
        while((x = product_name[i]) != '\0')
        {
            fputc(x,fp);
            i++;
        }
        fputc('|',fp);
        fclose(fp);
        char ch;
        printf("\n\n"space"Added successfully!!\n");
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n"space"Do you want to add more(y/n): ");
        fflush(stdin);
        ch = _getch();
        if(ch=='n')
        {
            break;
        }
    }
}
void modify_product()//change data of particular product
{
    system("cls");
    FILE *fp,*fp1;
    char temp, a;
    int h = 0;
    char product_no[100],cpydata[100],product_name[100],product_price[100];
    fp = fopen("billing_system_products_DB.txt","r");
    printf("\n\n\n\n\n\n\n\n"space space"Modify Products\n");
    int i;
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t    product num  : %c                       %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    int j = 0;
    i = 0;
    char x;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i++] = x;
    }
    fclose(fp);
    cpydata[i] = '\0';
    if(strstr(cpydata,product_no) == NULL)
    {
        setColor(RED);
        printf("\n"space space"Product not found!!");
        setColor(BLACK);
        _getch();
        admin_menu();
    }
    else
    {
        fflush(stdin);
        printf("\n"space space"Enter data to modify\n");
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"      Enter product name : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,18);
        scanf("%[^\n]s",product_name);
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"     Enter product price : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,22);
        scanf("%s",product_price);
        int flag = 0, i = 0, j = 0, k = 0, l = 0, idx;
        char x;
        char tempstring[100];
        while(cpydata[i] != '\0')
        {
            if(cpydata[i] == product_no[0] && cpydata[i+1] == product_no[1] && cpydata[i+2] == product_no[2] && flag == 0)
            {
                i = i + 1;
                while(cpydata[i] != '|')
                {
                    i++;
                }
                for(idx = 0; idx < 3; idx++)
                {
                    tempstring[j] = product_no[idx];
                    j++;
                }
                tempstring[j] = '*';
                j++;
                for(idx = 0; product_price[idx] != '\0'; idx++)
                {
                    tempstring[j] = product_price[idx];
                    j++;
                }
                tempstring[j] = '$';
                j++;
                for(idx = 0; product_name[idx] != '\0'; idx++)
                {
                    tempstring[j] = product_name[idx];
                    j++;
                }
                tempstring[j] = '|';
                j++;
                flag = 1;
            }
            else
            {
                tempstring[j] = cpydata[i];
                j++;
            }
            i++;
        }
        tempstring[j] = '\0';
        fp1 = fopen("replica.txt","w");
        i = 0;
        while((x = tempstring[i]) != '\0')
        {
            fputc(x,fp1);
            i++;
        }
        fclose(fp1);
        remove("billing_system_products_DB.txt");
        rename("replica.txt","billing_system_products_DB.txt");
        printf("\n"space"Modified!!");
    }
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    _getch();
}
void delete_product()//remove product
{
    system("cls");
    FILE *fp,*fp1;
    char tempstring[100];
    char product_no[100],cpydata[100];
    fp = fopen("billing_system_products_DB.txt","r");
    printf("\n\n\n\n\n\n\n\n"space space"Delete Product\n");
    int i;
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t    product num  : %c                       %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    int j = 0;
    i = 0;
    char x;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i++] = x;
    }
    fclose(fp);
    cpydata[i] = '\0';
    if(strstr(cpydata,product_no) == NULL)
    {
        setColor(RED);
        printf("\n"space"Product not found!!");
        setColor(BLACK);
        printf("\n\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        admin_menu();
    }
    else
    {
        i = 0;
        while(cpydata[i] != '\0')
        {
            if(cpydata[i] == product_no[0] && cpydata[i+1] == product_no[1] && cpydata[i+2] == product_no[2])
            {
                while(cpydata[i] != '|')
                {
                    i++;
                }
                i++;
                tempstring[j-1] = cpydata[i];
                i = i+1;
            }
            tempstring[j] = cpydata[i];
            j++;
            i++;
        }
        tempstring[j] = '\0';
    }
    i = 0;
    fp1 = fopen("replica.txt","w");
    while(tempstring[i] != '\0')
    {
        fputc(tempstring[i],fp1);
        i++;
    }
    fclose(fp1);
    remove("billing_system_products_DB.txt");
    rename("replica.txt","billing_system_products_DB.txt");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Deleted Entry!!");
    _getch();
}
int cashier_account_login(char *user)//cashier login
{
    int i, j, a = 219;
    char x, n;
    FILE *fp;
    system("cls");
    tempstr=(char*)malloc(sizeof(char));
    char anm[10][50] = {{a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
label2:
    system("cls");
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 10; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 24; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(GREEN);
    printf(space space"\t\tSuperMarkets\n");
    Sleep(100);
    setColor(BLACK);
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    i = 0;
    char BS = 8;
    printf(space"1) Login\n\n");
    printf(space"2) Sign up\n\n");
    printf(space"3) Main Menu\n\n");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n"space"Enter your choice:");
    fflush(stdin);
    n = _getch();
    if(n == '1')//login page
    {
        system("cls");
        printf("\n\n\n\n"space space"Cashier Portal");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", cashier_user);
        i = 0;
        while(cashier_user[i] != '\0')
        {
            user[i] = cashier_user[i];
            i++;
        }
        user[i] = '\0';
        i = 0;
        printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space"\t\tPassword : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy1(53,15);
        i = 0;
        while((x = _getch()) != '\r')
        {
            if(x != BS)
            {
                printf("*");
                cashier_password[i++] = x;
            }
        }
        cashier_password[i] = '\0';
        i = 0;
        strcat(cashier_user, cashier_password);
        fp = fopen("billing_system_cashier_DB.txt","r");
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        account[i] = '\0';
        fclose(fp);
        if(NULL == strstr(account, cashier_user))
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
        else
        {
            tempstr = strstr(account, cashier_user);
        }
        i = 0;
        while(tempstr[i] != '|')
        {
            i++;
        }
        if(i == strlen(cashier_user))
        {
            cashier_menu();
        }
        else
        {
            printf("\n\n"space space"*Username or password is wrong");
            _getch();
            goto label2;
        }
    }
    else if(n == '2')//sign up page
    {
label1 :
        system("cls");
        printf("\n\n\n\n"space space"Create Cashier Account");
        printf("\n\n\n\n\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        printf("\n"space "\t\tUsername : %c                       %c\n",179,179);
        printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        gotoxy(53,12);
        scanf("%s", cashier_user);
        i = 0;
        while((x = cashier_user[i]) != '\0')
        {
            if(x == '#' || x == '@' || x == '|')
            {
                printf("\n"space space "*Username must not contain special characters like |, *, @, # etc.");
                _getch();
                goto label1;
            }
            i++;
        }
        fp = fopen("billing_system_cashier_DB.txt","r");
        i = 0;
        while((x = fgetc(fp)) != EOF)
        {
            account[i++] = x;
        }
        fclose(fp);
        if(NULL == strstr(account, cashier_user))
        {
            printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space"\t\tPassword : %c                       %c\n",179,179);
            printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy1(53,14);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x == '&' || x == '|' || x == ')')
                {
                    printf("\n"space space"*Password must not contain special characters like |, &, $, ), ( etc.");
                    _getch();
                    goto label1;
                }
                if(x != BS)
                {
                    printf("*");
                    cashier_password[i++] = x;
                }
            }
            cashier_password[i] = '\0';
            printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
            printf("\n"space"    Enter password again : %c                       %c\n",179,179);
            printf(space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
            gotoxy1(53,17);
            i = 0;
            while((x = _getch()) != '\r')
            {
                if(x != BS)
                {
                    printf("*");
                    tempstr[i++] = x;
                }
            }
            tempstr[i] = '\0';
            if(strcmp(cashier_password, tempstr) == 0)
            {
                i = 0;
                fp = fopen("billing_system_cashier_DB.txt","a");
                fputc('|',fp);
                while((x = cashier_user[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                i = 0;
                while((x = cashier_password[i]) != '\0')
                {
                    fputc(x,fp);
                    i++;
                }
                fputc('|',fp);
                fclose(fp);
                printf("\n\n"space space"Sign up successful");
                _getch();
                goto label2;
            }
            else
            {
                printf("\n\n"space space"*Passwords do not match, try again");
                _getch();
                goto label1;
            }
        }
        else
        {
            printf("\n"space space"     *Username is already taken");
            _getch();
            goto label1;
        }
    }
    else if(n=='3')//return back to home page
    {
        main_menu();
    }
    else
    {
        setColor(RED);
        printf(space"Invalid entry\n");
        setColor(BLACK);
        _getch();
        goto label2;
    }
    return 0;
}
void cashier_menu()//cashier page/portal
{
    system("cls");
    char a = 219;
    int i,j;
    char anm[10][50] = {{a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
label2 :
    system("cls");
    setColor(BLUE);
    for(i = 0; i < 5; i++)
    {
        printf("\n");
    }
    for(i = 0; i < 10; i++)
    {
        printf(space "\t\t\t");
        for(j = 0; j < 24; j++)
        {
            printf("%c",anm[i][j]);
        }
        Sleep(30);
        printf("\n");
    }
    setColor(GREEN);
    printf(space space"\t\tSuperMarkets\n");
    Sleep(100);
    setColor(BLACK);
    printf(space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    printf(space"1--->View Products\n\n");
    printf(space"2--->Billing\n\n");
    printf(space"3--->logout\n\n");
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n");
    char ch;
    ch = _getch();
    if(ch == '1')
    {
        view_products();
    }
    else if(ch == '2')
    {
        billing();
    }
    else if(ch == '3')
    {
        main_menu();
    }
    else
    {
        setColor(RED);
        printf("invalid input\n");
        setColor(BLACK);
    }
    goto label2;
}

void billing()//generating bill
{
    system("cls");
    char product_no[100], *tempstring, cpydata[100], mrp[100];
    int i, k, j, x, flag = 0, temp1 = count, l = 0;
    double total = 0;
    tempstring = (char *)malloc(sizeof(char)*1);
    FILE *fp;
label:
    fp = fopen("billing_system_products_DB.txt","r");
    i = 0;
    while((x = fgetc(fp)) != EOF)
    {
        cpydata[i] = x;
        i++;
    }
    cpydata[i] = '\0';
    fclose(fp);
    system("cls");
    printf("\n\n\n\n\n\n\n"space space"\t\tBilling");
    printf("\n\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\tEnter product no : %c            %c\n",179,179);
    printf(space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,12);
    scanf("%s",product_no);
    printf("\n"space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf("\n"space"\t  Enter quantity : %c            %c\n",179,179);
    printf(""space space"   %c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy1(53,15);
    scanf("%d", &bill[count].quantity);
    if(strstr(cpydata,product_no) == NULL)
    {
        char ch;
        setColor(RED);
        printf("\n"space"Invalid Product Code!!");
        setColor(BLACK);
        printf("\n"space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        _getch();
        cashier_menu();
    }
    else
    {
        tempstring = strstr(cpydata,product_no);
        i = 0;
        j = 0;
        k = 0;
        l = 0;
        flag = 0;
        while(tempstring[i] != '\0' )
        {
            if(tempstring[i] == '|')
            {
                break;
            }
            else if(tempstring[i] == '$')
            {
                flag = 2;
            }
            else if(flag == 2)
            {
                bill[count].name[k] = tempstring[i];
                k++;
            }
            else if(tempstring[i] != '*' && flag == 0)
            {
                bill[count].code[j] = tempstring[i];
                j++;
            }
            else if(tempstring[i] == '*')
            {
                bill[count].code[j] == '\0';
                flag = 1;
            }
            else
            {
                mrp[l] = tempstring[i];
                l++;
            }
            i++;
        }
        bill[count].name[k] = '\0';
        mrp[l] = '\0';
    }
    bill[count].rate = strtod(mrp,NULL);
    printf("\n"space);
    for(i = 0; i < 72; i++)
    {
        printf("%c", 205);
    }
    printf("\n\n"space"do you want to add more products(y/n)?");
    char ch;
    ch = _getch();
    if(ch == 'y')
    {
        count++;
        goto label;
    }
    else//print bill
    {
        system("cls");
        printf("%d\n", count);
        printf(space"product code\t   product price\tquantity\t  product name\n");
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n");
        for(i = temp1; i <= count; i++)
        {
            printf(space"   %s\t\t   %lf  \t\t%d\t\t  %s\n\n", bill[i].code, bill[i].rate, bill[i].quantity, bill[i].name);
            total = total + ((bill[i].rate) * (bill[i].quantity));
        }
        printf(space);
        for(i = 0; i < 72; i++)
        {
            printf("%c", 205);
        }
        printf("\n\n"space"Sub Total %lf", total);
        int rnd;
        rnd = round(total);
        printf("\n"space"Rounding off: %d", rnd);
        printf("\n"space"TOTAL AMOUNT TO BE PAID: %d",rnd);
        count++;
    }
    _getch();
    cashier_menu();
}

void choice(int ch)//color choice for startup animation
{
    if(ch == 1)
        setColor(BLUE);
    if(ch == 2)
        setColor(GREEN);
    if(ch == 3)
        setColor(CYAN);
    if(ch == 4)
        setColor(MAGENTA);
    if(ch == 5)
        setColor(RED);
    if(ch == 6)
        setColor(YELLOW);
    if(ch == 7)
        setColor(BROWN);
    if(ch == 8)
        setColor(DARKGREY);
    if(ch == 9)
        setColor(LIGHTBLUE);
    if(ch == 10)
        setColor(LIGHTGREEN);
    if(ch == 11)
        setColor(LIGHTCYAN);
    if(ch == 12)
        setColor(LIGHTRED);
    if(ch == 13)
        setColor(LIGHTMAGENTA);
    if(ch == 14)
        setColor(BLUE);
}

void animation()//startup animation
{
    int k = 1, j, i;
    char a = 219;
    char anm[10][50] = {{a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,0,0,0,0,a,a,0,0,0,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,a,a,a,a,a,0,0,a,a,a,a,a,a,0,0,a,a,a,a,a,a,a},
        {a,a,0,0,0,a,a,0,0,0,0,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,0,0,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a},
        {a,a,0,0,0,a,a,0,0,a,a,a,a,a,a,0,0,a,a,0,0,0,a,a}
    };
    while(k != 5)
    {
        choice(k);
        k++;
        system("cls");
        for(i = 0; i < 10; i++)
        {
            printf("\n");
        }
        for(i = 0; i < 10; i++)
        {
            printf(space "\t\t\t");
            for(j = 0; j < 24; j++)
            {
                printf("%c",anm[i][j]);
            }
            Sleep(30);
            printf("\n");
        }
        setColor(GREEN);
        printf(space space"\t\tSuperMarkets\n");
        Sleep(100);
        setColor(BLACK);
    }
}

int main()
{
    system("color f0");
    animation();
    main_menu();
    return 0;
}

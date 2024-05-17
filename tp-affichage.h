#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define maxepreuve 20
#define maxuniv 45
#define MAX_ATH 15
#define MAX_NUMATH 13500

//----------------------------------------------------------/ FONCTIONAMITIES /--------------------------------------------------------//

void consumeBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // consume characters from the input buffer
    }
}

void readstr(char* str, int size)
{
    fgets(str, size, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0'; 
    }
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void Header(){
    printf("                                        \033[0mPeople's Democratic Republic of Algeria\033[0m                                        \n");
    printf("                                  \033[0mMinistry of Higher Education and Scientific Research\033[0m                                 \n");
    printf("                                               \033[1mRegional University Games\033[0m                                             \n\n\n ");
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void pleasewait( int delay ){
    printf("\n");
    for ( int i = 0; i < delay; i++)
    {
        printf("\33[2K\r      Please Wait ");Sleep(200);
        printf("\33[2K\r      Please Wait .");Sleep(200);
        printf("\33[2K\r      Please Wait ..");Sleep(200);
        printf("\33[2K\r      Please Wait ...");Sleep(200);
    }
}

void loading( int delay ){
    printf("\n");
    for ( int i = 0; i < delay; i++)
    {
        printf("\33[2K\r                                                      LOADING |");Sleep(200);
        printf("\33[2K\r                                                      LOADING /");Sleep(200);
        printf("\33[2K\r                                                      LOADING -");Sleep(200);
        printf("\33[2K\r                                                      LOADING \\");Sleep(200);
    }
}

void clickenter( int delay ){
    printf("\n");
    for ( int i = 0; i < delay; i++)
    {
        printf("\33[2K\r                                                    > CLICK ENTER <");Sleep(100);
        printf("\33[2K\r                                                   >> CLICK ENTER <<");Sleep(100);
        printf("\33[2K\r                                                  >>> CLICK ENTER <<<");Sleep(100);
        printf("\33[2K\r                                                   >> CLICK ENTER <<");Sleep(100);
    }
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void printESI(){
    printf("\n\t        \033[0;107m                  \033[0m          \033[0;107m                  \033[0m     \033[0;104m         \033[0m \n");Sleep(150);
    printf("\t      \033[0;107m                      \033[0m      \033[0;107m                      \033[0m   \033[0;104m         \033[0m  \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m            \033[0;107m      \033[0m \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;104m         \033[0m \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m            \033[0;107m      \033[0m             \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m       \033[0m  \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m                      \033[0;107m       \033[0m       L'ECOLE  NATIONALE\n");Sleep(150);
    printf("\t     \033[0;107m                        \033[0m    \033[0;107m                        \033[0m    \033[0;107m       \033[0m  \n");Sleep(150);
    printf("\t     \033[0;107m                        \033[0m    \033[0;107m                        \033[0m    \033[0;107m       \033[0m       SUPERIEURE\n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m                                        \033[0;107m      \033[0m    \033[0;107m       \033[0m  \n");Sleep(150);
    printf("\t     \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m      \033[0m            \033[0;107m      \033[0m    \033[0;107m       \033[0m       D'INFORMATIQUE\n");Sleep(150);
    printf("\t      \033[0;107m      \033[0m          \033[0;107m      \033[0m      \033[0;107m      \033[0m          \033[0;107m      \033[0m     \033[0;107m       \033[0m  \n");Sleep(150);
    printf("\t      \033[0;107m                      \033[0m      \033[0;107m                      \033[0m     \033[0;107m       \033[0m  \n");Sleep(150);
    printf("\t        \033[0;107m                  \033[0m          \033[0;107m                  \033[0m       \033[0;107m       \033[0m  \n\n\n");Sleep(150);
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void Intro() {
    system("cls");
    printf("\n\n\n                                        \033[0mPeople's Democratic Republic of Algeria\033[0m                                        \n");Sleep(200);
    printf("                                  \033[0mMinistry of Higher Education and Scientific Research\033[0m                             \n\n");Sleep(300);
    printf("\n");
    printESI();
    loading(4);
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void MainPage() {
    system("cls");
    printf("                                        \033[0mPeople's Democratic Republic of Algeria\033[0m                                        \n");
    printf("                                  \033[0mMinistry of Higher Education and Scientific Research\033[0m                             \n\n\n\n\n");
    printf("                   \033[1m PW n-1 : LLL - Case study: \"Regional university games\" (\"Matrix of linked lists\")  \033[0m     \n");
    printf("                               \033[1m         ALSDD - 1th year CPI, S2, (2023/2024)                    \033[0m           \n\n");
    printf("\n\n\n                                \033[0;44m\033[1m                          \033[0m\n");
    printf("                                \033[0;44m\033[1m              Realised By \033[0m  \033[1mAhmed Rami OTSMANE               \n");
    printf("                                \033[0;44m\033[1m                          \033[0m  \033[0;94m\033[1m&\033[0m \033[1mRayane KERFNOUF                \n");
    printf("                                \033[0;44m\033[1m                          \033[0m\n");
    printf("                                \033[0;44m\033[1m                  Section \033[0m  \033[1mC                                \n");
    printf("                                \033[0;44m\033[1m                    Group \033[0m  \033[1m11                               \n");
    printf("                                \033[0;44m\033[1m                          \033[0m\n");
    printf("                                \033[0;44m\033[1m Under The Supervision Of \033[0m  \033[1mDr. KERMI Adel\033[0m                    \n");
    printf("                                \033[0;44m\033[1m                          \033[0m\n\n\n\n\n\n");
    printf("            #  Welcome To The Regional University Games Program, Click \"\033[0;94mENTER\033[0m\" To Head to The Main Menu.");
    getchar();
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void MenuDisplay(int ch) {
    
    char Menu[8][150] = { " 1   Sign In A New Athlete To The Games                                           ", " 2   Display Athletes Information Of An University Institute                      ", " 3   Check Wether No Athlete Is Signed In To A Sport Event                        ",
                        " 4   Display The Registered Athletes Information To The Regional University Games ", " 5   Delete An Institution From Participating In The Games                        ", " 6   Delete An Athlete From Participating In The Games                            ", " 7   Delete Sport Events With No Registered Athletes                              ", " 8   Exit                                                                         "};
    system("cls");                                                                                                                                                                                                                                                                                                                 
    Header();
    printf("     \033[1m| Principal Menu\033[0m                                              \n\n\n");
    for (int i = 0; i < 8; i++)
    {
        if (i == ch)
        {
            printf("         \033[0;44m  %s\033[0m\n\n", Menu[i]);
        } else {
            printf("         %s\n\n", Menu[i]);
        }
        
    }
    
    printf("\n\n");
    printf("     #  Please, Navigate Through The Menu Using Keyboard Arrows,\n        Click \"\033[0;94mENTER\033[0m\" To Validate Your Choice ");
}

int MainMenu(){

    int i = 1;
    int ch = 0;

    MenuDisplay(i-1);

    do
    {
        ch = getch();
        switch ( ch )
        {
        case 80:
            i++;
            if ( i > 8 )
            {
                i = 1;
            }
            MenuDisplay(i-1);
            break;
        case 72:
            i--;
            if ( i < 1 )
            {
                i = 8;
            }
            MenuDisplay(i-1);
            break;
        default:
            break;
        }

    } while ( ch != 13 );

    return i;
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void MenuDisplay2(int ch) {
    
    char Menu[3][100] = { " 1   Delete One Athlete                              ", " 2   Delete All Athletes Registered To A Sport Event ", " 3   Exit                                            "};                                                                                                                                                                                            
    system("cls");  
    Header();
    printf("     \033[1m| Delete Athletes From Participating In The Games\033[0m                                              \n\n\n");
    for (int i = 0; i < 3; i++)
    {
        if (i == ch)
        {
            printf("         \033[0;44m  %s\033[0m\n\n", Menu[i]);
        } else {
            printf("         %s\n\n", Menu[i]);
        }
        
    }
    
    printf("\n\n");
    printf("     #  Please, Navigate Through The Menu Using Keyboard Arrows,\n        Click \"\033[0;94mENTER\033[0m\" To Validate Your Choice ");
}

int SubMenu2(){

    int i = 1;
    int ch = 0;

    MenuDisplay2(i-1);

    do
    {
        ch = getch();
        switch ( ch )
        {
        case 80:
            i++;
            if ( i > 3 )
            {
                i = 1;
            }
            MenuDisplay2(i-1);
            break;
        case 72:
            i--;
            if ( i < 1 )
            {
                i = 3;
            }
            MenuDisplay2(i-1);
            break;
        default:
            break;
        }

    } while ( ch != 13 );

    return i;
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//


//-----------------------------------------------------------------//-----------------------------------------------------------------//

void Universities(char tabuniv[maxuniv][100], int sizeuniv){
    for (int i = 0; i < sizeuniv; i++)
    {
        printf(     "%d- ",i+1);
        printf("%s\n",tabuniv[i]);
    }
}

void Events(char tabepreuve[maxepreuve], int sizeepreuve){
    for (int i = 0; i < sizeepreuve; i++)
    {
        printf(     "%d- ",i+1);
        printf("%s\n",tabepreuve[i]);
    }
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void print_llc(ptr h) {

    printf("     \033[0;44m                                                                                                      \033[0m\n");
    printf("     \033[0;44m            ID                                        First Name                           Last Name  \033[0m\n");
    printf("     \033[0;44m                                                                                                      \033[0m\n");
    printf("     \033[0;44m                 \033[0m                                     \n");
    while ( h != NULL )
    {
        printf("     \033[0;44m         %05d   \033[0m  %45s %35s  \n", h->ath.numath, h->ath.prenomath , h->ath.nomath);
        h = next(h);
    }
    printf("     \033[0;44m                 \033[0m                                          \n");
    // printf("     ---------------------------------------------------------------\n");
    // printf("     |    ID |                First Name                 Last Name |\n");
    // printf("     |-------------------------------------------------------------|\n");
    // while ( h != NULL )
    // {
    //     printf("     | %05d | %25s %25s |\n", h->ath.numath, h->ath.prenomath , h->ath.nomath);
    //     h = next(h);
    // }
    // printf("     ---------------------------------------------------------------\n");
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

void AFFICHAGE_1(ptr tabju[][maxuniv], char tabuniv[][100], char tabepreuve[][25]) {
        int i;
        printf("Choose University ( from 1 to 45 ) : ");
        scanf("%d", &i);
        printf("-------------------------------------------\n");
        printf("%s\n",tabuniv[i]);
        printf("-------------------------------------------\n");
        for (int j = 0; j < maxepreuve; j++)
        {
            printf("|%25s  \n",tabepreuve[j]);
            printf("-------------------------------------------\n");
            if ((tabju[j][i]) == NULL)
            {
                printf("| There is no athlete       \n");
            } else {
                printf("|    no |             nom          prenom |\n");
                printf("-------------------------------------------\n");
                print_llc(tabju[j][i]);
            }
            printf("-------------------------------------------\n");
        }
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//

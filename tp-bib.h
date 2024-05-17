#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

#include "tp-abstract-machine.h"
#include "tp-affichage.h"

#define data "tp-data.txt"
#define maxepreuve 20
#define maxuniv 45
#define MAX_ATH 15
#define MAX_NUMATH 13500

//-----------------------------------------------------------------/PROC 1/-----------------------------------------------------------------//

//read the vector containing the univercity institutions in the center region
void read_tabuniv(char T[][100]) {
    FILE *univ;
    char univname[100];

    //open the file for reading
    univ = fopen(data, "r");
    if (univ == NULL) {
        printf("Error opening file %s\n", data);
        return;
    }

    // Read integers from the file and store them in the table
    for (int i = 0; i < maxuniv+1; i++)
    {
        fgets(univname, 100, univ);
        if ( i>0 )
        {
            // Replace newline with null terminator
            if (univname[strlen(univname) - 1] == '\n') {
                univname[strlen(univname) - 1] = '\0'; 
            }
            strcpy(T[i-1], univname);
        }
    }
    
    // Close the file
    fclose(univ);
}

//read the vector containing the sport events
void read_tabepreuve(char T[][25]) {
    FILE *epr;
    char epreuve[500];

    //open the file for reading
    epr = fopen(data, "r");
    if (epr == NULL) {
        printf("Error opening file %s\n", data);
        return;
    }

    for (int i = 0; i < maxepreuve+maxuniv+2; i++)
    {
        fgets(epreuve, 500, epr);
        if (i>maxuniv+1)
        {
            // Replace newline with null terminator
            if (epreuve[strlen(epreuve) - 1] == '\n') {
                epreuve[strlen(epreuve) - 1] = '\0'; 
            }
            strcpy(T[i-(maxuniv+2)], epreuve);
        }
    }

    // Close the file
    fclose(epr);
}

//see if a value already exists in a vector
bool rechnumath(int num, ptr T[][45], int sizeep, int sizeuni) {
    bool found = false;
    int i = 0, j = 0;
    ptr p;
    while ( (i < sizeep) && (found == false) )
    {
        j = 0;
        while ( (j < sizeuni) && (found == false) )
        {
            p = T[i][j];
            while ( ( p != NULL ) && (found == false))
            {
                if ( numath(p) == num )
                {
                    found = true;
                }
                p = next(p);
            }
            j++;
        }
        i++;
    }
    return found;
}

//Generate a unique number for the athlete 
int generatenumath(ptr Tabju[][maxuniv], int sizeep, int sizeuni) {
    int numath;
    do
    {
        numath = rand() % MAX_NUMATH+1;
    } while ( rechnumath(numath, Tabju, sizeep, sizeuni) );
    return numath;
}

//Generate the name of the athlete ( also the last name )
void generatestr(char *strath){
    int MAX = rand() % (10 - 3 + 1) + 3, ascii;
    char str[25];
    for (int i = 0; i < MAX; i++)
    {
        ascii = rand() % ( 25 ) + 97;
        str[i] = ascii;
    }
    str[0]=str[0]-32;
    str[MAX] = '\0'; // Null-terminate the string
    strcpy(strath, str);
}

//Generate an athlete
void generateath(athlete *ath, ptr Tabju[][maxuniv], int sizeep, int sizeuni) {
    ath->numath=generatenumath(Tabju, sizeep, sizeuni);
    generatestr(ath->nomath);
    generatestr(ath->prenomath);
}

//Create the list of athletes
void create_tabjru(ptr *h, int n, ptr T[][maxuniv], int sizeep, int sizeuni) {
    ptr p, q;
    athlete ath;
    int i;
    if (n == 0) { // If n == 0, it's an empty list
        *h = NULL;
    } else {
        allocate(&p); // The first node
        generateath(&ath, T, sizeep, sizeuni);
        ass_ath(p, ath);
        *h = p;
        for (i = 0; i < n-1; i++) { // From the second node
            allocate(&q);
            generateath(&ath, T, sizeep, sizeuni);
            ass_ath(q, ath);
            ass_addr(p, q);
            p = q;
        }
        ass_addr(p, NULL); // The end of the list
    }
}

//The first procedure which creates tabuniv and tabepreuve, as well as the tabjru LLC matrix containing the records of all athletes from all universities in all events. 
void create_tabju(ptr tabju[][maxuniv], char tabuniv[][100], char tabepreuve[][25]) {
    int n;
    read_tabuniv(tabuniv);
    read_tabepreuve(tabepreuve);
    for (int i = 0; i < maxepreuve; i++)
    {
        for (int j = 0; j < maxuniv; j++)
        {
            n = rand() % 16; //Generate the number of athletes randomly per sport event
            create_tabjru(&(tabju[i][j]), n, tabju, i, j); 
        }
    }
}

//-----------------------------------------------------------------/PROC 2/-----------------------------------------------------------------//

//the length of the list
int length_llc(ptr p) {
    int cpt = 0;
    while ( p != NULL )
    {
        p = next(p);
        cpt++;
    }
    return cpt;
}

// Sign In A New Athlete To The Games
void addath(int numath, char* nomath, char* prenomath, int numet, int numep, ptr tabju[][maxuniv], int sizeepreuve, int sizeuniv) {
    ptr q;
    athlete ath;

    numet--; 
    numep--;

    if (length_llc(tabju[numep][numet]) >= MAX_ATH)
    {
        printf("     \033[0;41mThere Are Enough Athletes Signed In !\033[0m \n\n");
    } else {
        if (rechnumath(numath, tabju, sizeepreuve, sizeuniv))
        {
            printf("     \033[0;41mThe Athlete's ID Already Exists ! \n\n\033[0m");
        } else {
            allocate(&q);
            ath.numath=numath;
            strcpy(ath.nomath, nomath);
            strcpy(ath.prenomath, prenomath);
            ass_ath(q, ath);
            ass_addr(q,tabju[numep][numet]);
            tabju[numep][numet]=q;
            printf("     \033[0;42mThe Athlete \033[1m%s %s\033[0m\033[0;42m Has Been Signed In Successfully !\033[0m\n\n", prenomath, nomath);
        }
    }
}

//-----------------------------------------------------------------/PROC 3/-----------------------------------------------------------------//

// Display Athletes Information Of An niversity Institute
void listathet (char institution[100], char tabuniv[maxuniv][100], char tabepreuve[maxepreuve][25], ptr tabju[maxepreuve][maxuniv], int sizeepreuve, int sizeuniv)
{
        int numet = 0, found = -1;
        char str1[100], str2[100];

        strcpy(str1,institution);

        while ( (found != 0) && (numet < sizeuniv) )
        {
            strcpy(str2,tabuniv[numet]);
            found = strcmp(strupr(str2),strupr(str1));
            numet++;
        }
        numet--;

        if ( found == 0 )
        {
            printf("\n\n     \033[0;43m                                                                                                      \033[0m\n");
            printf("     \033[0;43m\033[1m  %-100s\033[0m\n",tabuniv[numet]);
            printf("     \033[0;43m                                                                                                      \033[0m\n");
                for (int j = 0; j < sizeepreuve; j++) 
                {
                    if ((tabju[j][numet]) != NULL)
                    {
                        printf("     \033[0;104m                                                                                                      \033[0m\n");
                        printf("     \033[0;104m\033[1m  %-100s\033[0m\n",tabepreuve[j]);
                        printf("     \033[0;104m                                                                                                      \033[0m\n");
                        print_llc(tabju[j][numet]);
                    }
                }
            printf("     \033[0;43m\033[1m                                    REGIONAL UNIVERSITY GAMES                                         \033[0m\n");

        } else {
            printf("\n\n    \033[0;41mError! University Institution Not Found. Please, try again later\033[0m \n\n");
        }
}

//-----------------------------------------------------------------/PROC 4/-----------------------------------------------------------------//

// Check Wether No Athlete Is Signed In To An Event
bool withoutath(ptr tabju[maxepreuve][maxuniv], int ne, int sizeuniv)
{
    bool find = true;
    int j = 0;
    while (j < sizeuniv && find == true)
    {
        if (tabju[ne][j] != NULL)
        {
            find = false;
        }
        j++;
    }
    return find;
}

//-----------------------------------------------------------------/PROC 5/-----------------------------------------------------------------//

//-----------------------------------------------------------/AFFICHAGE/--------------------------------------------------------------//

void MenuDisplay4(int ch, ptr tabju[][maxuniv], char tabepreuve[][25], int sizeepreuve, int sizeuniv) {
    
    system("cls");  
    Header();
    printf("     \033[1m|  Display The Registered Athletes Information To The Regional University Games\033[0m                                              \n\n\n");
    for (int i = 0; i < (sizeepreuve+1); i++)
    {
        if (i == sizeepreuve)
        {
            if (ch == sizeepreuve)
            {
                printf("         \033[0;41m  Exit.          \033[0m   \n\n");
            } else {
                printf("           Exit.\n\n");
            }
        } 
        else
        {
            if (i == ch)
            {
                printf("         \033[0;44m  %-15s\033[0m   ", tabepreuve[i]);
                if ( ((i+1)%3) == 0 )
                {
                    printf("\n\n");
                }
            } else {
                printf("           %-15s   ", tabepreuve[i]);
                if ( ((i+1)%3) == 0 )
                {
                    printf("\n\n");
                }
            }
        }
    }
    printf("\n\n");
    printf("     #  Please, Navigate Through The Menu Using Keyboard Arrows,\n        Click \"\033[0;94mENTER\033[0m\" To Validate Your Choice ");
}

int SubMenu4(ptr tabju[][maxuniv], char tabepreuve[][25], int sizeepreuve, int sizeuniv){

    int i = 1;
    int ch = 0;

    MenuDisplay4(i-1, tabju, tabepreuve, sizeepreuve, sizeuniv);

    do
    {
        ch = getch();
        switch ( ch )
        {
        case 80:
            i++;
            if ( i > (sizeepreuve+1) )
            {
                i = 1;
            }
            MenuDisplay4(i-1, tabju, tabepreuve, sizeepreuve, sizeuniv);
            break;
        case 72:
            i--;
            if ( i < 1 )
            {
                i = sizeepreuve + 1;
            }
            MenuDisplay4(i-1, tabju, tabepreuve, sizeepreuve, sizeuniv);
            break;
        default:
            break;
        }

    } while ( ch != 13 );

    return (i-1);
}

//-----------------------------------------------------------/AFFICHAGE/--------------------------------------------------------------//

//Display The Registered Athletes Information To The Regional University Games
void listju(ptr tabju[][maxuniv], char tabuniv[][100], char tabepreuve[][25], int sizeepreuve, int sizeuniv) {

        int i;

        do
        {

            i = SubMenu4(tabju, tabepreuve, sizeepreuve, sizeuniv);

            system("cls");  
            Header();
            printf("     \033[1m|  Display The Registered Athletes Information To The Regional University Games\033[0m                      \n\n\n");

            if ( (withoutath(tabju, i, sizeuniv) == false) && ( i != sizeepreuve ) )
            {
                printf("     \033[0;43m                                                                                                      \033[0m\n");
                printf("     \033[0;43m\033[1m  %-100s\033[0m\n",tabepreuve[i]);
                printf("     \033[0;43m                                                                                                      \033[0m\n");
                    for (int j = 0; j < sizeuniv; j++) 
                    {
                        if ((tabju[i][j]) != NULL)
                        {
                            printf("     \033[0;104m                                                                                                      \033[0m\n");
                            printf("     \033[0;104m\033[1m  %-100s\033[0m\n",tabuniv[j]);
                            printf("     \033[0;104m                                                                                                      \033[0m\n");
                            print_llc(tabju[i][j]);
                        }
                    }
                printf("     \033[0;43m\033[1m                                    REGIONAL UNIVERSITY GAMES                                         \033[0m\n");

                printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Sport Events Menu ...");
                getchar();
            }
            if ( (withoutath(tabju, i, sizeuniv)) && ( i != sizeepreuve ) )
            {
                printf("\n\n     No Athlete Is Registered To The Sport Event \033[0;33m\033[1m%s\033[0m.", tabepreuve[i]);

                printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Sport Events Menu ...");
                getchar();
            }

        } while ( i != sizeepreuve );

}

//-----------------------------------------------------------------/PROC 6/-----------------------------------------------------------------//

// Delete An Institution From Participating In The Games
void delet (char etablissement[100], char tabuniv[maxuniv][100], ptr tabju[maxepreuve][maxuniv], int sizeepreuve, int *sizeuniv) //PROC6
{
        int numet = 0, found = -1;
        char str1[100], str2[100];

        strcpy(str1,etablissement);

        while ( (found != 0) && (numet < (*sizeuniv)) )
        {
            strcpy(str2,tabuniv[numet]);
            found = strcmp(strupr(str2),strupr(str1));
            numet++;
        }
        numet--;
        
        if ( found == 0 )
        {

            printf("\n     \033[0;42mThe University Institution \033[1m%s\033[0;42m Has Been Deleted Successfully !\033[0m \n\n", tabuniv[numet]);

            for (int j = numet; j < ((*sizeuniv)-1); j++)
            {
                strcpy(tabuniv[j],tabuniv[j+1]);
            }

            for (int i = 0; i < sizeepreuve; i++)
            {
                for (int j = numet; j < ((*sizeuniv)-1); j++)
                {
                    tabju[i][j] = tabju[i][j+1];
                }
                tabju[i][(*sizeuniv)-1] = NULL;
            }
            (*sizeuniv)--;
        } else {
            printf("\n     \033[0;41mError! University Institution Not Found. Please, try again later\033[0m \n\n");
        }
}

//-----------------------------------------------------------------/PROC 7/-----------------------------------------------------------------//

// return the pointer address of the node containing the wanted athlete, and the node before
void rech_ath(ptr l, int v, bool *find, ptr *prec, ptr *p)
{
    *find = false;
    ptr h = l; // h is a pointer to the head of the list

    if (numath(h) == v) // if the value is in the head
    {
        *p = h;
        *prec = NULL;
        *find = true;
    }
    else
    {
        while ((next(h) != NULL) && (*find == false))
        {
            if (numath(next(h)) == v)
            {
                *prec = h;
                *p = next(h); // the value is in the next cell
                *find = true;
            }
            h = next(h); // move to the next cell
        }
    }
}

// Delete Athletes From Participating In The Games
void delath(ptr *t, int nath)
{
    ptr prec, p;
    bool find;
    char nom[25], prenom[25];

    rech_ath(*t, nath, &find, &prec, &p); // search for the athlete

    if (find == true) // if the athlete is found
    {
        strcpy(nom, nomath(p));
        strcpy(prenom, prenomath(p));
        if (prec == NULL) // if the athlete is in the head
        {
            *t = next(p);
        }
        else // if the athlete is not in the head
        {
            ass_addr(prec, next(p));
        }
        free(p);
        printf("\n\n     \033[0;42mThe Athlete \033[1m%s %s\033[0m\033[0;42m Has Been Deleted Successfully !\033[0m", prenom, nom);
    }

    else // if the athlete is not found
    {
        printf("\n\n     \033[0;41mError ! Athlete Not Found. Please, try again later...\033[0m");
    }
}

//-----------------------------------------------------------------/PROC 8/-----------------------------------------------------------------//

// Delete Sport Events With No Registered Athletes
void delemptylines(ptr tabju[maxepreuve][maxuniv], char tabepreuve[maxepreuve][25], int *sizeepreuve, int sizeuniv)
{
    int i = 0;
    bool found = false;
    while (i < (*sizeepreuve))
    {
        if (withoutath(tabju, i, sizeuniv) == true) // if a line is empty
        {

            printf("\33[2K\r     \033[0;32mThe Sport Event \033[1m%s\033[0m\033[0;32m Has Been Deleted Successfully !\033[0m \n", tabepreuve[i]);

            // shifting in tabepreuve (le vecteur)
            for (int j = i; j < ((*sizeepreuve) - 1); j++)
            {
                strcpy(tabepreuve[j], tabepreuve[j + 1]);
            }

            // shifting in tabju (la matrice)
            for (int j = i; j < ((*sizeepreuve) - 1); j++)
            {
                for (int k = 0; k < (sizeuniv); k++)
                {
                    tabju[j][k] = tabju[j + 1][k];
                }
            }
            (*sizeepreuve)--; // decrease the size of columns
            found = true;
        } else {
            i++;
        }
    }
    if (found == false)
    {
        printf("\33[2K\r     \033[0;41mEvery Sport Event Has At Least One Athlete Registered !\033[0m");
    }
}

//-----------------------------------------------------------------//-----------------------------------------------------------------//
#include <stdlib.h>
#include <string.h>

//---------------------------------------/DATA STRUCTURE/------------------------------------------//

// The information of the athlete
typedef struct {
    int numath; //ID number
    char nomath[25]; //Last Name
    char prenomath[25]; //First Name
} athlete;

//The type cell of the list
typedef struct cell {
    athlete ath;
    struct cell *addr;
} cell;

//define the type pointer
typedef struct cell* ptr;

//------------------------------------------------//----------------------------------------------//

//allocate
void allocate(ptr *p) 
{
    *p = (ptr)malloc(sizeof(cell));
}
//---------

//free(p);
void Free (ptr *p)
{
    free(p);
}
//---------

//assign an athlete 
void ass_ath( ptr p, athlete ath )
{
    p->ath=ath;
}
//---------

//assign an athlete
    //numath
    void ass_numath( ptr p, int num )
    {
        p->ath.numath = num;
    }
    //nomath
    void ass_nomath( ptr p, char nom[])
    {
        strcpy(p->ath.nomath, nom);
    }
    //prenomath
    void ass_prenomath( ptr p, char prenom[] )
    {
        strcpy(p->ath.prenomath, prenom);
    }
//---------

//assign an address
void ass_addr( ptr p, ptr q)
{
    p->addr = q;
}
//---------

//return the athlete's number
int numath( ptr p )
{
    return p->ath.numath;
}
//---------

//return the athlete's name
char* nomath( ptr p )
{
    return p->ath.nomath;
}
//---------

//return the athlete's last name
char* prenomath( ptr p )
{
    return p->ath.prenomath;
}
//---------

//return the address assigned to the cell (the address of the next cell)
ptr next( ptr p )
{
    return p->addr;
}
//---------

#ifndef JOL_H_INCLUDED
#define JOL_H_INCLUDED

#include <stdlib.h>
#include <iostream>

using namespace std;

#define infoO(P) (P)->infoO
#define brpkali(P)  (P)->brpkali
#define nextO(P) (P)->nextO
#define prevO(P) (P)->prevO
#define nextP(P) (P)->nextP
#define prevP(P) (P)->prevP
#define infoP(P) (P)->infoP
#define siojol(P) (P)->siojol
#define sipenumpang(P) (P)->sipenumpang
#define nextR(P) (P)->nextR
#define prevR(P) (P)->prevR
#define firstO(L) ((L).firstO)
#define lastO(L) ((L).lastO)
#define firstP(L) ((L).firstP)
#define lastP(L) ((L).lastP)
#define firstR(L) ((L).firstR)
#define lastR(L) ((L).lastR)
typedef struct elmojol *adrojol;
typedef struct elmpenumpang *adrpenumpang;
typedef struct elmrelasi *adrrelasi;

struct elmojol {
    string infoO;
    adrojol nextO;
    adrojol prevO;
    int brpkali;
};
struct elmrelasi{
    adrojol siojol;
    adrpenumpang sipenumpang;
    adrrelasi nextR;
    adrrelasi prevR;
};
struct listojol {
    adrojol firstO;
    adrojol lastO;
};
struct elmpenumpang {
    string infoP;
    adrpenumpang nextP;
    adrpenumpang prevP;
};
struct listpenumpang {
    adrpenumpang firstP;
    adrpenumpang lastP;
};
struct listRelasi{
    adrrelasi firstR;
    adrrelasi lastR;
};

void createlistOjol(listojol &O);
void createlistPenum(listpenumpang &P);
void createlistRelasi(listRelasi &R);
void insertojol(listojol &O);
void insertpenum(listpenumpang &P);
bool isEmptyO(listojol O);
bool isEmptyP(listpenumpang P);
bool isEmptyR(listRelasi R);
void delojol(listojol &O, adrojol siojol);
void delpenum(listpenumpang &P, adrpenumpang sipenum);
void printojol(listojol &O);
void printpenum(listpenumpang &P);
adrrelasi alokasi(adrojol O, adrpenumpang P);
void insertrelasi(listRelasi &R, adrrelasi rel);
adrojol cariojol(listojol O, string nama);
adrpenumpang caripenumpang(listpenumpang P, string nama);
void printpalingbanyaknarik(listojol &O);
void printrelasi(listRelasi &R);
void printojoldaripenumpang(listRelasi &R);

#endif // JOL_H_INCLUDED

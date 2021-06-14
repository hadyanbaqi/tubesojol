#include "jol.h"
void createlistOjol(listojol &O){
    firstO(O)   =   NULL;
    lastO(O)    =   NULL;
}
void createlistPenum(listpenumpang &P){
    firstP(P)   =   NULL;
    lastP(P)    =   NULL;
}
void createlistRelasi(listRelasi &R){
    firstR(R)   =   NULL;
    lastR(R)    =   NULL;
}
bool isEmptyO(listojol O){
    return (firstO(O)==NULL && lastO(O)==NULL);
}
bool isEmptyP(listpenumpang P){
    return (firstP(P)==NULL && lastP(P)==NULL);
}
bool isEmptyR(listRelasi R){
    return (firstR(R)==NULL && lastR(R)==NULL);
}
void insertojol(listojol &O){
    string nama;
    cout<<"Nama Ojol : ";
    cin>>nama;
    adrojol P= new elmojol;
    infoO(P)    =   nama;
    brpkali(P)  =   0;
    nextO(P)    =   NULL;
    prevO(P)    =   NULL;
    if (isEmptyO(O)){
        firstO(O)   =   P;
        lastO(O)    =   P;
    }else{
        nextO(lastO(O)) = P;
        prevO(P)        = lastO(O);
        lastO(O)        = P;
    }
}
void insertpenum(listpenumpang &P){
    string nama;
    cout<<"Nama Penumpang : ";
    cin>>nama;
    adrpenumpang Q = new elmpenumpang;
    infoP(Q)    =   nama;
    nextP(Q)    =   NULL;
    prevP(Q)    =   NULL;
    if (isEmptyP(P)){
        firstP(P)   =   Q;
        lastP(P)    =   Q;
    }else{
        nextP(lastP(P)) =   Q;
        prevP(Q)        =   lastP(P);
        lastP(P)        =   Q;
    }
}
void delojol(listojol &O, adrojol siojol){
    if ((firstO(O)==siojol)&&(lastO(O)==siojol)){
        firstO(O)   =   NULL;
        lastO(O)    =   NULL;
    }else{
        if(firstO(O)==siojol){
            firstO(O)           =   nextO(siojol);
            prevO(firstO(O))    =   NULL;
            nextO(siojol)       =   NULL;
        }else if (lastO(O)==siojol){
            lastO(O)            =   prevO(siojol);
            prevO(siojol)       =   NULL;
            nextO(lastO(O))     =   NULL;
        }else{
            nextO(prevO(siojol))    =   nextO(siojol);
            prevO(nextO(siojol))    =   prevO(siojol);
            nextO(siojol)           =   NULL;
            prevO(siojol)           =   NULL;
        }
    }
}
void delpenum(listpenumpang &P, adrpenumpang sipenum){
    if ((firstP(P)==sipenum)&&(lastP(P)==sipenum)){
        firstP(P)   =   NULL;
        lastP(P)    =   NULL;
    }else{
        if(firstP(P)==sipenum){
            firstP(P)           =   nextP(sipenum);
            prevP(firstP(P))    =   NULL;
            nextP(sipenum)      =   NULL;
        }else if (lastP(P)==sipenum){
            lastP(P)            =   prevP(sipenum);
            prevP(sipenum)      =   NULL;
            nextP(lastP(P))     =   NULL;
        }else{
            nextP(prevP(sipenum))   =   nextP(sipenum);
            prevP(nextP(sipenum))   =   prevP(sipenum);
            nextP(sipenum)  =   NULL;
            prevP(sipenum)  =   NULL;
        }
    }
}
void printojol(listojol &O){
    adrojol P = firstO(O);
    while (P!=NULL){
        cout<<"Nama Ojol: "<<infoO(P)<<endl;
        P=nextO(P);
    }
}
void printpenum(listpenumpang &P){
    adrpenumpang Q = firstP(P);
    while(Q!=NULL){
        cout<<"Nama Penumpang: "<<infoP(Q)<<endl;
        Q=nextP(Q);
    }
}
void printpalingbanyaknarik(listojol &O){
    adrojol Q = firstO(O);
    int temp = 0;
    string tempnama;
    while (Q!=NULL){
        if(brpkali(Q)>temp){
            temp        =   brpkali(Q);
            tempnama    =   infoO(Q);
            Q           =   nextO(Q);
        }else{
            Q           =   nextO(Q);
        }
    }
    cout<<"Nama Ojol dengan Pengambilan penumpang yang paling banyak adalah: "<<tempnama<<endl;
    cout<<"Dengan total penumpang sebanyak: "<<temp<<endl;
}
void printrelasi(listRelasi &R){
    if (isEmptyR(R)){
        cout<<"Belum ada yang narik"<<endl;
    }else{
        adrrelasi P = firstR(R);
        while(P!=NULL){
            cout<<"Ojol : "<<infoO(siojol(P))<<endl;
            cout<<"Penumpang : "<<infoP(sipenumpang(P))<<endl;
            cout<<endl;
            P=nextR(P);
        }
    }
}
void printojoldaripenumpang(listRelasi &R){
    string namapenumpang;
    cout<<"Nama ojol dari penumpang: ";
    cin>>namapenumpang;
    adrrelasi X = firstR(R);
    cout<<"Nama ojol yang narik "<<namapenumpang<<" yaitu: "<<endl;
    while (X!=NULL){
        if (infoP(sipenumpang(X))==namapenumpang){
            cout<<infoO(siojol(X))<<endl;
            X=nextR(X);
        }else{
            X=nextR(X);
        }
    }
}
adrrelasi alokasi(adrojol O, adrpenumpang P){
    adrrelasi X = new elmrelasi;
    siojol(X)=O;
    sipenumpang(X)=P;
    nextR(X)=NULL;
    prevR(X)=NULL;
    brpkali(O)++;
    return X;
}
void insertrelasi(listRelasi &R, adrrelasi X){
    if((firstR(R)==NULL)&&(lastR(R)==NULL)){
        firstR(R)=X;
        lastR(R)=X;
    }else{
        nextR(lastR(R))=X;
        prevR(X)=lastR(R);
        lastR(R)=X;
    }
}
adrojol cariojol(listojol O, string nama){
    adrojol P,X;
    P=firstO(O);
    X=NULL;
    while (P!=NULL){
        if(infoO(P)==nama){
            X=P;
        }
        P=nextO(P);
    }
    return X;
}
adrpenumpang caripenumpang(listpenumpang P, string nama){
    adrpenumpang Q,X;
    Q=firstP(P);
    X=NULL;
    while (Q!=NULL){
        if(infoP(Q)==nama){
            X=Q;
        }
        Q=nextP(Q);
    }
    return X;
}

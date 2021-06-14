#include "jol.h"
//1.menambahkan ojol
//2.menambahkan penumpang baru
//3.menambahkan hubungan antara ojol dan penumpang
//4.menghapus ojol tertentu
//5.menghapus penumpang tertentu
//6.menampilkan ojol yang banyak melayani penumpang
//7.menampilkan ojol dari penumpang tertentu
//8.menampilkan penumpang yang memesan ojol lbh dari dua kali di hari itu
//9.menampilka semua ojol dan list penumpangnya


int main()
{
    listojol O;
    listpenumpang P;
    listRelasi R;
    createlistOjol(O);
    createlistPenum(P);
    createlistRelasi(R);
    string nama,napen;
    adrojol ojol;
    adrpenumpang penum;
    adrrelasi rel;
    int X;
    bool pilih = false;
    do{
        cout<<"Selamat datang di Menu Utama"<<endl;
        cout<<"1. Menu menambahkan ojol"<<endl;
        cout<<"2. Menambahkan penumpang"<<endl;
        cout<<"3. menambahkan hubungan ojol dan penumpang"<<endl;
        cout<<"4. mengahpus ojol"<<endl;
        cout<<"5. menghapus penumpang"<<endl;
        cout<<"6. Menampilkan ojol paling banyak mengambil penumpang"<<endl;
        cout<<"7. menampilkan ojol"<<endl;
        cout<<"8. Menampilkan penumpang"<<endl;
        cout<<"9. menampilkan penumpang dengan ojolnya"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"Pilih menu: ";
        cin>>X;
        switch (X) {
            case 1:
                insertojol(O);
                break;
            case 2:
                insertpenum(P);
                break;
            case 3:
                cout<<"Selamat datang di menu buat relasi"<<endl;
                cout<<"Masukan nama ojol yang ingin di relasi kan: "<<endl;
                cin>>nama;
                cout<<endl;
                ojol = cariojol(O, nama);
                cout<<"Masukan nama penumpang yang akan berelasi dengan "<<nama<<endl;
                cin>>napen;
                penum = caripenumpang(P, napen);
                rel=alokasi(ojol, penum);
                insertrelasi(R, rel);
                break;
            case 4:
                cout<<"Menu Hapus"<<endl;
                cout<<"Masukan ojol yang ingin di hapus: "<<endl;
                cin>>nama;
                ojol = cariojol(O, nama);
                if(ojol==NULL){
                    cout<<"Ojol tidak ditemukan"<<endl;
                }else{
                    delojol(O, ojol);
                }
                break;
            case 5:
                cout<<"Menu Hapus"<<endl;
                cout<<"Masukan penumpang yang ingin di hapus: "<<endl;
                cin>>napen;
                penum = caripenumpang(P, napen);
                if(penum==NULL){
                    cout<<"penumpang tidak ditemukan"<<endl;
                }else{
                    delpenum(P, penum);
                }
                break;
            case 6:
                printpalingbanyaknarik(O);
                break;
            case 7:
                printojol(O);
                break;
            case 8:
                printpenum(P);
                break;
            case 9:
                printojoldaripenumpang(R);
                break;
            case 10:
                pilih=true;
                break;
        }
    }while(pilih == false);
}


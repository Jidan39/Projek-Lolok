#include <iostream>
#include <string.h>
#include <cctype>
#include <fstream>
#include <windows.h>

using namespace std;

//==========================================
// DILARANG MENAMBAH FITUR LAGI YA DEK


//change color
void setcolor(unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);

}
//end change color

//Fungsi Pengembalian
void pengembalian() {
    system("cls");

    string nama;
    int nim, balik, kembali, jumlahdenda = 0;
    string judul[5];
    string author[5];
    string kasus[4];
    int hari[5];
    int denda[5];

    time_t sekarang = time(0);
    tm * waktu_lokal = localtime(&sekarang);

    int tahun = 1900 + waktu_lokal->tm_year;
    int bulan = 1 + waktu_lokal->tm_mon;
    int hari1 = waktu_lokal->tm_mday;

    cout << "===================================" << endl;
    cout << "     Layanan Pengembalian Buku     " << endl;
    cout << "===================================" << endl;

    cin.ignore(1, '\n');
    cout << "Masukkan Nama Anda : "; 
    getline(cin, nama);
    cout << "Masukkan NIM Anda  : "; 
    cin >> nim;

    labelU:

    system("cls");
    cout << "Berapa Banyak Buku yang Ingin Anda Kembalikan? [MAX : 5]: ";
    cin >> balik;

    if (balik > 0 & balik <= 5) {
        goto labelP;

    } else {

        system("cls");
        cout << "==================================================" << endl;
        setcolor(12);
        cout << "  Maaf Inputan Yang Anda Masukkan Tidak Tersedia  " << endl;
        setcolor(15);
        cout << "==================================================" << endl;
        system("pause");
        goto labelU;

    }

    labelP:
    system("cls");

    cout << "=================================================" << endl;
    cout << "            List Buku Di Perpustakaan            " << endl;
    cout << "=================================================" << endl;

    string list[5] = {"Bumi Manusia [Pramoedya Ananta Toer]",
        "Pulang [Leila S. Chudori]","Catatan Seorang Demonstran [Seo Hok Gie]","Madilog [Tan Malaka]",
        "Matahari [Tere Liye]"};

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << list[i] << endl;
    }
    
    cout << "=================================================" << endl;
    cout << endl;

    if (balik <= 5 & balik > 0) {
        for (int i = 0; i < balik; i++) {
            cout << endl;
            cout << "Mohon Masukkan Urutan Nomor Buku Yang Ingin Anda Kembalikan : " << endl << i + 1 << ". "; 
            cin >> kembali;
            
            switch (kembali) {
                
                case 1:
                    judul[i] = list[0];
                    break;

                case 2:
                    judul[i] = list[1];
                    break;

                case 3:
                    judul[i] = list[2];
                    break;

                case 4:
                    judul[i] = list[3];
                    break;

                case 5:
                    judul[i] = list[4];
                    break;
            
                default:
                    system("cls");
                    cout << "============================================" << endl;
                    setcolor(12);
                    cout << "            Kode Tidak Tersedia!            " << endl;
                    setcolor(15);
                    cout << "============================================" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    goto labelP;
            }   

            cout << "Berapa hari anda meminjam buku ini? : ";
            cin >> hari[i];

            if (hari[i] > 0 & hari[i] <= 365) {
                continue;

            } else if (hari[i] < 0 & hari[i] > 365) {

                system("cls");
                cout << "==================================================" << endl;
                setcolor(12);
                cout << "    Maaf Jumlah Hari Tidak Tersedia [1 s/d 365]    " << endl;
                setcolor(15);
                cout << "==================================================" << endl;
                system("pause");
                system("cls");
                goto labelP;

            } else {

                system("cls");
                cout << "==================================================" << endl;
                setcolor(12);
                cout << "  Maaf Inputan Yang Anda Masukkan Tidak Tersedia  " << endl;
                setcolor(15);
                cout << "==================================================" << endl;
                system("pause");
                system("exit");

            }
 
        }
    }

    system("cls");
    cout << "============================================" << endl;
    cout << "       List Buku Yang Anda Kembalikan       " << endl;
    cout << "============================================" << endl;

    for (int i = 0; i < balik; i++) {
            cout << i + 1 << ". " << judul[i];
            cout << endl;

            if (hari[i] > 0 & hari[i] <= 365) { 
                if (hari[i] <= 7 & hari[i] > 0) {

          
                denda[i] = 0;
                cout << "=====================================================================" << endl;
                cout << "Terima Kasih '" << nama << "' Karena Telah Mengembalikan Buku Tepat Waktu" << endl;
                cout << "=====================================================================" << endl;
                cout << endl;

            } 
            else if (hari[i] > 7) {

              
                denda[i] = (hari[i] - 7) * 2000;
                cout << "============================================" << endl;
                cout << "Anda Melewati Batas Waktu Pengembalian Buku!" << endl;
                cout << "Anda Dikenakan Denda Sebesar : Rp" << denda[i] << endl;
                cout << "============================================" << endl; 
                cout << endl;
            }

                jumlahdenda += denda[i];
                if (i == balik - 1) {

                cout << "Jumlah Denda Anda Sebesar : Rp" << jumlahdenda << endl;}   
                system("Pause");
                cout << endl;
        } 

    }   

    system("CLS");
    cout << "=============================================" << endl;
    cout << "           Bukti Pengembalian Buku          " << endl;
    cout << "       Perpustakaan Rusdi Ngawi Jawir" << endl;
    cout << "=============================================" << endl;
    cout << "Nama Peminjam                  : " << nama << endl;
    cout << "Nim  Peminjam                  : " << nim << endl;
    cout << "Jumlah Buku Yang Dikembalikan  : " << balik << endl;
    cout << "Total Denda Anda Sebesar       : Rp" << jumlahdenda << endl;
    cout << "Tanggal Pengembalian Buku      : ";
    cout << hari1 << "/" << bulan << "/" << tahun << endl; 
    cout << "=============================================" << endl;

    string nim1 = to_string(nim);

    ofstream fileOut(nim1 + "_BuktiPengembalian.txt");

    fileOut << "==============================================" << endl;
    fileOut << "           Bukti Pengembalian Buku           " << endl;
    fileOut << "       Perpustakaan Rusdi Ngawi Jawir        " << endl;
    fileOut << "==============================================" << endl;
    fileOut << "Nama Peminjam                  : " << nama << endl;
    fileOut << "Nim Peminjam                   : " << nim << endl;
    fileOut << "Jumlah Buku Yang Dikembalikan  : " << balik << endl;
    fileOut << "Total Denda Anda Sebesar       : Rp" << jumlahdenda << endl;
    fileOut << "Tanggal Pengembalian Buku      : " << hari1 << "/" << bulan << "/" << tahun << endl;
    fileOut << "==============================================" << endl;

    fileOut.close();

    cout << endl;
    setcolor(10);
    cout << "Struk Bukti Pengembalian Buku Anda Telah Dibuat." << endl;
    setcolor(15);
}
//End Fungsi Pengembalian

//Fungsi Peminjaman
void peminjaman() {

    system("cls");
    string nama, struk;
    int nim, balik, jumlahdenda = 0;

    time_t sekarang = time(0);
    tm * waktu_lokal = localtime(&sekarang);

    int tahun = 1900 + waktu_lokal->tm_year;
    int bulan = 1 + waktu_lokal->tm_mon;
    int hari1 = waktu_lokal->tm_mday;
    
    cout << "===================================" << endl;
    cout << "      Layanan Peminjaman Buku      " << endl;
    cout << "===================================" << endl;

    cin.ignore(1, '\n');
    cout << "Masukkan Nama Anda : " ; 
    getline(cin, nama);
    cout << "Masukkan NIM Anda : " ; 
    cin >> nim;

    cout << "===================================" << endl;

    labelB:

    system("cls");
    int berapa;
    int ambil;
    string kasus[4];
    
    cout << "=================================================" << endl;
    cout << "            List Buku Di Perpustakaan            " << endl;
    cout << "=================================================" << endl;

    string list[5] = {"Bumi Manusia [Pramoedya Ananta Toer]",
        "Pulang [Leila S. Chudori]","Catatan Seorang Demonstran [Seo Hok Gie]","Madilog [Tan Malaka]",
        "Matahari [Tere Liye]"};

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << list[i] << endl;
    }
    
    cout << "=================================================" << endl;
    cout << endl;
    cout << "Berapa Banyak Buku Yang Ingin Anda Pinjam? [MAX = 3] : "; 
    cin >> berapa;

    if (berapa <= 3 & berapa > 0) {
        for (int i = 0; i < berapa; i++) {
            cout << endl;
            cout << "Mohon Masukkan Urutan Nomor Buku Yang Ingin Anda Pinjam : " << endl << i + 1 << ". "; 
            cin >> ambil;
            
            switch (ambil) {
                
                case 1:
                    kasus[i] = list[0];
                    break;

                case 2:
                    kasus[i] = list[1];
                    break;

                case 3:
                    kasus[i] = list[2];
                    break;

                case 4:
                    kasus[i] = list[3];
                    break;

                case 5:
                    kasus[i] = list[4];
                    break;
            
                default:
                    system("cls");
                    cout << "============================================" << endl;
                    setcolor(12);
                    cout << "            Kode Tidak Tersedia!            " << endl;
                    setcolor(15);
                    cout << "============================================" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    goto labelB;
            }   

            system("cls");   
            
            if (ambil <= 5 & ambil > 0) {
                cout << "==============================================" << endl;
                cout << "         Daftar Buku Yang Anda Pinjam         " << endl;
                cout << "==============================================" << endl;

                for (int i = 0; i < berapa; i++) {
                    cout << i + 1 << ". " << kasus[i] << endl;

                }       
        
            } else {

                system("cls");
                cout << "============================================================" << endl;
                cout << "          Nomor Yang Anda Masukkan Tidak Tersedia           " << endl;
                cout << "Mohon Masukkan Ulang Inputan Anda Sesuai Dengan Yang Tertera" << endl;
                cout << "============================================================" << endl;
                system("pause");
                system("cls");
                goto labelB;
    
            }

        }

            cout << "==============================================" << endl;
            cout << endl;
            system("pause"); 

            cout << "==============================================" << endl;
            cout << endl;
            cout << "Terima Kasih '" << nama << "' Karena Telah Meminjam Buku Menggunakan Layanan Kami:)" << endl;
            cout << "Note : Jangan Lupa Kembalikan Buku Dalam Tenggat Waktu Yang Ditentukan [MAX = 7 Hari]" << endl;
            cout << endl;

    } else {

        system("cls");
        cout << "=================================================" << endl;
        setcolor(12);
        cout << "  Maaf Input Yang Anda Masukkan Tidak Tersedia!  " << endl;
        setcolor(15);
        cout << "=================================================" << endl;
        system("pause");
        goto labelB;

    }

    system("CLS");
    
    cout << "=============================================" << endl;
    cout << "           Bukti Peminjaman Buku            " << endl;
    cout << "       Perpustakaan Rusdi Ngawi Jawir       " << endl;
    cout << "=============================================" << endl;
    cout << "Nama Peminjam                    : " << nama << endl;
    cout << "Nim  Peminjam                    : " << nim << endl;
    cout << "Jumlah Buku Yang Dipinjam        : " << berapa << endl;
    cout << "Tanggal Peminjaman Buku          : " << hari1 << "/" << bulan << "/" << tahun << endl; 
    cout << "=============================================" << endl;
    cout << "Note : Tunjukkan Bukti Peminjaman Buku Disaat Anda Mengembalikan Buku:)" << endl;  
    cout << endl;

    string nim1 = to_string(nim);

    ofstream fileOut(nim1 + "_BuktiPeminjaman.txt");

    fileOut << "==============================================" << endl;
    fileOut << "            Bukti Peminjaman Buku             " << endl;
    fileOut << "        Perpustakaan Rusdi Ngawi Jawir        " << endl;
    fileOut << "==============================================" << endl;
    fileOut << "Nama Peminjam                  : " << nama << endl;
    fileOut << "Nim Peminjam                   : " << nim << endl;
    fileOut << "Jumlah Buku Yang Dipinjam      : " << berapa << endl;
    fileOut << "Tanggal Pengembalian Buku      : " << hari1 << "/" << bulan << "/" << tahun << endl;
    fileOut << "==============================================" << endl;
    fileOut << "Note : Tunjukkan Bukti Peminjaman Buku Disaat Anda Mengembalikan Buku:)" << endl;

    fileOut.close();
    setcolor(10);
    cout << "Struk Bukti Peminjaman Buku Anda Telah Dibuat:D" << endl;
    setcolor(15); 
    
}
//End Fungsi Peminjaman

//Fungsi start
void start() {
    system("cls");
    string SeDa;

    repeat:

    setcolor(14);
    cout << "==========================================================" << endl;
    setcolor(11);    
    cout << " Selamat Datang Di Layanan Perpustakaan Rusdi Ngawi Jawir   " << endl;
    setcolor(14);
    cout << "==========================================================" << endl;
    setcolor(15);

    
    cout << "A. Peminjaman Buku" << endl;
    cout << "B. Pengembalian Buku" << endl;

    setcolor(14);
    cout << "==========================================================" << endl;
    setcolor(15);
    cout << "Silahkan pilih jenis layanan anda [A atau B] : ";
    cin >> SeDa;
    
    if (SeDa == "A" | SeDa == "a") {
        peminjaman();

    } else if (SeDa == "B" | SeDa == "b") {
        pengembalian();
    
    } else {
        system("cls");
        cout << "================================================" << endl;
        setcolor(12);
        cout << "  Maaf Input Yang Anda Masukkan Tidak Tersedia  " << endl;
        setcolor(15);
        cout << "================================================" << endl;
        system("pause");
        system("cls");
        goto repeat;
    }
}
//End Fungsi start


//================================
//Main Program
int main() {
    char any;

    labelA:

    start();
    cout << endl;
    cout << "Apakah Anda Ingin Menggunakan Layanan Lagi? [Y / N]: ";
    cin >> any;
    any = toupper(any);

    if (any == 'Y') {
        goto labelA;

    } else if (any == 'N') {

        system("cls");
        cout << "===================================================" << endl;
        cout << "   Terima Kasih Telah Menggunakan Layanan Kami:)  " << endl;
        cout << "===================================================" << endl;
        system("pause");

    } else {

        system("cls");
        cout << "===================================================" << endl;
        setcolor(12);
        cout << "   Maaf Input Yang Anda Masukkan Tidak Diketahui   " << endl;
        setcolor(15);
        cout << "===================================================" << endl;
        system("pause");

    }

    return 0;

}
//End Main Program
//================================

// DILARANG MENAMBAH FITUR LAGI YA DEK
//==========================================
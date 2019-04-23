#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<fstream>

using namespace std;

void admin();
void guest();
void header();
void tambahbuku();
void cetakbuku_admin();
void cetakbuku_guest();
void keluar();
void kotak();

struct data
{
    int id_buku;
    char judul_buku[20];
	char pengarang[20];
	char penerbit[20];
	int tahun;
	int stock;
}buku[20];


void gotoxy(int x, int y)	//fungsi untuk membuat titik kordinat
{

	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X=x;
	dwCursorPosition.Y=y;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void keluar()      //Tampilan saatkeluar//
{
    system("cls");
    gotoxy(35,6);cout << "\"                                          \"";
    gotoxy(35,7);cout << "TERIMAKASIH TELAH MENGUNJUNGI PERPUSTAKAAN";
    gotoxy(35,8);cout << "        BACALAH LEBIH BANYAK BUKU         ";
    gotoxy(35,9);cout << "\"                                          \"\n\n";
}

main()      //Program input password bagi admin dan guest//
{
    char a;
    char nama[50];
    int pw;
    system("cls");
    kotak();
    header();
    gotoxy(40,8);cout<<"Masukan Username :";cin>>nama;
    gotoxy(40,9);cout<<"Masukan Password :";cin>>pw;
    if(pw==1234)admin();
    else if(pw==123)guest();
    else
    {
        gotoxy(40,10);cout<<"Username & password yang anda masukan salah"; //Ketik y untuk caba lagi memasukan password dan t untuk keluar//
        gotoxy(40,11);cout << "Coba Lagi? [ Y / T ]"; cin >> a;
        if (a == 'y' || a == 'Y')
        main();
        keluar();
    }

}

void header()
{
    gotoxy(35,4);cout<<"\t           Tugas UAS"<<endl;
    gotoxy(35,5);cout<<"\t       Aplikasi Perpustakaan"<<endl;
    gotoxy(35,6);cout<<"\t Agung Prabowo & M. Iqbal Fadillah"<<endl;
    gotoxy(35,7);cout<<"\t-----------------------------------"<<endl;
}

void admin()        //Menu admin//
{
    int kode;
    char b;
        system("cls");
    gotoxy(45,5);cout<<"=========================";
    gotoxy(45,6);cout<<"          MENU          ";
	gotoxy(45,7);cout<<"-------------------------";
	gotoxy(45,9);cout<<" 1.Tambah Data Buku     ";
	gotoxy(45,10);cout<<" 2.Cetak Daftar Buku    ";
	gotoxy(45,11);cout<<" 3.Keluar               ";
	gotoxy(45,13);cout<<"=========================";
	gotoxy(45,15);cout<<"Pilihan: ";cin>>kode;

	if(kode==1)tambahbuku() ;
	else if(kode==2)cetakbuku_admin();
	else if (kode==3)keluar();
	else
    {
        cout<<"piliha adnda salah !!!!!"<<endl;
        cout<<"silahkan pilih ulang :";cin>>b; //ketik y untuk kembai ke menu admin dan t untuk keluar//
        if (b == 'y' || b == 'Y')
        admin();
        keluar();
    }
}

void guest()        //menu untuk guest//
{
    int kode;
    char c;
        system("cls");
    gotoxy(45,5);cout<<"=========================";
    gotoxy(45,6);cout<<"          MENU          ";
	gotoxy(45,7);cout<<"-------------------------";
	gotoxy(45,9);cout<<" 1.Cetak Daftar Buku    ";
	gotoxy(45,10);cout<<" 2.Keluar               ";
	gotoxy(45,12);cout<<"=========================";
	gotoxy(45,14);cout<<"Pilihan: ";cin>>kode;

	if(kode==1)cetakbuku_guest();
	else if(kode==2) keluar();
	else
    {
        cout<<"Salah input silahkan ulangi";
        gotoxy(45,17);cout << "Coba Lagi? [ Y / T ]"; cin >> c; //Ketil y unyuk mencoba lagi menginput dan ketik t untuk keluar//
        if (c == 'y' || c == 'Y')
        guest();
        keluar();
    }
}

void tambahbuku()  //Program untuk menambahkan buku//
{
    int a;
        system("cls");
    gotoxy(40,2);cout<<"------------------------------------";
    gotoxy(43,3);cout<<"INPUT BUKU YANG INGIN DITAMBAH";
    gotoxy(40,4);cout<<"------------------------------------";
    gotoxy(40,5);cout<<"Jumlah buku yang Ingin di tambah :";cin>>a;
    for (int i=1; i<=a; i++)
    {
                system("cls");
        kotak();
        gotoxy(45,3);cout<<"Data buku ke-"<<i<<endl;
        gotoxy(45,4);cout<<"ID Buku :";cin>>buku[i].id_buku;
        gotoxy(45,5);cout<<"Judul Buku :";cin>>buku[i].judul_buku; fflush(stdin);
        gotoxy(45,6);cout<<"Pengarang :";cin>>buku[i].pengarang;fflush(stdin);
        gotoxy(45,7);cout<<"Penerbit :";cin>>buku[i].penerbit;fflush(stdin);
        gotoxy(45,8);cout<<"Tahun :";cin>>buku[i].tahun;
        gotoxy(45,9);cout<<"Stock :";cin>>buku[i].stock;
        //simpan
        ofstream simpan_buku;
        simpan_buku.open("1.txt", ios :: app);
        simpan_buku << buku[i].id_buku << "\t    ";
        simpan_buku << buku[i].judul_buku << "\t";
        simpan_buku << buku[i].pengarang << "\t";
        simpan_buku << buku[i].penerbit << "\t";
        simpan_buku << buku[i].tahun << "\t";
        simpan_buku << buku[i].stock << "\n";
        simpan_buku.close();
    }
    admin();        //Setelah selesai menginput buku maka layar akan langsung di alihkan ke menu admin//
}

void cetakbuku_admin()      //Tampilan cetak buku untuk amdin//
{
        system("cls");
    kotak();
    char d;
    int x=4;
    const int MAX=80;
    char buffer[MAX+1];
    ifstream simpan_buku;
    simpan_buku.open("1.txt", ios :: app);
    gotoxy(45,3);cout << "DAFTAR BUKU YANG TERSEDIA\n";
    gotoxy(35,4);cout << "ID BUKU  JUDUL  PENGARANG  PENERBIT  TAHUN  STOK\n";
    gotoxy(35,5);cout << "------------------------------------------------\n";
    while(simpan_buku)
    {
        simpan_buku.getline(buffer,MAX);
        cout<<"\t\t\t\t   "<<buffer<<endl;
    }
    gotoxy(45,13);cout << "Kembali kemenu utama? [ Y / T ]"; cin >> d;      //Ketik y untuk kembali ke menu admin dan ketik t untuk keluar//
    if (d == 'y' || d == 'Y')
    admin();
    keluar();
}

void cetakbuku_guest()      //Tampilan cetak buku untuk guest//
{
        system("cls");
    kotak();
    char d;
    int x=4;
    const int MAX=80;
    char buffer[MAX+1];
    ifstream simpan_buku;
    simpan_buku.open("1.txt", ios :: app);
    gotoxy(45,3);cout << "DAFTAR BUKU YANG TERSEDIA\n";
    gotoxy(35,4);cout << "ID BUKU  JUDUL  PENGARANG  PENERBIT  TAHUN  STOK\n";
    gotoxy(35,5);cout << "------------------------------------------------\n";
    while(simpan_buku)
    {
        simpan_buku.getline(buffer,MAX);
        cout<<"\t\t\t\t    "<<buffer<<endl;
    }
    gotoxy(45,13);cout << "Kembali kemenu utama? [ Y / T ]"; cin >> d;      //Ketik y untuk kembali ke menu guest dan ketik t untuk keluar//
    if (d == 'y' || d == 'Y')
    guest();
    keluar();
}



void kotak()
{
    gotoxy(20,1);cout << "=========================================================================";
    gotoxy(20,2);cout << "=                                                                       =";
    gotoxy(20,3);cout << "=                                                                       =";
    gotoxy(20,4);cout << "=                                                                       =";
    gotoxy(20,5);cout << "=                                                                       =";
    gotoxy(20,6);cout << "=                                                                       =";
    gotoxy(20,7);cout << "=                                                                       =";
    gotoxy(20,8);cout << "=                                                                       =";
    gotoxy(20,9);cout << "=                                                                       =";
    gotoxy(20,10);cout << "=                                                                       =";
    gotoxy(20,11);cout << "=                                                                       =";
    gotoxy(20,12);cout << "=                                                                       =";
    gotoxy(20,13);cout << "=                                                                       =";
    gotoxy(20,14);cout << "=========================================================================";
}

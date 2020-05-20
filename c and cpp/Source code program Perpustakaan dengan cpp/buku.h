#pragma once
#include "ConsoleTable.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;
class buku :
	public ConsoleTable
{
	
	int SIZE;
	int i;
	int result;
	int index;
public:
	int recCount,foundbuku;
	std::ifstream myfile;
	ConsoleTable table{ "                 Judul Buku                 ","         Author         ","    Penerbit    ","   Kode Buku   ","   Jumlah Buku Tersedia  "," Jumlah Buku total " };
	struct perpustakaan {
		char namabuku[50], author[30], penerbit[30], kodebuku[30];
		int jumlahbukutersedia, jmlhbukutotal;
	}bukuperpus[250],tempS[250],tempSS;
	string str1, str2,str3,str4,str5,str6;
	int tPinjam[3], tBalik[3];
	void pencarian(string cari, int *found);
	void showlist(int code = 0);
	void edit_buku( char tkode[30],int com);
	void showbook(char kode[20]);
	int add_buku(char na[50], char aut[30],char pub[30],char kbu[30],int jmlh1,int jmlh2);
	int delete_buku(char tkode[30]);
};

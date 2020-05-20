#pragma once
#pragma warning(disable:4996)
#include "ConsoleTable.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <ctime>



using namespace std;
class Member:
	public ConsoleTable

{
	struct member {
		char username[8], password[10], nama[40], address[100],pinjaman[2][50],kodebuku[2][50];
		int noHP,waktuReturn[2],waktuPengambilan[2],bulanPinjam[2],bulanBalik[2],kali=0;
	}memberPerpus[100],tempM[100];
	string user1, pass2,username2,password2;
	int i, size, reccount,jumlahdata;
	ConsoleTable tableMember = { "Nama Member","Address","Nomor HP","Username" };
public:
	int found;
	struct member memberPUB;
	int login(char  user[12], char pas[20]);
	void getdata(int f);
	int add_user();
	int modify_member(char namany[40],int com);
	int delete_member(char use[12]);
	void Pinjaman_Member();
	void Pinjamin_buku(char minjamin[50],char pinjaman[50]);
	void perpanjang_buku(int y);
	void Pengembalian_buku(char kode[50],int xy);
	void show_member();
protected:
	
	
};


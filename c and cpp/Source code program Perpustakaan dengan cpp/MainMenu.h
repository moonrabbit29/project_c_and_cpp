#pragma once
#include <iostream>
#include <Windows.h>
#include "buku.h"
#include "Member.h"

using namespace std;
class MainMenu :
	public buku,public Member
{
	char ch, search[100]; int i;
public:
	void gotoxy(int x, int y);
	int main_menu();
	void tes();

protected:
	buku books;
	Member mem;
	string s_search;
	void Pinjam_Buku(char tkode[40]);
	void login_menu();
	void guest_menu();
	void book_list();
	void searchbox();
	void admin();
	void admin_showMember();
	void admin_deleteMember();
	void admin_addMember();
	void tambah_buku();
	void user();
};

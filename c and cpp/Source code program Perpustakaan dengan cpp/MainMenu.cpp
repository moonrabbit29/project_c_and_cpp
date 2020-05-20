#include "MainMenu.h"


void MainMenu::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int MainMenu::main_menu() {
	system("CLS");
	char choice;
	MainMenu::gotoxy(58, 0);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n";
	MainMenu::gotoxy(58, 2);
	cout << "\xDB\xDB\xDB\xDB\xB2 1. Guest  " << endl;;
	MainMenu::gotoxy(58, 4);
	cout << "\xDB\xDB\xDB\xDB\xB2 2. login Member   " << endl;
	MainMenu::gotoxy(58, 8);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	cout << endl;
	MainMenu::gotoxy(58, 10);
	cout << "Enter your choice : ";
	choice = _getch();
	if (choice == '1') {
		gotoxy(48, 0); MainMenu::guest_menu();
	}
	if (choice == '2') {
		system("CLS"); MainMenu::gotoxy(48, 4);MainMenu::login_menu();
	}
	if (choice == 27) return 0;


	return -1;
}
void MainMenu::guest_menu() {
	MENU:
	books.showlist(0);
	system("CLS");
	gotoxy(58, 0);
	cout << "1. Search Book" << endl;
	gotoxy(58, 1);
	cout << "2. Tampilkan Buku" << endl;
	gotoxy(58, 2);
	cout << "Pilihan anda";
	gotoxy(58, 3);
		ch = _getch();
		if (ch == '1') {
			system("CLS");
			MainMenu::searchbox();

			MainMenu::gotoxy(0, 20);
			int dummy=0;
			books.pencarian(s_search,&dummy);	
			getchar();
			goto MENU;
			
		}
		else if (ch == '2') {
			books.showlist(1);
			getchar();
			goto MENU;
		}
		else if (ch == 27) {
			system("CLS");
			MainMenu::main_menu();
			
		}
}

void MainMenu::login_menu()
{
	
	char userlog[12], passlog[20];
	int y;
yo:
	MainMenu::gotoxy(58, 4);
	cout << "masukan username : ";
	cin.getline(userlog,12);
	gotoxy(58, 5);
	cout << "masukan password : ";
	i = 0;
	while (true) {
		ch = _getch();
		if (ch == 13)
			break;
		else if (ch == 8) {
			_putch('\b');
			_putch(NULL);
			_putch('\b');
			--i;
			continue;
		}
		else if (ch == 27) {
			MainMenu::main_menu();
			break;
		}
		else {
			passlog[i] = ch;
			ch = '*';
			cout << ch;
			i++;

		}
	}
passlog[i] = '\0';
	y = mem.login(userlog, passlog);
	switch (y) {
	case 2: MainMenu::admin();break;
	case 1: MainMenu::user(); break;
	case 3: system("CLS"); goto yo; break;
	default:system("CLS");goto yo; break;
	}
}


void MainMenu::searchbox()
{
	system("CLS");
	for (int i = 0;i < 15;i++) {
		MainMenu::gotoxy(52, 0 + i);
		cout << "*";
		for (int y = 0;y < 30;y++) {
			if (i == 0 || i == 14) {
				cout << " ";
				cout << "*";
				if (y == 29)
					cout << "*";
			}
			else if (i == 4 && y == 4) {
				cout << "\t\t" << "Search book : ";
				cout << "\t\t\t" << "         " << "*";
				break;

			}
			else if (i == 5 && y == 0) {
				cout << "||";
				cout << "\t\t\t\t\t\t\t" << "       ||" << "*";
				break;
			}

			else if (y == 29) {
				cout << "  ";
				cout << "*";

			}
			else {

				cout << "  ";
			}

		}
		cout << endl;
	}
	MainMenu::gotoxy(55, 5 );
	getline(cin, s_search);
	

}


void MainMenu::admin() {
AMENU:
	system("CLS");
	char choice,choiceM;
	cout << "MENU ADMIN : " << endl;
	cout << "1.ADMINISTRASI" << endl;
	cout << "2.Peminjaman Buku" << endl;
	cout << "3.Pengembalian buku";
	choiceM = _getch();
	if (choiceM=='1'){
		system("CLS");
		cout << " Pilihan : " << endl;
	cout << "1. modify Book" << endl;
	cout << "2.add book" << endl;
	cout << "3.delete book" << endl;
	cout << "4.Add new user" << endl;
	cout << "5.Modify user" << endl;
	cout << "6.Delete user" << endl;
	cout << "7.Show User" << endl;
	cout << "your choice: ";
	choice = _getch();
	if (choice == 27) {

		goto AMENU;

	}
	else if (choice == '7') {
		system("CLS");
		mem.show_member();
		system("PAUSE");
		goto AMENU;
	}
	else if (choice == '1') {
	PIL:
		char bukuedit[20];
		system("CLS");
		cout << "Masukan Kode  buku yang ingin di Edit atau <enter> untuk melihat list buku: ";
		cin.getline(bukuedit, 20);
		if (strlen(bukuedit) == 0) {
			books.showlist(1);
			getchar();
			system("CLS");
			goto PIL;
		}
		else {
			books.edit_buku(bukuedit,0);
			cout << "ada hal lain yang bisa dibantu?";
			getchar();
			system("CLS");
			goto AMENU;
		}
	}
	else if (choice == '2') {
		MainMenu::tambah_buku();
		MainMenu::admin();
	}

	else if (choice == '3') {
		char kodedel[30];
	mil:
		system("CLS");
		cout << "Masukan kode buku yang ingin dihapus atau <Enter> untuk melihat daftar buku: ";
		cin.getline(kodedel, 30);
		if (strlen(kodedel) == 0) {
			books.showlist(1);
			getchar();
			system("CLS");
			goto mil;
		}
		else {
			if (books.delete_buku(kodedel) == 0) {
				cout << "record buku berhasil di hapus" << endl;
				getchar();
				MainMenu::admin();
			}
			else {
				cout << "gagal";
				exit(-1);
			}

		}
	}
	else if (choice == '4') {
		system("CLS");
		switch (mem.add_user()) {
		case 0: MainMenu::admin();
		}
	}
	else if (choice == '5') {
		char namamem[40];
		system("CLS");
		cout << "Masukan username member yang ingin diubah datanya : ";
		i = 0;
		while (1) {
			ch = _getch();
			if (ch == 13) break;
			else if (ch == 27) goto AMENU;
			else if (ch == 8) {
				_putch('\b');
				_putch(NULL);
				_putch('\b');
				--i;
				continue;
			}
			else {
				namamem[i] = ch;
				cout << ch;
				i++;
			}
		}
		namamem[i] = '\0';

		if (mem.modify_member(namamem,0) == -1) {
			system("PAUSE");
			MainMenu::admin();
		}
		else {
			cout << endl << "data sukses diubah" << endl;
			getchar();
			MainMenu::admin();
		}

	}
	else  if (choice == '6') {
		char username[12];
		system("CLS");
		cout << "Masukan username yang ingin dihapus";
		cin.getline(username, 12);
		if (mem.delete_member(username) == 0) {
			cout << "\n kembali ke menu admin..";
			system("PAUSE");
			system("CLS");
			goto AMENU;
		}
		else {
			cout << "\n gagal menghapus file" << endl;
			getchar();
			goto AMENU;
		}
	}
}
else if (choiceM == '2') {
system("CLS");
char kodecari[40];
gotoxy(48, 0);
cout << "Silahkan masukan kode buku : ";
i = 0;
while (1) {
	ch = _getch();
	if (ch == 27) {
		system("CLS");
		MainMenu::admin();
	}
	else if (ch == 8) {
		_putch('\b');
		_putch(NULL);
		_putch('\b');
		--i;
		continue;
	}
	else if (ch == 13) break;
	else {
			kodecari[i] = ch;
			cout << ch;
			i++;
	}
}
kodecari[i] = '\0';
MainMenu::Pinjam_Buku(kodecari);

}
else if (choiceM == '3') {
yoooo:
system("CLS");
char userMasuk[14],passMasuk[14];
MainMenu::gotoxy(48, 0);
cout << " Masukan username dan password" << endl;;
MainMenu::gotoxy(48, 1);
cout << "Username : ";
i = 0;
while (1) {
	ch = _getch();
	if (ch == 13)break;
	else if (ch == 27) {
		system("CLS");
		MainMenu::admin();
	}
	else if (ch == 8) {
		_putch('\b');
		_putch(NULL);
		_putch('\b');
		--i;
		continue;
	}
	else {
		userMasuk[i] = ch;
		i++;
		cout << ch;
	}
}
userMasuk[i] = '\0';
if (strlen(userMasuk) != 0);
MainMenu::gotoxy(48, 2);
cout << "masukan password : ";
i = 0;
while (true) {
	ch = _getch();
	if (ch == 13)
		break;
	else if (ch == 8) {
		_putch('\b');
		_putch(NULL);
		_putch('\b');
		--i;
		continue;
	}
	else {
		passMasuk[i] = ch;
		ch = '*';
		cout << ch;
		i++;

	}
} passMasuk[i] = '\0';
if (mem.login(userMasuk, passMasuk) == 1) {
	if (mem.memberPUB.waktuReturn[0] != 0) {
	int s = 0;string cari; int tes;
	cout << endl << endl;
	mem.Pinjaman_Member();
	cout << endl << "Masukan  buku yang ingin dikembalikan <masukan baris buku> : ";
	cin >> tes;
	cari = mem.memberPUB.kodebuku[tes - 1];
	books.pencarian(cari, &s);
	cout << endl;
	cout << "y/n";
	ch = _getch();
	if (ch == 'y') {
		books.edit_buku(mem.memberPUB.kodebuku[tes - 1], 2);
		mem.Pengembalian_buku(mem.memberPUB.kodebuku[tes - 1], s);
	}
	system("CLS");
	cout << "sukses";
	}
	else {
		cout << endl << "Tidak terdapat daftar buku pinjaman untuk pengguna tersebut" << endl;
			getchar();
	}
	system("CLS");
	MainMenu::admin();
}
else {
	cout << "Password atau username Salah" << endl;
		goto yoooo;
}


}
else if (choiceM == 27) {
MainMenu::main_menu();
return;
}
}

void MainMenu::Pinjam_Buku(char tkode[40]) {
	char nama[40], sandi[13];
NANI:

	MainMenu::gotoxy(48, 1);
	cout << "Silahkan Masukan username dan password " << endl;
	MainMenu::gotoxy(48, 2);
	cout << "Username Member : ";
	cin.getline(nama, 12);
	if(strlen(nama)!=0)
	MainMenu::gotoxy(48, 3);
	cout << "Password Member : ";
	i = 0;
	while (true) {
		ch = _getch();
		if (ch == 13)
			break;
		else if (ch == 8) {
			_putch('\b');
			_putch(NULL);
			_putch('\b');
			--i;
			continue;
		}
		else {
			sandi[i] = ch;
			ch = '*';
			cout << ch;
			i++;

		}
	} sandi[i] = '\0';
	cout << endl;
	if (mem.login(nama, sandi) == 1) {
		books.edit_buku(tkode, 1);
		cout << endl;
		cout << books.bukuperpus[books.foundbuku].namabuku<<endl;
		system("PAUSE");
		mem.Pinjamin_buku(books.bukuperpus[books.foundbuku].namabuku,books.bukuperpus[books.foundbuku].kodebuku);
		cout << endl;
		cout << "sukses";
		system("PAUSE");
		MainMenu::admin();
	}
	else {
		cout << endl;
		cout << "Gagal silahkan coba lagi";
		getchar();
		system("CLS");
		goto NANI;
	}
	

}



void MainMenu::tambah_buku()
{
	system("CLS");
	char na[50], au[30], pub[30], kbu[30];
	int j1, j2,op;
	cout << "Masukan Nama Buku :  ";
	cin.getline(na,50);
	cout << "Masukan Auhor/penulis : ";
	cin.getline(au, 30);
	cout << "Masukan nama publisher:";
	cin.getline(pub, 30);
	cout << "Masukan kode buku baru : ";
	cin.getline(kbu, 30);
	cout << "Masukan Jumlah buku : ";
	cin >> j1; cin.ignore(); j2 = j1;
	op= books.add_buku(na, au, pub, kbu, j1, j2);
	if (op == -1) {
		cout << "gagal" << endl;
		getchar();
		system("CLS");
		MainMenu::admin();

	}
	else {
		cout << "suskses menambahkan buku" << endl;
		getchar();
		system("CLS");
		MainMenu::admin();


	}




}

void MainMenu::user()
{
	pilih:
	system("CLS");
	char choice;
	MainMenu::gotoxy(48, 0);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n";
	MainMenu::gotoxy(48, 2);
	cout << "\xDB\xDB\xDB\xDB\xB2 Halo "<<memberPUB.nama<<endl;
	MainMenu::gotoxy(48, 4);
	cout << "\xDB\xDB\xDB\xDB\xB2 Menu :  " << endl;
	MainMenu::gotoxy(48, 6);
	cout << "\xDB\xDB\xDB\xDB\xB2 1. Perpanjangan buku" << endl;
	MainMenu::gotoxy(48, 8);
	cout << "\xDB\xDB\xDB\xDB\xB2 2. cek daftar buku pinjaman" << endl;
	MainMenu::gotoxy(48, 11);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	cout << endl;
	MainMenu::gotoxy(48, 12);
	cout << endl;
	cout << "Enter your choice : ";
	choice = _getch();
	cout << choice;
	if (choice == '1') {
		cout << "daftar buku "<<endl;
		mem.perpanjang_buku(2);
		cout << "buku diperpanjang "<<endl;
		system("PAUSE");
		goto pilih;
		
	}
	else if (choice == '2') {
		system("CLS");
		mem.Pinjaman_Member();
		goto pilih;
	}
	else if (choice == 27) {
		system("CLS");
		MainMenu::main_menu();
	}
}

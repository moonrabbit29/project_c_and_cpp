#include "Member.h"

int Member::login(char user[12], char pas[20])
{
	ifstream infile;
	infile.seekg(0, ios::beg);
	size = 100;
	reccount = 0;
	user1 = user;
	pass2 = pas;
	infile.open("datamember.dat", ios::in);
	while (true && reccount < size) {
		infile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (infile.eof())break;
		reccount++;
	}
	jumlahdata = reccount;
	infile.close();
	infile.open("dataadmin.txt", ios::in);
	i = 0;
	while (true ) {
		infile >> username2 >> password2;
		if (infile.eof())break;
		i++;
	}
	infile.close();
	for (i = 0;i <reccount;i++) {
		if (strcmp(memberPerpus[i].username,user)==0) {
			if (strcmp(pas,memberPerpus[i].password)==0) {
				found = i;
				Member::getdata(found);
				return 1;
			}
			else {
				cout << "Password SALAH";
				system("PAUSE");
				return 3;
			}
		}	
	}
	 if (user1 == username2 && pass2 == password2) {
	return 2;
		}
	return -1;
}
void Member::getdata(int f)
{
	i = 0;
	/*while (i < jumlahdata) {
		strcpy_s(memberPerpus)
		address[i] = address1[i];
		nomor[i] = nomor1[i];
		i++;
	}
	i = 0;
	while (i < jumlahdata) {
		if (nama[i] == namadoang) {
			return i;
		}
		else continue;
		}
	return -1;*/
	ifstream restfile("datamember.dat", ios::in);
	restfile.seekg(0, ios::beg);
	reccount = 0;
	while (true)
	{
		restfile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile.eof()) break;
		reccount += 1;
	}
	memberPUB = memberPerpus[f];
	restfile.close();
}

int Member::add_user()
{
	char ch,tusername[13], tpassword[13],ttpassword[13], tnama[40], taddress[100], tpinjaman[2][50];
	int tnoHP;
	ifstream restfile("datamember.dat", ios::in);
	restfile.seekg(0, ios::beg);
	reccount = 0;
	while (true)
	{
		restfile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile.eof()) break;
		reccount += 1;
	}
	nama:
	cout << "Masukan nama : ";
	i = 0;
	while (1) {
		ch = _getch();
		if (ch == 13) break;
		else if (ch == 27) {
			return -1;
		}
		else if (ch == 8) {
			_putch('\b');
			_putch(NULL);
			_putch('\b');
			--i;
			continue;
		}
		else {
			tnama[i] = ch;
			cout << ch;
			i++;
		}

	}
	tnama[i] = '\0';
	cout << endl;
	if (strlen(tnama) > 40) {
		cout << "nama pengguna tidak bisa lebih dari 40 huuruf" << endl;
		goto nama;
	}
	cout << "Masukan alamat : ";
	i = 0;
	while (1) {
		ch = _getch();
		if (ch == 13) break;
		else if (ch == 27) {
			return -1;
		}
		else if (ch == 8) {
			_putch('\b');
			_putch(NULL);
			_putch('\b');
			--i;
			continue;
		}
		else {
			taddress[i] = ch;
			cout << ch;
			i++;
		}

	}
	taddress[i] = '\0';
	cout << endl;
	cout << "Masukan nomor hp: ";
	cin >> tnoHP;
	cin.ignore();
	namaPeng:
	cout << "Masukan nama pengguna <maksimum 12 karakter> : ";
	i = 0;
	while (1) {
		ch = _getch();
		if (ch == 13) break;
		else if (ch == 27) {
			return -1;
		}
		else if (ch == 8) {
			_putch('\b');
			_putch(NULL);
			_putch('\b');
			--i;
			continue;
		}
		else {
			tusername[i] = ch;
			cout << ch;
			i++;
			continue;
		}

	}
	tusername[i] = '\0';
	cout << endl;

	if (strlen(tusername) > 8) {
		cout << "Nama pengguna melebihi 8 karakter " << endl;
		goto namaPeng;
	}
	passwordddd:
	cout << "Masukan Password : ";
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
			return -1;
		}
		else {
			tpassword[i] = ch;
			ch = '*';
			cout << ch;
			i++;

		}
	}

tpassword[i] = '\0';
cout << endl;
	i = 0;
cout << "\nMasukan Kembali pasword anda : ";
while (1) {
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
		return -1;
	}
	else {
		ttpassword[i] = ch;
		ch = '*';
		cout<< ch;
		i++;
	}
}
ttpassword[i] = '\0';
cout << endl;
if (strcmp(ttpassword, tpassword) != 0) {
	cout << "Passsword tidak sesuai" << endl;
	system("CLS");
		goto passwordddd;
}
else { cout << "Password Telah Sesuai" << endl; }
if (strlen(tpassword ) > 10) {
	cout << "Password melebihi 10 karakter";
	goto passwordddd;
	}
	for (i = 0;i < reccount;i++) {
		if (strcmp(tnama, memberPerpus[i].nama) == 0 || strcmp(tusername, memberPerpus[i].username) == 0) {
			cout << "Pengguna terserbut telah terdaftar sebagai member" << endl; getchar(); system("CLS"); return -1; break;
		}
		else if (tnoHP == memberPerpus[i].noHP) {
			cout << "Nomor hp terserbut telah terdaftar <coba masukan nomor hp yang lainnya" << endl;
			system("PAUSE");
			system("CLS");
			goto nama;
			
		}
	}
	cin.ignore();
	fstream tempo("datamember.dat", ios::out);
	remove("datamember.dat");
	for (i = 0;i <= reccount;i++) {
		if (i < reccount) {
			for (int y = 0;y < 2;y++) {
				strcpy_s(tempM[i].username, memberPerpus[i].username);
				strcpy_s(tempM[i].password, memberPerpus[i].password);
				strcpy_s(tempM[i].nama, memberPerpus[i].nama);
				strcpy_s(tempM[i].pinjaman[y], memberPerpus[i].pinjaman[y]);
				strcpy_s(tempM[i].address, memberPerpus[i].address);
				tempM[i].noHP = memberPerpus[i].noHP;
				tempM[i].waktuPengambilan[y] = memberPerpus[i].waktuPengambilan[y];
				tempM[i].waktuReturn[y] = memberPerpus[i].waktuReturn[y];
				tempM[i].bulanBalik[y] = memberPerpus[i].bulanBalik[y];
				tempM[i].bulanPinjam[y] = memberPerpus[i].bulanPinjam[y];
				tempM[i].kali = memberPerpus[i].kali;
				strcpy_s(tempM[i].kodebuku[y],memberPerpus[i].kodebuku[y]);
			}
		}
		else if (i == reccount) {
			for (int y = 0;y < 2;y++) {
				strcpy_s(tempM[i].username,tusername);
				strcpy_s(tempM[i].password, tpassword);
				strcpy_s(tempM[i].nama, tnama);
				strcpy_s(tempM[i].pinjaman[y],"");
				strcpy_s(tempM[i].address, taddress);
				strcpy_s(tempM[i].kodebuku[y], "");
				tempM[i].noHP = tnoHP;
				tempM[i].waktuPengambilan[y] = 0;
				tempM[i].waktuReturn[y] = 0;
				tempM[i].bulanBalik[y] = 0;
				tempM[i].bulanPinjam[y] = 0;
				memberPerpus[i].kali = 0;


			}
		}
		tempo.write((char*)&tempM[i], sizeof(tempM));
	}
	tempo.close();
	cout << "sukses ditambahkan";
	system("PAUSE");



	return 0;
}

int Member::modify_member(char namany[40],int com) {
	ifstream restfile("datamember.dat", ios::in);
	restfile.seekg(0, ios::beg);
	int foundM;
	reccount = 0;
	while (true && reccount < 100)

	{
		restfile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile.eof()) break;
		reccount++;

	}
	restfile.close();
	
		for (i = 0;i <= reccount; i++) {
			if (strcmp(namany, memberPerpus[i].username) == 0) {
				foundM = i;
				cout << endl;
				cout << "Member ditemukan pada indeks ke- " << foundM << endl; system("PAUSE"); break;
			}
			else if (i == reccount) {
				cout << endl;
				cout << "Tidak Terdapat member dengan nomor tersebut" << endl;
				return -1;
			}
		}
		cout << endl;

		system("CLS");
		string str1, str2, str3, str4; char choice, ch;
		int hapus;
		for (i = 0;i < tableMember.rows.size();i++) {
			hapus = 0;
			tableMember -= hapus;
		}
		char n[40], a[40], us[12], pass[12], passK[12]; int no;
		str1 = memberPerpus[foundM].nama;
		str2 = memberPerpus[foundM].address;
		str3 = to_string(memberPerpus[foundM].noHP);
		str4 = memberPerpus[foundM].username;
		tableMember += {str1, str2, str3, str4};
		cout << "Apakah anda ingin mengedit data berikut : " << endl;
		cout << endl;
		cout << tableMember;
		for (i = 0;i < tableMember.rows.size();i++) {
			hapus = 0;
			tableMember -= hapus;
		}
		cin >> choice;
		cin.ignore();
		if (choice == 'y' || choice == 'Y') {
			cout << "Masukan nama member yang baru <enter> apabila tidak ada perubahan : ";
			cin.getline(n, 40);
			if (strlen(n) > 0) {
				strcpy_s(memberPerpus[foundM].nama, n);
			}
			cout << "Masukan alamat baru <enter> apabila tidak ada perubahan: ";
			cin.getline(a, 40);
			if (strlen(a) > 0) strcpy_s(memberPerpus[foundM].address, a);
			cout << "Masukan NO HP baru : ";
			cin >> no; memberPerpus[foundM].noHP = no;
			cin.ignore();
		inputA:
			cout << "Masukan Username Baru, maksimal 8 karakter <enter> apabila tidak ada perubahan: ";
			cin.getline(us, 12);
			if (strlen(us) > 8) {
				cout << "username melebihi 8 karakter";
				getchar();
				system("CLS");
				goto inputA;
			}
		inputB:
			cout << "Masukan Password baru : ";
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
					return -1;
				}
				else {
					pass[i] = ch;
					ch = '*';
					cout << ch;
					i++;
					if (i == 12) {
						cout << endl;
						cout << "Password melebihi batas karakter";
						getchar();
						system("CLS");
						cout << "Masukan Password kembali" << endl;
						goto inputB;

					}
				}
			}
			cout << endl;
			if (strlen(pass) > 0) {
				cout << "Masukan kembali password: ";
				pass[i] = '\0';
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
						return -1;
					}
					else {
						passK[i] = ch;
						ch = '*';
						cout << ch;
						i++;
						if (i == 12) {
							cout << endl;
							cout << "Password melebihi batas karakter";
							getchar();
							system("CLS");
							cout << "Masukan Password kembali" << endl;
							goto inputB;

						}
					}
				}

			}

			passK[i] = '\0';
			if ((strcmp(pass, passK) == 0) && (strlen(pass) > 0)) {
				strcpy_s(memberPerpus[foundM].password, pass);
			}
			fstream tempo("datamember.dat", ios::out);
			remove("datamember.dat");
			for (i = 0;i < reccount;i++) {
				tempo.write((char*)&memberPerpus[i], sizeof(memberPerpus));
			}

			tempo.close();


		}



	return 0;
}

int Member::delete_member(char use[12])
{
	string str1, str2, str3, str4; char choice, ch;
	int f;
	
	ifstream restfile("datamember.dat", ios::in);
	restfile.seekg(0, ios::beg);
	reccount = 0;
	while (true)
	{
		restfile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile.eof()) break;
		reccount += 1;
	}
	restfile.close();
	for (i = 0;i <=reccount;i++) {
		if (strcmp(memberPerpus[i].username, use) == 0) {
			f = i; break;
		}
		else if (i == reccount) {
			cout << "tidak terdapat member dengan kode tersebut" << endl;
			getchar();
			return -1;
		}
	}
	Member::getdata(f);
	cout << "Apakah anda yakin untuk menghapus member berikut (y/n)" << endl;
	str1 = memberPerpus[f].nama;
	str2 = memberPerpus[f].address;
	str3 = to_string(memberPerpus[f].noHP);
	str4 = memberPerpus[f].username;
	tableMember += {str1, str2, str3, str4};
	cout << tableMember;
	int hapus;
	for (i = 0;i < tableMember.rows.size();i++) {
		hapus = 0;
		tableMember -= hapus;
	}
	ch = _getch();
	if (ch == 'y' || ch == 'Y') {
		remove("datamember.dat");
		fstream tempo("datamember.dat", ios::out);
		for (i = 0;i < reccount;i++) {
			if (i == f) continue;
			tempo.write((char*)&memberPerpus[i], sizeof(memberPerpus));
		}
		tempo.close();
	}
	else if (ch == 'N' || ch == 'n') {
		return -1;
	}
	
	return 0;
}

void Member::Pinjaman_Member()
{
	ConsoleTable tablePinjaman = { " Judul Buku ", " Jumlah Pinjaman ","Tanggal Peminjaman","Bulan Peminjaman", " Tanggal  Pengembalian ","Bulan pengembalian"," Denda " };
	string denda[2]; int denda1[2],ra1,ra2; string jumlah = "satu",str1,str2,str3,str4,str5;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	for (i = 0;i < 2;i++) {
		if (memberPUB.waktuReturn[i] == 0) continue;
			ra1 = ((ltm->tm_mon) - memberPUB.bulanPinjam[i]) * 30;
			ra2 = ((ltm->tm_mday) - memberPUB.waktuReturn[i]);
			if (ra2 > 0) {
				denda1[i] = 500 * (ra1 + ra2);
			}
			else denda1[i] = 0;
	}
	
	for (i = 0;i <2;i++) {
		if (memberPUB.waktuReturn[i] != 0) {
			str1 = to_string(memberPUB.waktuPengambilan[i]);
			str2 = to_string(memberPUB.waktuReturn[i]);
			str3 = to_string(denda1[i]);
			str4 = to_string(memberPUB.bulanPinjam[i]);
			str5 = to_string(memberPUB.bulanBalik[i]);
			tablePinjaman += {memberPUB.pinjaman[i], jumlah, str1, str4, str2, str5, str3 };
		}
	}
	cout << tablePinjaman;
	int hapus = 0;
	if (tableMember.rows.size() >= 2) {
		for (i = 0;i < tableMember.rows.size();i++) {
			tableMember -= hapus;
		}
	}

	system("PAUSE");
}

void Member::Pinjamin_buku(char minjamin[50],char pinjaman[50])
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	if (memberPerpus[found].waktuPengambilan[0] == 0) {
		memberPerpus[found].waktuPengambilan[0] = ltm->tm_mday;
		if ((ltm->tm_mon) == 2 || (ltm->tm_mon) == 4 || (ltm->tm_mon) == 6 || (ltm->tm_mon) == 9 || (ltm->tm_mon) == 11) {
			if ((ltm->tm_mday + 7) > 30) {
				memberPerpus[found].waktuReturn[0] = ltm->tm_mday + 7-30;
				memberPerpus[found].bulanPinjam[0] = ltm->tm_mon+2;
				memberPerpus[found].bulanBalik[0] = ltm->tm_mon + 2;
			}
			else {
				memberPerpus[found].waktuReturn[0] = ltm->tm_mday + 7;
				memberPerpus[found].bulanPinjam[0] = ltm->tm_mon+1 ;
				memberPerpus[found].bulanBalik[0] = ltm->tm_mon + 1;
			}
		}
		else {
			if ((ltm->tm_mday + 7) > 31) {
				memberPerpus[found].waktuReturn[0] = ltm->tm_mday + 7 - 31;
				memberPerpus[found].bulanPinjam[0] = ltm->tm_mon + 2;
				memberPerpus[found].bulanBalik[0] = ltm->tm_mon + 2;
			}
			else {
				memberPerpus[found].waktuReturn[0] = ltm->tm_mday + 7;
				memberPerpus[found].bulanPinjam[0] = ltm->tm_mon+1;
				memberPerpus[found].bulanBalik[0] = ltm->tm_mon + 1;
			}
		}
		strcpy_s(memberPerpus[found].pinjaman[0], minjamin);
		strcpy_s(memberPerpus[found].kodebuku[0], pinjaman);
	}
	else if (memberPUB.waktuReturn[1] == 0) {
		memberPerpus[found].waktuPengambilan[1] = ltm->tm_mday;
		if ((ltm->tm_mon) == 2 || (ltm->tm_mon) == 4 || (ltm->tm_mon) == 6 || (ltm->tm_mon) == 9 || (ltm->tm_mon) == 11) {
			if ((ltm->tm_mday + 7) > 30) {
				memberPerpus[found].waktuReturn[1] = ltm->tm_mday + 7 - 30;
				memberPerpus[found].bulanPinjam[1] = ltm->tm_mon + 2;
				memberPerpus[found].bulanBalik[1] = ltm->tm_mon + 2;
			}
			else {
				memberPerpus[found].waktuReturn[1] = ltm->tm_mday + 7;
				memberPerpus[found].bulanPinjam[1] = ltm->tm_mon+1;
				memberPerpus[found].bulanBalik[1] = ltm->tm_mon + 1;
			}
		}
		else {
			if ((ltm->tm_mday + 7) > 31) {
				memberPerpus[found].waktuReturn[1] = ltm->tm_mday + 7 - 31;
				memberPerpus[found].bulanPinjam[1] = ltm->tm_mon + 1;
			}
			else {
				memberPerpus[found].waktuReturn[1] = ltm->tm_mday + 7;
				memberPerpus[found].bulanPinjam[1] = ltm->tm_mon;
			}
		}
		strcpy_s(memberPerpus[found].pinjaman[1], minjamin);
		strcpy_s(memberPerpus[found].kodebuku[1], pinjaman);
	}
	else {
		cout << "anda tidak bisa meminjam lagi" << endl;
		return;
	}
	remove("datamember.dat");
	fstream tempo("datamember.dat", ios::out);
	for (i = 0;i < reccount;i++) {
		tempo.write((char*)&memberPerpus[i], sizeof(memberPerpus));
	}
	tempo.close();
}

void Member::perpanjang_buku(int yFwhi)
{
	ifstream restfile1("datamember.dat", ios::in);
	restfile1.seekg(0, ios::beg);
	reccount = 0;
	while (true)
	{
		restfile1.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile1.eof()) break;
		reccount += 1;
	}
	restfile1.close();
	fstream tempo("datamember.dat", ios::out);
	remove("datamember.dat");
	if (memberPerpus[found].kali == 0) {
		for (i = 0;i < reccount;i++) {
			for (int y = 0;y < 2;y++) {
				if (memberPerpus[found].waktuReturn[i] != 0) {
					memberPerpus[found].waktuReturn[i] += 7;
					memberPerpus[found].kali += 1;
				}
				else break;
			}
			tempo.write((char*)&memberPerpus[i], sizeof(memberPerpus));
		}
		
	
	}
	else {
		cout << "tidak dapat melakukan perpanjangan lagi<<endl";
		system("PAUSE");
	}
}

void Member::Pengembalian_buku(char kode[50],int xy) {
	ifstream restfile1("datamember.dat", ios::in);
	restfile1.seekg(0, ios::beg);
	reccount = 0;
	while (true)
	{
		restfile1.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (restfile1.eof()) break;
		reccount += 1;
	}
	restfile1.close();
	remove("datamember.dat");
	fstream restfile("datamember.dat", ios::out);
	reccount = 0;
	for (i = 0;i <=reccount;i++) {
		for (int  y = 0;y < 2;y++) {
			if (strcmp(memberPerpus[i].kodebuku[y], kode) == 0) {
				strcpy_s(memberPerpus[i].kodebuku[y], memberPerpus[i].kodebuku[y+1]);
				strcpy_s(memberPerpus[i].pinjaman[y], memberPerpus[i].pinjaman[y+1]);
				memberPerpus[i].bulanBalik[y] = memberPerpus[i].bulanBalik[y+1];
				memberPerpus[i].bulanPinjam[y] = memberPerpus[i].bulanPinjam[y+1];
				memberPerpus[i].waktuPengambilan[y] = memberPerpus[i].waktuPengambilan[y+1];
				memberPerpus[i].waktuReturn[y] = memberPerpus[i].waktuReturn[y+1];
				memberPerpus[i].kali=0;
				strcpy_s(memberPerpus[i].kodebuku[y+1], "");
				strcpy_s(memberPerpus[i].pinjaman[y+1], "");
				memberPerpus[i].bulanBalik[y+1] = 0;
				memberPerpus[i].bulanPinjam[y+1] = 0;
				memberPerpus[i].waktuPengambilan[y+1] = 0;
				memberPerpus[i].waktuReturn[y+1] = 0;
				memberPerpus[i].kali = 0;
			}
		}
		restfile.write((char*)&memberPerpus[i], sizeof(memberPerpus));

	}
	restfile.close();

}

void Member::show_member()
{
	ifstream infile;
	string str1, str2, str3, str4;
	infile.seekg(0, ios::beg);
	size = 100;
	reccount = 0;
	infile.open("datamember.dat", ios::in);
	while (true && reccount < size) {
		infile.read((char*)&memberPerpus[reccount], sizeof(memberPerpus));
		if (infile.eof())break;
		reccount++;
	}
	jumlahdata = reccount;
	infile.close();
	for (i = 0;i < reccount;i++) {
		str1 = memberPerpus[i].nama;
		str2 = memberPerpus[i].address;
		str3 = to_string(memberPerpus[i].noHP);
		str4 = memberPerpus[i].username;
		tableMember += {str1, str2, str3, str4};
	}
	cout << tableMember;
	int hapus;
	for (i = 0;i < tableMember.rows.size();i++) {
		hapus = 0;
		tableMember -= hapus;
	}
	
	
}


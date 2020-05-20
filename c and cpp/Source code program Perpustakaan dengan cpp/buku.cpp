#include "buku.h"

void buku::showlist(int code) {
	ifstream restfile("databuku.dat", ios::in);
	restfile.seekg(0, ios::beg);
	recCount = 0;
	SIZE = 250;
		while (true)
		{
			restfile.read((char*)&bukuperpus[recCount], sizeof(bukuperpus));
			if (restfile.eof()) break;
			recCount+=1;
			
		
		}
	
	restfile.close();


	if (code == 1) {
		system("CLS");
		for (i = 0;i <recCount;i++) {
			str1 = to_string(bukuperpus[i].jumlahbukutersedia);
			str2 = to_string(bukuperpus[i].jmlhbukutotal);
			str3 = bukuperpus[i].namabuku;
			str4 = bukuperpus[i].author;
			str5 = bukuperpus[i].penerbit;
			str6 = bukuperpus[i].kodebuku;
			table += {str3, str4, str5, str6, str1, str2};
		
		}
		cout << recCount<<endl;
		cout << table;
		int hapus;
		for (i = 0;i <recCount;i++) {
			hapus = 0;
			table -= hapus;
		}
	}
		

	

}

void buku::pencarian(string cari, int *found) {
	 int hapus=0;
	 const uint32_t yes = 0;
	 ifstream restfile("databuku.dat", ios::in);
	 restfile.seekg(0, ios::beg);
	 recCount = 0;
	 SIZE = 250;
	 while (true)
	 {
		 restfile.read((char*)&bukuperpus[recCount], sizeof(bukuperpus));
		 if (restfile.eof()) break;
		 recCount += 1;


	 }
	 restfile.close();
	if (*found>=0) {
		str5 = bukuperpus[*found].kodebuku;
		str3 = bukuperpus[*found].namabuku;
		if (cari == str5) {
		str1 = to_string(bukuperpus[*found].jumlahbukutersedia);
		str2 = to_string(bukuperpus[*found].jmlhbukutotal);
		str3 = bukuperpus[*found].namabuku;
		str4 = bukuperpus[*found].author;
		str5 = bukuperpus[*found].kodebuku;
		str6 = bukuperpus[*found].penerbit;
		
			table += {str3, str4, str6, str5, str1, str2};
			cout << table;
			if (table.rows.size() >= yes) {
				for (i = 0;i < table.rows.size();i++) {
					table -= hapus;
				}
			}
			return;
		}
		else if (str3 == cari) {
			str1 = to_string(bukuperpus[*found].jumlahbukutersedia);
			str2 = to_string(bukuperpus[*found].jmlhbukutotal);
			str3 = bukuperpus[*found].namabuku;
			str4 = bukuperpus[*found].author;
			str5 = bukuperpus[*found].kodebuku;
			str6 = bukuperpus[*found].penerbit;
			table += {str3, str4, str6, str5, str1, str2};
		
			cout << table;
			if (table.rows.size() >= yes) {
				for (i = 0;i < table.rows.size();i++) {
					table -= hapus;
				}
			}
			return;
		}
			
	}
	if(*found==0) {
		for (i = 0;i < recCount;i++) {
			str3 = bukuperpus[i].namabuku;
			str4 = bukuperpus[i].author;
			str6 = bukuperpus[i].penerbit;
			str2 = bukuperpus[i].kodebuku;
			if (str3.find(cari) != string::npos) {
				str1 = to_string(bukuperpus[i].jumlahbukutersedia);
				str2 = to_string(bukuperpus[i].jmlhbukutotal);
				str3 = bukuperpus[i].namabuku;
				str4 = bukuperpus[i].author;
				str5 = bukuperpus[i].kodebuku;
				str6 = bukuperpus[i].penerbit;
				table += {str3, str4, str6, str5, str1, str2};
				continue;
			}
			else if (str4.find(cari) != string::npos) {
				str1 = to_string(bukuperpus[i].jumlahbukutersedia);
				str2 = to_string(bukuperpus[i].jmlhbukutotal);
				str3 = bukuperpus[i].namabuku;
				str4 = bukuperpus[i].author;
				str5 = bukuperpus[i].kodebuku;
				str6 = bukuperpus[i].penerbit;
				table += {str3, str4, str5, str6, str1, str2};
				continue;

			}
			else if (str5.find(cari) != string::npos) {
				str1 = to_string(bukuperpus[i].jumlahbukutersedia);
				str2 = to_string(bukuperpus[i].jmlhbukutotal);
				str3 = bukuperpus[i].namabuku;
				str4 = bukuperpus[i].author;
				str5 = bukuperpus[i].kodebuku;
				str6 = bukuperpus[i].penerbit;
				table += {str3, str4, str6, str5, str1, str2};
				*found = i;
				continue;

			}
			else if (str2.find(cari) != string::npos) {
				str1 = to_string(bukuperpus[i].jumlahbukutersedia);
				str2 = to_string(bukuperpus[i].jmlhbukutotal);
				str3 = bukuperpus[i].namabuku;
				str4 = bukuperpus[i].author;
				str5 = bukuperpus[i].kodebuku;
				str6 = bukuperpus[i].penerbit;
				table += {str3, str4, str6, str5, str1, str2};
				continue;

			}


		}
	}

	cout << table;
	if (table.rows.size() >= yes) {
		for (i = 0;i < table.rows.size();i++) {
			table -= hapus;
		}
	}
	
	
}
void buku::edit_buku(char tkode[30],int com) {
		ifstream restfile("databuku.dat", ios::in);
		restfile.seekg(0, ios::beg);
		int f;
		recCount = 0;
		SIZE = 250;
		while (true && recCount < SIZE)

		{
			restfile.read((char*)&bukuperpus[recCount], sizeof(bukuperpus));
			if (restfile.eof()) break;
			recCount++;
				
		}
		restfile.close();
		if (com == 1) {
			for (i = 0;i < recCount; i++) {
				if (strcmp(tkode, bukuperpus[i].kodebuku) == 0) {
					foundbuku = i;
					f = i;
					cout << "Buku ditemukan pada indeks ke- " << f << endl; break;
				}
			}
			remove("databuku.dat");
			cout << recCount;
			fstream tempos("databuku.dat", ios::out);

			for (i = 0;i < recCount;i++) {
				if (i == f) {
					bukuperpus[i].jumlahbukutersedia -= 1;
				}
				tempos.write((char*)&bukuperpus[i], sizeof(bukuperpus));
			}
			tempos.close();
		}else if (com == 2) {
			for (i = 0;i < recCount; i++) {
				if (strcmp(tkode, bukuperpus[i].kodebuku) == 0) {
					f = i;
					cout << "Buku ditemukan pada indeks ke- " << f << endl; break;
					bukuperpus[i].jumlahbukutersedia += 1;

				}
			}
			remove("databuku.dat");

			fstream tempos("databuku.dat", ios::out);

			for (i = 0;i < recCount;i++) {
				if (i == f) {
					bukuperpus[i].jumlahbukutersedia += 1;
				}
				tempos.write((char*)&bukuperpus[i], sizeof(bukuperpus));
			}
			tempos.close();
		}
		else if(com==0){
			cout << recCount; system("PAUSE");

			 for (i = 0;i <=recCount; i++) {
				 cout << i << endl;
				 if (strcmp(tkode, bukuperpus[i].kodebuku) == 0) {
					f = i;
					cout << "Buku ditemukan pada indeks ke- " << f << endl;
					cout << endl;
						string tkodee;
						char ch, tname[50], tauthor[50], tkodes[20], tpub[30]; int tjmlh, ttersedia;
						tkodee = tkode;
						cout << "apakah anda ingin mengubah record buku berikut : " << endl;
						buku::pencarian(tkodee, &f);
						cout << '\n' << '\n';
						cout << "Pilihan : y/n ";
						ch = _getch();
						if (ch == 'y' || ch == 'Y') {
							cout << endl;
							cout << "Enter the name of the book or <ENTER> for no change ";
							cin.getline(tname, 50);
							if (strlen(tname) == 0) {
								strcpy_s(tname, bukuperpus[f].namabuku);
							}
							cout << "Enter the author's name or <ENTER> for no change ";
							cin.getline(tauthor, 50);
							if (strlen(tname) == 0) {
								strcpy_s(tname, bukuperpus[f].author);
							}
							cout << "Enter the Publisher namer or <ENTER> for no change ";
							cin.getline(tpub, 30);
							if (strlen(tpub) == 0) {
								strcpy_s(tpub, bukuperpus[f].penerbit);
							}
							cout << "Enter the new code or <ENTER> for no change ";
							cin.getline(tkodes, 20);
							if (strlen(tkodes) == 0) {
								strcpy_s(tkodes, bukuperpus[f].kodebuku);
							}
							cout << "Masukan jumlah buku total atau <0 atau null> tanpa perubahan ";
							cin >> tjmlh;
							int tjmlh2;
							cout << "Masukan jumlah buku yang tersedia <0 atau null> tanpa perubhan : ";
							cin >> bukuperpus[f].jumlahbukutersedia;
							cin.ignore();
							while (tjmlh != NULL) {
								if (bukuperpus[f].jmlhbukutotal > bukuperpus[f].jumlahbukutersedia) {
									ttersedia = bukuperpus[f].jumlahbukutersedia + (tjmlh - bukuperpus[f].jmlhbukutotal);
									break;
								}
								else if (bukuperpus[f].jmlhbukutotal == bukuperpus[f].jumlahbukutersedia) {
									ttersedia = bukuperpus[f].jumlahbukutersedia;
									break;
								}
								else if (bukuperpus[f].jmlhbukutotal < bukuperpus[f].jumlahbukutersedia) {
									ttersedia = bukuperpus[f].jumlahbukutersedia;
									bukuperpus[f].jumlahbukutersedia = bukuperpus[f].jmlhbukutotal;
									bukuperpus[f].jmlhbukutotal = ttersedia;
									ttersedia = bukuperpus[f].jumlahbukutersedia + (tjmlh - bukuperpus[f].jmlhbukutotal);
									break;
								}
								else break;
							}
							if (tjmlh == NULL) {
								tjmlh = bukuperpus[f].jmlhbukutotal;
								ttersedia = bukuperpus[f].jumlahbukutersedia;
							}
							remove("databuku.dat");
							cout << recCount;
							fstream tempo("databuku.dat", ios::out);

							for (i = 0;i < recCount;i++) {
								if (i == f) {
									strcpy_s(tempS[f].author, tauthor);
									strcpy_s(tempS[f].namabuku, tname);
									strcpy_s(tempS[f].kodebuku, tkodes);
									strcpy_s(tempS[f].penerbit, tpub);
									tempS[f].jumlahbukutersedia = ttersedia;
									tempS[f].jmlhbukutotal = tjmlh;
									tempo.write((char*)&tempS[i], sizeof(tempS));
									continue;
								}
								strcpy_s(tempS[i].author, bukuperpus[i].author);
								strcpy_s(tempS[i].namabuku, bukuperpus[i].namabuku);
								strcpy_s(tempS[i].kodebuku, bukuperpus[i].kodebuku);
								strcpy_s(tempS[i].penerbit, bukuperpus[i].penerbit);
								tempS[i].jumlahbukutersedia = bukuperpus[i].jumlahbukutersedia;
								tempS[i].jmlhbukutotal = bukuperpus[i].jmlhbukutotal;
								tempo.write((char*)&tempS[i], sizeof(tempS));

							}

							tempo.close();
						
				 }
						else if (i == recCount) {
							cout << "Tidak Terdapat buku dengan nomor tersebut" << endl;
							return;
						}
			  }
			





				
	





			}



			/*for (i = 0;i < recCount;i++) {
				if (f == i) {
					strcmp(bukuperpus[f].namabuku, nama);
						strcmp(bukuperpus[i].author, penulis);
						strcmp(bukuperpus[i].kodebuku, tkode);
				strcmp(bukuperpus[i].penerbit ,pub);
				bukuperpus[i].jumlahbukutersedia;
					bukuperpus[i].jmlhbukutotal = jmlh2;
				}
			}*/
		}
}

int buku::add_buku(char na[50], char aut[30], char pub[30], char kbu[30], int jmlh1, int jmlh2)
{
	ifstream restfile("databuku.dat", ios::in);
	restfile.seekg(0, ios::beg);
	recCount = 0;
	SIZE = 250;
	while (true)
	{
		restfile.read((char*)&bukuperpus[recCount], sizeof(bukuperpus));
		if (restfile.eof()) break;
		recCount += 1;
	}
	restfile.close();
	/*for (i = 0;i < recCount;i++) {
		if (bukuperpus[i].jmlhbukutotal == 0) {
			for (int x = i;x < recCount;x++) {
				bukuperpus[x] = bukuperpus[x + 1];

			}
		}
	}*/
	remove("databuku.dat");
	fstream tempo("databuku.dat", ios::out);
	for (i = 0;i <=recCount;i++) {
		if (strcmp(kbu, bukuperpus[i].kodebuku) == 0) {
			cout << "Kode buku  tidak boleh sama";
			return -1;  break;
		}else if (i<recCount) {
		strcpy_s(tempS[i].author, bukuperpus[i].author);
		strcpy_s(tempS[i].namabuku, bukuperpus[i].namabuku);
		strcpy_s(tempS[i].kodebuku, bukuperpus[i].kodebuku);
		strcpy_s(tempS[i].penerbit, bukuperpus[i].penerbit);
		tempS[i].jumlahbukutersedia = bukuperpus[i].jumlahbukutersedia;
		tempS[i].jmlhbukutotal = bukuperpus[i].jmlhbukutotal;
		
	}
		else if (i==recCount) {
			strcpy_s(tempS[recCount].author, aut);
			strcpy_s(tempS[recCount].namabuku, na);
			strcpy_s(tempS[recCount].kodebuku, kbu);
			strcpy_s(tempS[recCount].penerbit, pub);
			tempS[recCount].jumlahbukutersedia = jmlh1;
			tempS[recCount].jmlhbukutotal = jmlh2;
		}
		tempo.write((char*)&tempS[i], sizeof(tempS));
	}
	
	tempo.close();

		return 0;


}

int buku::delete_buku(char tkode[30])
{
	int f;
	char ch;
	ifstream restfile("databuku.dat", ios::in);
	restfile.seekg(0, ios::beg);
	recCount = 0;
	SIZE = 250;
	int x;
	while (true)
	{
		restfile.read((char*)&bukuperpus[recCount], sizeof(bukuperpus));
		if (restfile.eof()) break;
		recCount += 1;
	}
	restfile.close();
	for (i = 0;i <=recCount;i++) {
		if (strcmp(bukuperpus[i].kodebuku, tkode) == 0) {
			f = i;
			x = i;
			cout << "Apakah anda yakin untuk mengpus buku berikut (y/n)" << endl;
			buku::pencarian(tkode, &f);
			cout << endl << " masukan pilihan:  ";
			ch = _getch();
			if (ch == 'y' || ch == 'Y') {
				break;
			}
			else if (ch == 'N' || ch == 'n') {
				return -1;
			}
		}
		else if (i == recCount) {
			cout << "tidak terdapat buku dengan kode tersebut" << endl;
			getchar();
			return -1;
		}
	}
	  remove("databuku.dat");
	  fstream tempo("databuku.dat", ios::out);
	  for (i = 0;i < recCount;i++) {
		  if (i == x) cout << endl;
		  else {
			  tempo.write((char*)&bukuperpus[i], sizeof(bukuperpus));
		  }
	  }
	  return 0;
}



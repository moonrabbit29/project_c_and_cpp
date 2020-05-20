#include<iostream>
#include <string>
using namespace std;

int main(){
	string inputan;
	char cari;
	cout<<"Masukan string : ";
	cin>>inputan;
	cout<<"Masukan karakter yang ingin dicari : ";
	cin>>cari;
	int n=inputan.length(),jumlah=0;
	while(n>=0){//looping untuk mneghitung jumlah huruf
		if(inputan[n]==cari){
			jumlah++;
		}
		n--;
	}
	cout<<"Jumlah karakter '"<<cari<<"' : "<<jumlah;
	return 0;
}

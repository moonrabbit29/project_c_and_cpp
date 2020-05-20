#include<stdio.h>
#include<iostream>
#include <sstream>
using namespace std;
int main(){
	int i=1,Jam_awal,Jam_akhir,Menit_awal,Menit_akhir,Detik_awal,Detik_akhir,Lama_jam,Lama_menit,Lama_detik;
	char a[3],b[3];
	input:
	cout<<"Awal Panggilan(jj.mm.dd) : ";
	scanf("%[^.] . %[^.] . %d",a,b,&Detik_awal);
	stringstream ubah(a); stringstream ubah1(b);
	ubah>>Jam_awal; ubah1>>Menit_awal;
		if(Jam_awal>24||Jam_awal<0){
			cout<<"[WARNING] Inputkan Jam yang benar"<<endl;
			goto input;
		}if(Detik_awal>60||Detik_awal<0){
				cout<<"[WARNING] Inputkan detik yang benar"<<endl;
			goto input;
		}if(Menit_awal>60||Menit_awal<0){
				cout<<"[WARNING] Inputkan menit yang benar"<<endl;
			goto input;
		}
		akhir:
	cout<<"akhir Panggilan(jj.mm.dd) : ";
	scanf("%[^.] . %[^.] . %d",a,b,&Detik_akhir);
	stringstream ubah2(a); stringstream ubah3(b);
	ubah2>>Jam_akhir; ubah3>>Menit_akhir;
		if(Jam_akhir>24||Jam_akhir<0){
			cout<<"[WARNING] Inputkan Jam yang benar"<<endl;
			goto akhir;
		}if(Detik_akhir>60||Detik_akhir<0){
				cout<<"[WARNING] Inputkan detik yang benar"<<endl;
			goto akhir;
		}if(Menit_akhir>60||Menit_akhir<0){
				cout<<"[WARNING] Inputkan menit yang benar"<<endl;
			goto akhir;
		}
	Lama_detik=Detik_akhir-Detik_awal; 
		if(Lama_detik<0) {
		Lama_detik+=60;
		Lama_menit=Menit_akhir-Menit_awal;
			if(Lama_menit<0){
					if(Lama_menit<0) Lama_menit+=60;
					Lama_menit--;
			Lama_jam=Jam_akhir-Jam_awal; 
			if(Lama_jam<0) {
			Lama_jam+=23;
			}else{
			Lama_menit--;
			Lama_jam=Jam_akhir-Jam_awal; 
			if(Lama_jam<0) {
			Lama_jam+=24;
			}
		}
	}
}else{
		Lama_menit=Menit_akhir-Menit_awal;
			if(Lama_menit<0){
					if(Lama_menit<0) Lama_menit+=60;
			Lama_jam=Jam_akhir-Jam_awal; 
			if(Lama_jam<0) {
			Lama_jam+=23;
			}
			}else{
			Lama_jam=Jam_akhir-Jam_awal; 
			if(Lama_jam<0) {
			Lama_jam+=24;
			}
		}
	
}

	
	
	cout<<"Lama penggilan : "<<Lama_jam<<"Jam, "<<Lama_menit<<"Menit, "<<Lama_detik<<"Detik, ";

}

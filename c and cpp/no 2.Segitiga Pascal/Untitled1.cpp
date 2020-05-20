#include<iostream>
using namespace std;
int main(){
	int n,i; //deklarasi variable untuk menyimpan tinggi segitiga dan variable untuk iterasi
	int coef=1;
	cout<<"Masukan Tinggi Segitiga : ";
	cin>>n;
	for(i=0;i<n;i++){
		for(int y=0;y<n-i;y++) cout<<" ";
		for(int x=0;x<=i;x++){
			if(x==0||i==0||x==i) cout<<'1'<<" ";
			else{
				coef=coef*(i-x+1)/x; //menghitung nilai coefsien pola segitiga pascal 
				cout<<coef<<" ";	
			}
		}
		coef=1; //coefsien selalu dihitung dari satu
		cout<<endl;
		
	}
	return 0;
}

// refrensi : https://www.sanfoundry.com/cpp-program-print-pascal-triangle/

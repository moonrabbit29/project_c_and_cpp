#include <iostream>

using namespace std;
int main(){
	int t,p,j;
	cout<<"Masukan tinggi tangga: ";
	cin>>t;
	cout<<"Masukan Panjang tangga: ";
	cin>>p;
	cout<<"Masukan jumlah anak tangga: ";
	cin>>j;
	for(int i=0;i<j;i++){
		for(int x=0;x<t;x++){
			for(int z=0;z<=i;z++){
			for(int y=0;y<p;y++){
				cout<<("* ");
			}
		}
			cout<<"\n";
		}
	
	}
	
}

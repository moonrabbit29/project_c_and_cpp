#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<char> ArrayHuruf;
	char temp;
	int x,i=0;
	cout<<"Masukan jumlah string : ";
	cin>>x;
	ArrayHuruf.resize(x);
	while(i<x){
		cout<<"String ke-"<<i+1<<": ";
		cin>>ArrayHuruf[i];
		i++;
	}
	cout<<"--Setelah Diurutkan--";
	for(i=0;i<x;i++){//sorting array
		for(int y=0;y<x-1;y++){
		if(ArrayHuruf[y]>ArrayHuruf[y+1]){
			temp=ArrayHuruf[y];
			ArrayHuruf[y]=ArrayHuruf[y+1];
			ArrayHuruf[y+1]=temp;
		}
     }
	}
	i=0;
	while(i<x){
		cout<<endl<<ArrayHuruf[i];
		i++;
	}
	return 0;
}

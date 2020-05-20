#include<iostream>
using namespace std;
int main(){
	int fibonanci[3],n,i=0;
	cout<<"Masukan banyak deret fibonanci:";
	cin>>n; //menyimpan panjang deret pada variavle n
	fibonanci[0]=0;
	fibonanci[1]=1;
	while(i<n-1){
		if(i==0)
		cout<<fibonanci[0]<<" "<<fibonanci[1]<<" ";
		else{
		fibonanci[2]=fibonanci[0]+fibonanci[1]; //pola deret fibonaaci Un-2 + Un-1
		cout<<fibonanci[2]<<" ";
		fibonanci[0]=fibonanci[1];
		fibonanci[1]=fibonanci[2];
	}
		i++;
	}
	return 0;
}



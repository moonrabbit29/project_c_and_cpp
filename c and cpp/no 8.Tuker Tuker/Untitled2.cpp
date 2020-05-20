#include <iostream>
using namespace std;
void tuker(int *c,int *d){
	
}
int main(){
	int a,b;
	cout<<"Masukan bilangan A : ";
	cin>>a;
	cout<<"Masukan bilangan B: ";
	cin>>b;
	//menggunkan xor 4 dengan binary number=> 0100 ^ 0010= 0110 => 0110^0100 => 0010 
	a=(a|b)&(~a|~b); // opsi lain dari xor dengan simbol ('^")
	b=(a|b)&(~a|~b);
	a=(a|b)&(~a|~b);
	cout<<"Setelah ditukar"<<"\n"<<"A="<<a<<"\n"<<"B="<<b;
	return 0;
}
//refrensi: https://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/

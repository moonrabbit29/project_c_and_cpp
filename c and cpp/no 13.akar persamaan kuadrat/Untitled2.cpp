#include <iostream>
#include<math.h>
#include <iomanip>
using namespace std;
int main(){
	int a,b,c;
	cout<<"Masukan nilai a: ";
	cin>>a;
	cout<<"Masukan nilai b: ";
	cin>>b;
	cout<<"Masukan nilai c: ";
	cin>>c;
	float x1,x2;
	//rumus mencari akar persamaan kuadrat => x1,x2=(b +/- sqrt(b^2-4ac))/2a
	x1=(b+sqrt(b*b - 4*a*c))/(2*a);
	x2=(b-sqrt(b*b-4*a*c))/2*a;
	cout<<fixed;
	cout<<setprecision(2);
	cout<<"X1= "<<x1<<"\n";
	cout<<"X2= "<<x2<<"\n";
	return 0;
}

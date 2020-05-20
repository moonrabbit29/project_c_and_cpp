#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	float x;
	cout<<"Masukan nilai x : ";
	cin>>x;
	float y=x*22/7/180;
	cout<<fixed;
	cout<<setprecision(2);
	cout<<"sin("<<x<<")="<<sin(y)<<"\n";//built in function untuk mencari sin
	cout<<"cos("<<x<<")="<<cos(y)<<"\n";
	cout<<"tan("<<x<<")="<<tan(y)<<"\n";
	
return 0;	
}

#include <iostream>
using namespace std;
int main(){
	int i,n,med,j,space,x,space2=0;
	cout<<"input: ";
	cin>>n;
	med=n/2;
	//Bagian atas
	if(n%2==1) med+=1;
	for(i=med;i<n;i+=2){
		for(j=1;j<n-i;j+=2) cout<<" ";
		for(j=1;j<=i;j++) cout<<"*";
		for(j=1;j<=n-i-1;j++)cout<<" ";
		for(j=1;j<=i;j++)cout<<"*";
		cout<<endl;		
	}
	//Bagian bawah segitiga terbalik
	x=n+n;
	space=0;
		for(i=0;i<n;i++){
		for(j=x;j>2;j--){
					if(j==1&i!=0) continue ;
			while(space>1&&i!=0){
				cout<<" ";
				space--;
			}
			cout<<"*";
		}
		if(i==n-1){
		for(i=1;i<space2;i++){
		cout<<" ";
		}
		cout<<" *";
		break;
		}
		cout<<endl;
		space2++;
		x-=2;
		space=space2+1;
	}

	return 0;
	
}	

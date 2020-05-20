#include <iostream>
using namespace std;
int main(){
	int n; //variable untuk menyimpan tinggi karakter dan panjangnya
	int med,medbawah;//variable menyimpan nilai median dari tinggi dan panjang 
	cout<<"Masukan Tinggi dan Panjang : ";
	cin>>n;
	if(n%2==1) {
	med=n/2+1;
	medbawah=med-1;
	}
	else{
		med=n/2;
		medbawah=med;
	} 
		for(int y=0;y<med;y++){//huruf bagian atas
			if(y==0||y==med-1){
			for(int x=0;x<n*3+2;x++){
			 	if(x==n||x==n*2+1)cout<<" ";
				 else cout<<"*";
			}
			}else if((y!=0 && y%2==1) || y!=med-1){
				cout<<"*";
				for(int space2=0;space2<3;space2++){
					if(space2!=2){
						if(space2==1) cout<<"*";
						for(int space=0;space<n;space++){
							cout<<" ";
				 		}
				 	}else {
				 		cout<<"*";
					 for(int space=0;space<n-2;space++){
							cout<<" ";
				 		}cout<<"*";	
				}
			}
		}
			cout<<endl;
		}
		for(int y=0;y<medbawah;y++){//bagian bawah
			if(y!=medbawah-1){// kondisi selain bagian bawah
				for(int space=0;space<3;space++){
					if(space==0){
						for(int space2=0;space2<n-1;space2++)cout<<" ";
						cout<<"* ";
					}else if(space==1||space==2){
							cout<<"*";
							for(int space2=0;space2<n-2;space2++)cout<<" ";
							if(space==2) cout<<"* ";
							else cout<<"  ";
					}
				}
			}
			else{
					for(int x=0;x<n*3+2;x++){
			 	if(x==n||x==n*2+1||(x>n*2+2&&x<n*3+1))cout<<" ";
				 else cout<<"*";
			}
			}
			cout<<endl;
		}
return 0;
}

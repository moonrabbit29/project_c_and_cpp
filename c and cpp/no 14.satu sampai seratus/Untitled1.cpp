#include <iostream>
int main(){
	static int i=1;  //agar variable tidak di destroy saat fungsi berakhir
	if(i<=100){
		if(i%2==1) std::cout<<i<<" ";
		i++; 
		main(); //pemanggilan fungsi main 
		}
return 0;
}

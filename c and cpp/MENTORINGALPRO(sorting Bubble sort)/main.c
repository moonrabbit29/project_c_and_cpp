#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

            /*BUBLLE SORT

do
    ditukar = false
    for i = 1 to indexOfLastUnsortedElement
        if elemenKiri > elemenKanan
            swap(elemenKiri, elemenKanan)
            ditukar = true
while ditukar
*/
void main(){
	int y[5]={3,2,1,4,5},i;
	bool swap=false;
	do {
		swap=false;
		for(i=1;i<5;i++){
			if(y[i-1]>y[i]){
				y[i]=y[i-1]+y[i];
				y[i-1]=y[i]-y[i-1];
				y[i]=y[i]-y[i-1];
				swap=true;
			}
		}
	}while(swap);
		for( i=0;i<5;i++)
		printf("%d\n",y[i]);
}

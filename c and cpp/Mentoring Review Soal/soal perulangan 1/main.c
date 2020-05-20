#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y=1,i=1;
    scanf("%d",&x);
    do{
        if(x>i){
             y= y+2;
             i = i+x;
              }
        else {
             y= y-1;
             i=i-y; }
    }while(y!=x-1);
    printf("%d",i);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y[5]={12,11,34,25,8},max,i=0,x;
    printf("Sebelum diurutkan \n");
    while(i<sizeof(y)/sizeof(y[0])){
        printf("%d ",y[i]);
        i++;
    }
    for(i=0;i<sizeof(y)/sizeof(y[0])-1;i++){
        max=y[i];
        for(x=i;x<sizeof(y)/sizeof(y[0]);x++){
            if(max<y[x]){
                max=max+y[x];
                y[x]=max-y[x];
                max=max-y[x];
            }
        }
        y[i]=max;
    }
    printf("\n sesudah diurutkan \n");
    i=0;
    while(i<sizeof(y)/sizeof(y[0])){
        printf("%d ",y[i]);
        i++;
    }
    return 0;
}

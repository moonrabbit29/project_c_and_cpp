#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y[5]={2,1,5,4,3},i,j,temp;
    printf("Hello world!\n");
    printf("Data sebelum diurutkan\n");
    for(i=0;i<5;i++){
        printf("%d ",y[i]);
    }
    for(i=1;i<5;i++){
        j=i-1;
        temp=y[i];
        while(temp>y[j]&&j>=0){
            y[j+1]=y[j];
            j--;
        }
        y[j+1]=temp;
    }
    printf("\n Data setelah diurutkan secara ascending\n");
     for(i=0;i<5;i++){
        printf("%d ",y[i]);
    }
     for(i=1;i<5;i++){
        j=i-1;
        temp=y[i];
        while(temp<y[j]&&j>=0){
            y[j+1]=y[j];
            j--;
        }
        y[j+1]=temp;
    }
    printf("\n Data setelah diurutkan secara descending\n");
     for(i=0;i<5;i++){
        printf("%d ",y[i]);
    }

    return 0;
}

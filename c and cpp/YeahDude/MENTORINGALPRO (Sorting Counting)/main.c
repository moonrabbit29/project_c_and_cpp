#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int y[7]={4,4,4,3,2,1,6},i=0;
    int count[7],temp[10];
    memset(count,0,7*sizeof(count[0]));
    for(i=0;i<7;i++){ //menghitung jumlah setiap elemen dalam array
        count[y[i]]++;
    }
     for(i=0;i<7;i++){
       printf("%d ",y[i]);
    }
    printf("=> data array \n");
     for(i=0;i<7;i++){
       printf("%d ",count[i]);
    }


    for(i=1;i<7;i++){ //menempatkan elemen pada index seharusnya
        count[i] += count[i-1];
    }
    printf("=> hasil counting \n");
      for(i=0;i<7;i++){
       printf("%d ",count[i]);
    }

    for(i=0;i<7;i++){
        temp[count[y[i]]-1]= y[i];
        count[y[i]]= count[y[i]]-1;
    }
    printf("=> hasil positioning\n");
    for(int x=0;x<7;x++){
        printf("%d ",temp[x]);
    }
    return 0;
}

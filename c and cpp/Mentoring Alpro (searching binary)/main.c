#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
   int a[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   int mid,bawah=0,atas,IX;
   bool found = false;
   int cari;
   scanf("%d",&cari);
   atas=sizeof(a)/sizeof(int)-1;
   while(bawah<=atas && !found){
        mid=(atas+bawah)/2;
    if(cari==a[mid]){
        found=true;
        IX=mid;
    }
    else if(cari>a[mid]){
        bawah=mid+1;
    }
    else
        atas= mid-1;

   }
   if(found)
    printf("%d ditemukan pada indeks ke %d ",cari,IX);
   else
    printf("data tidak ditemukan ");

    return 0;
}

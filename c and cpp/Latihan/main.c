#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct sayuran{
char nama[10],asal[10];
int banyak,kualitas,harga,total;
} Dondo[10],temp,baca[10],sayur ;

int main()
{
    int totalsayur=0,cacahsayur=0,N,i,len,min,y,min_index;
    int totalasal=0,cacahasal=0;
    char current[10];
    bool swap=false; //tag untuk modified bubble sort
    printf("Dendi Arya Raditya Prawira Putra \n");
    printf("1103184150\n");
    printf("TK-42-05\n");
    printf("Jumlah data : ");
    scanf("%d",&N);fflush(stdin);
    for(i=0;i<N;i++){
        printf(" Nama sayur ke %d ",i);
        fgets(Dondo[i].nama,10,stdin);
        len = strlen(Dondo[i].nama);
        if( Dondo[i].nama[len-1] == '\n' )
            Dondo[i].nama[len-1] = 0;
        printf("Asal sayur ke %d",i);
        fgets(Dondo[i].asal,10,stdin);
        len=strlen(Dondo[i].asal);
        if( Dondo[i].asal[len-1] == '\n' )
            Dondo[i].asal[len-1] = 0;
        printf("banyak sayur ke %d : ",i);
        scanf("%d",&Dondo[i].banyak);
        printf("Kualitas ke %d : ",i);
        scanf("%d",&Dondo[i].kualitas);
        fflush(stdin);
        if(strcmp(Dondo[i].asal,"jabar")){
            switch(Dondo[i].kualitas){
                case 1 : Dondo[i].harga=1500; break;
                case 2 : Dondo[i].harga=1200; break;
            }
        }
        else{
            switch(Dondo[i].kualitas){
                case 1 : Dondo[i].harga=2500; break;
                case 2 : Dondo[i].harga=3000; break;
                default : Dondo[i].harga =500; break;
            }
        }
        Dondo[i].total=Dondo[i].harga * Dondo[i].banyak;
        totalsayur=totalsayur+Dondo[i].total;
        cacahsayur=cacahsayur+Dondo[i].banyak;
    }
    for(i=0; i<N ;i++ )
        printf("%s %s %d %d \n",Dondo[i].nama,Dondo[i].asal,Dondo[i].banyak,Dondo[i].harga);
    printf("\n Cacah sayur : %d ",cacahsayur);
    printf("\n Rata Rata harga: %d ",(totalsayur/cacahsayur));

    for(i=0;i<N-1;i++){ //selection sort berdasarkan kulatisan
          min_index=i;
          min=Dondo[i].kualitas;
          for(y=i+1;y<N;y++){
            if(Dondo[y].kualitas<min){
                min=Dondo[y].kualitas;
                min_index=y;
            }
          }
               temp=Dondo[i];
               Dondo[i]=Dondo[min_index];
               Dondo[min_index]=temp;
       }
       printf("\n \n Data setelah diurutkan\n");
    for(i=0; i<N ;i++ )
        printf("%s %s %d %d \n",Dondo[i].nama,Dondo[i].asal,Dondo[i].banyak,Dondo[i].harga);

    FILE *fp = fopen("file.txt","w"); //penulisan file setelah diurutkan
    fwrite(&Dondo, sizeof(struct sayuran), 5 , fp);
    fclose(fp);

    fp=fopen("file.txt","r"); //pembacaan file
    fread(&baca,sizeof(*baca),5,fp);
    fclose(fp);

        printf("Data hasil pembacaan \n");
   for(i=0; i<N ;i++ )
        printf("%s %s %d %d \n",baca[i].nama,baca[i].asal,baca[i].banyak,baca[i].harga);

    	do {
		swap=false;
		for(i=1;i<5;i++){
			if(strcmp(Dondo[i-1].asal,Dondo[i].asal)<0){
                temp=Dondo[i-1];
				Dondo[i-1]=Dondo[i];
				Dondo[i]=temp;
				swap=true;
			}
		}
	}while(swap);
	printf("\n Data setelah diurutkan menggunakan modified bubble sort\n");
	for(i=0; i<N ;i++ )
        printf("%s %s %d %d \n",Dondo[i].nama,Dondo[i].asal,Dondo[i].banyak,Dondo[i].harga);

    fp = fopen("file.txt","w");
    for(i=0;i<5;i++)
    fwrite(&Dondo[i], sizeof(struct sayuran), 1 , fp);
    fclose(fp);

    fp = fopen("file.txt","r");
         fread(&sayur,sizeof(sayur),1,fp);
    do{                                     // total asal = jumlah asalnya
         cacahasal=0;                       //cacah asal = jumlah masing masing asa
        strcpy(current,sayur.asal);         //current untuk menyimpan data sekarang yang sedang dibaca
        do{
            fread(&sayur,sizeof(sayur),1,fp);
            cacahasal++;
        }while(strcmp(sayur.asal,current)==0&&!feof(fp));
        totalasal++;
 printf("\n cacah asal sayuran %s : %d  ",current,cacahasal);
    }while(!feof(fp));


	fclose(fp);
    printf("\nTotal asal sayuran : %d ",totalasal);





return 0;
}

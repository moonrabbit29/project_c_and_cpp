#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <time.h>
FILE *ptr; FILE *ptrr;
char usrname[100],pass[100]; int logincnt;
struct maggie{
char name[40],nomor[14]; long long nik;
char add[40],gen,usr[12],password[14]; char ket[20];
 }temp,data[1000],ready[1000];
 struct maggies{
 char nama[40],party[40];
 int terpilih;
 }tempx,read2[20],data2[20];
static const struct maggie EmptyStruct;
static const struct maggies EmptyStruct2;
size_t num; size_t num2; int k=0,tq,calon;
char null[14];
void readfile(){
    int bc,ab;
ptr=fopen("databasepemilu.txt","rb");
if(ptr==NULL){
num=0; printf("data peserta pemilu tidak ditemukan\n"); getchar();
}else{
num = fread (ready, sizeof(*ready), sizeof(ready) / sizeof(*ready), ptr);
}
fclose (ptr);
ptrr=fopen("database.txt","rb");
if(ptrr==NULL){
num2=0; printf("data calon pemilu tidak ditemukan\n"); getchar();
}else{
    num2 = fread (read2, sizeof(*read2), sizeof(read2) / sizeof(*read2), ptrr);
}
fclose (ptrr);
}
int main()
{
    int r,q,pil,i;
     int z;
    readfile();
    if(z==1){
        goto menu;
    }
printf("\t\t\t\t*****************************************************************\n");
printf("\t\t\t\t*\t\t\tEVACOUNT\t\t\t\t*\n");
printf("\t\t\t\t*****************************************************************\n");
gotoxy(50,8);
system("pause");
system("cls");
gotoxy(38,8);
printf("Loading...");
gotoxy(38,9);
for(r=1;r<=22;r++){
    for(q=0;q<=100000000;q++);
    printf("%c",177);
}
system("cls");
gotoxy(50,10);
printf("complete");
delay(1);
system("cls");
menu:
 printf("\n\t\tSelamat datang di menu\n");
 printf(" \"1\" untuk menuju menu login\n\n");
 printf(" \"2\" untuk menuju menu register\n");
 printf("\"3\" Menampilkan perolehan suara\n");
 printf("\"4\" Menampilkan Data peserta pemilu\n");
 printf(" \"5\" simpan dan exit\n ");
 printf("Pilihan : "); scanf("%d",&pil); fflush(stdin);
    switch(pil){
    case 1 : system("cls"); logins(); break;
    case 2 : system("cls"); regist(); break;
    case 5 : system("cls"); simpan(); break;
    case 3 : system("cls"); goto tampil; break;
    case 4 : system("cls"); goto tampil2; break;
    default : goto menu; break;
    }
tampil:
if(num2==0){
    printf("data pemilu tidak ditemukan\n\n");
}
    for(i=0;i<num2;i++){
printf("Nama Calon Pemilu :  %s \n",read2[i].nama);
printf("Jumlah perolehan suara : %d\n",read2[i].terpilih);
}
getchar(); system("cls");
goto menu;
tampil2:
    if(num==0){
        printf("Tidak Terdapat Data Pemilu peserta pemilu \n");
        getchar(); system("cls"); goto menu;
    }
 printf("data peserta pemilu \n ");
for(i=0;i<num;i++){
    printf("Nama : %s\n",ready[i].name);
 printf("NIK : %lld\n",ready[i].nik);
 printf("No HP :%s\n",ready[i].nomor);
 printf("Alamat : %s\n",ready[i].add);
 printf("Gender : %c\n",ready[i].gen);
 printf("keterangan : %s\n",ready[i].ket);
        getchar();
 system("cls");
}
goto menu;
return 0;
}


void delay(int number1){
    int milnum=1000*number1;
clock_t start_time=clock();
while(clock()<start_time+milnum)
    ;
}

int gotoxy(int x, int y){
COORD coord;
coord.X=x;
coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int regist(){
     int umur;  int cg,d=0;
     int i; char ch; char password[20],tempa[20];
     printf("\t\t\t\tMenu Registrasi\n");
printf("Nama : "); gets(data[k].name);
printf("NIK : ");scanf("%lld",&data[k].nik); fflush(stdin);
for(i=0;i<=num;i++){
if(data[k].nik==ready[i].nik||strcmp(data[k].name,ready[i].name)==0){
        if(strcmp(ready[i].usr,EmptyStruct.usr)==0&&strcmp(ready[i].password,EmptyStruct.password)==0){
                printf("Nama dan Nik anda telah Terdaftar, silahkan lanjutkan untuk membuat username dan password\n\n");
                cg=i; d=1;
            goto heyhey;
        }else if(strcmp(ready[i].usr,EmptyStruct.usr)!=0&&strcmp(ready[i].password,data)!=0) {
     printf("NIK dan Nama anda telah terdaftar  \n");
    getchar(); system("cls"); main(); break;
}}}
printf("alamt : ");gets(data[k].add);
printf("Nomor HP : ");gets(data[k].nomor);
printf("Gender : "); scanf("%c",&data[k].gen);fflush(stdin);
printf("Umur : "); scanf("%d",&umur); fflush(stdin);
if(umur>=17) {
    heyhey:
        printf("masukan Username anda : ");
        gets(data[k].usr);
        for(i=0;i<=num;i++){
            if(strcasecmp(data[k].usr,ready[i].usr)==0){
                printf("\nusername telah terdaftar \n\n"); getchar();
                system("cls");
                goto heyhey;
            }
        }
        ryu:
        printf("Masukan Password anda : ");
        i=0;
        while(1){
  ch=getch();
  if(ch == 13)
 break;
    else if (ch==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   --i;
   continue;
  }
    else{
    data[k].password[i] = ch;
     ch = '*' ;
  printf("%c",ch);
  i++;
    }}
    data[k].password[i]='\0';
    i=0;
    printf("\nMasukan Kembali pasword anda : ");
            while(1){
  ch=getch();
  if(ch == 13)
 break;
    else if (ch==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   --i;
   continue;
  }
    else{
    password[i] = ch;
     ch = '*' ;
  printf("%c",ch);
  i++;
    }}
    password[i]='\0';
    i=0;
    if(d==1&&strcmp(password,data[k].password)==0){
        strcpy(ready[cg].password,data[k].password);
        strcpy(ready[cg].usr,data[k].password);
    simpan();
    }
    if(strcmp(password,data[k].password)!=0){
        printf("\n"); printf("Pasword Tidak sama \n"); getchar(); system("cls");
        strcpy(password,tempa);
        strcpy(data[k].password,EmptyStruct.password);
        goto ryu;
    }
    if(strcmp(password,data[k].password)==0){
     system("cls"); konfirm();
    }

}else {
        printf("\nUmur belum cukup untuk mengikuti pemilu\n\n"); getchar(); system("cls"); regist();
        }
}


int konfirm()
{
    char pass4[1000],admin[130],ch,ysn; int life=3;
    if(life<3&&life>0){
        printf("username atau password salah\n silahkan coba lagi");
    }
    if(life==0){
        printf("Telah gagal mencoba selama tiga kali akses ditolak ");
        data[k]=EmptyStruct;
        main();
    }
    int i=0;
    printf("Konfirmasi Admin \n");
    printf("Username : ");
    gets(admin);
    printf("Password : ");
    while(1){
  ch=getch();
  if(ch == 13)
 break;
    else if (ch==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   --i;
   continue;
  }
    else{
    pass4[i] = ch;
     ch = '*' ;
  printf("%c",ch);
  i++;
    }}
    pass4[i]='\0';
    i=0;
    if(strcmp(admin,"mayurichan")==0 && strcmp(pass4,"masterlimbad123")==0) {
    printf("\nregistrasi diterima \n");
    yep:
    printf("simpan data ?");
    scanf("%c",&ysn); fflush(stdin);
    if(ysn=='y'||ysn=='n'){
            if(ysn=='y'){
    ready[num]=data[k]; num=num+1;
    life=3; k++;
    system("pause"); system("cls"); simpan();
    }else{
        printf("data tidak dismpan");
        system("cls");
   life=3;
   data[k]=EmptyStruct; main();
    }}else{
    goto yep;
    }
    }else{
    life--; system("cls"); konfirm();
    }
}


void simpan(){
    int i,y;
    char x; int b;
    for(i=0;i<num;i++){
    for(y=1;y<num;y++){
        if(strcmp(ready[i].name,ready[y].name)>0){
            temp=ready[i];
            ready[i]=ready[y];
            ready[y]=temp;
            temp=EmptyStruct;
        }
    }
}
ptrr=fopen("databasepemilu.txt","wb");
fwrite(ready,sizeof(struct maggie),num,ptrr);
fclose(ptrr);
ptr=fopen("database.txt","wb");
fwrite(read2,sizeof(struct maggies),num2,ptr);
fclose(ptr);
printf("data berhasil disimpan\n\n");
getchar();
system("cls");
readfile();
printf(" ingin keluar dari aplikasi? /[y/n/] : ");
scanf("%c",&x);fflush(stdin);
if(x=='y'){
    exit(0);
}
mas:
if(x=='n'){
    printf("1. Menu Utama\n");
    printf("2. Menu Login\n");
    scanf("%d",&b); fflush(stdin);
    switch(b){
    case 1 : gotoxy(38,9); printf("reboot\n"); getchar(); system("cls"); main(); break;
    case 2 : system("cls"); logins(); break;
    default :  goto mas; break;
    }
}

}


int logins(){
     int i=0;
     int loginz=0; bool nani;
     char unm[100]; char pss[100]; char ch;
     hey:
     printf("Menu Login\n");
     if(logincnt>0){
            system("cls");
        printf("Username atau password salah dan pastikan anda telah melakukan registrasi terlebih dahulu\n");
        logincnt=0;
        getchar();
        goto tes;
     }
     tes:
 printf("username : ");
 gets(unm);
 printf("Password : ");
while(1){
  ch=getch();
  if(ch == 13)
 break;
    else if (ch==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   --i;
   continue;
  }
    else{
    pss[i] = ch;
     ch = '*' ;
  printf("%c",ch);
  i++;
    }}
    pss[i]='\0';
    i=0;
for(i=0;i<num;i++){
   if(strcmp(unm,ready[i].usr)==0 && strcmp(pss,ready[i].password)==0) {
        if(strcmp(ready[i].ket,"Telah Memilih")==0){
                system("cls");
            printf("\nanda telah memilih\n");
           exit(0);
        }else{
    loginz=1; tq=i; logincnt=0; break;
   }}}
   if(strcmp(unm,"mayurichan")==0  && strcmp(pss,"masterlimbad123")==0 ){
        system("cls"); admin();
   }else if(loginz==1){
    system("cls"); printf("login berhasil"); pemilih();
   }
   else if (loginz==0){
    logincnt=1; system("cls"); goto hey;
   }}

int pemilih(){
    int i; char ch,master[20],pss[30]; int pilihana,nyawa=5;
if(ready[tq].gen=='L'|| ready[tq].gen=='l'){
    strcpy(master,"tuan");
}else if(ready[tq].gen=='P'||ready[tq].gen=='p'){
    strcpy(master,"nyonya");
}
printf("Selamat datang di menu pilihan %s %s\n\n",master,ready[tq].name);
printf("Daftar calon pemilu \n\n");
for(i=0;i<=num2;i++){
if(strcmp(read2[i].nama,EmptyStruct2.nama)!=0&&strcmp(read2[i].party,EmptyStruct2.party)!=0){
    break;
    }
    if(strcmp(read2[num2].nama,EmptyStruct2.nama)==0&&strcmp(read2[num2].party,EmptyStruct2.party)==0){
            printf("tidak ada data yang tersedia\n"); getchar(); system("cls");
            main();
    }}
for(i=0;i<num2;i++){
   printf("\"%d\" %s dari partai %s\n",i+1,read2[i].nama,read2[i].party);
}
printf("\npilihan : ");
scanf("%d",&pilihana);fflush(stdin);
hay:
    if(nyawa==0){
        printf("Telah banyak percobaan gagal akses ditolak silahkan login kembali\n");
        getchar(); system("cls");
        main();
    }
printf("Konfirmasi pilihan anda dengan memasukan password : ");
while(1){
  ch=getch();
  if(ch == 13)
 break;
    else if (ch==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   --i;
   continue;
  }
    else{
    pss[i] = ch;
     ch = '*' ;
  printf("%c",ch);
  i++;
    }}
    pss[i]='\0';
    i=0;
if(strcmp(ready[tq].password,pss)==0){
    read2[pilihana-1].terpilih= read2[pilihana-1].terpilih+1;
    printf("Terima kasih telah memilih\n");
   strcpy(ready[tq].ket,"Telah Memilih");
    simpan(); main();
}else {
printf("\npassword salah ");nyawa--; getchar(); system("cls"); goto hay;
}}


int admin(){
int pil;
hey:
printf("Menu Admin\n\n");
printf("1. Peserta Pemilu\n");
printf("2. Calon Pemilu\n");
printf("3. Simpan dan exit\n");
printf(": ");
scanf("%d",&pil); fflush(stdin);
if(pil==1 || pil==2 || pil==3){
    switch(pil){
    case 1 : system("cls");pespel(); break;
    case 2 : system("cls");capel(); break;
    case 3 : system("cls");simpan(); break;
    }
}else{
system("cls"); goto hey;
}}

int pespel(){
int b,i,NIK,cg; int umur; char nama[100],pil[20],ganti[100],ganti2;
bool gintama;
gintama=false;
hey:
printf("Menu peserta pemilu \n");
printf("1. Tambah Data Peserta Pemilu\n");
printf("2. Edit Data Peserta Pemilu\n");
printf("3. Hapus Data Peserta Pemilu\n");
printf("4. Simpad dan Exit\n");
printf(" : ");
scanf("%d",&b);fflush(stdin); system("cls");
if(b==1){
    printf("Menambahkan data peserta pemilu\n");
    printf("Silahkan masukan data pemilu\n\n");
    printf("Nama : "); gets(data[k].name);
    printf("NIK : "); scanf("%lld",&data[k].nik);fflush(stdin);
for(i=0;i<num;i++){
if(strcmp(ready[i].name,data[k].name)==0 && data[k].nik==ready[i].nik){
    printf(" nama tersebut telah terdaftar \n");
     printf("NIK tersebut telah terdafatar\n");
    printf("tekan enter untuk melanjutkan ");
    getchar(); system("cls"); goto hey; break;
}}
printf("alamat : ");gets(data[k].add);
printf("Nomor HP : ");gets(data[k].nomor);
printf("Gender : "); scanf("%c",&data[k].gen);fflush(stdin);
printf("Umur : "); scanf("%d",&umur); fflush(stdin);
if(umur>=17){

    ready[num]=data[k]; num=num+1; k=k+1;
    simpan(); admin();
}else{
printf("Maaf belum cukup umur\n"); getchar(); system("cls"); admin();
}}else if(b==2){
printf("Masukan Nama Peserta Pemilu yang ingin di Ubah datanya :"); gets(nama);
printf("Masukan NIK Peserta Pemilu yang Ingin di Ubah datanya : "); scanf("%d",&NIK); fflush(stdin);
for(i=0;i<num;i++){
if(strcmp(nama,ready[i].name)==0 && NIK==ready[i].nik){
    cg=i; gintama=true; break;
}}

if(gintama==true){
printf("Nama     : %s\n",ready[cg].name);
printf("NIK      : %d\n",ready[cg].nik);
printf("Alamat   : %d\n",ready[cg].add);
printf("Nomor HP : %s\n",ready[cg].nomor);
printf("Gender   : %c\n",ready[cg].gen);
printf("pilih data yang ingi diubah (nama,NIK,Alamat,Nomor HP,Gender): "); gets(pil);
if(strcmp(pil,"nama")==0 || strcmp(pil,"Nama")==0 || strcmp(pil,"NAMA")==0){
    printf("Masukan Nama : ");
    gets(ganti);
    strcpy(ready[cg].name,ganti);
    printf("sukses nama berhasil diganti menjadi %s ",ready[cg].name);
    getchar();
    system("cls");
  simpan(); main();
}else if(strcmp(pil,"nik")==0 || strcmp(pil,"Nik")==0 || strcmp(pil,"NIK")==0){
printf("Masukan NIK : ");
gets(ganti);
ready[cg].nik=ganti;
printf("sukses NIK berhasil diganti menjadi %d ",ready[cg].nik);
    getchar();
    system("cls");
    simpan(); admin();
}else if(strcmp(pil,"Alamat")==0 || strcmp(pil,"alamat")==0 || strcmp(pil,"ALAMAT")==0){
printf("Masukan alamt : ");
    gets(ganti);
    strcpy(ready[cg].add,ganti);
    printf("sukses alamat berhasil diganti menjadi %s ",ready[cg].name);
    getchar();
    system("cls");
    simpan(); admin();
}else if(strcmp(pil,"No HP")==0 || strcmp(pil,"NO HP")==0 || strcmp(pil,"no hp")==0){
printf("Masukan No HP : ");
gets(ganti); fflush(stdin);
strcpy(ready[cg].nomor,ganti);
printf("sukses No HP berhasil diganti menjadi %s ",ready[cg].nomor);
    getchar();
    system("cls");
   simpan(); admin();
}else if(strcmp(pil,"Gender")==0 || strcmp(pil,"GENDER")==0 || strcmp(pil,"gender")==0){
printf("Masukan Gender : ");
scanf("%c",&ganti2); fflush(stdin);
ready[cg].gen=ganti2;
printf("sukses gender berhasil diganti menjadi %c ",ready[cg].gen);
    getchar();
    system("cls");
   simpan(); admin();
}else {
system("cls"); goto hey;
}}
if(!gintama){
    printf("Nama tidak terdaftar\n");
    getchar(); system("cls");
    goto hey;
}
}else if(b==3){
    printf("Masukan nama peserta pemilu yang ingin dihapus datanya : ");
    gets(nama);
    for(i=0;i<num;i++){
    if(strcmp(nama,ready[i].name)==0){
    cg=i; gintama=true; break;
    }}
    if(gintama==true){
        while(cg<num){
        ready[cg]=EmptyStruct;
        ready[cg]=ready[cg+1];
        ready[cg+1]=EmptyStruct;
        cg++;
        }
   printf("Berhasil Dihapus");
        num=num-1;
        getchar(); system("cls"); simpan(); admin();
    }
    if(!gintama){
        printf("data tidak ditemukan atau tidak terdapat peserta pemilu dengan nama tersebut \n");
        getchar(); system("cls"); admin();
    }
}else if(b==4){
    printf("Uh she up bye-bye"); delay(2); simpan(); return 0;
}else{
system("cls"); goto hey;
}
}

int capel(){
int b,i,cg,pil; char umur; char nama1[100],nama2[100],ganti[100],ganti2;
int gintama;
hey:
printf("Menu Calon pemilu\n");
printf("1. Tambah Data Calon Pemilu\n");
printf("2. Edit Data Calon Pemilu\n");
printf("3. Hapus Data calon Pemilu\n");
printf("4. Simpan dan Exit\n");
printf(" : ");
scanf("%d",&b);fflush(stdin); system("cls");
if(b==1){
    printf("masukan Nama calon Pemilu : ");
    gets(read2[num2].nama);
    printf("masukan partai pengusung : ");
    gets(read2[num2].party);
    printf("sukses");
    getchar();
    num2=num2+1;
     system("cls");
    simpan(); admin();
}else if(b==2){
printf("Masukan nama calon pemilu yang ingin diganti data nya : ");
gets(nama1);
for(i=0;i<num2;i++){
if(strcmp(nama1,read2[i].nama)==0){
 gintama=1; cg=i; break;
}}
if(gintama==1){
    printf("1. ganti nama\n");
    printf("2. ganti partai\n");
    printf("3. ganti nama dan party\n");
    printf("masukan nomor menu pilihan : ");
    scanf("%d",&pil); fflush(stdin);
    switch(pil){
    case 1 : printf("Masukan data nama baru : "); gets(nama1);
            strcpy(read2[cg].nama,nama1);
            printf("data sukses diganti"); getchar(); system("cls"); simpan();
            admin(); break;
    case 2 : printf("masukan data party bary : ");gets(nama2);
            strcpy(read2[cg].party,nama2); getchar(); system("cls"); simpan();
            admin();break;
    case 3 : printf("Masukan data nama baru : "); gets(nama1);
            printf("masukan data party bary : ");gets(nama2);
            strcpy(read2[cg].party,nama2); getchar();
            strcpy(read2[cg].nama,nama1); printf("data diubah"); getchar(); system("cls");simpan();
            admin();break;
    default : system("cls"); admin(); break;
    }
    system ("cls"); admin();
}else if(gintama!=1){
    printf("tidak ditemukan nama calon pemilu yang dicari\n"); getchar();
    system("cls"); goto hey;
}

}else if(b==3){
        printf("masukan nama calon pemilu yang ingin dihapus datanya: ");
        gets(nama1);
        for(i=0;i<num2;i++){
if(strcmp(nama1,read2[i].nama)==0){
 gintama=1; cg=i; printf("Data kana dihapus\n"); getchar(); system("cls"); break;
        }}
        if(gintama==1){
            while(cg<=num2){
            read2[cg]=EmptyStruct2;
            read2[cg]=read2[cg+1];
            read2[cg+1]=EmptyStruct2;
            cg++;
            }
            num2=num2-1;
            simpan();
        }else if(gintama!=1){
            printf("calon pemilu tidak ditemukan\n");
            getchar();
            system("cls");
            goto hey;
        }

}else if(b==4){
simpan(); main();
}
else{
    system("cls"); goto hey;
}}















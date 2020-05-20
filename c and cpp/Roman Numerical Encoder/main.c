#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0;
void predigit(char *yeahdude,char a,char b){
    yeahdude[i++]=a;
    yeahdude[i++]=b;
free(yeahdude);
}
void postdigit(char *yeahdude,char a,int n){
for(int y=0;y<n;y++){
    yeahdude[i++]=a;
}
free(yeahdude);
}
const char* solution(int n) {
char romanEmpire[1000]="";
char dude[1000]="";
  while(n>0){
    if(n>=1000){
            postdigit(romanEmpire,'M',n/1000);
            n-=(n/1000) * 1000;
    }else if(n>=500){
        if(n<900){
            postdigit(romanEmpire,'D',n/500);
            n-=(n/500)*500;
        }
        else{
            predigit(romanEmpire,'C','M');
            n-=900;
        }

    }else if(n>=100){
        if(n<400){
            postdigit(romanEmpire,'C',n/100);
            n-=(n/100)*100;
        }
        else {
            predigit(romanEmpire,'C','D');
            n-=400;
        }
    }else if(n>=50){
        if(n<90){
            postdigit(romanEmpire,'L',n/50);
            n-=(n/50)*50;
        }
        else{
            predigit(&romanEmpire,'X','C');
            n-=90;
        }
    }
    else if(n>=10){
            if(n<40){
                postdigit(romanEmpire,'X',n/10);
                n-=(n/10)*10;
            }
            else{
                predigit(romanEmpire,'X','L');
                n-=40;
            }
    }
    else if(n>5){
            if(n-5==4){
                predigit(romanEmpire,'I','X');
                n-=9;
                }else{
                    postdigit(romanEmpire,'V',(n-5));
                    n-=5;
                    continue;
                    }
    }else if(n==5){
        romanEmpire[i]='V';
        n-=5;
        }
  }
  strncpy(dude,romanEmpire,1000);
    return dude;
}
int main(){
    int number;
  printf("Masukan angka : ");
    scanf("%d",&number);
    fflush(stdin);
    char dudeyeah[1000];
    printf("%s",solution(number));

return 0;
}

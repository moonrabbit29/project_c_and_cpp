#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

static const char* angka[]={"one","two","three","four","five","six","seven","eight","nine"};

void check(int c,int d){
    int kind,i,ind;
    for(i=c;i<=d;i++){
    ind=(i<=9?i-1:c);
    kind=i%2;
     if(i<=9) printf("%s\n",angka[ind]);
    else {
        kind!=1?printf("even\n"):printf("odd\n");
        }
    }
};

int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	check(a,b);
    return 0;
}


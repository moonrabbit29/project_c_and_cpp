#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num)
{
int i=2,flag=1;
  while(flag=1&&i<num){
    if(num%i==0){
        if(num!=2)
          return false;
    }
    i++;
  }
  if(num>1)
  return true;
  else return false;
}

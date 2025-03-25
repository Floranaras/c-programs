#include <stdio.h>

int main(){
  
  int sum(int n){
    if (n > 1){
      return n + sum(n-1)''
    }
    else {
        return 1;
    }
  }

  return 0;
}

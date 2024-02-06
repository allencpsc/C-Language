#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int** arr = malloc(sizeof(int*) * 3);
  int i;
  for (i = 0; i <3; i++){
    arr[i] = malloc(sizeof(int) * 3);
  }
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  for (i=0; i < 3; i++){
    free(arr[i]);
      arr[i] = NULL;
  }
  free(arr);
  arr = NULL;
  return 0;
}
  

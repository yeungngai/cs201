#include<stdlib.h>
#include<stdio.h>


int count_ones(unsigned int num){
  int ones = 0;

  while (num  !=  0) {
    if (num  &  ~((~0U >> 1)) )
      ones++;
    printf("%d\n", num);
    num  >>=  1;
    // printf("%d\n", num);
  }
  return ones;
}




int main ()
{
    int result;

    unsigned int num = 50;


    result = count_ones(31);

    printf("\n%d\n", result);

}
#include <stdio.h>
#include "array.h"

int main(void){
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  Mapper increment_address = &increment;
  Array_ptr result = map( number_list , increment_address);
  display(result);

  Predicate is_even_address = &is_even;
  result = filter( number_list , is_even_address);
  display(result);

  Reducer sum_address = &sum;
  int total = reduce(number_list, 0, sum_address);
  printf("the sum is %d\n", total);
  return 0;
}
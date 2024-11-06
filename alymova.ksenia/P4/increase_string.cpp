#include "dynamic_string.h"
#include <cstdlib>
char* alymova::increase_string(char* str, size_t size)
{
  char* str_new = alymova::create(size);
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    str_new[i] = str[i];
  }
  free(str);
  return str_new;
}

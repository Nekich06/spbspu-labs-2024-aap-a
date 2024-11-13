#include "resizeString.hpp"
#include <cstdlib>
#include <new>

char* maslovskiy::resizeString(const char *str, size_t strSize, size_t iterSize)
{
  char *resized = static_cast<char*>(malloc(sizeof(char) * (strSize + iterSize + 1)));
  if (resized == nullptr)
  {
    throw std::bad_alloc();
  }
  for (size_t i = 0; i < strSize; ++i)
  {
    resized[i] = str[i];
  }
  resized[strSize + iterSize] = '\0';
  return resized;
}

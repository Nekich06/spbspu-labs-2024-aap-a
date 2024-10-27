#include "petrov_namespace.hpp"
#include <iostream>

int main()
{
  double start = 0.0, end = 0.0;
  size_t max = 0;
  std::cin >> start >> end >> max;
  if (!std::cin)
  {
    std::cerr << "ERROR:Invalid value\n";
    return 1;
  }
  if (start < -1.0 || start > 1.0 || end < -1.0 || end > 1.0 || start > end)
  {
    std::cerr << "ERROR:Invalid range\n";
    return 1;
  }
  const double abs_error = 0.1;
  const double step = 0.05;
  std::cout.precision(6);
  std::cout << std::fixed;
  for (auto i = start; i < end; i += step)
  {
    std::cout << i;
    std::cout << " ";
    try
    {
      std::cout << petrov::calculateByTailor(i, max, abs_error);
    }
    catch (const std::logic_error & e)
    {
      std::cout << "<MATH_ERROR>";
    }
    std::cout << " ";
    std::cout << petrov::calculateBySTD(i);
    std::cout << "\n";
  }
  std::cout << end;
  std::cout << " ";
  try
  {
    std::cout << petrov::calculateByTailor(end, max, abs_error);
  }
  catch (const std::logic_error & e)
  {
    std::cout << "<MATH_ERROR>";
  }
  std::cout << " ";
  std::cout << petrov::calculateBySTD(end);
  std::cout << "\n";
}
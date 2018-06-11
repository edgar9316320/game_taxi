#include <iostream>
#include "taxi.h"
#include <memory>


int main()
{

  std::shared_ptr<taxi> mijuego(new taxi());
  mijuego->run();

  return 0;
}

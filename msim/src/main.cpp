#include <iostream>
#include <cstdio>

#include "programloader.hpp"
#include "processor.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "usage: ./start <program_name>.s" << std::endl;
    exit(EXIT_FAILURE);
  }

  char *program_name = argv[1]; 
  uint8_t *program;
  int size = load_program(program_name, &program);

  Memory imem(256); imem.copy(0, program, size);
  Memory dmem(256);
  //std::cout << imem << std::endl << std:: endl << dmem << std::endl;

  Processor cpu(imem, dmem);
  Processor n_cpu(imem, dmem);

  const int limit = 600;
  for (int i = 0; i < limit; ++i)
  {
//    if (i % 5 == 0)
//      std::cout << "(t = " << i << ") " << cpu << std::endl;
    cpu.tick(n_cpu);
  }
  std::cout << "(t = " << limit << ") " << cpu << std::endl;

  std::cout << dmem << std::endl;

  return 0;
}

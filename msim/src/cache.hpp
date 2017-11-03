#ifndef CACHE_H
#define CACHE_H

#include "instruction.hpp"

class ICache
{
  public:
    ICache(Instruction *program, int size);
    ~ICache();
    Instruction operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const ICache& icache);

  private:
    Instruction *program;
    int size;
};
std::ostream& operator<<(std::ostream& os, const ICache& icache);

class DCache
{
  public:
    DCache(int size);
    DCache(int *data, int size);
    ~DCache();
    int& operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const DCache& dcache);

  private:
    int *data;
    int size;  
};
std::ostream& operator<<(std::ostream& os, const DCache& dcache);

#endif

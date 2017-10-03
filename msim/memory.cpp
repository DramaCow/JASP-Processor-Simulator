#include "memory.hpp"
#include <cstring>

#define WORD(b0,b1,b2,b3) (b0 | b1 << 8 | b2 << 16 | b3 << 24)

Memory::Memory(int capacity) :
  capacity(capacity)
{
  bytes = new uint8_t[capacity]();
}

uint32_t Memory::operator[](int a)
{
  //uint32_t word =
  //  bytes[addr+0] << 8 * 0 |
  //  bytes[addr+1] << 8 * 1 |
  //  bytes[addr+2] << 8 * 2 |
  //  bytes[addr+3] << 8 * 3;

  uint32_t word = WORD(bytes[a+0], bytes[a+1], bytes[a+2], bytes[a+3]);

  return word;
}

void Memory::copy(int offset, uint8_t *bytes, int size)
{
  memcpy(&this->bytes[offset], bytes, size);
}

std::ostream& operator<<(std::ostream& os, const Memory& mem)
{
  for (int a = 0; a < mem.capacity; a+=4)
  {
    os << std::hex << WORD(mem.bytes[a+0], mem.bytes[a+1], mem.bytes[a+2], mem.bytes[a+3]) << ' ';
  }
  return os;
}

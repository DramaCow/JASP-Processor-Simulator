#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "memory.hpp"
#include "registerfile.hpp"
#include "alu.hpp"

class Processor
{
  public:
    Processor(Memory &imem, Memory &dmem);
    friend std::ostream& operator<<(std::ostream& os, const Processor& cpu);
    void tick();

  private:
    // pipeline state
    enum State { FETCH, DECODE, EXECUTE, WRITEBACK };
    State state;

    // instruction type
    enum InstructionType { RRR, RRI };
    InstructionType itype;

    // memory units (references)
    Memory &imem; // instruction memory
    Memory &dmem; // data memory
    
    // registers
    RegisterFile regfile;
    uint32_t pc;
    uint32_t oreg;

    // execution units
    Alu alu;

    // pipeline functions
    void fetch();
    void decode();
    void execute();
    void writeback();

    // statistics recorders
    int cycles;
    int instructions_executed;
};

std::ostream& operator<<(std::ostream& os, const Processor& cpu);

#endif

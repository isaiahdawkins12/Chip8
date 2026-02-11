#include <stdint.h>

// https://austinmorlan.com/posts/chip8_emulator/ 

typedef struct {
  // Memory holds program instructions, long and short term data. References using addresses in that data
  // With 4096 we have address sapce from 0x000 - 0xFFF
  // 0x000-0x1FFF - Originally reserved for CHIP-8 Interpreter but we only read or write there when 
  // 0x050-0x0A0 - Storage space specifically for 16 the built-in characters (0 through F) that we have to manually put in the memory because the ROMs will be looking for the characters.
  // 0x200-0xFFF - Instructions from the ROM get stored starting at 0x200. Anything else after that space used by the ROM is free game
  uint8_t memory[4096];

  // CPU interacts with the registers V0 to VF, each able to hold any val from 0x00 to 0xFF. 
  // Register VF is a flag used to hold information about results.
  uint8_t registers[16];

  // Used to store memory addresses for use in operations. Use 16 bit because the max memory address 0xFFF is too big for an 8-bit reg.
  uint16_t index_register;

  // Special register that holds the address of the next instructions to execute.
  // Read about how to increment this properly in the link above
  uint16_t program_counter;

  // Order of execution - holds up to 16 PC's (program_counters)
  uint16_t stack[16];

  // Simple index of the stack that points to where the current PC is
  uint8_t stack_ptr;

  // Will implement this at a rate of 60Hz or whatever the cycle clock is - come back to this later
  uint8_t delay_timer;
  
  
} Chip8;

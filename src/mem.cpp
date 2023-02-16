#include "mem_commands.h"
#include <iostream>

int main(int argc, const char **argv) {
  int memloc = 0;
  char command;
  do {
    std::cin.read(&command, 1);
    switch (command) {
    case MEM_READ_COMMAND:
      std::cout.write((char *)&memloc, sizeof(int));
      break;
    case MEM_WRITE_COMMAND:
      std::cin.read((char *)&memloc, sizeof(int));
      break;
    }
  } while (command != MEM_EXIT_COMMAND);
}

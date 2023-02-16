#include "mem_commands.h"
#include "process.h"
#include <iostream>
#include <sys/wait.h>

int main(int argc, const char **argv) {
  // run & interact with the mem process
  Process p("./mem");
  for (int i = 10; i > 0; i--) {
    p.send_byte(MEM_WRITE_COMMAND);
    p.send_int(i);
    p.send_byte(MEM_READ_COMMAND);
    int val = p.take_int();
    std::cout << "val:" << val << std::endl;
  }
  p.send_byte(MEM_EXIT_COMMAND);

  wait(NULL); // waits for all child processes to terminate
}

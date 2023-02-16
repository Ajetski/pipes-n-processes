#include "process.h"
#include <sys/wait.h>
#include <iostream>

#define READ_COMMAND  0
#define WRITE_COMMAND 1
#define EXIT_COMMAND  2

int main(int argc, const char** argv) {
    // run & interact with the mem process
    Process p("./mem");
    for(int i=10; i>0; i--)
    {
        p.send_byte(WRITE_COMMAND);
        p.send_int(i);
        p.send_byte(READ_COMMAND);
        int val = p.take_int();
        std::cout << "val:" << val << std::endl;
    }
    p.send_byte(EXIT_COMMAND);

    wait(NULL); // waits for all child processes to terminate
}


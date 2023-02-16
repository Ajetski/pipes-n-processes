#ifndef PROCESS_H

#include <iostream>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1

struct Process {
    Process(const char* name) {
        if (pipe(parentToChild) == -1) {
            std::cerr << "Unable to create first pipe" << std::endl;
            exit(-1);
        } else if (pipe(childToParent) == -1) {
            std::cerr << "Unable to create second pipe" << std::endl;
            exit(-1);
        }

        child = fork();
        if (child == -1) {
            // handle errors
            std::cerr << "Error forking" << std::endl;
            exit(-1);
        } else if(child == 0) {
            // child process
            close(parentToChild[STDOUT]);
            close(childToParent[STDIN]);
            dup2(parentToChild[STDIN],  STDIN);
            dup2(childToParent[STDOUT], STDOUT);

            char *const args[] = {(char* const) name, NULL};
            execvp(name, args);
        } else {
            // parent proccess
            close(parentToChild[STDIN]);
            close(childToParent[STDOUT]);
         }
    }

    ~Process() {
        close(parentToChild[STDOUT]);
        close(childToParent[STDIN]);
    }

    int take_int() {
        int box;
        read(childToParent[STDIN], (void*) &box, sizeof(int));
        return box;
    }

    void send_int(int i) {
        write(parentToChild[STDOUT], (void*) &i, sizeof(int));
    }

    void send_byte(char i) {
        write(parentToChild[STDOUT], (void*) &i, 1);
    }

private:
    int parentToChild[2],
        childToParent[2];

	pid_t child;
};

#define PROCESS_H
#endif

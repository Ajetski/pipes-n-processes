# Pipes n Processes

A toy project for playing with pthreads in C++

## Compile/Run
Run `bash run.sh`

### How run.sh works
The script compiles all of the `.cpp` files within the `src` folder. The ouptut is
executable files that are placed into an `out` folder. The script has a `DRIVER`
variable that can be changed to pick which exectuable should be used to boostrap
the project. After complition is complete, the driver program is executed.

## Project Structure
```
src            - folder for source code
    cpu.cpp        - driver program. boostraps the application and comunicates with
                     subprocesses via stdio
    mem.cpp        - an in-memory db that stores a single integer
    mem_commands.h - helper file that defines commands for reuse
    process.h      - a class that abstracts away creating a process and
                     comminunicating via read/write syscalls. It exposes public
                     methods that provide similar functionality to a non-buffered
                     Go channel (such as take/send data over the channel)
run.sh         - helper script that compiles and runs the project
README.md      - hey, that's me ;)
.gitignore     - ignore any pesky files. git doesn't need to know about those.
.gitattributes - fix language stats so .h files aren't listed as C on GitHub
```

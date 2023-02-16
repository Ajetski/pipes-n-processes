#include <iostream>

#define READ_COMMAND  0
#define WRITE_COMMAND 1
#define EXIT_COMMAND  2

int main(int argc, const char** argv)
{
	int memloc = 0;
    char command;

	do
	{
	    std::cin.read(&command,1);
		switch(command)
		{
			case READ_COMMAND:
				std::cout.write((char*) &memloc, sizeof(int));
				break;
			case WRITE_COMMAND:
				std::cin.read((char*) &memloc, sizeof(int));
				break;
		}
	} while(command != EXIT_COMMAND);

	return 0;
}

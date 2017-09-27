#include "Anagramfinder.h"

int main(int argc, char *argv[])
{
    Anagramfinder create;
    //commandline argument to function
    // argv will be [1]input & [2]output
    create.findAndWrite(argv[1],argv[2]);
    return 0;
}


#include "libhello.h"

int main(int argc, char **argv){
    int i  = 0;
    for(i = 1; i < argc; i++){
	    printHello(argv[i]);
    }
    return 0;
}
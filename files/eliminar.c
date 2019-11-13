#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char** argv){
    char *archivo = argv[1];
    char *pwd = getcwd(NULL, 0);
    char path1[strlen(archivo)+strlen(pwd)+2];
    sprintf(path1, "%s/%s", pwd, archivo);
    unlink(path1);
}
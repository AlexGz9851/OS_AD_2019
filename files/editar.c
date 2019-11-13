#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv){
    char *patron = argv[1];
    char *nuevaPalabra = argv[2];
    char *archivo = argv[3];

    char current;
    char word[100];
    int i = 0;

    int fd = open(archivo, O_RDONLY);
    int fd2 = open("tmp.txt", O_WRONLY|O_CREAT,0666);

    while(read(fd,&current,1)){
        if(current != ' ') {
            word[i++] = current;
        } else {
            word[i] = '\0';
            
            if(strcmp(word, patron)){
                write(fd2, word, i);
                write(fd2, " ", 1);
            }
            else{
                write(fd2, nuevaPalabra, strlen(nuevaPalabra));
                write(fd2, " ", 1);
            }
            i = 0;
            
        }
    }
    close(fd);
    word[i] = '\0';
    
    if(strcmp(word, patron)){
        write(fd2, word, i);
        write(fd2, " ", 1);
    }
    else{
        write(fd2, nuevaPalabra, strlen(nuevaPalabra));
        write(fd2, " ", 1);
    }

    close(fd);
    close(fd2);

    unlink(archivo);
    link("tmp.txt", archivo);
    unlink("tmp.txt");

    return 0;
}
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char** argv){
    if(argc!=3)
        return -1;
    char *file1 = argv[1];
    char *file2 = argv[2];
    char *pwd = getcwd(NULL, 0);
    char path1[strlen(file1)+strlen(pwd)+2];
    char path2[strlen(file2)+strlen(pwd)+2];
    sprintf(path1, "%s/%s", pwd, file1);
    sprintf(path2, "%s/%s", pwd, file2);

    int fd1 = open(path1, O_RDONLY);
    int fd2 = open(path2, O_CREAT|O_WRONLY, 0666);

    char buff[100];
    int n;
    while((n = read(fd1, buff, 100)) !=0 ) write(fd2, buff, n);

    close(fd1);
    close(fd2);

    return 0;
}
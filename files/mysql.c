#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct full_student{
    char firstName[20];
    char lastName[20];
    int  prisionerId;
    char semester; 
} Student;
void writeStudent(int argc, char ** argv){
    char * fileName = argv[1];
    int fd = open(fileName, O_WRONLY | O_CREAT , 0666);
    for(int i=0;i<5;i++){
        Student myStudent;
        sprintf(myStudent.firstName,"juan%d",i);
        sprintf(myStudent.lastName,"perez%d",i);
        myStudent.prisionerId = ((i*37+i*i*3)<<4)%137 + 4;
        myStudent.semester = (i+1);
        write(fd,  &myStudent, sizeof(Student));
    }
    close(fd);
}
void readStudent(int argc, char ** argv){
    char *fileName = argv[1];
    int fd = open(fileName, O_RDONLY);
    Student myStudent;
    int element = atoi(argv[2]);
    lseek(fd, element*sizeof(Student), SEEK_SET);
    read(fd, &myStudent, sizeof(Student));
    close(fd);
    printf("Student name: %s %s\n", myStudent.firstName, myStudent.lastName);
    printf("Student id: %d, Student semestre %d\n", myStudent.prisionerId, myStudent.semester);
 
}
int main(int argc, char ** argv){
    /*writeStudent(argc,  argv);
    readStudent( argc, argv)*/

    char *fileName = argv[1];
    char *lastName = argv[2];
    char *newLastName = argv[3];
    int fd = open(fileName, O_RDONLY);
    int posElem= -1;

    for(int i=0;i<5;i++){
        Student myStudent;
        read(fd, &myStudent, sizeof(myStudent));
        if(!strcmp(myStudent.lastName, lastName)){
            printf("lo encontre: %s %s\n", myStudent.firstName, myStudent.lastName);
            posElem = i;
            break;
        }
    }
    close(fd);
    
    if(posElem==-1){
        printf("valor no encontrado");
    }else{
        Student myStudent;
        int sizeLastName = sizeof(myStudent.firstName);
        char truncLastName[sizeLastName];
        strncpy(truncLastName, newLastName, sizeLastName);
        int fd = open(fileName, O_WRONLY);
        lseek(fd, posElem*sizeof(Student)+sizeLastName, SEEK_SET);
        write(fd, truncLastName, strlen(truncLastName));
        close(fd);
    }

   return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int source,destination;
char buf[100];
size_t n;
source=open("source.txt",O_RDONLY);
if (source == -1)
{
printf("Source file not found\n");
return 1;
}
destination=open("destination.txt", O_WRONLY | O_CREAT |  O_TRUNC, 0644);
if (destination == -1)
{
printf("Destination file cannot be created\n");
return 1;
}
n=read(source,buf,100);
write(destination,buf,n);
close(source);
close(destination);
printf("File copied successfully\n");
}

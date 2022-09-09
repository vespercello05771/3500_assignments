#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char str[100];
    scanf("%s", str);

    char buf[100];
    int pipefd[2];
    pid_t cpid;
    // on a success the pipe returns 0 else -1
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        // printf("Pipe process failed");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (cpid == 0)
    {
        close(pipefd[0]);                   // closing read fil descriptor
        write(pipefd[1], str, sizeof(str)); // cpid[1] - write
    }
    else
    {
        close(pipefd[1]);                  // closing write file descriptor
        read(pipefd[0], buf, sizeof(str)); // cpid[2] - read
        close(pipefd[0]);                  // closing read file descriptor
    }
    printf("%s %d\n", buf, cpid);
}

#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main() {
    DIR *dir = opendir("/");
    struct dirent *d;
    while ((d = readdir(dir)) != NULL)
        printf("%s\n", d->d_name);
    return 0;
}

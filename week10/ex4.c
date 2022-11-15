#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct Link {
    char* name;
    int inode;
} Link;

int main() {
    Link map[100];
    Link links[100];
    int c = 0;
    int c2 = 0;
    DIR* directory = opendir("tmp");
    FILE* f = fopen("ex4.txt", "a");
    struct dirent *dir;
    struct stat st;
    if (directory == NULL || f == NULL ) {
        printf("Error");
        return 1;
    }
    while ((dir = readdir(directory)) != NULL) {
        char * path = (char*) calloc(100, sizeof(char));
        strcpy(path, "./tmp/");
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..")) {
            strcat(path, dir->d_name);
            stat(path, &st);
            Link p;
            p.inode = st.st_ino;
            p.name = dir->d_name;
            map[c++] = p;
            if (st.st_nlink >= 2) {
                links[c2] = p;
                c2++;
            }
        }
    }
    for(int i = c2 - 1; i >= 0; i--) {
        fprintf(f, "%s —– ", links[i].name);
        for(int j = c - 1; j >= 0; j--) {
            if (links[i].inode == map[j].inode) fprintf(f, "%s", map[j].name);
            if (j > 1) fprintf(f, "%s", ", ");
        }
        fprintf(f, "%s", "\n");
    }
}

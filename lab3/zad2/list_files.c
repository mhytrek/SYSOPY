#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


char buffor[1024];

int main(int argc, char** argv) {

    long long all_sizes = 0;
    DIR* dir = opendir(argv[1]);
    size_t dir_length = strlen(argv[1]);

    memcpy(buffor, argv[1], dir_length);

    struct stat file_stats; 
    struct dirent* next_file = readdir(dir);


    while(next_file != NULL){
        size_t file_name_length = strlen(next_file->d_name);

        memcpy(&buffor[dir_length], next_file->d_name, file_name_length);

        buffor[dir_length + file_name_length] = 0;
        stat(buffor, &file_stats);

        if(!S_ISDIR(file_stats.st_mode)){
            printf("%ld %s\n",file_stats.st_size, next_file->d_name);
            all_sizes += file_stats.st_size;
        }
        next_file = readdir(dir);
    }
    printf("All files: %llu\n", all_sizes);
    return 0;
}
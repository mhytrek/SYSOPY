#include <stdio.h>

void reverse_1(FILE* input_file, FILE* output_file){
    fseek(input_file, -1, SEEK_END);
    long not_reversed = ftell(input_file) + 1;
    while(not_reversed > 0){
        // fwrite((char*)getc(input_file), sizeof(char), 1, output_file);
        fprintf(output_file, "%c", getc(input_file));
        not_reversed--;
        fseek(input_file, -2, SEEK_CUR);
    } 
}


void reverse_1024(FILE* input_file, FILE* output_file){
    fseek(input_file, 0, SEEK_END);
    long not_reversed = ftell(input_file);
    char block[1024];
    while(not_reversed > 0){
        long to_read;
        if(not_reversed > 1024){
            to_read = 1024;
        }
        else{
            to_read = not_reversed;
        }
        fseek(input_file, - to_read, SEEK_CUR);
        size_t bytes_read = fread(block, sizeof(char), to_read, input_file);
        char c;
        for(int i = 0; i < bytes_read/2; i++){
            c = block[i];
            block[i] = block[bytes_read - 1 - i];
            block[bytes_read - 1 - i] = c;
        }
        fwrite(block, sizeof(char), bytes_read, output_file);
        fseek(input_file, -1024, SEEK_CUR);
        not_reversed -= bytes_read;
    }
}


int main(int argc, char** argv) {
    char *type = argv[3];
    int type1 = atoi(type);
    if(argc != 4){
        printf("zła ilość argumentów\n");
    } else if(type1 != 1 && type1 != 1024){
        printf("podaj dobry wariant: 1/1024\n");
    };
    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");
    if(type1 == 1){
        reverse_1(input_file, output_file);
    } else if(type1 == 1024){
        reverse_1024(input_file, output_file);
    };
    fclose(input_file);
    fclose(output_file);
}
#include <stdio.h>
#include <stdlib.h>

int STRINGLENGTH = 9;

int detect_dupe(char string[STRINGLENGTH]){
    for (int idx = 0; idx < STRINGLENGTH ; idx++){
        for (int jdx = idx+1; jdx < STRINGLENGTH; jdx++){
            if (string[idx] == string[jdx]){
                return 1;
            }
        }
    }
    return 0;
}

int itoa(int integer, char * buffer, size_t size){
    for (int idx = 0; idx < size; idx++){
        buffer[idx] = '0';
    }
    switch(size){
        case 1:
            return sprintf(buffer, "%01i", integer);
            break;
        case 2:
            return sprintf(buffer, "%02i", integer);
            break;
        case 3:
            return sprintf(buffer, "%03i", integer);
            break;
    }
    return 0;
}

int main(){
    int thousands = 0;
    int seconds = 0;
    int minutes = 0;
    int hours = 1;

    int tries = 0;
    int successes = 0;
    while (hours < 10){
        thousands++;
        if (thousands > 999){
            thousands = 0;
            seconds++;
        }
        if (seconds > 59){
            seconds = 0;
            minutes++;
        }
        if (minutes > 59){
            minutes = 0;
            hours++;
        }
        char string[STRINGLENGTH];
        itoa(hours,string,1);
        itoa(minutes,&string[1],2);
        itoa(seconds,&string[3],2);
        itoa(thousands,&string[5],3);

        tries++;
        if (!detect_dupe(string)){
            // printf("%s\n", string);
            successes++;
        }
    }
    printf("tries: %i\n", tries);
    printf("successes: %i\n", successes);
    double percentage = ((double) successes / (double) tries) * 100;
    printf("percentage: %.12lf%%\n", percentage);
}
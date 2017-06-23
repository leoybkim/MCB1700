#include <stdio.h>
#include <unistd.h>
#include "fault_injection.h"
#include "redundancy.h"
#include "voting.h"


// global variables
int test_val[] = {1, 100, 10000, 99999, 12345678};
integer_data original_int;
double_data original_double;


int main() {
    // debug tags
    char str_faulty_int[12];
    char str_original_int[12];
    char str_error[12];
    int faulty_int_var;


//RANDOM_FAULT (12345678)
//12345678: 000101111000110010101001110
//12346702: 000101111000110000101001110
//29122894: 001101111000110000101001110
//12345422: 000101111000110000001001110


//STUCK_AT_FAULT (100)
// WRONG
//     100: 000000000000000000001100100
//     612: 000000000000000001001100100
//  131172: 000000000100000000001100100
// 67108964: 100000000000000000001100100
//  262244: 000000001000000000001100100


    int mode = 2;
    double first;
    double second;
    double third;


    for(int i=0; i<30; i++) {

        switch(mode){
            case 1:
                // test_val[0,1,2] passes
                // test_val[3] failed must be somethnig in 99999999 shit
                // write_integer(test_val[3], &original_int);
                // if (read_integer(&original_int)){
                //    printf("error occured \n");
                //    fault_injection_reset();
                // } else {
                //     printf("fine\n");
                // }

                // TODO: fix!!
                write_double(100, &original_double);
                if (read_double(&original_double)){
                   printf("error occured \n");
                   fault_injection_reset();
                } else {
                   printf("fine\n");
                }

                break;
            case 2:
                first = newton_raphson(1.99, 10);
                second = newton_raphson(1.99, 10);
                third = newton_raphson(1.99, 10);

                if (!( (first == second) || (second == third) || (first == third) )){
                    printf("%f, %f, %f\n", first, second, third);
                } else {
                    printf("fine\n");
                }
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }

        sleep(1);
    }


    return 0;
}

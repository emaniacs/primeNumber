/*
 * prime.c
 * 
 * Copyright 2013 Ardi <noone.nu1@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include "prime.h"
int usage(char *self) {
    fprintf(stdout, "\
%s\n\
Usage:\n\
    %s <options> number\n\
Options:\n\
    -h           show this help.\n\
    -q           quiet mode.\n\
    -g <number>  generate prime number\n\
    -n <number>  find prime number\n\
    -s           char use 'char' as separator. (default is newline).\n\
Return:\n\
    0       if number is prime.\n\
    1       if number is not a prime.\n\
    -1      error\n\
",
self, self);
    return -1;
}

int main(int argc, char *argv[]) {
    // nilai return.
    int ret = 0;

    char *sep = "\n";
    int number = 0;
    int quiet = 0;
    int generate = 0;
    int nth = 0;
    
    // start parsing parameters
    int c;
    while ((c=getopt(argc, argv, "qhngs:")) != -1) {
        switch(c) {
            case 'q':
                quiet = 1; break;
            case 'h':
                return usage(argv[0]); break;
            case 'n':
                nth = 1; break;
            case 'g':
                generate = 1; break;
            case 's':
                sep = optarg; break;
            case '?':
                return -1;
            default:
                abort();
        }
    }

    /*
     * number adalah parameter yang tidak mempunyai opsi
     * ./program 4 maka number adalah 4
     * nilai optind adalah nilai yang digenerate oleh getopt jika parameter 
     * yang diberikan terdaftar, dan parameter yang tidak terdaftar akan dianggap
     * sebagai number.
     * Disini dilakukan casting ke integer.
     */
    if (optind < argc) {
        char *garbage = NULL;
        //number = atoi(argv[optind+1]);
        number = strtol(argv[optind], &garbage, 10);
        //printf("number=%d, garbage=%d\n", number, *garbage);
        if (*garbage != 0)
            number = 0;
    }

    if (number > 1) {
        // cari bilangan prima yang ke number
        if (nth) {
            fprintf(stdout, "%d\n", find_prime(number));
        }
        else if(generate) {
            generate_prime (number, sep);
        }
        else {
            if (its_prime(number) && !quiet){
                fprintf(stdout, "true\n");
            }
            else {
                ret = 1;
                if (! quiet)
                    fprintf(stdout, "false\n");
            }
        }
    }
    else {
        fprintf(stdout, "Please enter valid integer\n");
        return -1;
    }

    return ret;
}

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

int usage(char *self) {
    fprintf(stdout, "%s, This is HELP!!\n", self);
    return -1;
}

int its_prime (int number) {
    // angka 2 pasti bilangan prima
    if (number == 2)
        return 1;

    // bilangan genap bukan bilangan prima
    if ((number & 1) == 0)
        return 0;

    // set nilai default
    int start = 3;
    int to = number / 2;

    // looping sampai setengah bilangan, dengan step plus 2
    // misalkan number=27, berarti to=13
    // start akan selalu bilangan ganjil karena step plus 2
    // jika number(27) habis dibagi start(+2) maka bilangan tersebut bukan bilangan prima
    for (; start < to; start+=2) {
        if (number % start == 0) {
            return 0;
        }
    }
    
    // jika sampai sini berarti number adalah bilangan prima
    return 1;
}


int main(int argc, char *argv[]) {
    // nilai return.
    int ret = 0;

    char *sep = "\n";
    int number = 0;
    int quiet = 0;
    int generate = 0;
    int nth = 0;
    int help = 0;
    
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
                return 1;
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
            int x = 0, y = 1;
            while(x<number) {
                y++;
                if (its_prime(y))
                    x++;
            }
            if (! quiet) {
                fprintf(stdout, "%d\n", y);
            }
        }
        else if(generate) {
            int x = 0, y = 2;
            for (; x<number; y++) {
                if (its_prime(y)) {
                    fprintf(stdout, "%d", y);
                    x++;
                    if (x<number)
                        fprintf(stdout, "%s", sep);
                }
            }
            fprintf(stdout, "\n");
        }
        else {
            if (its_prime(number)) {
                if (!quiet)
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

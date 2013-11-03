/*
 * prime.h
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

int find_prime(int number) {
    int x = 0, prime = 1;
    while(x<number) {
        prime++;
        if (its_prime(prime))
            x++;
    }
    return prime;
}

void generate_prime(int number, char *separator) {
    int loop = 0, prime = 2;
    for (; loop < number; prime++) {
        if (its_prime(prime)) {
            fprintf(stdout, "%d", prime);
            loop++;
            if (loop < number)
                fprintf(stdout, "%s", separator);
        }
    }
    fprintf(stdout, "\n");
}

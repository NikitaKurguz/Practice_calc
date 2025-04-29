#pragma once
#ifndef FRACTION_H
#define FRACTION_H

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction create_fraction(int num, int den);
Fraction add_fractions(Fraction a, Fraction b);
Fraction subtract_fractions(Fraction a, Fraction b);
Fraction multiply_fractions(Fraction a, Fraction b);
Fraction divide_fractions(Fraction a, Fraction b);
int compare_fractions(Fraction a, Fraction b);
Fraction simplify_fraction(Fraction f);
double to_decimal(Fraction f);
void print_fraction(Fraction f);

void display_main_menu();
int input_fraction(Fraction* f);
void fraction_calculator_run();

#endif

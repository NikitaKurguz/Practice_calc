#ifndef FUNCTION_GRAPHER_H
#define FUNCTION_GRAPHER_H

#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>

using namespace std;

// Константы окна
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int GRAPH_MARGIN = 10;

// Структуры для хранения параметров функций
struct Polynomial {
    double* coefficients;
    int degree;
};

struct FunctionParams {
    double a, b, c, d;
};

// Глобальные переменные SDL
extern SDL_Window* window;
extern SDL_Renderer* renderer;

// Прототипы функций
bool initSDL();
bool createSDLWindow();
void closeSDL();
void drawFunction(double (*func)(double), double xMin, double xMax, SDL_Color color);
double findRoot(double (*func)(double), double a, double b, double epsilon);
void findExtremes(double (*func)(double), double a, double b, double& min, double& max);
double calculateIntegral(double (*func)(double), double a, double b, int n);
void Menu();
int FunctionType();
Polynomial inputPolynomial();
FunctionParams inputFunctionParams();
double currentFunction(double x);

// Функции проверки ввода
double getNumber(const string& prompt);
int getMenuChoice(int min, int max, const string& prompt = "");

// Математические функции
double polynomial(double x, const Polynomial& poly);
double powerFunction(double x, const FunctionParams& params);
double exponentialFunction(double x, const FunctionParams& params);
double logarithmicFunction(double x, const FunctionParams& params);
double sineFunction(double x, const FunctionParams& params);
double cosineFunction(double x, const FunctionParams& params);

// Глобальные переменные для текущей функции
extern Polynomial currentPoly;
extern FunctionParams currentParams;
extern int currentFunctionType;

#endif // FUNCTION_GRAPHER_H
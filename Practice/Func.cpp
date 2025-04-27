#include "Func.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Polynomial currentPoly;
FunctionParams currentParams;
int currentFunctionType = 0;

double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.good()) {
            cin.ignore(1000, '\n');
            return number;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка! Введите число.\n";
    }
}

int getMenuChoice(int min, int max, const string& prompt) {
    int choice;
    while (true) {
        if (!prompt.empty()) cout << prompt;

        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(1000, '\n');
            return choice;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Неверный выбор! Введите число от " << min << " до " << max << ".\n";
    }
}

double polynomial(double x, const Polynomial& poly) {
    double result = 0;
    for (int i = 0; i <= poly.degree; i++) {
        result += poly.coefficients[i] * pow(x, i);
    }
    return result;
}

double powerFunction(double x, const FunctionParams& params) {
    return params.a * pow(x, params.b) + params.c;
}

double exponentialFunction(double x, const FunctionParams& params) {
    return params.a * pow(params.b, params.c * x) + params.d;
}

double logarithmicFunction(double x, const FunctionParams& params) {
    return params.a * log(params.b * x) + params.c;
}

double sineFunction(double x, const FunctionParams& params) {
    return params.a * sin(params.b * x + params.c) + params.d;
}

double cosineFunction(double x, const FunctionParams& params) {
    return params.a * cos(params.b * x + params.c) + params.d;
}

double currentFunction(double x) {
    switch (currentFunctionType) {
    case 1: return polynomial(x, currentPoly);
    case 2: return powerFunction(x, currentParams);
    case 3: return exponentialFunction(x, currentParams);
    case 4: return logarithmicFunction(x, currentParams);
    case 5: return sineFunction(x, currentParams);
    case 6: return cosineFunction(x, currentParams);
    default: return 0.0;
    }
}

double calculateIntegral(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }
    return sum * h;
}

bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }
    return true;
}

bool createSDLWindow() {
    window = SDL_CreateWindow("Function Grapher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        return false;
    }

    return true;
}

void closeSDL() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void drawFunction(double (*func)(double), double xMin, double xMax, SDL_Color color) {
    double yMin, yMax;
    findExtremes(func, xMin, xMax, yMin, yMax);

    double yPadding = 0.1 * (yMax - yMin);
    yMin -= yPadding;
    yMax += yPadding;

    double xScale = (SCREEN_WIDTH - 2 * GRAPH_MARGIN) / (xMax - xMin);
    double yScale = (SCREEN_HEIGHT - 2 * GRAPH_MARGIN) / (yMax - yMin);

    int zeroX = GRAPH_MARGIN + (-xMin) * xScale;
    int zeroY = SCREEN_HEIGHT - GRAPH_MARGIN - (-yMin) * yScale;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    double prevX = xMin;
    double prevY = func(prevX);
    int prevScreenX = GRAPH_MARGIN;
    int prevScreenY = SCREEN_HEIGHT - GRAPH_MARGIN - (prevY - yMin) * yScale;

    for (int px = 0; px <= SCREEN_WIDTH - 2 * GRAPH_MARGIN; px++) {
        double x = xMin + px * (xMax - xMin) / (SCREEN_WIDTH - 2 * GRAPH_MARGIN);
        double y = func(x);

        if (isnan(y) || isinf(y)) continue;

        int screenX = GRAPH_MARGIN + (x - xMin) * xScale;
        int screenY = SCREEN_HEIGHT - GRAPH_MARGIN - (y - yMin) * yScale;

        screenY = max(GRAPH_MARGIN, min(SCREEN_HEIGHT - GRAPH_MARGIN, screenY));

        if (px > 0 && !isnan(prevY) && !isinf(prevY)) {
            SDL_RenderDrawLine(renderer, prevScreenX, prevScreenY, screenX, screenY);
        }

        prevScreenX = screenX;
        prevScreenY = screenY;
        prevY = y;
    }


    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer,
        GRAPH_MARGIN, zeroY,
        SCREEN_WIDTH - GRAPH_MARGIN, zeroY);
    SDL_RenderDrawLine(renderer,
        zeroX, GRAPH_MARGIN,
        zeroX, SCREEN_HEIGHT - GRAPH_MARGIN);
}
double findRoot(double (*func)(double), double a, double b, double epsilon) {
    double fa = func(a);
    double fb = func(b);

    if (fa * fb > 0) {
        cout << "Функция не меняет знак на отрезке!" << endl;
        return NAN;
    }

    while (fabs(b - a) > epsilon) {
        double c = (a + b) / 2;
        double fc = func(c);

        if (fc == 0) return c;
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }
    return (a + b) / 2;
}

void findExtremes(double (*func)(double), double a, double b, double& min, double& max) {
    const int N = 1000;
    double step = (b - a) / N;

    min = max = func(a);

    for (int i = 1; i <= N; i++) {
        double x = a + i * step;
        double y = func(x);

        if (y < min) min = y;
        if (y > max) max = y;
    }
}

void Menu() {
    cout << "\nМеню:\n"
        << "1. Вычисление определенного интеграла на отрезке\n"
        << "2. Построение графика функции (SDL)\n"
        << "3. Поиск корня Y=0 на отрезке\n"
        << "4. Поиск экстремумов на отрезке\n"
        << "5. Выход\n";
}

int FunctionType() {
    cout << "Выберите тип функции:\n"
        << "1. Полином степени N(a0 + a1*x + a2*x^2 ...)\n2. Степенная: a*x^b+c\n3. Показательная: a*b^(c*x)+d\n"
        << "4. Логарифмическая: a*ln(b*x)+c\n5. Синусоида: a*sin(b*x+c)+d\n6. Косинусоида: a*cos(b*x+c)+d\n";
    return getMenuChoice(1, 6, "Ваш выбор: ");
}

Polynomial inputPolynomial() {
    Polynomial poly;
    poly.degree = getNumber("Введите степень полинома: ");

    while (poly.degree < 0) {
        cout << "Степень не может быть отрицательной!\n";
        poly.degree = getNumber("Введите степень еще раз: ");
    }

    poly.coefficients = new double[poly.degree + 1];
    for (int i = 0; i <= poly.degree; i++) {
        poly.coefficients[i] = getNumber("Введите коэффициент a" + to_string(i) + ": ");
    }
    return poly;
}

FunctionParams inputFunctionParams() {
    FunctionParams params;
    params.a = getNumber("Введите параметр a: ");
    params.b = getNumber("Введите параметр b: ");
    params.c = getNumber("Введите параметр c: ");
    params.d = getNumber("Введите параметр d: ");
    return params;
}

int menu_function() {
    setlocale(LC_ALL, "Russian");
    if (!initSDL()) return 1;

    int choice;
    double a, b, epsilon;
    SDL_Color color = { 0, 255, 0, 255 };

    do {
        Menu();
        choice = getMenuChoice(1, 5, "Выберите действие: ");

        switch (choice) {
        case 1: {
            currentFunctionType = FunctionType();

            if (currentFunctionType == 1) {
                currentPoly = inputPolynomial();
            }
            else {
                currentParams = inputFunctionParams();
            }

            cout << "Введите границы отрезка:\n";
            a = getNumber("Начало (a): ");
            b = getNumber("Конец (b): ");

            while (a >= b) {
                cout << "Ошибка! Начало должно быть меньше конца!\n";
                a = getNumber("Введите a: ");
                b = getNumber("Введите b: ");
            }

            int n = getMenuChoice(1, 10000, "Введите количество разбиений (1-10000): ");
            double result = calculateIntegral(currentFunction, a, b, n);
            cout << "Значение интеграла: " << result << endl;

            if (currentFunctionType == 1) delete[] currentPoly.coefficients;
            break;
        }

        case 2: {
            currentFunctionType = FunctionType();

            if (currentFunctionType == 1) {
                currentPoly = inputPolynomial();
            }
            else {
                currentParams = inputFunctionParams();
            }

            cout << "Введите границы отрезка:\n";
            a = getNumber("Xmin: ");
            b = getNumber("Xmax: ");

            if (currentFunctionType == 4) {
                while (a <= 0) {
                    cout << "Для логарифма X должен быть > 0!\n";
                    a = getNumber("Введите Xmin: ");
                }
            }

            while (a >= b) {
                cout << "Xmin должен быть меньше Xmax!\n";
                a = getNumber("Введите Xmin: ");
                b = getNumber("Введите Xmax: ");
            }

            if (!createSDLWindow()) {
                cout << "Ошибка создания окна!\n";
                if (currentFunctionType == 1) delete[] currentPoly.coefficients;
                break;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            drawFunction(currentFunction, a, b, color);
            SDL_RenderPresent(renderer);

            cout << "График отображен. Закройте окно для продолжения...\n";

            SDL_Event e;
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) quit = true;
                }
                SDL_Delay(100);
            }

            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            renderer = nullptr;
            window = nullptr;

            if (currentFunctionType == 1) delete[] currentPoly.coefficients;
            break;
        }

        case 3: {
            currentFunctionType = FunctionType();

            if (currentFunctionType == 1) {
                currentPoly = inputPolynomial();
            }
            else {
                currentParams = inputFunctionParams();
            }

            cout << "Введите границы отрезка:\n";
            a = getNumber("Начало (a): ");
            b = getNumber("Конец (b): ");

            if (currentFunctionType == 4) {
                while (a <= 0) {
                    cout << "Для логарифма X должен быть > 0!\n";
                    a = getNumber("Введите a: ");
                }
            }

            while (a >= b) {
                cout << "Начало должно быть меньше конца!\n";
                a = getNumber("Введите a: ");
                b = getNumber("Введите b: ");
            }

            epsilon = getNumber("Введите точность (epsilon): ");
            double root = findRoot(currentFunction, a, b, epsilon);

            if (!isnan(root)) {
                cout << "Найден корень: x = " << root << endl;
            }
            else {
                cout << "Корень не найден на данном отрезке" << endl;
            }

            if (currentFunctionType == 1) delete[] currentPoly.coefficients;
            break;
        }

        case 4: {
            currentFunctionType = FunctionType();

            if (currentFunctionType == 1) {
                currentPoly = inputPolynomial();
            }
            else {
                currentParams = inputFunctionParams();
            }

            cout << "Введите границы отрезка:\n";
            a = getNumber("Начало (a): ");
            b = getNumber("Конец (b): ");

            if (currentFunctionType == 4) {
                while (a <= 0) {
                    cout << "Для логарифма X должен быть > 0!\n";
                    a = getNumber("Введите a: ");
                }
            }

            while (a >= b) {
                cout << "Начало должно быть меньше конца!\n";
                a = getNumber("Введите a: ");
                b = getNumber("Введите b: ");
            }

            double min, max;
            findExtremes(currentFunction, a, b, min, max);
            cout << "Минимальное значение: " << min << endl;
            cout << "Максимальное значение: " << max << endl;

            if (currentFunctionType == 1) delete[] currentPoly.coefficients;
            break;
        }

        case 5:
            cout << "Завершение программы...\n";
            break;
        }
    } while (choice != 5);
    closeSDL();
    return 0;
}
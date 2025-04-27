#include "Func.h"

int main(int argc, char* argv[]) {
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
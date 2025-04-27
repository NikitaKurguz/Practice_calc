#include "Func.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    if (!initSDL()) return 1;

    int choice;
    double a, b, epsilon;
    SDL_Color color = { 0, 255, 0, 255 };

    do {
        Menu();
        choice = getMenuChoice(1, 5, "�������� ��������: ");

        switch (choice) {
        case 1: { 
            currentFunctionType = FunctionType();

            if (currentFunctionType == 1) {
                currentPoly = inputPolynomial();
            }
            else {
                currentParams = inputFunctionParams();
            }

            cout << "������� ������� �������:\n";
            a = getNumber("������ (a): ");
            b = getNumber("����� (b): ");

            while (a >= b) {
                cout << "������! ������ ������ ���� ������ �����!\n";
                a = getNumber("������� a: ");
                b = getNumber("������� b: ");
            }

            int n = getMenuChoice(1, 10000, "������� ���������� ��������� (1-10000): ");
            double result = calculateIntegral(currentFunction, a, b, n);
            cout << "�������� ���������: " << result << endl;

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

            cout << "������� ������� �������:\n";
            a = getNumber("Xmin: ");
            b = getNumber("Xmax: ");

            if (currentFunctionType == 4) { 
                while (a <= 0) {
                    cout << "��� ��������� X ������ ���� > 0!\n";
                    a = getNumber("������� Xmin: ");
                }
            }

            while (a >= b) {
                cout << "Xmin ������ ���� ������ Xmax!\n";
                a = getNumber("������� Xmin: ");
                b = getNumber("������� Xmax: ");
            }

            if (!createSDLWindow()) {
                cout << "������ �������� ����!\n";
                if (currentFunctionType == 1) delete[] currentPoly.coefficients;
                break;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            drawFunction(currentFunction, a, b, color);
            SDL_RenderPresent(renderer);

            cout << "������ ���������. �������� ���� ��� �����������...\n";

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

            cout << "������� ������� �������:\n";
            a = getNumber("������ (a): ");
            b = getNumber("����� (b): ");

            if (currentFunctionType == 4) {
                while (a <= 0) {
                    cout << "��� ��������� X ������ ���� > 0!\n";
                    a = getNumber("������� a: ");
                }
            }

            while (a >= b) {
                cout << "������ ������ ���� ������ �����!\n";
                a = getNumber("������� a: ");
                b = getNumber("������� b: ");
            }

            epsilon = getNumber("������� �������� (epsilon): ");
            double root = findRoot(currentFunction, a, b, epsilon);

            if (!isnan(root)) {
                cout << "������ ������: x = " << root << endl;
            }
            else {
                cout << "������ �� ������ �� ������ �������" << endl;
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

            cout << "������� ������� �������:\n";
            a = getNumber("������ (a): ");
            b = getNumber("����� (b): ");

            if (currentFunctionType == 4) {
                while (a <= 0) {
                    cout << "��� ��������� X ������ ���� > 0!\n";
                    a = getNumber("������� a: ");
                }
            }

            while (a >= b) {
                cout << "������ ������ ���� ������ �����!\n";
                a = getNumber("������� a: ");
                b = getNumber("������� b: ");
            }

            double min, max;
            findExtremes(currentFunction, a, b, min, max);
            cout << "����������� ��������: " << min << endl;
            cout << "������������ ��������: " << max << endl;

            if (currentFunctionType == 1) delete[] currentPoly.coefficients;
            break;
        }

        case 5:
            cout << "���������� ���������...\n";
            break;
        }
    } while (choice != 5);

    closeSDL();
    return 0;
}
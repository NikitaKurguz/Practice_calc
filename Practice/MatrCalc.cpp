#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

double** dynMatr(int rows, int cols) {
    double** matr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matr[i] = new double[cols];
    }
    return matr;
}

void freeMatr(double** matr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matr[i];
    }
    delete[] matr;
}

int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
    }
    return value;
}

double getDoubleInput() {
    double value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Пожалуйста, введите число: ";
    }
    return value;
}

double** inputMatrix(int rows, int cols) {
    double** matr = dynMatr(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            matr[i][j] = getDoubleInput();
        }
    }
    return matr;
}

void printMatrix(double** matr, int rows, int cols) {
    cout << "Матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(8) << fixed << setprecision(2) << matr[i][j];
        }
        cout << endl;
    }
}

void menu_matr() {
    double** matr1 = nullptr;
    double** matr2 = nullptr;
    int rows1, cols1, rows2, cols2;
    int choice;

    do {
        cout << "\n=== МАТРИЧНЫЙ КАЛЬКУЛЯТОР ===\n";
        cout << "1. Сложение матриц\n";
        cout << "2. Вычитание матриц\n";
        cout << "3. Умножение матриц\n";
        cout << "4. Умножение матрицы на число\n";
        cout << "5. Транспонирование матрицы\n";
        cout << "6. Определитель матрицы\n";
        cout << "7. Обратная матрица\n";
        cout << "0. Выход\n";
        cout << "Выберите операцию: ";

        choice = getIntInput();

        switch (choice) {
        case 1: {
            cout << "Введите размеры первой матрицы (строки столбцы): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "Введите размеры второй матрицы (строки столбцы): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (rows1 != rows2 || cols1 != cols2) {
                cout << "Ошибка: размеры матриц должны совпадать!\n";
                break;
            }

            cout << "Ввод первой матрицы:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "Ввод второй матрицы:\n";
            matr2 = inputMatrix(rows2, cols2);

            cout << "Результат сложения:\n";
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols1; j++) {
                    cout << setw(8) << fixed << setprecision(2) << matr1[i][j] + matr2[i][j];
                }
                cout << endl;
            }

            freeMatr(matr1, rows1);
            freeMatr(matr2, rows2);
            break;
        }

        case 2: {
            cout << "Введите размеры первой матрицы (строки столбцы): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "Введите размеры второй матрицы (строки столбцы): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (rows1 != rows2 || cols1 != cols2) {
                cout << "Ошибка: размеры матриц должны совпадать!\n";
                break;
            }

            cout << "Ввод первой матрицы:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "Ввод второй матрицы:\n";
            matr2 = inputMatrix(rows2, cols2);

            cout << "Результат вычитания:\n";
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols1; j++) {
                    cout << setw(8) << fixed << setprecision(2) << matr1[i][j] - matr2[i][j];
                }
                cout << endl;
            }


            freeMatr(matr1, rows1);
            freeMatr(matr2, rows2);
            break;
        }

        case 3: {
            cout << "Введите размеры первой матрицы (строки столбцы): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "Введите размеры второй матрицы (строки столбцы): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (cols1 != rows2) {
                cout << "Ошибка: число столбцов первой матрицы должно равняться числу строк второй!\n";
                break;
            }

            cout << "Ввод первой матрицы:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "Ввод второй матрицы:\n";
            matr2 = inputMatrix(rows2, cols2);

            double** result = dynMatr(rows1, cols2);
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols2; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < cols1; k++) {
                        result[i][j] += matr1[i][k] * matr2[k][j];
                    }
                }
            }

            cout << "Результат умножения:\n";
            printMatrix(result, rows1, cols2);

            freeMatr(matr1, rows1);
            freeMatr(matr2, rows2);
            freeMatr(result, rows1);
            break;
        }

        case 4: {
            cout << "Введите размеры матрицы (строки столбцы): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "Ввод матрицы:\n";
            matr1 = inputMatrix(rows1, cols1);

            cout << "Введите число для умножения: ";
            double num = getDoubleInput();

            cout << "Результат умножения:\n";
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols1; j++) {
                    cout << setw(8) << fixed << setprecision(2) << matr1[i][j] * num;
                }
                cout << endl;
            }

            freeMatr(matr1, rows1);
            break;
        }

        case 5: {
            cout << "Введите размеры матрицы (строки столбцы): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "Ввод матрицы:\n";
            matr1 = inputMatrix(rows1, cols1);

            cout << "Транспонированная матрица:\n";
            for (int j = 0; j < cols1; j++) {
                for (int i = 0; i < rows1; i++) {
                    cout << setw(8) << fixed << setprecision(2) << matr1[i][j];
                }
                cout << endl;
            }

            freeMatr(matr1, rows1);
            break;
        }

        case 6: {
            cout << "Введите размер квадратной матрицы (2 или 3): ";
            int size = getIntInput();

            if (size != 2 && size != 3) {
                cout << "Поддерживаются только матрицы 2x2 и 3x3\n";
                break;
            }

            cout << "Ввод матрицы " << size << "x" << size << ":\n";
            matr1 = inputMatrix(size, size);

            if (size == 2) {
                double det = matr1[0][0] * matr1[1][1] - matr1[0][1] * matr1[1][0];
                cout << "Определитель: " << det << endl;
            }
            else {
                double det = matr1[0][0] * (matr1[1][1] * matr1[2][2] - matr1[1][2] * matr1[2][1]) -
                    matr1[0][1] * (matr1[1][0] * matr1[2][2] - matr1[1][2] * matr1[2][0]) +
                    matr1[0][2] * (matr1[1][0] * matr1[2][1] - matr1[1][1] * matr1[2][0]);
                cout << "Определитель: " << det << endl;
            }

            freeMatr(matr1, size);
            break;
        }

        case 7: {
            cout << "Введите размер квадратной матрицы (2 или 3): ";
            int size = getIntInput();

            if (size != 2 && size != 3) {
                cout << "Поддерживаются только матрицы 2x2 и 3x3\n";
                break;
            }

            cout << "Ввод матрицы " << size << "x" << size << ":\n";
            matr1 = inputMatrix(size, size);


            if (size == 2) {
                double det = matr1[0][0] * matr1[1][1] - matr1[0][1] * matr1[1][0];
                if (det == 0) {
                    cout << "Матрица вырожденная, обратной не существует\n";
                    break;
                }

                cout << "Обратная матрица:\n";
                cout << setw(8) << fixed << setprecision(2) << matr1[1][1] / det << " ";
                cout << setw(8) << fixed << setprecision(2) << -matr1[0][1] / det << endl;
                cout << setw(8) << fixed << setprecision(2) << -matr1[1][0] / det << " ";
                cout << setw(8) << fixed << setprecision(2) << matr1[0][0] / det << endl;
            }
            else {
                double det = matr1[0][0] * (matr1[1][1] * matr1[2][2] - matr1[1][2] * matr1[2][1]) -
                    matr1[0][1] * (matr1[1][0] * matr1[2][2] - matr1[1][2] * matr1[2][0]) +
                    matr1[0][2] * (matr1[1][0] * matr1[2][1] - matr1[1][1] * matr1[2][0]);
                if (det == 0) {
                    cout << "Матрица вырожденная, обратной не существует\n";
                    break;
                }

                double** inverse = dynMatr(size, size);

                inverse[0][0] = (matr1[1][1] * matr1[2][2] - matr1[1][2] * matr1[2][1]) / det;
                inverse[0][1] = (matr1[0][2] * matr1[2][1] - matr1[0][1] * matr1[2][2]) / det;
                inverse[0][2] = (matr1[0][1] * matr1[1][2] - matr1[0][2] * matr1[1][1]) / det;

                inverse[1][0] = (matr1[1][2] * matr1[2][0] - matr1[1][0] * matr1[2][2]) / det;
                inverse[1][1] = (matr1[0][0] * matr1[2][2] - matr1[0][2] * matr1[2][0]) / det;
                inverse[1][2] = (matr1[0][2] * matr1[1][0] - matr1[0][0] * matr1[1][2]) / det;

                inverse[2][0] = (matr1[1][0] * matr1[2][1] - matr1[1][1] * matr1[2][0]) / det;
                inverse[2][1] = (matr1[0][1] * matr1[2][0] - matr1[0][0] * matr1[2][1]) / det;
                inverse[2][2] = (matr1[0][0] * matr1[1][1] - matr1[0][1] * matr1[1][0]) / det;

                cout << "Обратная матрица:\n";
                printMatrix(inverse, size, size);

                freeMatr(inverse, size);
            }

            freeMatr(matr1, size);
            break;
        }

        case 0:
            cout << "Выход из матричного калькулятора.\n";
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);
}

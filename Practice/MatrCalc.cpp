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
        cout << "������ �����. ����������, ������� ����� �����: ";
    }
    return value;
}

double getDoubleInput() {
    double value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������ �����. ����������, ������� �����: ";
    }
    return value;
}

double** inputMatrix(int rows, int cols) {
    double** matr = dynMatr(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "������� [" << i << "][" << j << "]: ";
            matr[i][j] = getDoubleInput();
        }
    }
    return matr;
}

void printMatrix(double** matr, int rows, int cols) {
    cout << "�������:\n";
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
        cout << "\n=== ��������� ����������� ===\n";
        cout << "1. �������� ������\n";
        cout << "2. ��������� ������\n";
        cout << "3. ��������� ������\n";
        cout << "4. ��������� ������� �� �����\n";
        cout << "5. ���������������� �������\n";
        cout << "6. ������������ �������\n";
        cout << "7. �������� �������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";

        choice = getIntInput();

        switch (choice) {
        case 1: {
            cout << "������� ������� ������ ������� (������ �������): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "������� ������� ������ ������� (������ �������): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (rows1 != rows2 || cols1 != cols2) {
                cout << "������: ������� ������ ������ ���������!\n";
                break;
            }

            cout << "���� ������ �������:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "���� ������ �������:\n";
            matr2 = inputMatrix(rows2, cols2);

            cout << "��������� ��������:\n";
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
            cout << "������� ������� ������ ������� (������ �������): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "������� ������� ������ ������� (������ �������): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (rows1 != rows2 || cols1 != cols2) {
                cout << "������: ������� ������ ������ ���������!\n";
                break;
            }

            cout << "���� ������ �������:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "���� ������ �������:\n";
            matr2 = inputMatrix(rows2, cols2);

            cout << "��������� ���������:\n";
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
            cout << "������� ������� ������ ������� (������ �������): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "������� ������� ������ ������� (������ �������): ";
            rows2 = getIntInput();
            cols2 = getIntInput();

            if (cols1 != rows2) {
                cout << "������: ����� �������� ������ ������� ������ ��������� ����� ����� ������!\n";
                break;
            }

            cout << "���� ������ �������:\n";
            matr1 = inputMatrix(rows1, cols1);
            cout << "���� ������ �������:\n";
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

            cout << "��������� ���������:\n";
            printMatrix(result, rows1, cols2);

            freeMatr(matr1, rows1);
            freeMatr(matr2, rows2);
            freeMatr(result, rows1);
            break;
        }

        case 4: {
            cout << "������� ������� ������� (������ �������): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "���� �������:\n";
            matr1 = inputMatrix(rows1, cols1);

            cout << "������� ����� ��� ���������: ";
            double num = getDoubleInput();

            cout << "��������� ���������:\n";
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
            cout << "������� ������� ������� (������ �������): ";
            rows1 = getIntInput();
            cols1 = getIntInput();

            cout << "���� �������:\n";
            matr1 = inputMatrix(rows1, cols1);

            cout << "����������������� �������:\n";
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
            cout << "������� ������ ���������� ������� (2 ��� 3): ";
            int size = getIntInput();

            if (size != 2 && size != 3) {
                cout << "�������������� ������ ������� 2x2 � 3x3\n";
                break;
            }

            cout << "���� ������� " << size << "x" << size << ":\n";
            matr1 = inputMatrix(size, size);

            if (size == 2) {
                double det = matr1[0][0] * matr1[1][1] - matr1[0][1] * matr1[1][0];
                cout << "������������: " << det << endl;
            }
            else {
                double det = matr1[0][0] * (matr1[1][1] * matr1[2][2] - matr1[1][2] * matr1[2][1]) -
                    matr1[0][1] * (matr1[1][0] * matr1[2][2] - matr1[1][2] * matr1[2][0]) +
                    matr1[0][2] * (matr1[1][0] * matr1[2][1] - matr1[1][1] * matr1[2][0]);
                cout << "������������: " << det << endl;
            }

            freeMatr(matr1, size);
            break;
        }

        case 7: {
            cout << "������� ������ ���������� ������� (2 ��� 3): ";
            int size = getIntInput();

            if (size != 2 && size != 3) {
                cout << "�������������� ������ ������� 2x2 � 3x3\n";
                break;
            }

            cout << "���� ������� " << size << "x" << size << ":\n";
            matr1 = inputMatrix(size, size);


            if (size == 2) {
                double det = matr1[0][0] * matr1[1][1] - matr1[0][1] * matr1[1][0];
                if (det == 0) {
                    cout << "������� �����������, �������� �� ����������\n";
                    break;
                }

                cout << "�������� �������:\n";
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
                    cout << "������� �����������, �������� �� ����������\n";
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

                cout << "�������� �������:\n";
                printMatrix(inverse, size, size);

                freeMatr(inverse, size);
            }

            freeMatr(matr1, size);
            break;
        }

        case 0:
            cout << "����� �� ���������� ������������.\n";
            break;

        default:
            cout << "�������� �����! ���������� �����.\n";
        }
    } while (choice != 0);
}

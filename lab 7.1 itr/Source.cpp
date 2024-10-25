#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// ������� ������� � ���������� ����� � �������� �������
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            a[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}

// �������� ������� � ������ �������
void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// ��������� ������� � ���� ��������, �� ���������� �������, �� ������ �� �� ���
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] > 0 && (i % 2 != 0 || j % 2 != 0)) {  // ������ �������� � ��������� ���������
                S += a[i][j];
                k++;
                a[i][j] = 0;  // �������� ������� �� ����
            }
        }
    }
}

// ����� ����� ������� �������� �� ������ (�� ������� ������� �� ����������)
void Sort(int** a, const int rowCount, const int colCount) {
    for (int i0 = 0; i0 < rowCount - 1; i0++) {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++) {
            // ���������� �� ������ �������� �� ����������
            if ((a[i1][0] > a[i1 + 1][0]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||
                (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2])) {
                // ���� ����� ������
                for (int j = 0; j < colCount; j++) {
                    int temp = a[i1][j];
                    a[i1][j] = a[i1 + 1][j];
                    a[i1 + 1][j] = temp;
                }
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����
    const int Low = -41;
    const int High = 23;
    const int rowCount = 7;
    const int colCount = 9;

    // �������� ��������� �������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    // ���������, ��������� � ����������
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    int S = 0, k = 0;
    Calc(a, rowCount, colCount, S, k);
    cout << "Sum = " << S << endl;
    cout << "Count = " << k << endl;

    cout << "Matrix after replacing elements with zeros:" << endl;
    Print(a, rowCount, colCount);

    // ���������� �� ���������
    Sort(a, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // ��������� ���'��
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

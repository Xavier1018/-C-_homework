#include<iostream>
using namespace std;

int main()
{
    int count[6] = { 0 }; // ��l�Ƥ@�Ӥj�p�� 6 ����ư}�C�A�Ω�s�x�C�Ӧ��Z���p��
    char choice;

    do {
        int grade;
        cout << "Enter student's grade (0~5): "; // ���ܥΤ��J���Z
        cin >> grade; // Ū���Τ��J�����Z

        if (grade >= 0 && grade <= 5) { // �ˬd���Z�O�_�b�X�k�d��
            count[grade]++; // �p�G�O�X�k�d�򤺪����Z�A�N�������p�ƾ��[ 1
        }
        else {
            cout << "Invalid input. Please enter grade between 0 to 5." << endl; // �p�G��J�����Z���b�d�򤺡A��ܿ��~�T��
        }

        cout << "Do you want to enter another grade? (Y/N): "; // ���ܥΤ�O�_�n�~���J���Z
        cin >> choice; // Ū���Τ᪺���
    } while (choice == 'Y' || choice == 'y'); // �p�G�Τ����~��A�h�~��j��

    cout << "Count:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << count[i] << " grade(s) of " << i << endl; // ��ܨC�Ӧ��Z���p��
    }

    return 0;
}

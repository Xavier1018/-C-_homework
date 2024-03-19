#include<iostream>
using namespace std;

int main()
{
    int count[6] = { 0 }; // 初始化一個大小為 6 的整數陣列，用於存儲每個成績的計數
    char choice;

    do {
        int grade;
        cout << "Enter student's grade (0~5): "; // 提示用戶輸入成績
        cin >> grade; // 讀取用戶輸入的成績

        if (grade >= 0 && grade <= 5) { // 檢查成績是否在合法範圍內
            count[grade]++; // 如果是合法範圍內的成績，將相應的計數器加 1
        }
        else {
            cout << "Invalid input. Please enter grade between 0 to 5." << endl; // 如果輸入的成績不在範圍內，顯示錯誤訊息
        }

        cout << "Do you want to enter another grade? (Y/N): "; // 提示用戶是否要繼續輸入成績
        cin >> choice; // 讀取用戶的選擇
    } while (choice == 'Y' || choice == 'y'); // 如果用戶選擇繼續，則繼續迴圈

    cout << "Count:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << count[i] << " grade(s) of " << i << endl; // 顯示每個成績的計數
    }

    return 0;
}

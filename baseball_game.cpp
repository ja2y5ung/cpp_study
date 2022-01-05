#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    srand((unsigned int)time(0)); // 난수 생성

    int number[9] = {};
    int answer[3] = {};
    int input_num1, input_num2, input_num3;
    int strike, ball;

    // 1. 1~9 1차원 배열 생성
    for (int i = 0; i < 9; ++i)
    {
        number[i] = i + 1;
    }

    // 2. shuffle
    int temp, idx1, idx2;

    for (int i = 0; i < 50; ++i)
    {
        idx1 = rand() % 9;
        idx2 = rand() % 9;        
    
        temp = number[idx1];
        number[idx1] = number[idx2];
        number[idx2] = temp;
    }

    for (int i = 0; i < 3; ++i)
    {
        answer[i] = number[i];
        cout << answer[i] << "\t";
    }
    cout << endl;



    while (true)
    {
        
        cin >> input_num1 >> input_num2 >> input_num3;

        strike = 0;
        ball = 0;

        for (int i = 0; i < 3; ++i)
        {
            if (i == 0 && input_num1 == answer[0])
            {
                strike += 1;
            }
            else if (i != 0 && input_num1 == answer[i])
            {
                ball += 1;
            }

            if (i == 1 && input_num2 == answer[1])
            {
                strike += 1;
            }
            else if (i != 1 && input_num2 == answer[i])
            {
                ball += 1;
            }

            if (i == 2 && input_num3 == answer[2])
            {
                strike += 1;
            }
            else if (i != 2 && input_num3 == answer[i])
            {
                ball += 1;
            }
        }

        cout << strike << " strike  " << ball << " ball" << endl;
        cout << endl;

        if (strike == 3)
        {
            cout << "WIN !!" << endl;
            break;
        }
    } 

    return 0;
}
#include <iostream>
#include <time.h>
#include <conio.h>


using namespace std;

int main()
{
    int starcnt1, starcnt2, starcnt3, starcnt4, bingcnt;

    srand((unsigned int)time(0));

    int inum[25] = {};

    for (int i = 0; i<25; ++i)
    {
        inum[i] = i + 1;
    }


    int itemp, idx1, idx2;

    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 25;
        idx2 = rand() % 25;

        itemp = inum[idx1];
        inum[idx1] = inum[idx2];
        inum[idx2] = itemp;
    }

    while(true)
    {
        system("cls");
        for (int i = 0; i< 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (inum[i * 5 + j] == INT_MAX)
                    cout << "★\t";
                else
                    cout << inum[(5*i)+j] << "\t";
            }
            cout << endl;
        }

        cout << bingcnt << " bingo! " << endl;

        if (bingcnt == 5)
        {
            break;
        }


        int input_num;
        cout << "숫자 입력 : ";
        cin >> input_num;

        if( input_num == 0)
            break;


        for (int i = 0; i<25; ++i)
        {
            if (inum[i] == input_num)
                inum[i] = INT_MAX;
        }

        // 가로 빙고 
        bingcnt = starcnt1 = starcnt2 = starcnt3 = starcnt4 = 0;    
        for (int i = 0; i< 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if( inum[i*5 + j] == INT_MAX)
                    starcnt1 += 1;
            }
            if (starcnt1 == 5)
            {
                bingcnt += 1;
            }
            starcnt1 = 0;
        }

        //세로 빙고
        for (int i = 0; i< 5; ++i)
        {
            for (int j = 0; j < 25; j += 5)
            {
                if( inum[i + j] == INT_MAX)
                    starcnt2 += 1;
            }
            if (starcnt2 == 5)
            {
                bingcnt += 1;
            }
            starcnt2 = 0;
        }

        //왼쪽 대각선
        for (int i = 0; i< 1; ++i)
        {
            for (int j = 0; j < 25; j += 6)
            {
                if( inum[i + j] == INT_MAX)
                    starcnt3 += 1;
            }
            if (starcnt3 == 5)
            {
                bingcnt += 1;
            }
            starcnt3 = 0;
        }

         // 오른쪽 대각선
        for (int i = 0; i< 1; ++i)
        {
            for (int j = 4; j < 21; j += 4)
            {
                if( inum[i + j] == INT_MAX)
                    starcnt4 += 1;
            }
            if (starcnt4 == 5)
            {
                bingcnt += 1;
            }
            starcnt4 = 0;
        }
        



    }

    


    return 0;
}
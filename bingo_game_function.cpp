#include <iostream>
#include <time.h>

#define WIN_BINGO 3

using namespace std;


int* make_board();
int* shuffle_board(int arr[]);
void show_board(int arr[]);
void search_star(int arr[]);
void place_star(int arr[], int input_num);
int count_bingo(int arr[]);


int main()
{
    int num_bingo ;
    srand((unsigned int)time(0));

    int* game_board = shuffle_board(make_board());
    show_board(game_board);

    while(true)
    {
        system("cls");
        search_star(game_board);
        int num_bingo = count_bingo(game_board);
        cout << endl;
        cout << num_bingo << " Bingo!" << endl;

        if(num_bingo == WIN_BINGO)
        {
            cout << "Win!!!" << endl;
            break;
        }

        int input_num;
        cout << "���� �Է� : ";
        cin >> input_num;

        if( input_num == 0)
            break;        

        place_star(game_board, input_num);
    }
    return 0;
}


int* make_board()
{
    // �Լ� ���ο� ������ ���� ������ �ּҸ� �Լ� ������
    // ������ �ȵ�. ���� ������ return�� ���ÿ� �޸𸮿��� ����
    // ����� ������ �ּҸ� �����ؼ� �ȵȴ�.
    // �ذ� ��� : ������ ������ ���� ������ ����� �ش�.
    // ���� ���� ����� ���ϰ� ������ ������ �ٽ� �����Ѵ�.
    static int board[25] = {};

    for(int i = 0; i < 25; ++i)
    {
        board[i] = i + 1;
    }
    return board;
}

int* shuffle_board(int arr[])
{
    int itemp, idx1, idx2;

    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 25;
        idx2 = rand() % 25;

        itemp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = itemp;
    }
    return arr;
}


void show_board(int arr[])
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cout << arr[i * 5 + j] << '\t';
        }
        cout << endl;
    }
}


void search_star(int arr[])
{
    for (int i = 0; i< 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (arr[i * 5 + j] == INT_MAX)
                cout << "��\t";
            else
                cout << arr[(5*i)+j] << "\t";
        }
        cout << endl;
    }
}

void place_star(int arr[], int input_num)
{
    for (int i = 0; i<25; ++i)
    {
        if (arr[i] == input_num)
            arr[i] = INT_MAX;
    }
}

int count_bingo(int arr[])
{
    int bingcnt, starcnt1, starcnt2, starcnt3, starcnt4;
    bingcnt = starcnt1 = starcnt2 = starcnt3 = starcnt4 = 0;

    for (int i = 0; i< 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if( arr[i*5 + j] == INT_MAX)
                starcnt1 += 1;
            if( arr[i + j*5] == INT_MAX)
                starcnt2 += 1;
        }
        if (starcnt1 == 5 || starcnt2 == 5)
        {
            bingcnt += 1;
        }
        starcnt1 = starcnt2 = 0;
    }

    for (int i = 0; i < 25; ++i)
    {
        if (i % 6 == 0)
        {
            if ( arr[i] == INT_MAX )
                starcnt3 += 1;
        }
        if ((i % 4 == 0) && (i != 0) && (i != 24))
        {
            if ( arr[i] == INT_MAX)
                starcnt4 += 1;            
        }
    }
    if (starcnt3 == 5)
        bingcnt += 1;
    if (starcnt4 == 5)
        bingcnt += 1;
        
    starcnt3 = starcnt4 = 0;

    return bingcnt;
}
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;


/*
0 : 벽 
1 : 길
2 : 시작점
3 : 도착점
*/

struct _tagPoint
{
    int x;
    int y;
};

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;


void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos,
    PPOINT pEndpos)
{
    pStartPos->x = 0;
    pStartPos->y = 0;
    
    pEndpos->x = 19;
    pEndpos->y = 19;

    *pPlayerPos = *pStartPos;


    strcpy_s(Maze[0],    "21100000000000000000");
    strcpy_s(Maze[1],    "00111111110000000000");
    strcpy_s(Maze[2],    "00100010011111111100");
    strcpy_s(Maze[3],    "00100010000000000100");
    strcpy_s(Maze[4],    "01100011110001111100");
    strcpy_s(Maze[5],    "01000000001111000000");
    strcpy_s(Maze[6],    "01000000001000000000");
    strcpy_s(Maze[7],    "01101110001111111000");
    strcpy_s(Maze[8],    "00001010000000001000");
    strcpy_s(Maze[9],    "01111011111111111000");
    strcpy_s(Maze[10],   "01000000000000000000");
    strcpy_s(Maze[11],   "01111100000000000000");   
    strcpy_s(Maze[12],   "00000100111111111110");
    strcpy_s(Maze[13],   "01111111100000000010");
    strcpy_s(Maze[14],   "01000000001111111110");
    strcpy_s(Maze[15],   "01111110011000000000");
    strcpy_s(Maze[16],   "00000010010000000000");
    strcpy_s(Maze[17],   "01111110011111000000");
    strcpy_s(Maze[18],   "01000000000001100000");
    strcpy_s(Maze[19],   "11000000000000111113");

}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            if(pPlayerPos->x == j && pPlayerPos->y == i)
                cout << "☆";

            else if (Maze[i][j] == '0')
                cout << "■";
            else if (Maze[i][j] == '1')
                cout << " ";
            else if (Maze[i][j] == '2')
                cout << "★";
            else if (Maze[i][j] == '3')
                cout << "◎";
        }
        cout << endl;
    }
}

void Moveup(char Maze[21][21], PPOINT pPlayerPos)
{
    
    if (pPlayerPos->y - 1 >= 0)
    {
        if(Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
        {
            --pPlayerPos->y;
        }
    }
}

void Movedown(char Maze[21][21], PPOINT pPlayerPos)
{
    if (pPlayerPos->y + 1 < 20)
    {
        if(Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
        {
            ++pPlayerPos->y;
        }
    }
}

void Moveleft(char Maze[21][21], PPOINT pPlayerPos)
{
    if (pPlayerPos->x - 1 > 0)
    {
        if(Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
        {
            --pPlayerPos->x;
        }
    }
}

void Moveright(char Maze[21][21], PPOINT pPlayerPos)
{
    if (pPlayerPos->x + 1 < 20)
    {
        if(Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0')
        {
            ++pPlayerPos->x;
        }
    }
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
    switch(cInput)
    {
    case 'w':
    case 'W':
        Moveup(Maze, pPlayerPos);
        break;
    case 's':
    case 'S':
        Movedown(Maze, pPlayerPos);
        break;
    case 'a':
    case 'A':
        Moveleft(Maze, pPlayerPos);
        break;
    case 'd':
    case 'D':
        Moveright(Maze, pPlayerPos);
        break;
        
    }

}


int main()
{
    char    strMaze[21][21] = {};

    POINT   tPlayerPos;
    POINT   tStartPos;
    POINT   tEndPos;

    SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

    while(true)
    {
        system("cls");

        Output(strMaze, &tPlayerPos);
        cout << "w : 위  s : 아래  a : 왼쪽  d : 오른쪽  q : 종료";
        char    cinput = _getch();

        if(cinput == 'q' || cinput == 'Q')
            break;

        MovePlayer(strMaze, &tPlayerPos, cinput);
    }

    return 0;
}
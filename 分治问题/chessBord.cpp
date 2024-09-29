#include "iostream"
#include <iomanip>

int title =1;
int Chess[128][128];

void chessBoard(int tr, int tc, int dr, int dc,int size)
{
    if(size == 1) 
{
    return;
}
    int t = title++; //L型骨牌号
    int s = size/2; //分割棋盘
    //覆盖左上角子棋盘
    if(dr < tr+s && dc < tc+s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr, tc, dr, dc, s);
    }
    else
    {
        Chess[tr + s - 1][tc + s - 1] = t;
        chessBoard(tr, tc, tr + s -1, tc + s -1, s);
    }
    //覆盖右上角子棋盘
    if(dr < tr + s && dc >= tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr, tc+s, dr, dc, s);
    }
    else
    {
        Chess[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s -1, tc + s, s);
    }
    //覆盖左下角子棋盘
    if(dr >= tr + s && dc < tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr+s, tc, dr, dc, s);
    }
    else
    {
        Chess[tr + s][tc + s - 1] = t;
        chessBoard(tr+s, tc, tr + s, tc + s - 1, s);
    }
    //覆盖右下角子棋盘
    if(dr >= tr + s && dc >= tc + s)
    {
        //特殊方格在此棋盘中
        chessBoard(tr+s, tc+s, dr, dc, s);
    }
    else
    {
        Chess[tr + s][tc + s ] = t;
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}

int main(){
    int size = 16;

    chessBoard(0,0,13,13,size);

    for (int i = 0; i <size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << std::setw(6)<<Chess[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    

}
#include "game.h"

void menu() {
    printf("############################################\n");
    printf("################# 0  paly  #################\n");
    printf("################# 1  exit  #################\n");
    printf("############################################\n");
}
void game() {
    char board[ROW][COL];//存储游戏数据
    initialize(board,ROW,COL);//初始化函数 initialize：初始化棋盘
    dispalyboard(board,ROW,COL);//打印棋盘
    char win = 0;//存储游戏状态
    while (1)//一直循环直到有人胜出或者平局
    {
        palyerMove(board,ROW,COL);//玩家下棋
        dispalyboard(board,ROW,COL);//打印棋盘
        win = isWin(board, ROW, COL);//判断输赢
        if (win != 'c')//返回不是继续游戏就跳出
            break;
        computerMove(board, ROW, COL);//电脑下棋
        dispalyboard(board, ROW, COL);//打印棋盘
        win = isWin(board, ROW, COL);//判断输赢
        if (win != 'c')
            break;
        win = isDogfall(board, ROW, COL);//判断是否平局
        if (win == 'p')
            break;
    }
    if (win=='*')
    {
        printf("玩家赢！\n");
        dispalyboard(board, ROW, COL);//打印棋盘
    }
    else if (win=='#')
    {
        printf("电脑赢！\n");
        dispalyboard(board, ROW, COL);//打印棋盘
    }
    else
    {
        printf("平局！\n");
        dispalyboard(board, ROW, COL);//打印棋盘
    }
}
int main()
{
    int input = 0;
    srand((unsigned)time(NULL));
    do {
        menu();
        printf("请输入>\n");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            game();//game()函数是后续用来实现游戏过程的一个函数
            break;
        case 1:
            printf("退出游戏\n");
            break;
        default:printf("数字无效请重新输入\n");
            break;
        }

    } while (input !=0);//while(input)相当于while(input!=0)只要没进入游戏就会一直循环到进入为止
    return 0;
}
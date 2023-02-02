#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>//rand()、srand()函数都需要该头文件
#include<time.h>//time()函数需要该头文件

void menu()//菜单建立
{
	printf("*******************\n");
	printf("***1.play 2.exit***\n");
	printf("*******************\n");

}

void game()//游戏逻辑设计
{
	//生成随机数
	int i = 0;
	int ret = 0;//定义一个数用来存放随机数(游戏的真正答案)
	int guess = 0; //定义一个数存放玩家的答案
	ret = rand() % 100 + 1;//rand()函数是库函数，作用是生成一个随机数，该数为int类型，范围在0-RAND_MAX之间，RAND_MAX=0x7FFF=32767
	//因为随机数太大了，这里的rand()%100+1是把随机数的范围调整成0-100（0-32767模100的余数在0-99之间(32767%100=67,9999%100=99)），所以还要+1
	//猜数字
	//printf("答案：%d",ret);打印答案
	printf("请输入你的答案\n");

	while (i<5)//给予玩家五次机会
	{
		scanf("%d", &guess);//接收玩家的答案，放在while循环内接收，可以让玩家答错之后继续答题
		if (guess>ret)
		{
			printf("猜大了\n");
			i++;
			printf("你还有%d次机会\n", 5 - i);
		}
		else if (guess<ret)
		{
			printf("猜小了\n");
			i++;
			printf("你还有%d次机会\n", 5 - i);
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
	if (i == 5)//当i循环五次没有中途跳出，表示在游戏过程中玩家没有猜中答案，这时的i刚好为5
	{
		printf("很抱歉，你没能在规定次数内猜中答案\n");
	}
}

int main()
{
	//猜数字游戏，系统生成一个随机数然后去猜这个数字
	//猜大了，系统提示猜大了，猜小了，系统提示猜小了，猜对了提示祝贺
	int select = 0;
	srand((unsigned int)time(NULL));

	do//这里使用do-while是因为游戏进入就需要进行提示，至少执行一次
	{
		menu();//建立一个菜单函数，为游戏提供选项
		printf("请选择是否进行游戏\n");
		scanf("%d", &select);//接收选项
		switch (select)//分支
		{
		case 1://如果选择1
			game();//进行游戏，在game()中建立游戏逻辑
			break;
		case 2:
			printf("退出游戏\n");//如果选择2
			break;
		default://如果输入其他
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (select != 2);//当用户选择了2时，就跳出主循环，结束游戏

	return 0;
}
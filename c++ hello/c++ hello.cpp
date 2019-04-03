// c++ hello.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
//#include "windows.h"
#include "head.h"
#include "A.h"
#include "Solution.h"
int kl(const int e,int b)
{
    const int a = 8;
    char f[a];
    int c;
    int d;
    pp(&b);
    pp(&a);
    pp(&c);
    pp(&d);
    return 5;
}
int g = 5;
int h;
int main()
{
    Solution ss;
    pp("Hello World!");

    vector<int> pre = { 1,2,4,7,3,5,6,8 };
    vector<int> vin = { 4,7,2,1,5,3,8,6 };

    ss.printTree(ss.reConstructBinaryTree(pre, vin));
    int yy = ss.jumpFloorII(2);
    
    while (1)
    {

    }
    //Sleep(sizeof (int));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

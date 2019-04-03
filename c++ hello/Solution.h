#pragma once

#include "head.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution
{
public:
    Solution();
    ~Solution();
public:
#pragma region 二叉树
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[0]);

        if (pre.size() == 2)
        {
            if (pre[0] == vin[0])
            {
                root->right = new TreeNode(pre[1]);
            }
            else
            {
                root->left = new TreeNode(pre[1]);
            }
        }
        else if (pre.size() > 2)
        {
            int index = 0;
            for (int i = 0; i < vin.size(); ++i)
            {
                if (pre[0] == vin[i])
                {
                    index = i;
                    break;
                }
            }

            vector<int> p1(pre.cbegin() + 1, pre.cbegin() + 1 + index);
            vector<int> p2(pre.cbegin() + 1 + index, pre.cend());

            vector<int> v1(vin.cbegin(), vin.cbegin() + index);
            vector<int> v2(vin.cbegin() + index + 1, vin.cend());
            root->left = reConstructBinaryTree(p1, v1);
            root->right = reConstructBinaryTree(p2, v2);
        }
        return root;
    }
    void printTree(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            pp(root->val);
            printTree(root->left);
            printTree(root->right);
        }
    }
#pragma endregion

#pragma region 两个栈实现队列
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int temp = stack2.top();
        stack2.pop();
        return temp;
    }
    stack<int> stack1;
    stack<int> stack2;
#pragma endregion

#pragma region 旋转数组
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (size==0)
        {
            return 0;
        }
        else if (size == 1)
        {
            return rotateArray[0];
        }
        else
        {
            if (rotateArray[0] < rotateArray[size - 1])
            {
                return rotateArray[0];
            }
            for (size_t i = 0; i < size-1; i++)
            {
                if (rotateArray[i] > rotateArray[i + 1])
                {
                    return rotateArray[i + 1];
                }
            }
        }
    }
#pragma endregion

#pragma region 斐波那契数列
    int Fibonacci(int n) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            int n1 = 1;
            int n2 = 0;
            int n0 = 0;
            for (size_t i = 2; i <= n; i++)
            {
                n0 = n1 + n2;
                n2 = n1;
                n1 = n0;
            }
            return n0;
        }

    }
#pragma endregion

#pragma region 跳台阶
    int jumpFloor(int number) {
        if (number <= 0)
        {
            return 0;
        }
        else if (number == 1)
        {
            return 1;
        }
        else
        {
            int n1 = 1;
            int n2 = 1;
            int n0 = 0;
            for (size_t i = 2; i <= number; i++)
            {
                n0 = n1 + n2;
                n2 = n1;
                n1 = n0;
            }
            return n0;
        }
    }
#pragma endregion

#pragma region 变态跳台阶
    int jumpFloorII(int number) {
        return 1 << (--number);
        /*if (number <= 0)
        {
            return 0;
        }
        else if (number == 1)
        {
            return 1;
        }
        else
        {
            int* array = new int[number + 1]{};
            array[0] = 1;
            array[1] = 1;
            for (size_t i = 2; i <= number; i++)
            {
                int n = 0;
                while (++n<=i)
                {
                    array[i] += array[i - n];
                }
            }
            int ret = array[number];
            return ret;
        }*/
    }
#pragma endregion

#pragma region 矩形覆盖
    int rectCover(int number) {
        if (number <= 0)
        {
            return 0;
        }
        else if (number == 1)
        {
            return 1;
        }
        else
        {
            int n1 = 1;
            int n2 = 1;
            int n0 = 0;
            for (size_t i = 2; i <= number; i++)
            {
                n0 = n1 + n2;
                n2 = n1;
                n1 = n0;
            }
            return n0;
        }

    }
#pragma endregion

#pragma region  二进制中1的位数
    int  NumberOf1(int n) {
        int count = 0;
        while (n)
        {
            ++count;
            n=n&n-1;
        }
        return count;
    }
#pragma endregion

#pragma region 数值的整数次方
    double Power(double base, int exponent) {
        if (exponent == 0)
        {
            return 1.0;
        }
        bool max0 = exponent > 0;
        if (!max0)
        {
            exponent = -exponent;
        }

        if (base > -0.0000001&&base < 0.0000001 && !max0)
        {
            return 0.0;
        }

        double ret = base;
        int ex= exponent > 1;
        while (ex)
        {
            ret *= ret;
            ex = ex > 1;
        }

        if (exponent & 1)
        {
            ret *= base;
        }
        return max0 ? ret:1 / ret ;
    }
#pragma endregion

#pragma region 调整数组顺序使奇数位于偶数前面
    void reOrderArray(vector<int> &array) {

        vector<int> odd;
        vector<int> even;
        for (auto var: array)
        {
            if (var & 1)
            {
                odd.push_back(var);
            }
            else
            {
                even.push_back(var);
            }
        }
        array = odd;
        array.insert(array.end(), even.begin(), even.end());

    }
#pragma endregion
       
#pragma region 链表中倒数第k个结点
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k==0)
        {
            return NULL;
        }

        /*int count = 0;
        ListNode* head = pListHead;
        while (head)
        {
            count++;
            head = head->next;
        }
        if (k > count)
        {
            return NULL;
        }
        count = count - k;
        while (count--)
        {
            pListHead = pListHead->next;
        }
        return pListHead;*/

        ListNode* p_ahead = pListHead;
        ListNode* p_after = pListHead;

        while (--k)
        {
            if (!p_ahead->next)
            {
                return NULL;
            }
            p_ahead = p_ahead->next;
        }

        while (p_ahead->next)
        {
            p_ahead = p_ahead->next;
            p_after = p_after->next;
        }
        return p_after;


    }
#pragma endregion

#pragma region 反转链表
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead)
        {
            return NULL;
        }
        ListNode* pre;
        ListNode* next=pHead->next;
        pHead->next = NULL;
        while (next)
        {
            pre = pHead;
            pHead = next;
            next = next->next;
            pHead->next = pre;
        }
        return pHead;
    }
#pragma endregion

#pragma region 合并两个排序的链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1)
        {
            return pHead2;
        }
        if (!pHead2)
        {
            return pHead1;
        }

        ListNode* temp;
        ListNode* ret;
        if (pHead1->val > pHead2->val)
        {
            temp = pHead2;
            pHead2 = pHead1;
            pHead1 = pHead2;
        }

        ret = pHead1;
        while (pHead2)
        {
            if (!pHead1->next)
            {
                pHead1->next = pHead2;
                break;
            }

            if (pHead1->next->val > pHead2->val)
            {
                temp = pHead2;
                pHead2 = pHead2->next;
                temp->next = pHead1->next;
                pHead1->next = temp;
            }
            else
            {
                pHead1 = pHead1->next;
            }
        }
        return ret;
    }
#pragma endregion

#pragma region 树的子结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
        {
            return false;
        }

        bool ret = false;
        if (pRoot1->val == pRoot2->val)
        {
            if (pRoot2->left)
            {
                ret = HasSubtree(pRoot1->left, pRoot2->left);
            }
            else
            {
                ret = true;
            }

            if (ret)
            {
                if (pRoot2->right)
                {
                    ret = HasSubtree(pRoot1->right, pRoot2->right);
                }
                else
                {
                    ret = true;
                }
            }
        }

        if(!ret)
        {
            ret = HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
        return ret;
    }
#pragma endregion

#pragma region 二叉树的镜像
    void Mirror(TreeNode *pRoot) {
        if (!pRoot)
        {
            return ;
        }

        TreeNode * temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        

    }
#pragma endregion

#pragma region 顺时针打印矩阵
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        int y = matrix.size();
        if (y == 0)
        {
            return ret;
        }
        int x = matrix[0].size();
        if (x == 0)
        {
            return ret;
        }

        int up = 0;
        int down = y - 1;
        int left = 0;
        int right = x - 1;

        while (up <= down && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[up][i]);
            }
            if ((++up) > down)
            {
                break;
            }
            for (int i = up; i <= down; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            if ((--right) < left)
            {
                break;
            }
            for (int i = right; i >= left; i--)
            {
                ret.push_back(matrix[down][i]);
            }
            if ((--down) < up)
            {
                break;
            }
            for (int i = down; i >= up; i--)
            {
                ret.push_back(matrix[i][left]);
            }
            left++;
        }
        return ret;
    }
#pragma endregion

#pragma region 包含min函数的栈

#pragma endregion

#pragma region 栈的压入弹出序列

#pragma endregion

#pragma region 从上往下打印二叉树

#pragma endregion

#pragma region 二叉搜索树的后序遍历序列

#pragma endregion

#pragma region 二叉树中和为某一值的路径

#pragma endregion

#pragma region 复杂链表的复制

#pragma endregion

#pragma region 二叉搜索树与双向链表

#pragma endregion

#pragma region 字符串的排列

#pragma endregion

#pragma region 数组中出现次数超过一半的数字

#pragma endregion

#pragma region 最小的K个数

#pragma endregion

#pragma region 连续子数组的最大和

#pragma endregion

#pragma region 整数中1出现的次数（从1到n整数中1出现的次数）

#pragma endregion

#pragma region 把数组排成最小的数

#pragma endregion

#pragma region 丑数

#pragma endregion

#pragma region 第一个只出现一次的字符

#pragma endregion

#pragma region 数组中的逆序对

#pragma endregion

#pragma region 两个链表的第一个公共结点

#pragma endregion

#pragma region 数字在排序数组中出现的次数

#pragma endregion

#pragma region 二叉树的深度

#pragma endregion

#pragma region 平衡二叉树

#pragma endregion

#pragma region 数组中只出现一次的数字

#pragma endregion

#pragma region 和为S的连续正数序列

#pragma endregion

#pragma region 和为S的两个数字

#pragma endregion

#pragma region 左旋转字符串

#pragma endregion

#pragma region 翻转单词顺序列

#pragma endregion

#pragma region 扑克牌顺子

#pragma endregion

#pragma region 孩子们的游戏(圆圈中最后剩下的数)

#pragma endregion

#pragma region 求连续数和

#pragma endregion

#pragma region 不用加减乘除做加法

#pragma endregion

#pragma region 把字符串转换成整数

#pragma endregion

#pragma region 数组中重复的数字

#pragma endregion

#pragma region 构建乘积数组

#pragma endregion

#pragma region 正则表达式匹配

#pragma endregion

#pragma region 表示数值的字符串

#pragma endregion

#pragma region 字符流中第一个不重复的字符

#pragma endregion

#pragma region 链表中环的入口结点

#pragma endregion

#pragma region 删除链表中重复的结点

#pragma endregion

#pragma region 二叉树的下一个结点

#pragma endregion

#pragma region 对称的二叉树

#pragma endregion

#pragma region 按之字形顺序打印二叉树

#pragma endregion

#pragma region 把二叉树打印成多行

#pragma endregion

#pragma region 序列化二叉树

#pragma endregion

#pragma region 二叉搜索树的第k个结点

#pragma endregion

#pragma region 数据流中的中位数

#pragma endregion

#pragma region 滑动窗口的最大值 

#pragma endregion

#pragma region 矩阵中的路径

#pragma endregion

#pragma region 机器人的运动范围

#pragma endregion


       
};


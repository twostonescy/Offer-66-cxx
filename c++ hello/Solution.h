#pragma once

#include "head.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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


    
};


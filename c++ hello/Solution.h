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
#pragma region ������
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

#pragma region ����ջʵ�ֶ���
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

#pragma region ��ת����
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

#pragma region 쳲���������
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

#pragma region ��̨��
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

#pragma region ��̬��̨��
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

#pragma region ���θ���
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

#pragma region  ��������1��λ��
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

#pragma region ��ֵ�������η�
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

#pragma region ��������˳��ʹ����λ��ż��ǰ��
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
       
#pragma region �����е�����k�����
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

#pragma region ��ת����
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

#pragma region �ϲ��������������
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

#pragma region �����ӽṹ
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

#pragma region �������ľ���
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

#pragma region ˳ʱ���ӡ����
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

#pragma region ����min������ջ

#pragma endregion

#pragma region ջ��ѹ�뵯������

#pragma endregion

#pragma region �������´�ӡ������

#pragma endregion

#pragma region �����������ĺ����������

#pragma endregion

#pragma region �������к�Ϊĳһֵ��·��

#pragma endregion

#pragma region ��������ĸ���

#pragma endregion

#pragma region ������������˫������

#pragma endregion

#pragma region �ַ���������

#pragma endregion

#pragma region �����г��ִ�������һ�������

#pragma endregion

#pragma region ��С��K����

#pragma endregion

#pragma region ���������������

#pragma endregion

#pragma region ������1���ֵĴ�������1��n������1���ֵĴ�����

#pragma endregion

#pragma region �������ų���С����

#pragma endregion

#pragma region ����

#pragma endregion

#pragma region ��һ��ֻ����һ�ε��ַ�

#pragma endregion

#pragma region �����е������

#pragma endregion

#pragma region ��������ĵ�һ���������

#pragma endregion

#pragma region ���������������г��ֵĴ���

#pragma endregion

#pragma region �����������

#pragma endregion

#pragma region ƽ�������

#pragma endregion

#pragma region ������ֻ����һ�ε�����

#pragma endregion

#pragma region ��ΪS��������������

#pragma endregion

#pragma region ��ΪS����������

#pragma endregion

#pragma region ����ת�ַ���

#pragma endregion

#pragma region ��ת����˳����

#pragma endregion

#pragma region �˿���˳��

#pragma endregion

#pragma region �����ǵ���Ϸ(ԲȦ�����ʣ�µ���)

#pragma endregion

#pragma region ����������

#pragma endregion

#pragma region ���üӼ��˳����ӷ�

#pragma endregion

#pragma region ���ַ���ת��������

#pragma endregion

#pragma region �������ظ�������

#pragma endregion

#pragma region �����˻�����

#pragma endregion

#pragma region ������ʽƥ��

#pragma endregion

#pragma region ��ʾ��ֵ���ַ���

#pragma endregion

#pragma region �ַ����е�һ�����ظ����ַ�

#pragma endregion

#pragma region �����л�����ڽ��

#pragma endregion

#pragma region ɾ���������ظ��Ľ��

#pragma endregion

#pragma region ����������һ�����

#pragma endregion

#pragma region �ԳƵĶ�����

#pragma endregion

#pragma region ��֮����˳���ӡ������

#pragma endregion

#pragma region �Ѷ�������ӡ�ɶ���

#pragma endregion

#pragma region ���л�������

#pragma endregion

#pragma region �����������ĵ�k�����

#pragma endregion

#pragma region �������е���λ��

#pragma endregion

#pragma region �������ڵ����ֵ 

#pragma endregion

#pragma region �����е�·��

#pragma endregion

#pragma region �����˵��˶���Χ

#pragma endregion


       
};


#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <string.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char d = char()):data(d),left(NULL),right(NULL){}
};

class Tree
{
    public:
    Tree():root(NULL){}
    void Create(char *LVR,char *LRV)
    {
        int n = strlen(LRV);
        Create(root,LVR,LRV,n);
    }
    void PrintfV()//����
    {
        Node *t = root;
        if(t==NULL)return;
        stack<Node*> st;
        while(t!=NULL || st.empty()==false)
        {
                while(t!=NULL)
                {
                    st.push(t);
                    t=t->left;
                }
                t = st.top();
                st.pop();
                cout<<t->data<<"  ";
                t=t->right;
        }
        cout<<endl;
    }
    void PrintfR()//����
    {
        Node *t = root;
        if(t==NULL)return;
        stack<Node*> st;
        map<Node*,bool> mp;//test visted����¼�Ƿ��Ѿ�������
        while(1)
        {
                while(t!=NULL && mp.find(t->left)==mp.end())
                {   
                    st.push(t);
                    t=t->left;
                }
                t = st.top();
                if(t->right==NULL)
                {   
                      cout<<t->data<<"  ";
                        mp.insert(pair<Node*,bool>(t,true));
                        st.pop();
                        t = st.top();
                        continue;
                }
                if(mp.find(t->right)==mp.end()&&t->right!=NULL)
                {//��ѯ�Ƿ��Ѿ�����map�У���Ȼ��Ч������ֱ�ۡ�
                    t=t->right;
                    continue;
                }
                if(mp.find(st.top())==mp.end())
                {
                    cout<<st.top()->data<<"  ";
                    mp.insert(pair<Node*,bool>(t,true));
                    st.pop();
                    if(st.size()>0)
                    t = st.top();
                }
            if(st.empty()!=false)break;
        }
        cout<<endl;
    }

    void PrintfL()//ǰ��
    {
        Node *t = root;
        if(t==NULL)return;
        stack<Node*> st;
        while(t!=NULL || st.empty()==false)
        {
                while(t!=NULL)
                {
                    cout<<t->data<<"  ";
                    st.push(t);
                    t=t->left;
                }
                t = st.top();
                st.pop();
                t=t->right;
        }
        cout<<endl;
    }
    void Sprintf()//���
    {
        Node *t = root;
        if(t==NULL)return;
        queue<Node*> st;
        st.push(t);
        while(st.empty()==false)
        {
                Node *p = st.front();
                cout<<p->data<<"  ";
                st.pop();
                if(p->left!=NULL)
                {
                    st.push(p->left);
                }
                if(p->right!=NULL)
                {
                    st.push(p->right);
                }
        }
        cout<<endl;
    }
    private:
    void Create(Node *&t,char *LVR,char *LRV,int n)
    {//��������ͺ��������������n��¼��Ϊ��Ǹ�����
        if(n==0)return;
        int i = 0;
        while(LRV[n-1]!=LVR[i])i++;
        t = new Node(LRV[n-1]);
        Create(t->right,LVR+i+1,LRV+i,n-i-1);
        Create(t->left,LVR,LRV,i);
    }
    private:
    Node *root;
};
int main()
{
    char LVR[]="ABCDEFG";
    char LRV[]="GFEDCBA";
    Tree t;
    t.Create(LVR,LRV);
    t.PrintfV();
    t.PrintfL();
    t.PrintfR();    
    t.Sprintf();
    return 0;
}

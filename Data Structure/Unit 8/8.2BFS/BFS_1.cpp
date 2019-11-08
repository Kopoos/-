#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=100;
struct node{
    int x,y;        //位置(x,y)
    int step;       //step为从起点s到达该位置的最小步数(即层数)
}S,T,Node;      //S为起点,T为终点,Node为临时终点

int  n,m;       //n为行，m为列
char maze[maxn][maxn];      //迷宫信息
bool inq[maxn][maxn]={false};       //记录位置(x,y)是否已入过队
int X[4]={0,0,1,-1};        //增量数组
int Y[4]={1,-1,0,0};        

//检测位置(x,y)是否有效
bool test(int x,int y)
{
    if(x>=n||x<0||y>=m||y<0)return false;       //超过边界
    if(maze[x][y]=='*')return false;        //墙壁*
    if(inq[x][y]==true)return false;        //已经入过队
    return true;       //有效位置
}

int BFS(){
    queue<node>q;      //定义队列
    q.push(S);          //将起点s入队
    while(!q.empty())
    {
        node top=q.front();     //取出队首元素
        q.pop();        //队首元素出队
        if(top.x==T.x&&top.y==T.y){
            return top.step;        //终点，直接返回最少步数
        }
        for(int i=0;i<4;i++)
        {//循环4次，得到4个相邻的位置
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            if(test(newX,newY)){
                //位置（newX,newY)有效
                //设置Node的坐标为（newX,newY）
                Node.x=newX,Node.y=newY;
                Node.step=top.step+1;       //node的层数为top的层数加1
                q.push(Node);       //将结点Node入队
                inq[newX][newY]=true;       //设置位置(newX,newY)已入过队
            }

        }
    }
    return -1;      //无法到达终点T时返回-1
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        getchar();      //过滤掉每行后面的换行符
        for(int j=0;j<m;j++)
        {
            maze[i][j]=getchar();
        }
        maze[i][m+1]='\0';
    }
    scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);      //起点和终点的坐标
    S.step=0;       //初始化起点的层数为0，即为S到S的最小步数为0
    printf("%d\n",BFS());
    return 0;  
}
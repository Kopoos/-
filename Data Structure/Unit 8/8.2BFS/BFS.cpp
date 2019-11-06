#include<cstdio>
#include<queue>
using namespace std;
const int maxn=100;
struct node{
    int x,y;        //位置（x,y)
}Node;

int n,m;        //矩阵的大小为n*m
int matrix[maxn][maxn];     //01矩阵
bool inq[maxn][maxn]={false};       //记录位置（x,y)是否已经入过队
int X[4]={0,0,1,-1};        //增量数组
int Y[4]={1,-1,0,0}; 

bool judge(int x,int y){
    //判断坐标(x,y)是否需要访问
    //越界则返回false
    if(x>=n||x<0||y>=m||y<0)return false;
    //当前位置为0，或(x,y)已经入过队，返回false
    if(matrix[x][y]==0||inq[x][y]==true)return false;
    //以上都不满足，则返回true
    return true;
}
//BFS函数访问位置(x,y)所在的块，该块中所有的"1"的inq都设置为true；
void BFS(int x,int y){
    queue<node>Q;        //定义队列,注意定义的是node类型的结构体队列
    Node.x=x;Node.y=y;      //当前结点的坐标为(x,y)
    Q.push(Node);       //将结点Node入队
    inq[x][y]=true;     //设置(x,y)已经入过队
    while(!Q.empty()){
        node top=Q.front();     //取出队首元素
        Q.pop();        //队首元素出队
        for(int i=0;i<4;i++)
        {
            //循环4次，得到4个相邻的位置
            int newX=top.x+X[i];
            int newY=top.y+Y[i];
            if(judge(newX,newY)){
                //如果新位置(newx,newy)需要访问
                //设置Node的坐标为(newx,newy)
                Node.x=newX,Node.y=newY;
                Q.push(Node);       //将结点Node加入队列
                inq[newX][newY]=true;       //设置位置(newx,newy)已入过队
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<m;y++)
        {
            scanf("%d",&matrix[x][y]);      //读入01矩阵
        }
    }
    int ans=0;      //存放块数
    for(int x=0;x<n;x++)
    {
        //枚举每一个位置
        for(int y=0;y<m;y++)
        {   //如果元素为1,且未入队列
            if(matrix[x][y]==1&&inq[x][y]==false){
                ans++;      //块数加1
                BFS(x,y);       //访问整个块，将该块所有的1的inq都标记为true
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}



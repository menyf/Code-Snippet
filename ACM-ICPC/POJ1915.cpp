/*
 深度优先搜索DFS可描述为：
 
 （1）访问v0顶点；
 
 （2）置 visited[v0]=1；
 
 （3）搜索v0未被访问的邻接点w，若存在邻接点w，则DFS(w)。
 
 
 个人理解：
 越来越可以明白，DFS和BFS为什么没有一个模版了。DFS在很多地方都有运用，如最近学的二分图和EdmondsKarp的最大流问题解法，都运用到了DFS。
 
 DFS和BFS是一种思想，而不是一种算法。
 
 搜索背景：
 从一个点出发，有很多分岔口，在每条路的路上又有很多分岔口，最终形成一个树状结构
 
 DFS：
 一条路，一通到底，如果没有达到目的，则返回到最近的分岔口，走另一条路，以此类推
 DFS所蕴含的，是一种递归思想（栈）的表现形式，在搜索（图或者数）这一方面有经典的运用。
 
 BFS：
 先把第一个分岔口，如根结点，从队列取出（先定义一个tmp储存该元素，然后pop出队），然后把这个点标记，以表示该点已访问，然后找这个点的所有子节点（如ABCD），依次取出，放入队列里。此时，对于tmp来讲，这个元素已经没有用了，然后按照ABCD的顺序扫一遍，对每个节点同样执行和对tmp一样的操作。形象一点的说，就是层层扩散
 相比于DFS，BFS是一种队列的思想。如同大大师带着大师，大师带着徒弟，排队演戏，入队，但不演戏，大大师表演完了，大师演戏，大师演完了徒弟再演戏。
 */

#include <stdio.h>
#include "queue"
#include <cstring>
#include "iostream"
using namespace std;
int vis[305][305];
int mx[]={-2,-2,-1,-1,2,2,1,1};
int my[]={1,-1,2,-2,1,-1,2,-2};
int t,sx,sy,ex,ey,l;//sx sy表示开始时的(x,y)坐标
                    //ex ey表示结束时的(x,y)坐标
struct Point{
    int x,y,moves;
};
int go(int x,int y){    //用于控制边界
    return x>=0&&x<l&&y>=0&&y<l;
}
void bfs(){
    memset(vis, 0, sizeof(vis));
    queue<Point> qe;
    qe.push(Point{sx,sy,0});
    while (!qe.empty()) {
        int x=qe.front().x;
        int y=qe.front().y;
        int z=qe.front().moves;
        qe.pop();
        if (x==ex&&y==ey) {
            cout<<z<<endl;
            return;
        }
        for (int j=0; j<8; j++) {
            int tx=x+mx[j];
            int ty=y+my[j];
            if (!vis[tx][ty]&&go(tx, ty)) {
                vis[tx][ty]=1;
                qe.push(Point{tx,ty,z+1});
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        cin>>l>>sx>>sy>>ex>>ey;
        bfs();
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int VM=1010;
const int EM=200010;
const int INF=0x3f3f3f3f;

struct Edge{
    int to,nxt;
    int cap;
}edge[EM<<1];

int N,F,D,cnt,head[VM],src,des;
int dep[VM];

void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;    edge[cnt].cap=cw;   edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
    edge[cnt].to=cu;    edge[cnt].cap=0;    edge[cnt].nxt=head[cv];
    head[cv]=cnt++;
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(dep,-1,sizeof(dep));
    dep[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(edge[i].cap>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[des]!=-1;
}

int DFS(int u,int minx){
    if(u==des)
        return minx;
    int tmp;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(edge[i].cap>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,edge[i].cap)))){
            edge[i].cap-=tmp;
            edge[i^1].cap+=tmp;
            return tmp;
        }
    }
    dep[u]=-1;
    return 0;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(1){
            tmp=DFS(src,INF);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}

int main(){

    //freopen("input.txt","r",stdin);

    char str[220];
    while(~scanf("%d%d%d",&N,&F,&D)){
        cnt=0;
        memset(head,-1,sizeof(head));
        int f,d;
        src=0, des=F+2*N+D+1;
        for(int i=1;i<=F;i++){
            scanf("%d",&f);
            addedge(src,i,f);
        }
        for(int i=F+2*N+1;i<=F+2*N+D;i++){
            scanf("%d",&d);
            addedge(i,des,d);
        }
        for(int i=1;i<=N;i++){
            scanf("%s",str);
            for(int j=0;j<F;j++)
                if(str[j]=='Y')
                    addedge(j+1,F+i,1);
        }
        for(int i=1;i<=N;i++){
            scanf("%s",str);
            for(int j=0;j<D;j++)
                if(str[j]=='Y')
                    addedge(F+N+i,F+2*N+j+1,1);
        }
        for(int i=F+1;i<=F+N;i++)
            addedge(i,i+N,1);
        printf("%d\n",Dinic());
    }
    return 0;
}

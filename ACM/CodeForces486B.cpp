// Wrote by MenYifan on 2015-05-26 09:07:18
// Exe.Time 30ms Exe.Memory 88K
#include<iostream>
using namespace std;
int a[105][105]={},b[100][100]={},m,n;
void setzero(int y,int x){
    for (int i=0; i<n; i++) a[y][i]=0;
    for (int i=0; i<m; i++) a[i][x]=0;
    return;
}
int checkone(int y,int x){
    for (int i=0; i<n; i++)
        if (a[y][i]==1) return 1;
    for (int i=0; i<m; i++)
        if (a[i][x]==1) return 1;
    return 0;
}
int main(){
    int i,j;
    cin>>m>>n;
    for (i=0; i<105; i++)
        for (j=0; j<105; j++)
            a[i][j]=1;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            cin>>b[i][j];
            if (b[i][j]==0)setzero(i,j);
        }
    }
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (b[i][j]==1&&!checkone(i,j)) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            cout<<a[i][j];
            j!=n-1?cout<<" ":cout<<endl;
        }
    }
    return 0;
}
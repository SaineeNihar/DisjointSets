/*
Merging Communities problem HackerRank
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void makeset(int s[],int n)
{
    for(int i=n-1;i>=0;i--)
        s[i]=-1;
}
int find(int s[],int n,int x)
{
    if(!(x>=0 and x<n))
       return INT8_MIN;
    if(s[x]<0)
        return x;
    else return (s[x]=find(s,n,s[x]));
}
void Union(int s[],int n,int r1,int r2)
{
    if(find(s,n,r1)==find(s,n,r2) and find(s,n,r1)!=-1)
        return;
    int pr1=find(s,n,r1),pr2=find(s,n,r2);
    if(s[pr2]<s[pr1])
    {
        s[pr2]+=s[pr1];
        s[pr1]=pr2;
    }
    else
    {
        s[pr1]+=s[pr2];
        s[pr2]=pr1;
    }
}
int main() {
    int n,q;
    cin>>n>>q;
    n++;
    int s[n];
    makeset(s,n);
//    for(int i=0;i<n;i++)
//        cout<<s[i]<<" ";
//    cout<<find(s,n,5);
//   cout<<endl;
    
    while(q)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int x;
            cin>>x;
            cout<<abs(s[find(s,n,x)])<<endl;
        }
        else if(c=='M')
        {
            int x,y;
            cin>>x>>y;
            Union(s,n,x,y);
        //    for(int i=0;i<n;i++)
        //        cout<<s[i]<<"  ";
        //    cout<<endl;
        }
        q--;
    }
    return 0;
}

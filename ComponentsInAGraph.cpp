#include <bits/stdc++.h>
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
/*
 * Complete the componentsInGraph function below.
 */
vector<int> componentsInGraph(vector<vector<int>> gb) 
{
    int size=(gb.size()*2)+1;
    int s[size];
    makeset(s,size);
    for(unsigned int i=0;i<gb.size();i++)
    {
        Union(s,size,gb[i][0],gb[i][1]);
    }
    for(int i=0;i<size;i++)
        cout<<i<<" "<<s[i]<<endl;

    int min=0;
    vector<int> dummy;
    for(int i=1;i<=size;i++)
        if(s[i]<min and s[i]!=-1)
            min=s[i];
    int max=abs(min);
    min=abs(min);
    //cout<<max<<" max-min \n";
        for(int i=1;i<=size;i++)
        if(abs(s[i])<min and s[i]<-1)
        {   
            min=abs(s[i]);
        //    cout<<s[i]<<" ";
        }
       // cout<<"\nMin: "<<min;
    //cout<<endl;
    dummy.push_back(min);
    dummy.push_back(max);
    return dummy;
}

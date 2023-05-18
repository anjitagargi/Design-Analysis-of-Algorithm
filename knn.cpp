#include<iostream>
#include<math.h>
using namespace std;
class coords
{
    public:
    float x;
    float y;
    char gen;
    float dist;
};
float distance(coords a,coords b)
{
    float dist;
    dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return dist;
}
void selectionSort(coords* arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j].dist < arr[min_idx].dist)
            {
                min_idx = j;
            }
        }
        coords temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    coords a,b,c,d,e,action[2],comedy[2],farthest_pointA,farthest_pointC,nearest_pointA,nearest_pointC,centroidA,centroidC;
    int c_A=0,c_C=0;
    a.x=100;
    a.y=5;
    a.dist=distance(a,e);
    a.gen='A';
    b.x=20;
    b.y=90;
    b.dist=distance(b,e);
    b.gen='C';
    c.x=95;
    c.y-15;
    c.dist=distance(c,e);
    c.gen='A';
    d.x=25;
    d.y=110;
    d.dist=distance(d,e);
    d.gen='C';
    cout<<"Enter the no.of action and comedy scenes: ";
    cin>>e.x>>e.y;
    action[0]=a;
    action[1]=c;
    comedy[0]=b;
    comedy[1]=d;
    for(int i=0;i<2;i++)
    {
    centroidA.x=(action[i].x)/2;
    centroidA.y=(action[i].y)/2;
    centroidA.gen='A';
    }
    centroidA.dist=distance(centroidA,e);
    for(int i=0;i<2;i++)
    {
    centroidC.x=(comedy[i].x)/2;
    centroidC.y=(comedy[i].y)/2;
    centroidC.gen='C';
    }
    centroidC.dist=distance(centroidC,e);
    selectionSort(action,2);
    selectionSort(comedy,2);
    nearest_pointA=action[0];
    farthest_pointA=action[1];
    nearest_pointC=comedy[0];
    farthest_pointC=comedy[1];
    if(nearest_pointA.dist>nearest_pointC.dist)
    {
        c_C++;
    }
    else
    {
        c_A++;
    }
    if(farthest_pointA.dist>farthest_pointC.dist)
    {
        c_C++;
    }
    else
    {
        c_A++;
    }
        if(centroidA.dist>centroidC.dist)
    {
        c_C++;
    }
    else
    {
        c_A++;
    }
    if(c_C>c_A)
        cout<<"Comedy";
    else
        cout<<"Action";

}
#include <iostream>
using namespace std;

const int MAXN = 2e5+5;

void f1(int a[],int n)
{
    if(n<0) return;
    a[n] = rand()%100+1;
    f1(a,n-1);
}

void f2(int a[],int k,int n)
{
    if(k==n-1) return;
    for(int i=k+1;i<n;++i)
    {
        if(a[i]<a[k]) 
            swap(a[i],a[k]);
    }
    f2(a,k+1,n);
}

void print(int a[],int n)
{
    for(int i=0;i<n;++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int n; cin >> n;
    int a[MAXN];
    f1(a,n-1);
    print(a,n);
    f2(a,0,n);
    print(a,n);
}
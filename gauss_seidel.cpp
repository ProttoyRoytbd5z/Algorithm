#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,i,j,k,flag=0,cnt=0;//6 variables needed
    cout<<"Enter the number of equations:";//no of equations
    cout<<endl;
    cin>>n;
    double a[n][n+1];//desired matrix dimension
    double var[n];//another array
    double eps,y;//another 2 variables


    cout<<"Enter the elements of the augmented matrix row-wise:"<<endl;
    for(i=0; i<n; i++) //loop for row
    {
        for(j=0; j<=n; j++) //loop for column
        {
            cin>>a[i][j];
        }
    }
    cout<<endl;


    cout<<"Enter the initial values of the variables:"<<endl;
    for(i=0; i<n; i++) //first row coefficient collection
    {
        cin>>var[i];
    }
    cout<<endl;

    cout<<"Enter the accuracy upto which you want the solution:"<<endl;;
    cin>>eps;//maybe 10^-4
    //abs function returns absolute value of the integer
    //First Make the equations diagonally dominant
    for(i=0;i<n;i++)
    {
        for(k=i+1;k<n;k++)
        {
            if(abs(a[i][i])<abs(a[k][i]))
                for(j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
        }
    }


    cout<<"Iter"<<setw(10);
    for(i=0; i<n; i++)
    {
        cout<<"var"<<i<<setw(10);
    }

    cout<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    do
    {
        cout<<"\n"<<cnt+1<<"."<<setw(16);
        for (i=0; i<n; i++)
        {
            y=var[i];
            var[i]=a[i][n];
            for (j=0; j<n; j++)
            {
                if (j!=i)
                    var[i]=var[i]-a[i][j]*var[j];
            }
            var[i]=var[i]/a[i][i];
            if (abs(var[i]-y)<=eps)
                flag++;
            cout<<var[i]<<setw(18);
        }
        cout<<endl;
        cnt++;
    }
    while(flag<n);

    cout.precision(0);//for tab space
    cout<<endl;
    cout<<"So the final answer is:"<<endl;
    for (i=0; i<n; i++)
        cout<<"var"<<i<<" = "<<var[i]<<endl;
    return 0;
}

///7 2 -3 22
///2 5 -3 15
///1 -1 -6 -21

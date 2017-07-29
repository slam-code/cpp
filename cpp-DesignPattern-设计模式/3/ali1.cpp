
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

float  sum=1.0;

int main()
{
   int N,M;
    float  P;
    cin>>N>>M>>P;
    vector<vector<double>> matrix(M,vector<double >(N,0));

    double temp;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>temp;
            matrix[i][j]=temp;
        }
    }

    int prelocation=-1;
    int location=0;
    vector<int>dp(M,0);
    for (int i = 1; i < M; ++i) {
        double diff=0;

        for (int j = 0; j < N; ++j) {

            if(matrix[i-1][j]<=sum)//可以买上一层。
            {
                diff=std::max((matrix[i][j]-matrix[i-1][j]),diff);
               if(diff==matrix[i][j])
                   location=j;
            }

        }
        if(diff>0)
        {
            if(prelocation!=location)
            {
                /*cout<<" sum= "<<sum<<" diff: "<<diff<<endl;
                sum=(sum+diff)*(1-P);*/
                sum=sum-matrix[i-1][location]+matrix[i][location]*(1-P);
                prelocation=location;

            }
            else
            {
                sum=sum+matrix[i-1][location]*P;
            }

        }
    }

    printf("%.1f\n",sum);


}
/*
1 2 0.1
1
2
 * */

/*
3 3 0.1
1 2 3
 4 2.5 3
 3 3 4
 * */
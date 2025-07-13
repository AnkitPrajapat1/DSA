//cut into segments/maximize the cuts segments

// input-> given a rod of n length. we can break it into 'x','y'&'z' segments,x,y,x are integers.
//output-> return the maximum no. of possible segments x,y & z lenghts


#include <iostream>
#include <limits.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    if (n==0) return 0;
    if(n<0) return INT_MIN;

    int option1=1+maximizeTheCuts(n-x,x,y,z);
    int option2=1+maximizeTheCuts(n-y,x,y,z);
    int option3=1+maximizeTheCuts(n-z,x,y,z);
    int finalAns=max(option1,max(option2,option3));
    return finalAns;
}
int main()
{

    int n=11;
    int x=5;
    int y=3;
    int z=4;
    int result=maximizeTheCuts(n,x,y,z);
    cout << "Ans is: " << result;
    return 0;
}
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void insertion(int a[],int s)
 {

    for(int i=1;i<=s-1;i++)
    {
        int temp=a[i];
        int j=i-1;

        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];    //moves element forward
            j=j-1;
        }

        a[j+1]=temp;    //insert element in proper place
    }
 }
int main()
{


    ofstream fileinput;
    srand(time(NULL));
    fileinput.open("100k.txt");
    int n=100000;

    int*arr=new int[n];

    for(int i=0;i<n;i++)
    {
         arr[i]=rand()%7000;
        fileinput<<rand()<<endl;

    }

    fileinput.close();

    clock_t startTime=clock();
   insertion(arr,n);

    clock_t endTime=clock();

    ofstream fileoutput;
    fileoutput.open("100koutput.txt");
    for(int i=0;i<100000;i++)
    {
        fileoutput<<arr[i]<<endl;
    }

    double timelapse=double (endTime-startTime)/CLOCKS_PER_SEC;
    cout<<timelapse<<endl;

    fileoutput.close();
    delete[] arr;
}

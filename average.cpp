#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc,char *argv[])
{
    int sum = 0;
    float average,a;
    int i;
    if(argc == 1){
        cout << "Please input numbers to find average.";
    }else{
        for(i = 1;i < argc;i++){
            a = atoi(argv[i]);
            sum += a;
        }
        average = sum / (argc-1);
        cout << "---------------------------------" << endl;
        cout << "Average of " << i-1 << " numbers = " << average << endl;
        cout << "---------------------------------" << endl;
    }
    return 0;
}
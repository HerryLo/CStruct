#include<iostream>
#include <iomanip>
using namespace std;

const int PI = 3.141592;

/* main主函数 */
int main() {
    cout
    <<setprecision(1)<<PI<<endl
    <<setprecision(2)<<PI<<endl
    <<setprecision(7)<<PI<<endl; //setprecision 输出精度
    
    int b =100;
    cout<<"DEc:"<<dec<<b<<endl //10进制
    <<"hex:"<<hex<<b<<endl //16进制
    <<"oct:"<<oct<<b<<endl; //8进制
    
    cout<<dec<<b<<endl;
    
    cout<<b<<endl
    <<"input b =";
    cin>>b;
    cout<<b<<endl;
    
    cout<<dec<<setiosflags(ios_base::showpos)<<b<<endl;  //加正号
    cout<<b<<endl
    <<"input b =";
    cin>>b;
    cout<<resetiosflags(ios_base::showpos); //
    cout<<b<<endl;
}


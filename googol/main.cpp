#include <QCoreApplication>
#include "AssemblyRobot.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include  <QFile>
#include "gts.h"
using namespace std;

int main(int argc,char *argv[])	//协调运动
{
    QCoreApplication e(argc, argv);

    AssemblyRobot myrobot;
    short count,flag=1;
    long lGpiValue;

    cout << "myrobot.Initial():"<<myrobot.Initial(RbtAllAxis)<<endl;

    double vel1[1][3] = {{0.020,0.1,0.020}};
    double vel2[1][3] = {{0.010,0.04,0.010}};

    double ang0[2][3] = {{0,0,0},{0,0,0}};
    double ang1[2][3] = {{0,0,0},{-20,0,0}};
    double ang2[2][3] = {{0,0,0},{20,0,0}};
    double ang3[2][3] = {{0,0,0},{0,-20,0}};
    double ang4[2][3] = {{0,0,0},{0,20,0}};
    double ang5[2][3] = {{0,0,0},{0,0,20}};

    //double Pos[3][3] = { { -60000,-60000,-60000 },{ +40000,+40000,+40000 },{0,0,0}};
    //long time[3] = {2000,4000,6000};
    //
    //count = sizeof(time) / sizeof(time[0]);
    //cout << "count = " << count << endl;
    //cout << "PointMove(): = "<<myrobot.PointMove(Pos,time,count)<<endl;

    while(flag == 1)
    {
        GT_GetDi(MC_GPI,&lGpiValue);
        if(lGpiValue& (1<<1))
        {
            for(int i=0; i<10; i++)
            {
                if(myrobot.AngMove(ang1,vel1,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                if(myrobot.AngMove(ang3,vel1,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                if(myrobot.AngMove(ang2,vel1,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                if(myrobot.AngMove(ang4,vel1,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                if(myrobot.AngMove(ang0,vel1,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                if(myrobot.AngMove(ang5,vel2,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

                cout <<"myrobot.SetExtDo():"<< myrobot.SetExtDo(4,0)<<endl;
                cout <<"myrobot.SetDo()"<<myrobot.SetDo(1,0)<<endl;

                while(1)
                {
                   GT_GetDi(MC_GPI,&lGpiValue);
                   if(!(lGpiValue&(1<<0))) break;
                }

                cout <<"myrobot.SetDo()"<<myrobot.SetDo(1,1)<<endl;

                if(myrobot.AngMove(ang0,vel2,1)!=RobotSuccess)
                    cout<<"oh my god"<<endl;

            }
                cout <<"myrobot.SetExtDo():"<< myrobot.SetExtDo(4,1)<<endl;
        }

        if(lGpiValue& (1<<8))
        {
            flag = 0;
        }
    }

    cout <<"myrobot.Close():"<< myrobot.Close()<<endl;

    return e.exec();
}

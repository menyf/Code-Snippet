// Wrote by MenYifan on 2016-07-25 22:12:04
// Exe.Time 624ms Exe.Memory 1668K
#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
using namespace std;

map<string,string> ma1;
map<int,string> ma2;
void init()
{
    ma1["000001"] = "ADD";
    ma1["000010"] = "SUB";
    ma1["000011"] = "DIV";
    ma1["000100"] = "MUL";
    ma1["000101"] = "MOVE";
    ma1["000110"] = "SET";
    ma1["ADD"] = "000001";
    ma1["SUB"] = "000010";
    ma1["DIV"] = "000011";
    ma1["MUL"] = "000100";
    ma1["MOVE"] = "000101";
    ma1["SET"] = "000110";
    
    ma1["00001"] = "1",ma1["00010"] = "2",ma1["00011"] = "3",ma1["00100"] = "4",ma1["00101"] = "5",ma1["00110"] = "6",
    ma1["00111"] = "7",ma1[ "01000"] = "8",ma1["01001"] = "9",ma1["01010"] = "10",ma1["01011"] = "11",ma1["01100"] = "12",
    ma1["01101"] = "13",
    ma1["01110"] = "14",ma1["01111"] = "15",ma1[ "10000"] = "16",ma1[ "10001"] = "17",ma1["10010"] = "18",ma1["10011"] = "19",
    ma1["10100"] = "20",ma1["10101"] = "21",ma1["10110"] = "22",ma1["10111"] = "23",ma1["11000"] = "24",ma1["11001"] = "25",
    ma1["11010"] = "26",ma1[ "11011"] = "27",ma1["11100"] = "28",ma1["11101"] = "29",ma1["11110"] = "30",ma1["11111"] = "31";
    
    ma2[1] = "00001",ma2[2] = "00010",ma2[3] = "00011",ma2[4] = "00100",ma2[5] = "00101",ma2[6] = "00110",
    ma2[7] = "00111",ma2[8] = "01000",ma2[9] = "01001",ma2[10] = "01010",ma2[11] = "01011",ma2[12] = "01100",
    ma2[13] = "01101",
    ma2[14] = "01110",ma2[15] = "01111",ma2[16] = "10000",ma2[17] = "10001",ma2[18] = "10010",ma2[19] = "10011",
    ma2[20] = "10100",ma2[21] = "10101",ma2[22] = "10110",ma2[23] = "10111",ma2[24] = "11000",ma2[25] = "11001",
    ma2[26] = "11010",ma2[27] = "11011",ma2[28] = "11100",ma2[29] = "11101",ma2[30] = "11110",ma2[31] = "11111";
}


int main()
{
    init();
    int n;
    int a,b;
    while(~scanf("%d",&n))
    {
        string s1,s4;
        char s2,s3;
        string z1,z2,z3;
        if(n == 1)
        {
            cin >> s1;
            if(s1 != "SET")
            {
                scanf(" %c%d,%c%d",&s2,&a,&s3,&b);
                if(ma1.find(s1)!=ma1.end() && ma2.find(a) != ma2.end() && ma2.find(b) != ma2.end())
                {
                    cout << ma1[s1] << ma2[a]<<ma2[b]<<endl;
                }
                else {
                    cout << "Error!"<<endl;
                }
            }
            else
            {
                scanf(" %c%d",&s2,&a);
                //                cout << a << endl;
                if(ma1.find(s1)!=ma1.end() && ma2.find(a) != ma2.end()){
                    cout << ma1[s1]<<ma2[a]<<"00000"<<endl;
                }
                
                else {
                    cout << "Error!"<<endl;
                }
                
            }
            
        }
        else
        {
            cin >> s1;
            for(int i = 0 ; i < 6 ; i++){
                z1 += s1[i];
            }
            z1[6] = '\0';      // ?????
            //            cout<<z1;
            
            for(int i = 6 ; i < 11 ; i++){
                z2 += s1[i];
            }
            z2[5] = '\0';   //?????
            //            cout<<z2;
            
            for(int i = 11 ; i < 16 ; i++){
                z3 += s1[i];
            }
            z3[5] = '\0';
            //            cout<<z3<<endl;
            
            
            if(ma1.find(z1) == ma1.end())
            {
                cout << "Error!"<<endl;
            }
            else if(ma1[z1] == "SET")
            {
                if(ma1.find(z2) == ma1.end() || z3 != "00000"){
                    cout << "Error!"<<endl;
                }
                else {
                    cout << ma1[z1] << " "<<'R'<< ma1[z2] << endl;
                }
                
            }
            else
            {
                if(ma1.find(z3)==ma1.end() || ma1.find(z2)==ma1.end() ||ma1.find(z1) == ma1.end()){
                    cout << "Error!"<<endl;
                }
                else  {
                    cout << ma1[z1] << " "<< 'R'<<ma1[z2]<< ','<<'R'<<ma1[z3]<<endl;
                }
            }
            
        }
    }
    return 0;
}
//#include<bits/stdc++.h>

//
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int main()
{
vector<string> mode;
vector<string>:: iterator it;
mode.push_back("organic");
mode.push_back("semidetached");
mode.push_back("embedded"); 

float coef[3][4]={ 
					{	2.4,1.05,2.5,0.38 } ,
					{	3.0,1.12,2.5,0.35 } ,
					{	3.6,1.20,2.5,0.32 } 
				};	

	
int KLOC;//kilo lines of code
cout<<"Enter the estimated size of project";
cin>>KLOC;

int modeNo=0;
if(KLOC>=2&&KLOC<50)
	modeNo=0;
else if(KLOC>=50&&KLOC<300)
	modeNo=1;
else
	modeNo=2;


cout<<endl;
int i;
i=modeNo;
//for(int i=0;i<3;i++)
//{
float effort,dev_time,avg_staff_size,productivity;
effort=coef[i][0]*pow(KLOC,coef[i][1]);
dev_time=coef[i][2]*pow(effort,coef[i][3]);
avg_staff_size=effort/dev_time;
productivity=KLOC/effort;

cout<<"Mode: \n"<<mode[i];
cout<<"Effort : "<<effort<< " person-month\n";
cout<<"Development time : "<<dev_time<<" months\n";
cout<<"Average staff size : "<<avg_staff_size<<" persons \n";
cout<<"Productivity : "<<productivity<<" KLOC/PM\n\n";

//}



	return 0;
}
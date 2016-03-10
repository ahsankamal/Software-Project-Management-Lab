
//http://www.coders-hub.com/2013/05/c-code-for-detail-cocomo-model.html#.VuFA-Yx975Y
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
  
vector<string> mode;
mode.push_back("organic");
mode.push_back("semidetached");
mode.push_back("embedded"); 

vector<string> phase;
phase.push_back("Plan and requirements");
phase.push_back("System Design");
phase.push_back("Detailed Design");
phase.push_back("Module code and Test");
phase.push_back("Integration and Test");

vector<string> driver;
driver.push_back("RELY");
driver.push_back("DATA");
driver.push_back("CPLX");
driver.push_back("TIME");
driver.push_back("STOR");
driver.push_back("VIRT");
driver.push_back("TURN");
driver.push_back("ACAP");
driver.push_back("AEXP");
driver.push_back("PCAP");
driver.push_back("VEXP");
driver.push_back("LEXP");
driver.push_back("MODP");
driver.push_back("TOOL");
driver.push_back("SCED");





float intermediate_coef[3][4]={ 
          { 3.2,1.05,2.5,0.38 } ,
          { 3.0,1.12,2.5,0.35 } ,
          { 2.8,1.20,2.5,0.32 } 
        };  

float costdrivers[15][6]={ 
                {0.75,0.88,1,1.15,1.40,-1}, 
                {-1,0.94,1,1.08,1.16,-1}, 
                {0.70,0.85,1,1.15,1.30,1.65}, 

                {-1,-1,1,1.11,1.30,1.66}, 
                {-1,-1,1,1.06,1.21,1.56}, 
                {-1,0.87,1,1.15,1.30,-1}, 
                {-1,0.87,1,1.07,1.15,-1}, 

                {1.46,1.19,1,0.86,0.71,-1}, 
                {1.29,1.13,1.00,0.91,0.82,-1}, 
                {1.42,1.17,1,0.86,0.70,-1}, 
                {1.21,1.10,1,0.90,-1,-1}, 
                {1.14,1.07,1,0.95,-1,-1}, 

                {1.24,1.10,1.00,0.91,0.82,-1}, 
                {1.24,1.10,1,0.91,0.83,-1}, 
                {1.23,1.08,1,1.04,1.10,-1} 
                }; 

//Life cycle phase values of mp and tp
float mp[6][5]={ //
            {0.06,0.16,0.26,0.42,0.16}, 
            {0.06,0.16,0.24,0.38,0.22}, 
            {0.07,0.17,0.25,0.33,0.25}, 
            {0.07,0.17,0.24,0.31,0.28}, 
            {0.08,0.18,0.25,0.26,0.31}, 
            {0.08,0.18,0.24,0.24,0.34} 
          }; 

  float tp[6][5]={ 
            {0.10,0.19,0.24,0.39,0.18}, 
            {0.12,0.19,0.21,0.34,0.26}, 
            {0.20,0.26,0.21,0.27,0.26}, 
            {0.22,0.27,0.19,0.25,0.29}, 
            {0.36,0.36,0.18,0.18,0.28}, 
            {0.40,0.38,0.16,0.16,0.30} 
          };                 

  float effort,EAF,a,devtime,staff,productivity;                 


cout<<"Enter size of project\n";
  int size,model;
  cin>>size;

  if(size>=2 && size<=50) 
    model=0; 
  else if(size>50 && size<=300) 
    model=1; 
  else if(size>300) 
    model=2; 
cout<<"Mode : "<<mode[model];

  EAF=1;
int rating;

  for(int i=0;i<15;i++) 
  { 
    do 
    { 
      cout<<"\nRate cost driver "<<driver[i]<<" on scale of 0-5 ";
      cout<<"\n0-Very Low\t1-Low\t2-Nominal\t3-High\t4-Very High\t5-Extra High\n";
  
    cin>>rating;
    a=costdrivers[i][rating]; 
    if(a==-1) 
    { 
      cout<<" \nNo value exist for this rating..Enter another rating...\n";
    } 
    }while(a==-1); 
    EAF=EAF*a; 
  } 

  
  printf("\nEAF = %f",EAF);
  effort=(intermediate_coef[model][0]*pow(size,intermediate_coef[model][1])) * EAF; 
  devtime=intermediate_coef[model][2]*pow(effort,intermediate_coef[model][3]); 
  staff=effort/devtime; 
  productivity=size/effort; 

 printf("\n\nEffort = %f Person-Month",effort); 
  printf("\nDevelopment Time = %f Months",devtime); 
  printf("\nAverage Staff Required = %d Persons",(int)staff); 
  printf("\nProductivity = %f KLOC/Person-Month",productivity); 
  printf("\n\n"); 


return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Input data
    vector<string>str={"1","2","3","","5","6","7","8","9","10","11","12","","14","15","16","17","18","19","20"};
    cout<<"User input data: \n";
    for(int i=0;i<20;i++)
    cout<<str[i]<<" ";
    cout<<"\n\n";


    cout<<"1st METHOD --> "<<endl;

    cout<<"Filling missing values using -> IGNORE THE EMPTY TUPLE  \n\n";

    vector<string>::iterator itr =find(str.begin(), str.end(), "");

    while(itr != str.end())
    {str.erase(itr);
    itr=find(str.begin(), str.end(), "");
    }


    for(int i=0;i<str.size();i++)
    cout<<str[i]<<" ";

    cout<<"\n\n";


    cout<<"2nd METHOD --> "<<endl;

      cout<<"Filling missing values using -> USING GLOBAL CONSTANT 'N\A'\n\n";
    for(int i=0;i<20;i++)
    { if(str[i]=="")
      str[i]="N/A";
    }

    for(int i=0;i<20;i++)
    cout<<str[i]<<" ";

    cout<<"\n\n";


    cout<<"3rd METHOD -->  "<<endl;

     // calculating mean of present data
    int sum=0;
    int count=0;
    for(int i=0;i<str.size();i++)
    {   if(str[i]=="")
        continue;
    sum=sum+stoi(str[i]);
    count++;
    }

    int mean=sum/count;

    cout<<"Filling missing values using -> MEAN OF PRESENT DATA\n\n";
    for(int i=0;i<20;i++)
    { if(str[i]=="")
      str[i]=to_string(mean);
    }

    for(int i=0;i<str.size();i++)
    cout<<str[i]<<" ";

    cout<<"\n\n";



    return 0;
}


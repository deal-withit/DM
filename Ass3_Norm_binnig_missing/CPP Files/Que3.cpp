#include<bits/stdc++.h>
using namespace std;
int main()
{
    //  Implement missing values using class labels (10 values for column with 2 labels,  2 missing values)

    vector<pair<string,string> >v={{"10","Laptop"},{" ","Computer"},{"14","Laptop"},
                                   {"27","Computer"},{" ","Laptop"},{"5","Computer"},
                                   {"1","Laptop"},{"8","Computer"},{"30","Laptop"},
                                   {"40","Computer"},{"15","Laptop"},{"25","Computer"}};

                              cout<<"Input data --> \n";
                              for(int i=0;i<v.size();i++)
                              cout<<v[i].first<<"  "<<v[i].second<<endl;

                              unordered_map<string,vector<string> >um;
                              for(int i=0;i<v.size();i++)
                              um[v[i].second].push_back(v[i].first);

                             unordered_map<string,int>um1;

                             for(auto pr:um)
                             { float sum=0;
                             float count=0;

                               for(int i=0;i<pr.second.size();i++)
                                {if(pr.second[i]!=" ")
                                {sum=sum+stoi(pr.second[i]);
                                count++;
                                }
                                }

                                um1[pr.first]= sum/count;

                             }

                             for(int i=0;i<v.size();i++)
                             {
                                 if(v[i].first==" ")
                                 v[i].first=to_string(um1[v[i].second]);

                             }

                                cout<<endl;

                                cout<<"Output data --> \n";
                                for(int i=0;i<v.size();i++)
                                cout<<v[i].first<<"   "<<v[i].second<<endl;



}

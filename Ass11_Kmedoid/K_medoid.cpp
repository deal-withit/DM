#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
     ifstream rd("database.txt");
     vector<int>v1;
     vector<int>v2;
     string s;
     while(getline(rd,s))
     {
          stringstream ss(s);
          int s1;
          ss>>s1;
          int s2;
          ss>>s2;
          v1.push_back(s1);
          v2.push_back(s2);
     }
     pair<int,int>k1(v1[0],v2[0]);
     pair<int,int>k2(v1[1],v2[1]);
     vector<int>sum1;
     vector<int>sum2;
     vector<pair<int,int>>cluster1;
     vector<pair<int,int>>cluster2;
     cluster1.push_back(k1);
     cluster2.push_back(k2);
     int S1=0,S2=0;
     int temp = 2;
     for(int i=0;i<v1.size();i++)
     {
             pair<int,int>p(v1[i],v2[i]);
             if(p!=k1 && p!=k2)
             {
               int temp1 = abs(k1.first - v1[i])+abs(k1.second-v2[i]);
               int temp2 = abs(k2.first - v1[i])+abs(k2.second-v2[i]);
               sum1.push_back(temp1);
               sum2.push_back(temp2);
               if(temp1<temp2)
               {
                     cluster1.push_back({v1[i],v2[i]});
               }
               else{
                     cluster2.push_back({v1[i],v2[i]});
               }
             }
     }
     int AS = 0;
     for(int i=0;i<sum1.size();i++)
     {
         AS+=min(sum1[i],sum2[i]);
     }
     int AS1;
         while(1)
         {
             
              sum1.clear();
              sum2.clear();
              vector<pair<int,int>>t1;
              vector<pair<int,int>>t2;
              k2.first=v1[temp++];
              k2.second=v2[temp++];
              t1.push_back(k1);
              t1.push_back(k2);
              for(int i=0;i<v1.size();i++)
              {
              pair<int,int>p(v1[i],v2[i]);
              if(p!=k1 && p!=k2)
              {
               int temp3 = abs(k1.first - v1[i])+abs(k1.second-v2[i]);
               int temp4 = abs(k2.first - v1[i])+abs(k2.second-v2[i]);
               sum1.push_back(temp3);
               sum2.push_back(temp4);
               if(temp3<temp4)
               {
                     t1.push_back({v1[i],v2[i]});
               }
               else{
                     t2.push_back({v1[i],v2[i]});
               }
              }
             }
           AS1 = 0;
        for(int i=0;i<sum1.size();i++)
        {
           AS1+=min(sum1[i],sum2[i]);
        }
        if(AS1<AS)
        {
             break;
        }
        else
        {
             cluster1=t1;
             cluster2=t2;
             AS=AS1;
        }
         }
        
        cout<<"Cluster: 1\n";
        for(int i=0;i<cluster1.size();i++)
        {
             cout<<cluster1[i].first<<" "<<cluster1[i].second<<endl;
        }
        cout<<endl;
         cout<<"Cluster: 2\n";
        for(int i=0;i<cluster2.size();i++)
        {
             cout<<cluster2[i].first<<" "<<cluster2[i].second<<endl;
        }cout<<endl;
        
        cout<<AS1<<" ";
        
        cout<<endl;
     

}

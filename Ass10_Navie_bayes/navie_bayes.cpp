#include<bits/stdc++.h>
using namespace std;
int main(){
    
   ifstream read("input.txt");
   string s;
    unordered_map<string,pair<int,int>>o;
    unordered_map<string,pair<int,int>>h;
    unordered_map<string,pair<int,int>>w;//first represen how much time yes occured and second for no
    unordered_map<string,pair<int,int>>t;
    float yes=0;
    float no=0;
   
   getline(read,s);
   
   while(getline(read,s)){
       
       stringstream ss(s);
       string temp,o1,t1,h1,w1,pt;
       ss>>temp;
       ss>>o1;
       ss>>t1;
       ss>>h1;
       ss>>w1;
       ss>>pt;
       
       // chech total yes/no
       if(pt=="Yes")
       yes++;
       else
       no++;
       
       
       
       // outlook
       
       if(o.find(o1)==o.end()){
           if(pt=="Yes")
           o[o1]={1,0};
           
       else{
           o[o1]={0,1};
       }
     }else{
          if(pt=="Yes")
           o[o1].first++;
           
       else{
           o[o1].second++;
       }
     }
     
     //temprature
     
       if(t.find(t1)==t.end()){
           if(pt=="Yes")
           t[t1]={1,0};
           
       else{
           t[t1]={0,1};
       }
     }else
	 {
          if(pt=="Yes")
           t[t1].first++;
           
       else{
           t[t1].second++;
       }
     } 
     
     
     // humidity
     
       if(h.find(h1)==h.end()){
           if(pt=="Yes")
           h[h1]={1,0};
           
       else{
           h[h1]={0,1};
       }
     }else{
          if(pt=="Yes")
           h[h1].first++;
           
       else{
           h[h1].second++;
       }
     } 
     
     // wind
     
       if(w.find(w1)==w.end()){
           if(pt=="Yes")
           w[w1]={1,0};
           
       else{
           w[w1]={0,1};
       }
     }else{
          if(pt=="Yes")
           w[w1].first++;
           
       else{
           w[w1].second++;
       }
     } 
     
    
    // -----
    
   }
   
   for(auto it:o){
       cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
   }
   
   cout<<endl;
      for(auto it:t){
       cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
   }
   
   cout<<endl;
   
      for(auto it:h){
       cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
   }
   
   cout<<endl;
   
      for(auto it:w){
       cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
   }
    
    cout<<yes<<" "<<no<<endl;
    
    cout<<"Enter: ";
    string str;
    getline(cin,str);
    string o2,t2,h2,w2;
    stringstream ss1(str);
    ss1>>o2;
    ss1>>t2;
    ss1>>h2;
    ss1>>w2;
    
    // yes
    int o3=o[o2].first;
    int t3=t[t2].first;
    int h3=h[h2].first;
    int w3=w[w2].first;
    
    float p_yes=(o3*t3*h3*w3)/(yes*yes*yes*(yes+no));
    
    cout<<p_yes<<endl<<endl;
    
    
    
    //no
    
    
      o3=o[o2].second;
      t3=t[t2].second;
      h3=h[h2].second;
      w3=w[w2].second;
    
    float p_no=(o3*t3*h3*w3)/(no*no*no*(yes+no));
    cout<<p_no<<endl<<endl;
    if(p_yes>p_no)
    cout<<"YES\n";
    else
    cout<<"NO";
}

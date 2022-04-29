 #include<bits/stdc++.h>
using namespace std;
int main()
{

     vector<vector<int> >v={{16,17},{45,65},{80,46},{51,78},{73,60},{45,86},{40,65},{79,8},{5,34}};

     cout<<"\nINPUT DATA -->\n";

     for(int i=0;i<v.size();i++)
     cout<<v[i][0]<<" "<<v[i][1]<<endl;
     cout<<endl;


     // Separating Column 1 and 2
      vector<float>first,second;
      for(int i=0;i<v.size();i++)
        {first.push_back(v[i][0]);
         second.push_back(v[i][1]);
        }


      // ---------- Solving column 1st  ---------------

     cout<<"METHOD 1 --> DECIMAL SCALING"<<endl;
      int maxx=0;
      for(int i=0;i<first.size();i++)
      {   if(first[i]>maxx)
           maxx=first[i];

      }

      int count=0;
      while(maxx>0)
      {
          count++;
          maxx=maxx/10;
      }

      long long int temp=1;
      while(count--)
      {
          temp=temp*10;
      }

      vector<float>first1;
       for(int i=0;i<first.size();i++)
       {first1.push_back((float)first[i]/(float)temp);
        cout<<first1[i]<<" ";}

     cout<<"\n\n";

     cout<<"METHOD 2 --> MIN - MAX NORMALIZATION"<<endl;
     float min=10000;
     float max=0;
     float newmin=0;
     float newmax=1;

     for(int i=0;i<first.size();i++)
     {if(first[i]<min)
      min=first[i];
      if(first[i]>max)
        max=first[i];
     }

     // Using formula
     vector<float>first2;
     for(int i=0;i<first.size();i++)
     {   if(max-min != 0)
         {float ft=(float)((first[i]-min)/(float)(max-min))*(float)(newmax-newmin)+(float)newmin;
         first2.push_back(ft);
         cout<<first2[i]<<" ";
        }
     }
     cout<<"\n\n";
     cout<<"METHOD 3 --> z-Score Normalization"<<endl;

     float sum=0;
     count=0;
     for(int i=0;i<first.size();i++)
        {sum=sum+first[i];
        count++;
        }

        float mean=(float)sum/count;
        vector<float>vec;
        for(int i=0;i<first.size();i++)
            vec.push_back((first[i]-mean)*(first[i]-mean));

        float temp1=0;
        for(int i=0;i<vec.size();i++)
            temp1=temp1+vec[i];

        float variance=(float)temp1/(float)vec.size();
        float sd=sqrt(variance);

        vector<float>first3;
        for(int i=0;i<first.size();i++)
            {first3.push_back((float)(first[i]-mean)/(float)sd);
            cout<<first3[i]<<" ";}


            cout<<endl;
            cout<<endl;


}

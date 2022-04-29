#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> data{12,45,78,63,258,14,698,144,25,789,651,888,744,456,423,846,972,168,2,357};

    sort(data.begin(),data.end());
    int bin_size=4;

    cout<<"\n## Partition into (equal-frequency of 4) bins:\n\n";
    int j=1;
    for(int i=0;i<data.size();i++)
         {
            cout<<"Bin "<<j<<": ";
             for(;i<j*bin_size;i++)
             {
               cout<<data[i]<<" ";
             }
             i--;
             j++;
             cout<<endl;
         }

    cout<<"\n## Smoothing by bin means:\n\n";
       j=1;
    for(int i=0;i<data.size();i++)
         {
            cout<<"Bin "<<j<<": ";
            int sum=0;
             for(;i<j*bin_size;i++)
             {
                sum+=data[i];
             }
             for(int c=0;c<bin_size;c++)
             {
                cout<<sum/4<<" ";
             }
             i--;
             j++;
             cout<<endl;
         }


    cout<<"\n## Smoothing by bin boundaries:\n\n";
    j=1;
    for(int i=0;i<data.size();i++)
         {
            cout<<"Bin "<<j<<": ";
            int mx=INT_MIN;
            int mi=INT_MAX;
             for(;i<j*bin_size;i++)
             {
                mx=max(mx,data[i]);
                mi=min(mi,data[i]);
             }
             i=i-bin_size;

             for(;i<j*bin_size;i++)
             {  if(mx-data[i]>data[i]-mi)
                   data[i]=mi;
                else
                   data[i]=mx;
                cout<<data[i]<<" ";

             }
             i--;
             j++;
             cout<<endl;
         }

    return 0;

}

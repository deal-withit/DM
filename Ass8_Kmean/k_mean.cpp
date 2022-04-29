#include<bits/stdc++.h>
using namespace std;

int main(){


 
 // Reading data from file
 ifstream read("input.txt");
 string str;
 
 vector<pair<int,int>>v;
 while(getline(read,str)){
 	
	 stringstream ss(str);
 	 string temp;
 	 ss>>temp;
 	 while(ss>>temp){
 	 	int a=stoi(temp);
 	 	ss>>temp;
 	 	int b=stoi(temp);
 	 	v.push_back({a,b});
 	 }
}

cout<<"\n Printing my input text file data \n";

// Vector containing the data
for(int i=0;i<v.size();i++){
	cout<<v[i].first<<" "<<v[i].second<<endl;	
}

cout<<endl;

// Initially dividing into K - Clusters	

 int k=3;
 
// Vector containing clusters 
vector<pair<int,vector<pair<float,float>>>>contain_k_clusters;

// Vector containing mean of k clusters
vector<pair<float,float>>contain_k_means;




 
for(int i=0;i<k;i++){
	
	contain_k_clusters.push_back({i+1,{{v[i].first,v[i].second}}});
	contain_k_means.push_back({v[i].first,v[i].second});
	 	
	
}

cout<<"\nPrinting My initial "<<k<<" custers\n";

// Printing initial cluster
for(int i=0;i<contain_k_clusters.size();i++){
	for(int j=0;j<contain_k_clusters[i].second.size();j++)
	cout<<contain_k_clusters[i].first<<"  "<<contain_k_clusters[i].second[j].first<<"  "<<contain_k_clusters[i].second[j].second<<endl;
}


 
 // vector contain distance of point from k-cluster
vector<pair<float,float>>contain_distances;

// Now Working

for(int i=k;i<v.size();i++){
	 
	 int kk=k;
	int j=0;
	 while(kk--){
	 	
	 	// Using Euclidian Formula 
	 	float d1=sqrt(((contain_k_means[j].first-v[i].first)*(contain_k_means[j].first-v[i].first))+((contain_k_means[j].second-v[i].second)*(contain_k_means[j].second-v[i].second)));    
	 	contain_distances.push_back({d1,j+1});
	 	j++;
	 }
	 
	 sort(contain_distances.begin(),contain_distances.end());
	 
	  for(int p=0;p<contain_k_clusters.size();p++){
		
		if(contain_k_clusters[p].first==contain_distances[0].second){
	      contain_k_clusters[p].second.push_back({v[i].first,v[i].second});
		  break; 
      }

}
   contain_distances.clear();

}

 
 // Printing contain_k_clusters
 
 cout<<"\n Printing K-Clusters\n\n";
 
 	for(int p=0;p<contain_k_clusters.size();p++){
		
		cout<<"CLUSTER "<<contain_k_clusters[p].first<<"->";
		
		vector<pair<float,float>>vp=contain_k_clusters[p].second;
		
		for(float u=0;u<vp.size();u++)
		{
			pair<float,float>pp=vp[u];
			cout<<" ("<<pp.first<<" "<<pp.second<<") ";
		}
 cout<<endl<<endl;
}

 
	
	
}



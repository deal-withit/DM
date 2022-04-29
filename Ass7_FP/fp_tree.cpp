#include<bits/stdc++.h>
using namespace std;

 

 bool cmp(const pair<int,string>&a,const pair<int,string>&b)
{
	return a.first>b.first;
 
}
 
 // creating the node for tree
 struct Node{
    string item;
    int freq;
    Node* child[10];
    bool isEnd;
    Node(string x){
        item = x;
        freq = 0;
        isEnd = false;
        for(int i = 0; i < 10;i++) child[i] = NULL;
    }
};

// inserting the data into tree 

void insert_fp_tree(vector<string> &A,Node *root){
    Node *curr = root;
    for(auto i : A){
      int ind = stoi(i.substr(1));
        if(!curr->child[ind]) curr->child[ind] = new Node(i);
        curr->freq += 1;
        curr = curr->child[ind];
    }
    curr->freq += 1;
    curr->isEnd = true;
}

// traversing the tree and storing into database 

void traverse_fp_tree(Node *root,vector<Node*> &curr_path,vector<vector<Node*>> &Ans){
    if(!root) return;
    if(root->isEnd){
        curr_path.push_back(root);
        Ans.push_back(curr_path);
        curr_path.pop_back();
    }
    for(int i = 0;i < 10;i++){
        curr_path.push_back(root);
        traverse_fp_tree(root->child[i],curr_path,Ans);
        curr_path.pop_back();
    }
} 


// storing the tree in database and printing the tree

void print_database(vector<vector<string>> &data){
    cout<<"\ndata.txt : \n";
    for(auto i : data){
        for(auto j : i) cout<<j<<' ';
        cout<<'\n';
    }
    cout<<"------------------------------------------------------\n";
}

void print_fp_tree(Node *root){
    vector<Node*> curr_path;
    vector<vector<Node*>> res;

    traverse_fp_tree(root,curr_path,res);
cout<<"\n STEP: 8) Printing FP Tree based on sorted Itemset data\n\n";
    cout<<"\n\n";
    for(auto i : res){
        for(auto j : i){
            if(j->item != "root") cout<<j->item<<":"<<j->freq<<" -> ";
        }
        cout<<"NULL\n-------------------------------------------------\n";
    }
}

void mine_fp_tree(Node *root,Node *par,map<string,vector<pair<vector<string>,int>>> &conditional_pattern_base,vector<string> &curr){
    if(!root) return;

    if(par && par->item != "root") conditional_pattern_base[root->item].push_back({curr,root->freq});

    for(int i = 0;i < 10;i++){
        if(root->item != "root") curr.push_back(root->item);
        mine_fp_tree(root->child[i],root,conditional_pattern_base,curr);
        if(root->item != "root") curr.pop_back();
    }
}
 
 
 
 
 
 
 
 
int main()
 {
  
 ifstream read("input.txt");
 string str;
 vector<vector<string> >v;
 
 while(getline(read,str))
 {
 	stringstream ss(str);
 	string temp;
 	ss>>temp;
 	vector<string>temp1;
	 while(ss>>temp)
 	  temp1.push_back(temp);
 	  
 	  v.push_back(temp1);
 }
 
 
 // output 1 -----------------------
 cout<<"STEP: 1) Input data that I have read from input file\n";
 
 for(int i=0;i<v.size();i++){
 	for(int j=0;j<v[i].size();j++){
 		cout<<v[i][j]<<" ";
 			
 	}
 	 	
 	cout<<endl;	
 }
 
 // -------------------------------
 
 map<string,int>mp;
 
  for(int i=0;i<v.size();i++){
 	for(int j=0;j<v[i].size();j++){
 		mp[v[i][j]]++;
 	}	
 }
 
 
 // output 2 --------------
 cout<<"\nSTEP: 2) Frequency of each Item present: \n"; 
  for(auto it:mp){
 	cout<<it.first<<" "<<it.second<<endl;	
 }
 
 cout<<endl;
 cout<<endl;
 
 // ----------------------


 cout<<"\nSTEP: 3) Remove the items whose frequency is less than min_sup_count (Here MSC=2)\n\n";
   vector<pair<int,string> >pq;
   for(auto it:mp){
 	if(it.second>=2)
	 pq.push_back({it.second,it.first});	
 }
  
  
 sort(pq.begin(),pq.end(),cmp); 
  
   //output 3 -------------------------------
  cout<<"\nSTEP: 4) Sorting the items according to frequency in decending order\n";
  for(auto it:pq)
  cout<<it.first<<" "<<it.second<<endl;  
  
  cout<<endl;
  cout<<endl;
 //-------------------------------------


 vector<vector<string> >vv;
 
 for(int i=0;i<v.size();i++){
 	
  
    vector<string>vvv;
    
 for(int k=0;k<pq.size();k++){
	pair<int,string>pr=pq[k];
 
	
	for(int j=0;j<v[i].size();j++)
	if(pr.second==v[i][j])
	vvv.push_back(pr.second);
	 
	}
	

	vv.push_back(vvv);
	
}


// output 4  -------------------------
cout<<"\nSTEP: 5) Arrange the itemsets according to their frequencies in decending order\n";
 for(int i=0;i<vv.size();i++){
 	for(int j=0;j<vv[i].size();j++){
 		cout<<vv[i][j]<<" ";
 			
 	}
 	cout<<endl;	
 }
 
 // -------------------------------
 
 
 cout<<"\nSTEP: 6) Writing the arranged itemsets into (input1.txt) file\n\n";
 
 ofstream write("input1.txt");
 
 for(int i=0;i<vv.size();i++){
 	for(int j=0;j<vv[i].size();j++)
 		write<<vv[i][j]<<" ";
 		
 		write<<endl;
 			
 	}
 	
 	write.close();
 
 
 
 cout<<"\nSTEP: 7) Reading the data the arranged data into (input1.txt) file\n\n";
   ifstream read11("input1.txt");
     string stri;
     vector<vector<string>>data;
     
     while(getline(read11,str)){
     	vector<string>tempv;
     	stringstream ss(str);
     	string temp;
     	while(ss>>temp)
     	tempv.push_back(temp);
     	
     	data.push_back(tempv);
     	
     }
     
     read11.close();
     
     
     // constructing the fp tree from here
     
      Node *root = new Node("root");

    for(auto i : data) insert_fp_tree(i,root);

    print_fp_tree(root);

    map<string,vector<pair<vector<string>,int>>> conditional_pattern_base;

    vector<string> curr;

    mine_fp_tree(root,NULL,conditional_pattern_base,curr);


    // code is write just remove comments.........
    
    cout<<"\n\nSTEP: 9) Printing conditional Frequent Itemset\n\n";
    cout<<"\nItem          Conditional Pattern Base\n\n";
    cout<<endl;
    for(auto i : conditional_pattern_base){
        cout<<i.first<<"                 ";
        for(auto j : i.second){
            for(auto k : j.first){
                cout<<k;
            }
            cout<<"<"<<j.second<<"> ";
        }
        cout<<"\n-----------------------------------------------------\n";
    }
     
     
     

 return 0;
  
	
}


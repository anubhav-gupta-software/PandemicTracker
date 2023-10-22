#include "bits/stdc++.h"
using namespace std;

vector<string>wanted;

void addEdge(unordered_map<string, vector<string>>& graph, const string& u, const string& v) {
    graph[u].push_back(v);
}

void dfsRecursive(unordered_map<string, vector<string>>& graph, const string& vertex, set<string>& visited) {
    if (visited.find(vertex) == visited.end()) {
        cout << vertex << endl;

        wanted.push_back(vertex);
        visited.insert(vertex);
        if (graph.find(vertex) != graph.end()) {
            for (const string& neighbor : graph[vertex]) {
                dfsRecursive(graph, neighbor, visited);
            }
        }
    }
}


int main(){
	freopen("WARNING_needAction.txt", "w", stdout);
	 
	 //freopen("flu_positive.txt", "w", stdout);
	 ifstream namesFile("names.txt");
     ifstream btFile("bluetooth_user_data.txt");
     ifstream fpFile("flu_postitive.txt");
     ofstream sendMessage("send_notifications.txt");
     ofstream emergency("emergency.txt");
    string name;
    //addEdge(graph,"a","b");
    unordered_map<string, vector<string>> graph;
    while(getline(btFile, name)){
    	string j = name;
    	//cout<<j<<endl;
    	string name1="";
    	string name2 = "";
    	int curr = 0;
    	
    	for(int i=0;i<j.size();i++){
    		if(j[i]==' '){
    			curr = i+1;
    			break;
    		}
    		name1 += j[i];
    	}
    	for(int i=curr;i<j.size();i++){
    		name2 += j[i];
    	}
    	//cout<<name1<<endl;
    	addEdge(graph,name1,name2);
    	    }
   	

   	set<string> visited;
   	string patients;

   	//vector<string>warning;
    while(getline(fpFile, patients)){
    	
    	dfsRecursive(graph, patients, visited);
    }
    //dfsRecursive(graph,"DanielAnderson", visited);
    
    ifstream WAFile("WARNING_needAction.txt");
    string final;

    sort(wanted.begin(), wanted.end());
 	for(auto i: wanted){
 		sendMessage<<i<<endl;
 	}
	return 0;
}
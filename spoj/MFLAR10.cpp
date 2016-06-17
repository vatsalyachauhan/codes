#include <iostream>
#include <map>
using namespace std;

bool isline(string str){
	bool temp = false;
	int i =0;
	while(str[i]){
		if(str[i]!=' '){
			temp = true;
			break;
		}
		i++;
	}
	return temp;
}

int main(){
	int n,i;
	bool istauto;
	int prev;

	map<char,int> m;
	for(i=0;i<26;i++){
		m.insert(pair<char,int>('a'+i,i+1));
		m.insert(pair<char,int>('A'+i,i+1));
	}
	string line;
	getline(cin,line);
	while(line.compare("*")){
		istauto = true;
		i=0;
		if(isline(line)){
			if(line[0]==' ')
				i++;
			prev = m[line[i]];
			while(line[i]){
				if(line[i]==' ' && line[i+1]){
					if(prev!=m[line[i+1]]){
						istauto = false;
						break;
					}
				}

				i++;
			}

			if(istauto)
				cout<<"Y"<<endl;
			else
				cout<<"N"<<endl;
		}
		getline(cin,line);
	}
}
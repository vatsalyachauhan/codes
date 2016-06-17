#include <iostream>
#include <string>
#include <set>
using namespace std;


int check7(string str){
	int sz = str.size();
	int result = 0,i,temp;
	bool flag = true;
	for(i=sz-1;i>=2;i = i-3){
		temp = ( (str[i-2]-'0')*100 + (str[i-1]-'0')*10 + (str[i]-'0'));
		result += temp*(flag?1:-1);
		flag = !flag;
	}
	if(i==1){
		temp = (str[0]-'0')*10 + (str[1]-'0');
		result += temp*(flag?1:-1);
	}
	else if(i==0){
		temp = (str[0]-'0');
		result += temp*(flag?1:-1);
	}
	if(result%7)
		return 0;
	return 1;
}

int main(){
	int i,result,sz,sumofdigits;
	string str;
	set<int>::iterator it;
	while(cin>>str){
		set<int> s;
		result = 0;
		int counts[10] = {0};
		sumofdigits = 0;
		sz = str.size();
		for(i=0;i<sz;i++){
			s.insert(str[i]-'0');
			sumofdigits += (str[i]-'0');
			counts[str[i]-'0']++;
		}
		

		for(it=s.begin();it!=s.end();it++){
			switch(*it){
				case 0: break;
				case 1: result += counts[1]*1; break;
				case 2: result += counts[2]*(((str[sz-1]-'0')%2)?0:1); break;
				case 3: result += counts[3]*((sumofdigits%3)?0:1); break;
				case 4: result += counts[4]*(((  (sz>1?(str[sz-2]-'0')*10:0) + (str[sz-1]-'0'))%4==0)?1:0); break;
				case 5: result += counts[5]*((str[sz-1]=='0' || str[sz-1]=='5')?1:0); break;
				case 6: result += counts[6]*(( ((str[sz-1]-'0')%2)==0 && (sumofdigits%3)==0 )?1:0); break;
				case 7: result += counts[7]*check7(str); break;
				case 8: result += counts[8]*((( (sz>2?(str[sz-3]-'0')*100:0) + (sz>1?(str[sz-2]-'0')*10:0) + (str[sz-1]-'0'))%8)?0:1); break;
				case 9: result += counts[9]*((sumofdigits%9)?0:1); break;
			}
		}
		cout<<result<<endl;
	}
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//自訂順序(小長度排前面，接著照字典序) 
bool cmp(string a,string b)
{
	if(a.size()!=b.size())return a.size()<b.size();
	return a<b;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	vector<string> words;
	string tosearch; 
	int start=0,end=26;
	
	/*
	要把所有符合
	1.每個字串只包含小寫字母
	2.每個字串絕對遞增
	3.字串最長為5個字串
	丟進去words裡面 
	*/
	
	//一開始先把長度一的a~z丟進去 
	for(string i="a";i<="z";i[0]++)
		words.push_back(i);
		
	/*
	三層迴圈
	第一層迴圈目的要處理長度幾(2~5)
	第二層迴圈目的要將長度n-1的字串補上一個字讓他長度變為n 
	第三層迴圈目的要增加所有從長度n-1變成n的字串 
	例如當 
	i=1(長度為3)
	j=28(ac的編號)
	k=e
	words會push_back一個"ac"+'e'的字串也就是"ace" 
	*/ 
	for(int i=0;i<4;i++)
	{
		for(int j=start;j<end;j++)
			for(char k=words[j][i]+1;k<='z';k++)
				words.push_back(words[j]+k);
		start=end;
		end=words.size();
	}
	
	//*Test*/for(int i=0;i<words.size();i++){cout<<i+1<<' '<<words[i]<<endl;}
	
	
	while(cin>>tosearch)
	{
		if(*lower_bound(words.begin(),words.end(),tosearch,cmp)!=tosearch)
			cout<<"0\n";
		else 
			cout<<lower_bound(words.begin(),words.end(),tosearch,cmp)-words.begin()+1<<'\n';
	}
	return 0;
}

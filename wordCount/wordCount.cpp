#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include<stack>
#include <iomanip>
#include <fstream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define mst(a,b) memset(a,b,sizeof(a));
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int inf=0x3f3f3f3f;
map<string,int>mapp; 
struct po
{
	string name;
	int count;
}p[1000000];
int cc=0;
struct count_string
{
	string s;
	int count=0;
}count_s[10000];
int word_l=0;
int sum=0;
int c_c=0;
int c_l=0;
bool com(struct count_string a,struct count_string b)
{
	if(a.count!=b.count)
		return a.count>b.count;
	else
		a.s<b.s;
}
bool cmp(po a, po b)
{
	if(a.count==b.count)
	{
		return a.name<b.name;
	} 
	return a.count>b.count;
} 
bool is_word(string a)//zou
{
	int len=a.length();
	int i;
	int k=0;//统计开头连续的字母个数
	if(len<4) return false; //字符数组长度不足4则不是单词 
	for(i=0;i<len;i++)
	{
		if(a[i]>=97&&a[i]<=122) k++; //是字母则+1 
		if(i==3)
		{
			if(k<4)
				return false; //已经统计了4个但没有4个字母则报错
			else break;
		}
	}
	return true;
}
string lowcase(string str)//wang
{
	for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }
    return str;
}
int count_word(string arr)//wu
{
	
	char c[300]={0};
	int k=0;
	arr=lowcase(arr);

		for(int j=0;j<arr.length();j++)
		{
			if(((arr[j]<='z'&&arr[j]>='a')||(arr[j]<='9'&&arr[j]>='0'))&&j!=arr.length()-1)
			{
				c[k]=arr[j];
				k++;
			}	
			else
			{
				if(j==arr.length()-1&&((arr[j]<='z'&&arr[j]>='a')||(arr[j]<='9'&&arr[j]>='0')))
				{
					c[k]=arr[j];
					k++;	
				}
				string c1=c;
				if(is_word(c1)==true)
				{
					sum++;
					int x;
					if(word_l==0)
					{
						count_s[word_l].count=1;
						count_s[word_l].s=c1;
						word_l++;
						
					}
					else
					{
						for(x=0;x<word_l;x++)
						{
							if(c1==count_s[x].s)
							{
								count_s[x].count++;
								break;
							}
							
						}
						if(x>=word_l)
						{
							count_s[word_l].count=1;
							count_s[word_l].s=c1;
							word_l++;
						}
					}
					
				}	
				c1="";
				memset(c,0,sizeof(c));
				k=0;
			}
		}
}
void count_phrase(int m,string s)//m>=2
{
//	de(s);
//	cout<<s.size()<<endl;
	int c=0;//空格个数
	string tp=""; 
	string ans="";
	for(int i=0;i<s.size();i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
		{
			tp+=s[i];
		}
	//	de(tp);
		if(s[i]==' '||i==s.size()-1)
		{
			if(c==m-1)
			{
				string low=lowcase(tp);
				bool flag=is_word(low);
				if(flag)
				{
					ans+=low;
					mapp[ans]++;
					//de(ans);
					if(mapp[ans]==1)
					{
						p[cc].name=ans;
						p[cc++].count=1;
					}
					else
					{
						for(int j=0;j<cc;j++)
						{
							if(p[j].name==ans)
							{
								p[j].count++;
								break;
							}
						}
					}
					string tt;
					int f=0;
					for(int j=0;j<sz(ans);j++)
					{
						if(ans[j]==' ')
						{
							f=j;
							break;
						}
					}	
				//	de(f);
					for(int j=f+1;j<sz(ans);j++)
					{
						tt+=ans[j];
						//de(ans[j]);
					}
				//	de(tt);
					ans=tt;
					if(s[i]==' ')
					{
						ans+=' ';
					} 
					tp="";
				}
				else
				{
					ans="";
					tp="";
					c=0;
					
				}
			}
			else
			{
				string low=lowcase(tp);
				bool flag=is_word(low);
			//	de(flag);
				if(flag)
				{
					ans+=low;
					ans+=' ';
					c++;
					tp="";
				}
				else
				{
					ans="";
					tp="";
					c=0;
				}
				
			//	de(ans);
			}
		
		}
		else if(s[i]!=' '&&!(s[i]>='a'&&s[i]<='z')&&!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='0'&&s[i]<='9'))
		{
			//de(c);
			if(c==m-1)
			{
				string low=lowcase(tp);
				bool flag=is_word(low);
			//	de(flag);
				if(flag)
				{
					ans+=low;
					mapp[ans]++;
					if(mapp[ans]==1)
					{
						p[cc].name=ans;
						p[cc++].count=1;
					}
					else
					{
						for(int j=0;j<cc;j++)
						{
							if(p[j].name==ans)
							{
								p[j].count++;
								break;
							}
						}
					}
					ans="";
					tp="";
					c=0;
				}
				else
				{
					ans="";
					tp="";
					c=0;
				}
			}
			else
			{
				ans="";
				tp="";
				c=0;
			}
		}
	}
}
int count_line(string s)//hu
{
   	if(s.length()!=0)
   	{
   		c_l++;
   	}
   	c_c++;
}
int count_characters(string str)
{
	int len=str.length();
	for(int i=0;i<len;++i)
	{
		//cout<<str[i];//打印字符串 
		if(str[i]>=0&&str[i]<256)
		{
			++c_c;
		}
	}
	
}
int main(int argc, char *argv[])
{
 //	std::ios::sync_with_stdio(false);
   // cin.tie(0);
   string a, b, c, d,e;
    a = "-m";
    b = "-n";
    c = "-i";
    d = "-o";
    int n=-1,m=-1;
   
    for(int i=1;i<argc;i++)
    {
    	if(argv[i]==c)
    	{
    		freopen(argv[i+1], "r", stdin);
    		e=argv[i+1];
    		//ifstream ifile(argv[i+1]);
    	}
    	else if(argv[i]==d)
    	{
    		freopen(argv[i+1], "w", stdout);
    	}
    	else if(argv[i]==a)
    	{
    		m=0;
    		int len=strlen(argv[i+1]);
    		for(int j=0;j<len;j++)
    		{
    			m=m*10+argv[i+1][j]-'0';
    		}
    		
    	}
    	else if(argv[i]==b)
    	{
    		n=0;
    		int len=strlen(argv[i+1]);
    		for(int j=0;j<len;j++)
    		{
    			n=n*10+argv[i+1][j]-'0';
    		}
    	}
    }
    ifstream ifile(e);
    if(n==-1)
    {
    	n=10;
    }
   	while(!ifile.eof())
   	{
   		
   		string s;
   		getline(ifile,s);
   		count_word(s);
   		if(m>=2)
   		{
   			count_phrase(m,s);
   		}
   		
   		count_characters(s);
   		count_line(s);
   	}
   	sort(count_s,count_s+word_l,com);
   	sort(p,p+cc,cmp);
   	cout<<"characters: "<<c_c-1<<endl;
   	cout<<"words: "<<sum<<endl;
   	cout<<"lines: "<<c_l<<endl;
   	if(m==-1||m==1)
   	{
   		for(int i=0;i<min(n,word_l);i++)
   		{
   			cout<<"<"<<count_s[i].s<<">: ";
   			if(i==min(n,word_l)-1)
   			{
   				cout<<count_s[i].count;
   			}
   			else
   			{
   				cout<<count_s[i].count<<endl;
   			}
   			
   		}
   	}
   	else if(m>=2)
   	{
	   	for(int i=0;i<min(n,cc);i++)
	   	{
	   		cout<<"<"<<p[i].name<<">: ";
	   		if(i==min(n,cc)-1)
	   		{
	   			cout<<p[i].count;
	   		}
	   		else
	   		{
	   			cout<<p[i].count<<endl;
	   		}
	   		
	   	}
   	}
    return 0;
    
}

/*w.exe -i input.txt -o output.txt -m 3 -n 10*/


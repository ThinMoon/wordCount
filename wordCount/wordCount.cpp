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
void input ()//huan
{
	
}

int count_characters(string )//lin
{
	
}

int count_line(string )//hu
{
   int len = s.length();
   int num=1;
   for(int j=0;j<len;j++){
   	if(s[j]=='\n'){
   		num++;
   	}
   }
   return num;
}

int count_word(string )//wu
{
	
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

string lowcase(string )//wang
{
	
}

int count_phrase(int m,string s)//zhang
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
			}
		
		}
		else if(s[i]!=' '&&!(s[i]>='a'&&s[i]<='z')&&!(s[i]>='A'&&s[i]<='Z')&&!(s[i]>='0'&&s[i]<='9'))
		{
			de(c);
			if(c==m-1)
			{
				string low=lowcase(tp);
				bool flag=is_word(low);
				de(flag);
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

void output()//ye
{
    out_file<<"characters:"<<count_characters(s)<<endl;
    out_file<<"words:"<<count_word(s)<<endl;
    out_file<<"lines:"<<count_line(s)<<endl;
    for(int i=0;i<cc;i++)
    ofs<<"<"<<p[i].name<<">"<<": "<<p[i].count<<endl;
	
}

int main()//wen
{
	
} 


bool cmp(int a,int b)//sort qiu
{
	if(rank[a]>rank[b])return a>b;
	else if(rank[a]==rank[b])return word[a]<word[b];
}













int main()
{
 	std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
	cin>>n>>m;
	 
}




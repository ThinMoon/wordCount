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

struct count_string	//wu
{
	string s;
	int count=0;
}count_s[100];
int word_l=0;

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

bool com(struct count_string a,struct count_string b)	//wu
{
	if(a.count!=b.count)
		return a.count>b.count;
	else
		a.s<b.s;
}
string lowcase(string a_str);//wu
int count_word(string arr)//wu
{
	int sum=0;
	char c[30]={0};
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
				if(j==arr.length()-1)
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
		sort(count_s,count_s+word_l,com);
		return sum;
}

bool is_word(string )//zou
{
	
}

string lowcase(string )//wang
{
	
}

int count_phrase(int m,string )//zhang
{
	
}

void output()//ye
{
	
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




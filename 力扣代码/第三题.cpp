#include <bits/stdc++.h>
using namespace std;
//string getPreString(string s)
//{
//	for(int i=0;i<s.size();i++){
//		if(s[i]=='a'){
//			return "NULL";
//		}
//		else
//		{
//			if(i==s.size()-1){
//				s[i]=char(s[i]-1);
//			}
//		}
//	}
//	return s;
//}
//string getSString(string s,int l,int r)
//{
//	return s.substr(l-1,r-l+1);
//}
int main()
{
	string s;
	int q;
	cin>>s>>q;
//	cout<<s<<endl<<q<<endl;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		//��ȡ�Ӵ� 
		string ss=s.substr(l-1,r-l+1);
	//	cout <<ss<<endl;
		//Ȼ���� Ѱ����һ���Ĵ���
		//����ȫ����a���ַ����� 
		bool IsOk=false;
		//ע�⣬дsize��ʱ����ü�һ��(int)�� 
		for(int i=0;i<(int)ss.size();i++){
			if(ss[i]!='a'){
				IsOk=true;
			}
		}
		if(IsOk==false){
			cout<<"NULL"<<endl<<"Happy Chinese New Year!"<<endl;
		}
		else
		{
			int pos=-1;
			//������a��������ҵ���һ������a���ַ�����ʹ��--��
			//����ע�� 
			for(int i=ss.size()-1;i>=0;i--){
				if(ss[i]!='a'){
					pos=i;
					ss[i]--;
					break; 
				}
			}
			//��֮����ַ��������z�� 
			for(int i=pos+1;i<ss.size();i++){
				ss[i]='z';
			}
			cout<<ss<<endl; 	
			if(s.find(ss)!=-1)
				cout<<"Happy New Year!"<<endl;
			else
				cout<<"Happy Chinese New Year!"<<endl;
		}
	}
	return 0;
}

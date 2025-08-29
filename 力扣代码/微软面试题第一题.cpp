#include <bits/stdc++.h>
using namespace std;
bool isSubPath(const string& path1,const string& path2)
{

	size_t pos =path2.find(path1);
	if(pos==0)
	{
		if(path2.length()==path1.length()|| path2[path1.size()] == '/'){
			return true;
		}
	}
	return false;
}
bool comparePath(const string&a, const string&b)
{
	return a.size()<b.size();
} 

//С��Onƽ���ķ�����
vector<string> removeSubfolders(vector<string>& folder) {
     //��ϣ���ϣ����Ƚ����е�·������һ��unordered_set�У��������Կ��ٲ���·���Ƿ���ڣ�ʱ�临�Ӷ�Ϊ O (1)��
	 unordered_set<string> set;
     for (const string& f : folder) {
         set.insert(f);
         
     }
// 	for(auto str :set){
//	 	cout<<"set_insert: "<<str<<endl;
//	 }
     vector<string> result; 
     for (const string& f : folder) {
         bool isSubfolder = false;
         int len = f.length();
         /*
         �����жϣ�����ÿ��·��������ÿ��·�������������ǰ׺�Ƿ���unordered_set�С��������һ��ǰ׺��unordered_set�У�˵����·����һ�����ļ��У�������ΪisSubfolder�� 
		 */
         for (int i = 1; i < len; ++i) {
             if (f[i] == '/' && set.count(f.substr(0, i)) > 0) {
                 isSubfolder = true;
                 break;
             }
         }
         /*���һ��·���������ļ��У���������������С�*/
         if (!isSubfolder) {
             result.push_back(f);
         }
     }
 
     return result;
 }
//���Թ���ʾ�ķ�������������
vector<string> removeSubfolders_sortversion(vector<string>& folder) {
    // �����ֵ�����ļ���·���������� 
    sort(folder.begin(), folder.end());
    vector<string> result;
    // �������ĵ�һ���ļ���·���������б�
    result.push_back(folder[0]);

    // �ӵڶ����ļ���·����ʼ����
    for (int i = 1; i < (int)folder.size(); ++i) {
        const string& prev = result.back();
        const string& curr = folder[i];
        // ��鵱ǰ�ļ���·���Ƿ���ǰһ���ļ���·�������ļ���
        if (curr.length() > prev.length() && 
            curr.substr(0, prev.length()) == prev && 
            curr[prev.length()] == '/') {
            // �����ļ��У�����
            continue;
        }
        // �������ļ��У��������б�
        result.push_back(curr);
    }
    return result;
} 
 
int main()
{
	vector<string> paths={"a/b/c","a/b","c/d/e","c/d/e/f"};
	vector<string> result;
//	sort(paths.begin(),paths.end());
//	for(auto str:paths){
//		cout<<str<<endl;
//	} 
	result=removeSubfolders_sortversion(paths);
	for(const string& str : result)
	{
		cout<<str<<endl;
	} 
	//��򵥵ķ��������ǰ�������ַ����� 
//	for(const string& path: paths){
//		bool isSubFolder=false;
//		for(const string& otherPath:paths){
//			if(isSubPath(otherPath,path)&& path !=otherPath){
//				isSubFolder=true;
//				break;
//			}
//		}
//		if(!isSubFolder){
//			result.push_back(path);
//		}
//	}


//	sort(paths.begin(),paths.end(),comparePath);
////	�㷨ʹ��nlogn()��ʱ�临�Ӷȣ����������Լ������� 
//	for(const string& path: paths){
//		bool isSubFolder =false;
//		for(const string& otherPath:paths)
//		{
//			if(path!=otherPath&&otherPath.size()>=path.size()&&otherPath.substr(0,path.size())==path){
//				isSubFolder=true;
//				break;
//			}
//			if(!isSubFolder){
//				result.push_back(path);
//			}
//		}
//	}
//	for(const string &r : result){
//			cout<<r<<endl;
//		}
	return 0;
}

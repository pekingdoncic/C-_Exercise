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

//小于On平方的方案：
vector<string> removeSubfolders(vector<string>& folder) {
     //哈希集合：首先将所有的路径存入一个unordered_set中，这样可以快速查找路径是否存在，时间复杂度为 O (1)。
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
         遍历判断：遍历每个路径，对于每个路径，检查其所有前缀是否在unordered_set中。如果存在一个前缀在unordered_set中，说明该路径是一个子文件夹，将其标记为isSubfolder。 
		 */
         for (int i = 1; i < len; ++i) {
             if (f[i] == '/' && set.count(f.substr(0, i)) > 0) {
                 isSubfolder = true;
                 break;
             }
         }
         /*如果一个路径不是子文件夹，则将其加入结果向量中。*/
         if (!isSubfolder) {
             result.push_back(f);
         }
     }
 
     return result;
 }
//面试官提示的方法：利用排序！
vector<string> removeSubfolders_sortversion(vector<string>& folder) {
    // 按照字典序对文件夹路径进行排序 
    sort(folder.begin(), folder.end());
    vector<string> result;
    // 将排序后的第一个文件夹路径加入结果列表
    result.push_back(folder[0]);

    // 从第二个文件夹路径开始遍历
    for (int i = 1; i < (int)folder.size(); ++i) {
        const string& prev = result.back();
        const string& curr = folder[i];
        // 检查当前文件夹路径是否是前一个文件夹路径的子文件夹
        if (curr.length() > prev.length() && 
            curr.substr(0, prev.length()) == prev && 
            curr[prev.length()] == '/') {
            // 是子文件夹，跳过
            continue;
        }
        // 不是子文件夹，加入结果列表
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
	//最简单的方法，就是挨个检测字符串！ 
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
////	算法使用nlogn()的时间复杂度：利用排序以及其他的 
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

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:

};


#ifdef DEBUG_IN_MY_COMPUTER

int main() {
	Solution s;
	cout << (1 << 31) << endl;;
	cout << s.divide(10, 3) << endl;;
	cout << s.divide(10, 0) << endl;;
	cout << s.divide(10, -1) << endl;;
	cout << s.divide(1 << 31, -1) << endl;;
	cout << s.divide(1 << 31, 0) << endl;;
	cout << s.divide(1 << 31, 2) << endl;;
	cout << s.divide(7, -3) << endl;;
	cout << s.divide(7, 3) << endl;;
	return 0;
}

#endif

/*


${workspaceFolder} :表示当前workspace文件夹路径，也即/home/Coding/Test

${workspaceRootFolderName}:表示workspace的文件夹名，也即Test

${file}:文件自身的绝对路径，也即/home/Coding/Test/.vscode/tasks.json

${relativeFile}:文件在workspace中的路径，也即.vscode/tasks.json

${fileBasenameNoExtension}:当前文件的文件名，不带后缀，也即tasks

${fileBasename}:当前文件的文件名，tasks.json

${fileDirname}:文件所在的文件夹路径，也即/home/Coding/Test/.vscode

${fileExtname}:当前文件的后缀，也即.json

${lineNumber}:当前文件光标所在的行号

${env:PATH}:系统中的环境变量
————————————————
版权声明：本文为CSDN博主「古古有它」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/endurehero/article/details/80100991
*/
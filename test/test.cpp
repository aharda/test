#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct FileInclude
{
	int sum_if = 0;
	int sum_else = 0;
	int sum_else_if = 0;
	int sum_int = 0;
	int sum_long = 0;
	int sum_double = 0;
	int sum_switch = 0;
	int sum_while = 0;
};
int main()
{
	bool Match(FileInclude &F, string parameter);
	string file_name ="C:\\Users\\尘埃不如海水\\Desktop\\t.txt";
	string file_word;
	fstream fin;
	fin.open(file_name.c_str());
	bool flag = 0;
	FileInclude f;
	while(fin>>file_word)
	{
		cout<<file_word<<endl;	
	}
}

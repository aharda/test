#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;
struct FileInclude
{
	int sum = 0;
	int sum_switch_case = 0;
	int sum_if_else = 0;
	int sum_if_elseif_else = 0;
	int sum_case[100] = {0};
	int case_number = 0;
};
int main()
{
	void Mycout(FileInclude &f,int rank);
	bool Match(FileInclude &F, string parameter,queue<string> & S);
	void FileScan(string file_name, int rank);
	void KeywordstackMatch(FileInclude &F, queue<string> & S);
	
	int rank;
	string file_name = "C:\\Users\\尘埃不如海水\\Desktop\\text.txt";
//	cout<<"请输入文件地址：";
//	cin>>file_name; 
	cout<<"请输入完成等级：";
	cin>>rank;
	FileScan(file_name,rank);

 } 
 
 void FileScan(string file_name, string rank)
 {
 	string file_word;
	fstream fin;
	fin.open(file_name.c_str());
	bool flag = 0;
	FileInclude f;
	queue<string> keyword_queue;
	while (fin>>file_word)
	//while (getline(fin,file_word))
	{
		cout<<file_word<<endl;
		flag = Match(f,file_word);
		if (flag == 1)
		{
			fin>>file_word;
			cout<<file_word<<endl;
			if((file_word[0]=='i'&&file_word[1]=='f' && file_word[2] =='(') || file_word == "if")
			{
				keyword_queue.push("elseif");
			}
			else
			{
				keyword_queue.push("else");
			}
			flag = 0;
		}
	}
	KeywordqueueMatch(f,keyword_queue);
	MyCout(f,rank);
 }
 
 void KeywordqueueMatch(FileInclude &f,queue<string> & keyword_queue)
 {

 	while(!keyword_queue.empty == 0)
 	{
 		if(keyword_queue.front == "if")
 		{
 			keyword_queue.pop;
 			if(keyword_queue.front == "else")
 			{
 				keyword_queue.pop;
 				f.sum_if_else++;
			}
			else if(keyword_queue.front == "elseif")
			{
				keyword_queue.pop;
				if(keyword_queue.front == "else")
				{
					keyword_queue.pop;
					f.sum_if_elseif_else++;
				}
			}
		}
		else if(keyword_queue.front == "switch")
		{
			keyword_queue.pop;
			
			while(keyword_queue.front == "case" && !keyword_queue.empty == 0)
			{
				f.sum_case[f.case_number]++;
				keyword_queue.pop;
			}
			f.case_number++;
		}
		else
		{
			keyword_queue.pop;
		}
	 }
 }
 
 void Mycout(FileInclude &f,int rank)
 {
 	cout<<"total num: "<<f.sum<<endl;
 	if(rank >= 2)
 	{
 		int i = f.case_number;
 		int j = 0;
 		cout<<"switch num: "<<f.sum_switch<<endl;
 		cout<<"case num: ";
 		while(i--)
 		{
 			cout<<f.sum_case[j]<<' ';
 			j++
		}
 		
	}
	else if(rank >=3)
	{
		cout<<"if-else num: "<<f.sum_if_else<<endl;
	}
	else if(rank >= 4)
	{
		cout<<if-elseif-else num: <<f.sum_if_elseif_else<<endl;
	}
 }
 
bool Match(FileInclude &f, string parameter, queue<string> &keyword_queue)
 {
 //	cout<<parameter<<endl;
 	if(parameter == "int")
 	{
 //		cout<<parameter<<endl;
 		keyword_queue.push("int");
 		f.sum++;
	 }
	 
	else if(parameter == "long")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("long");
		f.sum++;
	}
	
	else if(parameter == "double")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("double");
		f.sum++;
	}
	
	else if((parameter[0] == 'i' && parameter[1] == 'f' && parameter[2] == '(') || parameter == "if")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("if");
		f.sum++;
	}
	
	else if(parameter[0] == 'e' && parameter[1] == 'l' && parameter[2] == 's' && parameter[3] == 'e')
	{
//		cout<<parameter<<endl;
		
		f.sum++;
		return 1;
	}
	
	else if(parameter[0] == 'c' && parameter[1] == 'a' && parameter[2] == 's' && parameter[3] == 'e')
	{
//		cout<<parameter<<endl;
		keyword_queue.push("case");
		f.sum++;
		return 1;
	}
	
	else if((parameter[0] == 'w' && parameter[1] == 'h' && parameter[2] == 'i' && parameter[3] == 'l' && parameter[4] == 'e' && parameter[5] == '(') || parameter =="while")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("while");
		f.sum++;
	}
	
	else if((parameter[0] == 's' && parameter[1] == 'w' && parameter[2] == 'i' && parameter[3] == 't' && parameter[4] == 'c' && parameter[5] == 'h' && parameter[6] == '(') || parameter =="switch") 
 	{
 //		cout<<parameter<<endl;
 		keyword_queue.push("switch");
 		f.sum++;
	 }
	 return 0;
 }

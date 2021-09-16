#include<fstream>
#include<string>
#include<queue>
#include<iostream>
#include<stack>
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
	void MyCout(FileInclude &f,int rank);
	bool Match(FileInclude &F, string parameter,queue<string> & S);
	void KeywordqueueMatch(FileInclude &F, queue<string> & S);
	
	int rank;
	string file_name ;//= "C:\\Users\\尘埃不如海水\\Desktop\\text.txt";
	cout<<"请输入文件地址：";
	cin>>file_name; 
	cout<<"请输入完成等级：";
	cin>>rank;
	int s = file_name.length();
//	cout<<"0"<<s<<endl;
	stack <char> temp;
	while(s--)
	{
	//	cout<<file_name[s]<<endl;
		temp.push(file_name[s]);
	}
	file_name = "";
//	cout<<"4"<<file_name<<endl;
	while(!temp.empty())
	{
		file_name+=temp.top();
//		cout<<file_name;
		if(temp.top() == '\\')
			file_name += '\\';
		temp.pop();
	}
//	cout<<"2"<<file_name<<endl;
	
	string file_word;
	fstream fin;
	fin.open(file_name.c_str());
	bool flag = 0;
	FileInclude f;
	queue<string> keyword_queue;
	while (fin>>file_word)
	//while (getline(fin,file_word))
	{
	//	cout<<file_word<<endl;
		flag = Match(f,file_word,keyword_queue);

		if(flag == 1)
		{
			fin>>file_word;
	//		cout<<file_word<<endl;
			if((file_word[0]=='i'&&file_word[1]=='f' && file_word[2] =='(') || file_word == "if" )
			{
				keyword_queue.push("elseif");
				f.sum++;

			}
			else
			{
				keyword_queue.push("else");
			}
		}
	}

	KeywordqueueMatch(f,keyword_queue);

	MyCout(f,rank);
	fin.close();

 } 
  void KeywordqueueMatch(FileInclude &f,queue<string> & keyword_queue)
 {
 	int i,j=0;
 	stack <string> temp;
 	while(!keyword_queue.empty())
 	{
//		cout<<keyword_queue.front()<<endl;
//		keyword_queue.pop();
 
		if(keyword_queue.front() == "if")
		{	
			temp.push(keyword_queue.front());
			keyword_queue.pop();
		}
		else if(keyword_queue.front() == "elseif")
		{

			temp.push(keyword_queue.front());
			keyword_queue.pop();
	//		cout<<keyword_queue.front()<<endl;;

		}
		
		else if(keyword_queue.front() == "else")
		{

			if(temp.top() == "if")
			{
//				cout<<i<<"   "<<temp.top()<<endl;
				i++;
				f.sum_if_else++;
				temp.pop();
			 } 
			else 
			{
				
				while(temp.top() == "elseif" && !temp.empty())
				{
					temp.pop();
				}
				if(!temp.empty())
				{
//					cout<<j<<"  elseif "<<temp.top()<<endl;
					j++;
					f.sum_if_elseif_else++;
					temp.pop();
				}
			}
			keyword_queue.pop();
	//		cout<<keyword_queue.front()<<endl;;

		}
		
		else if(keyword_queue.front() == "switch")
		{
		//	cout<<keyword_queue.front()<<endl;
			keyword_queue.pop();
			
			while((keyword_queue.front() == "case" || keyword_queue.front() == "break" || keyword_queue.front() == "default") && !keyword_queue.empty())
			{
		//		cout<<keyword_queue.front();
				if(keyword_queue.front() == "case")
					f.sum_case[f.case_number]++;

				keyword_queue.pop();
			}
			f.case_number++;
		}
		else
		{
				keyword_queue.pop();
		}
	}
}

void MyCout(FileInclude &f,int rank)
{
	void cout2(FileInclude &f);
	void cout3(FileInclude &f);
	void cout4(FileInclude &f);

 	cout<<"total num: "<<f.sum<<endl;
 	if(rank == 2)
 		cout2(f);
 	else if(rank == 3)
 	{
 		cout2(f);
 		cout3(f);
	 }
 	else
	{
 		cout2(f);
 		cout3(f);
 		cout4(f);
	 }
	
//	switch(rank)
// 	{
// 	case 4:	cout<<"if-elseif-else num: "<<f.sum_if_elseif_else<<endl;
// 	
// 	case 3: cout<<"if-else num: "<<f.sum_if_else<<endl;
// 	
// 	case 2:{
// 		int i = f.case_number;
// 		int j = 0;
// 		cout<<"switch num: "<<f.sum_switch_case<<endl;
// 		cout<<"case num: ";
// 		while(i--)
// 		{
// 			cout<<f.sum_case[j]<<' ';
// 			j++;
//		}
//		break;
//	 }
//	}
 
 }
 
 	void cout2(FileInclude &f)
	{
		int i = f.case_number;
 		int j = 0;
 		cout<<"switch num: "<<f.sum_switch_case<<endl;
 		cout<<"case num: ";
 		while(i--)
 		{
 			cout<<f.sum_case[j]<<' ';
 			j++;
		}
		cout<<endl;
	}
	void cout3(FileInclude &f)
	{
		cout<<"if-else num: "<<f.sum_if_else<<endl;
	}
	void cout4(FileInclude &f)
	{
		cout<<"if-elseif-else num: "<<f.sum_if_elseif_else<<endl;
	}
	
	
 bool Match(FileInclude &f, string parameter, queue<string> &keyword_queue)
 {
 //	cout<<parameter<<endl;
 	if(parameter == "int")
 	{
// 		cout<<parameter<<endl;
 		keyword_queue.push("int");
		f.sum++;
	 }
	 
	else if(parameter == "long")
	{
////		cout<<parameter<<endl;
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
	
	else if((parameter[0] == 'e' && parameter[1] == 'l' && parameter[2] == 's' && parameter[3] == 'e' && parameter[4] == '{') || parameter == "else" ) 
	{ 
//		cout<<parameter<<endl;
		f.sum++;
		if((parameter[0] == 'e' && parameter[1] == 'l' && parameter[2] == 's' && parameter[3] == 'e' && parameter[4] == '{') ) //防止出现else {if} 这种情况将字符串变为 elseif； 
		{
			keyword_queue.push("else");
		}
		else 
		{
			return 1;
		}
	}
		
	else if(parameter[0] == 'c' && parameter[1] == 'a' && parameter[2] == 's' && parameter[3] == 'e')
	{
//		cout<<parameter<<endl;
		keyword_queue.push("case");
		f.sum++;
	}

	else if(parameter[0] == 'a' && parameter[1] == 'u' && parameter[2] == 't' && parameter[3] == 'o')
	{
//		cout<<parameter<<endl;
		keyword_queue.push("auto");
		f.sum++;
	}

	else if((parameter[0] == 'b' && parameter[1] == 'r' && parameter[2] == 'e' && parameter[3] == 'a' && parameter[4] == 'k' && parameter[5] == ';') || parameter =="break")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("break");
		f.sum++;
	}
	
	else if((parameter[0] == 'd' && parameter[1] == 'e' && parameter[2] == 'f' && parameter[3] == 'a' && parameter[4] == 'u' && parameter[5] == 'l' && parameter[6] == 't' && parameter[7] == ':') || parameter =="default")
	{
//		cout<<parameter<<endl;
		keyword_queue.push("default");
		f.sum++;
	}
	
	else if((parameter[0] == 'r' && parameter[1] == 'e' && parameter[2] == 't' && parameter[3] == 'u' && parameter[4] == 'r' && parameter[5] == 'n'))
	{
//		cout<<parameter<<endl;
		keyword_queue.push("return");
		f.sum++;
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
 		f.sum_switch_case++;
	 }
	 return 0;
 }

#include<iostream>


//题目三
//		题目描述：
//定义对字符串插入一个字符、删除一个字符、替换一个字符的操作分别为i，d，r。例如，给定字符串abcdef，i 1 c代表在第1个字符处插入字符c，操作完成后的字符串为cabcdef。请根据题目要求，运算出相应操作之后的字符串。
//
//输入：
//第一行为输入的字符串S（长度1<L<=15）；第二行一个整数N（1<=N<=20）表示接下来有N组操作，每次都是对初始输入的字符串进行操作。
//
//输出：
//相应操作时候的字符串。当插入位置大于字符串长度时，将插入的字符放置在字符串末尾；删除或替换的位置大于或小于字符串长度时，直接输出原有字符串。操作除i，d，r外，均属非法操作，此时输出原有字符串。
//样例输入：
//abcdef
//4
//i 2 c
//		d 1
//r 1 b
//		i 10 c
//		样例输出：
//acbcdef
//		bcdef
//bbcdef
//		abcdefc

int my_strlen(char *s){
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return i;
}


// 越界检查在函数中
// 所有函数均复制一份， 主要是保持s不变。 说来这样其实降低插入时候移位复杂度
// 稍微复杂点是 \0 位置。 我的my_len算出来len的位置应该是\0 我直接加3 保证什么操作都能放下

char* my_insert(char *s, int pos, char c){
	int len = my_strlen(s);
	if(pos<0) return s;
	char *p = new char[len+3];
	for(int i=0; i<len; i++){
		p[i] = s[i];
	}
	if(pos >=len){
		p[len] = c;
		p[len+1] = '\0';
		return p;
	}
	for(int i=pos; i<len; i++){
		p[i+1] = s[i];
	}
	p[pos] = c;
	p[len + 2] = '\0';
	return p;
}


char* my_delete(char *s, int pos){
	// s最后必须有\0 
	//本函数不保证这个
	int len = my_strlen(s);
	if(pos < 0 || pos >= len){ return s;}


	char *p = new char[len+3];
	for(int i=0; i<len; i++){
		p[i] = s[i];
	}
	

	for(int i=pos; i<len; i++){
		p[i] = s[i + 1];
	}
	p[len] = '\0';
	return p;
}


char * my_replace(char *s, int pos, char c){
	int len = my_strlen(s);
	if(pos < 0 || pos >= len){ return s;}

	char *p = new char[len+3];
	for(int i=0; i<len; i++){
		p[i] = s[i];
	}

	p[pos] = c;
	p[len] = '\0';
	return p;
}






int main(){
	char ap[20];
	int n;
	std::cin>>ap;
	std::cin>>n;
	char op;
	for(int i=0; i<n; i++){
		std::cin>>op;
		// 该用switch 写法忘记了
		if(op == 'i'){
			int pos; char c;
			std::cin>>pos>>c;
			std::cout<<my_insert(ap,pos-1,c)<<std::endl;
		}else if (op == 'd') {
			int pos;
			std::cin>>pos;
			std::cout<<my_delete(ap,pos-1)<<std::endl;
		}else if (op == 'r') {
			int pos; char c;
			std::cin>>pos>>c;
			std::cout<<my_replace(ap,pos-1,c)<<std::endl;
		}else {
			std::cout<<ap<<std::endl;
		}
	}
}


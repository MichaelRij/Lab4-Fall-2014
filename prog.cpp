#include <cstdio>
#include <cctype>	//	Lab 4   Dictionary Thing by MichaelRij 5034140
#include <iostream>

using namespace std;

#define  NUMWORDS 100
#define WORDSIZE 22
int word=0;
char dict [NUMWORDS][WORDSIZE]={0};
int dicFreq[NUMWORDS]={0};
	
int strLength(int str){ //	with parameter without length error message
	int i=0;
	while(dict[str][i]!=0){
		 i++;
		if(i==WORDSIZE)break;
	}
return i;
}
int strLengthP(int str){ //	with parameter with length error message only gets run by printDict
	int i=0;
	while(dict[str][i]!=0){
		 i++;
		if(i==WORDSIZE){
			cout << "*";
			break;
		}
	}
return i;
}
int strLength(){ // 	no parameter should only runs on dict[word]
	int i=0;
	while(dict[word][i]!=0){
		i++;
		if(i==WORDSIZE)break;
	}
return i;
}
void printDict(){ //	Print out the dictionary
	int length = 0,tab=0;
	cout<<"\nNOTE: * means this word has been shortened because it was beyond the allowed length.\n\n";
	cout<<"Word		Frequency\n";
	cout<<"--------------------------\n";
	for(int i=0; i < word; i++){
		length = strLengthP(i);
//		cout<<i<<") ";
		for(int j=0; j < length; j++) 
			cout.put(dict[i][j]);
		tab=(WORDSIZE-length)/8;
		if(length%8==7)tab++;// handles a special case
		while(tab-->=0)cout << "	";
		cout << dicFreq[i]<<"\n";
	}
}

bool unique(){//	checks if string is unique
	bool same = false;
	int length = strLength();
	if(length==0)return false; //	skip if empty string
	for(int i=0;i<word;i++){    //go through the list of previous words 
		if(length==strLength(i)){
			same = true;
			for(int j=0; j < length; j++){ //	start checking each letter
				if(dict[i][j]!=dict[word][j]) {
					same = false;
					break;
				}
			}
			if(same){//		the word is alredy in dict
				dicFreq[i]+=1;
				for(int j=0; j < length; j++)// clear dict[word]
					dict[word][j]=0;
				return false;
			}
		}	
	}
	dicFreq[word]=1;
	word++;
	return true;
}
void fillDict(){//	fills the dictionary
	int i = 0;
	char ch;
	while( cin.good() ){
		ch = cin.get();
		if ( isalpha(ch) ) { /* function test if ch  is A-Z, a-z */
			if(ch>64 && ch<=90)ch+=32;  //convert A-Z to a-z
			dict[word][i++]=ch;
		}
		else if (ch==' '||ch=='\n'){//
			unique();
			if(word==NUMWORDS){
				cout<<"The list is full so you cant add any more words. Sorry.\n";
				break;
			}
			i=0;
		}
	}
}
int main() {
	fillDict();
	printDict();
	return 0;
	
}

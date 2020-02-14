#include <bits/stdc++.h> 
#include<string.h> 
using namespace std; 



int compare (const void * a, const void * b); 


void allLexicographicRecur (char *str, char* data, 
							int last, int index,int count,int &n, bool &complete) 
{ 
	int i, len = strlen(str); 
	// One by one fix all characters at 
	// the given index and recur for 
	// the/ subsequent indexes 
	for ( i = 0; i < len && !complete; i++ ) 
	{ 
		// Fix the ith character at index 
		// and if this is not the last 
		// index then recursively call 
		// for higher indexes 
		data[index] = str[i] ; 

		// If this is the last index then 
		// print the string stored in 
		// data[] 
		if (index == last && !complete){
            n+=strlen(data);
            if(n>=count){

			cout << data[(n-1)%count]<<"  "<< n<<"  "<<data<<endl;
            complete=true;
            }
        }
		else // Recur for higher indexes 
			allLexicographicRecur (str, data, last, index+1,count, n,complete); 
	} 
} 


void allLexicographic(char *str, int count, int &n, bool &complete) 
{ 
	int len = strlen (str) ; 
    if(complete)
        return;
	
	char *data = (char *) malloc (sizeof(char) * (len + 1)) ; 
	data[len] = '\0'; 



	qsort(str, len, sizeof(char), compare); 
    
    
	// Now print all permutaions 
	allLexicographicRecur (str, data, len-1, 0, count,n,complete); 

	// Free data to avoid memory leak 
	free(data); 
} 

// Needed for library function qsort() 
int compare (const void * a, const void * b) 
{ 
	return ( *(char *)a - *(char *)b ); 
} 

// Driver code 
int main() 
{ 
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    int num, index;
    cin>>num;
	int k;
    for(int i=0;i<num;i++){
    	cin>>k>>index;
		char st[k];
		for(int j=0; j<k;j++)
			st[j]=str[j];
		
		char temp[strlen(st)]; 
		int n=0;
		bool complete=false;
		for(int j =0;j<strlen(st);j++){
			temp[j]=st[j];
			// cout<<"For j = "<<j<<endl;
			allLexicographic(temp,index,n,complete);
		}                            
    }
	return 0; 
} 


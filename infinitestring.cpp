#include<iostream>
#include<cstring>
#include<climits>
using namespace std; 

// An optimized version that uses reverse instead of sort for 
// finding the next permutation 


int compare (const void *a, const void * b)  
{ return ( *(char *)a - *(char *)b ); }  

void swap (char* a, char* b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
}  

int findCeil (char str[], char first, int l, int h)  
{  
    // initialize index of ceiling element  
    int ceilIndex = l;  
  
    // Now iterate through rest of the elements and find  
    // the smallest character greater than 'first'  
    for (int i = l+1; i <= h; i++)  
    if (str[i] > first && str[i] < str[ceilIndex])  
            ceilIndex = i;  
  
    return ceilIndex;  
}  
// A utility function to reverse a string str[l..h] 
void reverse(char str[], int l, int h) 
{ 
	while (l < h) 
	{ 
		swap(&str[l], &str[h]); 
		l++; 
		h--; 
	} 
} 

// Print all permutations of str in sorted order 
bool sortedPermutations ( char str[], int index, int j ) 
{ 
	// Get size of string 
	// int size = strlen(str);
    int size = j; 
    int n=0;
	// Sort the string in increasing order 
	qsort( str, size, sizeof( str[0] ), compare ); 

	// Print permutations one by one 
	bool isFinished = false; 
	while ( ! isFinished ) 
	{ 
		// print this permutation 
		cout << str << endl;
        n+=strlen(str);
        if(n>index){
            cout<<str[n%index];            
            return true;
        }
		// Find the rightmost character which 
		// is smaller than its next character. 
		// Let us call it 'first char' 
		int i; 
		for ( i = size - 2; i >= 0; --i ) 
		if (str[i] < str[i+1]) 
			break; 

		// If there is no such character, all 
		// are sorted in decreasing order, 
		// means we just printed the last 
		// permutation and we are done. 
		if ( i == -1 ) 
			isFinished = true; 
		else
		{ 
			// Find the ceil of 'first char' in 
			// right of first character. 
			// Ceil of a character is the 
			// smallest character greater than it 
			int ceilIndex = findCeil( str, str[i], i + 1, size - 1 ); 

			// Swap first and second characters 
			swap( &str[i], &str[ceilIndex] ); 

			// reverse the string on right of 'first char' 
			reverse( str, i + 1, size - 1 ); 
		} 
	} 
    return false;
} 

int main()  
{  
    int n = 10;
    char str[] = "ABCDEF"; 
    char temp[strlen(str)]; 
    int index=53;
    for(int j =0;j<strlen(str);j++){
        temp[j]=str[j];
        if(sortedPermutations( temp,index,j+1))
            break;  
    }
    return 0;  
}  

#include <stdio.h>

void Permutation(char* pStr, char* pBegin);   


void Permutation(char* pStr, char* pBegin)  
{  
	if(!pStr || !pBegin)  
	  return;  

	if(*pBegin == '\0')  
	{  
		printf("%s\n", pStr);  
	}  
	else  
	{  
		char *pCh;
		for(pCh = pBegin; *pCh != '\0'; ++ pCh)  
		{  
			// swap pCh and pBegin  
			char temp = *pCh;  
			*pCh = *pBegin;  
			*pBegin = temp;  

			Permutation(pStr, pBegin + 1);    
			// restore pCh and pBegin  
			temp = *pCh;  
			*pCh = *pBegin;  
			*pBegin = temp;  
		}  
	}  
} 

int main(int argc, char **argv)
{ 
	Permutation(argv[1],argv[1]);
	getchar();
	return 0;
}

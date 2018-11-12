#include "myas.h"
//syntax check
int is_valid(char *op, char *args)
{
	char* ptr = strtok(args,",");//cut by ','
	char* ptr2;
	ptr2=strtok(NULL,"");//divide

	if(strcmp(op,"mov")==0){//op==mov?
		if(((ptr[0]=='0')&&(ptr[1]=='x'))||(ptr[0]=='(')||((ptr[0]=='-')&&(ptr[1]=='0')&&(ptr[2]=='x'))){//mem->
			if(((ptr2[0]=='0')&&(ptr2[1]=='x'))||(ptr2[0]=='(')||((ptr2[0]=='-')&&(ptr2[1]=='0')&&(ptr2[2]=='x')))//mem->mem
				return 0;
			else//mem-> others
				return 1;
		}
	else if(ptr[0]=='$'){//immediate->
		if(ptr2[0]=='$')//immediate->immediate
			return 0;
		else
			return 1;
	}
	else if(ptr2[0]=='$')//somewhere->immediate
		return 0;
	else
		return 1;
	}
	return 0;
}

	}	
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/

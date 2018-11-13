#include "myas.h"
	/*         syntax check         */

int is_valid(char *op, char *args)	//valid or not
{
	char args_[256]="";
	strcpy(args_,args);
	char* ptr = strtok(args_, ",  ");
	int a=strlen(ptr);
	char* ptr2;
	ptr2 = strtok(args_+a+1, "\0");      // cut by token

	if (strcmp(op, "mov") == 0) {//op==mov?
		if (((ptr[0] == '0') && (ptr[1] == 'x')) || (ptr[0] == '(') || ((ptr[0] == '-') && (ptr[1] == '0') && (ptr[2] == 'x'))) {//mem->
			if (((ptr2[0] == '0') && (ptr2[1] == 'x')) || (ptr2[0] == '(') || ((ptr2[0] == '-') && (ptr2[1] == '0') && (ptr2[2] == 'x')))//mem->mem
				return 0;

			else//mem-> not mem
				return 1;
		}
		else if (ptr[0] == '$') {//immediate->
			if (ptr2[0] == '$')//immediate->immediate
				return 0;
			else
				return 1;
			
		}
		else if (ptr2[0] == '$')//somewhere->immediate
			return 0;
		else
			return 1;	
	}
	return 0;
}

#include "myas.h"
/*    generate machine code     */
int instr_trans(char *op, char *args, char* mcode)// check syntax 
{
	if (!is_valid(op, args)) {		//유효한지 확인
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	strcpy(mcode, "AB CD EF");
	
	char args_[256]="";
	strcpy(args_,args);
	char* ptr = strtok(args_, ",");	//,를 기준으로 토큰나누기/From 
	int a=strlen(ptr);	
	char* ptr2;
	ptr2 = strtok(args_+a+1, "\0");		// 다음 문자열을 잘라서 포인터를 반환/To

	if (strcmp(ptr, "%eax") == 0 || strcmp(ptr, "%ecx") == 0 || strcmp(ptr, "%edx") == 0 || strcmp(ptr, "%ebx") == 0 || strcmp(ptr, "%esp") == 0 || strcmp(ptr, "%ebp") == 0 || strcmp(ptr, "%esi") == 0 || strcmp(ptr, "%edi") == 0) {	//register to something
		if (strcmp(ptr, "%eax") == 0) {	//reg(%eax)->
			if ((ptr2[0] == '0'&&ptr2[1] == 'x') || ((ptr2[0] == '(') && (ptr2[1] == '%'))) {		//reg(%eax)->mem
				strcpy(mcode, "a3");
				return 1;
			}
			else if (strcmp(ptr2, "%eax") == 0 || strcmp(ptr2, "%ecx") == 0 || strcmp(ptr2, "%edx") == 0 || strcmp(ptr2, "%ebx") == 0 || strcmp(ptr2, "%esp") == 0 || strcmp(ptr2, "%ebp") == 0 || strcmp(ptr2, "%esi") == 0 || strcmp(ptr2, "%edi") == 0) {//reg(%eax)->reg
				strcpy(mcode, "89");
				return 1;
			}
			else
				return 0;
		}
		else if (strcmp(ptr2, "%eax") == 0 || strcmp(ptr2, "%ecx") == 0 || strcmp(ptr2, "%edx") == 0 || strcmp(ptr2, "%ebx") == 0 || strcmp(ptr2, "%esp") == 0 || strcmp(ptr2, "%ebp") == 0 || strcmp(ptr2, "%esi") == 0 || strcmp(ptr2, "%edi") == 0) {//reg->reg
			strcpy(mcode, "89");
			return 1;
		}
		else
			return 0;
	}
	else if ((ptr[0] == '-') && (ptr[1] == '0') && (ptr[2] == 'x')) {	//mem(disp)->
		if (strcmp(ptr2, "%eax") == 0 || strcmp(ptr2, "%ecx") == 0 || strcmp(ptr2, "%edx") == 0 || strcmp(ptr2, "%ebx") == 0 || strcmp(ptr2, "%esp") == 0 || strcmp(ptr2, "%ebp") == 0 || strcmp(ptr2, "%esi") == 0 || strcmp(ptr2, "%edi") == 0) {	//mem(disp)->reg
			strcpy(mcode, "8b");
			return 1;
		}
		else
			return 0;
	}
	else if ((ptr[0] == '0'&&ptr[1] == 'x') || (ptr[0] == '('&&ptr[1] == '%')) {//mem->
		if (strcmp(ptr2, "%eax") == 0) {//mem->reg(%eax)
			strcpy(mcode, "a1");
			return 1;
		}
		else if (strcmp(ptr2, "%eax") == 0 || strcmp(ptr2, "%ecx") == 0 || strcmp(ptr2, "%edx") == 0 || strcmp(ptr2, "%ebx") == 0 || strcmp(ptr2, "%esp") == 0 || strcmp(ptr2, "%ebp") == 0 || strcmp(ptr2, "%esi") == 0 || strcmp(ptr2, "%edi") == 0) {//mem->reg
			strcpy(mcode, "8b");
			return 1;
		}
		else {//mem->others
			return 0;
		}
	}

	else if (ptr[0] == '$') {	//immediate to something 
		if (strcmp(ptr2, "%eax") == 0){
			strcpy(mcode, "b8");
			return 1;
		}

		else if (strcmp(ptr2, "%ecx") == 0) {
			strcpy(mcode, "b9");
			return 1;
		}
		else if (strcmp(ptr2, "%edx") == 0) {
			strcpy(mcode, "ba");
			return 1;
		}
		else if(strcmp(ptr2, "%ebx") == 0){
			strcpy(mcode, "bb");
			return 1;
		}
		else if(strcmp(ptr2, "%esp") == 0){
			strcpy(mcode, "bc");
			return 1;
		}
		else if(strcmp(ptr2, "%ebp") == 0){
			strcpy(mcode, "bd");
			return 1;
		}
		else if(strcmp(ptr2, "%esi") == 0){
			strcpy(mcode, "be");
			return 1;
		}
		else if(strcmp(ptr2, "%edi") == 0){
			strcpy(mcode, "bf");
			return 1;
		}
		else 	//nothing
			return 0;

	}
	else
		return 0;
}

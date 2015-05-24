#include <stdio.h>

int main()
{
	FILE *in=popen("dig +short myip.opendns.com @resolver1.opendns.com", "r");
	char tmp[2560]={0x0};
	while(fgets(tmp,sizeof(tmp),in)!=NULL)
	{
	
		printf("%s", tmp);
    /* mess with the tmp string it has the results of the netstat command */
	}

	FILE *file = fopen("hello.txt", "w");
	fputs(tmp, file);
	fclose(file);
		
	pclose(in);
	in = popen("./dropbox_uploader.sh upload ./hello.txt hello.txt", "r");
	while(fgets(tmp,sizeof(tmp),in)!=NULL)
	{
	
		printf("%s", tmp);
    /* mess with the tmp string it has the results of the netstat command */
	}


	pclose(in);
}

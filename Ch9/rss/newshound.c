#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char* feeds[] = {"https://www.reddit.com/r/news/.rss",
					 "https://rss.msn.com/en-au/",
					 "tinybuddha.com/feed"}; 

	int times = 3; 
	char* phrase = argv[1]; 
    const char* path = "./";

	int i; 

	for(i=0; i<times; i++)
	{
		char var[255]; 
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		puts(feeds[i]);
		char* vars[] = {var, NULL}; 
		if( execle(path, path,"./rssgossip.py", phrase, NULL, vars)==-1)
		{
			fprintf(stderr, "Can't run script: %s\n", strerror(errno)); 
			return 1; 
		}
	}

	return 0; 
}
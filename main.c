#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void show_error_message()
{
	printf("%s\n", "Invalid parameter.");
	printf("%s\n", "Usage: hiddenfiles parameter");
	printf("%s\n", "	on|true - Show hidden files.");
	printf("%s\n", "	off|false - Hide files.");
	printf("%s\n", "	-v|--version - Show the binary version.\n");
}

int main(int argc, char const *argv[])
{
	if (argc >= 2)
	{
		if (strcmp(argv[1], "on") == 0 || strcmp(argv[1], "true") == 0)
		{
			system("defaults write com.apple.finder AppleShowAllFiles TRUE && killall Finder");
			printf("%s\n", "All hidden files and directories are visible now.");
		}
		else if (strcmp(argv[1], "off") == 0 || strcmp(argv[1], "false") == 0)
		{
			system("defaults write com.apple.finder AppleShowAllFiles FALSE && killall Finder");
			printf("%s\n", "All hidden files and directories are invisible now.");
		}
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
		{
			printf("%s\n", "hiddenfiles v1.1 - 10-23-2015");
		}
		else
		{
			show_error_message();
		}
	}
	else
	{
		show_error_message();
	}
	return 0;
}

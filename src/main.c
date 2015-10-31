#include <stdio.h>
#include <windows.h>

char *get_clipboard_content(void) {
	OpenClipboard(NULL);
	HANDLE data = GetClipboardData(CF_TEXT);
	GlobalLock(data);
	char *c = (char*) data;
	GlobalUnlock(data);

	return c;
}

int main(void) {
	return 0;
}

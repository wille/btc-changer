#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define DELAY 1000

void set_clipboard_content(char *text) {
	HGLOBAL x = GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE, 64);
	char *y = (char*) GlobalLock(x);

	strcpy(y, text);
	GlobalUnlock(x);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, x);
	CloseClipboard();
}

char *get_clipboard_content(void) {
	OpenClipboard(NULL);
	HANDLE data = GetClipboardData(CF_TEXT);
	GlobalLock(data);
	char *c = (char*) data;
	GlobalUnlock(data);

	return c;
}

int main(void) {
	while (true) {
		char *c = get_clipboard_content();

		printf(c);

		Sleep(DELAY);
	}

	return 0;
}

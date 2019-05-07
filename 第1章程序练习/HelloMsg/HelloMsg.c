#include<Windows.h>
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPreInstance, LPSTR IpCmdLine, int nShowCmd)
{
	MessageBox(NULL, TEXT("Hello,Windows!"), TEXT("HelloMsg"), 0);
	return 0;
}
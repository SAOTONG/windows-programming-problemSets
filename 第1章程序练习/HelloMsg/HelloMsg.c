#include<Windows.h>
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPreInstance, LPSTR IpCmdLine, int nShowCmd)
{
	MessageBox(NULL, TEXT("Hello,Windows!"), TEXT("HelloMsg"), 2);
	return 0;
}
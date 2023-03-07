#include <windows.h>
#include <stdio.h>

HWND textfield,textbox1,textbox2,buttonp,buttonmi,buttonmu,buttond;
char textsaved1[50];
char textsaved2[50];
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) 
	{
		case WM_CREATE: {
			textfield = CreateWindow("STATIC","Please input two numbers",WS_VISIBLE | WS_CHILD,33,20,175,20,hwnd,NULL,NULL,NULL);
			textbox1 = CreateWindow("Edit","",WS_VISIBLE | WS_CHILD | WS_BORDER,50,52,140,20,hwnd,NULL,NULL,NULL);
			textbox2 = CreateWindow("Edit","",WS_VISIBLE | WS_CHILD | WS_BORDER,50,84,140,20,hwnd,NULL,NULL,NULL);
			buttonp = CreateWindow("BUTTON","+",WS_VISIBLE | WS_CHILD | WS_BORDER,65,125,20,20,hwnd,(HMENU) 1,NULL,NULL);
			buttonmi = CreateWindow("BUTTON","-",WS_VISIBLE | WS_CHILD | WS_BORDER,90,125,20,20,hwnd,(HMENU) 2,NULL,NULL);
			buttonmu = CreateWindow("BUTTON","*",WS_VISIBLE | WS_CHILD | WS_BORDER,115,125,20,20,hwnd,(HMENU) 3,NULL,NULL);
			buttond = CreateWindow("BUTTON","/",WS_VISIBLE | WS_CHILD | WS_BORDER,140,125,20,20,hwnd,(HMENU) 4,NULL,NULL);
			break;
		}
		case WM_COMMAND:{
			double gettext1 = 0;
			double gettext2 = 0;
			double result;
			char t[100];
			gettext1 = GetWindowText(textbox1,&textsaved1[0],50);
			gettext2 = GetWindowText(textbox2,&textsaved2[0],50);
			switch (LOWORD(wParam))
			{
				case 1:
					result = atof(textsaved1)+atof(textsaved2);
					sprintf(t,"%f",result);
					::MessageBox(hwnd,t,"Result",MB_OK);
					break;
				case 2:
					result = atof(textsaved1)-atof(textsaved2);
					sprintf(t,"%f",result);
					::MessageBox(hwnd,t,"Result",MB_OK);
					break;
				case 3:
					result = atof(textsaved1)*atof(textsaved2);
					sprintf(t,"%f",result);
					::MessageBox(hwnd,t,"Result",MB_OK);
					break;
				case 4:
					result = atof(textsaved1)/atof(textsaved2);
					sprintf(t,"%f",result);
					::MessageBox(hwnd,t,"Result",MB_OK);
					break;
			}
			break;
		}

		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd; 
	MSG msg; 

	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = CreateSolidBrush(RGB(204, 237, 29));
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}


	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
		TranslateMessage(&msg); 
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

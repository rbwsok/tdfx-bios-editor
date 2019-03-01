#include "stdafx.h"

struct BIOSPARAM
{
 unsigned char* lpLabel1; // указатель на 1-ую часть выводимого сообщения
 unsigned char* lpsizel;  // указатель на размер строки
 int maxlenlabel1;        // максимальная длина строки
 int lenlabel1;           // текущая длина строки
 
 unsigned char* lpLabel2; // указатель на 2-ую часть выводимого сообщения
 unsigned char* lpsize2;  // указатель на размер строки
 int maxlenlabel2;        // максимальная длина строки
 int lenlabel2;           // текущая длина строки
 
 unsigned char* lpData;   // указатель на строку с датой
 unsigned char data[10];  // копия строки с датой
 int maxlendata;          // максимальная длина строки
 int lendata;             // текущая длина строки

 unsigned char* lppciinit0;
 unsigned int pciinit0;
 unsigned char* lpmiscinit0;
 unsigned int miscinit0;
 unsigned char* lpmiscinit1;
 unsigned int miscinit1;
 unsigned char* lpdraminit0;
 unsigned int draminit0;
 unsigned char* lpdraminit1;
 unsigned int draminit1;
 unsigned char* lpagpinit0;
 unsigned int agpinit0;
 unsigned char* lppllctrl0;
 unsigned int pllctrl0;
 unsigned char* lppllctrl1;
 unsigned int pllctrl1;
 bool bpllctrl1;
 unsigned char* lpsgrammode;
 unsigned int sgrammode;

 char* font8x8;
 int offsetf8x8;
 char* font8x14;
 int offsetf8x14;
 char* font8x16;
 int offsetf8x16;
 char* tfont9x14;
 int offsetf9x14;
 int lentfont9x14;
 char* tfont9x16;
 int offsetf9x16;
 int lentfont9x16;

 unsigned char* pcir;
 
 unsigned char* lpProductName;
 int maxlenprname;
 unsigned char* lpProductRev;
 int maxlenprrev;
 unsigned char* lpVendorName;
 int maxlenvenname;
 unsigned char* lpVendorInfo;
 int maxlenveninfo;

 unsigned char* vmodeinfo;
 unsigned char* extvmodeinfo;

 unsigned int cmppciinit0;
 unsigned int cmpmiscinit0;
 unsigned int cmpmiscinit1;
 unsigned int cmpdraminit0;
 unsigned int cmpdraminit1;
 unsigned int cmpagpinit0;
 unsigned int cmppllctrl0;
 unsigned int cmppllctrl1;
 unsigned int cmpsgrammode;

 unsigned char* lpPatchLogoCode;
};

struct VMODEPARAM 
{
 char modetext[49]; // название
 int vnum;
 int extvnum;
};

VMODEPARAM vmodet[] = {
{"Mode 00h   - 40x25 Color Text (8x8 Font)"        ,0 ,0 },
{"Mode 01h   - 40x25 Color Text (8x8 Font)"		   ,1 ,1 },
{"Mode 0*    - 40x25 Color Text (8x14 Font)"	   ,19,19},
{"Mode 1*    - 40x25 Color Text (8x14 Font)"	   ,20,20},
{"Mode 0+/1+ - 40x25 Color Text (8x16 Font)"	   ,23,23},
{"Mode 02h   - 80x25 Color Text (8x8 Font)"		   ,2 ,2 },
{"Mode 03h   - 80x25 Color Text (8x8 Font)"		   ,3 ,3 },
{"Mode 07h   - 80x25 Mono Text (8x14 Font)"		   ,7 ,7 },
{"Mode 2*    - 80x25 Color Text (8x14 Font)"	   ,21,21},
{"Mode 3*    - 80x25 Color Text (8x14 Font)"	   ,22,22},
{"Mode 2+/3+ - 80x25 Color Text (8x16 Font)"	   ,24,24},
{"Mode 7+    - 80x25 Mono Text (8x16 Font)"		   ,25,25},
{"Mode 108h  - 80x60 Color Text (8x8 Font)"		   ,16,16},
{"Mode 109h  - 132x25 Color Text (8x16 font)"	   ,29,29},
{"Mode 10Ah  - 132x43 Color Text (8x8 font)"	   ,30,30},
{"Mode 10Bh  - 132x50 Color Text (8x8 font)"	   ,31,31},
{"Mode 10Ch  - 132x60 Color Text (8x8 font)"       ,32,32},
{"Mode 04h   - 320x200 4-color CGA (8x8 Font)"	   ,4 ,4 },
{"Mode 05h   - 320x200 4-color CGA (8x8 Font)"	   ,5 ,5 },
{"Mode 0Dh   - 320x200 16-color planar (8x8 Font)" ,13,13},
{"Mode 13h   - 320x200 256-color VGA (8x8 Font)"   ,28,28},
{"Mode 180h  - 320x200 8 bpp (8x8 Font)"		   ,33,33},
{"Mode 10Eh  - 320x200 16 bpp (8x8 Font)"		   ,33,37},
{"Mode 10Fh  - 320x200 24 bpp (8x8 Font)"		   ,33,38},
{"Mode 181h  - 320x240 8 bpp (8x8 Font)"	       ,34,34},
{"Mode 182h  - 320x240 16 bpp (8x8 Font)"		   ,34,39},
{"Mode 183h  - 320x240 24 bpp (8x8 Font)"	       ,34,40},
{"Mode 184h  - 400x300 8 bpp (8x8 Font)"		   ,35,35},
{"Mode 185h  - 400x300 16 bpp (8x8 Font)"		   ,35,41},
{"Mode 186h  - 400x300 24 bpp (8x8 Font)"		   ,35,42},
{"Mode 187h  - 512x384 8 bpp (8x14 Font)"          ,36,36},
{"Mode 188h  - 512x384 16 bpp (8x14 Font)"		   ,36,43},
{"Mode 189h  - 512x384 24 bpp (8x14 Font)"		   ,36,44},
{"Mode 06h   - 640x200 2-color CGA (8x8 Font)"	   ,6 ,6 },
{"Mode 0Eh   - 640x200 16-color planar (8x8 Font)" ,14,14},
{"Mode 0Fh   - 640x350 2-color (8x14 Font)"        ,17,17},
{"Mode 10h   - 640x350 16-color (8x14 Font)"	   ,18,18},
{"Mode 100h  - 640x400 8 bpp (8x16 Font)"          ,8 ,8 },
{"Mode 18Ah  - 640x400 16 bpp (8x16 Font)"		   ,8 ,45},
{"Mode 18Bh  - 640x400 24 bpp (8x16 Font)"         ,8 ,46},
{"Mode 11h   - 640x480 2-color planar (8x16 Font)" ,26,26},
{"Mode 12h   - 640x480 16-color planar (8x16 Font)",27,27},
{"Mode 101h  - 640x480 8 bpp (8x16 Font)"          ,9 ,9 },
{"Mode 111h  - 640x480 16 bpp (8x16 Font)"		   ,9 ,47},
{"Mode 112h  - 640x480 24 bpp (8x16 Font)"         ,9 ,48},
{"Mode 102h  - 800x600 16-color (8x16 Font)"	   ,10,10},
{"Mode 103h  - 800x600 8 bpp (8x16 Font)"          ,11,11},
{"Mode 114h  - 800x600 16 bpp (8x16 Font)"		   ,11,49},
{"Mode 115h  - 800x600 24 bpp (8x16 Font)"		   ,11,50},
{"Mode 105h  - 1024x768 8 bpp (8x16 Font)"		   ,15,15},
{"Mode 117h  - 1024x768 16 bpp (8x16 Font)"		   ,15,51},
{"Mode 118h  - 1024x768 24 bpp (8x16 Font)"        ,15,52},
{"Mode 107h  - 1280x1024 8 bpp (8x16 Font)"		   ,12,12},
{"Mode 11Ah  - 1280x1024 16 bpp (8x16 Font)"	   ,12,53},
{"Mode 11Bh  - 1280x1024 24 bpp (8x16 Font)"	   ,12,54},
};

struct rcolor 
{
 int start;
 int end;
 DWORD color;
};

rcolor *rcol;

int curcol = 0;

struct dev
{
 unsigned int vendorid;
 unsigned int deviceid;
 int high;
 char *vendorname;
 char devicename[20];
};

struct ven
{
 char vendorname[32];
};

ven vend[] = {
{"3Dfx Interactive, Inc."},
{"Alliance Semiconductor"},
{"Macronix International Co Ltd"},
{"ATI Technologies Inc"},
{"nVidia Corp"},
};

dev vd[] = {
// 3Dfx Interactive, Inc.
{0x121a,0x0003,0,vend[0].vendorname,"Banshee-based card"},
{0x121a,0x0005,0,vend[0].vendorname,"Avenger-based card"},
{0x121a,0x0009,0,vend[0].vendorname,"Napalm-based card"},
{0x121a,0x000b,0,vend[0].vendorname,"Napalm2-based card"},
{0x121a,0x0010,0,vend[0].vendorname,"Rampage-based card"},
// Alliance Semiconductor
{0x1142,0x643D,0,vend[1].vendorname,"Voodoo Rush"},
// Macronix International Co Ltd                                
{0x10d9,0x8626,0,vend[2].vendorname,"Voodoo Rush"},
// ATI Technologies
{0x1002,0x51,  1,vend[3].vendorname,"R2xx-based card"},
{0x1002,0x41,  1,vend[3].vendorname,"R3xx-based card"},
{0x1002,0x4E,  1,vend[3].vendorname,"R3xx-based card"},
{0x1002,0x4A,  1,vend[3].vendorname,"R4xx-based card"},
// nVidia Corp
{0x10DE,0x0020,0,vend[4].vendorname,"NV4-based card"},
{0x10DE,0x00,  1,vend[4].vendorname,"NV5-based card"},
{0x10DE,0x01,  1,vend[4].vendorname,"NV1x-based card"},
{0x10DE,0x02,  1,vend[4].vendorname,"NV2x-based card"},
};

unsigned char proc_viewlogo1[] = {
// push es
0x06,
// mov ax,0012h
0xb8,0x12,0x00,
// int 10h
0xcd,0x10,
// mov     bp,cs
0x8c,0xcd,
// mov     es,bp
0x8e,0xc5};

unsigned char proc_viewlogo2[]=
{
// mov si,offset szLogo
0xbe, 0,0,
// mov ah,0ch
0xb4,0x0c,
// xor bx,bx
0x33,0xdb,
// xor dx,dx
0x33,0xd2,
//l2:
// xor cx,cx
0x33,0xc9,
//l1:
// mov al,es:[si]
0x26,0x8a,0x04,
// shr al,4
0xc0,0xe8,0x04,
// inc cx
0x41,
// int 10h
0xcd,0x10,
// mov al,es:[si]
0x26,0x8a,0x04,
// and al,0fh
0x24,0x0f,
// inc cx
0x41,
// int 10h
0xcd,0x10,
// inc si
0x46};

unsigned char proc_viewlogo3[] =
{
// cmp cx,64
0x83,0xF9,0, // xres
// jnz l1
0x75,0xe9,
// inc dx
0x42};

unsigned char proc_viewlogo4[] =
{
// cmp dx,48
0x83,0xfa,0, // yres
// jnz l2
0x75,0xe1};

unsigned char proc_viewlogo5[] =
{
// mov ax,1301h
0xb8,0x01,0x13,
// mov bx,7
0xbb,0x07,0x00,
// mov cx,szstr2-szstr1
0xb9,0,0,
// mov dx,9
0xba,0x09,0x00,
// mov bp,offset szstr1
0xbd,0,0,
// int 10h
0xcd,0x10};

unsigned char proc_viewlogo6[] =
{
// pop es
0x07,
// retn
0xc3};

bool loadingbios = false,otapply = true,rtapply = true,dapply = true,vesaapply = true;
bool loadingcmpbios = false;
double mgz;
unsigned int k,m,n,tmp,scol;
unsigned int cmppciinit0,cmpmiscinit0,cmpmiscinit1,cmpdraminit0,cmpdraminit1,cmpagpinit0;
unsigned int cmppllctrl0,cmppllctrl1,cmpsgrammode;

BOOL res;
HINSTANCE hInst,hRTFLib;
HWND hmWnd,hpw[10];
RECT rcogl,winbox;
HBITMAP hFontBitmap = 0,hBigFontBitmap = 0,hLogo = 0;
HDC hfontDC,hbigfontDC,hLogoDC;
LOGFONT logfont;
HFONT hFont;
int lenbios = 256*256,fontmode = 0,actpage = 0,curviewdump, dumpview, curcodepage = 0;
int lencmpbios = 256*256;
unsigned char *bios,*bios2,*fontimage = 0,*textbuf,*bigfont = 0,*cmpbios,*bitmapi;
BITMAPINFO bmi[2],bigbmi[2],*bmilogo;
CHARFORMAT cf;
CHARRANGE cr;
BIOSPARAM biosparam;
POINT pt;
unsigned char *cpifile = 0;
char tx_equal[] = "equals";
char tx_diff[] = "differs";
char *bitmap = 0,*bmpoffset = 0;
int xbmp,ybmp;
static char szFilter[] = "BIOS file (*.rom;*.bin)\0*.rom;*.bin\0All files (*.*)\0*.*\0\0";
static char szFileName[_MAX_PATH];
char szTitleName[_MAX_FNAME + _MAX_EXT] ;

int LoadBios(int fname);
bool SaveBios(void);
void ViewTabPage(int curt,HWND hWnd);
void InitProperty(HWND hWnd);
LRESULT CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AboutProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc4(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc5(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc6(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc7(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc8(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc9(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc10(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc11(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc12(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc13(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc14(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc15(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc16(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc17(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void PutBitmap(HWND hWnd);
void DrawBitmap(HDC hDC, int x, int y, HBITMAP hBitmap);
void ViewDump(HWND hwnd,int pos, int sel);
bool AnalyzeBios(void);
void TextToBin(unsigned int num,char* buf);
void ViewFont(int fo);
int LoadFont(void);
void CalcCRC(void);
int SaveFont(void);
void GetCountCodePage(HWND hwnd);
void View3Font(HWND hDlg);
void GetChFont(HWND hDlg);
void ViewVideoMode(HWND hDlg);
bool LoadCMPBios(HWND hDlg);
bool AnalyzeCMPBios(void);
void CMPreg(HWND hDlg);
int LoadBMPLogo(void);
void SetLogoToBios(HWND hDlg);
void DrawDump(HWND hwnd);
int AltFindFont(int fontmode);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,int       nCmdShow)
{
 MSG msg;
 hInst = hInstance;

 static char mutexname[] = "tdfxbioseditor";
 HANDLE hh = OpenMutex(MUTEX_ALL_ACCESS, false, mutexname);
 if (hh == 0) hh = CreateMutex(0, false, mutexname);
  else return 0;

 if (hh == 0) return 0;



 memset(&biosparam,0,sizeof(BIOSPARAM));
 biosparam.bpllctrl1 = false;

 hRTFLib = LoadLibrary("RICHED32.DLL");
 if(!hRTFLib) return 0;

 // объект шрифта
 GetObject(GetStockObject(SYSTEM_FIXED_FONT),sizeof(LOGFONT),&logfont);
 hFont = CreateFontIndirect(&logfont);

 bios = (unsigned char *)malloc(lenbios);
 memset(bios,0,256*256);
 bios2 = (unsigned char *)malloc(lenbios);
 memset(bios2,0,256*256);
 cmpbios = (unsigned char *)malloc(lenbios);
 memset(cmpbios,0,256*256);
 textbuf = (unsigned char *)malloc(1024*1024);

 rcol = (rcolor *)malloc(0xff*0xff);

 hmWnd = CreateDialog(hInst, (LPCTSTR)IDD_MAINDLG, HWND_DESKTOP, (DLGPROC)WndProc );

 while (GetMessage(&msg, NULL, 0, 0))
 {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }

 return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 int t;
 switch (message)
 {
  case WM_INITDIALOG:
       InitProperty(hDlg);
       ViewTabPage(0,hDlg);
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
		case ID_EXIT:
			 SendMessage(hDlg, WM_DESTROY, 0, 0);
             break;
		case ID_ABOUT:
			 DialogBox(hInst,MAKEINTRESOURCE(IDD_ABOUT),hDlg,(DLGPROC)AboutProc);
             break;
        case ID_RELOAD:
			 if (loadingbios == false) break;
			 t = LoadBios(1);
			 goto l1;
		case ID_LOAD:
             t = LoadBios(0);
l1:;
             if (t == 1)
			 {
              MessageBox(hDlg,"BIOS loading error!!!","ERROR",MB_ICONHAND | MB_OK);
			  break;
			 }
			 if (t == 2) break;

			 loadingbios = false;
			 ViewDump(hpw[1],0,0);
			 AnalyzeBios();
             if (loadingcmpbios == true) CMPreg(hpw[3]);
			 if (biosparam.vmodeinfo != 0) ViewVideoMode(hpw[6]);
             SendDlgItemMessage(hpw[0],IDC_8X8,BM_SETCHECK,1,0);
             SendDlgItemMessage(hpw[0],IDC_8X14,BM_SETCHECK,0,0);
             SendDlgItemMessage(hpw[0],IDC_8X16,BM_SETCHECK,0,0);
             SetDlgItemText(hpw[0],IDC_LOADFONT,"Load Font 8x8");
			 SetDlgItemText(hpw[0],IDC_SAVEFONT,"Save Font 8x8");
             SetDlgItemText(hpw[0],IDC_OFFSETTABLE,"0");
			 ViewFont(0);
             		 
			 if (actpage == 0)
			 {
              UpdateWindow(hpw[0]);
			  ShowWindow(hpw[0],SW_NORMAL);
			 }
			 SendMessage(hpw[0],WM_PAINT,0,0);
			 loadingbios = true;

			 break;
		case ID_SAVE:
             if (loadingbios == true)
			 {
			  CalcCRC();
			  SaveBios();
			  ViewDump(hpw[1],0,0);
			 }
			 break;
		case ID_HELP:
             ShellExecute(0,"open","tdfxbios.chm",0,0,SW_SHOWMAXIMIZED | SW_MAXIMIZE);
			 break;
	   }
	   break;
  case WM_CLOSE:
  case WM_DESTROY:
       if (hRTFLib) FreeLibrary(hRTFLib);
	   if (hFont) DeleteObject(hFont);
	   if (hFontBitmap) DeleteObject(hFontBitmap);
	   if (bios != 0) free(bios);
	   bios = 0;
	   if (bios2 != 0) free(bios2);
	   bios2 = 0;
	   if (cmpbios != 0) free(cmpbios);
	   cmpbios = 0;
	   if (textbuf != 0) free(textbuf);
       textbuf = 0;
	   PostQuitMessage(0);
       break;
  case WM_NOTIFY:
       LPNMHDR pnmh = (LPNMHDR) lParam;
       switch (pnmh->code)
       {
        case TCN_SELCHANGE:
             ViewTabPage(TabCtrl_GetCurSel(GetDlgItem(hDlg,IDC_TAB1)),hDlg);
             break;
       }
       break;
 }
 return FALSE;
}

LRESULT CALLBACK AboutProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
 switch (iMsg)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   SetDlgItemText(hDlg,IDC_MAIL,"rbws@mail.ru");
	   SetDlgItemText(hDlg,IDC_WEB,"www.voodoodrivers.org");
       break;
  case WM_COMMAND :
       switch (LOWORD (wParam))
	   {
        case IDOK :
             EndDialog (hDlg, 0) ;
             return TRUE ;
	   }
       break;
 }
 return FALSE;
}

bool AnalyzeBios(void)
{
 int maxlen,i,plogo = 0;
 unsigned int reg,reg1,reg2;
 unsigned char *vctext,*vcr1,*vcr2;
 int blbios = 0;

 cmppciinit0 = biosparam.cmppciinit0;  
 cmpmiscinit0 = biosparam.cmpmiscinit0;
 cmpmiscinit1 = biosparam.cmpmiscinit1;
 cmpdraminit0 = biosparam.cmpdraminit0;
 cmpdraminit1 = biosparam.cmpdraminit1;
 cmpagpinit0 = biosparam.cmpagpinit0;
 cmppllctrl0 = biosparam.cmppllctrl0;
 cmppllctrl1 = biosparam.cmppllctrl1;
 cmpsgrammode = biosparam.cmpsgrammode;
 memset(&biosparam,0,sizeof(BIOSPARAM));
 biosparam.bpllctrl1 = false;
 biosparam.cmppciinit0 = cmppciinit0;  
 biosparam.cmpmiscinit0 = cmpmiscinit0;
 biosparam.cmpmiscinit1 = cmpmiscinit1;
 biosparam.cmpdraminit0 = cmpdraminit0;
 biosparam.cmpdraminit1 = cmpdraminit1;
 biosparam.cmpagpinit0 = cmpagpinit0;
 biosparam.cmppllctrl0 = cmppllctrl0;
 biosparam.cmppllctrl1 = cmppllctrl1;
 biosparam.cmpsgrammode = cmpsgrammode;

 // сброс контролов
 SetDlgItemText(hpw[2],IDC_VIEWSTARTUP,"");
 SetDlgItemText(hpw[2],IDC_VIEWSTARTUP2,"");
 SetDlgItemInt(hpw[3],IDC_PCIINIT0,0,0);
 SetDlgItemInt(hpw[3],IDC_MISCINIT0,0,0);
 SetDlgItemInt(hpw[3],IDC_MISCINIT1,0,0);
 SetDlgItemInt(hpw[3],IDC_DRAMINIT0,0,0);
 SetDlgItemInt(hpw[3],IDC_DRAMINIT1,0,0);
 SetDlgItemInt(hpw[3],IDC_AGPINIT0,0,0);
 SetDlgItemInt(hpw[3],IDC_PLLCTRL0,0,0);
 SetDlgItemInt(hpw[3],IDC_SGRAMMODE,0,0);

 SetDlgItemText(hpw[2],IDC_OFFSETVS1,"0");
 SetDlgItemInt(hpw[2],IDC_MAXLEN1,0,0);
 SetDlgItemInt(hpw[2],IDC_LENVS,0,0);
 SetDlgItemText(hpw[2],IDC_OFFSETVS2,"0");
 SetDlgItemInt(hpw[2],IDC_MAXLEN2,0,0);
 SetDlgItemInt(hpw[2],IDC_LENVS2,0,0);
 SetDlgItemText(hpw[5],IDC_VESA_VENDORINFO," ");
 SetDlgItemText(hpw[5],IDC_VESA_VENDORNAME," ");
 SetDlgItemText(hpw[5],IDC_VESA_PRODUCTNAME," ");
 SetDlgItemText(hpw[5],IDC_VESA_PRODUCTREVISION," ");
 SetDlgItemText(hpw[5],IDC_OFFSETVENDORINFO,"0");
 SetDlgItemText(hpw[5],IDC_OFFSETVENDORNAME,"0");
 SetDlgItemText(hpw[5],IDC_OFFSETPRODUCTREVISION,"0");
 SetDlgItemText(hpw[5],IDC_OFFSETPRODUCTNAME,"0");
 SetDlgItemText(hpw[5],IDC_MAXLEN1,"0");
 SetDlgItemText(hpw[5],IDC_MAXLEN2,"0");
 SetDlgItemText(hpw[5],IDC_MAXLEN3,"0");
 SetDlgItemText(hpw[5],IDC_MAXLEN4,"0");
 SetDlgItemText(hpw[7],IDC_STRING1,"");
 SetDlgItemText(hpw[7],IDC_STRING2,"");
 SetDlgItemText(hpw[7],IDC_STRING3,"");
 SetDlgItemText(hpw[7],IDC_STRING4,"");
 SetDlgItemText(hpw[7],IDC_STRING5,"");

 // поиск первой группы строк, выводимой при загрузке
 for(i=0;i<lenbios-30;i++)
 {
  // mov ax,1301h
  if (bios[i+0]  == 0xb8 && bios[i+1] == 0x01 && bios[i+2] == 0x13 &&
  // sub bh.bh
      bios[i+3]  == 0x2a && bios[i+4] == 0xff &&
  // mov bl, offst ...
      bios[i+5]  == 0x2e && 
  // mov cx, ... (длина строки)
      bios[i+10] == 0xb9 && 
  // sub dx,dx
      bios[i+13] == 0x2b && bios[i+14] == 0xd2 && 
  // mov bp,cs
      bios[i+15] == 0x8c && bios[i+16] == 0xcd && 
  // mov es,bp
      bios[i+17] == 0x8e && bios[i+18] == 0xc5 && 
  // mov bp, ... (адрес строки)
      bios[i+19] == 0xbd &&
  // int 10h
      bios[i+22] == 0xcd && bios[i+23] == 0x10)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 20));
   maxlen = (int)((unsigned short*)(bios + i + 11)[0]);
   biosparam.lpsizel = bios + i + 11;
   biosparam.lpPatchLogoCode = bios + i;
   plogo = 1;
   goto l1;
  }
 }

 for(i=0;i<lenbios-30;i++)
 {
  // rep movsw
  if (bios[i+0]  == 0xf3 && bios[i+1] == 0xa5 && 
  // mov ax, label1
      bios[i+2]  == 0xb8 && 
  // call ...
      bios[i+5]  == 0xe8 && 
  // mov cl,7
      bios[i+8]  == 0xb1 && bios[i+9]  == 0x07)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 3));
   maxlen = lstrlen((char*)vctext);
   biosparam.lpsizel = 0;
   plogo = 0;
   goto l1;
  }
 }
 goto l3;
l1:;
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[2],IDC_OFFSETVS1,(char*)textbuf);
 biosparam.lpLabel1 = vctext;
 biosparam.maxlenlabel1 = maxlen;
 biosparam.lenlabel1 = lstrlen((char*)vctext);
 SendDlgItemMessage(hpw[2],IDC_VIEWSTARTUP,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[2],IDC_VIEWSTARTUP,(char*)biosparam.lpLabel1);
 SendDlgItemMessage(hpw[2],IDC_VIEWSTARTUP,EM_LIMITTEXT,biosparam.maxlenlabel1,0);
 SetDlgItemInt(hpw[2],IDC_MAXLEN1,biosparam.maxlenlabel1,0);
 SetDlgItemInt(hpw[2],IDC_LENVS,biosparam.lenlabel1,0);

 if (plogo == 1)
 {
  memset((char*)textbuf,0,sizeof(textbuf));
  memcpy((char*)textbuf,biosparam.lpLabel1,biosparam.lenlabel1);
  vctext = (unsigned char*)strchr((char*)textbuf,0x0d);
  if (vctext == NULL) goto l3;
  vctext[0] = 0;
  SetDlgItemText(hpw[7],IDC_STRING1,(char*)textbuf);
  vctext+=2;
  vcr1 = vctext;
  vctext = (unsigned char*)strchr((char*)vctext,0x0d);
  if (vctext == NULL) goto l3;
  vctext[0] = 0;
  SetDlgItemText(hpw[7],IDC_STRING2,(char*)vcr1);
  vctext+=2;
  vcr1 = vctext;
  vctext = (unsigned char*)strchr((char*)vctext,0x0d);
  if (vctext == NULL) goto l3;
  vctext[0] = 0;
  SetDlgItemText(hpw[7],IDC_STRING3,(char*)vcr1);
  SetDlgItemText(hpw[7],IDC_STRING4,(char*)"3dfx Interactive, Inc.");
  SetDlgItemText(hpw[7],IDC_STRING5,(char*)"Total video memory:");
 }

l3:;
 // поиск второй группы строк, выводимой при загрузке
 for(i=0;i<lenbios-30;i++)
 {
  // mov ax,1301h
  if (bios[i+0]  == 0xb8 && bios[i+1] == 0x01 && bios[i+2] == 0x13 &&
  // mov dx,ds:...
      bios[i+3]  == 0x8b && bios[i+4] == 0x16 &&
  // mov bp, ... (адрес строки)
      bios[i+7] == 0xbd &&
  // mov cx,ds:[bp-2]
      bios[i+10] == 0x26 && bios[i+11] == 0x8b && bios[i+12] == 0x4e && bios[i+13] == 0xfe &&  
  // int 10h
      bios[i+14] == 0xcd && bios[i+15] == 0x10)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 8));
   maxlen = (int)((unsigned short*)(vctext-2)[0]);
   biosparam.maxlenlabel2 = 120;
   biosparam.lpsize2 = vctext - 2;
   goto l2;
  }
 }
 
 for(i=0;i<lenbios-30;i++)
 {
  // rep movsw
  if (bios[i+0]  == 0xf3 && bios[i+1] == 0xa5 && 
  // mov ax, label1
      bios[i+2]  == 0xb8 && 
  // call ...
      bios[i+5]  == 0xe8 && 
  // popa
      bios[i+8]  == 0x61)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 3));
   maxlen = lstrlen((char*)vctext);
   biosparam.maxlenlabel2 = maxlen;
   biosparam.lpsize2 = 0;
   goto l2;
  }
 }
 goto l4;
l2:;
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[2],IDC_OFFSETVS2,(char*)textbuf);
 biosparam.lpLabel2 = vctext;
 biosparam.lenlabel2 = lstrlen((char*)vctext);
 SendDlgItemMessage(hpw[2],IDC_VIEWSTARTUP2,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[2],IDC_VIEWSTARTUP2,(char*)biosparam.lpLabel2);
 SendDlgItemMessage(hpw[2],IDC_VIEWSTARTUP2,EM_LIMITTEXT,biosparam.maxlenlabel2,0);
 SetDlgItemInt(hpw[2],IDC_MAXLEN2,biosparam.maxlenlabel2,0);
 SetDlgItemInt(hpw[2],IDC_LENVS2,biosparam.lenlabel2,0);
l4:;
 // дата
 for(i=0;i<0x200;i++)
 {
  if (bios[i+0] == '/' && bios[i+3] == '/')
  {
   goto ll3;
  }
 }
 goto ll2;
ll3:;
 biosparam.lpData = bios + i - 2;
 biosparam.maxlendata = 8;
 biosparam.lendata = 8;
 memcpy(biosparam.data,biosparam.lpData,biosparam.maxlendata);
 SendDlgItemMessage(hpw[2],IDC_BIOSDATE,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[2],IDC_BIOSDATE,(char*)biosparam.data);
 SendDlgItemMessage(hpw[2],IDC_BIOSDATE,EM_LIMITTEXT,biosparam.maxlendata,0);

 wsprintf((char*)textbuf,"%04X",biosparam.lpData-bios);
 SetDlgItemText(hpw[2],IDC_OFFSETDATA,(char*)textbuf);

ll2:;

 // поиск регистров
 // pciinit0
 for(i=0;i<lenbios-30;i++)
 {
  // mov dx,cx
  if (bios[i+0]  == 0x8b && bios[i+1] == 0xd1 &&
  // add dx,4
	  bios[i+2]  == 0x83 && bios[i+3] == 0xc2 && bios[i+4] == 0x04 && 
  // mov eax,cs: ... (pciinit0)
	  bios[i+5]  == 0x66 && bios[i+6] == 0x2e && bios[i+7] == 0xa1 && 
  // or eax,edi
      bios[i+10] == 0x66 && bios[i+11] == 0x0b && bios[i+12] == 0xc7 && 
  // out dx,eax
      bios[i+13] == 0x66 && bios[i+14] == 0xef)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 8));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   goto l5;
  }
 }
 SetDlgItemText(hpw[3],IDC_OFFSETPCIINIT0,"0");
 goto l6;
l5:;
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETPCIINIT0,(char*)textbuf);
 biosparam.lppciinit0 = vctext;
 biosparam.pciinit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.pciinit0);
 SetDlgItemText(hpw[3],IDC_PCIINIT0,(char*)textbuf);
l6:;
 // draminit0,miscinit0,sgrammode
 for(i=0;i<lenbios-34;i++)
 {
  // in eax,dx
  if (bios[i+0]  == 0x66 && bios[i+1] == 0xed &&
  // and eax,fc000000h
	  bios[i+2]  == 0x66 && bios[i+3] == 0x25 && bios[i+4] == 0x00 && bios[i+5] == 0x00 && bios[i+6] == 0x00 && 
  // or eax,cs: ... (draminit0)
	  bios[i+8]  == 0x66 && bios[i+9] == 0x2e && bios[i+10] == 0x0b && bios[i+11]  == 0x06 &&
  // out dx,eax
      bios[i+14] == 0x66 && bios[i+15] == 0xef &&
  // lea dx,[si+10h]
      bios[i+16] == 0x8d && bios[i+17] == 0x54 && bios[i+18] == 0x10 &&
  // mov eax,cs: ... (miscinit0)
	  bios[i+19]  == 0x66 && bios[i+20] == 0x2e && bios[i+21] == 0xa1 &&
  // out dx,eax
      bios[i+24] == 0x66 && bios[i+25] == 0xef &&
  // lea dx,[si+34h]
      bios[i+26] == 0x8d && bios[i+27] == 0x54 && bios[i+28] == 0x34 &&
  // mov eax,cs: ... (sgrammode)
	  bios[i+29]  == 0x66 && bios[i+30] == 0x2e && bios[i+31] == 0xa1)
  {
   // draminit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 12));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // miscinit0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 22));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 32));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);
   goto l8;
  }
 }
 SetDlgItemText(hpw[3],IDC_OFFSETDRAMINIT0,"0");
 SetDlgItemText(hpw[3],IDC_OFFSETMISCINIT0,"0");
 SetDlgItemText(hpw[3],IDC_OFFSETSGRAMMODE,"0");
 goto l7;
l8:;
 // draminit0
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETDRAMINIT0,(char*)textbuf);
 biosparam.lpdraminit0 = vctext;
 biosparam.draminit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.draminit0);
 SetDlgItemText(hpw[3],IDC_DRAMINIT0,(char*)textbuf);
 // miscinit0
 wsprintf((char*)textbuf,"%04X",vcr1-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETMISCINIT0,(char*)textbuf);
 biosparam.lpmiscinit0 = vcr1;
 biosparam.miscinit0 = reg1;
 wsprintf((char*)textbuf,"%08X",biosparam.miscinit0);
 SetDlgItemText(hpw[3],IDC_MISCINIT0,(char*)textbuf);
 // sgrammode
 wsprintf((char*)textbuf,"%04X",vcr2-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETSGRAMMODE,(char*)textbuf);
 biosparam.lpsgrammode = vcr2;
 biosparam.sgrammode = reg2;
 wsprintf((char*)textbuf,"%08X",biosparam.sgrammode);
 SetDlgItemText(hpw[3],IDC_SGRAMMODE,(char*)textbuf);
l7:;
 // miscinit1,agpinit0,pllctrl0
 for(i=0;i<lenbios-30;i++)
 {
  // lea dx,[si+14h]
  if (bios[i+0]  == 0x8d && bios[i+1] == 0x54 && bios[i+2] == 0x14 &&
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,1ff40000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0xf4 && bios[i+10] == 0x1f && 
  // or eax,cs: ... (miscinit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14]  == 0x06 &&
  // call ...
      bios[i+17]  == 0xe8 &&
  // jz ...
      bios[i+20]  == 0x74 &&
  // or eax,8000h
      bios[i+22]  == 0x66 && bios[i+23] == 0x0d && bios[i+24]  == 0x00 && bios[i+25] == 0x80 && bios[i+26] == 0x00 && bios[i+27] == 0x00 &&
  // out eax,dx
      bios[i+28] == 0x66 && bios[i+29] == 0xef &&
  // lea dx,[si+20h]
      bios[i+30] == 0x8d && bios[i+31] == 0x54 && bios[i+32] == 0x20 &&
  // mov eax,cs: ... (agpinit0)
	  bios[i+33]  == 0x66 && bios[i+34] == 0x2e && bios[i+35] == 0xa1 &&
  // out dx,eax
      bios[i+38] == 0x66 && bios[i+39] == 0xef &&
  // lea dx,[si+44h]
      bios[i+40] == 0x8d && bios[i+41] == 0x54 && bios[i+42] == 0x44 &&
  // mov eax,cs: ... (pllctrl0)
	  bios[i+43]  == 0x66 && bios[i+44] == 0x2e && bios[i+45] == 0xa1)
  {
   // agpinit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 36));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // pllctrl0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 46));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 15));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);

   goto l11;
  }
 }

 // miscinit1,agpinit0,pllctrl0 (v3)
 for(i=0;i<lenbios-40;i++)
 {
  // lea dx,[si+14h]
  if (bios[i+0]  == 0x8d && bios[i+1] == 0x54 && bios[i+2] == 0x14 &&
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,1ff40000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0xf4 && bios[i+10] == 0x1f && 
  // or eax,cs: ... (miscinit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14]  == 0x06 &&
  // out eax,dx
      bios[i+17] == 0x66 && bios[i+18] == 0xef &&
  // lea dx,[si+20h]
      bios[i+19] == 0x8d && bios[i+20] == 0x54 && bios[i+21] == 0x20 &&
  // mov eax,cs: ... (agpinit0)
	  bios[i+22]  == 0x66 && bios[i+23] == 0x2e && bios[i+24] == 0xa1 &&
  // out dx,eax
      bios[i+27] == 0x66 && bios[i+28] == 0xef &&
  // lea dx,[si+44h]
      bios[i+29] == 0x8d && bios[i+30] == 0x54 && bios[i+31] == 0x44 &&
  // mov eax,cs: ... (pllctrl0)
	  bios[i+32]  == 0x66 && bios[i+33] == 0x2e && bios[i+34] == 0xa1 &&
  // out dx,eax
      bios[i+37] == 0x66 && bios[i+38] == 0xef)
  {
   // agpinit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 25));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // pllctrl0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 35));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 15));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);

   goto l11;
  }
 }
 SetDlgItemText(hpw[3],IDC_OFFSETAGPINIT0,"0");
 SetDlgItemText(hpw[3],IDC_OFFSETPLLCTRL0,"0");
 SetDlgItemText(hpw[3],IDC_OFFSETMISCINIT1,"0");
 SetDlgItemText(hpw[3],IDC_SPEED," ");
 goto l12;
l11:;
 // agpinit0
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETAGPINIT0,(char*)textbuf);
 biosparam.lpagpinit0 = vctext;
 biosparam.agpinit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.agpinit0);
 SetDlgItemText(hpw[3],IDC_AGPINIT0,(char*)textbuf);
 // pllctrl0
 wsprintf((char*)textbuf,"%04X",vcr1-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETPLLCTRL0,(char*)textbuf);
 biosparam.lppllctrl0 = vcr1;
 biosparam.pllctrl0 = reg1;
 wsprintf((char*)textbuf,"%08X",biosparam.pllctrl0);
 SetDlgItemText(hpw[3],IDC_PLLCTRL0,(char*)textbuf);

 k = biosparam.pllctrl0 & BIN8(00000011);
 m = (biosparam.pllctrl0 & BIN8(11111100)) >> 2;
 n = (biosparam.pllctrl0 & 0xff00) >> 8;
 mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
 sprintf((char*)textbuf,"%g MHz",mgz,k,m,n);
 SetDlgItemText(hpw[3],IDC_SPEED,(char*)textbuf);

 // miscinit1
 wsprintf((char*)textbuf,"%04X",vcr2-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETMISCINIT1,(char*)textbuf);
 biosparam.lpmiscinit1 = vcr2;
 biosparam.miscinit1 = reg2;
 wsprintf((char*)textbuf,"%08X",biosparam.miscinit1);
 SetDlgItemText(hpw[3],IDC_MISCINIT1,(char*)textbuf);

 // pllctrl1
 // lea dx,[si+48h]
 if (bios[i+39] == 0x8d && bios[i+40] == 0x54 && bios[i+41] == 0x48 &&
 // mov eax,cs: ... (pllctrl1)
     bios[i+42]  == 0x66 && bios[i+43] == 0x2e && bios[i+44] == 0xa1 &&
 // out dx,eax
     bios[i+47] == 0x66 && bios[i+48] == 0xef)
 {
  vctext = bios + (int)*((unsigned short*)(bios + i + 45));
  reg = (unsigned int)(((unsigned int*)vctext)[0]);
  wsprintf((char*)textbuf,"%04X",vctext-bios);
  SetDlgItemText(hpw[3],IDC_OFFSETPLLCTRL1,(char*)textbuf);
  biosparam.lppllctrl1 = vctext;
  biosparam.pllctrl1 = reg;
  biosparam.bpllctrl1 = true;
 }
 else
 {
  SetDlgItemText(hpw[3],IDC_OFFSETPLLCTRL1,(char*)"0");
  biosparam.lppllctrl1 = 0;
  biosparam.pllctrl1 = 0;
  biosparam.bpllctrl1 = false;
 }
 wsprintf((char*)textbuf,"%08X",biosparam.pllctrl1);
 SetDlgItemText(hpw[3],IDC_PLLCTRL1,(char*)textbuf);

l12:;

 // draminit1
 for(i=0;i<lenbios-30;i++)
 {
  // add dx,1ch
  if (bios[i+0]  == 0x83 && bios[i+1] == 0xc2 && bios[i+2] == 0x1c && 
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,c2000000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0x00 && bios[i+10] == 0xc2 && 
  // or eax,cs: ... (draminit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14] == 0x06)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 15));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   goto l13;
  }
 }
 SetDlgItemText(hpw[3],IDC_OFFSETDRAMINIT1,"0");
 goto l14;
l13:;
 // draminit1
 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[3],IDC_OFFSETDRAMINIT1,(char*)textbuf);
 biosparam.lpdraminit1 = vctext;
 biosparam.draminit1 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.draminit1);
 SetDlgItemText(hpw[3],IDC_DRAMINIT1,(char*)textbuf);
l14:;

 // поиск шрифтов
 // font 8x8
 for(i=0;i<lenbios-30;i++)
 {
  // mov ...,font8x8
  if (bios[i+0]  == 0xc7 && bios[i+1] == 0x06 &&
  // mov ...,cs
      bios[i+6]  == 0x8c && bios[i+7] == 0x0e &&
  // mov ...,tblvid
	  bios[i+10]  == 0xc7 && bios[i+11] == 0x06 &&  
  // mov ...,cs
	  bios[i+16] == 0x8c && bios[i+17] == 0x0e && 
  // sti
	  bios[i+20] == 0xfb)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 4));
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 14));
   reg = (unsigned int)(((unsigned short*)vcr1)[0]);
   goto l16;
  }
 }
 goto l15;
l16:;
 biosparam.offsetf8x8 = vctext-bios;
 biosparam.font8x8 = (char*)vctext;
 biosparam.vmodeinfo = bios + reg;
l15:;
 if (biosparam.font8x8 == 0 && biosparam.offsetf8x8 == 0)
 {
  for(i=0;i<lenbios-30;i++)
  {
   // mov di,font8x8
   if (bios[i+0]  == 0xbf && 
   // mov bh,8
	  bios[i+3]  == 0xb7 && bios[i+4] == 0x08 &&
   // mov al,...
	  bios[i+5]  == 0xa0 && 
   // cmp al,9
	  bios[i+8]  == 0x3c && bios[i+9] == 0x09)
   {
    vctext = bios + (int)*((unsigned short*)(bios + i + 1));
    //reg = (unsigned int)(((unsigned int*)vctext)[0]);
    goto lq16;
   }
  }
  goto lq15;
lq16:;
  biosparam.offsetf8x8 = vctext-bios;
  biosparam.font8x8 = (char*)vctext;
 }
lq15:;
 // поиск шрифтов
 // font 8x14 и font 8x16
 for(i=0;i<lenbios-30;i++)
 {
  // mov bh,14
  if (bios[i+0]  == 0xb7 && bios[i+1] == 0x0e &&
  // mov di,font8x14
      bios[i+2]  == 0xbf &&
  // cmp al,14
	  bios[i+5]  == 0x3c && bios[i+6] == 0x0e &&  
  // jbe ...
	  bios[i+7] == 0x76 &&
  // mov bh,16
	  bios[i+9]  == 0xb7 && bios[i+10] == 0x10 &&
  // mov di,font8x16
      bios[i+11]  == 0xbf)
  {
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 3));
   vcr2 = bios + (int)*((unsigned short*)(bios + i + 12));
   //reg = (unsigned int)(((unsigned int*)vctext)[0]);
   goto l17;
  }
 }
 goto l18;
l17:;
 biosparam.offsetf8x14 = vcr1-bios;
 biosparam.font8x14 = (char*)vcr1;
 biosparam.offsetf8x16 = vcr2-bios;
 biosparam.font8x16 = (char*)vcr2;
l18:;

 // tfont 9x14 и tfont 9x16
 for(i=0;i<lenbios-30;i++)
 {
  // mov di,tfont9x14
  if (bios[i+0]  == 0xbf &&
  // mov bh,0eh
	  bios[i+3]  == 0xb7 && bios[i+4] == 0x0e &&  
  // cmp ...,0eh
	  bios[i+5] == 0x83 && bios[i+6] == 0x3e && bios[i+9] == 0x0e &&
  // jbe ...
	  bios[i+10]  == 0x76 && 
  // mov di,tfont9x16
      bios[i+12]  == 0xbf &&
  // mov bh,10h
	  bios[i+15]  == 0xb7 && bios[i+16] == 0x10)
  {
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 1));
   vcr2 = bios + (int)*((unsigned short*)(bios + i + 13));
   goto l19;
  }
 }
 goto l20;
l19:;
 biosparam.tfont9x14 = (char*)vcr1;
 biosparam.offsetf9x14 = vcr1-bios;
 biosparam.tfont9x16 = (char*)vcr2;
 biosparam.offsetf9x16 = vcr2-bios;
l20:;

 // фонты voodoo rush (alliance)
 if (biosparam.font8x8 == 0 && biosparam.font8x14 == 0 && biosparam.font8x16 == 0)
 {
  for(i=0;i<lenbios-30;i++)
  {
   // mov bh,14
   if (bios[i+0]  == 0xb7 && bios[i+1]  == 0x0e &&
   // mov si,font8x14 
	  bios[i+2]  == 0xbe && 
   // jmp ...
	  bios[i+5]  == 0xeb && 

   // mov bh,8
      bios[i+7]  == 0xb7 && bios[i+8]  == 0x08 &&
   // mov si,font8x8 
	  bios[i+9]  == 0xbe && 
   // jmp ...
	  bios[i+12]  == 0xeb && 

   // mov bh,16
      bios[i+14]  == 0xb7 && bios[i+15]  == 0x10 &&
   // mov si,font8x16
	  bios[i+16]  == 0xbe)
   {
    biosparam.font8x8 = (char*)(bios + (int)*((unsigned short*)(bios + i + 10)));
    biosparam.font8x14 = (char*)(bios + (int)*((unsigned short*)(bios + i + 3)));
    biosparam.font8x16 = (char*)(bios + (int)*((unsigned short*)(bios + i + 17)));
    biosparam.offsetf8x8 = biosparam.font8x8 - (char*)bios;
    biosparam.offsetf8x14 = biosparam.font8x14 - (char*)bios;
    biosparam.offsetf8x16 = biosparam.font8x16 - (char*)bios;
	goto ll19;
   }
  }
 }
ll19:;
 // фонты voodoo rush (macronix)
 if (biosparam.font8x8 == 0 && biosparam.font8x14 == 0 && biosparam.font8x16 == 0)
 {
  for(i=0;i<lenbios-30;i++)
  {
   // mov ax,font8x8
   if (bios[i+0] == 0xb8 && 
   // cmp bl,8
	   bios[i+3] == 0x80 && bios[i+4]  == 0xfb && bios[i+5]  == 0x08 && 
   // jz ...
       bios[i+6] == 0x74 && 
   // mov ax,font8x14
       bios[i+8] == 0xb8 && 
   // cmp bl,14
	   bios[i+11] == 0x80 && bios[i+12]  == 0xfb && bios[i+13] == 0x0e && 
   // jz ...
       bios[i+14] == 0x74 && 
   // mov ax,font8x16
       bios[i+16] == 0xb8)
   {
    biosparam.font8x8 = (char*)(bios + (int)*((unsigned short*)(bios + i + 1)));
    biosparam.font8x14 = (char*)(bios + (int)*((unsigned short*)(bios + i + 9)));
    biosparam.font8x16 = (char*)(bios + (int)*((unsigned short*)(bios + i + 17)));
    biosparam.offsetf8x8 = biosparam.font8x8 - (char*)bios;
    biosparam.offsetf8x14 = biosparam.font8x14 - (char*)bios;
    biosparam.offsetf8x16 = biosparam.font8x16 - (char*)bios;
	
    biosparam.tfont9x16 = biosparam.font8x16 + 16*256;
    biosparam.offsetf9x16 = biosparam.tfont9x16 - (char*)bios;
	goto ll20;
   }
  }
 }
ll20:;

 wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x8);
 SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);

 // вычисление длин fixup таблиц
 int sym;
 char *tfont = 0;
 if (biosparam.tfont9x14 != 0)
 {
  tfont = biosparam.tfont9x14;
s2:;
  sym = (int)((unsigned char)tfont[0]);
  if (sym == 0) goto s1;
  tfont += 15;
  goto s2;
 }
s1:;
 biosparam.lentfont9x14 = tfont - biosparam.tfont9x14 + 1;

 if (biosparam.tfont9x16 != 0)
 {
  tfont = biosparam.tfont9x16;
s3:;
  sym = (int)((unsigned char)tfont[0]);
  if (sym == 0) goto s4;
  tfont += 17;
  goto s3;
 }
s4:;
 biosparam.lentfont9x16 = tfont - biosparam.tfont9x16 + 1;

 // PCIR:
 for(i=0;i<lenbios-30;i++)
 {
  if (bios[i+0] == 'P' && bios[i+1] == 'C' && bios[i+2] == 'I' && bios[i+3] == 'R')
  {
   vctext = bios + i;
   goto l22;
  }
 }
 goto l21;
l22:;
 biosparam.pcir = vctext;

 wsprintf((char*)textbuf,"%04X",vctext-bios);
 SetDlgItemText(hpw[4],IDC_OFFSETPCIR,(char*)textbuf);

 wsprintf((char*)textbuf,"%04X",(unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]));
 SetDlgItemText(hpw[4],IDC_VENDORID,(char*)textbuf);

 wsprintf((char*)textbuf,"%04X",(unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]));
 SetDlgItemText(hpw[4],IDC_DEVICEID,(char*)textbuf);

 SetDlgItemText(hpw[4],IDC_VID_COMMENT,"");
 SetDlgItemText(hpw[4],IDC_DID_COMMENT,"");

 for (i = 0;i < sizeof(vd)/sizeof(dev); i++)
 {
  if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]) == vd[i].vendorid &&
      
	  ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == vd[i].deviceid && vd[i].high == 0) ||
	  ((unsigned int)(((unsigned char*)(biosparam.pcir + 0x06))[1]) == vd[i].deviceid && vd[i].high == 1))
  {
   SetDlgItemText(hpw[4],IDC_VID_COMMENT,vd[i].vendorname);
   SetDlgItemText(hpw[4],IDC_DID_COMMENT,vd[i].devicename);
   blbios = 1;
   break;
  }
 }

 if (blbios == 0)
 {
  for (i = 0;i < sizeof(vd)/sizeof(dev); i++)
  {
   if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]) == vd[i].vendorid)
   {
    SetDlgItemText(hpw[4],IDC_VID_COMMENT,vd[i].vendorname);
    break;
   }
  }
 }


/*
 if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]) == 0x121a) 
  SetDlgItemText(hpw[4],IDC_VID_COMMENT,"3Dfx Interactive, Inc.");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]) == 0x1142) 
  SetDlgItemText(hpw[4],IDC_VID_COMMENT,"Alliance Semiconductor");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x04))[0]) == 0x10d9) 
  SetDlgItemText(hpw[4],IDC_VID_COMMENT,"Macronix International Co Ltd");

 if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 9) 
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"VSA100-based card");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 5)
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"Voodoo3-based card");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 5)
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"Voodoo3-based card");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 3)
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"Voodoo banshee-based card");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 0xb)
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"VSA101-based card");
 else if ((unsigned int)(((unsigned short*)(biosparam.pcir + 0x06))[0]) == 0x10)
  SetDlgItemText(hpw[4],IDC_DID_COMMENT,"Rampage-based card");
 else SetDlgItemText(hpw[4],IDC_DID_COMMENT," ");
*/
 wsprintf((char*)textbuf,"%04X",(unsigned int)(((unsigned short*)(biosparam.pcir + 0x08))[0]));
 SetDlgItemText(hpw[4],IDC_PTV,(char*)textbuf);
 wsprintf((char*)textbuf,"%04X",(unsigned int)(((unsigned short*)(biosparam.pcir + 0x0a))[0]));
 SetDlgItemText(hpw[4],IDC_PCISTRLEN,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(((unsigned char*)(biosparam.pcir +  0x0c))[0]));
 SetDlgItemText(hpw[4],IDC_PCISTRREV,(char*)textbuf);
 
 int cc1,cc2,cc3;
 cc1 = (unsigned int)(((unsigned char*)(biosparam.pcir +  0x0d))[0]);
 cc2 = (unsigned int)(((unsigned char*)(biosparam.pcir +  0x0e))[0]);
 cc3 = (unsigned int)(((unsigned char*)(biosparam.pcir +  0x0f))[0]);
 wsprintf((char*)textbuf,"%02X%02X%02X",cc1,cc2,cc3);
 SetDlgItemText(hpw[4],IDC_CLASSCODE,(char*)textbuf);
 
 if (cc1 == 0 && cc2 == 0 && cc3 == 3)
  SetDlgItemText(hpw[4],IDC_CC_COMMENT,"VGA-compatible video card");
 else
  SetDlgItemText(hpw[4],IDC_CC_COMMENT,"");
 
 cc1 = (unsigned int)(((unsigned short*)(biosparam.pcir + 0x10))[0]);
 wsprintf((char*)textbuf,"%04X",cc1);
 SetDlgItemText(hpw[4],IDC_IMAGELENGHT,(char*)textbuf);

 // размер биоса в 512байтных блоках
 wsprintf((char*)textbuf,"%dk",cc1>>1);
 SetDlgItemText(hpw[4],IDC_ROMIMAGESIZE,(char*)textbuf);

 wsprintf((char*)textbuf,"%04X",(unsigned int)(((unsigned short*)(biosparam.pcir + 0x12))[0]));
 SetDlgItemText(hpw[4],IDC_REVLEVELCD,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(((unsigned char*)(biosparam.pcir +  0x14))[0]));
 SetDlgItemText(hpw[4],IDC_CODETYPE,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(((unsigned char*)(biosparam.pcir +  0x15))[0]));
 SetDlgItemText(hpw[4],IDC_INDICATOR,(char*)textbuf);
l21:;
 // поиск vesa strings
 for(i=0;i<lenbios-70;i++)
 {
  // mov si,...vendorinfo
  if (bios[i+0]  == 0xbe && 
  // call ....
	  bios[i+3]  == 0xe8 && 
  // mov es,[bx+..],di
	  bios[i+6]  == 0x26 && bios[i+7]  == 0x89 && bios[i+8]  == 0x7f &&
  // mov es,[bx+..],es
      bios[i+10] == 0x26 && bios[i+11] == 0x8c && bios[i+12] == 0x47 &&
  // mov cx,...
      bios[i+14] == 0xb9 && 
  // mov si,...	  
	  bios[i+17] == 0xbe && 
  // rep movsw
      bios[i+20] == 0xf3 && bios[i+21] == 0xa5 &&
  // mov es,[bx+..],di
	  bios[i+22] == 0x26 && bios[i+23] == 0x89 && bios[i+24] == 0x7f &&
  // mov es,[bx+..],es
      bios[i+26] == 0x26 && bios[i+27] == 0x8c && bios[i+28] == 0x47 &&
  // mov si,...vendorname
	  bios[i+30] == 0xbe && 
  // call ....
	  bios[i+33] == 0xe8 && 
  // mov es,[bx+..],di
	  bios[i+36] == 0x26 && bios[i+37] == 0x89 && bios[i+38] == 0x7f &&
  // mov es,[bx+..],es
      bios[i+40] == 0x26 && bios[i+41] == 0x8c && bios[i+42] == 0x47 &&
  // mov si,...productname	  
	  bios[i+44] == 0xbe && 
  // call ....
	  bios[i+47] == 0xe8 && 
  // mov es,[bx+..],di
	  bios[i+50] == 0x26 && bios[i+51] == 0x89 && bios[i+52] == 0x7f &&
  // mov es,[bx+..],es
      bios[i+54] == 0x26 && bios[i+55] == 0x8c && bios[i+56] == 0x47 &&
  // mov si,...productrevision
	  bios[i+58] == 0xbe && 
  // call ....
	  bios[i+61] == 0xe8)
  {
   biosparam.lpVendorName = bios + (int)*((unsigned short*)(bios + i + 31));
   biosparam.lpProductRev = bios + (int)*((unsigned short*)(bios + i + 59));
   biosparam.lpProductName = bios + (int)*((unsigned short*)(bios + i + 45));
   
   biosparam.lpVendorInfo = bios + (int)*((unsigned short*)(bios + i + 1));
   wsprintf((char*)textbuf,"%04X",biosparam.lpVendorInfo-bios);
   SetDlgItemText(hpw[5],IDC_OFFSETVENDORINFO,(char*)textbuf);
   biosparam.maxlenveninfo = lstrlen((char*)biosparam.lpVendorInfo);
   SetDlgItemInt(hpw[5],IDC_MAXLEN4,biosparam.maxlenveninfo,0);
   SendDlgItemMessage(hpw[5],IDC_VESA_VENDORINFO,EM_LIMITTEXT,0,0);
   SetDlgItemText(hpw[5],IDC_VESA_VENDORINFO,(char*)biosparam.lpVendorInfo);
   SendDlgItemMessage(hpw[5],IDC_VESA_VENDORINFO,EM_LIMITTEXT,biosparam.maxlenveninfo,0);

   goto l24;
  }
 }

 // поиск vesa strings (rush macronix)
 for(i=0;i<lenbios-70;i++)
 {
  // mov di,si
  if (bios[i+0]  == 0x8b && bios[i+1]  == 0xfe && 
  // mov word ptr es:[di],...
	  bios[i+2]  == 0x26 && bios[i+3]  == 0xc7 && bios[i+4]  == 0x05 && 
  // mov word ptr es:[di+.2],...
	  bios[i+7]  == 0x26 && bios[i+8]  == 0xc7 && bios[i+9]  == 0x45 && 
  // mov word ptr es:[di+ 4],...
	  bios[i+13] == 0x26 && bios[i+14] == 0xc7 && bios[i+15] == 0x45 && 
  // mov word ptr es:[di+..],vendorinfo
	  bios[i+19] == 0x26 && bios[i+20] == 0xc7 && bios[i+21] == 0x45 && 
  // mov es:[di+8],cs
	  bios[i+25] == 0x26 && bios[i+26] == 0x8c && bios[i+27] == 0x4d)
  {
   biosparam.lpVendorInfo = bios + (int)*((unsigned short*)(bios + i + 23));
   wsprintf((char*)textbuf,"%04X",biosparam.lpVendorInfo-bios);
   SetDlgItemText(hpw[5],IDC_OFFSETVENDORINFO,(char*)textbuf);
   biosparam.maxlenveninfo = lstrlen((char*)biosparam.lpVendorInfo);
   SetDlgItemInt(hpw[5],IDC_MAXLEN4,biosparam.maxlenveninfo,0);
   SendDlgItemMessage(hpw[5],IDC_VESA_VENDORINFO,EM_LIMITTEXT,0,0);
   SetDlgItemText(hpw[5],IDC_VESA_VENDORINFO,(char*)biosparam.lpVendorInfo);
   SendDlgItemMessage(hpw[5],IDC_VESA_VENDORINFO,EM_LIMITTEXT,biosparam.maxlenveninfo,0);
   goto ll24;
  }
 }
ll24:;
 for(i=0;i<lenbios-70;i++)
 {
  // mov si,...vendorname
  if (bios[i+0]  == 0xbe && 
  // mov cx,...
	  bios[i+3]  == 0xb9 && 
  // rep movsb
	  bios[i+6]  == 0xf3 && bios[i+7] == 0xa4 && 
  // mov es:[bx+..],di
	  bios[i+8]  == 0x26 && bios[i+9] == 0x89 && 
  // mov si,...productname
      bios[i+12]  == 0xbe && 
  // mov cx,...
	  bios[i+15]  == 0xb9 && 
  // rep movsb
	  bios[i+18]  == 0xf3 && bios[i+19] == 0xa4 && 
  // mov es:[bx+..],di
	  bios[i+20]  == 0x26 && bios[i+21] == 0x89 && 
  // mov si,...productrevision
      bios[i+24]  == 0xbe && 
  // mov cx,...
	  bios[i+27]  == 0xb9 && 
  // rep movsb
	  bios[i+30]  == 0xf3 && bios[i+31] == 0xa4)
  {
   biosparam.lpVendorName = bios + (int)*((unsigned short*)(bios + i + 1));
   biosparam.lpProductRev = bios + (int)*((unsigned short*)(bios + i + 25));
   biosparam.lpProductName = bios + (int)*((unsigned short*)(bios + i + 13));
   goto l24;
  }
 }
 goto l23;
l24:;
 wsprintf((char*)textbuf,"%04X",biosparam.lpVendorName-bios);
 SetDlgItemText(hpw[5],IDC_OFFSETVENDORNAME,(char*)textbuf);
 biosparam.maxlenvenname = lstrlen((char*)biosparam.lpVendorName);
 SetDlgItemInt(hpw[5],IDC_MAXLEN3,biosparam.maxlenvenname,0);
 SendDlgItemMessage(hpw[5],IDC_VESA_VENDORNAME,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[5],IDC_VESA_VENDORNAME,(char*)biosparam.lpVendorName);
 SendDlgItemMessage(hpw[5],IDC_VESA_VENDORNAME,EM_LIMITTEXT,biosparam.maxlenvenname,0);

 wsprintf((char*)textbuf,"%04X",biosparam.lpProductRev-bios);
 SetDlgItemText(hpw[5],IDC_OFFSETPRODUCTREVISION,(char*)textbuf);
 biosparam.maxlenprrev = lstrlen((char*)biosparam.lpProductRev);
 SetDlgItemInt(hpw[5],IDC_MAXLEN2,biosparam.maxlenprrev,0);
 SendDlgItemMessage(hpw[5],IDC_VESA_PRODUCTREVISION,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[5],IDC_VESA_PRODUCTREVISION,(char*)biosparam.lpProductRev);
 SendDlgItemMessage(hpw[5],IDC_VESA_PRODUCTREVISION,EM_LIMITTEXT,biosparam.maxlenprrev,0);

 wsprintf((char*)textbuf,"%04X",biosparam.lpProductName-bios);
 SetDlgItemText(hpw[5],IDC_OFFSETPRODUCTNAME,(char*)textbuf);
 biosparam.maxlenprname = lstrlen((char*)biosparam.lpProductName);
 SetDlgItemInt(hpw[5],IDC_MAXLEN1,biosparam.maxlenprname,0);
 SendDlgItemMessage(hpw[5],IDC_VESA_PRODUCTNAME,EM_LIMITTEXT,0,0);
 SetDlgItemText(hpw[5],IDC_VESA_PRODUCTNAME,(char*)biosparam.lpProductName);
 SendDlgItemMessage(hpw[5],IDC_VESA_PRODUCTNAME,EM_LIMITTEXT,biosparam.maxlenprname,0);

l23:;
 // видеорежимы (ext)
 for(i=0;i<lenbios-30;i++)
 {
  // push cs
  if (bios[i+0]  == 0x0e &&
  // pop es
      bios[i+1]  == 0x07 &&
  // mov bx,exttabl
	  bios[i+2]  == 0xbb && 
  // jmp ...
	  bios[i+5]  == 0xeb)
  {
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 3));
   reg = (unsigned int)(((unsigned short*)vcr1)[0]);
   goto l30;
  }
 }
 goto l31;
l30:;
 biosparam.extvmodeinfo = bios + reg;
l31:;
 return true;
}

int LoadBios(int fname)
{
 int hFile,lenfile,readlen;
 OPENFILENAME ofn;

 if (fname == 1) goto l1;

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME) ;
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName ;
 ofn.nMaxFile          = _MAX_PATH ;
 ofn.lpstrFileTitle    = szTitleName ;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT ;
 ofn.Flags             = OFN_HIDEREADONLY ;
 ofn.lpstrTitle        = "Load BIOS";
 if( !GetOpenFileName(&ofn)) return 2;

l1:;
 // Проверка на наличие файла
 hFile = _lopen(szFileName, OF_READ);
 if (hFile == -1) return 1;
 // Определение длины файла
 lenfile = _llseek(hFile, 0, 2);
 _llseek(hFile, 0, 0);
 if (lenfile > 256*256)
 {
  _lclose(hFile);
  return 1;
 }
 memset(bios,0,256*256);
 
 // проверка на сигнатуру биоса
 readlen = _lread(hFile,textbuf,2);
 if (textbuf[0] != 0x55 && textbuf[1] != 0xaa)
 {
  _lclose(hFile);
  return 1;
 }
 _llseek(hFile, 0, 0);

 // Чтение файла
 readlen = _lread(hFile,bios,lenfile);
 if (readlen == HFILE_ERROR || readlen != lenfile)
 {
  _lclose(hFile);
  return 1;
 }
 // Закрытие файла
 _lclose(hFile);
 lenbios = lenfile;

 wsprintf((char*)textbuf,"tdfx bios editor [%s]",szTitleName);
 SetWindowText(hmWnd,(char*)textbuf);

 memcpy(bios2,bios,lenbios);
 return 0;
}

void InitProperty(HWND hWnd)
{
 TCITEM tci[10];
 tci[0].mask = TCIF_TEXT;
 tci[0].pszText = "Fonts";
 tci[1].mask = TCIF_TEXT;
 tci[1].pszText = "Dump";
 tci[2].mask = TCIF_TEXT;
 tci[2].pszText = "Boot-up Strings";
 tci[3].mask = TCIF_TEXT;
 tci[3].pszText = "Registers";
 tci[4].mask = TCIF_TEXT;
 tci[4].pszText = "PCIR";
 tci[5].mask = TCIF_TEXT;
 tci[5].pszText = "VESA Strings";
 tci[6].mask = TCIF_TEXT;
 tci[6].pszText = "Video Modes";
 tci[7].mask = TCIF_TEXT;
 tci[7].pszText = "Logo Image";

 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),0,&tci[0]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),1,&tci[1]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),2,&tci[2]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),3,&tci[3]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),4,&tci[4]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),5,&tci[5]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),6,&tci[6]);
 TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),7,&tci[7]);
 
 hpw[0] = CreateDialog(hInst,(LPCTSTR)IDD_FONTS,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc1);
 hpw[1] = CreateDialog(hInst,(LPCTSTR)IDD_DUMP,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc2);
 hpw[2] = CreateDialog(hInst,(LPCTSTR)IDD_OTHER,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc3);
 hpw[3] = CreateDialog(hInst,(LPCTSTR)IDD_REGISTERS,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc4);
 hpw[4] = CreateDialog(hInst,(LPCTSTR)IDD_PCIR,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc13);
 hpw[5] = CreateDialog(hInst,(LPCTSTR)IDD_VESA,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc14);
 hpw[6] = CreateDialog(hInst,(LPCTSTR)IDD_VIDEOMODES,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc16);
 hpw[7] = CreateDialog(hInst,(LPCTSTR)IDD_LOGO,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc17);
}

void ViewTabPage(int curt,HWND hWnd)
{
 RECT rect,rectc;
 GetClientRect(GetDlgItem(hWnd,IDC_TAB1),&rect);
 GetClientRect(hpw[curt],&rectc);
 TabCtrl_AdjustRect(GetDlgItem(hWnd,IDC_TAB1),FALSE,&rect); 
 ShowWindow(hpw[actpage],SW_HIDE);
 MoveWindow(hpw[curt],rect.left,rect.top,rectc.right,rectc.bottom,FALSE);
 UpdateWindow(hpw[curt]);
 ShowWindow(hpw[curt],SW_SHOW);
 actpage = curt;
 if (actpage == 7)
 {
  if (hfontDC != 0)
  {
   ReleaseDC(hpw[0],hfontDC);
   hfontDC = 0;
  }
  hLogoDC = GetDC(hpw[7]);
 }
 else 
 if (actpage == 0)
 {
  if (hLogoDC != 0) 
  {
   ReleaseDC(hpw[7],hLogoDC);
   hLogoDC = 0;
  }
  hfontDC = GetDC(hpw[0]);
 }
}

void DrawBitmap(HDC hDC, int x, int y, HBITMAP hBitmap)
{
 HDC hMemDC;
 BITMAP bm;
 POINT  ptSize, ptOrg;
 hMemDC = CreateCompatibleDC(hDC);
 SelectObject(hMemDC, hBitmap);
 SetMapMode(hMemDC, GetMapMode(hDC));
 GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
 ptSize.x = bm.bmWidth;
 ptSize.y = bm.bmHeight;
 DPtoLP(hDC, &ptSize, 1);
 ptOrg.x = 0;
 ptOrg.y = 0;
 DPtoLP(hMemDC, &ptOrg, 1);
 BitBlt(hDC, x, y, ptSize.x, ptSize.y,hMemDC, ptOrg.x, ptOrg.y, SRCCOPY);
 DeleteDC(hMemDC);
}

LRESULT CALLBACK pWndProc2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       // установка шрифта
       SendDlgItemMessage(hDlg,IDC_RICHEDIT1,WM_SETFONT,(WPARAM)hFont,0);
	   // вывод дампа
	   ViewDump(hDlg,0,0);
       // установка цвета символов
	   cf.cbSize = sizeof(cf);
       cf.dwMask = CFM_COLOR;
	   cf.dwEffects = 0;
	   cf.crTextColor = RGB(0,0,0);
	   SendDlgItemMessage(hDlg,IDC_RICHEDIT1,EM_SETCHARFORMAT,SCF_ALL,(LPARAM)&cf);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_APPLY:
             if (loadingbios == true)
			 {
			  dapply = true;
			  loadingbios = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  memcpy(bios2,bios,lenbios);
              ViewDump(hDlg,0,0);
              loadingbios = true;
			 }
             break;
        case IDC_RESTORE:
			 if (loadingbios == true)
			 {
			  dapply = true;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  loadingbios = false;
			  memcpy(bios,bios2,lenbios);
              ViewDump(hDlg,0,0);
              AnalyzeBios();
              loadingbios = true;
			 }
			 break;
	   }
	   break;
 }
 return FALSE;
}

// pos - с какой позиции
// sel - сколько выделять
void ViewDump(HWND hwnd,int pos, int sel)
{
 memset(textbuf,0,1024*1024);
 char *ctext = (char*)textbuf;
 char ch;

 // перемотка дампа в начало
 if (sel != 0 && pos != 0)
  SendDlgItemMessage(hwnd,IDC_RICHEDIT1,WM_VSCROLL,SB_TOP,0);

 // формирование текста
 for (int i=0;i<lenbios;i+=16)
 {
  wsprintf(ctext,"%04X: %02X %02X %02X %02X %02X %02X %02X %02X  %02X %02X %02X %02X %02X %02X %02X %02X  ",i,bios[i],bios[i+1],bios[i+2],bios[i+3],bios[i+4],bios[i+5],bios[i+6],bios[i+7],bios[i+8],bios[i+9],bios[i+10],bios[i+11],bios[i+12],bios[i+13],bios[i+14],bios[i+15]);
  ctext += lstrlen(ctext);
  for (int j=i;j<i+16;j++)
  {
   if (bios[j] < ' ' || bios[j] > '~') ch = '.';
    else ch = bios[j];
   wsprintf(ctext,"%c",ch);
   ctext += lstrlen(ctext);
  }
  memcpy(ctext,"\r\n",2);
  ctext += 2;
 }

 // выводим текст на экран
 SendDlgItemMessage(hwnd,IDC_RICHEDIT1,WM_SETTEXT,0,(LPARAM)textbuf);

 int t1,t2,t3,k,j, lm = 0;

 curcol = 0;

 // выделение измененных блоков
 for (i=0;i<lenbios;i++)
 {
  if (bios[i] != bios2[i])
  {
   t2 = i - (i/16)*16;
   if (t2 < 8) t3 = t2 * 3;
    else t3 = t2 * 3 + 1;
   t1 = (i/16)*74 + 6 + t3; // расчет положения отображения байтов
   
   lm = 1;
   for (k = t2, j = i + 1; k < 15; k++,j++)
   {
	if (j >= lenbios) break;
    if (bios[j] != bios2[j]) lm++;
	 else break;
   }

   int t = 0;
   if (t2 < 8 && t2 + lm >= 8) t = 1;

   rcol[curcol].start = t1;
   rcol[curcol].end = t1+lm*3 + t;
   rcol[curcol].color = RGB(255,0,0);
   curcol++;
   rcol[curcol].start = (i/16)*74 + 56 + i - (i/16)*16;
   rcol[curcol].end = rcol[curcol].start + lm;
   rcol[curcol].color = RGB(255,0,0);
   curcol++;

   i = i + lm - 1;
/*
   rcol[curcol].start = t1;
   rcol[curcol].end = t1+2;
   rcol[curcol].color = RGB(255,0,0);
   curcol++;
   rcol[curcol].start = (i/16)*74 + 56 + i - (i/16)*16;
   rcol[curcol].end = rcol[curcol].start + 1;
   rcol[curcol].color = RGB(255,0,0);
   curcol++;
*/
   dapply = false;
  }
 }
 if (dapply == false) EnableWindow(GetDlgItem(hwnd,IDC_APPLY),TRUE);

 bool fl = false;
 int c1,c2;

 // выделениме отмеченных участков
 if (sel != 0 && pos != 0)
 {
  for (i = pos;i<pos+sel;i++)
  {
   t2 = i - (i/16)*16;       // номер байта от начала строки (0..15)
   if (t2 < 8) t3 = t2 * 3;  // если во 2-ой 8-ке, то смещение + 1:
    else t3 = t2 * 3 + 1;    // 3 - подсвечивать 3 байта (2 + пробел)
   t1 = (i/16)*74 + 6 + t3; // расчет положения отображения байтов
   if (fl == false)
   {
    c1 = t1;
	c2 = (i/16)*74 + 56 + t2;
	fl = true;
   }
   if (t2 == 0 && i + 16 <= pos+sel-1)
   {
    rcol[curcol].start = c1;
    rcol[curcol].end = c1 + (16 * 3) + 1+ 16 + 1 ;
    rcol[curcol].color = RGB(0,0,255);
    curcol++;
	i += 15;
    fl = false;
   }
   else
   if ((t2 == 15 || i == pos+sel-1) && fl == true)
   {  
    rcol[curcol].start = c1;
    rcol[curcol].end = t1 + 2;
    rcol[curcol].color = RGB(0,0,255);
    curcol++;

    rcol[curcol].start = c2;
    rcol[curcol].end = (i/16)*74 + 56 + t2 + 1;
    rcol[curcol].color = RGB(0,0,255);
    curcol++;

	fl = false;
   }
  }
 }

 DrawDump(hwnd);

 pos = pos / 16;
 for (i = 0; i < pos; i++)
  SendDlgItemMessage(hwnd,IDC_RICHEDIT1,EM_LINESCROLL,0,1);
}

LRESULT CALLBACK pWndProc3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       // установка шрифта
       SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP,WM_SETFONT,(WPARAM)hFont,0);
       SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP2,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_BIOSDATE,WM_SETFONT,(WPARAM)hFont,0);
	  // SendDlgItemMessage(hDlg,IDC_ROMSIGNATURE,WM_SETFONT,(WPARAM)hFont,0);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_VIEWSTARTUP:
             if (HIWORD(wParam) == EN_UPDATE && loadingbios == true)
			 {
              biosparam.lenlabel1 = SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP,WM_GETTEXTLENGTH,0,0);
              SetDlgItemInt(hDlg,IDC_LENVS,biosparam.lenlabel1,0);
			  otapply = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			 }
             break;			 
        case IDC_VIEWSTARTUP2:
             if (HIWORD(wParam) == EN_UPDATE && loadingbios == true)
			 {
              biosparam.lenlabel2 = SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP2,WM_GETTEXTLENGTH,0,0);
              SetDlgItemInt(hDlg,IDC_LENVS2,biosparam.lenlabel2,0);
			  otapply = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			 }
             break;			 
        case IDC_BIOSDATE:
             if (HIWORD(wParam) == EN_UPDATE && loadingbios == true)
			 {
			  otapply = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			 }
             break;
        case IDC_APPLY:
			 if (loadingbios == true)
			 {
			  otapply = true;
			  loadingbios = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  memset((char*)biosparam.lpLabel1,0,biosparam.maxlenlabel1);
			  if (biosparam.lpLabel1 != NULL)
			  {
               GetDlgItemText(hDlg,IDC_VIEWSTARTUP,(char*)biosparam.lpLabel1,biosparam.maxlenlabel1+1);
			   if (biosparam.lpsizel != NULL)
			    ((unsigned short*)(biosparam.lpsizel))[0] = (unsigned short)lstrlen((char*)biosparam.lpLabel1);
			  }
              
			  if (biosparam.lpLabel2 != NULL)
			  {
			   memset((char*)biosparam.lpLabel2,0,biosparam.maxlenlabel2);
			   GetDlgItemText(hDlg,IDC_VIEWSTARTUP2,(char*)biosparam.lpLabel2,biosparam.maxlenlabel2+1);
               if (biosparam.lpsize2 != NULL)
                ((unsigned short*)(biosparam.lpsize2))[0] = (unsigned short)(lstrlen((char*)biosparam.lpLabel2));
			  }
              
			  if (biosparam.lpData != NULL)
			  {
			   memset((char*)biosparam.data,0,biosparam.maxlendata);
               GetDlgItemText(hDlg,IDC_BIOSDATE,(char*)biosparam.data,biosparam.maxlendata+1);
			   memcpy(biosparam.lpData,biosparam.data,biosparam.maxlendata);
			  }
              ViewDump(hpw[1],0,0);
			  loadingbios = true;
			 }
             break;
		case IDC_RESTORE:
			 if (loadingbios == true)
			 {
			  otapply = true;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  loadingbios = false;
 
			  if (biosparam.lpLabel1 != NULL)
			  {
               biosparam.lenlabel1 = lstrlen((char*)biosparam.lpLabel1);
               SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VIEWSTARTUP,(char*)biosparam.lpLabel1);
               SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP,EM_LIMITTEXT,biosparam.maxlenlabel1,0);
               SetDlgItemInt(hDlg,IDC_LENVS,biosparam.lenlabel1,0);
			  }

			  if (biosparam.lpLabel2 != NULL)
			  {
               biosparam.lenlabel2 = lstrlen((char*)biosparam.lpLabel2);
               SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP2,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VIEWSTARTUP2,(char*)biosparam.lpLabel2);
               SendDlgItemMessage(hDlg,IDC_VIEWSTARTUP2,EM_LIMITTEXT,biosparam.maxlenlabel2,0);
               SetDlgItemInt(hDlg,IDC_LENVS2,biosparam.lenlabel2,0);
			  }
			  
			  if (biosparam.lpData != NULL)
			  {
               biosparam.lendata = 8;
               memcpy(biosparam.data,biosparam.lpData,biosparam.maxlendata);
               SendDlgItemMessage(hDlg,IDC_BIOSDATE,EM_LIMITTEXT,0,0);
               SetDlgItemText(hpw[2],IDC_BIOSDATE,(char*)biosparam.data);
               SendDlgItemMessage(hDlg,IDC_BIOSDATE,EM_LIMITTEXT,biosparam.maxlendata,0);
			  }
              loadingbios = true;
			 }
			 break;
		case IDC_OFFSETVS1:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenlabel1);
			 break;
		case IDC_OFFSETVS2:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenlabel2);
			 break;
		case IDC_OFFSETDATA:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlendata);
			 break;

	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc4(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_CPCIINIT0:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_PCIINIT0),hDlg,(DLGPROC)pWndProc5);
			 break;
        case IDC_CMISCINIT0:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_MISCINIT0),hDlg,(DLGPROC)pWndProc6);
			 break;
        case IDC_CMISCINIT1:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_MISCINIT1),hDlg,(DLGPROC)pWndProc7);
			 break;
        case IDC_CDRAMINIT0:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_DRAMINIT0),hDlg,(DLGPROC)pWndProc8);
			 break;
        case IDC_CDRAMINIT1:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_DRAMINIT1),hDlg,(DLGPROC)pWndProc9);
			 break;
        case IDC_CAGPINIT0:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_AGPINIT0),hDlg,(DLGPROC)pWndProc10);
			 break;
        case IDC_CPLLCTRL0:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_PLLCTRL0),hDlg,(DLGPROC)pWndProc11);
			 break;
        case IDC_CSGRAMMODE:
	  	     if (loadingbios == true) DialogBox(hInst,MAKEINTRESOURCE(IDD_SGRAMMODE),hDlg,(DLGPROC)pWndProc12);
			 break;
		case IDC_PCIINIT0:
		case IDC_MISCINIT0:
		case IDC_MISCINIT1:
		case IDC_DRAMINIT0:
		case IDC_DRAMINIT1:
		case IDC_AGPINIT0:
		case IDC_PLLCTRL0:
		case IDC_PLLCTRL1:
		case IDC_SGRAMMODE:
             if (HIWORD(wParam) == EN_UPDATE && loadingbios == true)
			 {
              rtapply = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			 }
			 break;
		case IDC_COMPARE:
             if (loadingbios == true) 
			 {
			  if (LoadCMPBios(hDlg) == false) break;
			  AnalyzeCMPBios();
              loadingcmpbios = true;
			  CMPreg(hDlg);
			 }
			 break;
        case IDC_APPLY:
			 if (loadingbios == true)
			 {
			  rtapply = true;
			  loadingbios = false;
			  // считать результат
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  memset((char*)textbuf,0,1024*1024);
              GetDlgItemText(hDlg,IDC_PCIINIT0,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.pciinit0);
			  if (biosparam.lppciinit0 != 0) ((unsigned int*)(biosparam.lppciinit0))[0] = (unsigned int)biosparam.pciinit0;
              GetDlgItemText(hDlg,IDC_MISCINIT0,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.miscinit0);
			  if (biosparam.lpmiscinit0 != 0) ((unsigned int*)(biosparam.lpmiscinit0))[0] = (unsigned int)biosparam.miscinit0;
              GetDlgItemText(hDlg,IDC_MISCINIT1,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.miscinit1);
			  if (biosparam.lpmiscinit1 != 0) ((unsigned int*)(biosparam.lpmiscinit1))[0] = (unsigned int)biosparam.miscinit1;
              GetDlgItemText(hDlg,IDC_DRAMINIT0,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.draminit0);
			  if (biosparam.lpdraminit0 != 0) ((unsigned int*)(biosparam.lpdraminit0))[0] = (unsigned int)biosparam.draminit0;
              GetDlgItemText(hDlg,IDC_DRAMINIT1,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.draminit1);
			  if (biosparam.lpdraminit1 != 0) ((unsigned int*)(biosparam.lpdraminit1))[0] = (unsigned int)biosparam.draminit1;
              GetDlgItemText(hDlg,IDC_AGPINIT0,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.agpinit0);
			  if (biosparam.lpagpinit0 != 0) ((unsigned int*)(biosparam.lpagpinit0))[0] = (unsigned int)biosparam.agpinit0;
              GetDlgItemText(hDlg,IDC_PLLCTRL0,(char*)textbuf,256);
			  sscanf((char*)textbuf,"%X",&biosparam.pllctrl0);
			  if (biosparam.lppllctrl0 != 0) ((unsigned int*)(biosparam.lppllctrl0))[0] = (unsigned int)biosparam.pllctrl0;
              if (biosparam.bpllctrl1 == true)
			  {
               GetDlgItemText(hDlg,IDC_PLLCTRL1,(char*)textbuf,256);
			   sscanf((char*)textbuf,"%X",&biosparam.pllctrl1);
			   if (biosparam.lppllctrl1 != 0) ((unsigned int*)(biosparam.lppllctrl1))[0] = (unsigned int)biosparam.pllctrl1;
			  }
              GetDlgItemText(hDlg,IDC_SGRAMMODE,(char*)textbuf,256);
              sscanf((char*)textbuf,"%X",&biosparam.sgrammode);
		      if (biosparam.lpsgrammode != 0) ((unsigned int*)(biosparam.lpsgrammode))[0] = (unsigned int)biosparam.sgrammode;
			  ViewDump(hpw[1],0,0);
              // вывести результат
              wsprintf((char*)textbuf,"%08X",biosparam.pciinit0);
              SetDlgItemText(hDlg,IDC_PCIINIT0,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.miscinit0);
              SetDlgItemText(hDlg,IDC_MISCINIT0,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.miscinit1);
              SetDlgItemText(hDlg,IDC_MISCINIT1,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.draminit0);
              SetDlgItemText(hDlg,IDC_DRAMINIT0,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.draminit1);
              SetDlgItemText(hDlg,IDC_DRAMINIT1,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.agpinit0);
              SetDlgItemText(hDlg,IDC_AGPINIT0,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.pllctrl0);
              SetDlgItemText(hDlg,IDC_PLLCTRL0,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.pllctrl1);
              SetDlgItemText(hDlg,IDC_PLLCTRL1,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",biosparam.sgrammode);
              SetDlgItemText(hDlg,IDC_SGRAMMODE,(char*)textbuf);
			  loadingbios = true;

              k = biosparam.pllctrl0 & BIN8(00000011);
              m = (biosparam.pllctrl0 & BIN8(11111100)) >> 2;
              n = (biosparam.pllctrl0 & 0xff00) >> 8;
              mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
              sprintf((char*)textbuf,"%g MHz",mgz,k,m,n);
              SetDlgItemText(hDlg,IDC_SPEED,(char*)textbuf);
              CMPreg(hDlg);
			 }
             break;
        case IDC_RESTORE:
			 if (loadingbios == true)
			 {
			  rtapply = true;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
              // вывести результат
			  loadingbios = false;
              if (biosparam.pciinit0 != 0) biosparam.pciinit0 = ((unsigned int*)(biosparam.lppciinit0))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.pciinit0);
              SetDlgItemText(hDlg,IDC_PCIINIT0,(char*)textbuf);

              if (biosparam.lpmiscinit0 != 0) biosparam.miscinit0 = ((unsigned int*)(biosparam.lpmiscinit0))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.miscinit0);
              SetDlgItemText(hDlg,IDC_MISCINIT0,(char*)textbuf);

              if (biosparam.lpmiscinit1 != 0) biosparam.miscinit1 = ((unsigned int*)(biosparam.lpmiscinit1))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.miscinit1);
              SetDlgItemText(hDlg,IDC_MISCINIT1,(char*)textbuf);

              if (biosparam.lpdraminit0 != 0) biosparam.draminit0 = ((unsigned int*)(biosparam.lpdraminit0))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.draminit0);
              SetDlgItemText(hDlg,IDC_DRAMINIT0,(char*)textbuf);

              if (biosparam.lpdraminit1 != 0) biosparam.draminit1 = ((unsigned int*)(biosparam.lpdraminit1))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.draminit1);
              SetDlgItemText(hDlg,IDC_DRAMINIT1,(char*)textbuf);

              if (biosparam.agpinit0 != 0) biosparam.agpinit0 = ((unsigned int*)(biosparam.lpagpinit0))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.agpinit0);
              SetDlgItemText(hDlg,IDC_AGPINIT0,(char*)textbuf);

              if (biosparam.pllctrl0 != 0) biosparam.pllctrl0 = ((unsigned int*)(biosparam.lppllctrl0))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.pllctrl0);
              SetDlgItemText(hDlg,IDC_PLLCTRL0,(char*)textbuf);

              if (biosparam.bpllctrl1 == true)
			  {
               if (biosparam.pllctrl1 != 0) biosparam.pllctrl1 = ((unsigned int*)(biosparam.lppllctrl1))[0];
               wsprintf((char*)textbuf,"%08X",biosparam.pllctrl1);
               SetDlgItemText(hDlg,IDC_PLLCTRL1,(char*)textbuf);
			  }

              if (biosparam.lpsgrammode != 0) biosparam.sgrammode = ((unsigned int*)(biosparam.lpsgrammode))[0];
              wsprintf((char*)textbuf,"%08X",biosparam.sgrammode);
              SetDlgItemText(hDlg,IDC_SGRAMMODE,(char*)textbuf);
			  loadingbios = true;
			 }
             break;
		case IDC_OFFSETPCIINIT0:
		case IDC_OFFSETMISCINIT0:
		case IDC_OFFSETMISCINIT1:
		case IDC_OFFSETDRAMINIT0:
		case IDC_OFFSETDRAMINIT1:
		case IDC_OFFSETAGPINIT0:
		case IDC_OFFSETPLLCTRL0:
		case IDC_OFFSETPLLCTRL1:
		case IDC_OFFSETSGRAMMODE:
             SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,4);
			 break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc5(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.pciinit0,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_PCIINIT0_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.pciinit0);
       SetDlgItemText(hDlg,IDC_PCIINIT0_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_EDIT1, (biosparam.pciinit0 & BIN32(00000000,00000000,00000000,01111100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_EDIT2, (biosparam.pciinit0 & BIN32(00000000,00000000,00000001,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_EDIT3, (biosparam.pciinit0 & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_EDIT4, (biosparam.pciinit0 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_EDIT5, (biosparam.pciinit0 & BIN32(00000000,00000000,00010000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_EDIT6, (biosparam.pciinit0 & BIN32(00000000,00000011,11100000,00000000))>>13,0);
       SetDlgItemInt(hDlg,IDC_EDIT7, (biosparam.pciinit0 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_EDIT8, (biosparam.pciinit0 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
       SetDlgItemInt(hDlg,IDC_EDIT9, (biosparam.pciinit0 & BIN32(00000011,11110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_EDIT10,(biosparam.pciinit0 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_EDIT11,(biosparam.pciinit0 & BIN32(00011000,00000000,00000000,00000000))>>27,0);

       SetDlgItemInt(hDlg,IDC_EDIT12,(biosparam.cmppciinit0 & BIN32(00000000,00000000,00000000,01111100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_EDIT13,(biosparam.cmppciinit0 & BIN32(00000000,00000000,00000001,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_EDIT14,(biosparam.cmppciinit0 & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_EDIT15,(biosparam.cmppciinit0 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_EDIT16,(biosparam.cmppciinit0 & BIN32(00000000,00000000,00010000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_EDIT17,(biosparam.cmppciinit0 & BIN32(00000000,00000011,11100000,00000000))>>13,0);
       SetDlgItemInt(hDlg,IDC_EDIT18,(biosparam.cmppciinit0 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_EDIT19,(biosparam.cmppciinit0 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
       SetDlgItemInt(hDlg,IDC_EDIT20,(biosparam.cmppciinit0 & BIN32(00000011,11110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_EDIT21,(biosparam.cmppciinit0 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_EDIT22,(biosparam.cmppciinit0 & BIN32(00011000,00000000,00000000,00000000))>>27,0);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_EDIT1:
		 case IDC_EDIT2:
		 case IDC_EDIT3:
		 case IDC_EDIT4:
		 case IDC_EDIT5:
		 case IDC_EDIT6:
		 case IDC_EDIT7:
		 case IDC_EDIT8:
		 case IDC_EDIT9:
		 case IDC_EDIT10:
		 case IDC_EDIT11:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT1, &res,0) & BIN8(00011111)) << 2);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT2, &res,0) & BIN8(00000001)) << 8);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT3, &res,0) & BIN8(00000001)) << 9);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT4, &res,0) & BIN8(00000001)) << 11);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT5, &res,0) & BIN8(00000001)) << 12);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT6, &res,0) & BIN8(00011111)) << 13);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT7, &res,0) & BIN8(00000001)) << 18);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT8, &res,0) & BIN8(00000001)) << 19);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT9, &res,0) & BIN8(00111111)) << 20);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT10,&res,0) & BIN8(00000001)) << 26);
              tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT11,&res,0) & BIN8(00000011)) << 27);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_PCIINIT0_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_PCIINIT0_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
			 tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT1, &res,0) & BIN8(00011111)) << 2);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT2, &res,0) & BIN8(00000001)) << 8);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT3, &res,0) & BIN8(00000001)) << 9);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT4, &res,0) & BIN8(00000001)) << 11);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT5, &res,0) & BIN8(00000001)) << 12);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT6, &res,0) & BIN8(00011111)) << 13);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT7, &res,0) & BIN8(00000001)) << 18);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT8, &res,0) & BIN8(00000001)) << 19);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT9, &res,0) & BIN8(00111111)) << 20);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT10,&res,0) & BIN8(00000001)) << 26);
             tmp |= ((GetDlgItemInt(hDlg,IDC_EDIT11,&res,0) & BIN8(00000011)) << 27);
             biosparam.pciinit0 = tmp;

             wsprintf((char*)textbuf,"%08X",biosparam.pciinit0);
             SetDlgItemText(hpw[3],IDC_PCIINIT0,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

void TextToBin(unsigned int num,char* buf)
{
 int i,j,k = 0;
 memset(textbuf,0,1024*1024);
 for (j=0;j<4;j++)
 {
  for (i=0;i<8;i++)
  {
   if ((num & 0x80000000) == 0) buf[k] = '0';
    else buf[k] = '1';
   num <<= 1;
   k++;
  }
  buf[k] = ' ';
  k++;
 }
 buf[k] = 0;
}

LRESULT CALLBACK pWndProc6(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.miscinit0,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_MISCINIT0_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.miscinit0);
       SetDlgItemText(hDlg,IDC_MISCINIT0_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_MEDIT1, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT2, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00000010))>>1, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT3, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00000100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT4, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT5, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00010000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT6, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,00100000))>>5, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT7, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,01000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT8, (biosparam.miscinit0 & BIN32(00000000,00000000,00000000,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT9, (biosparam.miscinit0 & BIN32(00000000,00000000,00000111,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT10,(biosparam.miscinit0 & BIN32(00000000,00000000,00111000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_MEDIT11,(biosparam.miscinit0 & BIN32(00000000,00000001,11000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_MEDIT12,(biosparam.miscinit0 & BIN32(00111111,11111100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_MEDIT13,(biosparam.miscinit0 & BIN32(01000000,00000000,00000000,00000000))>>30,0);
       SetDlgItemInt(hDlg,IDC_MEDIT14,(biosparam.miscinit0 & BIN32(10000000,00000000,00000000,00000000))>>31,0);

       SetDlgItemInt(hDlg,IDC_MEDIT15,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT16,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00000010))>>1, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT17,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00000100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT18,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT19,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00010000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT20,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,00100000))>>5, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT21,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,01000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT22,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000000,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT23,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00000111,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_MEDIT24,(biosparam.cmpmiscinit0 & BIN32(00000000,00000000,00111000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_MEDIT25,(biosparam.cmpmiscinit0 & BIN32(00000000,00000001,11000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_MEDIT26,(biosparam.cmpmiscinit0 & BIN32(00111111,11111100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_MEDIT27,(biosparam.cmpmiscinit0 & BIN32(01000000,00000000,00000000,00000000))>>30,0);
       SetDlgItemInt(hDlg,IDC_MEDIT28,(biosparam.cmpmiscinit0 & BIN32(10000000,00000000,00000000,00000000))>>31,0);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_MEDIT1:
		 case IDC_MEDIT2:
		 case IDC_MEDIT3:
		 case IDC_MEDIT4:
		 case IDC_MEDIT5:
		 case IDC_MEDIT6:
		 case IDC_MEDIT7:
		 case IDC_MEDIT8:
		 case IDC_MEDIT9:
		 case IDC_MEDIT10:
		 case IDC_MEDIT11:
		 case IDC_MEDIT12:
		 case IDC_MEDIT13:
		 case IDC_MEDIT14:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT1, &res,0) & BIN8(00000001)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT2, &res,0) & BIN8(00000001)) << 1);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT3, &res,0) & BIN8(00000001)) << 2);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT4, &res,0) & BIN8(00000001)) << 3);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT5, &res,0) & BIN8(00000001)) << 4);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT6, &res,0) & BIN8(00000001)) << 5);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT7, &res,0) & BIN8(00000001)) << 6);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT8, &res,0) & BIN8(00000001)) << 7);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT9, &res,0) & BIN8(00000111)) << 8);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT10,&res,0) & BIN8(00000111)) << 11);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT11,&res,0) & BIN8(00000111)) << 14);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT12,&res,0) & BIN16(00001111,11111111)) << 18);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT13,&res,0) & BIN8(00000001)) << 30);
              tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT14,&res,0) & BIN8(00000001)) << 31);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_MISCINIT0_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_MISCINIT0_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT1, &res,0) & BIN8(00000001)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT2, &res,0) & BIN8(00000001)) << 1);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT3, &res,0) & BIN8(00000001)) << 2);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT4, &res,0) & BIN8(00000001)) << 3);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT5, &res,0) & BIN8(00000001)) << 4);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT6, &res,0) & BIN8(00000001)) << 5);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT7, &res,0) & BIN8(00000001)) << 6);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT8, &res,0) & BIN8(00000001)) << 7);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT9, &res,0) & BIN8(00000111)) << 8);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT10,&res,0) & BIN8(00000111)) << 11);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT11,&res,0) & BIN8(00000111)) << 14);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT12,&res,0) & BIN16(00001111,11111111)) << 18);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT13,&res,0) & BIN8(00000001)) << 30);
             tmp |= ((GetDlgItemInt(hDlg,IDC_MEDIT14,&res,0) & BIN8(00000001)) << 31);
             biosparam.miscinit0 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.miscinit0);
             SetDlgItemText(hpw[3],IDC_MISCINIT0,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc7(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.miscinit1,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_MISCINIT1_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.miscinit1);
       SetDlgItemText(hDlg,IDC_MISCINIT1_HEX,(char*)textbuf);
       SetDlgItemInt(hDlg,IDC_NEDIT1, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT2, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,00000110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT3, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT4, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,00010000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT5, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,00100000))>>5, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT6, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,01000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT7, (biosparam.miscinit1 & BIN32(00000000,00000000,00000000,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT8, (biosparam.miscinit1 & BIN32(00000000,00000000,00000001,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT9, (biosparam.miscinit1 & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT10,(biosparam.miscinit1 & BIN32(00000000,00000000,00000100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_NEDIT11,(biosparam.miscinit1 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_NEDIT12,(biosparam.miscinit1 & BIN32(00000000,00000000,01110000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_NEDIT13,(biosparam.miscinit1 & BIN32(00000000,00000000,10000000,00000000))>>15,0);
       SetDlgItemInt(hDlg,IDC_NEDIT14,(biosparam.miscinit1 & BIN32(00000000,00000001,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_NEDIT15,(biosparam.miscinit1 & BIN32(00000000,00000010,00000000,00000000))>>17,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT22,(biosparam.miscinit1 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_NEDIT16,(biosparam.miscinit1 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT23,(biosparam.miscinit1 & BIN32(00000000,00110000,00000000,00000000))>>20,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT24,(biosparam.miscinit1 & BIN32(00000000,01000000,00000000,00000000))>>22,0);
       SetDlgItemInt(hDlg,IDC_NEDIT17,(biosparam.miscinit1 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_NEDIT18,(biosparam.miscinit1 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_NEDIT19,(biosparam.miscinit1 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_NEDIT20,(biosparam.miscinit1 & BIN32(00001000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_NEDIT21,(biosparam.miscinit1 & BIN32(00010000,00000000,00000000,00000000))>>28,0);
       SetDlgItemInt(hDlg,IDC_NEDIT25,(biosparam.miscinit1 & BIN32(00100000,00000000,00000000,00000000))>>29,0);	   
       SetDlgItemInt(hDlg,IDC_NEDIT26,(biosparam.miscinit1 & BIN32(11000000,00000000,00000000,00000000))>>29,0);	   

       SetDlgItemInt(hDlg,IDC_NEDIT27,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT28,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,00000110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT29,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT30,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,00010000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT31,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,00100000))>>5, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT32,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,01000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT33,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000000,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT34,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000001,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT35,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_NEDIT36,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00000100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_NEDIT37,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_NEDIT38,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,01110000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_NEDIT39,(biosparam.cmpmiscinit1 & BIN32(00000000,00000000,10000000,00000000))>>15,0);
       SetDlgItemInt(hDlg,IDC_NEDIT40,(biosparam.cmpmiscinit1 & BIN32(00000000,00000001,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_NEDIT41,(biosparam.cmpmiscinit1 & BIN32(00000000,00000010,00000000,00000000))>>17,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT42,(biosparam.cmpmiscinit1 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_NEDIT43,(biosparam.cmpmiscinit1 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT44,(biosparam.cmpmiscinit1 & BIN32(00000000,00110000,00000000,00000000))>>20,0);
	   SetDlgItemInt(hDlg,IDC_NEDIT45,(biosparam.cmpmiscinit1 & BIN32(00000000,01000000,00000000,00000000))>>22,0);
       SetDlgItemInt(hDlg,IDC_NEDIT46,(biosparam.cmpmiscinit1 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_NEDIT47,(biosparam.cmpmiscinit1 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_NEDIT48,(biosparam.cmpmiscinit1 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_NEDIT49,(biosparam.cmpmiscinit1 & BIN32(00001000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_NEDIT50,(biosparam.cmpmiscinit1 & BIN32(00010000,00000000,00000000,00000000))>>28,0);
       SetDlgItemInt(hDlg,IDC_NEDIT51,(biosparam.cmpmiscinit1 & BIN32(00100000,00000000,00000000,00000000))>>29,0);	   
       SetDlgItemInt(hDlg,IDC_NEDIT52,(biosparam.cmpmiscinit1 & BIN32(11000000,00000000,00000000,00000000))>>29,0);	   
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_NEDIT1:
		 case IDC_NEDIT2:
		 case IDC_NEDIT3:
		 case IDC_NEDIT4:
		 case IDC_NEDIT5:
		 case IDC_NEDIT6:
		 case IDC_NEDIT7:
		 case IDC_NEDIT8:
		 case IDC_NEDIT9:
		 case IDC_NEDIT10:
		 case IDC_NEDIT11:
		 case IDC_NEDIT12:
		 case IDC_NEDIT13:
		 case IDC_NEDIT14:
		 case IDC_NEDIT15:
		 case IDC_NEDIT16:
		 case IDC_NEDIT17:
		 case IDC_NEDIT18:
		 case IDC_NEDIT19:
		 case IDC_NEDIT20:
		 case IDC_NEDIT21:
	     case IDC_NEDIT22:
	     case IDC_NEDIT23:
	     case IDC_NEDIT24:
	     case IDC_NEDIT25:
	     case IDC_NEDIT26:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT1, &res,0) & BIN8(00000001)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT2, &res,0) & BIN8(00000011)) << 1);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT3, &res,0) & BIN8(00000001)) << 3);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT4, &res,0) & BIN8(00000001)) << 4);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT5, &res,0) & BIN8(00000001)) << 5);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT6, &res,0) & BIN8(00000001)) << 6);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT7, &res,0) & BIN8(00000001)) << 7);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT8, &res,0) & BIN8(00000001)) << 8);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT9, &res,0) & BIN8(00000001)) << 9);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT10,&res,0) & BIN8(00000001)) << 10);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT11,&res,0) & BIN8(00000001)) << 11);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT12,&res,0) & BIN8(00000111)) << 12);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT13,&res,0) & BIN8(00000001)) << 15);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT14,&res,0) & BIN8(00000001)) << 16);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT15,&res,0) & BIN8(00000001)) << 17);
			  tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT22,&res,0) & BIN8(00000001)) << 18);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT16,&res,0) & BIN8(00000001)) << 19);
			  tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT23,&res,0) & BIN8(00000011)) << 20);
			  tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT24,&res,0) & BIN8(00000001)) << 22);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT17,&res,0) & BIN8(00000001)) << 24);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT18,&res,0) & BIN8(00000001)) << 25);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT19,&res,0) & BIN8(00000001)) << 26);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT20,&res,0) & BIN8(00000001)) << 27);
              tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT21,&res,0) & BIN8(00000001)) << 28);
			  tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT25,&res,0) & BIN8(00000001)) << 29);
			  tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT26,&res,0) & BIN8(00000011)) << 30);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_MISCINIT1_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_MISCINIT1_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT1, &res,0) & BIN8(00000001)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT2, &res,0) & BIN8(00000011)) << 1);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT3, &res,0) & BIN8(00000001)) << 3);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT4, &res,0) & BIN8(00000001)) << 4);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT5, &res,0) & BIN8(00000001)) << 5);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT6, &res,0) & BIN8(00000001)) << 6);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT7, &res,0) & BIN8(00000001)) << 7);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT8, &res,0) & BIN8(00000001)) << 8);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT9, &res,0) & BIN8(00000001)) << 9);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT10,&res,0) & BIN8(00000001)) << 10);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT11,&res,0) & BIN8(00000001)) << 11);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT12,&res,0) & BIN8(00000111)) << 12);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT13,&res,0) & BIN8(00000001)) << 15);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT14,&res,0) & BIN8(00000001)) << 16);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT15,&res,0) & BIN8(00000001)) << 17);
			 tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT22,&res,0) & BIN8(00000001)) << 18);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT16,&res,0) & BIN8(00000001)) << 19);
  		     tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT23,&res,0) & BIN8(00000011)) << 20);
		     tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT24,&res,0) & BIN8(00000001)) << 22);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT17,&res,0) & BIN8(00000001)) << 24);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT18,&res,0) & BIN8(00000001)) << 25);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT19,&res,0) & BIN8(00000001)) << 26);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT20,&res,0) & BIN8(00000001)) << 27);
             tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT21,&res,0) & BIN8(00000001)) << 28);
			 tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT25,&res,0) & BIN8(00000001)) << 29);
			 tmp |= ((GetDlgItemInt(hDlg,IDC_NEDIT26,&res,0) & BIN8(00000011)) << 30);
             biosparam.miscinit1 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.miscinit1);
             SetDlgItemText(hpw[3],IDC_MISCINIT1,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc8(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.draminit0,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_DRAMINIT0_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.draminit0);
       SetDlgItemText(hDlg,IDC_DRAMINIT0_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_DEDIT1, (biosparam.draminit0 & BIN32(00000000,00000000,00000000,00000011))>>0, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT2, (biosparam.draminit0 & BIN32(00000000,00000000,00000000,00001100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT3, (biosparam.draminit0 & BIN32(00000000,00000000,00000000,00110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT4, (biosparam.draminit0 & BIN32(00000000,00000000,00000011,11000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT5, (biosparam.draminit0 & BIN32(00000000,00000000,00111100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_DEDIT6, (biosparam.draminit0 & BIN32(00000000,00000000,11000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_DEDIT7, (biosparam.draminit0 & BIN32(00000000,00000001,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_DEDIT8, (biosparam.draminit0 & BIN32(00000000,00000010,00000000,00000000))>>17,0);
       SetDlgItemInt(hDlg,IDC_DEDIT9, (biosparam.draminit0 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_DEDIT10,(biosparam.draminit0 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
       SetDlgItemInt(hDlg,IDC_DEDIT11,(biosparam.draminit0 & BIN32(00000000,00110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_DEDIT12,(biosparam.draminit0 & BIN32(00000000,01000000,00000000,00000000))>>22,0);
       SetDlgItemInt(hDlg,IDC_DEDIT13,(biosparam.draminit0 & BIN32(00000000,10000000,00000000,00000000))>>23,0);
       SetDlgItemInt(hDlg,IDC_DEDIT14,(biosparam.draminit0 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_DEDIT15,(biosparam.draminit0 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_DEDIT16,(biosparam.draminit0 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_DEDIT17,(biosparam.draminit0 & BIN32(00111000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_DEDIT18,(biosparam.draminit0 & BIN32(01000000,00000000,00000000,00000000))>>30,0);

       SetDlgItemInt(hDlg,IDC_DEDIT19,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,00000000,00000011))>>0, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT20,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,00000000,00001100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT21,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,00000000,00110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT22,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,00000011,11000000))>>6, 0);
       SetDlgItemInt(hDlg,IDC_DEDIT23,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,00111100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_DEDIT24,(biosparam.cmpdraminit0 & BIN32(00000000,00000000,11000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_DEDIT25,(biosparam.cmpdraminit0 & BIN32(00000000,00000001,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_DEDIT26,(biosparam.cmpdraminit0 & BIN32(00000000,00000010,00000000,00000000))>>17,0);
       SetDlgItemInt(hDlg,IDC_DEDIT27,(biosparam.cmpdraminit0 & BIN32(00000000,00000100,00000000,00000000))>>18,0);
       SetDlgItemInt(hDlg,IDC_DEDIT28,(biosparam.cmpdraminit0 & BIN32(00000000,00001000,00000000,00000000))>>19,0);
       SetDlgItemInt(hDlg,IDC_DEDIT29,(biosparam.cmpdraminit0 & BIN32(00000000,00110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_DEDIT30,(biosparam.cmpdraminit0 & BIN32(00000000,01000000,00000000,00000000))>>22,0);
       SetDlgItemInt(hDlg,IDC_DEDIT31,(biosparam.cmpdraminit0 & BIN32(00000000,10000000,00000000,00000000))>>23,0);
       SetDlgItemInt(hDlg,IDC_DEDIT32,(biosparam.cmpdraminit0 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_DEDIT33,(biosparam.cmpdraminit0 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_DEDIT34,(biosparam.cmpdraminit0 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_DEDIT35,(biosparam.cmpdraminit0 & BIN32(00111000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_DEDIT36,(biosparam.cmpdraminit0 & BIN32(01000000,00000000,00000000,00000000))>>30,0);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_DEDIT1:
		 case IDC_DEDIT2:
		 case IDC_DEDIT3:
		 case IDC_DEDIT4:
		 case IDC_DEDIT5:
		 case IDC_DEDIT6:
		 case IDC_DEDIT7:
		 case IDC_DEDIT8:
		 case IDC_DEDIT9:
		 case IDC_DEDIT10:
		 case IDC_DEDIT11:
		 case IDC_DEDIT12:
		 case IDC_DEDIT13:
		 case IDC_DEDIT14:
		 case IDC_DEDIT15:
		 case IDC_DEDIT16:
		 case IDC_DEDIT17:
		 case IDC_DEDIT18:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT1, &res,0) & BIN8(00000011)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT2, &res,0) & BIN8(00000011)) << 2);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT3, &res,0) & BIN8(00000011)) << 4);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT4, &res,0) & BIN8(00001111)) << 6);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT5, &res,0) & BIN8(00001111)) << 10);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT6, &res,0) & BIN8(00000011)) << 14);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT7, &res,0) & BIN8(00000001)) << 16);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT8, &res,0) & BIN8(00000001)) << 17);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT9, &res,0) & BIN8(00000001)) << 18);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT10,&res,0) & BIN8(00000001)) << 19);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT11,&res,0) & BIN8(00000011)) << 20);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT12,&res,0) & BIN8(00000001)) << 22);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT13,&res,0) & BIN8(00000001)) << 23);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT14,&res,0) & BIN8(00000001)) << 24);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT15,&res,0) & BIN8(00000001)) << 25);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT16,&res,0) & BIN8(00000001)) << 26);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT17,&res,0) & BIN8(00000111)) << 27);
              tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT18,&res,0) & BIN8(00000001)) << 30);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_DRAMINIT0_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_DRAMINIT0_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT1, &res,0) & BIN8(00000011)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT2, &res,0) & BIN8(00000011)) << 2);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT3, &res,0) & BIN8(00000011)) << 4);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT4, &res,0) & BIN8(00001111)) << 6);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT5, &res,0) & BIN8(00001111)) << 10);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT6, &res,0) & BIN8(00000011)) << 14);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT7, &res,0) & BIN8(00000001)) << 16);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT8, &res,0) & BIN8(00000001)) << 17);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT9, &res,0) & BIN8(00000001)) << 18);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT10,&res,0) & BIN8(00000001)) << 19);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT11,&res,0) & BIN8(00000011)) << 21);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT12,&res,0) & BIN8(00000001)) << 22);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT13,&res,0) & BIN8(00000001)) << 23);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT14,&res,0) & BIN8(00000001)) << 24);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT15,&res,0) & BIN8(00000001)) << 25);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT16,&res,0) & BIN8(00000001)) << 26);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT17,&res,0) & BIN8(00000111)) << 27);
             tmp |= ((GetDlgItemInt(hDlg,IDC_DEDIT18,&res,0) & BIN8(00000001)) << 30);
             biosparam.draminit0 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.draminit0);
             SetDlgItemText(hpw[3],IDC_DRAMINIT0,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}


LRESULT CALLBACK pWndProc9(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.draminit1,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_DRAMINIT1_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.draminit1);
       SetDlgItemText(hDlg,IDC_DRAMINIT1_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_TEDIT1, (biosparam.draminit1 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_TEDIT2, (biosparam.draminit1 & BIN32(00000000,00000000,00000011,11111110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_TEDIT3, (biosparam.draminit1 & BIN32(00000000,00000000,00000100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_TEDIT4, (biosparam.draminit1 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_TEDIT5, (biosparam.draminit1 & BIN32(00000000,00000000,00010000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_TEDIT6, (biosparam.draminit1 & BIN32(00000000,00000000,00100000,00000000))>>13,0);
       SetDlgItemInt(hDlg,IDC_TEDIT7, (biosparam.draminit1 & BIN32(00000000,00000000,01000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_TEDIT8, (biosparam.draminit1 & BIN32(00000000,00000000,10000000,00000000))>>15,0);
       SetDlgItemInt(hDlg,IDC_TEDIT9, (biosparam.draminit1 & BIN32(00000000,00001111,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_TEDIT10,(biosparam.draminit1 & BIN32(00000000,11110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_TEDIT11,(biosparam.draminit1 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_TEDIT12,(biosparam.draminit1 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_TEDIT13,(biosparam.draminit1 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_TEDIT14,(biosparam.draminit1 & BIN32(00001000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_TEDIT15,(biosparam.draminit1 & BIN32(00010000,00000000,00000000,00000000))>>28,0);
       SetDlgItemInt(hDlg,IDC_TEDIT16,(biosparam.draminit1 & BIN32(00100000,00000000,00000000,00000000))>>29,0);
       SetDlgItemInt(hDlg,IDC_TEDIT17,(biosparam.draminit1 & BIN32(01000000,00000000,00000000,00000000))>>30,0);

       SetDlgItemInt(hDlg,IDC_TEDIT18,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_TEDIT19,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00000011,11111110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_TEDIT20,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00000100,00000000))>>10,0);
       SetDlgItemInt(hDlg,IDC_TEDIT21,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00001000,00000000))>>11,0);
       SetDlgItemInt(hDlg,IDC_TEDIT22,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00010000,00000000))>>12,0);
       SetDlgItemInt(hDlg,IDC_TEDIT23,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,00100000,00000000))>>13,0);
       SetDlgItemInt(hDlg,IDC_TEDIT24,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,01000000,00000000))>>14,0);
       SetDlgItemInt(hDlg,IDC_TEDIT25,(biosparam.cmpdraminit1 & BIN32(00000000,00000000,10000000,00000000))>>15,0);
       SetDlgItemInt(hDlg,IDC_TEDIT26,(biosparam.cmpdraminit1 & BIN32(00000000,00001111,00000000,00000000))>>16,0);
       SetDlgItemInt(hDlg,IDC_TEDIT27,(biosparam.cmpdraminit1 & BIN32(00000000,11110000,00000000,00000000))>>20,0);
       SetDlgItemInt(hDlg,IDC_TEDIT28,(biosparam.cmpdraminit1 & BIN32(00000001,00000000,00000000,00000000))>>24,0);
       SetDlgItemInt(hDlg,IDC_TEDIT29,(biosparam.cmpdraminit1 & BIN32(00000010,00000000,00000000,00000000))>>25,0);
       SetDlgItemInt(hDlg,IDC_TEDIT30,(biosparam.cmpdraminit1 & BIN32(00000100,00000000,00000000,00000000))>>26,0);
       SetDlgItemInt(hDlg,IDC_TEDIT31,(biosparam.cmpdraminit1 & BIN32(00001000,00000000,00000000,00000000))>>27,0);
       SetDlgItemInt(hDlg,IDC_TEDIT32,(biosparam.cmpdraminit1 & BIN32(00010000,00000000,00000000,00000000))>>28,0);
       SetDlgItemInt(hDlg,IDC_TEDIT33,(biosparam.cmpdraminit1 & BIN32(00100000,00000000,00000000,00000000))>>29,0);
       SetDlgItemInt(hDlg,IDC_TEDIT34,(biosparam.cmpdraminit1 & BIN32(01000000,00000000,00000000,00000000))>>30,0);

       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_TEDIT1:
		 case IDC_TEDIT2:
		 case IDC_TEDIT3:
		 case IDC_TEDIT4:
		 case IDC_TEDIT5:
		 case IDC_TEDIT6:
		 case IDC_TEDIT7:
		 case IDC_TEDIT8:
		 case IDC_TEDIT9:
		 case IDC_TEDIT10:
		 case IDC_TEDIT11:
		 case IDC_TEDIT12:
		 case IDC_TEDIT13:
		 case IDC_TEDIT14:
		 case IDC_TEDIT15:
		 case IDC_TEDIT16:
		 case IDC_TEDIT17:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT1, &res,0) & BIN8(00000001)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT2, &res,0) & BIN16(00000001,11111111)) << 1);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT3, &res,0) & BIN8(00000001)) << 10);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT4, &res,0) & BIN8(00000001)) << 11);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT5, &res,0) & BIN8(00000001)) << 12);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT6, &res,0) & BIN8(00000001)) << 13);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT7, &res,0) & BIN8(00000001)) << 14);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT8, &res,0) & BIN8(00000001)) << 15);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT9, &res,0) & BIN8(00001111)) << 16);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT10,&res,0) & BIN8(00001111)) << 20);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT11,&res,0) & BIN8(00000001)) << 24);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT12,&res,0) & BIN8(00000001)) << 25);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT13,&res,0) & BIN8(00000001)) << 26);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT14,&res,0) & BIN8(00000001)) << 27);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT15,&res,0) & BIN8(00000001)) << 28);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT16,&res,0) & BIN8(00000001)) << 29);
              tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT17,&res,0) & BIN8(00000001)) << 30);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_DRAMINIT1_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_DRAMINIT1_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT1, &res,0) & BIN8(00000001)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT2, &res,0) & BIN16(00000001,11111111)) << 1);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT3, &res,0) & BIN8(00000001)) << 10);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT4, &res,0) & BIN8(00000001)) << 11);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT5, &res,0) & BIN8(00000001)) << 12);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT6, &res,0) & BIN8(00000001)) << 13);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT7, &res,0) & BIN8(00000001)) << 14);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT8, &res,0) & BIN8(00000001)) << 15);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT9, &res,0) & BIN8(00001111)) << 16);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT10,&res,0) & BIN8(00001111)) << 20);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT11,&res,0) & BIN8(00000001)) << 24);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT12,&res,0) & BIN8(00000001)) << 25);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT13,&res,0) & BIN8(00000001)) << 26);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT14,&res,0) & BIN8(00000001)) << 27);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT15,&res,0) & BIN8(00000001)) << 28);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT16,&res,0) & BIN8(00000001)) << 29);
             tmp |= ((GetDlgItemInt(hDlg,IDC_TEDIT17,&res,0) & BIN8(00000001)) << 30);
             biosparam.draminit1 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.draminit1);
             SetDlgItemText(hpw[3],IDC_DRAMINIT1,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc10(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.agpinit0,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_AGPINIT0_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.agpinit0);
       SetDlgItemText(hDlg,IDC_AGPINIT0_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_AEDIT1, (biosparam.agpinit0 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT2, (biosparam.agpinit0 & BIN32(00000000,00000000,00000000,00001110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT3, (biosparam.agpinit0 & BIN32(00000000,00000000,00000000,01110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT4, (biosparam.agpinit0 & BIN32(00000000,00000000,00000111,10000000))>>7, 0);

       SetDlgItemInt(hDlg,IDC_AEDIT5, (biosparam.cmpagpinit0 & BIN32(00000000,00000000,00000000,00000001))>>0, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT6, (biosparam.cmpagpinit0 & BIN32(00000000,00000000,00000000,00001110))>>1, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT7, (biosparam.cmpagpinit0 & BIN32(00000000,00000000,00000000,01110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_AEDIT8, (biosparam.cmpagpinit0 & BIN32(00000000,00000000,00000111,10000000))>>7, 0);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_AEDIT1:
		 case IDC_AEDIT2:
		 case IDC_AEDIT3:
		 case IDC_AEDIT4:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_AEDIT1, &res,0) & BIN8(00000001)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_AEDIT2, &res,0) & BIN8(00000111)) << 1);
              tmp |= ((GetDlgItemInt(hDlg,IDC_AEDIT3, &res,0) & BIN8(00000111)) << 4);
              tmp |= ((GetDlgItemInt(hDlg,IDC_AEDIT4, &res,0) & BIN8(00001111)) << 7);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_AGPINIT0_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_AGPINIT0_HEX,(char*)textbuf);
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             biosparam.agpinit0 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.agpinit0);
             SetDlgItemText(hpw[3],IDC_AGPINIT0,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc11(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.pllctrl0,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_PLLCTRL0_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.pllctrl0);
       SetDlgItemText(hDlg,IDC_PLLCTRL0_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_PEDIT1, (biosparam.pllctrl0 & BIN32(00000000,00000000,00000000,00000011))>>0, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT2, (biosparam.pllctrl0 & BIN32(00000000,00000000,00000000,11111100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT3, (biosparam.pllctrl0 & BIN32(00000000,00000000,11111111,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT4, (biosparam.pllctrl0 & BIN32(00000000,00000001,00000000,00000000))>>16, 0);

       SetDlgItemInt(hDlg,IDC_PEDIT5, (biosparam.cmppllctrl0 & BIN32(00000000,00000000,00000000,00000011))>>0, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT6, (biosparam.cmppllctrl0 & BIN32(00000000,00000000,00000000,11111100))>>2, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT7, (biosparam.cmppllctrl0 & BIN32(00000000,00000000,11111111,00000000))>>8, 0);
       SetDlgItemInt(hDlg,IDC_PEDIT8, (biosparam.cmppllctrl0 & BIN32(00000000,00000001,00000000,00000000))>>16, 0);

	   tmp = biosparam.cmppllctrl0;
       k = tmp & BIN8(11);
       m = (tmp & BIN8(11111100)) >> 2;
       n = (tmp & 0xff00) >> 8;
       mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
       sprintf((char*)textbuf,"%g MHz",mgz);
       SetDlgItemText(hDlg,IDC_CMPMGZ,(char*)textbuf);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_PEDIT1:
		 case IDC_PEDIT2:
		 case IDC_PEDIT3:
		 case IDC_PEDIT4:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT1, &res,0) & BIN8(00000011)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT2, &res,0) & BIN8(00111111)) << 2);
              tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT3, &res,0) & BIN8(11111111)) << 8);
              tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT4, &res,0) & BIN8(00000001)) << 16);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_PLLCTRL0_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_PLLCTRL0_HEX,(char*)textbuf);

              k = tmp & BIN8(11);
              m = (tmp & BIN8(11111100)) >> 2;
              n = (tmp & 0xff00) >> 8;
              mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
              sprintf((char*)textbuf,"%g MHz",mgz);
              SetDlgItemText(hDlg,IDC_MGZ,(char*)textbuf);
			 
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT1, &res,0) & BIN8(00000011)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT2, &res,0) & BIN8(00111111)) << 2);
             tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT3, &res,0) & BIN8(11111111)) << 8);
             tmp |= ((GetDlgItemInt(hDlg,IDC_PEDIT4, &res,0) & BIN8(00000001)) << 16);
             biosparam.pllctrl0 = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.pllctrl0);
             SetDlgItemText(hpw[3],IDC_PLLCTRL0,(char*)textbuf);

             k = biosparam.pllctrl0 & BIN8(11);
             m = (biosparam.pllctrl0 & BIN8(11111100)) >> 2;
             n = (biosparam.pllctrl0 & 0xff00) >> 8;
             mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
             sprintf((char*)textbuf,"%g MHz",mgz,k,m,n);
             SetDlgItemText(hpw[3],IDC_SPEED,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc12(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   TextToBin(biosparam.sgrammode,(char*)textbuf);
	   SetDlgItemText(hDlg,IDC_SGRAMMODE_BIN,(char*)textbuf);
       wsprintf((char*)textbuf,"%08X",biosparam.sgrammode);
       SetDlgItemText(hDlg,IDC_SGRAMMODE_HEX,(char*)textbuf);

       SetDlgItemInt(hDlg,IDC_SEDIT1, (biosparam.sgrammode & BIN32(00000000,00000000,00000000,00000111))>>0, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT2, (biosparam.sgrammode & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT3, (biosparam.sgrammode & BIN32(00000000,00000000,00000000,01110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT4, (biosparam.sgrammode & BIN32(00000000,00000000,00000001,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT5, (biosparam.sgrammode & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT6, (biosparam.sgrammode & BIN32(00000000,00000000,00000100,00000000))>>10,0);

       SetDlgItemInt(hDlg,IDC_SEDIT7, (biosparam.cmpsgrammode & BIN32(00000000,00000000,00000000,00000111))>>0, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT8, (biosparam.cmpsgrammode & BIN32(00000000,00000000,00000000,00001000))>>3, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT9, (biosparam.cmpsgrammode & BIN32(00000000,00000000,00000000,01110000))>>4, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT10,(biosparam.cmpsgrammode & BIN32(00000000,00000000,00000001,10000000))>>7, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT11,(biosparam.cmpsgrammode & BIN32(00000000,00000000,00000010,00000000))>>9, 0);
       SetDlgItemInt(hDlg,IDC_SEDIT12,(biosparam.cmpsgrammode & BIN32(00000000,00000000,00000100,00000000))>>10,0);
       break;
  case WM_COMMAND:
	   if (HIWORD(wParam) == EN_CHANGE)
	   {
        switch (LOWORD(wParam))
		{
		 case IDC_SEDIT1:
		 case IDC_SEDIT2:
		 case IDC_SEDIT3:
		 case IDC_SEDIT4:
		 case IDC_SEDIT5:
		 case IDC_SEDIT6:
              tmp = 0;
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT1, &res,0) & BIN8(00000111)) << 0);
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT2, &res,0) & BIN8(00000001)) << 3);
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT3, &res,0) & BIN8(00000111)) << 4);
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT4, &res,0) & BIN8(00000011)) << 7);
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT5, &res,0) & BIN8(00000001)) << 9);
              tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT6, &res,0) & BIN8(00000001)) << 10);
              TextToBin(tmp,(char*)textbuf);
	          SetDlgItemText(hDlg,IDC_SGRAMMODE_BIN,(char*)textbuf);
              wsprintf((char*)textbuf,"%08X",tmp);
              SetDlgItemText(hDlg,IDC_SGRAMMODE_HEX,(char*)textbuf);		 
			  break;
		}
        break;
	   }
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
             EndDialog(hDlg,0);
             break;
        case IDOK:
             tmp = 0;
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT1, &res,0) & BIN8(00000111)) << 0);
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT2, &res,0) & BIN8(00000001)) << 3);
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT3, &res,0) & BIN8(00000111)) << 4);
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT4, &res,0) & BIN8(00000011)) << 7);
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT5, &res,0) & BIN8(00000001)) << 9);
             tmp |= ((GetDlgItemInt(hDlg,IDC_SEDIT6, &res,0) & BIN8(00000001)) << 10);
             biosparam.sgrammode = tmp;
             wsprintf((char*)textbuf,"%08X",biosparam.sgrammode);
             SetDlgItemText(hpw[3],IDC_SGRAMMODE,(char*)textbuf);
             CMPreg(hpw[3]);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
 }
 return FALSE;
}

void ViewFont(int fo)
{
 // fo = 0 8x8
 // fo = 1 8x14
 // fo = 2 8x16
 unsigned char *font;
 int i,j,k,num = 0;
 memset(fontimage,0,256*256/8);
 if (fo == 0)
 {
  font = (unsigned char *)biosparam.font8x8;
  if (!font) return;
  for (j=255;j>191;j-=8)
  {
   for (i=0;i<32;i++)
   { 
    for (k=0;k<8;k++)
    {
     fontimage[(j-k)*32+i] = font[num*8+k];
    }
    num++;
   }
  }
 }
 else if (fo == 1)
 {
  font = (unsigned char *)biosparam.font8x14;
  if (!font) return;
  for (j=255;j>143;j-=14)
  {
   for (i=0;i<32;i++)
   { 
    for (k=0;k<14;k++)
    {
     fontimage[(j-k)*32+i] = font[num*14+k];
    }
    num++;
   }
  }
 }
 else if (fo == 2)
 {
  font = (unsigned char *)biosparam.font8x16;
  if (!font) return;
  for (j=255;j>127;j-=16)
  {
   for (i=0;i<32;i++)
   { 
    for (k=0;k<16;k++)
    {
     fontimage[(j-k)*32+i] = font[num*16+k];
    }
    num++;
   }
  }
 }
}

LRESULT CALLBACK pWndProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 PAINTSTRUCT ps;
 switch (message)
 {
  case WM_INITDIALOG:
       hfontDC = GetDC(hDlg);
	   memset(&bmi,0,sizeof(BITMAPINFO));	   
	   bmi[0].bmiHeader.biHeight = 256;
	   bmi[0].bmiHeader.biWidth = 256;
	   bmi[0].bmiHeader.biPlanes = 1;
	   bmi[0].bmiHeader.biBitCount = 1;
	   bmi[0].bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
       scol = GetSysColor(COLOR_BTNFACE);
	   bmi[0].bmiColors[0].rgbBlue = (unsigned char)(scol & 0xff);
	   bmi[0].bmiColors[0].rgbGreen = (unsigned char)((scol & 0xff00) >> 8);
	   bmi[0].bmiColors[0].rgbRed = (unsigned char)((scol & 0xff0000) >> 16);
	   bmi[0].bmiColors[0].rgbReserved = 0;
	   bmi[0].bmiColors[1].rgbBlue = 0;
	   bmi[0].bmiColors[1].rgbGreen = 0;
	   bmi[0].bmiColors[1].rgbRed = 0;
	   bmi[0].bmiColors[1].rgbReserved = 0;
	   hFontBitmap = CreateDIBSection(GetDC(hDlg),&bmi[0],DIB_RGB_COLORS,(void**)&fontimage,NULL,NULL);
	   memset(fontimage,0,256*256/8);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
	    case IDC_ALTERNATIVESEARCH2:
			 if (loadingbios == false) break; 
			 switch (fontmode)
			 {
			  case 0:
				   if (AltFindFont(0) == 1) goto l1;
				   break;
			  case 1:
				   if (AltFindFont(1) == 1) goto l2;
				   break;
			  case 2:
				   if (AltFindFont(2) == 1) goto l3;
				   break;
			 }
             break;
	    case IDC_ALTERNATIVESEARCH:
			 // альтернативный поиск фонта по другому фонту
			 // предположительно они идут друг за другом.
			 if (loadingbios == false) break; 
			 switch (fontmode)
			 {
			  case 0:
				   if (biosparam.offsetf8x14 == 0 || biosparam.font8x14 == 0) break;
                   biosparam.offsetf8x8 = biosparam.offsetf8x14 - 0x800;
                   biosparam.font8x8 = biosparam.font8x14 - 0x800;
				   goto l1;
			  case 1:
				   if (biosparam.offsetf8x8 == 0 || biosparam.font8x8 == 0) break;
                   biosparam.offsetf8x14 = biosparam.offsetf8x8 + 0x800;
                   biosparam.font8x14 = biosparam.font8x8 + 0x800;
				   goto l2;
			  case 2:
				   if (biosparam.offsetf8x14 == 0 || biosparam.font8x14 == 0) break;
                   biosparam.offsetf8x16 = biosparam.offsetf8x14 + 0xe00;
                   biosparam.font8x16 = biosparam.font8x14 + 0xe00;
				   goto l3;
				   break;
			 }
             break;
        case IDC_8X8:
l1:;
			 fontmode = 0;
			 ViewFont(fontmode);
			 SetDlgItemText(hpw[0],IDC_LOADFONT,"Load Font 8x8");
			 SetDlgItemText(hpw[0],IDC_SAVEFONT,"Save Font 8x8");
			 wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x8);
             SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
             SetDlgItemText(hpw[0],IDC_OFFSETTABLE,"0");
			 UpdateWindow(hpw[0]);
			 ShowWindow(hpw[0],SW_NORMAL);
			 SendMessage(hpw[0],WM_PAINT,0,0);
             break;			 
        case IDC_8X14:
l2:;
			 fontmode = 1;
			 ViewFont(fontmode);
			 SetDlgItemText(hpw[0],IDC_LOADFONT,"Load Font 8x14");
			 SetDlgItemText(hpw[0],IDC_SAVEFONT,"Save Font 8x14");
			 wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x14);
             SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
			 wsprintf((char*)textbuf,"%04X",biosparam.offsetf9x14);
             SetDlgItemText(hpw[0],IDC_OFFSETTABLE,(char*)textbuf);
             
			 UpdateWindow(hpw[0]);
			 ShowWindow(hpw[0],SW_NORMAL);
			 SendMessage(hpw[0],WM_PAINT,0,0);
             break;			 
        case IDC_8X16:
l3:;
			 fontmode = 2;
			 ViewFont(fontmode);
			 SetDlgItemText(hpw[0],IDC_LOADFONT,"Load Font 8x16");
			 SetDlgItemText(hpw[0],IDC_SAVEFONT,"Save Font 8x16");
			 wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x16);
             SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
			 wsprintf((char*)textbuf,"%04X",biosparam.offsetf9x16);
             SetDlgItemText(hpw[0],IDC_OFFSETTABLE,(char*)textbuf);

			 UpdateWindow(hpw[0]);
			 ShowWindow(hpw[0],SW_NORMAL);
			 SendMessage(hpw[0],WM_PAINT,0,0);
             break;			 
        case IDC_LOADFONT:
			 if (loadingbios == false) break;


			 {
			  int ml = LoadFont();
              if (ml > 0)
			  {
			   if (ml == 1)
                MessageBox(hDlg,"FONT loading error!!!","ERROR",MB_ICONHAND | MB_OK);
			   break;
			  }
			 }


			 ViewFont(fontmode);
             ViewDump(hpw[1],0,0);
             if (fontmode == 0)
			 {
			  wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x8);
              SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
              SetDlgItemText(hpw[0],IDC_OFFSETTABLE,"0");
			 }
             if (fontmode == 1)
			 {
			  wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x14);
              SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
              wsprintf((char*)textbuf,"%04X",biosparam.offsetf9x14);
              SetDlgItemText(hpw[0],IDC_OFFSETTABLE,(char*)textbuf);
			 }
             if (fontmode == 2)
			 {
			  wsprintf((char*)textbuf,"%04X",biosparam.offsetf8x16);
              SetDlgItemText(hpw[0],IDC_OFFSETFONT,(char*)textbuf);
              wsprintf((char*)textbuf,"%04X",biosparam.offsetf9x16);
              SetDlgItemText(hpw[0],IDC_OFFSETTABLE,(char*)textbuf);
			 }
			 UpdateWindow(hpw[0]);
			 ShowWindow(hpw[0],SW_NORMAL);
			 SendMessage(hpw[0],WM_PAINT,0,0);
             break;			 
        case IDC_SAVEFONT:
			 if (loadingbios == false) break;
             if (SaveFont() == 1)
			 {
              MessageBox(hDlg,"FONT saving error!!!","ERROR",MB_ICONHAND | MB_OK);
			 }
             break;
        case IDC_OFFSETFONT:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 if (fontmode == 0) ViewDump(hpw[1],dumpview,256*8);
			 if (fontmode == 1) ViewDump(hpw[1],dumpview,256*14);
			 if (fontmode == 2) ViewDump(hpw[1],dumpview,256*16);
             break;
        case IDC_OFFSETTABLE:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 if (fontmode == 1) ViewDump(hpw[1],dumpview,biosparam.lentfont9x14);
			 if (fontmode == 2) ViewDump(hpw[1],dumpview,biosparam.lentfont9x16);
             break;
	   }
	   break;
  case WM_PAINT:
	   if (hFontBitmap != 0)
	   {
        BeginPaint(hDlg, &ps);
        DrawBitmap(hfontDC,150,75,hFontBitmap);
        EndPaint(hDlg, &ps);
	   }
       break;
 }
 return FALSE;
}

int LoadFont(void)
{
 int hFile,lenfile,readlen;
 OPENFILENAME ofn;
 static char szFilter[] = "font file (*.fnt;*.cpi)\0*.fnt;*.cpi\0\0";
 static char szFileName[_MAX_PATH];
 char szTitleName[_MAX_FNAME + _MAX_EXT] ;
 char *extfile;
 char opext[4];

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME) ;
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName ;
 ofn.nMaxFile          = _MAX_PATH ;
 ofn.lpstrFileTitle    = szTitleName ;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT ;
 ofn.Flags             = OFN_HIDEREADONLY ;
 ofn.lpstrTitle        = "Load FONT";
 if( !GetOpenFileName(&ofn)) return 2;

 extfile = ofn.lpstrFile + ofn.nFileExtension;
 
 // Проверка на наличие файла
 hFile = _lopen(szFileName, OF_READ);
 if (hFile == -1) return 1;
 // Определение длины файла
 lenfile = _llseek(hFile, 0, 2);
 _llseek(hFile, 0, 0);
 
 //определение типа файла (fnt или cpi)
 if (lstrlen(extfile) != 3)
 {
  _lclose(hFile);
  return 1;
 }
 
 opext[0] = tolower(extfile[0]);
 opext[1] = tolower(extfile[1]);
 opext[2] = tolower(extfile[2]);
 opext[3] = 0;

 if (opext[0] == 'c' && opext[1] == 'p' && opext[2] == 'i') goto getcpifile;

 if (opext[0] == 'f' && opext[1] == 'n' && opext[2] == 't') goto getfntfile;

 _lclose(hFile);
 return 1;

getfntfile:;
  
 // Чтение файла
 if (lenfile == 256*8 && fontmode == 0)
 {
  if (biosparam.font8x8) readlen = _lread(hFile,biosparam.font8x8,lenfile);
 }
 else if (lenfile == 256*14 && fontmode == 1)
 {
  if (biosparam.font8x14) readlen = _lread(hFile,biosparam.font8x14,lenfile);
 }
 else if (lenfile == 256*16 && fontmode == 2)
 {
  if (biosparam.font8x16) readlen = _lread(hFile,biosparam.font8x16,lenfile);
 }
 else
 {
  _lclose(hFile);
  return 1;
 }

 if (readlen == HFILE_ERROR || readlen != lenfile)
 {
  _lclose(hFile);
  return 1;
 }
 // Закрытие файла
 _lclose(hFile);

correcttable:;

 // корректировка таблиц 9x
 // 9x14
 int sym;
 char *tfont,*font;
 if (biosparam.tfont9x14 != 0)
 {
  tfont = biosparam.tfont9x14;
l2:;
  sym = (int)((unsigned char)tfont[0]);
  if (sym == 0) goto l1;
  font = biosparam.font8x14 + sym*14;
  memcpy(tfont+1,font,14);
  tfont += 15;
  goto l2;
 }
l1:;
 // 9x16
 if (biosparam.tfont9x16 != 0)
 {
  tfont = biosparam.tfont9x16;
l3:;
  sym = (int)((unsigned char)tfont[0]);
  if (sym == 0) goto l4;
  font = biosparam.font8x16 + sym*16;
  memcpy(tfont+1,font,16);
  tfont += 17;
  goto l3;
 }
l4:;
 return 0;

getcpifile:;
 
 if (cpifile) free(cpifile);
 cpifile = (unsigned char*)malloc(lenfile);
 if (cpifile == 0)
 {
  _lclose(hFile);
  return 1;
 }
 readlen = _lread(hFile,cpifile,lenfile);
 if (readlen == HFILE_ERROR || readlen != lenfile)
 {
  _lclose(hFile);
  return 1;
 }
 _lclose(hFile);


 if (cpifile[0] != 0xff || cpifile[1] != 'F' || cpifile[2] != 'O' || cpifile[3] != 'N' || cpifile[4] != 'T')
 {
  free(cpifile);
  return 1;
 }
	  
 wsprintf((char*)textbuf,"Select Font [%s]",szTitleName);
 DialogBox(hInst,MAKEINTRESOURCE(IDD_SELECTFONT),hmWnd,(DLGPROC)pWndProc15);
 
 goto correcttable;
}

int SaveFont(void)
{
 int hFile;
 OPENFILENAME ofn;
 static char szFilter[] = "font file (*.fnt)\0*.fnt\0\0";
 static char szFileName[_MAX_PATH];
 char szTitleName[_MAX_FNAME + _MAX_EXT] ;

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME);
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName;
 ofn.nMaxFile          = _MAX_PATH;
 ofn.lpstrFileTitle    = szTitleName;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT;
 ofn.Flags             = OFN_HIDEREADONLY | OFN_EXTENSIONDIFFERENT | OFN_OVERWRITEPROMPT;
 ofn.lpstrDefExt       = "*.rom";
 ofn.lpstrTitle        = "Save FONT";
 if(!GetSaveFileName(&ofn)) return 2;

 hFile = _lcreat(szFileName, 0);
 if (hFile == -1) return 1;
 _llseek(hFile, 0, 2);

 if (fontmode == 0)
 {
  _lwrite(hFile,(char*)biosparam.font8x8,256*8);
 }
 else if (fontmode == 1)
 {
  _lwrite(hFile,(char*)biosparam.font8x14,256*14);
 }
 else if (fontmode == 2)
 {
  _lwrite(hFile,(char*)biosparam.font8x16,256*16);
 }
 else
 {
  _lclose(hFile);
  return 1;
 }
 _lclose(hFile);
 return 0;
}

bool SaveBios(void)
{
 int hFile;
 OPENFILENAME ofn;
 static char szFilter[] = "BIOS file (*.rom)\0*.rom\0\0";
 static char szFileName[_MAX_PATH];
 char szTitleName[_MAX_FNAME + _MAX_EXT];

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME);
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName;
 ofn.nMaxFile          = _MAX_PATH;
 ofn.lpstrFileTitle    = szTitleName;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT;
 ofn.Flags             = OFN_HIDEREADONLY | OFN_EXTENSIONDIFFERENT | OFN_OVERWRITEPROMPT;
 ofn.lpstrDefExt       = "*.rom";
 ofn.lpstrTitle        = "Save BIOS";
 if( !GetSaveFileName(&ofn)) return false;

 hFile = _lcreat(szFileName, 0);
 if (hFile == -1) return false;
 _llseek(hFile, 0, 2);
 _lwrite(hFile,(char*)bios,lenbios);
 _lclose(hFile);
 return true;
}

LRESULT CALLBACK pWndProc13(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
		case IDC_OFFSETPCIR:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,22);
			 break;
	   }
	   break;
 }
 return FALSE;
}

void CalcCRC(void)
{
 unsigned char crc = 0,chc;
 int lenbios = bios[2]*0x200;
 chc = bios[lenbios-1];
 bios[lenbios-1] = 0;
 for (int i = 0;i<lenbios;i++)
 {
  crc += bios[i];
 }
 crc = -crc;
 bios[lenbios-1] = crc;
}

LRESULT CALLBACK pWndProc14(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       // установка шрифта
       SendDlgItemMessage(hDlg,IDC_VESA_VENDORINFO,WM_SETFONT,(WPARAM)hFont,0);
       SendDlgItemMessage(hDlg,IDC_VESA_VENDORNAME,WM_SETFONT,(WPARAM)hFont,0);
       SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTNAME,WM_SETFONT,(WPARAM)hFont,0);
       SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTREVISION,WM_SETFONT,(WPARAM)hFont,0);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
		case IDC_VESA_VENDORINFO:
		case IDC_VESA_VENDORNAME:
		case IDC_VESA_PRODUCTNAME:
		case IDC_VESA_PRODUCTREVISION:
             if (HIWORD(wParam) == EN_UPDATE && loadingbios == true)
			 {
              vesaapply = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			 }
			 break;
        case IDC_APPLY:
             if (loadingbios == true)
			 {
			  vesaapply = true;
			  loadingbios = false;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);

			  if (biosparam.lpProductName != 0)
			  {
			   memset((char*)biosparam.lpProductName,' ',biosparam.maxlenprname);
               GetDlgItemText(hDlg,IDC_VESA_PRODUCTNAME,(char*)biosparam.lpProductName,biosparam.maxlenprname+1);
			  }
			  if (biosparam.lpProductRev != 0)
			  {
 			   memset((char*)biosparam.lpProductRev,' ',biosparam.maxlenprrev);
               GetDlgItemText(hDlg,IDC_VESA_PRODUCTREVISION,(char*)biosparam.lpProductRev,biosparam.maxlenprrev+1);
			  }
			  if (biosparam.lpVendorName != 0)
			  {
               memset((char*)biosparam.lpVendorName,' ',biosparam.maxlenvenname);
               GetDlgItemText(hDlg,IDC_VESA_VENDORNAME,(char*)biosparam.lpVendorName,biosparam.maxlenvenname+1);
			  }
			  if (biosparam.lpVendorInfo != 0)
			  {
               memset((char*)biosparam.lpVendorInfo,' ',biosparam.maxlenveninfo);
               GetDlgItemText(hDlg,IDC_VESA_VENDORINFO,(char*)biosparam.lpVendorInfo,biosparam.maxlenveninfo+1);
			  }
              ViewDump(hpw[1],0,0);
			  loadingbios = true;
			 }
             break;
        case IDC_RESTORE:
			 if (loadingbios == true)
			 {
			  vesaapply = true;
              EnableWindow(GetDlgItem(hDlg,IDC_APPLY),FALSE);
			  loadingbios = false;

			  if (biosparam.lpVendorInfo != 0)
			  {
               SendDlgItemMessage(hDlg,IDC_VESA_VENDORINFO,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VESA_VENDORINFO,(char*)biosparam.lpVendorInfo);
               SendDlgItemMessage(hDlg,IDC_VESA_VENDORINFO,EM_LIMITTEXT,biosparam.maxlenveninfo,0);
			  }
   			  if (biosparam.lpVendorName != 0)
			  {
 			   SendDlgItemMessage(hDlg,IDC_VESA_VENDORNAME,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VESA_VENDORNAME,(char*)biosparam.lpVendorName);
               SendDlgItemMessage(hDlg,IDC_VESA_VENDORNAME,EM_LIMITTEXT,biosparam.maxlenvenname,0);
			  }
   			  if (biosparam.lpProductRev != 0)
			  {
               SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTREVISION,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VESA_PRODUCTREVISION,(char*)biosparam.lpProductRev);
               SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTREVISION,EM_LIMITTEXT,biosparam.maxlenprrev,0);
			  }
   			  if (biosparam.lpProductName != 0)
			  {
               SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTNAME,EM_LIMITTEXT,0,0);
               SetDlgItemText(hDlg,IDC_VESA_PRODUCTNAME,(char*)biosparam.lpProductName);
               SendDlgItemMessage(hDlg,IDC_VESA_PRODUCTNAME,EM_LIMITTEXT,biosparam.maxlenprname,0);             
			  }
              loadingbios = true;
			 }
			 break;
		case IDC_OFFSETPRODUCTNAME:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenprname);
			 break;
		case IDC_OFFSETPRODUCTREVISION:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenprrev);
			 break;
		case IDC_OFFSETVENDORNAME:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenvenname);
			 break;
		case IDC_OFFSETVENDORINFO:
			 SendDlgItemMessage(hDlg,LOWORD(wParam),WM_GETTEXT,256,(LPARAM)textbuf);
             sscanf((char*)textbuf,"%X",&dumpview);
			 ViewDump(hpw[1],dumpview,biosparam.maxlenveninfo);
			 break;
	   }
	   break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc15(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 PAINTSTRUCT ps;
 switch (message)
 {
  case WM_INITDIALOG:
       SetWindowText(hDlg,(char*)textbuf);
	   GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
	   // Определение количества кодовых страниц
	   GetCountCodePage(hDlg);
	   SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,0,0);
       // 
	   hbigfontDC = GetDC(hDlg);
	   memset(&bigbmi,0,sizeof(BITMAPINFO));	   
	   bigbmi[0].bmiHeader.biHeight = 512;
	   bigbmi[0].bmiHeader.biWidth = 256;
	   bigbmi[0].bmiHeader.biPlanes = 1;
	   bigbmi[0].bmiHeader.biBitCount = 1;
	   bigbmi[0].bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
       scol = GetSysColor(COLOR_BTNFACE);
	   bigbmi[0].bmiColors[0].rgbBlue = (unsigned char)(scol & 0xff);
	   bigbmi[0].bmiColors[0].rgbGreen = (unsigned char)((scol & 0xff00) >> 8);
	   bigbmi[0].bmiColors[0].rgbRed = (unsigned char)((scol & 0xff0000) >> 16);
	   bigbmi[0].bmiColors[0].rgbReserved = 0;
	   bigbmi[0].bmiColors[1].rgbBlue = 0;
	   bigbmi[0].bmiColors[1].rgbGreen = 0;
	   bigbmi[0].bmiColors[1].rgbRed = 0;
	   bigbmi[0].bmiColors[1].rgbReserved = 0;
	   hBigFontBitmap = CreateDIBSection(GetDC(hDlg),&bigbmi[0],DIB_RGB_COLORS,(void**)&bigfont,NULL,NULL);
	   View3Font(hDlg);
	   SetTimer(hDlg,1,200,NULL);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDCANCEL:
			 KillTimer(hDlg,1);
             EndDialog(hDlg,0);
             break;
        case IDOK:
			 GetChFont(hDlg);
			 KillTimer(hDlg,1);
             EndDialog(hDlg,0);
             break;
	   }
	   break;
  case WM_TIMER:
       switch (wParam)
       {
        case 1:
             View3Font(hDlg);
			 UpdateWindow(hDlg);
			 ShowWindow(hDlg,SW_NORMAL);
			 SendMessage(hDlg,WM_PAINT,0,0);
             break;
       }
       break;
  case WM_PAINT:
	   if (hBigFontBitmap != 0)
	   {
        BeginPaint(hDlg, &ps);
        DrawBitmap(hbigfontDC,160,8,hBigFontBitmap);
        EndPaint(hDlg, &ps);
	   }
       break;
 }
 return FALSE;
}

void GetCountCodePage(HWND hwnd)
{
 unsigned char *fadr;
 int j,codepage,entr,fontdata;
 SendDlgItemMessage(hwnd,IDC_LIST1,LB_RESETCONTENT,(WPARAM)0,(LPARAM)0);
 fadr = cpifile + 25;
 entr = (int)*((unsigned short*)(cpifile+23));
 for (j = 0;j<entr;j++)
 {
  codepage = (int)*((unsigned short*)(fadr+16));
  wsprintf((char*)textbuf,"%d",codepage);
  SendDlgItemMessage(hwnd,IDC_LIST1,LB_ADDSTRING,(WPARAM)0,(LPARAM)textbuf);

  fontdata = (int)*((unsigned short*)(fadr+32));
  fadr += fontdata + 34;
 }
 curcodepage = 0;
}


void View3Font(HWND hDlg)
{
 int i,j,k,num = 0;
 unsigned char *adrfont,*baseadr,*fadr;
 int xfont,yfont,fonts,lenfont,zi,zj,codepage,entr,fontdata;
 int ypos;

 SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETTEXT,(WPARAM)SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0),(LPARAM)textbuf);
 if (curcodepage == atoi((char*)textbuf)) return;
 curcodepage = atoi((char*)textbuf);

 memset(bigfont,0,512*256/8);
 fadr = cpifile + 25;
 entr = (int)*((unsigned short*)(cpifile+23));
 for (zj = 0;zj<entr;zj++)
 {
  baseadr = fadr + 34;
  fonts = (int)*((unsigned short*)(fadr+30));
  codepage = (int)*((unsigned short*)(fadr+16));
  fontdata = (int)*((unsigned short*)(fadr+32));
  if (codepage == curcodepage)
  {
   for (zi=0;zi<fonts;zi++)
   {
    adrfont = baseadr + 6;
    yfont = baseadr[0];
    xfont = baseadr[1];
    lenfont = yfont*256;
    num = 0;
    if (yfont == 16 && xfont == 8) ypos = 511;
     else
    if (yfont == 14 && xfont == 8) ypos = 370;
     else 
    if (yfont == 8 && xfont == 8) ypos = 240;
     else continue;
    for (j=ypos;j>ypos-8*yfont;j-=yfont)
    {
     for (i=0;i<32;i++)
     { 
      for (k=0;k<yfont;k++)
      {
       bigfont[(j-k)*32+i] = adrfont[num*yfont+k];
      }
      num++;
     }
    }
    baseadr += lenfont + 6;
    ypos = ypos - 8*yfont - 8;
   }
  }
  fadr += fontdata + 34;
 }
}
 
void GetChFont(HWND hDlg)
{
 unsigned char *adrfont,*baseadr,*fadr;
 int xfont,yfont,fonts,lenfont,i,j,codepage,entr,fontdata;

 fadr = cpifile + 25;
 entr = (int)*((unsigned short*)(cpifile+23));
 for (j = 0;j<entr;j++)
 {
  baseadr = fadr + 34;
  fonts = (int)*((unsigned short*)(fadr+30));
  codepage = (int)*((unsigned short*)(fadr+16));
  fontdata = (int)*((unsigned short*)(fadr+32));
  if (codepage == curcodepage)
  {
   for (i=0;i<fonts;i++)
   {
    adrfont = baseadr + 6;
    yfont = baseadr[0];
    xfont = baseadr[1];
    lenfont = yfont*256;
    if (yfont == 16 && xfont == 8 && SendDlgItemMessage(hDlg,IDC_CHECK8X16,BM_GETCHECK,0,0) == BST_CHECKED)
    {
     if (biosparam.font8x16) memcpy(biosparam.font8x16,adrfont,256*16);
    }
    if (yfont == 14 && xfont == 8 && SendDlgItemMessage(hDlg,IDC_CHECK8X14,BM_GETCHECK,0,0) == BST_CHECKED)
    {
     if (biosparam.font8x14) memcpy(biosparam.font8x14,adrfont,256*14);
    }
    if (yfont == 8 && xfont == 8 && SendDlgItemMessage(hDlg,IDC_CHECK8X8,BM_GETCHECK,0,0) == BST_CHECKED)
    {
     if (biosparam.font8x8) memcpy(biosparam.font8x8,adrfont,256*8);
    }
    baseadr += lenfont + 6;
   }
  }
  fadr += fontdata + 34;
 }
}

LRESULT CALLBACK pWndProc16(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 int i;
 switch (message)
 {
  case WM_INITDIALOG:
       // установка шрифта
       SendDlgItemMessage(hDlg,IDC_LIST1,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0);
	   for (i = 0;i<sizeof(vmodet)/sizeof(VMODEPARAM);i++)
        SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)&vmodet[i].modetext);
       SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,0,0);
	   break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
		case IDC_LIST1:
			 if (loadingbios == true && biosparam.vmodeinfo != 0) ViewVideoMode(hDlg);
			 break;
	   }
	   break;
 }
 return FALSE;
}

void ViewVideoMode(HWND hDlg)
{
 int num = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0);

 unsigned char *vmode = biosparam.vmodeinfo + 64*vmodet[num].vnum;
 unsigned char *evmode = biosparam.extvmodeinfo + 5*vmodet[num].extvnum;

 SetDlgItemInt(hDlg,IDC_COLUMN,(unsigned int)(vmode[0]),0);
 SetDlgItemInt(hDlg,IDC_ROWS,(unsigned int)(vmode[1]),0);
 SetDlgItemInt(hDlg,IDC_CHARHEIGHT,(unsigned int)(vmode[2]),0);
 wsprintf((char*)textbuf,"%04X",(unsigned int)((unsigned short*)(vmode+3))[0]);
 SetDlgItemText(hDlg,IDC_REGENLENGTH,(char*)textbuf);

 wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[5]));
 SetDlgItemText(hDlg,IDC_SEQ1,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[6]));
 SetDlgItemText(hDlg,IDC_SEQ2,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[7]));
 SetDlgItemText(hDlg,IDC_SEQ3,(char*)textbuf);
 wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[8]));
 SetDlgItemText(hDlg,IDC_SEQ4,(char*)textbuf);

 wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[9]));
 SetDlgItemText(hDlg,IDC_MISCOUTPUT,(char*)textbuf);

 for (int i = 0;i<25;i++)
 {
  wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[10+i]));
  SetDlgItemText(hDlg,IDC_CRTC1+i,(char*)textbuf);
 }

 for (i = 0;i<20;i++)
 {
  wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[35+i]));
  SetDlgItemText(hDlg,IDC_AC1+i,(char*)textbuf);
 }

 for (i = 0;i<9;i++)
 {
  wsprintf((char*)textbuf,"%02X",(unsigned int)(vmode[55+i]));
  SetDlgItemText(hDlg,IDC_GDC1+i,(char*)textbuf);
 }


 if (evmode[0] & BIN8(00000001)) SendDlgItemMessage(hDlg,IDC_NATIVEMODE,BM_SETCHECK,1,0);
  else SendDlgItemMessage(hDlg,IDC_NATIVEMODE,BM_SETCHECK,0,0);

 if (evmode[0] & BIN8(00000010)) SendDlgItemMessage(hDlg,IDC_INTERLACE,BM_SETCHECK,1,0);
  else SendDlgItemMessage(hDlg,IDC_INTERLACE,BM_SETCHECK,0,0);

 if (evmode[0] & BIN8(00000100)) SendDlgItemMessage(hDlg,IDC_NATIVEMODEDS,BM_SETCHECK,1,0);
  else SendDlgItemMessage(hDlg,IDC_NATIVEMODEDS,BM_SETCHECK,0,0);

 wsprintf((char*)textbuf,"%02X",(unsigned int)((evmode[0] & BIN8(00111000)) >> 3));
 SetDlgItemText(hDlg,IDC_DPF,(char*)textbuf);

 wsprintf((char*)textbuf,"%02X",(unsigned int)(evmode[1]));
 SetDlgItemText(hDlg,IDC_CRTC1B,(char*)textbuf);

 wsprintf((char*)textbuf,"%02X",(unsigned int)(evmode[2]));
 SetDlgItemText(hDlg,IDC_INDPARAM,(char*)textbuf);

 wsprintf((char*)textbuf,"%04X",(unsigned int)((unsigned short*)(evmode+3))[0]);
 SetDlgItemText(hDlg,IDC_CLOCK,(char*)textbuf);
}

bool LoadCMPBios(HWND hDlg)
{
 int hFile,lenfile,readlen;
 OPENFILENAME ofn;
 static char szFilter[] = "BIOS file (*.rom;*.bin)\0*.rom;*.bin\0All files (*.*)\0*.*\0\0";
 static char szFileName[_MAX_PATH];
 char szTitleName[_MAX_FNAME + _MAX_EXT] ;

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME) ;
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName ;
 ofn.nMaxFile          = _MAX_PATH ;
 ofn.lpstrFileTitle    = szTitleName ;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT ;
 ofn.Flags             = OFN_HIDEREADONLY ;
 ofn.lpstrTitle        = "Load BIOS";
 if( !GetOpenFileName(&ofn)) return false;

 // Проверка на наличие файла
 hFile = _lopen(szFileName, OF_READ);
 if (hFile == -1) return false;
 // Определение длины файла
 lenfile = _llseek(hFile, 0, 2);
 _llseek(hFile, 0, 0);
 if (lenfile > 256*256)
 {
  _lclose(hFile);
  return false;
 }
 memset(cmpbios,0,256*256);
 
 // проверка на сигнатуру биоса
 readlen = _lread(hFile,textbuf,2);
 if (textbuf[0] != 0x55 && textbuf[1] != 0xaa)
 {
  _lclose(hFile);
  return false;
 }
 _llseek(hFile, 0, 0);

 // Чтение файла
 readlen = _lread(hFile,cmpbios,lenfile);
 if (readlen == HFILE_ERROR || readlen != lenfile)
 {
  _lclose(hFile);
  return false;
 }
 // Закрытие файла
 _lclose(hFile);
 lencmpbios = readlen;

 SetDlgItemText(hDlg,IDC_FILE2,(char*)szTitleName);

 return true;
}

bool AnalyzeCMPBios(void)
{
 int i,lenbios = lencmpbios;
 unsigned int reg,reg1,reg2;
 unsigned char *vctext,*vcr1,*vcr2,*bios = cmpbios;

 // поиск регистров
 // pciinit0
 for(i=0;i<lenbios-30;i++)
 {
  // mov dx,cx
  if (bios[i+0]  == 0x8b && bios[i+1] == 0xd1 &&
  // add dx,4
	  bios[i+2]  == 0x83 && bios[i+3] == 0xc2 && bios[i+4] == 0x04 && 
  // mov eax,cs: ... (pciinit0)
	  bios[i+5]  == 0x66 && bios[i+6] == 0x2e && bios[i+7] == 0xa1 && 
  // or eax,edi
      bios[i+10] == 0x66 && bios[i+11] == 0x0b && bios[i+12] == 0xc7 && 
  // out dx,eax
      bios[i+13] == 0x66 && bios[i+14] == 0xef)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 8));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   goto l5;
  }
 }
 goto l6;
l5:;
 biosparam.cmppciinit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.cmppciinit0);
 SetDlgItemText(hpw[3],IDC_CMPPCIINIT0,(char*)textbuf);
l6:;
 // draminit0,miscinit0,sgrammode
 for(i=0;i<lenbios-34;i++)
 {
  // in eax,dx
  if (bios[i+0]  == 0x66 && bios[i+1] == 0xed &&
  // and eax,fc000000h
	  bios[i+2]  == 0x66 && bios[i+3] == 0x25 && bios[i+4] == 0x00 && bios[i+5] == 0x00 && bios[i+6] == 0x00 && 
  // or eax,cs: ... (draminit0)
	  bios[i+8]  == 0x66 && bios[i+9] == 0x2e && bios[i+10] == 0x0b && bios[i+11]  == 0x06 &&
  // out dx,eax
      bios[i+14] == 0x66 && bios[i+15] == 0xef &&
  // lea dx,[si+10h]
      bios[i+16] == 0x8d && bios[i+17] == 0x54 && bios[i+18] == 0x10 &&
  // mov eax,cs: ... (miscinit0)
	  bios[i+19]  == 0x66 && bios[i+20] == 0x2e && bios[i+21] == 0xa1 &&
  // out dx,eax
      bios[i+24] == 0x66 && bios[i+25] == 0xef &&
  // lea dx,[si+34h]
      bios[i+26] == 0x8d && bios[i+27] == 0x54 && bios[i+28] == 0x34 &&
  // mov eax,cs: ... (sgrammode)
	  bios[i+29]  == 0x66 && bios[i+30] == 0x2e && bios[i+31] == 0xa1)
  {
   // draminit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 12));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // miscinit0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 22));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 32));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);
   goto l8;
  }
 }
 goto l7;
l8:;
 // draminit0
 biosparam.cmpdraminit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpdraminit0);
 SetDlgItemText(hpw[3],IDC_CMPDRAMINIT0,(char*)textbuf);
 // miscinit0
 biosparam.cmpmiscinit0 = reg1;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpmiscinit0);
 SetDlgItemText(hpw[3],IDC_CMPMISCINIT0,(char*)textbuf);
 // sgrammode
 biosparam.cmpsgrammode = reg2;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpsgrammode);
 SetDlgItemText(hpw[3],IDC_CMPSGRAMMODE,(char*)textbuf);
l7:;
 // miscinit1,agpinit0,pllctrl0
 for(i=0;i<lenbios-30;i++)
 {
  // lea dx,[si+14h]
  if (bios[i+0]  == 0x8d && bios[i+1] == 0x54 && bios[i+2] == 0x14 &&
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,1ff40000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0xf4 && bios[i+10] == 0x1f && 
  // or eax,cs: ... (miscinit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14]  == 0x06 &&
  // call ...
      bios[i+17]  == 0xe8 &&
  // jz ...
      bios[i+20]  == 0x74 &&
  // or eax,8000h
      bios[i+22]  == 0x66 && bios[i+23] == 0x0d && bios[i+24]  == 0x00 && bios[i+25] == 0x80 && bios[i+26] == 0x00 && bios[i+27] == 0x00 &&
  // out eax,dx
      bios[i+28] == 0x66 && bios[i+29] == 0xef &&
  // lea dx,[si+20h]
      bios[i+30] == 0x8d && bios[i+31] == 0x54 && bios[i+32] == 0x20 &&
  // mov eax,cs: ... (agpinit0)
	  bios[i+33]  == 0x66 && bios[i+34] == 0x2e && bios[i+35] == 0xa1 &&
  // out dx,eax
      bios[i+38] == 0x66 && bios[i+39] == 0xef &&
  // lea dx,[si+44h]
      bios[i+40] == 0x8d && bios[i+41] == 0x54 && bios[i+42] == 0x44 &&
  // mov eax,cs: ... (pllctrl0)
	  bios[i+43]  == 0x66 && bios[i+44] == 0x2e && bios[i+45] == 0xa1)
  {
   // agpinit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 36));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // pllctrl0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 46));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 15));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);

   goto l11;
  }
 }

 // miscinit1,agpinit0,pllctrl0 (v3)
 for(i=0;i<lenbios-40;i++)
 {
  // lea dx,[si+14h]
  if (bios[i+0]  == 0x8d && bios[i+1] == 0x54 && bios[i+2] == 0x14 &&
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,1ff40000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0xf4 && bios[i+10] == 0x1f && 
  // or eax,cs: ... (miscinit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14]  == 0x06 &&
  // out eax,dx
      bios[i+17] == 0x66 && bios[i+18] == 0xef &&
  // lea dx,[si+20h]
      bios[i+19] == 0x8d && bios[i+20] == 0x54 && bios[i+21] == 0x20 &&
  // mov eax,cs: ... (agpinit0)
	  bios[i+22]  == 0x66 && bios[i+23] == 0x2e && bios[i+24] == 0xa1 &&
  // out dx,eax
      bios[i+27] == 0x66 && bios[i+28] == 0xef &&
  // lea dx,[si+44h]
      bios[i+29] == 0x8d && bios[i+30] == 0x54 && bios[i+31] == 0x44 &&
  // mov eax,cs: ... (pllctrl0)
	  bios[i+32]  == 0x66 && bios[i+33] == 0x2e && bios[i+34] == 0xa1 &&
  // out dx,eax
      bios[i+37] == 0x66 && bios[i+38] == 0xef)
  {
   // agpinit0
   vctext = bios + (int)*((unsigned short*)(bios + i + 25));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   // pllctrl0
   vcr1 = bios + (int)*((unsigned short*)(bios + i + 35));
   reg1 = (unsigned int)(((unsigned int*)vcr1)[0]);

   vcr2 = bios + (int)*((unsigned short*)(bios + i + 15));
   reg2 = (unsigned int)(((unsigned int*)vcr2)[0]);

   goto l11;
  }
 }
 SetDlgItemText(hpw[3],IDC_CMPSPEED," ");
 goto l12;
l11:;
 // agpinit0
 biosparam.cmpagpinit0 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpagpinit0);
 SetDlgItemText(hpw[3],IDC_CMPAGPINIT0,(char*)textbuf);
 // pllctrl0
 biosparam.cmppllctrl0 = reg1;
 wsprintf((char*)textbuf,"%08X",biosparam.cmppllctrl0);
 SetDlgItemText(hpw[3],IDC_CMPPLLCTRL0,(char*)textbuf);

 k = biosparam.cmppllctrl0 & BIN8(00000011);
 m = (biosparam.cmppllctrl0 & BIN8(11111100)) >> 2;
 n = (biosparam.cmppllctrl0 & 0xff00) >> 8;
 mgz = 14.31818 * (n + 2) / ((m + 2) * pow(2,k));
 sprintf((char*)textbuf,"%g MHz",mgz,k,m,n);
 SetDlgItemText(hpw[3],IDC_CMPSPEED,(char*)textbuf);

 // miscinit1
 biosparam.cmpmiscinit1 = reg2;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpmiscinit1);
 SetDlgItemText(hpw[3],IDC_CMPMISCINIT1,(char*)textbuf);

 // pllctrl1
 // lea dx,[si+48h]
 if (bios[i+39] == 0x8d && bios[i+40] == 0x54 && bios[i+41] == 0x48 &&
 // mov eax,cs: ... (pllctrl1)
     bios[i+42]  == 0x66 && bios[i+43] == 0x2e && bios[i+44] == 0xa1 &&
 // out dx,eax
     bios[i+47] == 0x66 && bios[i+48] == 0xef)
 {
  vctext = bios + (int)*((unsigned short*)(bios + i + 45));
  reg = (unsigned int)(((unsigned int*)vctext)[0]);
  biosparam.cmppllctrl1 = reg;
 }
 else
 {
  biosparam.cmppllctrl1 = 0;
 }
 wsprintf((char*)textbuf,"%08X",biosparam.cmppllctrl1);
 SetDlgItemText(hpw[3],IDC_CMPPLLCTRL1,(char*)textbuf);

l12:;

 // draminit1
 for(i=0;i<lenbios-30;i++)
 {
  // add dx,1ch
  if (bios[i+0]  == 0x83 && bios[i+1] == 0xc2 && bios[i+2] == 0x1c && 
  // in eax,dx
      bios[i+3]  == 0x66 && bios[i+4] == 0xed &&
  // and eax,c2000000h
	  bios[i+5]  == 0x66 && bios[i+6] == 0x25 && bios[i+7] == 0x00 && bios[i+8] == 0x00 && bios[i+9] == 0x00 && bios[i+10] == 0xc2 && 
  // or eax,cs: ... (draminit1)
	  bios[i+11] == 0x66 && bios[i+12] == 0x2e && bios[i+13] == 0x0b && bios[i+14] == 0x06)
  {
   vctext = bios + (int)*((unsigned short*)(bios + i + 15));
   reg = (unsigned int)(((unsigned int*)vctext)[0]);
   goto l13;
  }
 }
 goto l14;
l13:;
 // draminit1
 biosparam.cmpdraminit1 = reg;
 wsprintf((char*)textbuf,"%08X",biosparam.cmpdraminit1);
 SetDlgItemText(hpw[3],IDC_CMPDRAMINIT1,(char*)textbuf);
l14:;
 return true;
}

void CMPreg(HWND hDlg)
{
 if (loadingcmpbios == false) return;
 if (biosparam.pciinit0 == biosparam.cmppciinit0) SetDlgItemText(hDlg,IDC_MMPCIINIT0,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMPCIINIT0,tx_diff);
 if (biosparam.miscinit0 == biosparam.cmpmiscinit0) SetDlgItemText(hDlg,IDC_MMMISCINIT0,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMMISCINIT0,tx_diff);
 if (biosparam.miscinit1 == biosparam.cmpmiscinit1) SetDlgItemText(hDlg,IDC_MMMISCINIT1,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMMISCINIT1,tx_diff);
 if (biosparam.draminit0 == biosparam.cmpdraminit0) SetDlgItemText(hDlg,IDC_MMDRAMINIT0,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMDRAMINIT0,tx_diff);
 if (biosparam.draminit1 == biosparam.cmpdraminit1) SetDlgItemText(hDlg,IDC_MMDRAMINIT1,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMDRAMINIT1,tx_diff);
 if (biosparam.agpinit0 == biosparam.cmpagpinit0) SetDlgItemText(hDlg,IDC_MMAGPINIT0,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMAGPINIT0,tx_diff);
 if (biosparam.pllctrl0 == biosparam.cmppllctrl0) SetDlgItemText(hDlg,IDC_MMPLLCTRL0,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMPLLCTRL0,tx_diff);
 if (biosparam.pllctrl1 == biosparam.cmppllctrl1) SetDlgItemText(hDlg,IDC_MMPLLCTRL1,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMPLLCTRL1,tx_diff);
 if (biosparam.sgrammode == biosparam.cmpsgrammode) SetDlgItemText(hDlg,IDC_MMSGRAMMODE,tx_equal);
  else SetDlgItemText(hDlg,IDC_MMSGRAMMODE,tx_diff);
}

int LoadBMPLogo(void)
{
 int hFile,lenfile,readlen;
 OPENFILENAME ofn;
 static char szFilter[] = "16-colors uncompressed BMP files (*.bmp)\0*.bmp\0\0";
 static char szFileName[_MAX_PATH];
 char szTitleName[_MAX_FNAME + _MAX_EXT] ;

 memset(&ofn,0,sizeof(OPENFILENAME));

 ofn.lStructSize       = sizeof (OPENFILENAME) ;
 ofn.hwndOwner         = hmWnd;
 ofn.lpstrFilter       = szFilter;
 ofn.lpstrFile         = szFileName ;
 ofn.nMaxFile          = _MAX_PATH ;
 ofn.lpstrFileTitle    = szTitleName ;
 ofn.nMaxFileTitle     = _MAX_FNAME + _MAX_EXT ;
 ofn.Flags             = OFN_HIDEREADONLY ;
 ofn.lpstrTitle        = "Load BMP";
 if( !GetOpenFileName(&ofn)) return 2;

 // Проверка на наличие файла
 hFile = _lopen(szFileName, OF_READ);
 if (hFile == -1) return 1;
 // Определение длины файла
 lenfile = _llseek(hFile, 0, 2);
 _llseek(hFile, 0, 0);

 if (bitmap != 0) free(bitmap);
 bitmap = (char*)malloc(lenfile);
 // Чтение файла
 readlen = _lread(hFile,bitmap,lenfile);
 if (readlen == HFILE_ERROR || readlen != lenfile)
 {
  _lclose(hFile);
  return 1;
 }
 // Закрытие файла
 _lclose(hFile);

 if (bitmap[0] != 'B' && bitmap[0] != 'M') return 1;
 BITMAPINFOHEADER *bmif;
 BITMAPFILEHEADER *bmfh = (BITMAPFILEHEADER*)bitmap;
 bmif = (BITMAPINFOHEADER*)(bitmap + sizeof(BITMAPFILEHEADER));
 if (bmif->biBitCount != 4) return 1;

 SetDlgItemText(hpw[7],IDC_NAMEBMP,szTitleName);
 SetDlgItemInt(hpw[7],IDC_WIDTH,bmif->biWidth,0);
 SetDlgItemInt(hpw[7],IDC_HEIGHT,bmif->biHeight,0);

 xbmp = bmif->biWidth;
 ybmp = bmif->biHeight;
 bmpoffset = bitmap + bmfh->bfOffBits;
 bmilogo = (BITMAPINFO*)bmif;

 return 0;
}


LRESULT CALLBACK pWndProc17(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 PAINTSTRUCT ps;
 char *mm,*upr,*dn;
 int i;
 switch (message)
 {
  case WM_INITDIALOG:
//
	   SendDlgItemMessage(hDlg,IDC_STRING1,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_STRING2,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_STRING3,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_STRING4,WM_SETFONT,(WPARAM)hFont,0);
	   SendDlgItemMessage(hDlg,IDC_STRING5,WM_SETFONT,(WPARAM)hFont,0);
	   break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
		case IDC_LOADIMAGE:
			 if (loadingbios == true)
			 {
			  int ml = LoadBMPLogo();
              if (ml > 0)
			  {
			   if (ml == 1)
                MessageBox(hDlg,"Bitmap loading error!!!","ERROR",MB_ICONHAND | MB_OK);
			   break;
			  }

              hLogo = CreateDIBSection(hLogoDC,bmilogo,DIB_RGB_COLORS,(void**)&bitmapi,NULL,NULL);
			  if (hLogo == 0)
			  {
               MessageBox(hDlg,"Bitmap format error!!!","ERROR",MB_ICONHAND | MB_OK);
			   break;
			  }
			  memcpy(bitmapi,bmpoffset,xbmp*ybmp/2);
			  EnableWindow(GetDlgItem(hDlg,IDC_APPLY),TRUE);
			  // поворот изображения
              mm = (char*)malloc(xbmp/2);
			  upr = bmpoffset;
			  dn = bmpoffset+(ybmp-1)*xbmp/2;
              for (i = 0;i<ybmp/2;i++)
			  {
               memcpy(mm,upr,xbmp/2);
               memcpy(upr,dn,xbmp/2);
               memcpy(dn,mm,xbmp/2); 
               upr+=xbmp/2;
               dn-=xbmp/2;
			  }
			 }
			 break;
        case IDC_APPLY:
             if (loadingbios == true)
			 {
			  SetLogoToBios(hDlg);
			 }
             break;
	   }
	   break;
  case WM_PAINT:
	   if (hLogo != 0)
	   {
        BeginPaint(hDlg, &ps);
        DrawBitmap(hLogoDC,16,112,hLogo);
        EndPaint(hDlg, &ps);
	   }
       break;
 }
 return FALSE;
}

void SetLogoToBios(HWND hDlg)
{
 // нахождение свободного места под картинку
 int qwlen = xbmp*ybmp/2+512,i,j,codelen,cclen;
 unsigned char *fmem,*cfmem,*txb;

 if (((unsigned short*)(biosparam.pcir + 0x04))[0] != 0x121a)
 {
  MessageBox(hDlg,"Out of memory","ERROR",MB_ICONHAND | MB_OK);
  return;
 }

 if (bios[2] == 0x50) cclen = 40*1024;
  else cclen = lenbios;
 for (i=0;i<cclen-qwlen;i++)
 {
  if (bios[i] == 0xff)
  {
   for (j=0;j<qwlen;j++)
   {
    if (bios[i+j] == 0xff) continue;
	break;
   }
   if (j >= qwlen) goto l1;
  }
 }
 MessageBox(hDlg,"Out of memory","ERROR",MB_ICONHAND | MB_OK);
 return;
l1:;
 fmem = bios + i;
 codelen = sizeof(proc_viewlogo1) + sizeof(proc_viewlogo2) +
	       sizeof(proc_viewlogo3) + sizeof(proc_viewlogo4) + 
		 5*sizeof(proc_viewlogo5) + sizeof(proc_viewlogo6);
 // забивание nop'ами
 memset(biosparam.lpPatchLogoCode,0x90,27);
 
 // формирование call ... 
 biosparam.lpPatchLogoCode[0] = 0xe8;
 //((short*)(biosparam.lpPatchLogoCode + 1))[0] = fmem-bios;
 ((short*)(biosparam.lpPatchLogoCode + 1))[0] = fmem-biosparam.lpPatchLogoCode-3;
 // копироувание картинки в биос
 memcpy(fmem+codelen,bmpoffset,xbmp*ybmp/2);
 txb = fmem+codelen + xbmp*ybmp/2;
 // создание процедуры вывода изображения
 memcpy(fmem,proc_viewlogo1,sizeof(proc_viewlogo1));
 cfmem = fmem + sizeof(proc_viewlogo1);

 memcpy(cfmem,proc_viewlogo2,sizeof(proc_viewlogo2));
 ((short*)(cfmem + 1))[0] = fmem+codelen-bios;
 cfmem += sizeof(proc_viewlogo2);
 
 memcpy(cfmem,proc_viewlogo3,sizeof(proc_viewlogo3));
 cfmem[2] = (unsigned char)(xbmp);
 cfmem += sizeof(proc_viewlogo3);

 memcpy(cfmem,proc_viewlogo4,sizeof(proc_viewlogo4));
 cfmem[2] = (unsigned char)(ybmp);
 cfmem += sizeof(proc_viewlogo4);
 // вывод текстовых строк

 GetDlgItemText(hDlg,IDC_STRING1,(char*)txb,256);
 memcpy(cfmem,proc_viewlogo5,sizeof(proc_viewlogo5));
 ((short*)(cfmem + 7))[0] = lstrlen((char*)txb);
 cfmem[10] = (xbmp/8)+1;
 cfmem[11] = 0;
 ((short*)(cfmem + 13))[0] = txb-bios;
 cfmem += sizeof(proc_viewlogo5);
 txb += lstrlen((char*)txb);

 GetDlgItemText(hDlg,IDC_STRING2,(char*)txb,256);
 memcpy(cfmem,proc_viewlogo5,sizeof(proc_viewlogo5));
 ((short*)(cfmem + 7))[0] = lstrlen((char*)txb);
 cfmem[10] = (xbmp/8)+1;
 cfmem[11] = 1;
 ((short*)(cfmem + 13))[0] = txb-bios;
 cfmem += sizeof(proc_viewlogo5);
 txb += lstrlen((char*)txb);
 
 GetDlgItemText(hDlg,IDC_STRING3,(char*)txb,256);
 memcpy(cfmem,proc_viewlogo5,sizeof(proc_viewlogo5));
 ((short*)(cfmem + 7))[0] = lstrlen((char*)txb);
 cfmem[10] = (xbmp/8)+1;
 cfmem[11] = 2;
 ((short*)(cfmem + 13))[0] = txb-bios;
 cfmem += sizeof(proc_viewlogo5);
 txb += lstrlen((char*)txb);

 GetDlgItemText(hDlg,IDC_STRING4,(char*)txb,256);
 memcpy(cfmem,proc_viewlogo5,sizeof(proc_viewlogo5));
 ((short*)(cfmem + 7))[0] = lstrlen((char*)txb);
 cfmem[10] = (xbmp/8)+1;
 cfmem[11] = 3;
 ((short*)(cfmem + 13))[0] = txb-bios;
 cfmem += sizeof(proc_viewlogo5);
 txb += lstrlen((char*)txb);

 GetDlgItemText(hDlg,IDC_STRING5,(char*)txb,256);
 memcpy(cfmem,proc_viewlogo5,sizeof(proc_viewlogo5));
 ((short*)(cfmem + 7))[0] = lstrlen((char*)txb);
 cfmem[10] = (xbmp/8)+1;
 cfmem[11] = 4;
 ((short*)(cfmem + 13))[0] = txb-bios;
 cfmem += sizeof(proc_viewlogo5);
 txb += lstrlen((char*)txb);

 memcpy(cfmem,proc_viewlogo6,sizeof(proc_viewlogo6));
}


HANDLE hThread;
DWORD dwThreadId;

DWORD WINAPI TProc(LPVOID);
HWND hh;


void DrawDump(HWND hwnd)
{
 if (curcol == 0) return;
 hh = hwnd;
 hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)TProc,0,0,&dwThreadId);
}

DWORD WINAPI TProc(LPVOID lpar)
{
 for (int i = 0; i < curcol; i++)
 {
  cr.cpMin = rcol[i].start;
  cr.cpMax = rcol[i].end;
  SendDlgItemMessage(hh,IDC_RICHEDIT1,EM_EXSETSEL,0,(LPARAM)&cr);
  cf.cbSize = sizeof(cf);
  cf.dwMask = CFM_COLOR;
  cf.dwEffects = 0;
  cf.crTextColor = rcol[i].color;
  SendDlgItemMessage(hh,IDC_RICHEDIT1,EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf);
 }

 cr.cpMin = 0;
 cr.cpMax = 0;
 SendDlgItemMessage(hh,IDC_RICHEDIT1,EM_EXSETSEL,0,(LPARAM)&cr);

// SetDlgItemInt(hh,IDC_EDIT1,curcol,1);

 ExitThread(0); // завершаем поток
 return 0;
}


int AltFindFont(int fontmode)
{
 if (fontmode == 0)
 {
  for(int i=0;i<lenbios-30;i++)
  {
   if (bios[i+0]  == 0x00 && bios[i+1]  == 0x00 &&
	   bios[i+2]  == 0x00 && bios[i+3]  == 0x00 && 
	   bios[i+4]  == 0x00 && bios[i+5]  == 0x00 &&
	   bios[i+6]  == 0x00 && bios[i+7]  == 0x00 &&

       bios[i+8]  == 0x7e && bios[i+9]  == 0x81 && 
       bios[i+10] == 0xa5 && bios[i+11] == 0x81 && 
       bios[i+12] == 0xbd && bios[i+13] == 0x99 && 
       bios[i+14] == 0x81 && bios[i+15] == 0x7e)
   {
    biosparam.offsetf8x8 = i;
    biosparam.font8x8 = ((char*)bios + i);
    return 1;
   }
  }
 }
 else
 if (fontmode == 1)
 {
  for(int i=0;i<lenbios-30;i++)
  {
   if (bios[i+0]  == 0x00 && bios[i+1]  == 0x00 &&
	   bios[i+2]  == 0x00 && bios[i+3]  == 0x00 && 
	   bios[i+4]  == 0x00 && bios[i+5]  == 0x00 &&
	   bios[i+6]  == 0x00 && bios[i+7]  == 0x00 &&
	   bios[i+8]  == 0x00 && bios[i+9]  == 0x00 &&
	   bios[i+10] == 0x00 && bios[i+11] == 0x00 &&
	   bios[i+12] == 0x00 && bios[i+13] == 0x00 &&

	   bios[i+14] == 0x00 && bios[i+15] == 0x00 &&
       bios[i+16] == 0x7e && (bios[i+24] == 0x7e || bios[i+25] == 0x7e || bios[i+26] == 0x7e)
	   )
   {
    biosparam.offsetf8x14 = i;
    biosparam.font8x14 = ((char*)bios + i);
    return 1;
   }
  }
 }
 else
 if (fontmode == 2)
 {
  for(int i=0;i<lenbios-30;i++)
  {
   if (bios[i+0]  == 0x00 && bios[i+1]  == 0x00 &&
	   bios[i+2]  == 0x00 && bios[i+3]  == 0x00 && 
	   bios[i+4]  == 0x00 && bios[i+5]  == 0x00 &&
	   bios[i+6]  == 0x00 && bios[i+7]  == 0x00 &&
	   bios[i+8]  == 0x00 && bios[i+9]  == 0x00 &&
	   bios[i+10] == 0x00 && bios[i+11] == 0x00 &&
	   bios[i+12] == 0x00 && bios[i+13] == 0x00 &&

	   bios[i+14] == 0x00 && bios[i+15] == 0x00 &&
	   bios[i+16] == 0x00 && bios[i+17] == 0x00 &&
       bios[i+18] == 0x7e && (bios[i+27] == 0x7e || bios[i+28] == 0x7e)
	   )
   {
    biosparam.offsetf8x16 = i;
    biosparam.font8x16 = ((char*)bios + i);
    return 1;
   }
  }
 }


 return 0;
}
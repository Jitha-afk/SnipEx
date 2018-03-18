// SnipEx.h
// Author: Joseph Ryan Ries, 2017
// The snip.exe that comes bundled with Microsoft Windows is *almost* good enough. So I made one just a little better.

#pragma once

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

// You could refer to an individual button like gButtons[BUTTON_NEW - 10001], gButtons[BUTTON_DELAY - 10001], etc.

#define BUTTON_NEW     10001
#define BUTTON_DELAY   10002
#define BUTTON_SAVE    10003
#define BUTTON_COPY    10004
#define BUTTON_HILIGHT 10005
#define BUTTON_BOX     10006
#define BUTTON_ARROW   10007
#define BUTTON_REDACT  10008

#define SYSCMD_REPLACE 20001
#define SYSCMD_RESTORE 20002
#define SYSCMD_SHADOW  20003

#define DELAY_TIMER    30001


// This is like Microsoft's POINT struct, but smaller.
// It's just for efficiency's sake since I don't need LONGs for this.
// Until 64K monitors become common.
typedef struct SMALLPOINT
{
	UINT16 x;
	UINT16 y;
} SMALLPOINT;

typedef enum BUTTONSTATE
{
	BUTTONSTATE_NORMAL,
	BUTTONSTATE_PRESSED
} BUTTONSTATE;

typedef struct BUTTON
{
	RECT        Rectangle;      // left, top, right, bottom
	char*       Caption;
	HBITMAP     EnabledIcon;
	HBITMAP     DisabledIcon;
	int         EnabledIconId;
	int         DisabledIconId;
	BUTTONSTATE State;          // Is the button pressed or not
	UINT16      Hotkey;
	HWND        Handle;
	BOOL        Enabled;
	LONGLONG    Id;
	BOOL        SelectedTool;   // If the button is selected as a tool it should stay pressed
	int         CursorId;
	HCURSOR     Cursor;
} BUTTON;

typedef enum APPSTATE
{
	APPSTATE_BEFORECAPTURE,
	APPSTATE_DURINGCAPTURE,
	APPSTATE_DELAYCOOKING,
	APPSTATE_AFTERCAPTURE
} APPSTATE;

#pragma region DECLARATIONS

int CALLBACK WinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PreviousInstance, _In_ LPSTR CommandLine, _In_ int WindowShowCode);

LRESULT CALLBACK MainWindowCallback(_In_ HWND Window, _In_ UINT Message, _In_ WPARAM WParam, _In_ LPARAM LParam);

void DrawButton(_In_ DRAWITEMSTRUCT* DrawItemStruct, _In_ BUTTON Button);

LRESULT CALLBACK CaptureWindowCallback(_In_ HWND Window, _In_ UINT Message, _In_ WPARAM WParam, _In_ LPARAM LParam);

void CaptureWindow_OnLeftButtonUp(void);

// Returns TRUE if we were successful in creating the capture window. FALSE if it fails.
BOOL NewButton_Click(void);

// Returns TRUE if the snip was saved. Returns FALSE if there was an error or if user cancelled.
BOOL SaveButton_Click(void);

// Returns TRUE if the snip was copied to the clipboard. FALSE if it fails.
BOOL CopyButton_Click(void);

// Save a 32-bit bitmap to a file. Returns FALSE if it fails.
BOOL SaveBitmapToFile(_In_ wchar_t* FilePath);

// Save png image to a file. Returns FALSE if it fails.
BOOL SavePngToFile(_In_ wchar_t* FilePath);

void AddReplaceSnippingToolMenuItem(_In_ HINSTANCE Instance);

void AddDropShadowToolMenuItem(void);

BOOL IsAppRunningElevated(void);

// MessageBox enhanced with varargs.
int MyMessageBoxA(_In_opt_ HWND ParentWindow, _In_opt_ LPCTSTR Caption, _In_ UINT Type, _In_ LPCTSTR Text, _In_ ...);

// OutputDebugStringA enhanced with varargs. Only works in debug builds.
void MyOutputDebugStringA(_In_ char* Message, _In_ ...);

// OutputDebugStringW enhanced with varargs. Only works in debug builds.
void MyOutputDebugStringW(_In_ wchar_t* Message, _In_ ...);

BOOL AdjustForCustomScaling(void);

#pragma endregion
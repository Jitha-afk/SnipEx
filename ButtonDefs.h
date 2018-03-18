#pragma once
// ButtonDefs.h
// Author: Joseph Ryan Ries, 2017
// The snip.exe that comes bundled with Microsoft Windows is *almost* good enough. So I made one just a little better.
//
// Buttons!
// You could refer to an individual button like gButtons[BUTTON_NEW - 10001], gButtons[BUTTON_DELAY - 10001], etc.

BUTTON gNewButton = {
	{ 2,  0, 72,  52 }, // Rectangle left, top, right, bottom
	"New",              // Caption
	NULL,               // EnabledIcon
	NULL,               // DisabledIcon
	IDB_SCISSORS32x32E, // EnabledIconId
	0,                  // DisabledIconId
	BUTTONSTATE_NORMAL, // State
	0x4E,               // Hotkey (N)
	NULL,				// HWND Handle
	TRUE,               // Enabled
	BUTTON_NEW,         // Id
	FALSE,              // SelectedTool
	0,                  // CursorId
	NULL                // Cursor
};

BUTTON gDelayButton = {
	{ 74, 0, 144, 52 }, // Rectangle left, top, right, bottom
	"Delay",            // Caption
	NULL,               // EnabledIcon
	NULL,               // DisabledIcon
	IDB_DELAY32x32E,    // EnabledIconId
	0,                  // DisabledIconId
	BUTTONSTATE_NORMAL, // State
	0x44,               // Hotkey (D)
	NULL,               // HWND Handle
	TRUE,               // Enabled
	BUTTON_DELAY,       // Id
	FALSE,              // SelectedTool
	0,                  // CursorId
	NULL                // HCURSOR
};

BUTTON gSaveButton = {
	{ 146, 0, 216, 52 },
	"Save",
	NULL,
	NULL,
	IDB_SAVE32x32E,
	IDB_SAVE32x32D,
	BUTTONSTATE_NORMAL,
	0x53,
	NULL,
	FALSE,				// Initially disabled
	BUTTON_SAVE,
	FALSE,
	0,
	NULL
};

BUTTON gCopyButton = {
	{ 218, 0, 288, 52 },
	"Copy",
	NULL,
	NULL,
	IDB_COPY32x32E,
	IDB_COPY32x32D,
	BUTTONSTATE_NORMAL,
	0x43,
	NULL,
	FALSE,
	BUTTON_COPY,
	FALSE,
	0,
	NULL
};

BUTTON gHilighterButton = {
	{ 290, 0, 360, 52 },
	"Hilight",
	NULL,
	NULL,
	IDB_HILIGHT32x32E,
	IDB_HILIGHT32x32D,
	BUTTONSTATE_NORMAL,
	0x48,
	NULL,
	FALSE,
	BUTTON_HILIGHT,
	FALSE,
	IDC_HILIGHTCURSOR,
	NULL
};

BUTTON gRectangleButton = {
	{ 362, 0, 432, 52 },	// Rectangle left, top, right, bottom
	"Box",					// Caption
	NULL,					// EnalbedIcon
	NULL,					// DisabledIcon
	IDB_BOX32x32E,			// EnabledIconId
	IDB_BOX32x32D,			// DisabledIconId
	BUTTONSTATE_NORMAL,		// State
	0x42,					// Hotkey (B)
	NULL,					// HWND Handle
	FALSE,					// Enabled
	BUTTON_BOX,				// Id
	FALSE,					// SelectedTool
	IDC_REDCROSSHAIR,		// CursorId
	NULL					// HCURSOR
};

BUTTON gArrowButton = {
	{ 434, 0, 504, 52 },	// Rectangle left, top, right, bottom
	"Arrow",			    // Caption
	NULL,					// EnalbedIcon
	NULL,					// DisabledIcon
	IDB_ARROW32x32E,		// EnabledIconId
	IDB_ARROW32x32D,		// DisabledIconId
	BUTTONSTATE_NORMAL,		// State
	0x41,					// Hotkey (A)
	NULL,					// HWND Handle
	FALSE,					// Enabled
	BUTTON_ARROW,			// Id
	FALSE,					// SelectedTool
	IDC_REDCROSSHAIR,		// CursorId
	NULL					// HCURSOR
};

BUTTON gRedactButton = {
	{ 506, 0, 576, 52 },
	"Redact",
	NULL,
	NULL,
	IDB_REDACT32x32E,
	IDB_REDACT32x32D,
	BUTTONSTATE_NORMAL,
	0x52,
	NULL,
	FALSE,
	BUTTON_REDACT,
	FALSE,
	IDC_REDACTCURSOR,
	NULL
};

BUTTON* gButtons[] = { &gNewButton, &gDelayButton, &gSaveButton, &gCopyButton, &gHilighterButton, &gRectangleButton, &gArrowButton, &gRedactButton };

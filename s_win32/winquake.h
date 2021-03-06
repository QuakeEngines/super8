/*  Copyright (C) 1996-1997 Id Software, Inc.
    Copyright (C) 1999-2012 other authors as noted in code comments

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.   */
// winquake.h: Win32-specific Quake header file

#include <windows.h>
//qb: already defined in windows.h  #define WM_MOUSEWHEEL                   0x020A

#ifndef SERVERONLY
#include <ddraw.h>
#include <dsound.h>
#ifndef GLQUAKE
//#include <mgraph.h> qb: gone! mh vid_win.c
#endif
#endif

extern	HINSTANCE	global_hInstance;
extern	int			global_nCmdShow;

#ifndef SERVERONLY

extern LPDIRECTDRAW		lpDD;
//extern qboolean			DDActive;
extern LPDIRECTDRAWSURFACE	lpPrimary;
extern LPDIRECTDRAWSURFACE	lpFrontBuffer;
extern LPDIRECTDRAWSURFACE	lpBackBuffer;
extern LPDIRECTDRAWPALETTE	lpDDPal;
extern LPDIRECTSOUND pDS;
extern LPDIRECTSOUNDBUFFER pDSBuf;

extern DWORD gSndBufSize;
//#define SNDBUFSIZE 65536

void	VID_LockBuffer (void);
void	VID_UnlockBuffer (void);

#endif

typedef enum {MS_WINDOWED, MS_FULLSCREEN, MS_FULLDIB, MS_UNINIT} modestate_t;

typedef struct
{
    modestate_t type;
    int                 width;
    int                 height;
    int                 modenum;
    int                 fullscreen;
    char                modedesc[20];
    qboolean            stretched;
} vmode_t;

#define MAX_MODE_LIST   200 //qb: 40 will fit on menu, I think
extern modestate_t	modestate;
extern vmode_t  modelist[MAX_MODE_LIST];
extern int nummodes;
extern int vid_modenum;

extern HWND			mainwindow;
extern int		ActiveApp, Minimized;

extern int	WinNT;

void IN_ShowMouse (void);
void IN_DeactivateMouse (void);
void IN_HideMouse (void);
void IN_ActivateMouse (void);
void IN_RestoreOriginalMouseState (void);
void IN_SetQuakeMouseState (void);
void IN_MouseEvent (int mstate);

extern qboolean	winsock_lib_initialized;

//extern cvar_t		_windowed_mouse; // Manoel Kasimier - removed

extern int		window_center_x, window_center_y;
extern RECT		window_rect;

extern qboolean	mouseinitialized;
extern HWND		hwnd_dialog;

extern HANDLE	hinput, houtput;

extern float    hack_ctr;

void IN_UpdateClipCursor (void);
void CenterWindow(HWND hWndCenter);

void S_BlockSound (void);
void S_UnblockSound (void);

void VID_SetDefaultMode (void);

extern int (PASCAL FAR *pWSAStartup)(WORD wVersionRequired, LPWSADATA lpWSAData);
extern int (PASCAL FAR *pWSACleanup)(void);
extern int (PASCAL FAR *pWSAGetLastError)(void);
extern SOCKET (PASCAL FAR *psocket)(int af, int type, int protocol);
extern int (PASCAL FAR *pioctlsocket)(SOCKET s, long cmd, u_long FAR *argp);
extern int (PASCAL FAR *psetsockopt)(SOCKET s, int level, int optname,
							  const char FAR * optval, int optlen);
extern int (PASCAL FAR *precvfrom)(SOCKET s, char FAR * buf, int len, int flags,
							struct sockaddr FAR *from, int FAR * fromlen);
extern int (PASCAL FAR *psendto)(SOCKET s, const char FAR * buf, int len, int flags,
						  const struct sockaddr FAR *to, int tolen);
extern int (PASCAL FAR *pclosesocket)(SOCKET s);
extern int (PASCAL FAR *pgethostname)(char FAR * name, int namelen);
extern struct hostent FAR * (PASCAL FAR *pgethostbyname)(const char FAR * name);
extern struct hostent FAR * (PASCAL FAR *pgethostbyaddr)(const char FAR * addr,
												  int len, int type);
extern int (PASCAL FAR *pgetsockname)(SOCKET s, struct sockaddr FAR *name,
							   int FAR * namelen);

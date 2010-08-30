// Naadh.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#define VERSION		2
#define VERMONTH	"Sep 2010"
#define MAXRESRV	16
#define MAXBOLS		12
#define MAXBOLVARS	10	//varieties of bols
#define MAXSTATUS	4	//0123
#define BOLS		{"Na", "Ta", "Ti", "Tin", "Tun", "Dha", "Dhin", "Dhit", "Dhun", "Ga", "Ge", "Ke"}
#define BOLSTATUS	{"", "~S~", "~T~", "~K~"}
#define BOL_NONE	0xFFFF
#define BOL_SILENCE	0xFFFE
#define BOL_SAM		1
#define BOL_TALI	2
#define BOL_KHALI	3
#define BOLVARS		{\
"Na01",		"Na02",		"Na03",		"Na04",		"Na05",		"Na06",		"Na07",		"Na08",		"Na09",		"Na10",\
"Ta01",		"Ta02",		"Ta03",		"Ta04",		"Ta05",		"Ta06",		"Ta07",		"Ta08",		"Ta09",		"Ta10",\
"Ti01",		"Ti02",		"Ti03",		"Ti04",		"Ti05",		"Ti06",		"Ti07",		"Ti08",	"	Ti09",		"Ti10",\
"Tin01",	"Tin02",	"Tin03",	"Tin04",	"Tin05",	"Tin06",	"Tin07",	"Tin08",	"Tin09",	"Tin10",\
"Tun01",	"Tun02",	"Tun03",	"Tun04",	"Tun05",	"Tun06",	"Tun07",	"Tun08",	"Tun09",	"Tun10",\
"Dha01",	"Dha02",	"Dha03",	"Dha04",	"Dha05",	"Dha06",	"Dha07",	"Dha08",	"Dha09",	"Dha10",\
"Dhin01",	"Dhin02",	"Dhin03",	"Dhin04",	"Dhin05",	"Dhin06",	"Dhin07",	"Dhin08",	"Dhin09",	"Dhin10",\
"Dhit01",	"Dhit02",	"Dhit03",	"Dhit04",	"Dhit05",	"Dhit06",	"Dhit07",	"Dhit08",	"Dhit09",	"Dhit10",\
"Dhun01",	"Dhun02",	"Dhun03",	"Dhun04",	"Dhun05",	"Dhun06",	"Dhun07",	"Dhun08",	"Dhun09",	"Dhun10",\
"Ga01",		"Ga02",		"Ga03",		"Ga04",		"Ga05",		"Ga06",		"Ga07",		"Ga08",		"Ga09",		"Ga10",\
"Ge01",		"Ge02",		"Ge03",		"Ge04",		"Ge05",		"Ge06",		"Ge07",		"Ge08",		"Ge09",		"Ge10",\
"Ke01",		"Ke02",		"Ke03",		"Ke04",		"Ke05",		"Ke06",		"Ke07",		"Ke08",		"Ke09",		"Ke10" }


//#define BOLFILE		{"Dha0^.wav", "Dhin0^.wav", "Dhit0^.wav", "Dhun0^.wav", "Ga0^.wav", "Ge0^.wav", "Ke0^.wav", "Na0^.wav", "Tat0^.wav", "Ti0^.wav", "Tin0^.wav", "Tun0^.wav"}

// CNaadhApp:
// See Naadh.cpp for the implementation of this class
//

class CNaadhApp : public CWinApp
{
public:
	CNaadhApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CNaadhApp theApp;


// NaadhDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Naadh.h"
#include "NaadhDlg.h"
#include "mmsystem.h"
#include ".\naadhdlg.h"
#include "AboutNaadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CNaadhDlg dialog



CNaadhDlg::CNaadhDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNaadhDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNaadhDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_SLIDER_TEMPO, m_TempoSliderCtrl);
	DDX_Control(pDX, IDC_SLIDER_RAND, m_RandSliderCtrl);
	DDX_Control(pDX, IDC_COMBO_MATRA, m_ComboMatra);
	DDX_Control(pDX, IDC_SLIDER_BOLVAR, m_BolVarSliderCtrl);
}

BEGIN_MESSAGE_MAP(CNaadhDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER ()
	ON_WM_HSCROLL()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_ABOUTNAADH, OnHelpAboutnaadh)
	ON_COMMAND(ID_HELP_CHECKFORUPDATES, OnHelpCheckforupdates)
	ON_COMMAND(ID_FILE_OPEN32773, OnFileOpen32773)
	ON_COMMAND(ID_FILE_SAVE32774, OnFileSave32774)
	ON_COMMAND(ID_FILE_SAVEAS, OnFileSaveas)
	ON_COMMAND(ID_BOLS_CLEAR32792, OnBolsClear32792)
	ON_COMMAND(ID_BOLS_SILENCE, OnBolsSilence)
	//ON_COMMAND(ID_DAYAN_NA, OnDayanNa)
	//ON_COMMAND(ID_DAYAN_TAT, OnDayanTat)
	//ON_COMMAND(ID_DAYAN_TI, OnDayanTi)
	//ON_COMMAND(ID_DAYAN_TIN, OnDayanTin)
	//ON_COMMAND(ID_DAYAN_TUN, OnDayanTun)
	//ON_COMMAND(ID_BAYAN_DHA, OnBayanDha)
	//ON_COMMAND(ID_BAYAN_DHIN, OnBayanDhin)
	//ON_COMMAND(ID_BAYAN_DHIT, OnBayanDhit)
	//ON_COMMAND(ID_BAYAN_DHUN, OnBayanDhun)
	//ON_COMMAND(ID_BAYAN_GA, OnBayanGa)
	//ON_COMMAND(ID_BAYAN_GE, OnBayanGe)
	//ON_COMMAND(ID_BAYAN_KE, OnBayanKe)
	ON_COMMAND(ID_FILE_NEWTAAL, OnFileNewtaal)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnBnClickedButtonStop)
	ON_CBN_SELCHANGE(IDC_COMBO_MATRA, OnCbnSelchangeComboMatra)
	ON_BN_CLICKED(IDC_CHECK_ACC, OnBnClickedCheckAcc)
	ON_BN_CLICKED(IDC_CHECK_RNDBOL, OnBnClickedCheckRndbol)
	ON_WM_MENUSELECT()
	ON_COMMAND(ID_OPTIONS_PLAYALLSAMPLES, OnOptionsPlayallsamples)
	ON_CONTROL_RANGE(BN_CLICKED,ID_NA_NA01,ID_KE_KE10, OnSelectBol)
	ON_COMMAND(ID_BOLS_SAM, OnBolsSam)
	ON_COMMAND(ID_BOLS_TALI, OnBolsTali)
	ON_COMMAND(ID_BOLS_KHALI, OnBolsKhali)
	ON_BN_CLICKED(IDC_CHECK_SAM, OnBnClickedCheckSam)
END_MESSAGE_MAP()


// CNaadhDlg message handlers

BOOL CNaadhDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	m_BolMenu.LoadMenu(IDR_MENU2);

	m_Quiet = true;
	m_Version = VERSION;
	m_Mesg.Format("%.1f", (float)VERSION/10.0);
	m_Mesg = "  Naad - Version " + m_Mesg + ", " + VERMONTH + " Beta";
	this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);

	// get the app path.
	char strPathName[_MAX_PATH];
	::GetModuleFileName(NULL, strPathName, _MAX_PATH);

	CString newPath(strPathName);
	int fpos = newPath.ReverseFind('\\');

	if (fpos != -1)	newPath = newPath.Left(fpos + 1);
	m_AppPath = newPath;

#ifndef _DEBUG
	OnHelpCheckforupdates();
#endif

	m_Quiet	= false;
	m_Saved = true;

	CString t;
	m_List.SetSize(MC,MR);
	m_List.m_IsMarkable = true;
	for(int x=0;x<MC;x++)
	{
		m_List.SetColWidth(x,100);
		t.Format("Maatra%d - Bol%d",x+1, x+1);
		m_List.SetColHeading(x,t);
		for(int y=0;y<MR;y++) 
		{
			m_Taal[y][x]	= BOL_NONE;
			m_Status[y][x]	= 0;
		}
	}

	m_Cols	= 0;
	m_Rows	= 0;
	m_BolVar= 0;
	m_MaxBol= 0;
	m_Rand	= 10;
	m_Tempo = 240;
	m_SamBeat = FALSE;

	m_TempoSliderCtrl.SetRange(1,1000);
	m_TempoSliderCtrl.SetPos(m_Tempo);
	m_TempoSliderCtrl.SetTicFreq(50);

	m_RandSliderCtrl.SetRange(1,100);
	m_RandSliderCtrl.SetPos(m_Rand);
	m_RandSliderCtrl.SetTicFreq(5);

	m_BolVarSliderCtrl.SetRange(0,100);
	m_BolVarSliderCtrl.SetPos(m_BolVar);
	m_BolVarSliderCtrl.SetTicFreq(5);

	m_ComboMatra.SetCurSel(0);
	m_RndBol = TRUE;
	this->CheckDlgButton(IDC_CHECK_RNDBOL,1);

	LoadBolWaves();

	this->SetDlgItemText(IDC_STATIC_FILE, " Ready...");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNaadhDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNaadhDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNaadhDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CNaadhDlg::OnFileExit()
{
	OnBnClickedButtonStop();
	CDialog::OnOK();
}

void CNaadhDlg::OnHelpAboutnaadh()
{
	m_WaveBox.Play(126);

	CAboutNaadDlg dlgAbout;
	dlgAbout.m_ImageFileName = m_AppPath + "NaadHelp\\HelpImages\\About.jpg";
	if(IDCANCEL==dlgAbout.DoModal()) 
	{
		CAboutDlg adlg;
		adlg.DoModal();
	}
}

UINT UpdateCheckProc(LPVOID param)
{
	CUpdateCheck *checkUpdate = (CUpdateCheck *)param;
	checkUpdate->Check(IDS_UPDATE);
	delete checkUpdate;
	return 0;
}

void CNaadhDlg::OnHelpCheckforupdates()
{
	CUpdateCheck *checkUpdate1 = new CUpdateCheck;
	checkUpdate1->m_Quiet = m_Quiet;
	CWinThread* hTh1 = AfxBeginThread( UpdateCheckProc, checkUpdate1, THREAD_PRIORITY_NORMAL );
}

void CNaadhDlg::OnFileOpen32773()
{
	OnBnClickedButtonStop();
	if(!m_Saved)
	{
		int ex = AfxMessageBox("Do you wish to save this Taal before loading another one ??",MB_YESNOCANCEL | MB_ICONQUESTION);
		if( ex == IDCANCEL)	return;
		if( ex == IDYES)	OnFileSave32774();
	}

	//opens output file select dialog
	CFileDialog DataFileOpenDialog(true,"nad","",OFN_HIDEREADONLY,"Naad Files (*.nad)|*.nad|All Files (*.*)|*.*||");
	DataFileOpenDialog.m_ofn.lpstrTitle = "Load a Naadh File ...";
	//DataFileOpenDialog.m_ofn.lpstrInitialDir = m_DataFilePath;
	INT_PTR res = DataFileOpenDialog.DoModal();
	if(res==IDCANCEL) return;
	m_NaadhFileName = DataFileOpenDialog.GetPathName();
	if(m_NaadhFileName.IsEmpty()) return;
	if(DataFileOpenDialog.GetFileExt() != "nad") return;

	CFile naadhfile;
	BOOL res1 = naadhfile.Open(m_NaadhFileName, CFile::modeRead);
	if(!res1)
	{
		AfxMessageBox("Error : Failed to open the file");
		m_NaadhFileName = "";
		return;
	}
	CArchive arch(&naadhfile, CArchive::load);

	UINT ver			= 0;
	UINT futureuint		= 0;
	CString futurestr;
	BOOL futurebool		= false;
	ClearTaal();

	arch >> ver >> m_Cols >> m_Rows >> m_MaatraBol;
	if(m_MaatraBol<1) m_MaatraBol = 1;

	for(int x=0;x<MAXRESRV-1;x++) arch >> futureuint;
	for(int x=0;x<MAXRESRV;x++) arch >> futurestr;
	for(int x=0;x<MAXRESRV;x++) arch >> futurebool;

	for(int x=0;x<MR;x++)
	{
		for(int y=0;y<MC;y++)
		{
			arch >> m_Taal[x][y];
			arch >> m_Status[x][y];
		}
	}

	arch.Close();
	naadhfile.Close();

	DisplayTaal();

	m_Mesg = "  Loaded ...  " + DataFileOpenDialog.GetFileTitle();
	this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
	this->SetDlgItemText(IDC_STATIC_MSG, "  Ready...");
	m_Saved = true;
}

void CNaadhDlg::OnFileSave32774()
{
	if(m_NaadhFileName.IsEmpty()) {OnFileSaveas(); return;}
	CFile naadhfile;
	BOOL res = naadhfile.Open(m_NaadhFileName, CFile::modeCreate|CFile::modeWrite);
	if(!res)
	{
		AfxMessageBox("Error : Failed to create the file");
		m_NaadhFileName = "";
		return;
	}
	CArchive arch(&naadhfile, CArchive::store);

	UINT futureuint		= 0;
	CString futurestr	= "Reserved";
	BOOL futurebool		= false;

	arch << VERSION << m_Cols << m_Rows << m_MaatraBol;
	for(int x=0;x<MAXRESRV-1;x++) arch << futureuint;
	for(int x=0;x<MAXRESRV;x++) arch << futurestr;
	for(int x=0;x<MAXRESRV;x++) arch << futurebool;

	for(int x=0;x<MR;x++)
	{
		for(int y=0;y<MC;y++)
		{
			arch << m_Taal[x][y];
			arch << m_Status[x][y];
		}
	}

	arch.Close();
	naadhfile.Close();

	m_Mesg = "  Saved ...  " + m_NaadhFileName;
	this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);
	m_Mesg.Delete(0,1+m_Mesg.ReverseFind('\\'));
	this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
	m_Saved = true;
}

void CNaadhDlg::OnFileSaveas()
{
	CFileDialog ResFileOpenDialog(false,"nad",m_NaadhFileName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Naad Files (*.nad)|*.nad|All Files (*.*)|*.*||");
	INT_PTR res = ResFileOpenDialog.DoModal();
	if(res==IDOK) 
	{
		m_NaadhFileName = ResFileOpenDialog.GetPathName();
		OnFileSave32774();
	}
}

void CNaadhDlg::DisplayTaal()
{
	//CString bols[MAXBOLS] = BOLS;

	for(int x=0;x<MR;x++)
	{
		for(int y=0;y<MC;y++)
		{
			if(m_Taal[x][y] != BOL_NONE) 
			{
				//if(m_Taal[x][y] != BOL_SILENCE) m_List.SetCellText(y, x, bols[m_Taal[x][y]/MAXBOLVARS], 1);
				//else m_List.SetCellText(y, x, "~ o ~", 1);
				m_List.m_selrow = x;
				m_List.m_selcol = y;
				DisplayBol();
				m_List.SetCellMark(y, x, true);
			}
		}
	}
	
	m_ComboMatra.SetCurSel(m_MaatraBol-1);
	OnCbnSelchangeComboMatra();
}

BOOL CNaadhDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
   if ((HIWORD(wParam) == LBN_SELCHANGE) && (LOWORD(wParam) == IDC_LIST))
   {
		OnBnClickedButtonStop();
		//what happened to previous cell ?
		if(m_Taal[m_List.m_selrow][m_List.m_selcol]==BOL_NONE) m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, false);
		//which cell selected/deselected
		m_List.GetCellSelection();
		m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, true);
		CMenu *PopupMenu = m_BolMenu.GetSubMenu(0);
		PopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, m_List.m_XPos, m_List.m_YPos, this);
   }

   return CDialog::OnCommand(wParam, lParam);
}

void CNaadhDlg::DisplayBol()
{
	//OnBnClickedButtonStop();
	if(m_Taal[m_List.m_selrow][m_List.m_selcol]==BOL_NONE) 
	{
		m_List.SetCellText(m_List.m_selcol, m_List.m_selrow, " ", 1);
		m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, false);
		return;
	}
	if(m_Taal[m_List.m_selrow][m_List.m_selcol]==BOL_SILENCE) 
	{
		m_List.SetCellText(m_List.m_selcol, m_List.m_selrow, "~ o ~", 1);
		return;
	}

	CString bols[MAXBOLVARS*MAXBOLS] = BOLVARS;
	CString stat[MAXSTATUS] = BOLSTATUS;
	int nbol = m_Taal[m_List.m_selrow][m_List.m_selcol];
	int nstat = m_Status[m_List.m_selrow][m_List.m_selcol];
	m_List.SetCellText(m_List.m_selcol, m_List.m_selrow, bols[nbol]+" "+stat[nstat], 1);
	
	//m_WaveBox.Play(m_Taal[m_List.m_selrow][m_List.m_selcol]);
	m_Saved = false;

	//OnBnClickedButtonPlay();
}

void CNaadhDlg::ClearTaal()
{
	for(int x=0;x<MC;x++)
	{
		for(int y=0;y<MR;y++) 
		{
			if(m_Taal[y][x] != BOL_NONE)
			{
				m_Taal[y][x] = BOL_NONE;
				m_List.SetCellText(x, y, " ", 1);
				m_List.SetCellMark(x, y, false);
			}
		}
	}
	m_ComboMatra.SetCurSel(0);
	OnCbnSelchangeComboMatra();
}
void CNaadhDlg::OnBolsClear32792()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_NONE;
	m_Status[m_List.m_selrow][m_List.m_selcol] = 0;
	DisplayBol();
}

void CNaadhDlg::OnBolsSilence()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_SILENCE;
	DisplayBol();
}
/*
void CNaadhDlg::OnDayanNa()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_NA;
	DisplayBol();
}

void CNaadhDlg::OnDayanTat()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_TAT;
	DisplayBol();
}

void CNaadhDlg::OnDayanTi()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_TI;
	DisplayBol();
}

void CNaadhDlg::OnDayanTin()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_TIN;
	DisplayBol();
}

void CNaadhDlg::OnDayanTun()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_TUN;
	DisplayBol();
}

void CNaadhDlg::OnBayanDha()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_DHA;
	DisplayBol();
}

void CNaadhDlg::OnBayanDhin()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_DHIN;
	DisplayBol();
}

void CNaadhDlg::OnBayanDhit()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_DHIT;
	DisplayBol();
}

void CNaadhDlg::OnBayanDhun()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_DHUN;
	DisplayBol();
}

void CNaadhDlg::OnBayanGa()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_GA;
	DisplayBol();
}

void CNaadhDlg::OnBayanGe()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_GE;
	DisplayBol();
}

void CNaadhDlg::OnBayanKe()
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = BOL_KE;
	DisplayBol();
}
*/

void CNaadhDlg::OnFileNewtaal()
{
	if(!m_Saved)
	{
		int ex = AfxMessageBox("Do you wish to save this Taal before creating a new one ??",MB_YESNOCANCEL | MB_ICONQUESTION);
		if( ex == IDCANCEL)	return;
		if( ex == IDYES)	OnFileSave32774();
	}
	OnBnClickedButtonStop();
	ClearTaal();
	m_NaadhFileName = "";
	this->SetDlgItemText(IDC_STATIC_FILE, " New Taal");

}

void CNaadhDlg::OnBnClickedButtonPlay()
{
	m_NextBol	= 0;
	m_BolCount	= 0;
	OnBnClickedButtonStop();

	//prepare bol sequence
	for(int y=0;y<MR;y++)
	{
		for(int x=0;x<MC;x++)
		{
			if(m_Taal[y][x] != BOL_NONE) 
			{
				m_BolSeq[m_BolCount] = m_Taal[y][x];
				m_StatusSeq[m_BolCount] = m_Status[y][x];
				m_BolCount ++;
			}
		}
	}
	CTime time = CTime::GetCurrentTime();
	srand(time.GetSecond());
	m_Timer = SetTimer(WM_USER+200, m_Tempo, NULL);
	this->SetDlgItemText(IDC_STATIC_MSG, " Playing ...");
}

void CNaadhDlg::OnTimer(UINT nIDEvent)
{
	if(nIDEvent==m_TimerAcc)
	{
		m_WaveBox.Play(m_Acc);
	}
	else
	{
		//variation in bols
		//series1 0-11 series2 12-23 series3 24-35
		int r = /*rand() % */m_BolVar;
		UINT nbol = r + m_BolSeq[m_NextBol];
		if(nbol>m_MaxBol) nbol = m_BolSeq[m_NextBol];
		//TRACE2("%d, %d\r\n",r,s);

		//play it
		if(m_BolSeq[m_NextBol] != BOL_SILENCE) m_WaveBox.Play(nbol);

		//sam
		if(m_SamBeat)
		{
			if(m_StatusSeq[m_NextBol] == BOL_SAM) m_WaveBox.Play(121);
		}

		//set next
		m_NextBol ++;
		if(m_NextBol>=m_BolCount) m_NextBol = 0;

		//variation in timer
		KillTimer(m_Timer);
		r = rand() % m_Rand;//1-100
		r = (int)m_Tempo*(r - (int)m_Rand/2)/150;
		TRACE2("%d, %d\r\n",r,m_Rand);
		m_Timer = SetTimer(WM_USER+200, m_Tempo + r, NULL);
	}

	CDialog::OnTimer(nIDEvent);
}

void CNaadhDlg::OnBnClickedButtonStop()
{
	KillTimer(m_Timer);
	this->SetDlgItemText(IDC_STATIC_MSG, " Stopped ...");
}

void CNaadhDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == (CScrollBar*)&m_TempoSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)||(nSBCode == SB_THUMBTRACK))
		{
			int bpm = nPos;
			m_Tempo = 60000/nPos;
			m_Mesg.Format("  Tempo = %d Beats per minute", bpm);
			this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);
			//if(nSBCode == SB_THUMBPOSITION) OnBnClickedButtonPlay(); 
		}
	}
	if (pScrollBar == (CScrollBar*)&m_RandSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)||(nSBCode == SB_THUMBTRACK))
		{
			m_Rand = nPos;
			m_Mesg.Format("  Timing Variation = %d",nPos);
			this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);
			//if(nSBCode == SB_THUMBPOSITION) OnBnClickedButtonPlay(); 
		}
	}
	if (pScrollBar == (CScrollBar*)&m_BolVarSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)||(nSBCode == SB_THUMBTRACK))
		{
			m_BolVar = nPos;
			m_Mesg.Format("  Bol Variation = %d",nPos);
			this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);
			//if(nSBCode == SB_THUMBPOSITION) OnBnClickedButtonPlay(); 
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CNaadhDlg::OnCbnSelchangeComboMatra()
{
	m_MaatraBol = 1 + m_ComboMatra.GetCurSel();

	CString t;
	UINT y = 1, z = 1;
	for(int x=0;x<MC;x++)
	{
		t.Format("Maatra%d - Bol%d",z, x+1);
		m_List.SetColHeading(x,t);
		y++;
		if(y>m_MaatraBol) {y=1;z++;}
	}
}

void CNaadhDlg::LoadBolWaves()
{
	CString bolfile[MAXBOLS] = BOLS;
	CString t, alarm;
	int bolcount = 0, nbol = 0, failed = 0;
	alarm = m_AppPath+"Bol\\Acc\\Alarm.wav";

	for(int x=0;x<MAXBOLS;x++)
	{
		for(int y=0;y<MAXBOLVARS;y++)
		{
			t.Format("%02d.wav",y+1);
			t = m_AppPath+"Bol\\"+bolfile[x]+"\\"+bolfile[x]+t;
			nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));
			if(nbol<0) 
			{
				m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));
				failed++;
			}
			m_MaxBol++;
		}
	}
	//load accompaniment waves and other stuff
	t = m_AppPath+"Bol\\Acc\\Tanpura_SaPa_G.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//121

	t = m_AppPath+"Bol\\Acc\\Ghungru01.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//122
	t = m_AppPath+"Bol\\Acc\\Ghungru02.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//123
	t = m_AppPath+"Bol\\Acc\\Ghungru03.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//124
	t = m_AppPath+"Bol\\Acc\\Ghungru04.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//125
	t = m_AppPath+"Bol\\Acc\\Ghungru05.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//126
	t = m_AppPath+"Bol\\Acc\\Ghungru06.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//127

	t = m_AppPath+"Bol\\Acc\\Intro.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//128
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));//129
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));//130

	m_Acc = 121-1;
}

void CNaadhDlg::OnBnClickedCheckAcc()
{
	if(this->IsDlgButtonChecked(IDC_CHECK_ACC))
	{
		m_TimerAcc = SetTimer(WM_USER+201, 7880, NULL);
		m_WaveBox.Play(m_Acc);//dont wait till it starts
	}
	else KillTimer(m_TimerAcc);
}

void CNaadhDlg::OnBnClickedCheckRndbol()
{
	m_RndBol = this->IsDlgButtonChecked(IDC_CHECK_RNDBOL);
}

void CNaadhDlg::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
{
	CDialog::OnMenuSelect(nItemID, nFlags, hSysMenu);
	if((nItemID>=ID_NA_NA01)&&(nItemID<=ID_KE_KE10))
	{
		m_WaveBox.Play(nItemID - ID_NA_NA01);
	}
}

void CNaadhDlg::OnOptionsPlayallsamples()
{
	for(UINT x=0;x<m_WaveBox.wload;x++)
	{
		m_WaveBox.Play(x);
		Sleep(250);
	}
}

void CNaadhDlg::OnSelectBol(UINT nID)
{
	m_Taal[m_List.m_selrow][m_List.m_selcol] = nID-ID_NA_NA01;
	DisplayBol();
}

void CNaadhDlg::OnBolsSam()
{
	m_Status[m_List.m_selrow][m_List.m_selcol] = BOL_SAM;
	DisplayBol();
}

void CNaadhDlg::OnBolsTali()
{
	m_Status[m_List.m_selrow][m_List.m_selcol] = BOL_TALI;
	DisplayBol();
}

void CNaadhDlg::OnBolsKhali()
{
	m_Status[m_List.m_selrow][m_List.m_selcol] = BOL_KHALI;
	DisplayBol();
}

void CNaadhDlg::OnBnClickedCheckSam()
{
	m_SamBeat = this->IsDlgButtonChecked(IDC_CHECK_SAM);	
}

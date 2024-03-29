// NaadhDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Naadh.h"
#include "NaadhDlg.h"
#include "mmsystem.h"
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
	ON_COMMAND(ID_FILE_NEWTAAL, OnFileNewtaal)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_CHECK_ACC, OnBnClickedCheckAcc)
	ON_BN_CLICKED(IDC_CHECK_RNDBOL, OnBnClickedCheckRndbol)
	ON_WM_MENUSELECT()
	ON_COMMAND(ID_OPTIONS_PLAYALLSAMPLES, OnOptionsPlayallsamples)
	ON_CONTROL_RANGE(BN_CLICKED,ID_NA_NA01,ID_KE_KE10, OnSelectBol)
	ON_COMMAND(ID_BOLS_SAM, OnBolsSam)
	ON_COMMAND(ID_BOLS_TALI, OnBolsTali)
	ON_COMMAND(ID_BOLS_KHALI, OnBolsKhali)
	ON_BN_CLICKED(IDC_CHECK_SAM, OnBnClickedCheckSam)
	ON_COMMAND(ID_OPTIONS_BOLFOLDER, OnOptionsBolfolder)
	ON_COMMAND(ID_HELP_CONTACT, OnHelpContact)
	ON_COMMAND(ID_HELP_NAADHHELP, OnHelpNaadhhelp)
	ON_COMMAND(ID_FILE_NEWCOMPOSITION, OnFileNewcomposition)
	ON_COMMAND(ID_LOOP_OPEN, OnLoopOpen)
	ON_COMMAND(ID_VIEW_COMPOSITION, OnViewComposition)
	ON_COMMAND(ID_LOOP_CLEAR, OnLoopClear)
	ON_COMMAND(ID_BOLS_VIEWCOMP, OnBolsViewcomp)
	ON_COMMAND(ID_LOOP_PROPERTIES, OnLoopProperties)
	ON_COMMAND(ID_VIEW_LOOP, OnViewLoop)
	ON_BN_CLICKED(IDC_CHECK_ECHO, &CNaadhDlg::OnBnClickedCheckEcho)
	ON_BN_CLICKED(IDOK, &CNaadhDlg::OnBnClickedOk)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU01, &CNaadhDlg::OnGhungruGhungru01)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU02, &CNaadhDlg::OnGhungruGhungru02)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU03, &CNaadhDlg::OnGhungruGhungru03)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU04, &CNaadhDlg::OnGhungruGhungru04)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU05, &CNaadhDlg::OnGhungruGhungru05)
	ON_COMMAND(ID_GHUNGRU_GHUNGRU06, &CNaadhDlg::OnGhungruGhungru06)
	ON_COMMAND(ID_ACCOMPANIMENT_TANPURA, &CNaadhDlg::OnAccompanimentTanpura)
	ON_COMMAND(ID_ACCOMPANIMENT_2, &CNaadhDlg::OnAccompaniment2)
	ON_COMMAND(ID_ACCOMPANIMENT_3, &CNaadhDlg::OnAccompaniment3)
	ON_COMMAND(ID_ACCOMPANIMENT_4, &CNaadhDlg::OnAccompaniment4)
	ON_BN_CLICKED(IDC_CHECK_VARSAME, &CNaadhDlg::OnBnClickedCheckVarsame)
	ON_BN_CLICKED(IDC_CHECK_VARANY, &CNaadhDlg::OnBnClickedCheckVarany)
	ON_BN_CLICKED(IDC_BUTTON_SAVEVAR, &CNaadhDlg::OnBnClickedButtonSavevar)
	ON_BN_CLICKED(IDC_CHECK_VARCOMP, &CNaadhDlg::OnBnClickedCheckVarcomp)
	ON_BN_CLICKED(IDC_CHECK_VARLOOP, &CNaadhDlg::OnBnClickedCheckVarloop)
	ON_BN_CLICKED(IDC_BUTTON_AUTOCOMPOSE, &CNaadhDlg::OnBnClickedButtonAutocompose)
	ON_BN_CLICKED(IDC_BUTTON_PLAYLOOP, &CNaadhDlg::OnBnClickedButtonPlayloop)
	ON_BN_CLICKED(IDC_BUTTON_GUN1, &CNaadhDlg::OnBnClickedButtonGun1)
	//ON_BN_CLICKED(IDC_BUTTON_GUN2, &CNaadhDlg::OnBnClickedButtonGun2)
	//ON_BN_CLICKED(IDC_BUTTON_GUN3, &CNaadhDlg::OnBnClickedButtonGun3)
	//ON_BN_CLICKED(IDC_BUTTON_GUN4, &CNaadhDlg::OnBnClickedButtonGun4)
	ON_COMMAND(ID_LOOP_LOADLOOP, &CNaadhDlg::OnLoopLoadloop)
	ON_COMMAND(ID_LOOP_SAVELOOP, &CNaadhDlg::OnLoopSaveloop)
	ON_COMMAND(ID_EDIT_SELECT, &CNaadhDlg::OnEditSelect)
	ON_COMMAND(ID_EDIT_CLEAR32974, &CNaadhDlg::OnEditClear32974)
	ON_COMMAND(ID_EDIT_COPY32956, &CNaadhDlg::OnEditCopy32956)
	ON_COMMAND(ID_EDIT_CUT32957, &CNaadhDlg::OnEditCut32957)
	ON_COMMAND(ID_EDIT_PASTE32958, &CNaadhDlg::OnEditPaste32958)
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
	m_LoopMenu.LoadMenu(IDR_MENU3);

	m_Quiet			= TRUE;
	m_IsInstalled	= FALSE;
	m_IsShellOpen	= FALSE;
	m_IsBolLoaded	= FALSE;
	m_Version		= VERSION;

	m_Mesg.Format("%.1f", (float)VERSION/10.0);
	m_Mesg = "  Naad - Version " + m_Mesg + ", " + VERMONTH + " Beta";
	this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);

	// get the app path.
	char strPathName[_MAX_PATH];
	::GetModuleFileName(NULL, strPathName, _MAX_PATH);

	CString newPath(strPathName);
	CString t(strPathName);

	int fpos = newPath.ReverseFind('\\');
	if (fpos != -1)	newPath = newPath.Left(fpos + 1);
	m_AppPath = newPath;

	LoadSettings();
	if(!m_IsInstalled) 
	{
		AssociateFileType(".nad", t , "NaadFile", "Naad File", t+",1");
		AssociateFileType(".nlp", t , "NaadLoopFile", "Naad Loop File", t+",2");
		m_IsInstalled = true;
		SaveSettings();
	}

#ifndef _DEBUG
	OnHelpCheckforupdates();
#endif

	m_Quiet	= FALSE;
	m_Saved = TRUE;

	m_List.SetSize(MC,MR);
	m_List.m_IsMarkable = TRUE;

	m_TempoSliderCtrl.SetRange(-MAXBPM, MAXBPM);
	m_TempoSliderCtrl.SetTicFreq(MAXBPM/10);

	m_RandSliderCtrl.SetRange(0,30);
	m_RandSliderCtrl.SetTicFreq(2);

	m_BolVarSliderCtrl.SetRange(0,100);
	m_BolVarSliderCtrl.SetTicFreq(5);
	//UpdateTempo();

	LoadBolWaves();

	m_Menu.CheckMenuItem(ID_INSTRUMENT_TABLA,		MF_CHECKED|MF_BYCOMMAND);
	m_Menu.CheckMenuItem(ID_ACCOMPANIMENT_TANPURA,	MF_CHECKED|MF_BYCOMMAND);
	m_Menu.CheckMenuItem(ID_GHUNGRU_GHUNGRU01,		MF_CHECKED|MF_BYCOMMAND);

	Reset();

	//get the command line
	CCommandLineInfo cinfo;
	theApp.ParseCommandLine(cinfo);
	m_NaadhFileName = cinfo.m_strFileName;
	if(!m_NaadhFileName.IsEmpty())
	{
		m_IsShellOpen = TRUE;
		OnFileOpen32773();
		m_IsShellOpen = FALSE;
	}
	else 
	{	
		OnFileNewcomposition();
	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNaadhDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 0xFFF0) == SC_CLOSE)
	{
		OnFileExit();
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

void CNaadhDlg::Reset()
{
	for(int x=0;x<MC;x++)
	{
		m_List.SetColWidth(x,100);
	}

	//m_Cols			= 0;
	//m_Rows			= 0;
	//m_MaxBol			= 0;
	//m_Echo			= 0;

	m_BolVar		= 0;
	m_GhungruSel	= 0;
	m_TanpuraSel	= 0;
	m_BpmDeviation	= 0;
	m_Rand			= 0;
	m_BpmRand		= 0;
	m_TotalLoops	= 0;
	m_SeqNum		= 0;
	m_Gun			= 1;
	m_MaatraBol		= 1;
	m_Bpm			= DEFAULT_BPM;

	m_Sequence		= NULL;
	m_LoopSequence	= NULL;

	m_IsCompView	= TRUE;
	m_SamBeat		= FALSE;
	m_IsPlaying		= FALSE;
	m_PlayLoop		= FALSE;
	m_EditMode		= FALSE;
	//m_Paste			= FALSE;

	m_VarietySameSpecies	= TRUE;
	m_VarietyAnySpecies		= FALSE;
	m_VarietyLoop			= TRUE;
	m_VarietyComp			= FALSE;

	this->CheckDlgButton(IDC_CHECK_VARSAME, m_VarietySameSpecies);
	this->CheckDlgButton(IDC_CHECK_VARANY, m_VarietyAnySpecies);
	this->CheckDlgButton(IDC_CHECK_VARLOOP, m_VarietyLoop);
	this->CheckDlgButton(IDC_CHECK_VARCOMP, m_VarietyComp);
	this->CheckDlgButton(IDC_CHECK_SAM, m_SamBeat);

	m_TempoSliderCtrl.SetPos(m_BpmDeviation);
	m_RandSliderCtrl.SetPos(m_Rand);
	m_BolVarSliderCtrl.SetPos(m_BolVar);

	m_List.SetColHeading(7,"Compose Mode");
	m_Menu.CheckMenuItem(ID_EDIT_SELECT, (MF_CHECKED * (UINT)m_EditMode) |MF_BYCOMMAND);

	m_Mesg.Format("%.1f", (float)VERSION/10.0);
	m_Mesg = "  Naad - Version " + m_Mesg + ", " + VERMONTH + " Beta";
	this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);
}

void CNaadhDlg::OnFileExit()
{	
	OnBnClickedButtonStop();
	DeleteLoopSequence();

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

void CNaadhDlg::OpenOldVer()
{
	//new comp
	CString filetitle = m_NaadhFileName;
	m_Saved = TRUE;
	OnFileNewcomposition();
	m_Composition.DeleteLoop(0);

	m_List.m_selcol = 0;
	m_List.m_selrow = 0;
	OpenLoopOldVer(filetitle);

	//CFile naadhfile;
	//BOOL res1 = naadhfile.Open(m_NaadhFileName, CFile::modeRead);
	//if(!res1)
	//{
	//	AfxMessageBox("Error : Failed to open the file");
	//	m_NaadhFileName = "";
	//	return;
	//}
	//CArchive arch(&naadhfile, CArchive::load);

	//UINT ver = 0;
	////ver
	//arch >> ver;
	//if(ver < 2)
	//{
	//	arch.Close();
	//	naadhfile.Close();
	//	AfxMessageBox("The file you are trying to open is of a version that is no longer supported");
	//	return;
	//}
	//UINT futureuint	= 0, col, row;
	//CString futurestr;
	//BOOL futurebool	= false;
	////ClearDisplay();

	//arch >> col >> row >> m_MaatraBol;
	//if(m_MaatraBol<1) m_MaatraBol = 1;

	//for(int x=0;x<MAXRESRV-1;x++) arch >> futureuint;
	//for(int x=0;x<MAXRESRV;x++) arch >> futurestr;
	//for(int x=0;x<MAXRESRV;x++) arch >> futurebool;

	////for(int x=0;x<MR;x++)
	////{
	////	for(int y=0;y<MC;y++)
	////	{
	////		//arch >> m_Taal[x][y];
	////		//arch >> m_Status[x][y];
	////	}
	////}

	//arch.Close();
	//naadhfile.Close();

	////DisplayTaal();

	//CString filetitle = m_NaadhFileName;
	//filetitle.Delete(0,m_NaadhFileName.ReverseFind('\\')+1);

	//m_Mesg = "  Loaded ...  " + filetitle; //DataFileOpenDialog.GetFileTitle();
	//this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
	//this->SetDlgItemText(IDC_STATIC_MSG, "  Ready...");
	//m_Saved = true;
}

void CNaadhDlg::OnFileOpen32773()
{
	if(!m_IsShellOpen)
	{
		if(m_IsPlaying) OnBnClickedButtonStop();
		if(!m_Saved)
		{
			int ex = AfxMessageBox("Do you wish to save this composition before loading another one ??",MB_YESNOCANCEL | MB_ICONQUESTION);
			if( ex == IDCANCEL)	return;
			if( ex == IDYES)	OnFileSave32774();
		}

		//opens output file select dialog
		CFileDialog DataFileOpenDialog(true,"nad","",OFN_HIDEREADONLY,"Naad Files (*.nad)|*.nad|All Files (*.*)|*.*||");
		DataFileOpenDialog.m_ofn.lpstrTitle = "Load a Naad File ...";
		DataFileOpenDialog.m_ofn.lpstrInitialDir = m_AppPath + "Compositions";
		INT_PTR res = DataFileOpenDialog.DoModal();
		if(res==IDCANCEL) return;
		m_NaadhFileName = DataFileOpenDialog.GetPathName();
		if(m_NaadhFileName.IsEmpty()) return;
		if(DataFileOpenDialog.GetFileExt() != "nad") return;
	}

	CFile naadhfile;
	BOOL res1 = naadhfile.Open(m_NaadhFileName, CFile::modeRead);
	if(!res1)
	{
		AfxMessageBox("Error : Failed to open the file");
		m_NaadhFileName = "";
		return;
	}
	CArchive arch(&naadhfile, CArchive::load);

	UINT ver = 0, type = 0;
	//ver
	arch >> ver;
	if(ver < VERSION)
	{
		arch.Close();
		naadhfile.Close();
		OpenOldVer();
		return;
	}

	if(ver > VERSION)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is of a newer version. Please update to the latest version and try again.");
		return;
	}
	
	arch >> type;
	if(type != FILETYPE_COMP)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is probably not a Naad composition and cannot be opened");
		return;
	}


	//new comp
	CString filetitle = m_NaadhFileName;
	m_Saved = TRUE;
	OnFileNewcomposition();
	m_Composition.DeleteLoop(0);

	//comp
	UINT loopcount = 0;
	arch 
		>> m_Composition.m_CompositionName 
		>> m_Composition.m_ComposerName 
		>> m_Composition.m_Notes
		>> loopcount;

	//chk loopcount
	if(loopcount > MC*MR)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is probably corrupt and cannot be opened");
		OnFileNewcomposition();
		return;
	}

	//loops
	UINT col = 0, row = 0, bolcount = 0;
	for(UINT x=0; x<loopcount; x++)
	{
		arch 
			>> col
			>> row;

		m_Composition.AddLoop(col, row);

		arch 
			>> m_Composition.m_Loop[x].m_LoopName
			>> m_Composition.m_Loop[x].m_Note
			>> m_Composition.m_Loop[x].m_Accompaniment
			>> m_Composition.m_Loop[x].m_LoopBpm
			>> m_Composition.m_Loop[x].m_MaatraBol
			>> m_Composition.m_Loop[x].m_RepeatCount
			>> bolcount;

		for(UINT y=0; y<bolcount; y++)
		{
			m_Composition.m_Loop[x].AddBol();
			arch 
				>> m_Composition.m_Loop[x].m_Bol[y].m_BolId
				>> m_Composition.m_Loop[x].m_Bol[y].m_BolName
				>> m_Composition.m_Loop[x].m_Bol[y].m_BolStatusName
				>> m_Composition.m_Loop[x].m_Bol[y].m_Col
				>> m_Composition.m_Loop[x].m_Bol[y].m_Row
				>> m_Composition.m_Loop[x].m_Bol[y].m_Species
				>> m_Composition.m_Loop[x].m_Bol[y].m_Status;
		}

	}


	arch.Close();
	naadhfile.Close();

	DisplayComposition();

	filetitle.Delete(0,m_NaadhFileName.ReverseFind('\\')+1);

	m_Mesg = "  Loaded ...  " + filetitle; //DataFileOpenDialog.GetFileTitle();
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

	//ver
	arch << VERSION << FILETYPE_COMP;

	//comp
	arch 
		<< m_Composition.m_CompositionName 
		<< m_Composition.m_ComposerName 
		<< m_Composition.m_Notes
		<< m_Composition.m_LoopCount;

	//loops
	for(UINT x=0; x<m_Composition.m_LoopCount; x++)
	{
		arch 
			<< m_Composition.m_Loop[x].m_Col
			<< m_Composition.m_Loop[x].m_Row
			<< m_Composition.m_Loop[x].m_LoopName
			<< m_Composition.m_Loop[x].m_Note
			<< m_Composition.m_Loop[x].m_Accompaniment
			<< m_Composition.m_Loop[x].m_LoopBpm
			<< m_Composition.m_Loop[x].m_MaatraBol
			<< m_Composition.m_Loop[x].m_RepeatCount
			<< m_Composition.m_Loop[x].m_BolCount;

		for(UINT y=0; y<m_Composition.m_Loop[x].m_BolCount; y++)
		{
			arch 
				<< m_Composition.m_Loop[x].m_Bol[y].m_BolId
				<< m_Composition.m_Loop[x].m_Bol[y].m_BolName
				<< m_Composition.m_Loop[x].m_Bol[y].m_BolStatusName
				<< m_Composition.m_Loop[x].m_Bol[y].m_Col
				<< m_Composition.m_Loop[x].m_Bol[y].m_Row
				<< m_Composition.m_Loop[x].m_Bol[y].m_Species
				<< m_Composition.m_Loop[x].m_Bol[y].m_Status;
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
	ResFileOpenDialog.m_ofn.lpstrInitialDir = m_AppPath + "Compositions";
	INT_PTR res = ResFileOpenDialog.DoModal();
	if(res==IDOK) 
	{
		m_NaadhFileName = ResFileOpenDialog.GetPathName();
		OnFileSave32774();
	}
}

//void CNaadhDlg::DisplayTaal()
//{
//	//CString bols[MAXBOLS] = BOLS;
//
//	for(int x=0;x<MR;x++)
//	{
//		for(int y=0;y<MC;y++)
//		{
//			if(m_Taal[x][y] != BOL_NONE) 
//			{
//				//if(m_Taal[x][y] != BOL_SILENCE) m_List.SetCellText(y, x, bols[m_Taal[x][y]/MAXBOLVARS], 1);
//				//else m_List.SetCellText(y, x, "~ o ~", 1);
//				m_List.m_selrow = x;
//				m_List.m_selcol = y;
//				DisplayBol();
//				//m_List.SetCellMark(y, x, true);
//			}
//		}
//	}
//	
//	m_ComboMatra.SetCurSel(m_MaatraBol-1);
//	OnCbnSelchangeComboMatra();
//}

BOOL CNaadhDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
   if ((HIWORD(wParam) == LBN_SELCHANGE) && (LOWORD(wParam) == IDC_LIST))
   {
		if(m_IsPlaying) OnBnClickedButtonStop();
/*		if(m_Paste)
		{
			m_List.GetCellSelection();
			m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, m_List.m_sel);
			Paste(m_List.m_selcol, m_List.m_selrow);
		}
		else */
		if(m_EditMode)
		{
			//which cell selected/deselected
			m_List.GetCellSelection();
			m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, m_List.m_sel);
			if(m_ActiveLoop != LOOP_NONE)
			{
				m_Composition.SetBolSelection(m_ActiveLoop, m_List.m_selcol, m_List.m_selrow, m_List.m_sel);
			}
			else
			{
				m_Composition.SetLoopSelection(m_List.m_selcol, m_List.m_selrow, m_List.m_sel);
			}

		}
		else
		{
			//un-highlight previous cell
			m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, false);
			//which cell selected/deselected
			m_List.GetCellSelection();
			m_List.SetCellMark(m_List.m_selcol, m_List.m_selrow, true);
			CMenu *PopupMenu = NULL;
			if(m_IsCompView) PopupMenu = m_LoopMenu.GetSubMenu(0);
			else PopupMenu = m_BolMenu.GetSubMenu(0);
			PopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, m_List.m_XPos, m_List.m_YPos, this);
		}
   }

   return CDialog::OnCommand(wParam, lParam);
}

void CNaadhDlg::ClearDisplay()
{
	for(int x=0;x<MC;x++)
	{
		for(int y=0;y<MR;y++) 
		{
			m_List.SetCellText(x, y, " ", 1);
			m_List.SetCellMark(x, y, false);
		}
	}

}

void CNaadhDlg::ClearSelection()
{
	for(int x=0;x<MC;x++)
	{
		for(int y=0;y<MR;y++) 
		{
			m_List.SetCellMark(x, y, false);
		}
	}

	m_List.m_sel = FALSE;
	m_Composition.DeSelectAll();
}

void CNaadhDlg::OnFileNewtaal()//add loop
{
	if(m_ActiveLoop != LOOP_NONE) 
	{
		DisplayComposition();
	}

	//find an empty box
	bool found = false;
	int x = 0, y = 0;
	for(y=0;y<MR;y++) 
	{
		for(x=0;x<MC;x++)
		{
			if((m_List.GetCellText(x,y).GetLength()-2)<1) {found = true; break;}
		}
		if(found) break;
	}
	if(!found)
	{
		AfxMessageBox("All positions are occupied, please delete some loops");
		return;
	}
	
	m_Composition.AddLoop(x,y);
	//m_Composition.m_Loop[m_Composition.m_LoopCount-1].m_Col = x;
	//m_Composition.m_Loop[m_Composition.m_LoopCount-1].m_Row = y;
	DisplayComposition();
	m_List.SetCellMark(x,y,true);
}

bool CNaadhDlg::CreateLoopSequence()
{
	if(m_Sequence || m_LoopSequence) DeleteLoopSequence();
	
	bool allocloop	= true;
	bool allocseq	= true;
	bool allocbol	= true;

	//get total num of loops including repeats
	m_TotalLoops = 0;
	for(UINT nloop=0; nloop<m_Composition.m_LoopCount; nloop++)
	{
		if(m_Composition.m_Loop[nloop].m_BolCount > 0) m_TotalLoops += m_Composition.m_Loop[nloop].m_RepeatCount;
	}

	if(m_TotalLoops == 0) return false;

	m_LoopSequence = new UINT[m_TotalLoops];
	if(m_LoopSequence == NULL)
	{
		allocloop = false;
	}
	

	//seq of loops
	UINT nseq = 0;
	for(UINT by=0;by<MR;by++)
	{
		for(UINT bx=0;bx<MC;bx++)
		{
			UINT nloop = m_Composition.GetLoop(bx,by);
			if( (nloop != LOOP_NONE) && (m_Composition.m_Loop[nloop].m_BolCount > 0) )
			{
				for(UINT bz=0;bz<m_Composition.m_Loop[nloop].m_RepeatCount;bz++)
				{
					m_LoopSequence[nseq] = nloop;
					TRACE("loopseq [%d] = %d\r\n", nseq, nloop);
					nseq++;
				}
			}
		}
	}


	//seq of bols in each loop
	m_Sequence = new CSequence[m_Composition.m_LoopCount];
	if(m_Sequence == NULL)
	{
		allocseq = false;
	}
	if(allocseq)
	{
		for(UINT nloop=0; nloop<m_Composition.m_LoopCount; nloop++)
		{
			allocbol = allocbol && m_Sequence[nloop].CreateBolSequence(m_Composition.m_Loop[nloop]);
		}
	}

	return (allocloop && allocbol && allocseq);
}

void CNaadhDlg::DeleteLoopSequence()
{
	if(m_Sequence) 
	{
		delete [] m_Sequence; 
		m_Sequence = NULL;
	}
	if(m_LoopSequence) 
	{
		delete [] m_LoopSequence; 
		m_LoopSequence = NULL;
	}
}

void CNaadhDlg::OnBnClickedButtonPlay()
{
	m_PlayLoop = FALSE;
	m_NextLoop	= 0;
	InitPlay();
}

void CNaadhDlg::TempoVariation()
{
	//variation in tempo and tempo randomness
	if(m_Rand==0) 
	{
		m_BpmRand = 0;
		return;
	}

	m_BpmRand = m_Rand - rand() % (2*m_Rand);
	UpdateTempo();
}

//bool CNaadhDlg::GetNextLoop()
//{
//	while(m_Sequence[m_NextLoop].m_BolSeqCount == 0)
//	{
//		m_NextLoop ++;
//		if(m_NextLoop >= m_Composition.m_LoopCount)
//		{
//			return false;	//all loops are empty
//		}
//		
//	}
//}

void CNaadhDlg::PlayLoopSequence()
{
	if(m_LoopDone)
	{
		if((m_PlayLoop) && (m_ActiveLoop != LOOP_NONE))
		{
			//do nothing
		}
		else
		{
			if(m_SeqNum < m_TotalLoops-1) m_SeqNum ++;
			else m_SeqNum = 0;
			m_NextLoop = m_LoopSequence[m_SeqNum]; 
			SetLoopBpm();
			m_LoopDone = FALSE;
		}
	
	}

	PlayBolSequence();
}

void CNaadhDlg::PlayBolSequence()
{
	if(m_Sequence[m_NextLoop].m_BolSeqCount == 0) return;

	//play bol
	UINT nbolseq = BOL_NONE;

	if(	m_BolVar > 0) nbolseq = m_Sequence[m_NextLoop].m_BolVarSeq[m_NextBol];
	else nbolseq = m_Sequence[m_NextLoop].m_BolIdSeq[m_NextBol];

	//play it
	if(nbolseq != BOL_SILENCE) m_WaveBox.Play(nbolseq);

	//sam
	if(m_SamBeat)
	{
		if(m_Sequence[m_NextLoop].m_BolStatusSeq[m_NextBol] == BOL_SAM) m_WaveBox.Play(m_Ghungru[m_GhungruSel]);
	}

	//set next
	if(m_NextBol < m_Sequence[m_NextLoop].m_BolSeqCount-1) 
	{
		m_NextBol ++;
	}
	else 
	{
		m_NextBol = 0;
		m_LoopDone = TRUE;
	}

	TempoVariation();
}

//void CNaadhDlg::PlaySequence()
//{	
//	//check seq
//	if((m_Sequence[m_NextLoop].m_BolSeqCount == 0) && (m_Composition.m_LoopCount<=1)) return; //nothing to play
//
//	if((m_PlayLoop) && (m_ActiveLoop != LOOP_NONE))
//	{
//		if(m_Sequence[m_NextLoop].m_BolSeqCount == 0) 
//		{
//			//OnTimer(WM_USER+200);
//			return;
//		}
//	}
//	else
//	{
//		if(m_Sequence[m_NextLoop].m_BolSeqCount == 0) 
//		{
//			if(m_NextLoop < m_Composition.m_LoopCount-1) {m_NextLoop ++; SetLoopBpm();}
//			else {m_NextLoop = 0; SetLoopBpm();}
//
//			//OnTimer(WM_USER+200);
//			return;
//		}
//	}
//
//	//play bol
//	UINT nbolseq = BOL_NONE;
//
//	if(	m_BolVar > 0) nbolseq = m_Sequence[m_NextLoop].m_BolVarSeq[m_NextBol];
//	else nbolseq = m_Sequence[m_NextLoop].m_BolIdSeq[m_NextBol];
//
//	//play it
//	if(nbolseq != BOL_SILENCE) m_WaveBox.Play(nbolseq);
//
//	//sam
//	if(m_SamBeat)
//	{
//		if(m_Sequence[m_NextLoop].m_BolStatusSeq[m_NextBol] == BOL_SAM) m_WaveBox.Play(m_Ghungru[m_GhungruSel]);
//	}
//
//	//set next
//	if(m_NextBol < m_Sequence[m_NextLoop].m_BolSeqCount-1) m_NextBol ++;
//	else 
//	{
//		m_NextBol = 0;
//		if((m_PlayLoop) && (m_ActiveLoop != LOOP_NONE))
//		{
//			m_NextLoop = m_ActiveLoop;
//		}
//		else
//		{
//			if(m_NextLoop <= m_Composition.m_LoopCount-1) 
//			{
//				//check repeats
//				if(m_Sequence[m_NextLoop].m_RepeatSeqCount > 1)
//				{
//					if(m_Sequence[m_NextLoop].m_RepeatCountDown < 2) 
//					{
//						m_Sequence[m_NextLoop].m_RepeatCountDown = m_Sequence[m_NextLoop].m_RepeatSeqCount;
//						if(m_NextLoop < m_Composition.m_LoopCount-1) {m_NextLoop ++; SetLoopBpm();}
//						else {m_NextLoop = 0; SetLoopBpm();}
//					}
//					else m_Sequence[m_NextLoop].m_RepeatCountDown --;
//				}
//				else
//				{
//					if(m_NextLoop < m_Composition.m_LoopCount-1) {m_NextLoop ++; SetLoopBpm();}
//					else {m_NextLoop = 0; SetLoopBpm();}
//				}
//
//			}
//			else 
//			{
//				m_NextLoop = 0; 
//				SetLoopBpm();
//			}
//		}
//	}
//
//	TempoVariation();
//}

void CNaadhDlg::SetLoopBpm()
{
	m_Bpm = m_Composition.m_Loop[m_NextLoop].m_LoopBpm;
	m_MaatraBol = m_Composition.m_Loop[m_NextLoop].m_MaatraBol;
	UpdateTempo();
}

void CNaadhDlg::OnTimer(UINT nIDEvent)
{	
	if(!m_IsPlaying) return;

	if(nIDEvent==m_TimerAcc)
	{
		m_WaveBox.Play(m_Tanpura[m_TanpuraSel]);
	}
	else
	{
		PlayLoopSequence();
	}


	//else
	//{
	//	//variation in bols
	//	//series1 0-11 series2 12-23 series3 24-35
	//	int r = /*rand() % */m_BolVar;
	//	UINT nbol = r + m_BolSeq[m_NextBol];
	//	if(nbol>m_MaxBol) nbol = m_BolSeq[m_NextBol];
	//	//TRACE2("%d, %d\r\n",r,s);

	//	//play it
	//	if(m_BolSeq[m_NextBol] != BOL_SILENCE) m_WaveBox.Play(nbol);

	//	//sam
	//	if(m_SamBeat)
	//	{
	//		if(m_StatusSeq[m_NextBol] == BOL_SAM) m_WaveBox.Play(121);
	//	}

	//	//set next
	//	m_NextBol ++;
	//	if(m_NextBol>=m_BolCount) m_NextBol = 0;

	//	//variation in timer
	//	KillTimer(m_Timer);
	//	r = rand() % m_Rand;//1-100
	//	r = (int)m_Tempo*(r - (int)m_Rand/2)/150;
	//	//TRACE2("%d, %d\r\n",r,m_Rand);
	//	m_Timer = SetTimer(WM_USER+200, m_Tempo + r, NULL);
	//}

	CDialog::OnTimer(nIDEvent);
}

void CNaadhDlg::OnBnClickedButtonStop()
{
	KillTimer(m_Timer);
	m_IsPlaying = FALSE;
	this->SetDlgItemText(IDC_STATIC_MSG, " Stopped ...");
}

void CNaadhDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == (CScrollBar*)&m_TempoSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)||(nSBCode == SB_THUMBTRACK))
		{
			m_BpmDeviation = nPos;
			UpdateTempo();
			//if(nSBCode == SB_THUMBPOSITION) OnBnClickedButtonPlay(); 
		}
	}
	if (pScrollBar == (CScrollBar*)&m_RandSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)||(nSBCode == SB_THUMBTRACK))
		{
			m_Rand = nPos;
			m_Mesg.Format("Timing Variation = %d",nPos);
			this->SetDlgItemText(IDC_EDIT_TEMPOVAR, m_Mesg);
			//if(nSBCode == SB_THUMBPOSITION) OnBnClickedButtonPlay(); 
		}
	}
	if (pScrollBar == (CScrollBar*)&m_BolVarSliderCtrl)
	{
		if((nSBCode == SB_THUMBPOSITION)/*||(nSBCode == SB_THUMBTRACK)*/)
		{
			m_BolVar = nPos;
			
			//create a varient
			if(m_BolVar	> 0) 
			{
				CreateVarient();
				m_List.SetColHeading(2,"Variant");
			}
			else m_List.SetColHeading(2," ");

			m_Mesg.Format("Bol Variation = %d",m_BolVar);
			this->SetDlgItemText(IDC_EDIT_BOLVAR, m_Mesg);
		}
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CNaadhDlg::FormatCells()
{
	bool mark = true;
	UINT m = 1;
	for(int x=0;x<MC;x++)
	{
		for(int r=0;r<MR;r++) 
		{
			if(m_IsCompView) m_List.SetCellBg(x,r,false);
			else m_List.SetCellBg(x,r,mark);
		}
		m++;
		if(m>m_MaatraBol) {m = 1; mark = !mark;}
	}
	m_List.Invalidate();
}

void CNaadhDlg::LoadBolWaves()
{
	CString bolfile[MAXBOLS] = BOLS;
	CString t, alarm;
	int nbol = 0, failed = 0;
	if(m_BolFolder.IsEmpty())
	{
		m_BolFolder = m_AppPath+"Bol";
	}
	
	//check paths validity
	if(GetFileAttributes(m_BolFolder)  == INVALID_FILE_ATTRIBUTES)
	{
		m_IsBolLoaded = FALSE;
		m_BolFolder = "";
		return;
	}

	alarm = m_BolFolder + "\\Acc\\Alarm.wav";

	UINT loadedcount = 0;
	m_WaveBox.wload = 0;	//reset in case another bol folder is loaded
	for(int x=0;x<MAXBOLS;x++)
	{
		for(int y=0;y<MAXBOLVARS;y++)
		{
			t.Format("%02d.wav",y+1);
			t = m_BolFolder + "\\"+bolfile[x]+"\\"+bolfile[x]+t;
			nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));
			if(nbol<0) 
			{
				m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));
				failed++;
			}
			else loadedcount++;
		}
	}

	//check count
	if(loadedcount<1)
	{
		m_IsBolLoaded = FALSE;
		m_BolFolder = "";
		return;
	}

	//load accompaniment waves and other stuff
	t = m_BolFolder + "\\Acc\\Tanpura_SaPa_G.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//121
	m_Tanpura[0] = nbol-1;

	for(int x=0;x<MAXGHUNGRU;x++)
	{
		t.Format("%02d.wav",x+1);
		t = m_BolFolder + "\\Acc\\Ghungru" + t;
		nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));
		if(nbol<0) 
		{
			nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));
			failed++;
		}
		m_Ghungru[x] = nbol-1;
	}

	t = m_BolFolder + "\\Acc\\Intro.wav";
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(t));//128
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));//129
	nbol = m_WaveBox.Load((TCHAR*)(LPCSTR)(alarm));//130

	//m_Acc = 121-1;
	m_IsBolLoaded = TRUE;
}

void CNaadhDlg::OnBnClickedCheckAcc()
{
	if(this->IsDlgButtonChecked(IDC_CHECK_ACC))
	{
		m_TimerAcc = SetTimer(WM_USER+201, 7880, NULL);
		m_WaveBox.Play(m_Tanpura[m_TanpuraSel]);//dont wait till it starts
	}
	else KillTimer(m_TimerAcc);
}

void CNaadhDlg::OnBnClickedCheckRndbol()
{
}

void CNaadhDlg::OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu)
{
	CDialog::OnMenuSelect(nItemID, nFlags, hSysMenu);

	UINT id = 0;
	if((nItemID>=ID_NA_NA01)&&(nItemID<=ID_KE_KE10))
	{
		if(!m_IsBolLoaded)
		{
			OnOptionsBolfolder();
			return;
		}
		m_WaveBox.Play(nItemID - ID_NA_NA01);
	}

	if(nItemID==ID_ACCOMPANIMENT_TANPURA)
	{
		id = m_Tanpura[0] + nItemID - ID_ACCOMPANIMENT_TANPURA;
		if(id<=m_Tanpura[MAXTANPURA-1]) m_WaveBox.Play(id);
	}

	if((nItemID>=ID_GHUNGRU_GHUNGRU01)&&(nItemID<=ID_GHUNGRU_GHUNGRU06))
	{
		id = m_Ghungru[0]+ nItemID - ID_GHUNGRU_GHUNGRU01;
		if(id<=m_Ghungru[MAXGHUNGRU-1]) m_WaveBox.Play(id);
	}
}

void CNaadhDlg::OnOptionsPlayallsamples()
{
	if(!m_IsBolLoaded)
	{
		OnOptionsBolfolder();
		return;
	}

	for(UINT x=0;x<m_WaveBox.wload;x++)
	{
		m_WaveBox.Play(x);
		Sleep(200);
	}
}

void CNaadhDlg::OnSelectBol(UINT nID)
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);

	if(nbol == BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].AddBol();
		nbol = m_Composition.m_Loop[m_ActiveLoop/*m_Composition.m_LoopCount-1*/].m_BolCount-1;
	}

	m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolType(nID-ID_NA_NA01, m_List.m_selcol, m_List.m_selrow);

	DisplayBol(m_ActiveLoop, nbol);
}

void CNaadhDlg::OnBolsClear32792()
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);
	if(nbol != BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].DeleteBol(nbol);
		m_List.SetCellText(m_List.m_selcol, m_List.m_selrow, " ");
		m_List.SetColHeading(3, m_Composition.m_Loop[m_ActiveLoop].GetMatraCount());
	}
}

void CNaadhDlg::OnBolsSilence()
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);

	if(nbol == BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].AddBol();
		nbol = m_Composition.m_Loop[m_ActiveLoop/*m_Composition.m_LoopCount-1*/].m_BolCount-1;
	}

	m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolType(BOL_SILENCE, m_List.m_selcol, m_List.m_selrow);

	DisplayBol(m_ActiveLoop, nbol);
}

void CNaadhDlg::OnBolsSam()
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);
	if(nbol != BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolStatus(BOL_SAM);
		DisplayBol(m_ActiveLoop, nbol);
	}
}

void CNaadhDlg::OnBolsTali()
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);
	if(nbol != BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolStatus(BOL_TALI);
		DisplayBol(m_ActiveLoop, nbol);
	}
}

void CNaadhDlg::OnBolsKhali()
{
	UINT nbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(m_List.m_selcol, m_List.m_selrow);
	if(nbol != BOL_NONE) 
	{
		m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolStatus(BOL_KHALI);
		DisplayBol(m_ActiveLoop, nbol);
	}
}

void CNaadhDlg::OnBnClickedCheckSam()
{
	m_SamBeat = this->IsDlgButtonChecked(IDC_CHECK_SAM);	
}


CString strTmpPath;

int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	TCHAR szDir[MAX_PATH];
	switch(uMsg){
	case BFFM_INITIALIZED:
		if (lpData){
			strcpy_s(szDir, strTmpPath.GetBuffer(strTmpPath.GetLength()));
			SendMessage(hwnd,BFFM_SETSELECTION,TRUE,(LPARAM)szDir);
		}
		break;
	case BFFM_SELCHANGED: {
	   if (SHGetPathFromIDList((LPITEMIDLIST) lParam ,szDir)){
		  SendMessage(hwnd,BFFM_SETSTATUSTEXT,0,(LPARAM)szDir);
	   }
	   break;
	}
	default:
	   break;
	}
         
	return 0;
}

BOOL GetFolder(CString* strSelectedFolder,
				   const char* lpszTitle,
				   const HWND hwndOwner, 
				   const char* strRootFolder, 
				   const char* strStartFolder)
{
	char pszDisplayName[MAX_PATH];
	LPITEMIDLIST lpID;
	BROWSEINFOA bi;
	
	bi.hwndOwner = hwndOwner;
	if (strRootFolder == NULL){
		bi.pidlRoot = NULL;
	}else{
	   LPITEMIDLIST  pIdl = NULL;
	   IShellFolder* pDesktopFolder;
	   char          szPath[MAX_PATH];
	   OLECHAR       olePath[MAX_PATH];
	   ULONG         chEaten;
	   ULONG         dwAttributes;

	   strcpy_s(szPath, (LPCTSTR)strRootFolder);
	   if (SUCCEEDED(SHGetDesktopFolder(&pDesktopFolder)))
	   {
		   MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szPath, -1, olePath, MAX_PATH);
		   pDesktopFolder->ParseDisplayName(NULL, NULL, olePath, &chEaten, &pIdl, &dwAttributes);
		   pDesktopFolder->Release();
	   }
	   bi.pidlRoot = pIdl;
	}
	bi.pszDisplayName = pszDisplayName;
	bi.lpszTitle = lpszTitle;
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT;
	bi.lpfn = BrowseCallbackProc;
	if (strStartFolder == NULL){
		bi.lParam = FALSE;
	}else{
		strTmpPath.Format("%s", strStartFolder);
		bi.lParam = TRUE;
	}
	bi.iImage = NULL;
	lpID = SHBrowseForFolderA(&bi);
	if (lpID != NULL){
		BOOL b = SHGetPathFromIDList(lpID, pszDisplayName);
		if (b == TRUE){
			strSelectedFolder->Format("%s",pszDisplayName);
			return TRUE;
		}
	}else{
		strSelectedFolder->Empty();
	}
	return FALSE;
}

void CNaadhDlg::OnOptionsBolfolder()
{
	if(m_IsPlaying) OnBnClickedButtonStop();

	//check current folder
	CString t;
	if(m_BolFolder.IsEmpty()) t = "Bol Samples were not loaded.\r\nUsually the samples are included with this program in a folder named Bol. If you have moved the program or misplaced this folder you can specify its path.\r\nDo you wish to specify the Bol folder now ?";
	else t = "Current Bol Folder is : " + m_BolFolder + "\r\n\r\nYou can play your own sample collection in Naad as long as you keep the folder structure and filenames like those in original Bol folder. Or if you are using some other Bol folder you can specify the original one again.\r\n\r\nDo you wish to specify another folder ?";
	if(IDNO==AfxMessageBox(t, MB_YESNO)) return;

	CString oldpath = m_BolFolder;
	if (GetFolder(&m_BolFolder, "Select the Folder where your Bol Sample files are ....", this->m_hWnd, NULL, NULL))
	{
		if (!m_BolFolder.IsEmpty())
		{
			LoadBolWaves();
			SaveSettings();
		}
	}
	else m_BolFolder = oldpath;
}

void CNaadhDlg::OnHelpContact()
{
	CString str;
	str.Format("%.1f", (float)VERSION/10.0);
	str = "mailto:urmila57@gmail.com? subject=Naad & body=I wish to report following problem/bug/feature request:%0A%0ANaad version: " + str + "%0A%0ADated: " + VERMONTH + " Beta%0A%0ADescription: %0A%0A%0A%0A%0A%0AThanks.%0A%0A%0A%0AName:%0A%0ALocation:%0A%0A" ;
	ShellExecute(NULL, "open", str, NULL , NULL, SW_SHOWNORMAL);
}

void CNaadhDlg::OnHelpNaadhhelp()
{
	ShellExecute(0,"open",m_AppPath + "NaadHelp\\HelpIndex.htm",0,0,SW_SHOWNORMAL); 
}

void CNaadhDlg::SaveSettings()
{
	if(m_AppPath.IsEmpty()) return;

	CFile SettFile;
	BOOL m_IsSettFileOpen = SettFile.Open( m_AppPath + "\\NaadSettings.set", CFile::modeCreate | CFile::modeWrite );
	if(!m_IsSettFileOpen) {return;}

	CArchive archive(&SettFile, CArchive::store);
	archive << VERSION << FILETYPE_SETT << m_IsInstalled << m_BolFolder;

	archive.Close();
	SettFile.Close();
}

void CNaadhDlg::LoadSettings()
{
	if(m_AppPath.IsEmpty()) return;

	CFile SettFile;
	BOOL m_IsSettFileOpen = SettFile.Open( m_AppPath + "\\NaadSettings.set", CFile::modeRead );
	if(!m_IsSettFileOpen) {return;}
	CArchive archive(&SettFile, CArchive::load);

	int ver, type;
	archive >> ver >> type;
	
	if(type != FILETYPE_SETT) return;

	if(ver == VERSION)
	{
		archive >> m_IsInstalled >> m_BolFolder;
	}

	archive.Close();
	SettFile.Close();

}


void CNaadhDlg::AssociateFileType(CString ext, CString app, CString id, CString desc, CString icon)
{
	//CreateRegistryKey   HKEY_CLASSES_ROOT\Extension
	DWORD dwDisposition;
	HKEY hKey, hKey2;

	LONG res = RegCreateKeyEx(HKEY_CLASSES_ROOT, ext, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key ext");

	//SetRegistryValue of HKEY_CLASSES_ROOT\Extension, _use default value, value= Identifier
	res = RegSetValueEx(hKey, "", 0, REG_SZ, reinterpret_cast<BYTE *>((LPSTR)(LPCSTR)id), id.GetLength() +1);
	if(res != ERROR_SUCCESS) return;

	//CreateRegistryKey HKEY_CLASSES_ROOT\Identifier
	res = RegCreateKeyEx(HKEY_CLASSES_ROOT, id, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key id");
	//SetRegistryValue  HKEY_CLASSES_ROOT, Identifier, "", _REG_SZ, Description
	res = RegSetValueEx(hKey, "", 0, REG_SZ, reinterpret_cast<BYTE *>((LPSTR)(LPCSTR)desc), desc.GetLength() +1);
	if(res != ERROR_SUCCESS) return;

	//CreateRegistryKey HKEY_CLASSES_ROOT\Identifier\DefaultIcon
	res = RegCreateKeyEx(hKey, "DefaultIcon", 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey2, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key id");
	//SetRegistryValue  of HKEY_CLASSES_ROOT\Identifier\DefaultIcon, _use default value,value= Icon
	res = RegSetValueEx(hKey2, "", 0, REG_SZ, reinterpret_cast<BYTE *>((LPSTR)(LPCSTR)icon), icon.GetLength() +1);
	if(res != ERROR_SUCCESS) return;

	//Identifier = Identifier + "\shell"
	id = id + "\\shell";
	//CreateRegistryKey HKEY_CLASSES_ROOT\Identifier
	res = RegCreateKeyEx(HKEY_CLASSES_ROOT, id, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key id");

	//Identifier = Identifier + "\open"
	id = id + "\\open";
	//CreateRegistryKey HKEY_CLASSES_ROOT\Identifier
	res = RegCreateKeyEx(HKEY_CLASSES_ROOT, id, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key id");

	//Identifier = Identifier + "\command"
	id = id + "\\command";
	//CreateRegistryKey HKEY_CLASSES_ROOT\Identifier
	res = RegCreateKeyEx(HKEY_CLASSES_ROOT, id, 0, 0, REG_OPTION_NON_VOLATILE, KEY_WRITE, 0, &hKey, &dwDisposition);
	if(res != ERROR_SUCCESS) return;
	if(dwDisposition == REG_OPENED_EXISTING_KEY) TRACE("Opened key id");
	//SetRegistryValue  of HKEY_CLASSES_ROOT\Identifier, _use default value,value= ("Application" "%1")
	app = "\""+app+"\" \"%1\"";
	res = RegSetValueEx(hKey, "", 0, REG_SZ, reinterpret_cast<BYTE *>((LPSTR)(LPCSTR)app), app.GetLength() +1);
	if(res != ERROR_SUCCESS) return;

}

void CNaadhDlg::OnFileNewcomposition()
{
	if(!m_Saved)
	{
		int ex = AfxMessageBox("Do you wish to save this composition before creating a new one ??",MB_YESNOCANCEL | MB_ICONQUESTION);
		if( ex == IDCANCEL)	return;
		if( ex == IDYES)	OnFileSave32774();
	}
	if(m_IsPlaying) OnBnClickedButtonStop();
	m_NaadhFileName = "";

	//clean up previous composition
	UINT lastcount = m_Composition.m_LoopCount;
	for(UINT x=0; x<lastcount; x++)
	{
		m_Composition.DeleteLoop(0);
	}
	Reset();

	m_Composition.AddLoop(0,0);
	m_Composition.m_Notes = "\r\n\r\nCreated using :\r\n" + m_Mesg;
	DisplayComposition();

	//m_List.SetColHeading(0,"New Composition");
	this->SetDlgItemText(IDC_STATIC_FILE, " New Composition");
	m_Saved = true;
}

void CNaadhDlg::DisplayBol(UINT nloop, UINT nbol)
{
	COLORREF color;
	if(m_Composition.m_Loop[nloop].m_Bol[nbol].m_Species < 5) color = TXTRED;
	else color = TXTBLUE;

	m_List.SetCellText(
		m_Composition.m_Loop[nloop].m_Bol[nbol].m_Col,
		m_Composition.m_Loop[nloop].m_Bol[nbol].m_Row,
		m_Composition.m_Loop[nloop].m_Bol[nbol].m_BolName + " " +
		m_Composition.m_Loop[nloop].m_Bol[nbol].m_BolStatusName, 1, color);
	
	m_List.SetColHeading(3, m_Composition.m_Loop[nloop].GetMatraCount());
	m_Saved = false;
}

void CNaadhDlg::DisplayLoop(UINT nloop)
{
	if(nloop == LOOP_NONE) return;

	ClearDisplay();

	for(UINT x=0;x<m_Composition.m_Loop[nloop].m_BolCount;x++)
	{
		DisplayBol(nloop, x);
	}
	m_MaatraBol = m_Composition.m_Loop[nloop].m_MaatraBol;
	m_List.SetColHeading(1, m_Composition.m_Loop[nloop].m_LoopName);
	m_List.SetColHeading(3, m_Composition.m_Loop[nloop].GetMatraCount());
	UpdateTempo();
	FormatCells();
}

void CNaadhDlg::OnLoopOpen()
{
	UINT nloop = m_Composition.GetLoop(m_List.m_selcol, m_List.m_selrow);
	if(nloop == LOOP_NONE)
	{
		m_Composition.AddLoop(m_List.m_selcol, m_List.m_selrow);
		nloop = m_Composition.m_LoopCount-1;
		//m_Composition.m_Loop[nloop].m_Col = m_List.m_selcol;
		//m_Composition.m_Loop[nloop].m_Row = m_List.m_selrow;
	}
	m_IsCompView = FALSE;
	m_ActiveLoop = nloop;
	ClearDisplay();
	DisplayLoop(nloop);
}

void CNaadhDlg::OnViewComposition()
{
	m_Composition.DoCompositionPropDlg();
	m_Saved = FALSE;
	DisplayComposition();
}

void CNaadhDlg::DisplayComposition()
{
	ClearDisplay();

	CString t;
	for(UINT x=0;x<m_Composition.m_LoopCount;x++)
	{
		t.Format("  x%d",m_Composition.m_Loop[x].m_RepeatCount);
		m_List.SetCellText(m_Composition.m_Loop[x].m_Col, m_Composition.m_Loop[x].m_Row, m_Composition.m_Loop[x].m_LoopName + t, 1, TXTGREEN); 
		//TRACE( m_Composition.m_Loop[x].m_LoopName+"\r\n");
	}

	m_List.SetColHeading(0,m_Composition.m_CompositionName);
	m_List.SetColHeading(1," ");
	m_List.SetColHeading(2," ");
	m_List.SetColHeading(3," ");
	m_IsCompView = TRUE;
	m_ActiveLoop = LOOP_NONE;
	FormatCells();

}

void CNaadhDlg::OnLoopClear()
{
	UINT nloop = 0;
	nloop = m_Composition.GetLoop(m_List.m_selcol, m_List.m_selrow);

	m_Composition.DeleteLoop(nloop);
	DisplayComposition();
}

void CNaadhDlg::OnBolsViewcomp()
{
	DisplayComposition();
}

void CNaadhDlg::OnLoopProperties()
{
	UINT nloop = 0;
	nloop = m_Composition.GetLoop(m_List.m_selcol, m_List.m_selrow);
	if(nloop == LOOP_NONE) return;

	m_Composition.DoLoopPropDlg(nloop);
	m_Saved = FALSE;
	DisplayComposition();
}

void CNaadhDlg::OnViewLoop()
{
	if(m_ActiveLoop == LOOP_NONE) 
	{
		AfxMessageBox("Please open a loop to see its properties");
		return;
	}
	if(m_IsPlaying) OnBnClickedButtonStop();
	m_Composition.DoLoopPropDlg(m_ActiveLoop);
	m_Saved = FALSE;
	DisplayLoop(m_ActiveLoop);
}

void CNaadhDlg::OnBnClickedCheckEcho()
{
	//if(this->IsDlgButtonChecked(IDC_CHECK_ECHO))
	//{
	//	m_Echo = 50;
	//}
	//else m_Echo = 0;
}


void CNaadhDlg::OnBnClickedOk()
{
	OnFileExit();
}


void CNaadhDlg::OnGhungruGhungru01()
{
	m_GhungruSel = 0;
}


void CNaadhDlg::OnGhungruGhungru02()
{
	m_GhungruSel = 1;
}


void CNaadhDlg::OnGhungruGhungru03()
{
	m_GhungruSel = 2;
}


void CNaadhDlg::OnGhungruGhungru04()
{
	m_GhungruSel = 3;
}


void CNaadhDlg::OnGhungruGhungru05()
{
	m_GhungruSel = 4;
}


void CNaadhDlg::OnGhungruGhungru06()
{
	//m_GhungruSel = 5;
}


void CNaadhDlg::OnAccompanimentTanpura()
{
	m_TanpuraSel = 0;
}


void CNaadhDlg::OnAccompaniment2()
{
	//m_TanpuraSel = 1;
}


void CNaadhDlg::OnAccompaniment3()
{
	//m_TanpuraSel = 2;
}


void CNaadhDlg::OnAccompaniment4()
{
	//m_TanpuraSel = 3;
}


void CNaadhDlg::OnBnClickedCheckVarsame()
{
	m_VarietySameSpecies = this->IsDlgButtonChecked(IDC_CHECK_VARSAME);
	m_VarietyAnySpecies = !m_VarietySameSpecies;
	this->CheckDlgButton(IDC_CHECK_VARANY, m_VarietyAnySpecies);
	//reset to original varient
	ResetVarient(); 
}


void CNaadhDlg::OnBnClickedCheckVarany()
{
	m_VarietyAnySpecies = this->IsDlgButtonChecked(IDC_CHECK_VARANY);
	m_VarietySameSpecies = !m_VarietyAnySpecies;
	this->CheckDlgButton(IDC_CHECK_VARSAME, m_VarietySameSpecies);
	//reset to original varient
	ResetVarient(); 
}

UINT CNaadhDlg::GetBolVarient(UINT nbol)
{
	if((nbol == BOL_SILENCE)||(nbol == BOL_NONE)) return nbol;

	UINT r = 0, vbol = nbol, maxany = MAXBOLS*MAXBOLVARS, species = nbol/MAXBOLVARS;

	if(m_VarietyAnySpecies)
	{
		r = rand() % (1+(maxany*m_BolVar/100));
		vbol = nbol + r;
		if(vbol >= maxany) vbol = vbol - maxany; //wrap
	}

	if(m_VarietySameSpecies)
	{
		r = rand() % (1+(MAXBOLVARS*m_BolVar/100));
		vbol = nbol + r;
		if(vbol >= (species*MAXBOLVARS+MAXBOLVARS)) vbol = vbol - MAXBOLVARS; //wrap
	}

	return vbol;
}

void CNaadhDlg::OnBnClickedButtonSavevar()
{
	int res = AfxMessageBox("Do you wish to save the original before replacing it with this variation ?", MB_YESNOCANCEL);
	if(res == IDCANCEL) return;
	if(res == IDYES) OnFileSaveas();

	//replace
	UINT nseq = 0;
	for(UINT x=0; x<m_Composition.m_LoopCount; x++)
	{
		for(UINT y=0; y<m_Composition.m_Loop[x].m_BolCount; y++)
		{
			m_Composition.m_Loop[x].m_Bol[y].SetBolType(m_Sequence[x].m_BolVarSeq[y]);
		}
	}

	if(m_ActiveLoop != LOOP_NONE) DisplayLoop(m_ActiveLoop);
	else DisplayComposition();

	m_Mesg = "Replaced Bol Variations";
	this->SetDlgItemText(IDC_STATIC_MSG, m_Mesg);

}


void CNaadhDlg::OnBnClickedCheckVarcomp()
{
	m_VarietyComp = this->IsDlgButtonChecked(IDC_CHECK_VARCOMP);
	m_VarietyLoop = !m_VarietyComp;
	this->CheckDlgButton(IDC_CHECK_VARLOOP, m_VarietyLoop);
	//reset to original varient
	ResetVarient(); 
}


void CNaadhDlg::OnBnClickedCheckVarloop()
{
	m_VarietyLoop = this->IsDlgButtonChecked(IDC_CHECK_VARLOOP);
	m_VarietyComp = !m_VarietyLoop;
	this->CheckDlgButton(IDC_CHECK_VARCOMP, m_VarietyComp);
	//reset to original varient
	ResetVarient(); 
}

void CNaadhDlg::ResetVarient()
{
	m_BolVar = 0;
	m_List.SetColHeading(2," ");
	m_BolVarSliderCtrl.SetPos(m_BolVar);
	this->SetDlgItemText(IDC_EDIT_BOLVAR, "");
}

void CNaadhDlg::CreateVarient()
{	
	if(!m_IsPlaying) return;

	if(m_BolVar > (UINT)m_BolVarSliderCtrl.GetRangeMax())
	{
		this->OnBnClickedButtonStop();
		AfxMessageBox("Bol variance is out of range");
		return;
	}

	if(m_VarietyLoop)
	{
		if(m_ActiveLoop != LOOP_NONE)
		{
			for(UINT y=0; y<m_Composition.m_Loop[m_ActiveLoop].m_BolCount; y++)
			{
				m_Sequence[m_ActiveLoop].m_BolVarSeq[y] = GetBolVarient(m_Sequence[m_ActiveLoop].m_BolIdSeq[y]);
			}
		}
	}

	if(m_VarietyComp)
	{
		for(UINT x=0; x<m_Composition.m_LoopCount; x++)
		{
			for(UINT y=0; y<m_Composition.m_Loop[x].m_BolCount; y++)
			{
				m_Sequence[x].m_BolVarSeq[y] = GetBolVarient(m_Sequence[x].m_BolIdSeq[y]);
			}
		}
	}

}

void CNaadhDlg::OnBnClickedButtonAutocompose()
{
	//init
	OnFileNewcomposition();
	m_Composition.DeleteLoop(0); //clean it

	m_Composition.AutoCompose();

	//done
	DisplayComposition();
}

void CNaadhDlg::UpdateTempo()
{
	int bpm = m_Bpm + m_BpmDeviation + m_BpmRand;
	if(bpm<0) bpm = 1;
	m_Tempo = 60000/(bpm * m_MaatraBol);

	KillTimer(m_Timer);
	m_Timer = SetTimer(WM_USER+200, m_Tempo, NULL);

	m_Mesg.Format("Loop = %d Bpm, Deviation = %+d\r\nEffective = %d Beats/minute\r\nBol duration = %d ms", m_Bpm, m_BpmDeviation + m_BpmRand, bpm, m_Tempo);
	this->SetDlgItemText(IDC_EDIT_TEMPO, m_Mesg);
}

void CNaadhDlg::OnBnClickedButtonPlayloop()
{
	if(m_ActiveLoop == LOOP_NONE) return;
	m_PlayLoop = TRUE;
	//m_NextLoop = m_ActiveLoop;
	InitPlay();
}

void CNaadhDlg::InitPlay()
{
	if(m_IsPlaying) OnBnClickedButtonStop();
	if(m_Composition.m_LoopCount<1) return;
	if(!m_IsBolLoaded)
	{
		OnOptionsBolfolder();
		return;
	}

	if(!CreateLoopSequence())
	{
		if(m_TotalLoops > 0) AfxMessageBox("Loop sequence creation Failed");
		return;
	}
	
	m_SeqNum	= 0;
	m_NextLoop	= m_LoopSequence[m_SeqNum];
	if(m_PlayLoop)	m_NextLoop	= m_ActiveLoop;
	m_NextBol	= 0;
	m_IsPlaying = TRUE;
	m_LoopDone	= FALSE;

	//seed rand
	CTime time = CTime::GetCurrentTime();
	srand(time.GetSecond());

	//no varient
	ResetVarient();
	
	//start timer
	SetLoopBpm();
	
	this->SetDlgItemText(IDC_STATIC_MSG, " Playing ...");
}


void CNaadhDlg::OnBnClickedButtonGun1()
{
	m_Gun++;
	if(m_Gun >  4) m_Gun = -3;
	if(m_Gun == 0) m_Gun =  1;

	CString t;
	if(m_Gun>0) 
	{
		m_BpmDeviation = m_Bpm * (m_Gun - 1);
		t.Format("%d X", m_Gun);
	}
	else 
	{
		m_BpmDeviation = ((int)m_Bpm/(1-m_Gun)) - (int)m_Bpm;
		t.Format("1/%d X", 1-m_Gun);
	}

	UpdateTempo();

	this->SetDlgItemTextA(IDC_BUTTON_GUN1,t);
	m_TempoSliderCtrl.SetPos(m_BpmDeviation);
}


void CNaadhDlg::OpenLoopOldVer(CString loopfilename)
{
	CFile naadhfile;
	if(!naadhfile.Open(loopfilename, CFile::modeRead))
	{
		AfxMessageBox("Error : Failed to open the nlp file");
		return;
	}
	CArchive arch(&naadhfile, CArchive::load);

	//ver
	UINT ver = 0, type = 0, bolcount = 0;
	arch >> ver;

	if(ver == 1)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is of a version that is no longer supported");
		return;
	}

	if(ver == 2)
	{
		UINT futureuint	= 0, mcols = 0, mrows = 0, matrabol, mtaal[24][24], mstat[24][24], bolcount = 0, nloop;
		CString futurestr;
		BOOL futurebool	= false;

		arch >> mcols >> mrows >> matrabol;
		if(matrabol<1) matrabol = 1;

		m_Composition.AddLoop(m_List.m_selcol,m_List.m_selrow);
		nloop = m_Composition.m_LoopCount-1;
	
		//loop
		loopfilename.Replace(".nad","");
		CString filetitle = loopfilename;
		filetitle.Delete(0,loopfilename.ReverseFind('\\')+1);
		m_Composition.m_Loop[nloop].m_Note = "Converted from Naad Version 0.2 file :\r\n" + filetitle + ".nad";
		m_Composition.m_Loop[nloop].m_LoopName = filetitle;
		m_Composition.m_Loop[nloop].m_MaatraBol	= matrabol;

		for(int x=0;x<MAXRESRV-1;x++) arch >> futureuint;
		for(int x=0;x<MAXRESRV;x++) arch >> futurestr;
		for(int x=0;x<MAXRESRV;x++) arch >> futurebool;

		for(int x=0;x<24;x++)
		{
			for(int y=0;y<24;y++)
			{
				arch >> mtaal[x][y];
				arch >> mstat[x][y];
				if(mtaal[x][y] != BOL_NONE)
				{
					m_Composition.m_Loop[nloop].AddBol();
					m_Composition.m_Loop[nloop].m_Bol[bolcount].SetBolType(mtaal[x][y], y, x);
					m_Composition.m_Loop[nloop].m_Bol[bolcount].SetBolStatus(mstat[x][y]);
					bolcount ++;
				}
			}
		}
	}

	arch.Close();
	naadhfile.Close();
	DisplayComposition();

	m_Mesg = "  Loop Loaded ...  " + loopfilename;
	this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
}

void CNaadhDlg::OnLoopLoadloop()
{
	UINT nloop = m_Composition.GetLoop(m_List.m_selcol,m_List.m_selrow);
	if(nloop != LOOP_NONE)
	{
		if(IDNO == AfxMessageBox("Do you wish to overwrite the existing loop ?", MB_YESNO)) return;
		m_Composition.DeleteLoop(nloop);
	}

	CString loopfilename;
	CFileDialog ResFileOpenDialog(true,"nlp","",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Naad Loop Files (*.nlp)|*.nlp|All Files (*.*)|*.*||");
	ResFileOpenDialog.m_ofn.lpstrInitialDir = m_AppPath + "Loops";
	INT_PTR res = ResFileOpenDialog.DoModal();
	if(res==IDOK) loopfilename = ResFileOpenDialog.GetPathName();
	if(loopfilename.IsEmpty()) return;

	CFile naadhfile;
	if(!naadhfile.Open(loopfilename, CFile::modeRead))
	{
		AfxMessageBox("Error : Failed to open the nlp file");
		return;
	}
	CArchive arch(&naadhfile, CArchive::load);

	//ver
	UINT ver = 0, type = 0, bolcount = 0;
	arch >> ver;

	if(ver < VERSION)
	{
		arch.Close();
		naadhfile.Close();
		OpenLoopOldVer(loopfilename);
		return;
	}

	if(ver > VERSION)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is of a newer version. Please update to the latest version and try again.");
		return;
	}
	
	arch >> type;
	if(type != FILETYPE_LOOP)
	{
		arch.Close();
		naadhfile.Close();
		AfxMessageBox("The file you are trying to open is probably not a Naad loop and cannot be opened");
		return;
	}

	m_Composition.AddLoop(m_List.m_selcol,m_List.m_selrow);
	nloop = m_Composition.m_LoopCount-1;
	
	//loop
	arch 
		>> m_Composition.m_Loop[nloop].m_LoopName
		>> m_Composition.m_Loop[nloop].m_Note
		>> m_Composition.m_Loop[nloop].m_Accompaniment
		>> m_Composition.m_Loop[nloop].m_LoopBpm
		>> m_Composition.m_Loop[nloop].m_MaatraBol
		>> m_Composition.m_Loop[nloop].m_RepeatCount
		>> bolcount;

	for(UINT y=0; y<bolcount; y++)
	{
		m_Composition.m_Loop[nloop].AddBol();
		arch 
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_BolId
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_BolName
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_BolStatusName
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_Col
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_Row
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_Species
			>> m_Composition.m_Loop[nloop].m_Bol[y].m_Status;
	}

	arch.Close();
	naadhfile.Close();
	DisplayComposition();

	m_Mesg = "  Loop Loaded ...  " + loopfilename;
	this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
}


void CNaadhDlg::OnLoopSaveloop()
{
	UINT nloop = m_Composition.GetLoop(m_List.m_selcol,m_List.m_selrow);
	if(nloop == LOOP_NONE) return;

	CString loopfilename;
	CFileDialog ResFileOpenDialog(false,"nlp",m_Composition.m_Loop[nloop].m_LoopName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"Naad Loop Files (*.nlp)|*.nlp|All Files (*.*)|*.*||");
	ResFileOpenDialog.m_ofn.lpstrInitialDir = m_AppPath + "Loops";
	INT_PTR res = ResFileOpenDialog.DoModal();
	if(res==IDOK) loopfilename = ResFileOpenDialog.GetPathName();
	if(loopfilename.IsEmpty()) return;

	CFile naadhfile;
	if(!naadhfile.Open(loopfilename, CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("Error : Failed to create the nlp file");
		return;
	}
	CArchive arch(&naadhfile, CArchive::store);

	//ver
	arch << VERSION << FILETYPE_LOOP;

	//loop
	arch 
		//<< m_Composition.m_Loop[nloop].m_Col
		//<< m_Composition.m_Loop[nloop].m_Row
		<< m_Composition.m_Loop[nloop].m_LoopName
		<< m_Composition.m_Loop[nloop].m_Note
		<< m_Composition.m_Loop[nloop].m_Accompaniment
		<< m_Composition.m_Loop[nloop].m_LoopBpm
		<< m_Composition.m_Loop[nloop].m_MaatraBol
		<< m_Composition.m_Loop[nloop].m_RepeatCount
		<< m_Composition.m_Loop[nloop].m_BolCount;

	for(UINT y=0; y<m_Composition.m_Loop[nloop].m_BolCount; y++)
	{
		arch 
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_BolId
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_BolName
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_BolStatusName
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_Col
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_Row
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_Species
			<< m_Composition.m_Loop[nloop].m_Bol[y].m_Status;
	}

	arch.Close();
	naadhfile.Close();

	m_Mesg = "  Loop Saved ...  " + loopfilename;
	this->SetDlgItemText(IDC_STATIC_FILE, m_Mesg);
}


void CNaadhDlg::OnEditSelect()
{
	m_EditMode = !m_EditMode;
	m_Menu.CheckMenuItem(ID_EDIT_SELECT, (MF_CHECKED * (UINT)m_EditMode) |MF_BYCOMMAND);
	//m_Paste = FALSE;
	if(m_EditMode)
	{
		ClearSelection();
		this->SetDlgItemTextA(IDC_STATIC_MSG, "  Edit Mode");
		m_List.SetColHeading(7,"Edit Mode");
		this->SetDlgItemTextA(IDC_STATIC_FILE, "  Click on cells to select/deselect. Click [Edit->Select] again to cancel edit mode");
	}
	else
	{
		ClearSelection();
		this->SetDlgItemTextA(IDC_STATIC_MSG, "  Compose Mode");
		m_List.SetColHeading(7,"Compose Mode");
		this->SetDlgItemTextA(IDC_STATIC_FILE, "  Ready ...");
	}
}


void CNaadhDlg::OnEditClear32974()
{
	if(m_ActiveLoop != LOOP_NONE)
	{
		for(UINT x=0; x<m_Composition.m_Loop[m_ActiveLoop].m_BolCount ; )
		{
			if(m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_Selected)
			{
				m_Composition.m_Loop[m_ActiveLoop].DeleteBol(x);
				x = 0;
			}
			else x++;
		}

		DisplayLoop(m_ActiveLoop);
	}
	else
	{
		for(UINT x=0; x<m_Composition.m_LoopCount; )
		{
			if(m_Composition.m_Loop[x].m_Selected)
			{
				m_Composition.DeleteLoop(x);
				x = 0;
			}
			else x++;
		}

		DisplayComposition();
	}

	m_Saved = FALSE;
}


void CNaadhDlg::OnEditCopy32956()
{
	m_CompositionCopy.Clear();

	if(m_ActiveLoop != LOOP_NONE)
	{
		m_CompositionCopy.AddLoop(0,0);
		UINT nbol = 0;
		for(UINT x=0; x<m_Composition.m_Loop[m_ActiveLoop].m_BolCount ; x++)
		{
			if(m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_Selected)
			{
				m_CompositionCopy.m_Loop[0].AddBol();
				m_CompositionCopy.m_Loop[0].m_Bol[nbol].SetBolType(	m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_BolId,
																	m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_Col,
																	m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_Row);
				m_CompositionCopy.m_Loop[0].m_Bol[nbol].SetBolStatus(m_Composition.m_Loop[m_ActiveLoop].m_Bol[x].m_Status);
				nbol++;
			}
		}
	}
	else
	{
		UINT nloop = 0;
		for(UINT x=0; x<m_Composition.m_LoopCount; x++ )
		{
			if(m_Composition.m_Loop[x].m_Selected)
			{
				m_CompositionCopy.AddLoop(m_Composition.m_Loop[x].m_Col,m_Composition.m_Loop[x].m_Row);
				m_CompositionCopy.m_Loop[nloop].Clone(m_Composition.m_Loop[x]);
				nloop++;
			}
		}
	}

	NormalizeLocations();
	m_List.m_sel = FALSE;
}

void CNaadhDlg::NormalizeLocations()
{
	UINT mincol = MC, minrow = MR;
	if(m_ActiveLoop != LOOP_NONE)
	{
		for(UINT x=0; x<m_CompositionCopy.m_Loop[0].m_BolCount ; x++)
		{
			if(m_CompositionCopy.m_Loop[0].m_Bol[x].m_Col < mincol) mincol = m_CompositionCopy.m_Loop[0].m_Bol[x].m_Col;
			if(m_CompositionCopy.m_Loop[0].m_Bol[x].m_Row < minrow) minrow = m_CompositionCopy.m_Loop[0].m_Bol[x].m_Row;
		}
		for(UINT x=0; x<m_CompositionCopy.m_Loop[0].m_BolCount ; x++)
		{
			m_CompositionCopy.m_Loop[0].m_Bol[x].m_Col -= mincol;
			m_CompositionCopy.m_Loop[0].m_Bol[x].m_Row -= minrow;
		}

	}
	else
	{
		for(UINT x=0; x<m_CompositionCopy.m_LoopCount; x++ )
		{
			if(m_CompositionCopy.m_Loop[x].m_Col < mincol) mincol = m_CompositionCopy.m_Loop[x].m_Col; 
			if(m_CompositionCopy.m_Loop[x].m_Row < minrow) minrow = m_CompositionCopy.m_Loop[x].m_Row; 
		}
		for(UINT x=0; x<m_CompositionCopy.m_LoopCount ; x++)
		{
			m_CompositionCopy.m_Loop[x].m_Col -= mincol;
			m_CompositionCopy.m_Loop[x].m_Row -= minrow;
		}
	}

}

void CNaadhDlg::OnEditCut32957()
{
	OnEditCopy32956();
	OnEditClear32974();
}

void CNaadhDlg::OnEditPaste32958()
{
	//this->SetDlgItemTextA(IDC_STATIC_FILE, "  Please select an empty cell to paste into.\r\nEnsure that there are enough empty cells around it");
	//ClearSelection();
	//m_Paste = TRUE;
	//m_List.GetCellSelection();
	if(!m_List.m_sel)
	{
		AfxMessageBox("Please select an empty cell to paste into and click [Edit->Paste] on menu.", MB_OK, MB_ICONINFORMATION);
		return;
	}

	Paste(m_List.m_selcol, m_List.m_selrow);
	ClearSelection();
	m_Saved = FALSE;
}

void CNaadhDlg::Paste(UINT col, UINT row)
{
	bool overwritten = false;

	if(m_ActiveLoop != LOOP_NONE)
	{
		UINT nbol = 0;
		for(UINT x=0; x<m_CompositionCopy.m_Loop[0].m_BolCount ; x++)
		{
			UINT newcol = m_CompositionCopy.m_Loop[0].m_Bol[x].m_Col + col;
			UINT newrow = m_CompositionCopy.m_Loop[0].m_Bol[x].m_Row + row;
			
			//check if something is already here
			UINT tbol = m_Composition.m_Loop[m_ActiveLoop].GetBol(newcol, newrow);
			if(tbol == BOL_NONE) //nothing was here
			{
				m_Composition.m_Loop[m_ActiveLoop].AddBol();
				nbol = m_Composition.m_Loop[m_ActiveLoop].m_BolCount - 1;
			}
			else 
			{
				nbol = tbol; //overwrite it
				overwritten = true;
			}

			m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolType(m_CompositionCopy.m_Loop[0].m_Bol[x].m_BolId, newcol, newrow);
			m_Composition.m_Loop[m_ActiveLoop].m_Bol[nbol].SetBolStatus(m_CompositionCopy.m_Loop[0].m_Bol[x].m_Status);
		}

		DisplayLoop(m_ActiveLoop);
	}
	else
	{
		UINT nloop = 0;
		for(UINT x=0; x<m_CompositionCopy.m_LoopCount ; x++)
		{
			UINT newcol = m_CompositionCopy.m_Loop[x].m_Col + col;
			UINT newrow = m_CompositionCopy.m_Loop[x].m_Row + row;

			//check if something is already here
			UINT tloop = m_Composition.GetLoop(newcol, newrow);
			if(tloop == LOOP_NONE) //nothing was here
			{
				m_Composition.AddLoop(0, 0); //temp position
				nloop = m_Composition.m_LoopCount - 1;
			}
			else 
			{
				nloop = tloop; //overwrite it
				overwritten = true;
			}

			m_Composition.m_Loop[nloop].Clone(m_CompositionCopy.m_Loop[x]);
			m_Composition.m_Loop[nloop].m_Col = newcol; 
			m_Composition.m_Loop[nloop].m_Row = newrow; 
		}

		DisplayComposition();
	}
	
	if(overwritten)
	{
		this->SetDlgItemTextA(IDC_STATIC_FILE, "  Some items were overwritten !");
	}
	else
	{
		this->SetDlgItemTextA(IDC_STATIC_FILE, "  Ready...");
	}

}

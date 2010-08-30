// NaadhDlg.h : header file
//

#pragma once
#include "UpdateCheck.h"
#include "multilinelist.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "wavebox.h"


#define MC 24 //max cols
#define MR 24 //max rows


// CNaadhDlg dialog
class CNaadhDlg : public CDialog
{
// Construction
public:
	CNaadhDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_NAADH_DIALOG };

//------------------------------------------------------------------------------------------------------------
	//enum BOLID
	//{
	//	BOL_NONE = 0,
	//	BOL_SILENCE,
	//	BOL_DHA,
	//	BOL_DHIN,
	//	BOL_DHIT,
	//	BOL_DHUN,
	//	BOL_GA,
	//	BOL_GE,
	//	BOL_KE,
	//	BOL_NA,
	//	BOL_TAT,
	//	BOL_TI,
	//	BOL_TIN,
	//	BOL_TUN,
	//	BOL_COUNT
	//};
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
	CMenu			m_Menu, m_BolMenu;
	BOOL			m_Quiet, m_Saved, m_RndBol, m_SamBeat;
	CString			m_Mesg, m_AppPath, m_NaadhFileName, m_BolFileSeq[MC*MR];
	UINT			m_Version, m_Cols, m_Rows, m_Tempo, m_NextBol, m_BolCount, m_Rand, m_MaatraBol, m_BolVar;
	UINT			m_BolSeq[MC*MR], m_Taal[MR][MC], m_Acc, m_MaxBol, m_StatusSeq[MC*MR], m_Status[MR][MC];
	UINT_PTR		m_Timer, m_TimerAcc;
	CMultilineList	m_List;
	CSliderCtrl		m_TempoSliderCtrl, m_RandSliderCtrl, m_BolVarSliderCtrl;
	CComboBox		m_ComboMatra;
    CWaveBox		m_WaveBox/*, m_WaveBox2*/;

//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
	void DisplayTaal(void);
	void DisplayBol(void);
	void ClearTaal(void);
	void LoadBolWaves(void);
//------------------------------------------------------------------------------------------------------------

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnFileExit();
	afx_msg void OnHelpAboutnaadh();
	afx_msg void OnHelpCheckforupdates();
	afx_msg void OnFileOpen32773();
	afx_msg void OnFileSave32774();
	afx_msg void OnFileSaveas();
	afx_msg void OnBolsClear32792();
	//afx_msg void OnDayanNa();
	//afx_msg void OnDayanTat();
	//afx_msg void OnDayanTi();
	//afx_msg void OnDayanTin();
	//afx_msg void OnDayanTun();
	//afx_msg void OnBayanDha();
	//afx_msg void OnBayanDhin();
	//afx_msg void OnBayanDhit();
	//afx_msg void OnBayanDhun();
	//afx_msg void OnBayanGa();
	//afx_msg void OnBayanGe();
	//afx_msg void OnBayanKe();
	afx_msg void OnFileNewtaal();
	afx_msg void OnBnClickedButtonPlay();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBolsSilence();
	afx_msg void OnCbnSelchangeComboMatra();
	afx_msg void OnBnClickedCheckAcc();
	afx_msg void OnBnClickedCheckRndbol();
	afx_msg void OnMenuSelect(UINT nItemID, UINT nFlags, HMENU hSysMenu);
	afx_msg void OnOptionsPlayallsamples();
	afx_msg void OnSelectBol(UINT nID);
	afx_msg void OnBolsSam();
	afx_msg void OnBolsTali();
	afx_msg void OnBolsKhali();
	afx_msg void OnBnClickedCheckSam();
};

/*
 * (C) 2024 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stdafx.h"
#include "mplayerc.h"
#include "SendToFolderDlg.h"

// CSendToFolderDlg dialog

IMPLEMENT_DYNAMIC(CSendToFolderDlg, CMPCThemeDialog)

CSendToFolderDlg::CSendToFolderDlg(const CStringArray& folders, CWnd* pParent /*=nullptr*/)
    : CMPCThemeDialog(CSendToFolderDlg::IDD, pParent)
    , m_folders(folders)
{
}

void CSendToFolderDlg::DoDataExchange(CDataExchange* pDX)
{
    __super::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_SUBFOLDERS, m_list);
}

BOOL CSendToFolderDlg::OnInitDialog()
{
    __super::OnInitDialog();

    for (INT_PTR i = 0; i < m_folders.GetCount(); i++) {
        const CString& fullPath = m_folders[i];
        int slash = fullPath.ReverseFind(_T('\\'));
        CString displayName = (slash >= 0) ? fullPath.Mid(slash + 1) : fullPath;
        int idx = m_list.AddString(displayName);
        m_list.SetItemDataPtr(idx, (void*)(INT_PTR)i);
    }

    return TRUE;
}

void CSendToFolderDlg::OnOK()
{
    int sel = m_list.GetCurSel();
    if (sel == LB_ERR) {
        return;
    }
    INT_PTR folderIdx = (INT_PTR)m_list.GetItemDataPtr(sel);
    m_selectedFolder = m_folders[(int)folderIdx];
    __super::OnOK();
}

void CSendToFolderDlg::OnLbnDblclkList()
{
    OnOK();
}

BEGIN_MESSAGE_MAP(CSendToFolderDlg, CMPCThemeDialog)
    ON_LBN_DBLCLK(IDC_LIST_SUBFOLDERS, OnLbnDblclkList)
END_MESSAGE_MAP()

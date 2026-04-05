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

#pragma once

#include "resource.h"
#include "CMPCThemeDialog.h"
#include "CMPCThemeListBox.h"

// CSendToFolderDlg dialog

class CSendToFolderDlg : public CMPCThemeDialog
{
    DECLARE_DYNAMIC(CSendToFolderDlg)

public:
    CSendToFolderDlg(const CStringArray& folders, CWnd* pParent = nullptr);

    CString m_selectedFolder; // output: full path of chosen folder

    enum { IDD = IDD_SENDTOFOLDER };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    virtual void OnOK();

    DECLARE_MESSAGE_MAP()

    afx_msg void OnLbnDblclkList();

private:
    const CStringArray& m_folders;
    CMPCThemeListBox m_list;
};

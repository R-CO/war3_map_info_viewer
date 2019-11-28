///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WAR3_HERO_SKILL_VIEWER_FRAME_BSE_H__
#define __WAR3_HERO_SKILL_VIEWER_FRAME_BSE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

namespace rco
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class War3HeroSkillViewerFrameBase
	///////////////////////////////////////////////////////////////////////////////
	class War3HeroSkillViewerFrameBase : public wxFrame 
	{
		private:
		
		protected:
			wxPanel* hero_skill_panel_;
			wxTextCtrl* search_hero_text_ctrl_;
			wxListBox* hero_list_box_;
			wxListBox* skill_list_box_;
			wxPanel* skill_info_panel_;
			wxTextCtrl* skill_info_text_ctrl_;
			wxMenuBar* main_frame_menu_bar_;
			wxMenu* file_menu_;
			wxMenu* help_menu_;
			
			// Virtual event handlers, overide them in your derived class
			virtual void SearchHeroTextCtrlOnText( wxCommandEvent& event ) { event.Skip(); }
			virtual void HeroListBoxOnListBox( wxCommandEvent& event ) { event.Skip(); }
			virtual void SkillListBoxOnListBox( wxCommandEvent& event ) { event.Skip(); }
			virtual void OpenFileMenuItemOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
			virtual void Close_menuItem_OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
			virtual void AboutMenuItemOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
			
		
		public:
			
			War3HeroSkillViewerFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Hero Skill Viewer by R-CO"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
			
			~War3HeroSkillViewerFrameBase();
		
	};
	
} // namespace rco

#endif //__WAR3_HERO_SKILL_VIEWER_FRAME_BSE_H__

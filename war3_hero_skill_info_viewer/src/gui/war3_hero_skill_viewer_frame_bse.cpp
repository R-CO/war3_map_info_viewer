///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "war3_hero_skill_viewer_frame_bse.h"

///////////////////////////////////////////////////////////////////////////
using namespace rco;

War3HeroSkillViewerFrameBase::War3HeroSkillViewerFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	hero_skill_panel_ = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	hero_skill_panel_->SetMaxSize( wxSize( 200,-1 ) );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	search_hero_text_ctrl_ = new wxTextCtrl( hero_skill_panel_, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( search_hero_text_ctrl_, 0, wxALL|wxEXPAND, 5 );
	
	hero_list_box_ = new wxListBox( hero_skill_panel_, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	hero_list_box_->SetFont( wxFont( 14, 70, 90, 90, false, wxT("標楷體") ) );
	hero_list_box_->SetForegroundColour( wxColour( 255, 255, 255 ) );
	hero_list_box_->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer3->Add( hero_list_box_, 1, wxALL|wxEXPAND, 5 );
	
	skill_list_box_ = new wxListBox( hero_skill_panel_, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL|wxLB_NEEDED_SB|wxLB_SINGLE ); 
	skill_list_box_->SetFont( wxFont( 14, 70, 90, 90, false, wxT("標楷體") ) );
	skill_list_box_->SetForegroundColour( wxColour( 255, 255, 255 ) );
	skill_list_box_->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	skill_list_box_->SetMinSize( wxSize( -1,150 ) );
	
	bSizer3->Add( skill_list_box_, 0, wxALL|wxEXPAND, 5 );
	
	
	hero_skill_panel_->SetSizer( bSizer3 );
	hero_skill_panel_->Layout();
	bSizer3->Fit( hero_skill_panel_ );
	bSizer1->Add( hero_skill_panel_, 0, wxEXPAND | wxALL, 0 );
	
	skill_info_panel_ = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	skill_info_text_ctrl_ = new wxTextCtrl( skill_info_panel_, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	skill_info_text_ctrl_->SetFont( wxFont( 14, 70, 90, 90, false, wxT("標楷體") ) );
	skill_info_text_ctrl_->SetForegroundColour( wxColour( 255, 255, 255 ) );
	skill_info_text_ctrl_->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer4->Add( skill_info_text_ctrl_, 1, wxALL|wxEXPAND, 5 );
	
	
	skill_info_panel_->SetSizer( bSizer4 );
	skill_info_panel_->Layout();
	bSizer4->Fit( skill_info_panel_ );
	bSizer1->Add( skill_info_panel_, 1, wxEXPAND | wxALL, 0 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	main_frame_menu_bar_ = new wxMenuBar( 0 );
	file_menu_ = new wxMenu();
	wxMenuItem* open_file_menu_item_;
	open_file_menu_item_ = new wxMenuItem( file_menu_, wxID_ANY, wxString( wxT("&Open...") ) + wxT('\t') + wxT("Ctrl+O"), wxEmptyString, wxITEM_NORMAL );
	file_menu_->Append( open_file_menu_item_ );
	
	file_menu_->AppendSeparator();
	
	wxMenuItem* close_menu_item_;
	close_menu_item_ = new wxMenuItem( file_menu_, wxID_ANY, wxString( wxT("&Close") ) + wxT('\t') + wxT("Alt-F4"), wxEmptyString, wxITEM_NORMAL );
	file_menu_->Append( close_menu_item_ );
	
	main_frame_menu_bar_->Append( file_menu_, wxT("&File") ); 
	
	help_menu_ = new wxMenu();
	wxMenuItem* about_menu_item_;
	about_menu_item_ = new wxMenuItem( help_menu_, wxID_ANY, wxString( wxT("&About...") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	help_menu_->Append( about_menu_item_ );
	
	main_frame_menu_bar_->Append( help_menu_, wxT("&Help") ); 
	
	this->SetMenuBar( main_frame_menu_bar_ );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	search_hero_text_ctrl_->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::SearchHeroTextCtrlOnText ), NULL, this );
	hero_list_box_->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::HeroListBoxOnListBox ), NULL, this );
	skill_list_box_->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::SkillListBoxOnListBox ), NULL, this );
	this->Connect( open_file_menu_item_->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::OpenFileMenuItemOnMenuSelection ) );
	this->Connect( close_menu_item_->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::Close_menuItem_OnMenuSelection ) );
	this->Connect( about_menu_item_->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::AboutMenuItemOnMenuSelection ) );
}

War3HeroSkillViewerFrameBase::~War3HeroSkillViewerFrameBase()
{
	// Disconnect Events
	search_hero_text_ctrl_->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::SearchHeroTextCtrlOnText ), NULL, this );
	hero_list_box_->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::HeroListBoxOnListBox ), NULL, this );
	skill_list_box_->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::SkillListBoxOnListBox ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::OpenFileMenuItemOnMenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::Close_menuItem_OnMenuSelection ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( War3HeroSkillViewerFrameBase::AboutMenuItemOnMenuSelection ) );
	
}

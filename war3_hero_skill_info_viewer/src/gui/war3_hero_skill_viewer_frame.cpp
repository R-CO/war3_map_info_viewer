#include "war3_hero_skill_viewer_frame.h"

#include <wx/msgdlg.h>
#include <wx/filedlg.h>

namespace rco
{

War3HeroSkillViewerFrame::War3HeroSkillViewerFrame(wxWindow* parent)
  :
  War3HeroSkillViewerFrameBase(parent)
{
  if (!ParseHeroSkillListFile(L"hero_skill_list.txt")) {
    wxMessageBox(_("Can not load [hero_skill_list.txt]."));
  }

  CreateHeroInfoMap();
  FillHeroListBox();
}

bool War3HeroSkillViewerFrame::ParseHeroSkillListFile(const std::wstring & file_name)
{
  hero_skill_list_ini_.SetUnicode();
  if (hero_skill_list_ini_.LoadFile(file_name.c_str()) != SI_Error::SI_OK) {
    return false;
  }

  return true;
}

void War3HeroSkillViewerFrame::CreateHeroInfoMap()
{
  CSimpleIni::TNamesDepend all_sections;
  hero_skill_list_ini_.GetAllSections(all_sections);
  for (const auto &section : all_sections) {
    HeroInfo hero_info;
    CSimpleIni::TNamesDepend all_keys;
    hero_info.name = section.pItem;
    hero_skill_list_ini_.GetAllKeys(section.pItem, all_keys);
    for (const auto &key : all_keys) {
      SkillInfo skill_info;
      skill_info.name = key.pItem;
      skill_info.research_uber_tip = hero_skill_list_ini_.GetValue(section.pItem, key.pItem, L"EMPTY!");
      hero_info.skill_info_vector.push_back(skill_info);
    }
    hero_info_map_.insert(HeroInfoPair(hero_info.name, hero_info));
  }
}

void War3HeroSkillViewerFrame::FillHeroListBox()
{
  for (const auto &hero_info : hero_info_map_) {
    hero_list_box_->Append(wxString(hero_info.first));
  }
}

void War3HeroSkillViewerFrame::FillSkillListBox(const std::wstring &hero_name)
{
  for (const auto &skill_info : hero_info_map_[hero_name].skill_info_vector) {
    skill_list_box_->Append(skill_info.name);
    research_uber_tip_vector_.push_back(skill_info.research_uber_tip);
  }
}

void War3HeroSkillViewerFrame::SearchHeroTextCtrlOnText(wxCommandEvent& event)
{
  hero_list_box_->Clear();
  const auto &search_pattern = event.GetString();
  if (search_pattern == wxEmptyString) {
    FillHeroListBox();
  }
  else {
    for (const auto &hero_info : hero_info_map_) {
      const auto &hero_name = hero_info.first;
      if (hero_name.find(search_pattern) == 0) {
        hero_list_box_->Append(hero_name);
      }
    }
  }
}

void War3HeroSkillViewerFrame::HeroListBoxOnListBox(wxCommandEvent& event)
{
  skill_list_box_->Clear();
  research_uber_tip_vector_.clear();

  const auto hero_name = event.GetString().ToStdWstring();
  FillSkillListBox(hero_name);
}

void War3HeroSkillViewerFrame::SkillListBoxOnListBox(wxCommandEvent& event)
{
  skill_info_text_ctrl_->Clear();
  skill_info_text_ctrl_->SetDefaultStyle(wxTextAttr(*wxWHITE, *wxBLACK));

  // process control code
  wxString modified_content = research_uber_tip_vector_[event.GetSelection()];
  modified_content.Replace(wxS("|n"), wxS("\n"));
  modified_content.Replace(wxS("|r"), wxS(""));

  // process color code
  const size_t content_length{modified_content.Length()};
  size_t index{0};
  while (index < content_length) {
    if (modified_content[index] == wxS('|') && (index + 1 < content_length) && (modified_content[index + 1] == wxS('c') || modified_content[index + 1] == wxS('C'))) {
      index += 2;
      if (index + 7 < content_length) {
        unsigned long red{0xFF}, green{0xFF}, blue{0xFF}, alpha{0x00};
        wxString::Format(wxS("%c%c"), modified_content[index], modified_content[index + 1]).ToULong(&red, 16);
        wxString::Format(wxS("%c%c"), modified_content[index + 2], modified_content[index + 3]).ToULong(&green, 16);
        wxString::Format(wxS("%c%c"), modified_content[index + 4], modified_content[index + 5]).ToULong(&blue, 16);
        wxString::Format(wxS("%c%c"), modified_content[index + 6], modified_content[index + 7]).ToULong(&alpha, 16);
        skill_info_text_ctrl_->SetDefaultStyle(wxTextAttr(wxColour((unsigned char)red, (unsigned char)green, (unsigned char)blue, (unsigned char)alpha)));
        index += 8;
      }
    }
    else {
      (*skill_info_text_ctrl_) << (wchar_t)modified_content[index++];
    }
  }

  //skill_info_text_ctrl_->SetLabel(modified_content);
}

void War3HeroSkillViewerFrame::OpenFileMenuItemOnMenuSelection(wxCommandEvent & WXUNUSED(event))
{
  wxFileDialog open_file_dialog(this, _("Open hero-skill list file"), "", "",
                                "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
  if (open_file_dialog.ShowModal() == wxID_CANCEL) {
    return;
  }

  if (!ParseHeroSkillListFile(open_file_dialog.GetPath().ToStdWstring())) {
    wxMessageBox(_("Can not load file [") + open_file_dialog.GetPath()+ wxS("]."));
    return;
  }
  hero_info_map_.clear();
  hero_list_box_->Clear();
  skill_list_box_->Clear();
  skill_info_text_ctrl_->Clear();
  CreateHeroInfoMap();
  FillHeroListBox();
}

void War3HeroSkillViewerFrame::Close_menuItem_OnMenuSelection(wxCommandEvent& WXUNUSED(event))
{
  this->Close();
}

void War3HeroSkillViewerFrame::AboutMenuItemOnMenuSelection(wxCommandEvent& WXUNUSED(event))
{
  wxMessageBox(wxS("Version 1.0.0\nAuthor: R-CO"), wxS("About..."));
}

} // end of namespace "rco"

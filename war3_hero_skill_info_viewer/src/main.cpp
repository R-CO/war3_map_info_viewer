/**
*** Author: R-CO
*** Mail: daniel1820kobe@gmail.com
*** Date: 2016-01-09
***/
#include "main.h"

#include <wx/wx.h>

// Include main_frame.h here
#include "gui\war3_hero_skill_viewer_frame.h"

IMPLEMENT_APP(WxProjectTemplateApp)

bool WxProjectTemplateApp::OnInit()
{
  rco::War3HeroSkillViewerFrame *main_frame = new rco::War3HeroSkillViewerFrame(nullptr);

  return main_frame->Show();
}

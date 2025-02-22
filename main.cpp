#include "CameraReport.h"

using namespace CameraReport_NS;

//CameraReport cr;

int main()
{
  CameraReport cr;
  cr.SetMainProjectNotes();
  cr.ShowNotes(cr.GetMainNotesArray());

  cr.WriteToCVS(cr.GetMainColoumnTitles(), cr.GetMainNotesArray(), "CamraReportTest.cvs", "Report Collumn");
  
  return 0;
}


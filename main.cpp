#include "CameraReport.h"

using namespace CameraReport_NS;

CameraReport cr;

int main()
{
  cr.SetMainProjectNotes();
  cr.ShowNotes(cr.GetMainNotesArray());

  cr.WriteToCVS(cr.GetMainColoumnTitles(), cr.GetMainNotesArray(), cr.GetProjectTitle().append(".cvs"), "Report Column");
  
  return 0;
}


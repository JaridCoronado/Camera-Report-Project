#include "CameraReport.h"

using namespace CameraReport_NS;

void CameraReport::SetMainProjectNotes()
{
    string c;
    cout << "What is the name of the project: ";
    getline(cin, c);
    SetProjectTitle(c);

    string d;
    cout << "Director: ";
    getline(cin, d);
    SetDirector(d);

    string e;
    cout << "Director of Photograhgy: ";
    getline(cin, e);
    SetDirectorOfPhotography(e);

    string f;
    cout << "What Camera are you using?: ";
    getline(cin, f);
    SetCamera(f);

    // AskToFinishMainNotes();
    SetUpMainNotesArray();

    cout << "\nMain notes complete!\n\n";
}

void CameraReport::AskToFinishMainNotes()
{
    char answer;
    string c, d, e, f, g, h;
    cout << "Would you like to set Framing, Camera, Firmware, Time Base, Color, and Codec? (Y/n): ";
    cin >> answer;

    switch (answer)
    {

    case 'y':
        AnswerYes();
        break;

    case 'Y':
        AnswerYes();
        break;

    case 'n':
        cout << "Carry on.\n";
        break;

    case 'N':
        cout << "Carry on.\n";
        break;

    default:
        cout << "Please select (Y/n)\n";
        AskToFinishMainNotes();
        break;
    }
}

void CameraReport::AnswerYes()
{
    string c, d, e, f, g, h;

    /*cout << "What is the framing?: ";
    getline(cin, c);
    SetFraming(c);*/

    cout << "What is the Camera?: ";
    getline(cin, d);
    SetCamera(d);

    cout << "What is the firmware?: ";
    getline(cin, e);
    SetFirmware(e);

    cout << "What is the time base?: ";
    getline(cin, e);
    SetTimeBase(f);

    cout << "What is the color?: ";
    getline(cin, g);
    SetColorLook(g);

    cout << "What is the codec?: ";
    getline(cin, h);
    SetCodec(h);
}

void CameraReport::SetUpMainNotesArray()
{
    vector<string> mainNotesArray;
    mainNotesArray = {
        GetProjectTitle(),
        GetDirector(),
        GetDirectorOfPhotography(),
        GetCamera()};

    SetMainNotesArray(mainNotesArray);
}

void CameraReport::ShowNotes(vector<string> notes)
{
    for (int i = 0; i < GetMainColoumnTitles().size(); i++)
    {
        cout << GetMainColoumnTitles().at(i) << GetMainNotesArray().at(i) << "\n";
    }

    cout << endl;
}

void CameraReport::WriteToCVS(vector<string> titles, vector<string> dataSet, string fileName, string colName)
{
    ofstream cameraReportFile(fileName);

    if (!cameraReportFile.is_open()) // error handling
    {
        cerr << "Error, could not open file " << fileName << endl;
        return;
    }

    cameraReportFile << colName << "\n";

    for (int i = 0; i < titles.size(); i++)
    {
        cout << "Writing: " << titles[i] << " + : " << dataSet[i] << " to file\n";
        cameraReportFile << titles[i] << "," << dataSet[i] << "\n";
    }
    cameraReportFile << "\n";
    cout << endl;

    vector<string> rows = GetTakeRows();
    cout << "Writing Row:\n";
    for (int j = 0; j < rows.size(); j++)
    {
        cout << rows[j] << " created!\n";
        cameraReportFile << rows[j] << ",";

        if (j == rows.size())
        {
            cout << "End of the rows\n";
            cameraReportFile << "\n";
        }
    }

    cout << "CVS File Created!\n";
    system("pause");

    cameraReportFile.close();
}

vector<string> CameraReport::GetMainColoumnTitles()
{
    vector<string> cellRowTitles = {
        "Project: ",
        "Director: ",
        "Director of Photography: ",
        "Camera: "};

    return cellRowTitles;
}

vector<string> CameraReport::GetTakeRows()
{
    vector<string> takeRowNames = {
        "SCENE",
        "TAKE",
        "SHOT LENGTH",
        "STOP",
        "FILTER",
        "FPS",
        "ANGLE",
        "ISO",
        "KELVIN",
        "FOCUS",
        "HEIGHT",
        "TILT",
        "NOTES"};
        
    return takeRowNames;
}

void CameraReport::AddTake(){

}

void CameraReport::ChooseWhatCellToEdit(){

}

void CameraReport::MainLoop(){

}
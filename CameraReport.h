#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

namespace CameraReport_NS
{
    class CameraReport
    {
    public:
        // Some getters for the variables
        string GetProjectTitle() const { return projectTitle; }                   // returns the title of the project of the movie
        string GetDirector() const { return director; }                           // returns name of the project's director.
        string GetDirectorOfPhotography() const { return directorOfPhotography; } // returns the name of the project's DOP
        string GetFraming() const { return framing; }                             // Returns the "framing" variable
        string GetCamera() const { return cameraUsed; }
        string GetFirmware() const { return firmware; }
        string GetTimeBase() const { return timeBase; }
        string GetColorLook() const { return colorLook; }
        string GetCodec() const { return codec; }
        string GetRoleLetter() const { return roleLetter; }
        string GetNotes() const { return notes; }
        string GetScene() const { return scene; }

        vector<string> GetMainNotesArray() { return mainNotesArr; }

        float GetLens() const {return lens;}
        float GetFstop() const { return fstop; }
        float GetFilters() const { return filters; }
        float GetCameraHeight() const { return height; }
        float GetCameraTilt() const { return tilt; }
        float GetFramesPerSecond() const { return fps; }

        int GetISO() const { return iso; }
        int GetColorTemp() const { return colorTemp; }
        int GetRoleNumber() const { return roleNum; }
        int GetTakeNumber() const { return takeNum; }

        // Setters for the variables
        string SetProjectTitle(string setProjectTitle) { return projectTitle = setProjectTitle; }
        string SetDirector(string setDirector) { return director = setDirector; }
        string SetDirectorOfPhotography(string setDirectorOfPhotography) { return directorOfPhotography = setDirectorOfPhotography; }
        string SetCamera(string setCamera) { return cameraUsed = setCamera; }
        string SetFirmware(string setFirmware) { return firmware = setFirmware; }
        string SetFraming(string setFraming) { return framing = setFraming; }
        string SetTimeBase(string setTimeBase) { return timeBase = setTimeBase; }
        string SetColorLook(string setColorLook) { return colorLook = setColorLook; }
        string SetCodec(string setCodec) { return codec = setCodec; }
        string SetRoleLetter(string setRoleLetter) { return roleLetter = setRoleLetter; }
        string SetNotes(string setNotes) { return notes = setNotes; }
        string SetScene(string setScene) { return scene = setScene; }

        vector<string> SetMainNotesArray(vector<string> setMainNotesArray) { return mainNotesArr = setMainNotesArray; }

        // Creates the titles needed for the cvs file.
        vector<string> GetMainColoumnTitles();

        //Retrun the top row for Scenen, take, lens, fstop, filter, iso, kelvin, height, tilt, and notes.
        vector<string> GetTakeRows();

        float SetLens(float setLens) {return lens = setLens;}
        float SetFstop(float setFStop) { return fstop = setFStop; }
        float SetFilters(float setFilter) { return filters = setFilter; }
        float SetCameraHeight(float setCameraHeight) { return height = setCameraHeight; }
        float SetCameraTilt(float setTilt) { return tilt = setTilt; }
        float SetFramesPerSecond(float setFPS) { return fps = setFPS; }

        int SetISO(int setISO) { return iso = setISO; }
        int SetColorTemp(int setColorTemp) { return colorTemp = setColorTemp; }
        int SetRoleNumber(int setRoleNum) { return roleNum = setRoleNum; }
        int SetTakeNumber(int setTake) { return takeNum = setTake; }

        // This will contain the project name, director, DOP, framing, camera, firemware, timebase, color/look, and codec information.
        void SetMainProjectNotes();

        void AskToFinishMainNotes();
        void FinishMainNotes();

        // Write out the new row.
        void NewTake();

        // User enters the coloumns of the camera log IDK if i need this one
        void SetCameraLogColoumn();

        // Print the results to terminal
        void ShowNotes(vector<string> notes);

        // Set up the array for printing main notes
        void SetUpMainNotesArray();

        void AnswerYes();

        // Write date to CVS file
        void WriteToCVS(vector<string> titles, vector<string> dataSet, string fileName, string colName);

        //This is where the main part of the program begins, decide to open up a file, decide to add scenes, etc
        void MainLoop();

        //Add a new take here. 
        void AddTake();

        //User selects a cell to edit from this menu
        void ChooseWhatCellToEdit();

    private:
        string projectTitle,
            director,
            directorOfPhotography,
            framing,
            cameraUsed,
            firmware,
            timeBase,
            colorLook,
            codec,
            roleLetter,
            notes,
            scene,
            fileName,
            collumnName;
        vector<string> mainNotesArr;

        float lens,
            fstop,
            filters,
            height,
            tilt,
            fps;

        int iso,
            colorTemp,
            roleNum,
            takeNum;
    };
}
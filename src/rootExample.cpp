#include <iostream>
#include <string>

#include <TFile.h>
#include <TDirectory.h>

#include "root/ROOTObject.h"

int createRootFile()
{

    TFile* pRootFile = new TFile("myfile.root", "RECREATE");
    if (pRootFile == NULL) {
        std::cout << "Error creating ROOT file" << std::endl;
        return 1;
    }

    TDirectory* pTestDir = pRootFile->mkdir("TestDir");
    if (pTestDir == NULL) {
        std::cout << "Error creating directory in ROOT file" << std::endl;
        delete pRootFile;
        return 1;
    }
    
    std::string name = "testobj";
    MyROOTObject* pMyObj = new MyROOTObject(17, 1.2e3, name);
    std::cout << pMyObj->getIntValue() << std::endl;
    pMyObj->setIntValue(100);
    std::cout << pMyObj->getIntValue() << std::endl;
    std::cout << pMyObj->GetName() << std::endl;

    pTestDir->cd();
    pMyObj->Write(pMyObj->GetName());

    if (pRootFile != NULL) {
        if (pRootFile->IsOpen() && !pRootFile->IsZombie()) {
            pRootFile->Close();
            delete pRootFile;
        }
    }

}

void loadFromFile()
{

    TFile* pRootFile = new TFile("myfile.root", "READ");

    if (pRootFile != NULL) {
        TDirectory* pTestDir = (TDirectory*)pRootFile->Get("TestDir");
        if (pTestDir != NULL) {
            pTestDir->cd();

            MyROOTObject* pMyObj = NULL;
            std::string name = "testobj";
            pMyObj = (MyROOTObject*)pTestDir->Get(name.c_str());
            if (pMyObj != NULL) {
                std::cout << pMyObj->getIntValue() << std::endl;
                std::cout << pMyObj->getDoubleValue() << std::endl;
            }
        }

        if (pRootFile->IsOpen() && !pRootFile->IsZombie()) {
            pRootFile->Close();
            delete pRootFile;
        }
    }    

}

int main(int argc, char* argv[])
{
    std::string cmd(argv[1]);
    std::cout << cmd << std::endl;

    if (cmd == "create") {
        createRootFile();
    } else if (cmd == "load") {
        loadFromFile();
    }

}

#include "Riostream.h"
#include "TFile.h"
#include "root/ROOTObject.h"

void macro()
{
				cout << "Example macro for testing the ROOTobject library from CINT" 
									<< endl;

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

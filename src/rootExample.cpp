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
    std::cout << *pMyObj;
    //std::cout << pMyObj->GetName() << ": "
				//										<< pMyObj->getIntValue() << "; "
				//										<< pMyObj->getDoubleValue()
				//										<< std::endl;

    pTestDir->cd();
    pMyObj->Write(pMyObj->GetName());

    if (pRootFile != NULL) {
        if (pRootFile->IsOpen() && !pRootFile->IsZombie()) {
            pRootFile->Close();
            delete pRootFile;
        }
    }

}

void loadRootFile()
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
                std::cout << *pMyObj;
																//std::cout << pMyObj->GetName() << ": "
																//										<< pMyObj->getIntValue() << "; "
																//										<< pMyObj->getDoubleValue()
																//										<< std::endl;
            }
        }

        if (pRootFile->IsOpen() && !pRootFile->IsZombie()) {
            pRootFile->Close();
            delete pRootFile;
        }
    }    

}

void appendRootFile()
{

    TFile* pRootFile = new TFile("myfile.root", "UPDATE");

    if (pRootFile != NULL) {
        TDirectory* pTestDir = (TDirectory*)pRootFile->Get("TestDir");
        if (pTestDir != NULL) {
            pTestDir->cd();

            MyROOTObject* pMyObj = NULL;
            std::string name = "testobj";
            pMyObj = (MyROOTObject*)pTestDir->Get(name.c_str());
            if (pMyObj != NULL) {
                std::cout << *pMyObj;
																//std::cout << pMyObj->GetName() << ": "
																//										<< pMyObj->getIntValue() << "; "
																//										<< pMyObj->getDoubleValue()
																//										<< std::endl;
            }

												name = "newobj";
												MyROOTObject* pNewObj = NULL;
												pNewObj = new MyROOTObject(42, 5.9e2, name);
            if (pNewObj != NULL) {
                std::cout << *pMyObj;
																//std::cout << pNewObj->GetName() << ": "
																//										<< pNewObj->getIntValue() << "; "
																//										<< pNewObj->getDoubleValue()
																//										<< std::endl;
																pNewObj->Write(pNewObj->GetName());
            }
        }

        if (pRootFile->IsOpen() && !pRootFile->IsZombie()) {
            pRootFile->Close();
            delete pRootFile;
        }
    }    

}

void overwriteRootFile()
{

    TFile* pRootFile = new TFile("myfile.root", "UPDATE");

    if (pRootFile != NULL) {
        TDirectory* pTestDir = (TDirectory*)pRootFile->Get("TestDir");
        if (pTestDir != NULL) {
            pTestDir->cd();

												pTestDir->Delete("testobj;*");

												std::string name = "testobj";
												MyROOTObject* pNewObj = NULL;
												int ival = rand() % 100 + 1;
												double dval = (double)(rand() % 1000 + 1)/1000.0;
												pNewObj = new MyROOTObject(ival, dval, name);
            if (pNewObj != NULL) {
                std::cout << *pNewObj;
																//std::cout << pNewObj->GetName() << ": "
																//										<< pNewObj->getIntValue() << "; "
																//										<< pNewObj->getDoubleValue()
																//										<< std::endl;
																pNewObj->Write(pNewObj->GetName(), TObject::kOverwrite);
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

				std::cout << sizeof(MyROOTObject) << std::endl;

    if (cmd == "create") {
        createRootFile();
    } else if (cmd == "load") {
        loadRootFile();
    } else if (cmd == "append") {
								appendRootFile();
				} else if (cmd == "overwrite") {
								overwriteRootFile();
				}

}

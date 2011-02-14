{

// This rootlogon.C will load the test macro. It assumes you have set
// the LD_LIBRARY_PATH correctly and that the header file is in
// ${HOME}/usr/include. If not, change that line below.

cout << "Loading the shared library..." << endl;
gSystem->Load("libROOTobject.so");

gSystem->AddIncludePath(" -I${HOME}/usr/include/");

gROOT->LoadMacro("macro.C+");

}

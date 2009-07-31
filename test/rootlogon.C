{

cout << "Loading the shared library..." << endl;
gSystem->Load("libROOTobject.so");

gSystem->AddIncludePath(" -I/home/nkarlsson/usr/include/");

gROOT->LoadMacro("macro.C+");

}

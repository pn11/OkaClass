#include "OH1.hh"
#include <iostream>

ClassImp(OH1);

OH1::OH1(char *hname, char *htitle, int nbin, double x1, double x2)
: TH1D(hname, htitle, nbin, x1, x2)
{
};


#ifndef __OH1__
#define __OH1__

#include "TH1.h"


class OH1 : public TH1D
{

private:
  Int_t hogehoge;

public:
  OH1(char *hname, char *htitle, int nbin, double x1, double x2);
//  ~OH1();

  ClassDef(OH1, 1);
};
#endif


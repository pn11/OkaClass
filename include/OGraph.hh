#ifndef __OGRAPH__
#define __OGRAPH__

#include "TGraphErrors.h"


class OGraph : public TGraphErrors
{

private:
  Int_t hogehoge;

public:
  OGraph();
  OGraph(int n);
  OGraph(Int_t n, const Float_t *x, const Float_t *y, const Float_t *ex, const Float_t *ey);
  OGraph(Int_t n, const Double_t *x, const Double_t *y, const Double_t *ex, const Double_t *ey);
  OGraph(const TVectorF &vx, const TVectorF &vy, const TVectorF &vex, const TVectorF &vey);

//  ~OH1();
  void SetXTitle(char *title);
  void SetYTitle(char *title);
  void SetXRange(Double_t ufirst, Double_t ulast);
  void SetYRange(Double_t ufirst, Double_t ulast);


  ClassDef(OGraph, 1);
};
#endif


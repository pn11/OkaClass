#include "OGraph.hh"
#include <iostream>
#include "TAxis.h"
#include "TH1.h"


ClassImp(OGraph);
//https://root.cern.ch/root/html/src/TGraphErrors.cxx.html

OGraph::OGraph(): TGraphErrors()
{
};

OGraph::OGraph(int n)
: TGraphErrors(n)
{
};

OGraph::OGraph(Int_t n, const Float_t *x, const Float_t *y, const Float_t *ex, const Float_t *ey)
: TGraphErrors(n, x, y, ex, ey)
{
};

OGraph::OGraph(Int_t n, const Double_t *x, const Double_t *y, const Double_t *ex, const Double_t *ey)
: TGraphErrors(n, x, y, ex, ey)
{
};

OGraph::OGraph(const TVectorF &vx, const TVectorF &vy, const TVectorF &vex, const TVectorF &vey)
: TGraphErrors(vx, vy, vex, vey)
{
};



void OGraph::SetXTitle(char *title){
	TAxis *ax = GetXaxis();
    ax->SetTitle(title);
};

void OGraph::SetYTitle(char *title){
	TAxis *ax = GetYaxis();
    ax->SetTitle(title);
};


// setting range https://root.cern.ch/drupal/content/how-set-ranges-axis
void OGraph::SetXRange(Double_t ufirst, Double_t ulast){
	TAxis *ax = GetXaxis();
    ax->SetLimits(ufirst, ulast);
};

void OGraph::SetYRange(Double_t ufirst, Double_t ulast){
	GetHistogram()->SetMaximum(ufirst);
	GetHistogram()->SetMinimum(ulast);
};

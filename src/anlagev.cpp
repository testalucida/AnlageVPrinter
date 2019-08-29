#include "anlagev.h"

//see: https://www.unitconverters.net/typography/centimeter-to-pixel-x.htm

#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>

FlatOutput::FlatOutput(int x, int y, int w)
    : Fl_Output(x, y, w, 19)
{
    box(FL_FLAT_BOX);
    textsize(10);
}

void FlatOutput::draw()
{
    Fl_Output::draw();
}

PageOne::PageOne(int x, int y, int w, int h)
    : Fl_Group(x, y, w, h)
{
    begin();
    int top = 47;
    int Y = 82 + top;

    int X = 90;
    //Name
    _pName = new FlatOutput(X, Y, 442);
    _pName->value("Kendel");

    Y += 23;
    _pVorname = new FlatOutput(X, Y, 442);
    _pVorname->value("Martin");

    Y += 23;
    _pSteuernr = new FlatOutput(X + 70, Y, 221);
    _pSteuernr->value("217/235/50499");

    Y += 65;
    _pWhgStrasse = new FlatOutput(X, Y, 442);
    _pWhgStrasse->value("Mendelstr. 24 / 3.OG links");

    Y += 23;
    _pWhgPlz = new FlatOutput(X, Y, 70);
    _pWhgPlz->value("90429");

    Y += 23;
    _pEinhwert_Az = new FlatOutput(X + 30, Y, 200);
    _pEinhwert_Az->value("2410111534700200");

    Y += 33;
    _pNtzgFeWo = new FlatOutput(X + 150, Y, 20);
    _pNtzgFeWo->value("2");

    Y += 25;
    _pWohnflaeche = new FlatOutput(X + 50, Y, 40);
    _pWohnflaeche->value("53");

    Y += 27;
    _pMieteNetto = new FlatOutput(X + 423, Y, 40);
    _pMieteNetto->value("4095");

    Y += 93;
    _pNK = new FlatOutput(X + 423, Y, 40);
    _pNK->value("816");

    Y += 151;
    _pSummeEin = new FlatOutput(X + 423, Y, 40);
    _pSummeEin->value("4911");

    Y += 20;
    _pSummeWK = new FlatOutput(X + 423, Y, 40);
    _pSummeWK->value("11621");

    Y += 22;
    _pUeberschuss = new FlatOutput(X + 423, Y, 40);
    _pUeberschuss->value("-6710");

    Y += 30;
    _pZurechng = new FlatOutput(X + 210, Y, 40);
    _pZurechng->value("-6710");
    end();
}

PageTwo::PageTwo(int x, int y, int w, int h)
: Fl_Group(x, y, w, h)
{

}

AnlageV::AnlageV(int x, int y, int w, int h)
    : Fl_Group(x, y, w, h)
{
    begin();
    _pPageOne = new PageOne(x, y, w, h);
    _pShownPage = _pPageOne;
    _pPageTwo = new PageTwo(x, y, w, h);
    _pPageTwo->hide();
    end();
}

void AnlageV::changePage() {
    if( _pShownPage == _pPageOne ) {
        _pPageOne->hide();
        _pPageTwo->set_visible();
        _pShownPage = _pPageTwo;
    } else {
        _pPageTwo->hide();
        _pPageOne->set_visible();
        _pShownPage = _pPageOne;
    }
}

AnlageV::~AnlageV()
{
    //dtor
}

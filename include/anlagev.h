#ifndef ANLAGEV_H
#define ANLAGEV_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>

class FlatOutput : public Fl_Output {
    public:
        FlatOutput(int x, int y, int w);
        void draw();
};

class PageOne : public Fl_Group {
    public:
        PageOne(int x, int y, int w, int h);
    private:
        FlatOutput *_pName;
        FlatOutput *_pVorname;
        FlatOutput *_pSteuernr;
        FlatOutput *_lfdNr;
        FlatOutput *_pWhgStrasse;
        FlatOutput *_pWhgPlz;
        FlatOutput *_pWhgOrt;
        FlatOutput *_pEinhwert_Az;
        FlatOutput *_pNtzgFeWo;
        FlatOutput *_pWohnflaeche;
        FlatOutput *_pMieteNetto;
        FlatOutput *_pNK;
        FlatOutput *_pSummeEin;
        FlatOutput *_pSummeWK;
        FlatOutput *_pUeberschuss;
        FlatOutput *_pZurechng;

};

class PageTwo : public Fl_Group {
    public:
        PageTwo(int x, int y, int w, int h);
    private:
        FlatOutput *_stnrNameEtc;
        FlatOutput *_afaLinear;
        FlatOutput *_afaDegr;
        FlatOutput *_afaProzent;
        FlatOutput *_afaWieVj;
        FlatOutput *_afaBetrag;
        FlatOutput *_aufwandVollAbz;
        FlatOutput *_aufwand5JVert;
        FlatOutput *_aufwand5JAbzVj;
        FlatOutput *_nkMieter;
        FlatOutput *_verwaltKosten;
        FlatOutput *_sonstKosten;
        FlatOutput *_summeWK;
};

class AnlageV : public Fl_Group {
    public:
        AnlageV(int x, int y, int w, int h);
        virtual ~AnlageV();
        void changePage();

    protected:

    private:
        PageOne *_pPageOne;
        PageTwo *_pPageTwo;
        Fl_Group *_pShownPage;
};

#endif // ANLAGEV_H

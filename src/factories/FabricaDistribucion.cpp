#include "FabricaDistribucion.h"
#include "DTBer.h"
#include "Ber.h"
#include "DTBin.h"
#include "Bin.h"
#include "DTBinNeg.h"
#include "BinNeg.h"
#include "DTExp.h"
#include "Exp.h"
#include "DTHip.h"
#include "Hip.h"
#include "DTNormal.h"
#include "Normal.h"
#include "DTPois.h"
#include "Pois.h"
#include "DTUni.h"
#include "Uni.h"

#include "TipoDistribucionInvalidaException.h"

Distribucion* FabricaDistribucion::crear(DTDistribucion& dt) {
    if(auto ber = dynamic_cast<DTBer*>(&dt)){
        return new Ber(ber->getP());
    }
    if(auto bin = dynamic_cast<DTBin*>(&dt)){
        return new Bin(bin->getN(), bin->getP());
    }
    if(auto binNeg = dynamic_cast<DTBinNeg*>(&dt)){
        return new BinNeg(binNeg->getR(), binNeg->getP());
    }
    if(auto exp = dynamic_cast<DTExp*>(&dt)){
        return new Exp(exp->getLambda());
    }
    if(auto hip = dynamic_cast<DTHip*>(&dt)){
        return new Hip(hip->getSampleSize(), hip->getTotalSize(), hip->getDistinguishedSize());
    }
    if(auto nor = dynamic_cast<DTNormal*>(&dt)){
        return new Normal(nor->getMu(), nor->getSigmaSquare());
    }
    if(auto pois = dynamic_cast<DTPois*>(&dt)){
        return new Pois(pois->getLambda());
    }
    if(auto uni = dynamic_cast<DTUni*>(&dt)){
        return new Uni(uni->getA(), uni->getB());
    }
    throw TipoDistribucionInvalidaException("La distribución proporcionada no está contemplada");
}
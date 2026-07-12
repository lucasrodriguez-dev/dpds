#include "factories/FabricaDistribucion.h"
#include "datatypes/DTBer.h"
#include "distributions/Ber.h"
#include "datatypes/DTBin.h"
#include "distributions/Bin.h"
#include "datatypes/DTBinNeg.h"
#include "distributions/BinNeg.h"
#include "datatypes/DTExp.h"
#include "distributions/Exp.h"
#include "datatypes/DTHip.h"
#include "distributions/Hip.h"
#include "datatypes/DTNormal.h"
#include "distributions/Normal.h"
#include "datatypes/DTPois.h"
#include "distributions/Pois.h"
#include "datatypes/DTUni.h"
#include "distributions/Uni.h"

#include "exceptions/TipoDistribucionInvalidaException.h"

Distribucion* FabricaDistribucion::crear(DTDistribucion* dt) {
    if(dt == nullptr){
        throw TipoDistribucionInvalidaException("La distribución no puede ser nula");
    }
    if(auto ber = dynamic_cast<DTBer*>(dt)){
        return new Ber(ber->getP());
    }
    if(auto bin = dynamic_cast<DTBin*>(dt)){
        return new Bin(bin->getN(), bin->getP());
    }
    if(auto binNeg = dynamic_cast<DTBinNeg*>(dt)){
        return new BinNeg(binNeg->getR(), binNeg->getP());
    }
    if(auto exp = dynamic_cast<DTExp*>(dt)){
        return new Exp(exp->getLambda());
    }
    if(auto hip = dynamic_cast<DTHip*>(dt)){
        return new Hip(hip->getSampleSize(), hip->getTotalSize(), hip->getDistinguishedSize());
    }
    if(auto nor = dynamic_cast<DTNormal*>(dt)){
        return new Normal(nor->getMu(), nor->getSigmaSquare());
    }
    if(auto pois = dynamic_cast<DTPois*>(dt)){
        return new Pois(pois->getLambda());
    }
    if(auto uni = dynamic_cast<DTUni*>(dt)){
        return new Uni(uni->getA(), uni->getB());
    }
    throw TipoDistribucionInvalidaException("La distribución proporcionada no está contemplada");
}
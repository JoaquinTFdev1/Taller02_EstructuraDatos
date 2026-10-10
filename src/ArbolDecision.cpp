#include "ArbolDecision.h"


ArbolDecision::ArbolDecision() {
    this->raiz = nullptr;
    this->construirArbol();
}

ArbolDecision::~ArbolDecision() {

    this->liberar(this->raiz);
}

void ArbolDecision::construirArbol() {

    NodoDecision* edad = new NodoDecision(1,"Edad menor a 14","");
    NodoDecision* trauma = new NodoDecision(2,"Trauma igual a 1","");
    NodoDecision* cirugia = new NodoDecision(3,"Requiere cirugia igual a 1","");
    NodoDecision* neurologicos = new NodoDecision(4,"Sintomas neurologicos igual a 1","");
    NodoDecision* dolorPecho =new NodoDecision(5,"Tipo de dolor igual a pecho","");
    NodoDecision* urgencia = new NodoDecision(6, "Temperatura alta, dolor intenso o presion alta","");
    NodoDecision* hospitalizacion = new NodoDecision(7,"Dias de hospitalizacion mayor o igual a 2","");
    NodoDecision* pediatria = new NodoDecision(0, "","Pediatria");
    NodoDecision* servicioCirugia =new NodoDecision(0, "","Cirugia");
    NodoDecision* traumatologia = new NodoDecision(0, "","Traumatologia" );
    NodoDecision* neurologia = new NodoDecision(0,"", "Neurologia");
    NodoDecision* cardiologia = new NodoDecision(0, "", "Cardiologia");
    NodoDecision* urgencias = new NodoDecision(0,"","Urgencias");
    NodoDecision* servicioHospitalizacion = new NodoDecision( 0, "", "Hospitalizacion");
    NodoDecision* medicinaGeneral = new NodoDecision( 0, "", "Medicina General");

    edad->setRamaSi(pediatria);
    edad->setRamaNo(trauma);

    trauma->setRamaSi(cirugia);
    trauma->setRamaNo(neurologicos);

    cirugia->setRamaSi(servicioCirugia);
    cirugia->setRamaNo(traumatologia);

    neurologicos->setRamaSi(neurologia);
    neurologicos->setRamaNo(dolorPecho);

    dolorPecho->setRamaSi(cardiologia);
    dolorPecho->setRamaNo(urgencia);

    urgencia->setRamaSi(urgencias);
    urgencia->setRamaNo(hospitalizacion);

    hospitalizacion->setRamaSi(servicioHospitalizacion);
    hospitalizacion->setRamaNo(medicinaGeneral);
    this->raiz = edad;
}

void ArbolDecision::liberar(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    this->liberar(nodo->getRamaSi());
    this->liberar(nodo->getRamaNo());
    delete nodo;
}


NodoDecision* ArbolDecision::getRaiz() {
    return this->raiz;
}




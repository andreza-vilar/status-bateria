/*>Discente: Andreza Vilar de Farias
>Disciplina: Técnicas de Programação
>Turma: 02 */

#include <iostream>
#include <iomanip>

using namespace std;


class BMS{
	private:
		float estadoBateriaIdeal = 30;
		float temperaturaBateriaIdeal = 25;
		float correnteIdeal;
		float tensaoBateria, temperaturaBateria, correnteBateria, correnteSobrecargaBateria, nivelCargaBateria;

	public:
		BMS(); //declaração do construtor
		~BMS(); //declaração do destrutor
		void setTensao(float);
		void setCorrenteBat(float);
		void setTempBat(float);
		void setNivelCarga(float);
		void setCorrenteSobrecarga(float);
		float getTensao();
		float getCorrenteBat();
		float getTempBat();
		float getNivelCarga();
		float getCorrenteSobrecarga();
		float calculaPotencia();
		string situacaoCarga();
		string situacaoTemperatura();
		string situacaoCorrente();

};


//depois do prototipo da classe, cada função vai ser implementada
BMS::BMS(){  //construtor default inicializando os atributos
    tensaoBateria = 0;
    temperaturaBateria = 0;
    correnteBateria = 0;
    correnteSobrecargaBateria = 0;
    nivelCargaBateria = 0;
}

//set pra receber valores
void BMS::setTensao(float tensaoBateria){
    this->tensaoBateria = tensaoBateria;
}

void BMS:: setCorrenteBat(float correnteBateria){
    this->correnteBateria = correnteBateria;
}

void BMS :: setTempBat(float temperaturaBateria){
    this->temperaturaBateria = temperaturaBateria;
}

void BMS:: setNivelCarga(float nivelCargaBateria){
    this->nivelCargaBateria = nivelCargaBateria;
}

void BMS:: setCorrenteSobrecarga(float correnteSobrecargaBateria){
    this->correnteSobrecargaBateria = correnteSobrecargaBateria;
}

// gets pra retornar valores
float BMS::getTensao(){
    return tensaoBateria;
}

float BMS::getCorrenteBat(){
    return correnteBateria;
}

float BMS::getTempBat(){
    return temperaturaBateria;
}

float BMS::getNivelCarga(){
    return nivelCargaBateria;
}

float BMS::getCorrenteSobrecarga(){
    return correnteSobrecargaBateria;
}

float BMS::calculaPotencia(){
    return (correnteBateria*tensaoBateria);
}

//esses 3 métodos retornam a situação da bateria quanto a carga, temperatura e corrente
string BMS::situacaoCarga(){
    if (nivelCargaBateria < estadoBateriaIdeal)
        return "Estado de carga anormal (estado de alerta)";
    else
        return "Estado de carga normal";
}

string BMS::situacaoTemperatura(){
    if (temperaturaBateria > temperaturaBateriaIdeal)
        return "Temperatura anormal (estado de alerta)";
    else
        return "Temperatura normal";
}

string BMS::situacaoCorrente(){
    if (correnteBateria >= correnteSobrecargaBateria)
        return "Corrente anormal (estado de alerta)";
    else
        return "Corrente normal";
}

//destrutor pra assim que finalizar o código liberar memória
BMS::~BMS(){
    cout<<"TESTES REALIZADOS COM SUCESSO!";
}

//implementação das funções com as atribuições
int main (){
    setlocale(LC_ALL,"Portuguese");

    BMS bateria1; //instanciação do objeto a classe
    float tensao_inst,temperatura,corrente,corrente_sobrecarga, nivel_carga;

    cout<<"Informe o valor da tensão instantânea: ";
    cin >>tensao_inst;
    cout<<"Informe o valor da corrente: ";
    cin >>corrente;
    cout<<"Informe o valor da Temperatura: ";
    cin >>temperatura;
    cout<<"Informe o valor da corrente de sobrecarga: ";
    cin >>corrente_sobrecarga;
    cout<<"Informe o nível de carga da bateria (em porcentagem): ";
    cin >>nivel_carga;

    bateria1.setCorrenteBat(corrente);
    bateria1.setCorrenteSobrecarga(corrente_sobrecarga);
    bateria1.setNivelCarga(nivel_carga);
    bateria1.setTempBat(temperatura);
    bateria1.setTensao(tensao_inst);


    cout<<"Tensão Bateria ---->   "<<bateria1.getTensao()<<"V"<<endl;
    cout<<"Corrente Bateria ---->   "<<bateria1.getCorrenteBat()<<"A   "<<bateria1.situacaoCorrente()<<endl;
    cout<<"Potencia ---->   "<<bateria1.calculaPotencia()<<"W "<<endl;
    cout<<"Sensor de Temperatura ---->   "<<bateria1.getTempBat()<<"ºC   "<<bateria1.situacaoTemperatura()<<endl;
    cout<<"Estado da Carga ---->   "<<bateria1.getNivelCarga()<<"%   "<<bateria1.situacaoCarga()<<endl;


    return 0;
}

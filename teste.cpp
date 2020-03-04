#include <iostream>
using namespace std;

class Pessoa{
	public:
		Pessoa(string nome,int idade){ nomePessoa = nome; idadePessoa = idade;};
		
		int getIdade(){ return idadePessoa; };
		string getNome(){ return nomePessoa; };
		Pessoa* getPtr(){ return this; };
		Pessoa* getPtrPessoa(){ return ptrPessoa; };
		
		void setNome(string novoNome){ nomePessoa = novoNome;};
		void setIdade(int idade){ idadePessoa = idade;};
		Pessoa* setPtr(Pessoa* pessoa){ return ptrPessoa=pessoa;};
		
		bool nomeEhJoao(){ return (nomePessoa == "Joao" ? true : false); };
		string nomeExiste(){ return (nomePessoa != "" ? "sim" : "nao"); };
		
	private:
		int idadePessoa;
		string nomePessoa;
		Pessoa* ptrPessoa;
	
};

int main()
{
	Pessoa Joao("Joao",20);
	
	cout << "Nome " << Joao.getNome() << " Nome existe? " << Joao.nomeExiste() << " Nome é Joao? " << Joao.nomeEhJoao() << endl;
	
	Joao.setIdade(15);
	
	cout << "Idade de Joao " << Joao.getIdade() << endl;
	
	cout << Joao.getPtr() << endl;
	
	Pessoa Pedro("Pedro",25);
	
	cout << "Nome " << Pedro.getNome() << " Nome existe? " << Pedro.nomeExiste() << " Nome é Joao? " << Pedro.nomeEhJoao() << endl;
	
	cout << "Pedro Ponteiro Original " << Pedro.getPtr() << endl;
	
	Pedro.setPtr(Joao.getPtrPessoa());
	
	cout << "Pedro Ponteiro Alterado " << Pedro.getPtr() << endl;
	
	cout << "Pedro Ponteiro " << Pedro.getPtrPessoa() << endl;
	


}

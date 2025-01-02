#include<bits/stdc++.h>

using namespace std;

struct Elemento
{
	int peso;
	int beneficio;

	Elemento(int x, int y)
	{
		peso = x;
		beneficio = y;
	}

	int getPeso()
	{
		return peso;
	}
	void setPeso(int x)
	{
		peso = x;
	}
	int getBeneficio()
	{
		return beneficio;
	}
	void setBeneficio(int x)
	{
		beneficio = x;
	}
	void mostrar()
	{
		cout << "Peso: " << peso << ", Beneficio: " << beneficio << "\n";
	}
};

struct Mochila
{
	int pesoMaximo;
	vector<Elemento> elementos;

	int peso;
	int beneficio;

	Mochila(int pesoMax)
	{
		pesoMaximo = pesoMax;
		beneficio = 0;
		peso = 0;
	}

	
	vector<Elemento> getElementos()
	{
		return elementos;
	}

	int getPesoMaximo()
	{
		return peso;
	}
	void setPesoMaximo(int x)
	{
		pesoMaximo = x;
	}
	int getPeso()
	{
		return peso;
	}
	void setPeso(int x)
	{
		peso = x;
	}
	int getBeneficio()
	{
		return beneficio;
	}
	void setBeneficio(int x)
	{
		beneficio = x;
	}
	void aniadirElemento(Elemento e)
	{
		elementos.push_back(e);
	}
	void eliminarElemento()
	{
		elementos.pop_back();
	}
	bool existeElemento(Elemento e)
	{
		for(int i = 0; i < elementos.size(); i++)
			if(elementos[i].getPeso() == e.getPeso() and elementos[i].getBeneficio() == e.getBeneficio()) return true;
		return false;
	}

	void limpiar()
	{
		while(elementos.size() != 0)
			elementos.pop_back();
	}

	void vaciar(Mochila &Z)
	{
		vector<Elemento> ze = Z.getElementos();
		int i = 0;
		while(ze.size() != 0)
		{
			elementos.push_back(ze[i]);
			i++;
			ze.pop_back();
		}
	}

	void mostrar()
	{
		cout << "Capacidad maxima de la mochila: " << pesoMaximo << "\n";
		cout << "Beneficio: " << beneficio << "\n";
		cout << "Peso: " << peso << "\n";
		cout << "Elementos: " << "\n";
		for(int i = 0; i < elementos.size(); i++)
			elementos[i].mostrar();
	}
};

void llenarMochila(Mochila &m_base, vector<Elemento> &elementos, bool llena, Mochila &m_opt)
{
	if(llena) //verificar si esta llena
	{
		if(m_base.getBeneficio() > m_opt.getBeneficio()) // si el beneficio de la mochila base es mayor al beneficio de la mochila optima
		{
			m_opt.limpiar();
			m_opt.vaciar(m_base); //retiro los elementos de m_base a m_opt
		}
	}
	else
	{
		for (int i = 0; i < elementos.size(); i++) //recorremos los elementos
		{
			if(not m_base.existeElemento(elementos[i]))
			{
				if(m_base.getPesoMaximo() > m_base.getPeso() + elementos[i].getPeso()) //verifica si es factible agregar un objeto
				{
					m_base.aniadirElemento(elementos[i]); //adicionamos
					llenarMochila(m_base, elementos, false, m_opt);
					m_base.eliminarElemento(); //eliminamos volver atras
				}
				else //caso contrario pues la mochila esta en sobrecarga al meter el elementos[i]
					llenarMochila(m_base, elementos, true, m_opt);
			}
		}
	}
}

int main()
{
	vector<Elemento> elementos = {Elemento(1, 1), Elemento(2, 2), Elemento(4, 10), Elemento(1, 2), Elemento(12, 4)};
	Mochila m_base(15);
	Mochila m_opt(15);
	llenarMochila(m_base, elementos, false, m_opt);
	m_opt.mostrar();
	//Mochila m_base(15, elementos.size());
	//Mochila m_opt(15, elementos.size());
	
}
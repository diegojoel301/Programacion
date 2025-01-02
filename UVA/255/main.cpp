#include<iostream>
#include<queue>

using namespace std;

int Kp, Qp, nQp, cihq, cshq, civq, csvq;

queue<int> K, Q;

void acotar()
{
	cshq = (Qp - Qp % 8) + 7;
	cihq = (Qp - Qp % 8);
	civq = (56 + Qp % 8);
	csvq = Qp % 8;
}

void llenar()
{
	if(Kp % 8 <= Kp - 8 and Kp - 8 <= Kp)
		K.push(Kp - 8);
	if(Kp <= Kp + 8 and Kp + 8 <= 56 + Kp % 8)
		K.push(Kp + 8);
	if(Kp <= Kp + 1 and Kp + 1 <= (Kp - Kp % 8) + 7)
		K.push(Kp + 1);
	if(Kp - Kp % 8 <= Kp - 1 and Kp - 1 <= Kp)
		K.push(Kp - 1);
	

	int U = Qp -8, D = Qp + 8, L = Qp - 1, R = Qp + 1;
	bool sw = true;

	while(sw)
	{
		if(csvq <= U and U <= Qp)
			Q.push(U);
		if(Qp <= D and D <= civq)
			Q.push(D);
		if(Qp <= R and R <= cshq)
			Q.push(R);
		if(cihq <= L and L <= Qp)
			Q.push(L);
		if(not (csvq <= U and U <= Qp) and not (Qp <= D and D <= civq) and not (Qp <= R and R <= cshq) and not (cihq <= L and L <= Qp))
			sw = false;
		else
		{
			U -= 8;
			D += 8;
			L -= 1;
			R += 1;	
		}
		
	}
}

void mostrar(queue<int> a)
{
	if(not a.empty())
	{
		int elem = a.front();
		a.pop();
		cout << elem << " ";
		mostrar(a);
		a.push(elem);
	}
	else
		cout << "\n";
}

void intersecar()
{
	/*int tK = K.size();
	
	for(int i = 0; i < tK; i++)
	{
		int y = K.front(), tQ = Q.size(); K.pop();
		bool sw = false;
		for(int j = 0; j < tQ; j++)
		{
			int x = Q.front(); Q.pop();
			
			if(x != y)
			{
				if(cihq <= x and x <= cshq)
				{
					if(Qp < Kp)
					{
						if(Qp < x and x < Kp)
							Q.push(x);
						else
						{
							if(Qp > x)
								Q.push(x);
						}
					}
					else
					{
						if(Qp > Kp)
						{
							if(Kp < x and x < Qp)
								Q.push(x);
							else
							{
								if(Qp < x)
									Q.push(x);
							}
						}
					}
				}
				else
				{
					if(csvq <= x and x <= civq)
					{
						if(Qp < Kp)
						{
							if(Kp < x and x < Qp)
								Q.push(x);
							else
							{
								if(Qp > x or not (csvq <= Kp and Kp <= civq and (Kp - 1) % 8 == 0))
									Q.push(x);
							}
						}
						else
						{
							if(Qp > Kp)
							{
								if(Kp < x and x < Qp)
									Q.push(x);
								else
								{
									if(Qp < x or not (csvq <= Kp and Kp <= civq))
										Q.push(x);
								}
							}
						}
					}
				}
			}
			else
			{
				if(x == Kp)
					Q.push(x);
				else
					sw = true;
			}
		}
		if(not sw)
			K.push(y);
	}
	*/
	int tQ = Q.size();
	for(int i = 0; i < tQ; i++)
	{
		
		int x = Q.front(), tK = K.size(); Q.pop();
		
		bool sw = true;

		for(int j = 0; j < tK; j++)
		{
			int y = K.front(); K.pop();
			
			if(x != y and y != Qp)
				K.push(y);		
			else
				sw = false;
			
		}

		if(sw)
		{
			if(cihq <= x and x <= cshq)
			{
				if(Qp < Kp)
				{
					if(Qp < x and x < Kp)
						Q.push(x);
					else
					{
						if(Qp > x)
							Q.push(x);
					}
				}
				else
				{
					if(Qp > Kp)
					{
						if(Kp < x and x < Qp)
							Q.push(x);
						else
						{
							if(Qp < x)
								Q.push(x);
						}
					}
				}
			}
			else
			{
				if(csvq <= x and x <= civq)
				{
					if(Qp < Kp)
					{
						if(Kp > x and x > Qp)
							Q.push(x);
						else
						{
							if(Qp > x)
								Q.push(x);
						}
					}
					else
					{
						if(Qp > Kp)
						{
							if(Kp < x and x < Qp)
								Q.push(x);
							else
							{
								if(Qp < x)
									Q.push(x);
							}
						}
					}
				}
			}
		}		
	}
}

int main()
{
	cin >> Kp >> Qp >> nQp;

	acotar();
	llenar();

	mostrar(Q);
	mostrar(K);	

	cout << "----------------------------------------\n";
	intersecar();

	mostrar(Q);
	mostrar(K);

	return 0;
}
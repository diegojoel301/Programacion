#include<bits/stdc++.h>

using namespace std;

int main()
{
	//Creacion
	set<int> st;

	st.insert(26);
	st.insert(58);
	st.insert(26);
	st.insert(2);
	st.insert(13);
	st.insert(5);
	st.insert(2000);

	//begin(): retorna el primer elemento del conjunto

	//cout << *st.begin() << "\n";

	for(set<int>::iterator itr = st.begin(); itr != st.end(); itr++)
		cout << *itr << "\n";

	return 0;
}